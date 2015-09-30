%{
#include <stdio.h>
/*#include "lex.yy.c" [>É necessário adicionar o arquivo do analisador lexico gerado <]*/

void yyerror(const char *str)
{    fprintf(stderr,"error: %s\n",str);}
%}

%token ID
%token WILDSCORE
%token INT
%token FLOAT
%token BOOLVAL
%token BOOL
%token FLOAT_T
%token INTEGER

%start program

%%
program:  
    line_elems
	;

line_elems: 
    line_elem line_elems
    | line_elem
	;

line_elem:
    fundecl
    | procdecl
    | funtype_decl
	;

fundecl: 
    ID args "=" expr ';'
    | ID args "=" expr where_exp 
    | ID "=" expr ';'
    | ID "=" expr where_exp
	;

args:
    arg_value args 
    | arg_value
    | WILDSCORE
	;

arg_value:
    list_value
    | basic_value
    | "(" arg_value ")"
	;

basic_value: 
    INT
    | FLOAT
    | BOOLVAL
    | ID
    | "(" ")"
	;

list_value:
    basic_value ":" list_value
    list_value ":" list_value
    WILDSCORE ":" list_value
    | built_list_value
	;

built_list_value:
    "[" "]"
    | "[" args "]"
	;

funtype_decl:
    ID "::" funtype ';'
	;

funtype:
    basic_type
    | "(" funtype ")"
    | basic_type "->" funtype
	;

basic_type:
    INTEGER
    | FLOAT_T
    | BOOL
    | "[" basic_type "]" 
    | ID
    | "(" ")"
	;

appexpr:
    expr expr
	;

expr:
    op_prec1
    | appexpr
    | ifexpr
    | yieldexpr
	;

ifexpr:
    "if" expr "then" '{' expr '}' "else" '{' expr '}'
	;

yieldexpr:
    "yield" ifexpr
    | "yield" appexpr
    | "yield" op_prec1
	;

op_prec1:
     op_prec2 "||" op_prec1
     | op_prec2
	;

op_prec2:
     op_prec3 "&&" op_prec2
     | op_prec3
	;

op_prec3:
     op_prec3 "==" op_prec4
     | op_prec3 "/=" op_prec4
     | op_prec3 "<" op_prec4
     | op_prec3 "<=" op_prec4
     | op_prec3 ">" op_prec4
     | op_prec3 ">=" op_prec4
     op_prec4
	;

op_prec4:
     op_prec5 ":" op_prec4
     | op_prec5 "++" op_prec4
     | op_prec5
	;

op_prec5:
    op_prec5 "+" op_prec6
    | op_prec5 "-" op_prec6
    | op_prec6
	;

op_prec6:
     op_prec6 "%" op_prec7
     | op_prec7
	;

op_prec7:
    op_prec7 "*" op_prec8
    | op_prec7 "/" op_prec8
    | op_prec8
	;

op_prec8:
    basic_value
    | list_expr
    | "(" expr ")"
    | "-" expr
	;

exprs:
    expr
    | expr "," exprs
	;


list_expr:
    | "[" exprs "]"
    | "[" "]"
	;


where_exp:
    "where" '{' line_elems '}' 
	;

procdecl:
    ID args "=" "do" '{' stmts '}'
    | ID args "=" "do" '{' stmts '}' where_exp
    | ID "=" "do" '{' stmts '}'
    | ID "=" "do" '{' stmts '}' where_exp
	;

stmts:
    stmt
    | stmt stmts
	;

stmt:
    ID "<-" expr ';'
    | ID "<-" while_expr ';'
    | ID "<-" io_stmt ';'
    | expr ';'
    | while_expr ';'
    | io_stmt ';'
	;

io_stmt:
    | "readInt"
    | "readFloat"
    | "readBool"
    | "print" expr
	;

while_expr:
    "while" "(" expr ")" '{' stmts '}' 
	;
%%

int main(int argc, char** argv) {

    if(argc > 1) {
        yyin = fopen(argv[1], "r");
    }

    yyparse();

    return 0;
}
