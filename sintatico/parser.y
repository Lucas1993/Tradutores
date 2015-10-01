%{
#include <stdio.h>
#include <string.h>
#include "ast.h"

/*Macro para alocar e inicializar a struct toda com 0*/
#define NEW(TYPE) memset(malloc(sizeof(TYPE)), 0, sizeof(TYPE))

void yyerror(const char *str)
{    fprintf(stderr,"error: %s\n",str);}
%}

%token <str> ID
%token WILDSCORE
%token FLOAT
%token BOOLVAL
%token BOOL
%token NUMBER
%token FLOATNUM
%token INTEGER
%token IF
%token ELSE
%token THEN
%token WHILE
%token WHERE
%token YIELD
%token DO
%token PRINT
%token READBOOL
%token READFLOAT
%token READINT
%token RARROW
%token LARROW
%token DIFF
%token EQUALS
%token DOUBLECOLON
%token APPEND
%token AND
%token OR
%token LEQ
%token GEQ

%union {
    while_t* while_f;          
    io_t* io_f;             
    stmt_t* stmt_f;           
    stmts_t* stmts_f;          
    proc_t* proc_f;           
    list_t* list_f;           
    appexpr_t* appexpr_f;        
    where_t* where_f;          
    exprs_t* exprs_f;       
    op_t* op_f;             
    yieldexpr_t* yieldexpr_f;      
    ifexpr_t* ifexpr_f;         
    expr_t* expr_f;           
    basic_type_t* basic_type_f;     
    funtype_t* funtype_f;        
    funtype_decl_t* funtype_decl_f;   
    basic_val_t* basic_val_f;      
    arg_t* arg_f;            
    fun_t* fun_f;            
    lines_t* lines_f;          
    line_t* line_f;           
    args_t* args_f;           
    program_t* program_f;        
    list_args_t* list_args_f;      
    built_list_val_t* built_list_val_f; 
    char* str;
}


%type    <while_f> while_expr
%type    <io_f> io_stmt
%type    <stmt_f> stmt
%type    <stmts_f>stmts
%type    <proc_f> procdecl
%type    <list_f> list_value
%type    <appexpr_f> appexpr
%type    <where_f> where_exp          
%type    <exprs_f> list_expr
%type    <exprs_f> exprs
%type    <op_f> op_prec1
%type    <op_f> op_prec2
%type    <op_f> op_prec3
%type    <op_f> op_prec4
%type    <op_f> op_prec5
%type    <op_f> op_prec6
%type    <op_f> op_prec7
%type    <op_f> op_prec8
%type    <yieldexpr_f> yieldexpr     
%type    <ifexpr_f> ifexpr
%type    <expr_f> expr  
%type    <basic_type_f> basic_type     
%type    <funtype_f> funtype
%type    <funtype_decl_f> funtype_decl
%type    <basic_val_f> basic_value
%type    <arg_f> arg_value 
%type    <fun_f> fundecl  
%type    <lines_f> line_elems    
%type    <line_f> line_elem
%type    <args_f> args 
%type    <program_f> program      
%type    <list_args_f> list_args
%type    <built_list_val_f> built_list_value


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
    ID args '=' expr ';'
    | ID args '=' expr where_exp 
    | ID '=' expr ';'
    | ID '=' expr where_exp
	;

args:
    arg_value args 
    | arg_value
    | WILDSCORE
	;

arg_value:
    list_value
    | basic_value
    | '(' arg_value ')'
	;

basic_value: 
    NUMBER 
    | FLOATNUM
    | BOOLVAL
    | ID
    | '(' ')'
	;

list_value:
    basic_value ':' list_value
    '[' list_args ']' ':' list_value
    | WILDSCORE ':' list_value
    | built_list_value
	;

list_args:
         arg_value
         | arg_value ',' list_args
         ;

built_list_value:
    '[' ']'
    | '[' list_args ']'
	;

funtype_decl:
    ID DOUBLECOLON funtype ';'
	;

