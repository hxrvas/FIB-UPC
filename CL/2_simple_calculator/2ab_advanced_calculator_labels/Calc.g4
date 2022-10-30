grammar Calc;

prog:  stat+ EOF ;

stat:  expr NEWLINE           # printExpr
    |  ID '=' expr NEWLINE    # assign
    |  NEWLINE                # blank
    ;

expr:  expr MUL expr        # prod
    |  expr DIV expr        # divis
    |  expr (ADD|SUB) expr  # plusMinus
    |  SUB expr             # neg
    |  expr FACT            #facto
    |  expr (GT|LT|EQ) expr #comp
    |  INT                  # int
    |  ID                   # id
    |  '(' expr ')'         # pars
    |  MAX '(' exprList ')' # max
    ;

exprList
    : expr (',' expr)*
    ;


MAX : 'max' ;
MUL :  '*' ;
DIV :  '/' ;
ADD :  '+' ;
SUB : '-' ;
FACT: '!' ;
GT :  '>' ;
LT :  '<' ;
EQ :  '=''=';
ID  :  [a-zA-Z]+ ;       // match identifiers
INT :  [0-9]+ ;          // match integers
NEWLINE: '\r'? '\n' ;    // return newlines to parser (is end-statement signal)
WS  :  [ \t]+ -> skip ;  // toss out whitespace
