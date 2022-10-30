//////////////////////////////////////////////////////////////////////
//
//    CodeGenVisitor - Walk the parser tree to do
//                     the generation of code
//
//    Copyright (C) 2017-2022  Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 3
//    of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: José Miguel Rivero (rivero@cs.upc.edu)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

#include "CodeGenVisitor.h"
#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/code.h"

#include <string>
#include <cstddef>    // std::size_t

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
CodeGenVisitor::CodeGenVisitor(TypesMgr       & Types,
                               SymTable       & Symbols,
                               TreeDecoration & Decorations) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations} {
}

// Accessor/Mutator to the attribute currFunctionType
TypesMgr::TypeId CodeGenVisitor::getCurrentFunctionTy() const {
  return currFunctionType;
}

void CodeGenVisitor::setCurrentFunctionTy(TypesMgr::TypeId type) {
  currFunctionType = type;
}

// Methods to visit each kind of node:
//
antlrcpp::Any CodeGenVisitor::visitProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  code my_code;
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  for (auto ctxFunc : ctx->function()) { 
    subroutine subr = visit(ctxFunc);
    my_code.add_subroutine(subr);
  }
  Symbols.popScope();
  DEBUG_EXIT();
  return my_code;
}

antlrcpp::Any CodeGenVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  subroutine subr(ctx->ID()->getText());
  codeCounters.reset();
  

  if (ctx->funcType()) subr.add_param("_result");
  
  if (ctx->parameters()) {
        std::vector<var> && lpars = visit(ctx->parameters());
        for (auto & onepar : lpars) {
          subr.add_param(onepar.name);
        }
  }
  
  std::vector<var> && lvars = visit(ctx->declarations());
  for (auto & onevar : lvars) {
    subr.add_var(onevar);
  }

  instructionList && code = visit(ctx->statements());
  code = code || instruction(instruction::RETURN());
  subr.set_instructions(code);
  Symbols.popScope();
  DEBUG_EXIT();
  return subr;
}

antlrcpp::Any CodeGenVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_ENTER();
  std::vector<var> lvars;
  for (auto & varDeclCtx : ctx->variable_decl()) {
    std::vector<var> vars = visit(varDeclCtx);
    for (auto & onevar : vars) {
        lvars.push_back(onevar);
    }
  }
  DEBUG_EXIT();
  return lvars;
}

antlrcpp::Any CodeGenVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId   t1 = getTypeDecor(ctx->type());
  std::size_t      size = Types.getSizeOfType(t1);

  std::vector<var> vars;
  for (unsigned int i = 0; i < ctx->ID().size(); ++i) {
      vars.push_back(var{ctx->ID(i)->getText(), size});
  }

  DEBUG_EXIT();
  return vars;
}

antlrcpp::Any CodeGenVisitor::visitParameters(AslParser::ParametersContext *ctx) {
  DEBUG_ENTER();
    std::vector<var> vars;
    for (unsigned int i = 0; i < ctx->ID().size(); ++i) {
        TypesMgr::TypeId   t1 = getTypeDecor(ctx->type(i));
        std::size_t      size = Types.getSizeOfType(t1);
        vars.push_back(var{ctx->ID(i)->getText(), size});
    }

  DEBUG_EXIT();
  return vars;
}

