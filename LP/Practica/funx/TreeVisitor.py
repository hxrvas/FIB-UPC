if __name__ is not None and "." in __name__:
    from .FunxParser import FunxParser
    from .FunxVisitor import FunxVisitor
else:
    from FunxParser import FunxParser
    from FunxVisitor import FunxVisitor
    
class TreeVisitor(FunxVisitor):
    def __init__(self):
        self.GlobalScope = dict()
        self.ScopeStack = []

    def visitRoot(self, ctx):
        #print("Visiting Root")
        l = list(ctx.getChildren())
        for i in range (len(l)-2):
            self.visit(l[i])
        result = str(self.visit(l[len(l)-2]))
        print("Out: "+result)
    
     
    def visitFunction(self, ctx):
        #print("Visiting Function")
        l = list(ctx.getChildren())
        Scope = {
           "Params" : self.visit(l[1]),
           "Code" : l[3]
        }
        self.GlobalScope[l[0].getText()] = Scope

    def visitParameters(self, ctx):
        #print("Visiting Params")
        params = []
        l = list(ctx.getChildren())
        for c in l:
            params.append(c.getText())
        return params

    # Visit a parse tree produced by FunxParser#statements.
    def visitStatements(self, ctx):
        #print("Visiting Function Statements")
        l = list(ctx.getChildren())
        for c in l:
            ret = self.visit(c)
            if ret != None:
                return ret

    
    def visitAssignStmt(self, ctx):
        #print("Visiting Assign")
        l = list(ctx.getChildren())
        self.ScopeStack[len(self.ScopeStack)-1][l[0].getText()] = self.visit(l[2])


    def visitIfStmt(self, ctx):
        #print("Visiting If")
        l = list(ctx.getChildren())
        cond =self.visit(l[1]) == 1
        if cond:
            return self.visit(l[3])
        elif len(l) > 5:
            return self.visit(l[7])
        


    def visitWhileStmt(self, ctx):
        #print("Visiting While")
        l = list(ctx.getChildren())
        cond =self.visit(l[1]) == 1
        while cond:
            self.visit(l[3])
            cond = self.visit(l[1]) == 1
        return self.visitChildren(ctx)


    def visitReturnStmt(self, ctx):
        #print("Visiting Return Expr")
        l = list(ctx.getChildren())
        return self.visit(l[0])


    def visitPars(self, ctx):
        #print("Visiting Pars")
        l=list(ctx.getChildren())
        return(self.visit(l[1]))

    def visitArithmetic(self, ctx):
        #print("Visiting Arithmetic")
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
        #print("Visiting Relational")
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

   
    def visitFuncExpr(self, ctx):
        #print("Visiting Function Call")
        l = list(ctx.getChildren())
        d = self.GlobalScope[l[0].getText()]
        Scope = dict()
        i = 1
        for param in d["Params"]:
            Scope[param] = self.visit(l[i])
            i += 1
        self.ScopeStack.append(Scope)
        result = self.visit(d["Code"])
        self.ScopeStack.pop()
        return result

    def visitIdent(self, ctx):
        #print("Visiting Ident")
        l = list(ctx.getChildren())
        return self.ScopeStack[len(self.ScopeStack)-1][l[0].getText()]
 

    def visitValue(self, ctx):
        #print("Visiting Value")
        l = list(ctx.getChildren())
        return int(l[0].getText())

