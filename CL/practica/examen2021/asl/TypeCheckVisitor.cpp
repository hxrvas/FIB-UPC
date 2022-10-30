//////////////////////////////////////////////////////////////////////
//
//    TypeCheckVisitor - Walk the parser tree to do the semantic
//                       typecheck for the Asl programming language
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

#include "TypeCheckVisitor.h"
#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/SemErrors.h"

#include <iostream>
#include <string>

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
TypeCheckVisitor::TypeCheckVisitor(TypesMgr       & Types,
                                   SymTable       & Symbols,
                                   TreeDecoration & Decorations,
                                   SemErrors      & Errors) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations},
  Errors{Errors} {
}

// Accessor/Mutator to the attribute currFunctionType
TypesMgr::TypeId TypeCheckVisitor::getCurrentFunctionTy() const {
  return currFunctionType;
}

void TypeCheckVisitor::setCurrentFunctionTy(TypesMgr::TypeId type) {
  currFunctionType = type;
}

// Methods to visit each kind of node:
//
antlrcpp::Any TypeCheckVisitor::visitProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  for (auto ctxFunc : ctx->function()) { 
    visit(ctxFunc);
  }
  if (Symbols.noMainProperlyDeclared())
    Errors.noMainProperlyDeclared(ctx);
  Symbols.popScope();
  Errors.print();
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId tRet;
  if (ctx->funcType())
    tRet = getTypeDecor(ctx->funcType());
  else
    tRet = Types.createVoidTy();
  setCurrentFunctionTy(tRet);

  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);

  // Symbols.print();
  visit(ctx->statements());
  Symbols.popScope();
  DEBUG_EXIT();
  return 0;
}

// antlrcpp::Any TypeCheckVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

// antlrcpp::Any TypeCheckVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

// antlrcpp::Any TypeCheckVisitor::visitType(AslParser::TypeContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

antlrcpp::Any TypeCheckVisitor::visitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
  visitChildren(ctx);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitReturnStmt(AslParser::ReturnStmtContext *ctx) {
    DEBUG_ENTER();
    if (ctx->expr()) {
        visit(ctx->expr());
        TypesMgr::TypeId t = getTypeDecor(ctx->expr());
        if ((not Types.isErrorTy(t) and not Types.isErrorTy(getCurrentFunctionTy())) and not (Types.isIntegerTy(t) and Types.isFloatTy(getCurrentFunctionTy()))) {
            if (not Types.equalTypes(t, getCurrentFunctionTy()))
                Errors.incompatibleReturn(ctx->RETURN());
        }
    }
    else {
        if ((not Types.isErrorTy(getCurrentFunctionTy())) and (not Types.isVoidTy(getCurrentFunctionTy())))
            Errors.incompatibleReturn(ctx->RETURN());
    }
    putTypeDecor(ctx, getCurrentFunctionTy());
    DEBUG_EXIT();
    return 0;
}

antlrcpp::Any TypeCheckVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->left_expr());
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.copyableTypes(t1, t2)))
    Errors.incompatibleAssignment(ctx->ASSIGN());
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableLeftExpr(ctx->left_expr());
  DEBUG_EXIT();
  return 0;
}