antlrcpp::Any CodeGenVisitor::visitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  for (auto stCtx : ctx->statement()) {
    instructionList && codeS = visit(stCtx);
    code = code || codeS;
  }
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitPotencia(AslParser::PotenciaContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE1 = visit(ctx->expr(0));
  std::string           addr1 = codAtsE1.addr;
  std::string           offs1 = codAtsE1.offs;
  instructionList &     code1 = codAtsE1.code;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr(0));

  CodeAttribs     && codAtsE2 = visit(ctx->expr(1));
  std::string           addr2 = codAtsE2.addr;
  std::string           offs2 = codAtsE2.offs;
  instructionList &     code2 = codAtsE2.code;
    
    code = code1 || code2;

    //First, we check if the arrays are parameters
    std::string base = "%"+codeCounters.newTEMP();

    std::string result = "%"+codeCounters.newTEMP();
    std::string tmp = "%"+codeCounters.newTEMP();
    std::string tmpI = "%"+codeCounters.newTEMP();
    std::string tmp1 = "%"+codeCounters.newTEMP();

    
    //we initialize the i
    code = code || instruction::ILOAD(tmpI, "0");
    code = code || instruction::ILOAD(tmp1, "1");

    //result and base
    code = code || instruction::FLOAD(result, "1.0");
    code = code || instruction::LOAD(base, addr1);
    if (Types.isIntegerTy(tid1)) code = code || instruction::FLOAT(base, base);
    //WHILE STARTS---------
    std::string label = codeCounters.newLabelWHILE();
    std::string labelWhile = "while"+label;
    std::string labelEndWhile = "endwhile"+label;

    
    code = code || instruction::LABEL(labelWhile);

    //loop condition while i < size
    code = code || instruction::LT(tmp, tmpI, addr2);
    code = code || instruction::FJUMP(tmp, labelEndWhile);


    //while body------
    code = code|| instruction::FMUL(result, result, base);
    code = code || instruction::ADD(tmpI, tmp1, tmpI); //i+1
    //----------------

    //loop
    code = code || instruction::UJUMP(labelWhile);
    code = code || instruction::LABEL(labelEndWhile);
  
  CodeAttribs codAts(result, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitMapStmt(AslParser::MapStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE1 = visit(ctx->ident(0));
  std::string           addr1 = codAtsE1.addr;
  std::string           offs1 = codAtsE1.offs;
  instructionList &     code1 = codAtsE1.code;

  TypesMgr::TypeId tid1 = getTypeDecor(ctx->ident(0));
  TypesMgr::TypeId tid2 = getTypeDecor(ctx->ident(1));
  TypesMgr::TypeId tid3 = getTypeDecor(ctx->ident(2));
  TypesMgr::TypeId tElem1 = Types.getArrayElemType(tid1);
  TypesMgr::TypeId tElem2 = Types.getArrayElemType(tid2);
  TypesMgr::TypeId tRet = Types.getFuncReturnType(tid3);
  TypesMgr::TypeId tParam = Types.getParameterType(tid3, 0);

  CodeAttribs     && codAtsE2 = visit(ctx->ident(1));
  std::string           addr2 = codAtsE2.addr;
  std::string           offs2 = codAtsE2.offs;
  instructionList &     code2 = codAtsE2.code;
    
    code = code1 || code2;

    //First, we check if the arrays are parameters
    std::string ArrayL = "%"+codeCounters.newTEMP();
    std::string ArrayR = "%"+codeCounters.newTEMP();
    if (Symbols.isParameterClass(ctx->ident(0)->getText())) 
              code = code || instruction::LOAD(ArrayL, addr1);
    else 
              ArrayL = ctx->ident(0)->getText();
    if (Symbols.isParameterClass(ctx->ident(1)->getText())) 
              code = code || instruction::LOAD(ArrayR, addr2);
    else         
              ArrayR = ctx->ident(1)->getText();


    //We get the array size as string
    unsigned int si = Types.getArraySize(tid1);
    std::string size = std::to_string(si);


    std::string tmp = "%"+codeCounters.newTEMP();
    std::string tmpI = "%"+codeCounters.newTEMP();
    std::string tmpSize = "%"+codeCounters.newTEMP();
    std::string tmp1 = "%"+codeCounters.newTEMP();

    //we initialize the i
    code = code || instruction::ILOAD(tmpI, "0");
    code = code || instruction::ILOAD(tmp1, "1");
    code = code || instruction::ILOAD(tmpSize, size);


    //WHILE STARTS---------
    std::string label = codeCounters.newLabelWHILE();
    std::string labelWhile = "while"+label;
    std::string labelEndWhile = "endwhile"+label;

    
    code = code || instruction::LABEL(labelWhile);

    //loop condition while i < size
    code = code || instruction::LT(tmp, tmpI, tmpSize);
    code = code || instruction::FJUMP(tmp, labelEndWhile);


    //while body------
    std::string param = "%"+codeCounters.newTEMP();
    std::string funcRes = "%"+codeCounters.newTEMP();
    code = code || instruction::LOADX(param, ArrayL, tmpI); //tmp = b[i]
    code = code || instruction::PUSH("");
    if (Types.isIntegerTy(tElem1) and Types.isFloatTy(tParam))
      code = code || instruction::FLOAT(param, param);
    code = code || instruction::PUSH(param);
    code = code || instruction::CALL(ctx->ident(2)->getText());
    code = code || instruction::POP("");
    code = code || instruction::POP(funcRes);
    if (Types.isIntegerTy(tRet) and Types.isFloatTy(tElem2))
      code = code || instruction::FLOAT(funcRes, funcRes);
    code = code|| instruction::XLOAD(ArrayR, tmpI, funcRes); //a[i] = b[i]
    code = code || instruction::ADD(tmpI, tmp1, tmpI); //i+1
    //----------------

    //loop
    code = code || instruction::UJUMP(labelWhile);
    code = code || instruction::LABEL(labelEndWhile);


  DEBUG_EXIT();
  return code;

}

antlrcpp::Any CodeGenVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE1 = visit(ctx->left_expr());
  std::string           addr1 = codAtsE1.addr;
  std::string           offs1 = codAtsE1.offs;
  instructionList &     code1 = codAtsE1.code;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());

  CodeAttribs     && codAtsE2 = visit(ctx->expr());
  std::string           addr2 = codAtsE2.addr;
  std::string           offs2 = codAtsE2.offs;
  instructionList &     code2 = codAtsE2.code;
  TypesMgr::TypeId tid2 = getTypeDecor(ctx->expr());

  if (Types.isArrayTy(tid1) && Types.isArrayTy(tid2)) {
    
    code = code1 || code2;

    //First, we check if the arrays are parameters
    std::string ArrayL = "%"+codeCounters.newTEMP();
    std::string ArrayR = "%"+codeCounters.newTEMP();
    if (Symbols.isParameterClass(ctx->left_expr()->getText())) 
              code = code || instruction::LOAD(ArrayL, addr1);
    else 
              ArrayL = ctx->left_expr()->getText();
    if (Symbols.isParameterClass(ctx->expr()->getText())) 
              code = code || instruction::LOAD(ArrayR, addr2);
    else         
              ArrayR = ctx->expr()->getText();

    //We get the array size as string
    unsigned int si = Types.getArraySize(tid1);
    std::string size = std::to_string(si);


    std::string tmp = "%"+codeCounters.newTEMP();
    std::string tmpI = "%"+codeCounters.newTEMP();
    std::string tmpSize = "%"+codeCounters.newTEMP();
    std::string tmp1 = "%"+codeCounters.newTEMP();

    //we initialize the i
    code = code || instruction::ILOAD(tmpI, "0");
    code = code || instruction::ILOAD(tmp1, "1");
    code = code || instruction::ILOAD(tmpSize, size);


    //WHILE STARTS---------
    std::string label = codeCounters.newLabelWHILE();
    std::string labelWhile = "while"+label;
    std::string labelEndWhile = "endwhile"+label;

    
    code = code || instruction::LABEL(labelWhile);

    //loop condition while i < size
    code = code || instruction::LT(tmp, tmpI, tmpSize);
    code = code || instruction::FJUMP(tmp, labelEndWhile);


    //while body------
    std::string tmpCA = "%"+codeCounters.newTEMP();
    code = code || instruction::LOADX(tmpCA, ArrayR, tmpI); //tmp = b[i]
    code = code|| instruction::XLOAD(ArrayL, tmpI, tmpCA); //a[i] = b[i]
    code = code || instruction::ADD(tmpI, tmp1, tmpI); //i+1
    //----------------

    //loop
    code = code || instruction::UJUMP(labelWhile);
    code = code || instruction::LABEL(labelEndWhile);


  }

  else if(offs1 != "") {
    if (Types.isFloatTy(tid1) && Types.isIntegerTy(tid2)) {
      std::string tmp = "%"+codeCounters.newTEMP();
      code = code1 || code2 || instruction::FLOAT(tmp, addr2);
      code = code || instruction::XLOAD(addr1, offs1, tmp);
    }
    else code = code1 || code2 || instruction::XLOAD(addr1, offs1, addr2);
  }

  else {
    if (Types.isFloatTy(tid1) && Types.isIntegerTy(tid2)) {
      std::string tmp = "%"+codeCounters.newTEMP();
      code = code1 || code2 || instruction::FLOAT(tmp, addr2);
      code = code || instruction::LOAD(addr1, tmp);
    }
    else code = code1 || code2 || instruction::LOAD(addr1, addr2);
  } 
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE = visit(ctx->expr());
  std::string          addr1 = codAtsE.addr;
  instructionList &    code1 = codAtsE.code;
  instructionList &&   code2 = visit(ctx->statements(0));

  std::string label = codeCounters.newLabelIF();
  std::string labelEndIf = "endif"+label;

 
  if (ctx->ELSE()) {
     instructionList && codeElse = visit(ctx->statements(1));
     std::string labelElse = "else"+label;
     code = code1 || instruction::FJUMP(addr1, labelElse) || code2 || instruction::UJUMP(labelEndIf) 
     || instruction::LABEL(labelElse) || codeElse || instruction::LABEL(labelEndIf);
  }

  else {
    code = code1 || instruction::FJUMP(addr1, labelEndIf) ||
          code2 || instruction::LABEL(labelEndIf);
  }
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();
  //cogemos el codigo que genera la expresion y los statements y lo guardamos
  instructionList code;
  CodeAttribs     && codAtsE = visit(ctx->expr());
  std::string          addr1 = codAtsE.addr;
  instructionList &    code1 = codAtsE.code;
  
  //cogemos el codigo de los statements
  instructionList &&   code2 = visit(ctx->statements());
  
  //lo meteremos en la estructura de while
  std::string label = codeCounters.newLabelWHILE();
  std::string labelWhile = "while"+label;
  std::string labelEndWhile= "endwhile"+label;
  
  //pegamos todo el codigo con la estructura del while
  code = instruction::LABEL(labelWhile) || code1 ||instruction::FJUMP(addr1, labelEndWhile) ||
         code2 || instruction::UJUMP(labelWhile) || instruction::LABEL(labelEndWhile);
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitProcCallNoParams(AslParser::ProcCallNoParamsContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  // std::string name = ctx->ident()->ID()->getSymbol()->getText();
  std::string name = ctx->ident()->getText();
  code = instruction::CALL(name);
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitProcCallParams(AslParser::ProcCallParamsContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  TypesMgr::TypeId tRet = Types.getFuncReturnType(t1);
  std::vector<TypesMgr::TypeId> paramTypes = Types.getFuncParamsTypes(t1);
  if (!Types.isVoidTy(tRet)) code = code || instruction::PUSH("");
  for (unsigned int i = 0; i < ctx->expr().size(); ++i) {
    TypesMgr::TypeId t = getTypeDecor(ctx->expr(i));
    CodeAttribs && codAts = visit(ctx->expr(i));
    code = code || codAts.code;
    if (not (Types.equalTypes(t, paramTypes[i]))) {
      std::string tmp = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(tmp, codAts.addr);
      code = code || instruction::PUSH(tmp);
    } 
    else if (Types.isArrayTy(paramTypes[i]) && !Symbols.isParameterClass(ctx->expr(i)->getText())) {
      std::string tmp = "%"+codeCounters.newTEMP();
      code = code || instruction::ALOAD(tmp, codAts.addr);
      code = code || instruction::PUSH(tmp);
    }
    else code = code || instruction::PUSH(codAts.addr);
  }
  code = code || instruction::CALL(ctx->ident()->getText());
  for (unsigned int i = 0; i < ctx->expr().size(); ++i) {
    CodeAttribs && codAts = visit(ctx->expr(i));
    code = code || instruction::POP("");
  }
  if (!Types.isVoidTy(tRet)) code = code || instruction::POP("");

  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAtsE = visit(ctx->left_expr());
  std::string          addr1 = codAtsE.addr;
  std::string          offs1 = codAtsE.offs;
  instructionList &    code1 = codAtsE.code;
  instructionList &     code = code1;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());

  if (offs1 != "") {
    std::string tmp = "%"+codeCounters.newTEMP();
    if (Types.isIntegerTy(tid1) || Types.isBooleanTy(tid1)) 
      code = code1 || instruction::READI(tmp);
    else if (Types.isFloatTy(tid1))
      code = code1 || instruction::READF(tmp);
    else if (Types.isCharacterTy(tid1))
      code = code1 || instruction::READC(tmp);

    code = code || instruction::XLOAD(addr1, offs1, tmp);
  }

  else {
    if (Types.isIntegerTy(tid1) || Types.isBooleanTy(tid1)) 
      code = code1 || instruction::READI(addr1);
    else if (Types.isFloatTy(tid1))
      code = code1 || instruction::READF(addr1);
    else if (Types.isCharacterTy(tid1))
      code = code1 || instruction::READC(addr1);
  }

  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr());
  std::string         addr1 = codAt1.addr; 
  // std::string         offs1 = codAt1.offs;
  instructionList &   code1 = codAt1.code;
  instructionList &    code = code1;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr());
  
  if (Types.isIntegerTy(tid1) || Types.isBooleanTy(tid1)) 
    code = code1 || instruction::WRITEI(addr1);
  else if (Types.isFloatTy(tid1))
    code = code1 || instruction::WRITEF(addr1);
  else if (Types.isCharacterTy(tid1))
    code = code1 || instruction::WRITEC(addr1);
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitReturnStmt(AslParser::ReturnStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;

  if (ctx->expr()) { 
    CodeAttribs&& codAt = visit(ctx->expr());
    TypesMgr::TypeId tRet = getTypeDecor(ctx);
    TypesMgr::TypeId tExpr = getTypeDecor(ctx->expr());
    if (!Types.equalTypes(tRet, tExpr)) {
          code = code || codAt.code;
          std::string addr = codAt.addr;
          std::string tmp = "%"+codeCounters.newTEMP();
          code = code || instruction::FLOAT(tmp, addr);
          code = code || instruction::LOAD("_result", tmp);
    }
    else {
      code = code || codAt.code;
      std::string addr = codAt.addr;
      code = code || instruction::LOAD("_result", addr);
    }
  }
  code = code || instruction::RETURN();
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  std::string s = ctx->STRING()->getText();
  code = code || instruction::WRITES(s);
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitLeftArray(AslParser::LeftArrayContext *ctx) {
  DEBUG_ENTER();

  instructionList code;

  CodeAttribs && codAt1 = visit(ctx->ident());
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  code = code || code1;
  if (Symbols.isParameterClass(ctx->ident()->getText())) {
    std::string temp = "%"+codeCounters.newTEMP();
    code = code || instruction::LOAD(temp, addr1);
    CodeAttribs && codAtExpr = visit(ctx->expr());
    code = code || codAtExpr.code;
    CodeAttribs codAts(temp, codAtExpr.addr, code);
    DEBUG_EXIT();
    return codAts;
  }

  else {
    CodeAttribs && codAtExpr = visit(ctx->expr());
    code = code || codAtExpr.code;
    CodeAttribs codAts(addr1, codAtExpr.addr, code);
    DEBUG_EXIT();
    return codAts;
  }
}

antlrcpp::Any CodeGenVisitor::visitExprArray(AslParser::ExprArrayContext *ctx) {
  DEBUG_ENTER();

  instructionList code;

  CodeAttribs && codAt1 = visit(ctx->ident());
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  code = code || code1;

  if (Symbols.isParameterClass(ctx->ident()->getText())) {
    std::string temp = "%"+codeCounters.newTEMP();
    code = code || instruction::LOAD(temp, addr1);
    CodeAttribs && codAtExpr = visit(ctx->expr());
    code = code || codAtExpr.code;

    std::string tmp = "%"+codeCounters.newTEMP();
    code = code || instruction::LOADX(tmp, temp, codAtExpr.addr);

     CodeAttribs codAts(tmp, "", code);
    DEBUG_EXIT();
    return codAts;
  }

  else {
    CodeAttribs && codAtExpr = visit(ctx->expr());
    code = code || codAtExpr.code;

    std::string tmp = "%"+codeCounters.newTEMP();
    code = code || instruction::LOADX(tmp, codAt1.addr, codAtExpr.addr);

    CodeAttribs codAts(tmp, "", code);
        DEBUG_EXIT();
    return codAts;
  }

}


antlrcpp::Any CodeGenVisitor::visitLeftIdent(AslParser::LeftIdentContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->ident());
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;
  
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  TypesMgr::TypeId  t = getTypeDecor(ctx);
  
  std::string temp = "%"+codeCounters.newTEMP();
  if (Types.isIntegerTy(t)) {
    if (ctx->MUL())
        code = code || instruction::MUL(temp, addr1, addr2);
    else if (ctx->DIV())
        code = code || instruction::DIV(temp, addr1, addr2);
    else if (ctx->MOD()) {
      //a % b = a - (b * int(a/b))
      code = code || instruction::DIV(temp, addr1, addr2); //(a/b)
      code = code || instruction::MUL(temp, temp, addr2); //(a/b)*b
      code = code || instruction::SUB(temp, addr1, temp); //a - (b * (a/b))
    }
       
    else if (ctx->PLUS())
      code = code || instruction::ADD(temp, addr1, addr2);
    else // (ctx->MINUS())
      code = code || instruction::SUB(temp, addr1, addr2);
  }
  
  else {
    if (ctx->MUL()) {
        std::string temp1 = "%"+codeCounters.newTEMP();
        if (Types.isIntegerTy(t1)) {
            code = code|| instruction::FLOAT(temp1, addr1);
            code = code || instruction::FMUL(temp, temp1, addr2);
        }
        else if (Types.isIntegerTy(t2)) {
            code = code|| instruction::FLOAT(temp1, addr2);
            code = code || instruction::FMUL(temp, addr1, temp1);
        }
         else {
             code = code || instruction::FMUL(temp, addr1, addr2);
         }
    }
    else if (ctx->DIV()){
        std::string temp1 = "%"+codeCounters.newTEMP();
        if (Types.isIntegerTy(t1)) {
            code = code|| instruction::FLOAT(temp1, addr1);
            code = code || instruction::FDIV(temp, temp1, addr2);
        }
        else if (Types.isIntegerTy(t2)) {
            code = code|| instruction::FLOAT(temp1, addr2);
            code = code || instruction::FDIV(temp, addr1, temp1);
        }
         else {
        code = code || instruction::FDIV(temp, addr1, addr2);
         }
    }

    else if (ctx->PLUS()) {
        std::string temp1 = "%"+codeCounters.newTEMP();
        if (Types.isIntegerTy(t1)) {
            code = code|| instruction::FLOAT(temp1, addr1);
            code = code || instruction::FADD(temp, temp1, addr2);
        }
        else if (Types.isIntegerTy(t2)) {
            code = code|| instruction::FLOAT(temp1, addr2);
            code = code || instruction::FADD(temp, addr1, temp1);
        }
         else {
        code = code || instruction::FADD(temp, addr1, addr2);
         }
    }
    else { // (ctx->MINUS()) 
        std::string temp1 = "%"+codeCounters.newTEMP();
        if (Types.isIntegerTy(t1)) {
            code = code|| instruction::FLOAT(temp1, addr1);
            code = code || instruction::FSUB(temp, temp1, addr2);
        }
        else if (Types.isIntegerTy(t2)) {
            code = code|| instruction::FLOAT(temp1, addr2);
            code = code || instruction::FSUB(temp, addr1, temp1);
        }
         else {
        code = code || instruction::FSUB(temp, addr1, addr2);
         }
    }
  }
  
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));

  std::string temp = "%"+codeCounters.newTEMP();
  
  if (Types.isFloatTy(t1) && Types.isFloatTy(t2)) {
    if (ctx->E())
      code = code || instruction::FEQ(temp, addr1, addr2);
    else if (ctx->NE()) {
      code = code || instruction::FEQ(temp, addr1, addr2);
      code = code || instruction::NOT(temp, temp);
    }
    else if (ctx->GE())
      code = code || instruction::FLE(temp, addr2, addr1);
    else if (ctx->LE())
      code = code || instruction::FLE(temp, addr1, addr2);
    else if (ctx->GT())
      code = code || instruction::FLT(temp, addr2, addr1);
    else if (ctx->LT())
      code = code || instruction::FLT(temp, addr1, addr2);
  }

  else if (Types.isFloatTy(t1) && Types.isIntegerTy(t2)) {
    std::string temp1 = "%"+codeCounters.newTEMP();
    code = code|| instruction::FLOAT(temp1, addr2);
    if (ctx->E())
      code = code || instruction::FEQ(temp, addr1, temp1);
    else if (ctx->NE()) {
      code = code || instruction::FEQ(temp, addr1, temp1);
      code = code || instruction::NOT(temp, temp);
    }
    else if (ctx->GE())
      code = code || instruction::FLE(temp, temp1, addr1);
    else if (ctx->LE())
      code = code || instruction::FLE(temp, addr1, temp1);
    else if (ctx->GT())
      code = code || instruction::FLT(temp, temp1, addr1);
    else if (ctx->LT())
      code = code || instruction::FLT(temp, addr1, temp1);
  }

  else if (Types.isIntegerTy(t1) && Types.isFloatTy(t2)) {
    std::string temp1 = "%"+codeCounters.newTEMP();
    code = code|| instruction::FLOAT(temp1, addr1);  
    if (ctx->E())
      code = code || instruction::FEQ(temp, temp1, addr2);
    else if (ctx->NE()) {
      code = code || instruction::FEQ(temp, temp1, addr2);
      code = code || instruction::NOT(temp, temp);
    }
    else if (ctx->GE())
      code = code || instruction::FLE(temp, addr2, temp1);
    else if (ctx->LE())
      code = code || instruction::FLE(temp, temp1, addr2);
    else if (ctx->GT())
      code = code || instruction::FLT(temp, addr2, temp1);
    else if (ctx->LT())
      code = code || instruction::FLT(temp, temp1, addr2);
  }

  else {
    if (ctx->E())
      code = code || instruction::EQ(temp, addr1, addr2);
    else if (ctx->NE()) {
      code = code || instruction::EQ(temp, addr1, addr2);
      code = code || instruction::NOT(temp, temp);
    }
    else if (ctx->GE())
      code = code || instruction::LE(temp, addr2, addr1);
    else if (ctx->LE())
      code = code || instruction::LE(temp, addr1, addr2);
    else if (ctx->GT())
      code = code || instruction::LT(temp, addr2, addr1);
    else if (ctx->LT())
      code = code || instruction::LT(temp, addr1, addr2);
  }
  
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitBoolean(AslParser::BooleanContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;

  std::string temp = "%"+codeCounters.newTEMP();
  

  if (ctx->AND())
    code = code || instruction::AND(temp, addr1, addr2);
  else if (ctx->OR())
    code = code || instruction::OR(temp, addr1, addr2);

  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}
  
