
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "AslParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by AslParser.
 */
class  AslVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by AslParser.
   */
    virtual antlrcpp::Any visitProgram(AslParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitFunction(AslParser::FunctionContext *context) = 0;

    virtual antlrcpp::Any visitParameters(AslParser::ParametersContext *context) = 0;

    virtual antlrcpp::Any visitFuncType(AslParser::FuncTypeContext *context) = 0;

    virtual antlrcpp::Any visitDeclarations(AslParser::DeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitVariable_decl(AslParser::Variable_declContext *context) = 0;

    virtual antlrcpp::Any visitArrayDecl(AslParser::ArrayDeclContext *context) = 0;

    virtual antlrcpp::Any visitBasic(AslParser::BasicContext *context) = 0;

    virtual antlrcpp::Any visitBasicType(AslParser::BasicTypeContext *context) = 0;

    virtual antlrcpp::Any visitStatements(AslParser::StatementsContext *context) = 0;

    virtual antlrcpp::Any visitAssignStmt(AslParser::AssignStmtContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(AslParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt(AslParser::WhileStmtContext *context) = 0;

    virtual antlrcpp::Any visitProcCallNoParams(AslParser::ProcCallNoParamsContext *context) = 0;

    virtual antlrcpp::Any visitProcCallParams(AslParser::ProcCallParamsContext *context) = 0;

    virtual antlrcpp::Any visitReadStmt(AslParser::ReadStmtContext *context) = 0;

    virtual antlrcpp::Any visitWriteExpr(AslParser::WriteExprContext *context) = 0;

    virtual antlrcpp::Any visitWriteString(AslParser::WriteStringContext *context) = 0;

    virtual antlrcpp::Any visitReturnStmt(AslParser::ReturnStmtContext *context) = 0;

    virtual antlrcpp::Any visitLeftIdent(AslParser::LeftIdentContext *context) = 0;

    virtual antlrcpp::Any visitLeftArray(AslParser::LeftArrayContext *context) = 0;

    virtual antlrcpp::Any visitBoolean(AslParser::BooleanContext *context) = 0;

    virtual antlrcpp::Any visitExprFuncNoParams(AslParser::ExprFuncNoParamsContext *context) = 0;

    virtual antlrcpp::Any visitPars(AslParser::ParsContext *context) = 0;

    virtual antlrcpp::Any visitUnitary(AslParser::UnitaryContext *context) = 0;

    virtual antlrcpp::Any visitExprIdent(AslParser::ExprIdentContext *context) = 0;

    virtual antlrcpp::Any visitArithmetic(AslParser::ArithmeticContext *context) = 0;

    virtual antlrcpp::Any visitRelational(AslParser::RelationalContext *context) = 0;

    virtual antlrcpp::Any visitExprArray(AslParser::ExprArrayContext *context) = 0;

    virtual antlrcpp::Any visitValue(AslParser::ValueContext *context) = 0;

    virtual antlrcpp::Any visitExprFuncParams(AslParser::ExprFuncParamsContext *context) = 0;

    virtual antlrcpp::Any visitIdent(AslParser::IdentContext *context) = 0;


};