antlrcpp::Any TypeCheckVisitor::visitMapStmt(AslParser::MapStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident(0));
  visit(ctx->ident(1));
  visit(ctx->ident(2));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->ident(1));
  TypesMgr::TypeId t3 = getTypeDecor(ctx->ident(2));

  bool b1 = (not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and (not Types.isArrayTy(t1)) and (not Types.isArrayTy(t2));
  bool b2 = not ((Types.isArrayTy(t1)) and (Types.isArrayTy(t2)) and (Types.getArraySize(t1) == Types.getArraySize(t2)));

  bool error = false;

  TypesMgr::TypeId tRet, tParam;

  if (Types.isFunctionTy(t3)) {
    if (Types.getNumOfParameters(t3) != 1) {
      error = true;
      Errors.incompatibleMapOperands(ctx);
    }
    else {
      tRet = Types.getFuncReturnType(t3);
      tParam = Types.getParameterType(t3, 0);
    }
  }

  bool eqTy1 = (Types.isFunctionTy(t3)) and (Types.isArrayTy(t1)) and ((Types.equalTypes(tParam, Types.getArrayElemType(t1))) or (Types.isFloatTy(tParam) and Types.isIntegerTy(Types.getArrayElemType(t1))));
  bool eqTy2 = (Types.isFunctionTy(t3)) and (Types.isArrayTy(t2)) and ((Types.equalTypes(tRet, Types.getArrayElemType(t2))) or (Types.isFloatTy(Types.getArrayElemType(t2)) and Types.isIntegerTy(tRet)));
  bool b3 = not (eqTy1 and eqTy2);
  
  if (not error and (b1 or b2))
    Errors.incompatibleMapOperands(ctx);

  else if (b3)
    Errors.incompatibleMapOperands(ctx);

  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);
  visit(ctx->statements(0));

  if(ctx->ELSE()) visit(ctx->statements(1));
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);
  visit(ctx->statements());

  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitProcCallNoParams(AslParser::ProcCallNoParamsContext *ctx) {
  DEBUG_ENTER();
  visitChildren(ctx);
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  if (not Types.isErrorTy(t1) and not Types.isFunctionTy(t1)) {
    Errors.isNotCallable(ctx->ident());
  }
  else if (not Types.isErrorTy(t1)){
    int size = Types.getNumOfParameters(t1);
    if (size != 0)
        Errors.numberOfParameters(ctx->ident());
    else {
        TypesMgr::TypeId ret = Types.getFuncReturnType(t1);
        putTypeDecor(ctx, ret);
    }
  }
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitProcCallParams(AslParser::ProcCallParamsContext *ctx) {
  DEBUG_ENTER();
  visitChildren(ctx);
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  if (not Types.isErrorTy(t1) and not Types.isFunctionTy(t1)) {
    Errors.isNotCallable(ctx->ident());
  }
  else if (not Types.isErrorTy(t1)){
      unsigned int size = Types.getNumOfParameters(t1);
        if (not (size == ctx->expr().size()))
            Errors.numberOfParameters(ctx->ident());
        else {
            std::vector<TypesMgr::TypeId> paramTypes = Types.getFuncParamsTypes(t1);
            for (unsigned int i=0; i < size; ++i) {
                TypesMgr::TypeId t = getTypeDecor(ctx->expr(i));
                if (not Types.isErrorTy(t)) {
                if (not (Types.isIntegerTy(t) and Types.isFloatTy(paramTypes[i]))) {
                    if (not Types.equalTypes(t, paramTypes[i])) Errors.incompatibleParameter(ctx->expr(i), i+1, ctx);
                }
                }
            }
        }
  TypesMgr::TypeId ret = Types.getFuncReturnType(t1);
  putTypeDecor(ctx, ret);
  }
  else putTypeDecor(ctx, t1);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->left_expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)) and
      (not Types.isFunctionTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableExpression(ctx);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  DEBUG_EXIT();
  return 0;
}

// antlrcpp::Any TypeCheckVisitor::visitWriteString(AslParser::WriteStringContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