antlrcpp::Any CodeGenVisitor::visitUnitary(AslParser::UnitaryContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr());
  std::string         addr1 = codAt1.addr;
  instructionList &   code = codAt1.code;

  std::string temp = "%"+codeCounters.newTEMP();

  if (ctx->NOT())
    code = code || instruction::NOT(temp, addr1);
  else if (ctx->MINUS()) {
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
    if (Types.isFloatTy(t1)) code = code || instruction::FNEG(temp, addr1);
    else code = code || instruction::NEG(temp, addr1);
  }
  else temp = addr1;

  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitPars(AslParser::ParsContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAts = visit(ctx->expr());
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitExprFuncNoParams(AslParser::ExprFuncNoParamsContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  code = code || instruction::PUSH("");
  code = code || instruction::CALL(ctx->ident()->getText());
  std::string temp = "%"+codeCounters.newTEMP();
  code = code || instruction::POP(temp);
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitExprFuncParams(AslParser::ExprFuncParamsContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  std::vector<TypesMgr::TypeId> paramTypes = Types.getFuncParamsTypes(t1);
  code = code || instruction::PUSH("");
  for (unsigned int i = 0; i < ctx->expr().size(); ++i) {
    TypesMgr::TypeId t = getTypeDecor(ctx->expr(i));
    CodeAttribs && codAts = visit(ctx->expr(i));
    code = code || codAts.code;
    if (not (Types.equalTypes(t, paramTypes[i]))) {
      std::string tmp = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(tmp, codAts.addr);
      code = code || instruction::PUSH(tmp);
    } 
    else if (Types.isArrayTy(paramTypes[i]) && !Symbols.isParameterClass(ctx->expr(i)->getText())) {
      std::string tmp = "%"+codeCounters.newTEMP();
      code = code || instruction::ALOAD(tmp, codAts.addr);
      code = code || instruction::PUSH(tmp);
    }
    else code = code || instruction::PUSH(codAts.addr);
  }
  code = code || instruction::CALL(ctx->ident()->getText());
  for (unsigned int i = 0; i < ctx->expr().size(); ++i) {
    CodeAttribs && codAts = visit(ctx->expr(i));
    code = code || instruction::POP("");
  }
  std::string temp = "%"+codeCounters.newTEMP();
  code = code || instruction::POP(temp);
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  std::string temp = "%"+codeCounters.newTEMP();
  if (ctx->INTVAL()) code = instruction::ILOAD(temp, ctx->getText());
  else if (ctx->FLOATVAL()) code = instruction::FLOAD(temp, ctx->getText());
  else if (ctx->CHARVAL()) {
      std::string s = ctx->getText();
      code = instruction::CHLOAD(temp, s.substr(1, s.size()-2));
  } 
  else if (ctx->BOOLVAL())
  {
      std::string boolVal = ctx->getText();
      if (boolVal == "true") code = instruction::ILOAD(temp, "1");
      else code = instruction::ILOAD(temp, "0");
  }
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->ident());
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs codAts(ctx->ID()->getText(), "", instructionList());
  DEBUG_EXIT();
  return codAts;
}


// Getters for the necessary tree node atributes:
//   Scope and Type
SymTable::ScopeId CodeGenVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) const {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId CodeGenVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) const {
  return Decorations.getType(ctx);
}


// Constructors of the class CodeAttribs:
//
CodeGenVisitor::CodeAttribs::CodeAttribs(const std::string & addr,
                                         const std::string & offs,
                                         instructionList & code) :
  addr{addr}, offs{offs}, code{code} {
}

CodeGenVisitor::CodeAttribs::CodeAttribs(const std::string & addr,
                                         const std::string & offs,
                                         instructionList && code) :
  addr{addr}, offs{offs}, code{code} {
}
