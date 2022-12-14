 
if __name__ is not None and "." in __name__:
    from .FunxParser import FunxParser
    from .FunxVisitor import FunxVisitor
else:
    from FunxParser import FunxParser
    from FunxVisitor import FunxVisitor
from antlr4 import *
from FunxLexer import FunxLexer
from FunxParser import FunxParser
import sys

from flask import Flask, render_template, request


class TreeVisitor(FunxVisitor):
    def __init__(self):
        self.GlobalScope = dict()
        self.ScopeStack = []

    def visitRoot(self, ctx):
        #print("Visiting Root")
        l = list(ctx.getChildren())
        for i in range(len(l) - 2):
            self.visit(l[i])
        result = str(self.visit(l[len(l) - 2]))
        return result

    def visitFunction(self, ctx):
        #print("Visiting Function")
        l = list(ctx.getChildren())
        Scope = {
            "Params": self.visit(l[1]),
            "Code": l[3]
        }
        if l[0].getText() in self.GlobalScope:
            raise Exception("Function already defined")
        self.GlobalScope[l[0].getText()] = Scope

    def visitParameters(self, ctx):
        #print("Visiting Params")
        params = []
        l = list(ctx.getChildren())
        for c in l:
            if c.getText() in params:
                raise Exception("Duplicate parameter")
            params.append(c.getText())
        return params

    def visitStatements(self, ctx):
        #print("Visiting Function Statements")
        l = list(ctx.getChildren())
        for c in l:
            ret = self.visit(c)
            if ret is not None:
                return ret

    def visitAssignStmt(self, ctx):
        #print("Visiting Assign")
        l = list(ctx.getChildren())
        self.ScopeStack[len(self.ScopeStack) -
                        1][l[0].getText()] = self.visit(l[2])

    def visitIfStmt(self, ctx):
        #print("VisitiDIVng If")
        l = list(ctx.getChildren())
        cond = self.visit(l[1]) == 1
        if cond:
            return self.visit(l[3])
        elif len(l) > 5:
            return self.visit(l[7])

    def visitWhileStmt(self, ctx):
        #print("Visiting While")
        l = list(ctx.getChildren())
        cond = self.visit(l[1]) == 1
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
        l = list(ctx.getChildren())
        return (self.visit(l[1]))

    def visitArithmetic(self, ctx):
        #print("Visiting Arithmetic")
        l = list(ctx.getChildren())
        value1 = self.visit(l[0])
        value2 = self.visit(l[2])
        op = FunxParser.symbolicNames[l[1].getSymbol().type]
        if op == "MUL":
            return value1 * value2
        elif op == "DIV":
            if value2 == 0:
                raise Exception("Division by zero")
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
        if l[0].getText() not in self.GlobalScope:
            raise Exception("Function not defined")
        d = self.GlobalScope[l[0].getText()]
        Scope = dict()
        n = len(d["Params"])
        m = len(l[1:])
        if n != m:
            raise Exception("Invalid number of parameters")
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
        if l[0].getText() not in self.ScopeStack[len(self.ScopeStack) - 1]:  # noqa: E501
            raise Exception("Variable not defined")
        return self.ScopeStack[len(self.ScopeStack) - 1][l[0].getText()]

    def visitValue(self, ctx):
        #print("Visiting Value")
        l = list(ctx.getChildren())
        return int(l[0].getText())

app = Flask(__name__)
visitor = TreeVisitor()
results = []
@app.route('/')
def index():    
    return render_template('base.html',results=results, functions=visitor.GlobalScope, error="")

@app.route('/result', methods=['POST', 'GET'])
def result():
    if request.method == 'POST':
        try:
            input_stream = InputStream(request.form.get('input', type=str))
            lexer = FunxLexer(input_stream)
            token_stream = CommonTokenStream(lexer)
            parser = FunxParser(token_stream)
            tree = parser.root() 
            out = visitor.visit(tree)
            result = str(input_stream)
            results.append(result)
            result = str(out)
            results.append(result)

            if len(results) > 12:
                results.pop(0)
                results.pop(0)

            functions = visitor.GlobalScope
            return render_template("base.html", results=results, functions=functions, error="")
        except Exception as e:
            return render_template("base.html", results=results, functions=visitor.GlobalScope, error=e)



""" while True:
    try:
        input_stream = InputStream(input('? '))
        lexer = FunxLexer(input_stream)
        token_stream = CommonTokenStream(lexer)
        parser = FunxParser(token_stream)
        tree = parser.root() 
        out = visitor.visit(tree)

        print("In " + str(i) + ": " + str(input_stream))
        print("Out " + str(i) + ": " + str(out))
        i += 1
    except Exception as e:
        print(e) """