antlrcpp::Any TypeCheckVisitor::visitLeftIdent(AslParser::LeftIdentContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  putTypeDecor(ctx, t1);
  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitLeftArray(AslParser::LeftArrayContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  visit(ctx->expr());
  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
  if (not Types.isErrorTy(t2) and not Types.isIntegerTy(t2)) {
      Errors.nonIntegerIndexInArrayAccess(ctx->expr());
  }
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  if (not Types.isErrorTy(t1) and not Types.isArrayTy(t1)) {
      TypesMgr::TypeId e = Types.createErrorTy();
      putTypeDecor(ctx, e);
      Errors.nonArrayInArrayAccess(ctx);
  }
  else if (not Types.isErrorTy(t1)) {
    TypesMgr::TypeId t = Types.getArrayElemType(t1);
    putTypeDecor(ctx, t);
  }
  else {
      putTypeDecor(ctx, t1);
  }
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  TypesMgr::TypeId t;
  if (ctx->MOD()) {
    if (((not Types.isErrorTy(t1)) and (not Types.isIntegerTy(t1))) or
      ((not Types.isErrorTy(t2)) and (not Types.isIntegerTy(t2))))
        Errors.incompatibleOperator(ctx->op);
    t = Types.createIntegerTy();
  }
  else {
  //check if both operands are numeric
  if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))) or
      ((not Types.isErrorTy(t2)) and (not Types.isNumericTy(t2))))
    Errors.incompatibleOperator(ctx->op);
  
  //is int or float?

  if (Types.isFloatTy(t1) or Types.isFloatTy(t2)) t = Types.createFloatTy();
  else t = Types.createIntegerTy();
  }
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitPotencia(AslParser::PotenciaContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  TypesMgr::TypeId t;

  //check if both operands are numeric
  if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))) or
      ((not Types.isErrorTy(t2)) and (not Types.isIntegerTy(t2))))
    Errors.incompatibleOperator(ctx->op);
  
  //is int or float?

  t = Types.createFloatTy();

  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  
  //check if operands are comparable 
  std::string oper = ctx->op->getText();
  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.comparableTypes(t1, t2, oper)))
    Errors.incompatibleOperator(ctx->op);
  
  //create a boolean
  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any
TypeCheckVisitor::visitBoolean(AslParser::BooleanContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));

  //check if operands are comparable
  std::string oper = ctx->op->getText();
  if (((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1))) or
      ((not Types.isErrorTy(t2)) and (not Types.isBooleanTy(t2))))
    Errors.incompatibleOperator(ctx->op);

  //create a boolean
  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any
TypeCheckVisitor::visitPars(AslParser::ParsContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  putTypeDecor(ctx, getTypeDecor(ctx->expr()));
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any
TypeCheckVisitor::visitUnitary(AslParser::UnitaryContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());

  TypesMgr::TypeId t;

  if(ctx->NOT()) {
  //check if operands are comparable
  std::string oper = ctx->op->getText();
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.incompatibleOperator(ctx->op);

  t = Types.createBooleanTy();
  }

  else {
  if ((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1)))
    Errors.incompatibleOperator(ctx->op);

  //is int or float?
  if (Types.isFloatTy(t1)) t = Types.createFloatTy();
  else t = Types.createIntegerTy();
  }

  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}


antlrcpp::Any
TypeCheckVisitor::visitValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId t;
  
  //check wich type it is
  if (ctx->INTVAL()) t = Types.createIntegerTy();
  else if (ctx->FLOATVAL()) t = Types.createFloatTy();
  else if (ctx->BOOLVAL()) t = Types.createBooleanTy();
  else t = Types.createCharacterTy();
  
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any
TypeCheckVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  putTypeDecor(ctx, t1);
  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any
