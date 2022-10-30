grammar Expr;

s : e ;

e : e '*' e
  | e ('+'|'-') e
  | FUNC '(' e ',' e ')'
  | e '/' e
  | INT
  ;

INT : [0-9]+ ;
FUNC : 'max' | 'min';
WS  : [ \t\n]+ -> skip ;
