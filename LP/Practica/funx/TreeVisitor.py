if __name__ is not None and "." in __name__:
    from .FunxParser import FunxParser
    from .FunxVisitor import FunxVisitor
else:
    from FunxParser import FunxParser
    from FunxVisitor import FunxVisitor
    
class TreeVisitor(FunxVisitor):
    #def __init__(self):

    def visitRoot(self, ctx):
        print("Visiting Root")
        l = list(ctx.getChildren())
        result = str(self.visit(l[len(l)-2]))
        print("Out: "+result)

    def visitPars(self, ctx):
        print("Visiting Pars")
        l=list(ctx.getChildren())
        return(self.visit(l[1]))

    def visitArithmetic(self, ctx):
        print("Visiting Arithmetic")
        l = list(ctx.getChildren())
        value1 = self.visit(l[0])
        value2 = self.visit(l[2])
        op = FunxParser.symbolicNames[l[1].getSymbol().type]   
        if op == "MUL": 
            return value1 * value2
        elif op == "DIV": 
            return value1 // value2
        elif op == "MOD": 
            return value1 % value2
        elif op == "PLUS":
            return value1 + value2
        elif op == "MINUS":
            return value1 - value2

    def visitRelational(self, ctx):
        print("Visiting Relational")
        l = list(ctx.getChildren())
        value1 = self.visit(l[0])
        value2 = self.visit(l[2])
        op = FunxParser.symbolicNames[l[1].getSymbol().type]

        if op == "E": 
            return int(value1 == value2)
        elif op == "NE": 
            return int(value1 != value2)
        elif op == "GE": 
            return int(value1 >= value2)
        elif op == "LE":
            return int(value1 <= value2)
        elif op == "GT":
            return int(value1 > value2)
        elif op == "LT":
            return int(value1 < value2)
        
    def visitIdent(self, ctx):
        l = list(ctx.getChildren())
        print("  " * self.nivell +
            FunxParser.symbolicNames[l[0].getSymbol().type] +
            '(' +l[0].getText() + ')')
 

    def visitValue(self, ctx):
        print("Visiting Value")
        l = list(ctx.getChildren())
        return int(l[0].getText())

