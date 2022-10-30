
// Generated from Calc.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CalcVisitor.h"


/**
 * This class provides an empty implementation of CalcVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CalcBaseVisitor : public CalcVisitor {
public:

  virtual antlrcpp::Any visitProg(CalcParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrintExpr(CalcParser::PrintExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign(CalcParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlank(CalcParser::BlankContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNeg(CalcParser::NegContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComp(CalcParser::CompContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPlusMinus(CalcParser::PlusMinusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProd(CalcParser::ProdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMax(CalcParser::MaxContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPars(CalcParser::ParsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDivis(CalcParser::DivisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFacto(CalcParser::FactoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitId(CalcParser::IdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInt(CalcParser::IntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprList(CalcParser::ExprListContext *ctx) override {
    return visitChildren(ctx);
  }


};

