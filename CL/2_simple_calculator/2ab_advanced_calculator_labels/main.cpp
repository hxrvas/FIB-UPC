
#include "antlr4-runtime.h"
#include "CalcLexer.h"
#include "CalcParser.h"
#include "CalcBaseVisitor.h"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdio>     // fopen
#include <cstdlib>    // EXIT_FAILURE, EXIT_SUCCESS

// using namespace std;
// using namespace antlr4;
// using namespace antlrcpp;


//////////////////////////////////////////////////////////////////////
// Sample "calculator" (implemented with a visitor)
class Calculator : public CalcBaseVisitor {
public:
  // "memory" for the calculator; variable/value pairs go here
  std::map<std::string, int> memory;

  // stat : expr NEWLINE
  antlrcpp::Any visitPrintExpr(CalcParser::PrintExprContext *ctx) {
    int value = visit(ctx->expr());         // evaluate the expr child
    std::cout << value << std::endl;        // print the result
    return 0;                               // return dummy value
  }

  // stat : ID '=' expr NEWLINE
  antlrcpp::Any visitAssign(CalcParser::AssignContext *ctx) {
    std::string id = ctx->ID()->getText();  // id is left-hand side of '='
    int value = visit(ctx->expr());         // compute value of expression on right
    memory[id] = value;                     // store it in the memory
    return 0;                               // return dummy value
  }

  // expr : expr MUL expr
  antlrcpp::Any visitProd(CalcParser::ProdContext *ctx) {
    int left = visit(ctx->expr(0));         // get value of left subexpression
    int right = visit(ctx->expr(1));        // get value of right subexpression
    return left*right;
  }
  // expr : expr DIV expr
  antlrcpp::Any visitDivis(CalcParser::DivisContext *ctx) {
    int left = visit(ctx->expr(0));         // get value of left subexpression
    int right = visit(ctx->expr(1));        // get value of right subexpression
    return left/right;
  }
  
  // expr : expr (ADD|SUB) expr
  antlrcpp::Any visitPlusMinus(CalcParser::PlusMinusContext *ctx) {
    int left = visit(ctx->expr(0));         // get value of left subexpression
    int right = visit(ctx->expr(1));        // get value of right subexpression
    if (ctx->ADD())
        return left+right;
    else
        return left-right;
  }

  // expr : SUB expr
  antlrcpp::Any visitNeg(CalcParser::NegContext *ctx) {
    int left = visit(ctx->expr());         // get value of left subexpression
    return -left;
  }

  // expr : expr FACT
  antlrcpp::Any visitFacto(CalcParser::FactoContext *ctx) {
    int left = visit(ctx->expr());         // get value of left subexpression
    int result = 1;
      for (int i = 2; i <= left; ++i) {
          result *= i;
      }
      return result;
  }

    // expr : SUB expr
  antlrcpp::Any visitPars(CalcParser::ParsContext *ctx) {
    int left = visit(ctx->expr());         // get value of left subexpression
    return left;
  }

    // expr : expr (GT|LT|EQ) expr
  antlrcpp::Any visitComp(CalcParser::CompContext *ctx) {
    int left = visit(ctx->expr(0));         // get value of left subexpression
    int right = visit(ctx->expr(1));        // get value of right subexpression
    if (ctx->GT())
        return int(left>right);
    else if (ctx->LT())
        return int(left<right);
    else return int(left==right);
  }

      // expr : expr (GT|LT|EQ) expr
  antlrcpp::Any visitMax(CalcParser::MaxContext *ctx) {
    int max = visit(ctx -> exprList() -> expr(0));
    for (auto & oneExpr : ctx->exprList()->expr()) {
        int val = visit(oneExpr);
        if (val > max) max = val;
    }
    return max;
  }
  
        // expr : expr (GT|LT|EQ) expr
  antlrcpp::Any visitExprList(CalcParser::ExprListContext *ctx) {
    return visitChildren(ctx);
  }

  // expr : INT
  antlrcpp::Any visitInt(CalcParser::IntContext *ctx) {
    return std::stoi(ctx->INT()->getText());       // or: ctx->getText()
  }
  
  // expr : ID
  antlrcpp::Any visitId(CalcParser::IdContext *ctx) {
    std::string id = ctx->ID()->getText();         // or: ctx->getText()
    if (memory.find(id) != memory.end()) return memory[id];
    return 0;
  }
};
// Sample "calculator" (implemented with a visitor)
//////////////////////////////////////////////////////////////////////


int main(int argc, const char* argv[]) {
  // check the correct use of the program
  if (argc > 2) {
    std::cout << "Usage: ./main [<file>]" << std::endl;
    return EXIT_FAILURE;
  }
  if (argc == 2 and not std::fopen(argv[1], "r")) {
    std::cout << "No such file: " << argv[1] << std::endl;
    return EXIT_FAILURE;
  }

  // open input file (or std::cin) and create a character stream
  antlr4::ANTLRInputStream input;
  if (argc == 2) {  // reads from <file>
    std::ifstream stream;
    stream.open(argv[1]);
    input = antlr4::ANTLRInputStream(stream);
  }
  else {            // reads fron std::cin
    input = antlr4::ANTLRInputStream(std::cin);
  }

  // create a lexer that consumes the character stream and produce a token stream
  CalcLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);

  // create a parser that consumes the token stream, and parses it.
  CalcParser parser(&tokens);

  // call the parser and get the parse tree. prog is the initial rule
  antlr4::tree::ParseTree *tree = parser.prog();

  // check for lexical or syntactical errors
  if (lexer.getNumberOfSyntaxErrors() > 0 or
      parser.getNumberOfSyntaxErrors() > 0) {
    std::cout << "Lexical and/or syntactical errors have been found." << std::endl;
    return EXIT_FAILURE;
  }
  
  // print the parse tree (for debugging purposes)
  std::cout << tree->toStringTree(&parser) << std::endl;

  ////////////////////////////////////////////////////////////////////

  // Create a visitor that will execute the statements
  Calculator calc;

  // Traverse the tree using this Calculator visitor
  calc.visit(tree);

  return EXIT_SUCCESS;
}
