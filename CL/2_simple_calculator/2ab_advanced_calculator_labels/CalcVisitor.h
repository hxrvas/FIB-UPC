
// Generated from Calc.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CalcParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CalcParser.
 */
class  CalcVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CalcParser.
   */
    virtual antlrcpp::Any visitProg(CalcParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitPrintExpr(CalcParser::PrintExprContext *context) = 0;

    virtual antlrcpp::Any visitAssign(CalcParser::AssignContext *context) = 0;

    virtual antlrcpp::Any visitBlank(CalcParser::BlankContext *context) = 0;

    virtual antlrcpp::Any visitNeg(CalcParser::NegContext *context) = 0;

    virtual antlrcpp::Any visitComp(CalcParser::CompContext *context) = 0;

    virtual antlrcpp::Any visitPlusMinus(CalcParser::PlusMinusContext *context) = 0;

    virtual antlrcpp::Any visitProd(CalcParser::ProdContext *context) = 0;

    virtual antlrcpp::Any visitMax(CalcParser::MaxContext *context) = 0;

    virtual antlrcpp::Any visitPars(CalcParser::ParsContext *context) = 0;

    virtual antlrcpp::Any visitDivis(CalcParser::DivisContext *context) = 0;

    virtual antlrcpp::Any visitFacto(CalcParser::FactoContext *context) = 0;

    virtual antlrcpp::Any visitId(CalcParser::IdContext *context) = 0;

    virtual antlrcpp::Any visitInt(CalcParser::IntContext *context) = 0;

    virtual antlrcpp::Any visitExprList(CalcParser::ExprListContext *context) = 0;


};

