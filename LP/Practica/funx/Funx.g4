grammar Funx;

//////////////////////////////////////////////////
/// Parser Rules
//////////////////////////////////////////////////


root : function* expr? EOF
     ;

// A function has a name, a list of parameters and a list of statements
function
        :FUNCID (parameters)? '{' statements '}'
        ;

parameters
        : VARID (VARID)*
        ;

statements
        : (statement)*
        ;

// The different types of instructions
statement
        // Assignació
        : left_expr ASSIGN expr                                 # assignStmt
        // if else (else optional)
        | IF expr '{' statements '}' (ELSE '{' statements '}')? # ifStmt
        // Iteració amb while
        | WHILE expr '{' statements '}'                         # whileStmt
        | expr                                                  # returnStmt
        ;

// Grammar for left expressions (l-values in C++)
left_expr
        : ident                               # leftIdent
        ;

// Grammar for expressions with boolean, relational and aritmetic operators
expr    
        : '(' expr ')'                        # pars
        | FUNCID (expr (expr)*)?           # funcExpr
        //| (PLUS|MINUS) expr                # unitary
        | expr (MUL|DIV|MOD) expr          # arithmetic
        | expr (PLUS|MINUS) expr           # arithmetic
        | expr (E|NE|GE|LE|GT|LT) expr     # relational
        | ident                               # exprIdent
        | (INT)                               # value
        ;

// Identifiers
ident   : VARID
        ;

//////////////////////////////////////////////////
/// Lexer Rules
//////////////////////////////////////////////////

ASSIGN    : '<-' ;
E         : '=' ;
NE        : '!=' ;
GE        : '>=' ;
LE        : '<=' ;
GT        : '>' ;
LT        : '<' ;
PLUS      : '+' ;
MINUS     : '-' ;
MUL       : '*';
DIV       : '/';
MOD       : '%';
IF        : 'if' ;
ELSE      : 'else' ;
WHILE     : 'while' ;
DO        : 'do' ;
FUNC      : 'func' ;
RETURN    : 'return' ;
INT       : ('0'..'9')+ ;
VARID     : ('a'..'z') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')* ;
FUNCID    : ('A'..'Z') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')* ;


COMMENT   : '#' ~('\n'|'\r')* '\r'? '\n' -> skip ;

WS        : [ \t\r\n]+ -> skip ;