funtype:
    basic_type
    | '(' funtype ')'
    | basic_type RARROW funtype
	;

basic_type:
    INTEGER
    | FLOAT
    | BOOL
    | '[' basic_type ']' 
    | ID
    | '(' ')'
	;

appexpr:
       appexpr nonapp
       | nonapp nonapp
	;

nonapp:
      basic_value
      | '(' expr ')'
      ;

expr:
    op_prec1
    | appexpr
    | ifexpr
    | yieldexpr
	;

ifexpr:
    IF expr THEN '{' expr '}' ELSE '{' expr '}'
	;

yieldexpr:
    YIELD ifexpr
    | YIELD appexpr
    | YIELD op_prec1
	;

op_prec1:
    op_prec2 OR op_prec1 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_OR;
        tmp->opt.opt1 = $1;
        tmp->opt2 = $3;
        $$ = tmp;
    
    }
    | op_prec2 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = $1;
        $$ = tmp;
    }
	;

op_prec2:
    op_prec3 AND op_prec2 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_AND;
        tmp->opt.opt1 = $1;
        tmp->opt2 = $3;
        $$ = tmp;
    
    }
    | op_prec3 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = $1;
        $$ = tmp;
    }
	;

op_prec3:
    op_prec4 EQUALS op_prec3 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_EQ;
        tmp->opt.opt1 = $1;
        tmp->opt2 = $3;
        $$ = tmp;
    
    }
    | op_prec4 DIFF op_prec3 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_DIFF;
        tmp->opt.opt1 = $1;
        tmp->opt2 = $3;
        $$ = tmp;
    
    }
    | op_prec4 '<' op_prec3 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_LESS;
        tmp->opt.opt1 = $1;
        tmp->opt2 = $3;
        $$ = tmp;
    
    }
    | op_prec4 LEQ op_prec3 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_LEQ;
        tmp->opt.opt1 = $1;
        tmp->opt2 = $3;
        $$ = tmp;
    
    }
    | op_prec4 '>' op_prec3 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_GREATER;
        tmp->opt.opt1 = $1;
        tmp->opt2 = $3;
        $$ = tmp;
    
    }
    | op_prec4 GEQ op_prec3 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_GEQ;
        tmp->opt.opt1 = $1;
        tmp->opt2 = $3;
        $$ = tmp;
    
    }
    | op_prec4 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = $1;
        $$ = tmp;
    }
	;

op_prec4:
    op_prec5 ':' op_prec4 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_CONS;
        tmp->opt.opt1 = $1;
        tmp->opt2 = $3;
        $$ = tmp;
    
    }
    | op_prec5 APPEND op_prec4 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_APPEND;
        tmp->opt.opt1 = $1;
        tmp->opt2 = $3;
        $$ = tmp;
    
    }
    | op_prec5 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = $1;
        $$ = tmp;
    }
	;

op_prec5:
    op_prec5 '+' op_prec6 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_PLUS;
        tmp->opt.opt1 = $1;
        tmp->opt2 = $3;
        $$ = tmp;
    
    }
    | op_prec5 '-' op_prec6 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_MINUS;
        tmp->opt.opt1 = $1;
        tmp->opt2 = $3;
        $$ = tmp;
    
    }
    | op_prec6 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = $1;
        $$ = tmp;
    }
	;

op_prec6:
     op_prec6 '%' op_prec7
     | op_prec7 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = $1;
        $$ = tmp;
     }
	 ;

op_prec7:
    op_prec7 '*' op_prec8
    | op_prec7 '/' op_prec8
    | op_prec8 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = $1;
        $$ = tmp;
    }
	;

op_prec8:
    basic_value {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_BVALUE;
        tmp->opt.bval = $1;
        $$ = tmp;
    }
    | list_expr {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_LIST;
        tmp->opt.lexpr = $1;
        $$ = tmp;
    }
    | '(' expr ')' {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_EXPR;
        tmp->opt.expr = $2;
        $$ = tmp;
    }
    | '-' op_prec8 {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEG;
        tmp->opt.opt1 = $2;
        $$ = tmp;
    }
	;

