grammar Expr;

s : e EOF ;

e : e MUL e  // MUL is '*'
  | e DIV e  // DIV is '/'
  | e ADD e  // ADD is '+'
  | e SUB e  // SUB is '-'
  | INT
  ;

MUL : '*' ;
DIV : '/' ;
ADD : '+' ;
SUB : '-' ;
INT : [0-9]+ ;
WS  : [ \t\n]+ -> skip ;