TypeCheckVisitor::visitExprArray(AslParser::ExprArrayContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  visit(ctx->expr());
  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
  if (not Types.isErrorTy(t2) and not Types.isIntegerTy(t2)) {
      Errors.nonIntegerIndexInArrayAccess(ctx->expr());
  }
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  if (not Types.isErrorTy(t1) and not Types.isArrayTy(t1)) {
      TypesMgr::TypeId e = Types.createErrorTy();
      putTypeDecor(ctx, e);
      Errors.nonArrayInArrayAccess(ctx);
  }

   else if (not Types.isErrorTy(t1)) {
    TypesMgr::TypeId t = Types.getArrayElemType(t1);
    putTypeDecor(ctx, t);
  }
  else {
      putTypeDecor(ctx, t1);
  }
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any
TypeCheckVisitor::visitExprFuncNoParams(AslParser::ExprFuncNoParamsContext *ctx) {
  DEBUG_ENTER();
  visitChildren(ctx);
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  if (not Types.isErrorTy(t1) and not Types.isFunctionTy(t1))
      Errors.isNotCallable(ctx->ident());
  else if (not Types.isErrorTy(t1)){
    int size = Types.getNumOfParameters(t1);
    if (not (size == 0))
            Errors.numberOfParameters(ctx->ident());
    TypesMgr::TypeId ret = Types.getFuncReturnType(t1);
    if (not Types.isErrorTy(ret) and Types.isVoidTy(ret)) {
        Errors.isNotFunction(ctx->ident());
        ret = Types.createErrorTy();
    }
    putTypeDecor(ctx, ret);
  }
  else {
      putTypeDecor(ctx, t1);
  }
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any
TypeCheckVisitor::visitExprFuncParams(AslParser::ExprFuncParamsContext *ctx) {
  DEBUG_ENTER();
  visitChildren(ctx);
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  if (not Types.isErrorTy(t1) and not Types.isFunctionTy(t1))
      Errors.isNotCallable(ctx->ident());
  else if (not Types.isErrorTy(t1)) {
      unsigned int size = Types.getNumOfParameters(t1);
        if (not (size == ctx->expr().size()))
            Errors.numberOfParameters(ctx->ident());
        else {
            std::vector<TypesMgr::TypeId> paramTypes = Types.getFuncParamsTypes(t1);
            for (unsigned int i=0; i < size; ++i) {
                TypesMgr::TypeId t = getTypeDecor(ctx->expr(i));
                if (not Types.isErrorTy(t)) {
                if (not (Types.isIntegerTy(t) and Types.isFloatTy(paramTypes[i]))) {
                    if (not Types.equalTypes(t, paramTypes[i])) Errors.incompatibleParameter(ctx->expr(i), i+1, ctx);
                }
                }
            }
        }
    TypesMgr::TypeId ret = Types.getFuncReturnType(t1);
    if (not Types.isErrorTy(ret) and Types.isVoidTy(ret)) {
        Errors.isNotFunction(ctx->ident());
        ret = Types.createErrorTy();
    }
    putTypeDecor(ctx, ret);
  }
  else putTypeDecor(ctx, t1);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any
TypeCheckVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  std::string ident = ctx->getText();
  if (Symbols.findInStack(ident) == -1) {
    Errors.undeclaredIdent(ctx->ID());
    TypesMgr::TypeId te = Types.createErrorTy();
    putTypeDecor(ctx, te);
    putIsLValueDecor(ctx, true);
  }
  else {
    TypesMgr::TypeId t1 = Symbols.getType(ident);
    putTypeDecor(ctx, t1);
    if (Symbols.isFunctionClass(ident))
      putIsLValueDecor(ctx, false);
    else
      putIsLValueDecor(ctx, true);
  }
  DEBUG_EXIT();
  return 0;
}


// Getters for the necessary tree node atributes:
//   Scope, Type ans IsLValue
SymTable::ScopeId TypeCheckVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId TypeCheckVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}
bool TypeCheckVisitor::getIsLValueDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getIsLValue(ctx);
}

// Setters for the necessary tree node attributes:
//   Scope, Type ans IsLValue
void TypeCheckVisitor::putScopeDecor(antlr4::ParserRuleContext *ctx, SymTable::ScopeId s) {
  Decorations.putScope(ctx, s);
}
void TypeCheckVisitor::putTypeDecor(antlr4::ParserRuleContext *ctx, TypesMgr::TypeId t) {
  Decorations.putType(ctx, t);
}
void TypeCheckVisitor::putIsLValueDecor(antlr4::ParserRuleContext *ctx, bool b) {
  Decorations.putIsLValue(ctx, b);
}