exprs:
    expr {
        exprs_t* tmp = NEW(exprs_t);
        tmp->expr = $1;
        $$ = tmp;
    }
    | expr ',' exprs {
        exprs_t* tmp = NEW(exprs_t);
        tmp->expr = $1;
        tmp->next = $3;
        $$ = tmp;
    
    }
	;

list_expr:
     '[' exprs ']' {
        $$ = $2;
     }
    | '[' ']' {
        $$ = NEW(exprs_t);
    }
	;


where_exp:
    WHERE '{' line_elems '}'  {
        where_t* tmp = NEW(where_t);
        tmp->lines = $3;
        $$ = tmp;
    }
	;

procdecl:
    ID args '=' DO '{' stmts '}' { 
        proc_t* tmp = NEW(proc_t);
        tmp->label = $1;
        tmp->args = $2;
        tmp->stmts = $6;
        $$ = tmp;
    }
    | ID args '=' DO '{' stmts '}' where_exp { 
        proc_t* tmp = NEW(proc_t);
        tmp->label = $1;
        tmp->args = $2;
        tmp->stmts = $6;
        tmp->where_exp = $8;
        $$ = tmp;
    }
    | ID '=' DO '{' stmts '}' { 
        proc_t* tmp = NEW(proc_t);
        tmp->label = $1;
        tmp->stmts = $5;
        $$ = tmp;
    }
    | ID '=' DO '{' stmts '}' where_exp  { 
        proc_t* tmp = NEW(proc_t);
        tmp->label = $1;
        tmp->stmts = $5;
        tmp->where_exp = $7;
        $$ = tmp;
    }
	;

stmts:
    stmt {
        stmts_t* tmp = NEW(stmts_t);
        tmp->stmt = $1;
        $$ = tmp;
    }
    | stmt stmts {
        stmts_t* tmp = NEW(stmts_t);
        tmp->stmt = $1;
        tmp->next = $2;
        $$ = tmp;
    }
	;

stmt:
    ID LARROW expr ';' {
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_EXPR;
       tmp->lhs = $1;
       tmp->body.expr = $3;
       $$ = tmp;
    }
    | ID LARROW while_expr ';' {
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_WH;
       tmp->lhs = $1;
       tmp->body.while_expr = $3;
       $$ = tmp;
    }
    | ID LARROW io_stmt ';'{
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_IO;
       tmp->lhs = $1;
       tmp->body.io_expr = $3;
       $$ = tmp;
    }
    | expr ';'{
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_EXPR;
       tmp->body.expr = $1;
       $$ = tmp;
    }
    | while_expr ';'{
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_WH;
       tmp->body.while_expr = $1;
       $$ = tmp;
    }
    | io_stmt ';' {
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_IO;
       tmp->body.io_expr = $1;
       $$ = tmp;
    }
	;

io_stmt:
    READINT     {
        io_t* tmp = NEW(io_t);
        tmp->opt = I_READINT;
        $$ = tmp;
    }
    | READFLOAT {
        io_t* tmp = NEW(io_t);
        tmp->opt = I_READFLOAT;
        $$ = tmp;
    }
    | READBOOL {
        io_t* tmp = NEW(io_t);
        tmp->opt = I_READBOOL;
        $$ = tmp;
    }
    | PRINT expr {
        io_t* tmp = NEW(io_t);
        tmp->opt = I_PRINT;
        tmp->expr = $2;
        $$ = tmp;
    }
	;

while_expr:
    WHILE '(' expr ')' '{' stmts '}' { 
                while_t* tmp = NEW(while_t);
                tmp->expr = $3;
                tmp->stmts = $6;
                $$ = tmp;
    }
	;
%%

int main(int argc, char** argv) {

    /*if(argc > 1) {*/
        /*yyin = fopen(argv[1], "r");*/
    /*}*/

    yyparse();

    return 0;
}
