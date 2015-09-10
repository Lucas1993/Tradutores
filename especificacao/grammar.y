program:  
    line_elems

line_elems: 
    line_elem line_elems
    | line_elem

line_elem:
    fundecl
    | procdecl
    | funtype_decl

fundecl: 
    ID args '=' expr ';'
    | ID args '=' expr where_exp 
    | ID '=' expr ';'
    | ID '=' expr where_exp

args:
    arg_value args 
    | arg_value
    | WILDSCORE

arg_value:
    list_value
    | basic_value
    | '(' arg_value ')'

basic_value: 
    INT
    | FLOAT
    | BOOLVAL
    | ID
    | '(' ')'

list_value:
    arg_value ':' list_value
    | built_list_value

built_list_value:
    '[' ']'
    | '[' args ']'

funtype_decl:
    ID '::' funtype ';'

funtype:
    basic_type
    | '(' funtype ')'
    | basic_type '->' funtype

basic_type:
    INTEGER
    | FLOAT_T
    | BOOL
    | '[' types ']' 
    | ID
    | '(' ')'

types:
    basic_type
    | basic_type ',' types

expr:
    op_prec1
    | appexp
    | ifexpr
    | yieldexpr

ifexpr:
    'if' expr 'then' '{' expr '}' 'else' '{' expr '}'

yieldexpr:
    "yield" ifexpr
    | "yield" appexpr
    | "yield" op_prec1


op_prec1:
     op_prec2 '||' op_prec1
     | op_prec2

op_prec2:
     op_prec3 '&&' op_prec2
     | op_prec3

op_prec3:
     op_prec3 '==' op_prec4
     | op_prec3 '/=' op_prec4
     | op_prec3 '<' op_prec4
     | op_prec3 '<=' op_prec4
     | op_prec3 '>' op_prec4
     | op_prec3 '>=' op_prec4
     op_prec4

op_prec4:
     op_prec5 ':' op_prec4
     | op_prec5 '++' op_prec4
     | op_prec5

op_prec5:
    op_prec5 '+' op_prec6
    | op_prec5 '-' op_prec6
    | op_prec6

op_prec6:
     op_prec6 '%' op_prec7
     | op_prec7

op_prec7:
    op_prec7 '*' op_prec8
    | op_prec7 '/' op_prec8
    | op_prec8

op_prec8:
    basic_value
    | list_expr
    | '(' expr ')'
    | '-' expr

exprs:
    expr
    | expr ',' exprs


list_expr:
    | '[' exprs ']'
    | '[' ']'

appexp:
    ID expr

where_exp:
    'where' '{' line_elems '}' 

procdecl:
    ID args '=' 'do' '{' stmts '}'
    | ID args '=' 'do' '{' stmts '}' where_exp
    | ID '=' 'do' '{' stmts '}'
    | ID '=' 'do' '{' stmts '}' where_exp

stmts:
    stmt
    | stmt stmts

stmt:
    basic_value '<-' expr ';'
    | basic_value '<-' while_expr ';'
    | basic_value '<-' io_stmt ';'
    | expr ';'
    | while_expr ';'
    | io_stmt ';'

io_stmt:
    | 'readInt'
    | 'readFloat'
    | 'readBool'
    | 'print' expr

while_expr:
    'while' '(' expr ')' '{' stmts '}' 
