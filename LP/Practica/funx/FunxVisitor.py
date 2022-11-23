# Generated from Funx.g4 by ANTLR 4.7.2
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .FunxParser import FunxParser
else:
    from FunxParser import FunxParser

# This class defines a complete generic visitor for a parse tree produced by FunxParser.

class FunxVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by FunxParser#root.
    def visitRoot(self, ctx:FunxParser.RootContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by FunxParser#function.
    def visitFunction(self, ctx:FunxParser.FunctionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by FunxParser#parameters.
    def visitParameters(self, ctx:FunxParser.ParametersContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by FunxParser#statements.
    def visitStatements(self, ctx:FunxParser.StatementsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by FunxParser#assignStmt.
    def visitAssignStmt(self, ctx:FunxParser.AssignStmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by FunxParser#ifStmt.
    def visitIfStmt(self, ctx:FunxParser.IfStmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by FunxParser#whileStmt.
    def visitWhileStmt(self, ctx:FunxParser.WhileStmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by FunxParser#returnStmt.
    def visitReturnStmt(self, ctx:FunxParser.ReturnStmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by FunxParser#leftIdent.
    def visitLeftIdent(self, ctx:FunxParser.LeftIdentContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by FunxParser#funcExpr.
    def visitFuncExpr(self, ctx:FunxParser.FuncExprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by FunxParser#pars.
    def visitPars(self, ctx:FunxParser.ParsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by FunxParser#exprIdent.
    def visitExprIdent(self, ctx:FunxParser.ExprIdentContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by FunxParser#arithmetic.
    def visitArithmetic(self, ctx:FunxParser.ArithmeticContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by FunxParser#relational.
    def visitRelational(self, ctx:FunxParser.RelationalContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by FunxParser#value.
    def visitValue(self, ctx:FunxParser.ValueContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by FunxParser#ident.
    def visitIdent(self, ctx:FunxParser.IdentContext):
        return self.visitChildren(ctx)



del FunxParser