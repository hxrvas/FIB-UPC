if __name__ is not None and "." in __name__:
    from .FunxParser import FunxParser
    from .FunxVisitor import FunxVisitor
else:
    from FunxParser import FunxParser
    from FunxVisitor import FunxVisitor
    
class TreeVisitor(FunxVisitor):
    def __init__(self):
        self.nivell = 0


    # Visit a parse tree produced by FunxParser#arithmetic.
    def visitArithmetic(self, ctx):
        l = list(ctx.getChildren())
        print('  ' *  self.nivell + l[1].getText())
        self.nivell += 1
        self.visit(l[0])
        self.visit(l[2])
        self.nivell -= 1

    def visitIdent(self, ctx):
        l = list(ctx.getChildren())
        print("  " * self.nivell +
            FunxParser.symbolicNames[l[0].getSymbol().type] +
            '(' +l[0].getText() + ')')
 

    def visitValue(self, ctx):
        l = list(ctx.getChildren())
        print("  " * self.nivell +
            FunxParser.symbolicNames[l[0].getSymbol().type] +
            '(' +l[0].getText() + ')')

