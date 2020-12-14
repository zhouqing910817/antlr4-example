grammar Expr;
stat : selectSql ;

selectSql : select column from table nl ;

select : 'select' | 'SELECT' ;

column : '*'
        | col (',' col)*
       ;
col : STRING ;
from : 'from' | 'FROM' ;
table : STRING;

where : 'where' | 'WHERE' ;
condition : col op value ;

op : '>'
   | '<'
   | '='
   | '!='
   ;

value : STRING
      | INT
      ;

nl : ';'
   | nl '\r'? '\n';

STRING : [a-zA-Z_]+ ;
INT : [0-9]+ ;
WS : [ \t] -> skip ;
