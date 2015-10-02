%{
#include <stdio.h>
#include <string.h>
#include "lex.yy.c"

/*Macro para alocar e inicializar a struct toda com 0*/
#define NEW(TYPE) memset(malloc(sizeof(TYPE)), 0, sizeof(TYPE))

void yyerror(const char *str) {    
    printf("%d:%d: %s\n", line, col, str);
}
%}

%error-verbose

%token <str> ID
%token WILDSCORE
%token FLOAT
%token <boolval> BOOLVAL
%token BOOL
%token <intval> NUMBER
%token <floatval> FLOATNUM
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
    nonapp_t* nonapp_f;        
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
    list_value_t* list_value_f;
    char* str;
    int intval;
    float floatval;
    int boolval;
}


%type    <while_f> while_expr
%type    <io_f> io_stmt
%type    <stmt_f> stmt
%type    <stmts_f>stmts
%type    <proc_f> procdecl
%type    <appexpr_f> appexpr
%type    <nonapp_f> nonapp
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
%type    <list_value_f> list_value


%start program

%%
program:  
    line_elems {
        program_t* tmp = NEW(program_t);
        tmp->lines = $1;
        $$ = tmp;
    }
	;

line_elems: 
    line_elem line_elems {
        lines_t* tmp = NEW(lines_t);
        tmp->line = $1;
        tmp->next = $2;
        $$ = tmp; 
    }
    | line_elem {
        lines_t* tmp = NEW(lines_t);
        tmp->line = $1;
        $$ = tmp;
    }
	;

line_elem:
    fundecl {
        line_t* tmp = NEW(line_t);
        tmp->opt_type = L_FUN;
        tmp->opt.fun = $1;
        $$ = tmp; 
    }
    | procdecl {
        line_t* tmp = NEW(line_t);
        tmp->opt_type = L_PROC;
        tmp->opt.proc = $1;
        $$ = tmp; 
    }
    | funtype_decl {
        line_t* tmp = NEW(line_t);
        tmp->opt_type = L_FUNTYPE;
        tmp->opt.funtype = $1;
        $$ = tmp; 
    }
	;

fundecl: 
    ID args '=' expr ';' {
        fun_t* tmp = NEW(fun_t);
        tmp->label = $1;
        tmp->args = $2;
        tmp->expr = $4;
        $$ = tmp;
    
    }
    | ID args '=' expr where_exp {
        fun_t* tmp = NEW(fun_t);
        tmp->label = $1;
        tmp->args = $2;
        tmp->expr = $4;
        tmp->where_exp = $5;
        $$ = tmp;
    
    }
    | ID '=' expr ';' {
        fun_t* tmp = NEW(fun_t);
        tmp->label = $1;
        tmp->expr = $3;
        $$ = tmp;
    
    }
    | ID '=' expr where_exp {
        fun_t* tmp = NEW(fun_t);
        tmp->label = $1;
        tmp->expr = $3;
        tmp->where_exp = $4;
        $$ = tmp;
    
    }
	;

args:
    arg_value args  {
        args_t* tmp = NEW(args_t);
        tmp->arg = $1;
        tmp->next = $2;
        $$ = tmp;
    
    }
    | arg_value {
        args_t* tmp = NEW(args_t);
        tmp->arg = $1;
        $$ = tmp;
    
    }
    | WILDSCORE {
        $$ = NEW(arg_t);
    }
	;

arg_value:
    list_value {
        arg_t* tmp = NEW(arg_t);
        tmp->tp = AR_LIST;
        tmp->opt.listval = $1;
        $$ = tmp;
    
    }
    | basic_value {
        arg_t* tmp = NEW(arg_t);
        tmp->tp = AR_BASIC;
        tmp->opt.basicval = $1;
        $$ = tmp; 
    }
    | '(' arg_value ')' {
        arg_t* tmp = NEW(arg_t);
        tmp->tp = AR_ARG;
        tmp->opt.argval = $2;
        $$ = tmp; 
    }
	;

basic_value: 
    NUMBER {
        basic_val_t* tmp = NEW(basic_val_t);
        tmp->valtype = BINT;
        tmp->val.intval = $1;
        $$ = tmp;
    }
    | FLOATNUM {
        basic_val_t* tmp = NEW(basic_val_t);
        tmp->valtype = BFLOAT;
        tmp->val.floatval = $1;
        $$ = tmp;
    }
    | BOOLVAL {
        basic_val_t* tmp = NEW(basic_val_t);
        tmp->valtype = BBOOL;
        tmp->val.boolval = $1;
        $$ = tmp; 
    }
    | ID {
        basic_val_t* tmp = NEW(basic_val_t);
        tmp->valtype = BLABEL;
        tmp->val.label = $1;
        $$ = tmp; 
    }
    | '(' ')' {
        basic_val_t* tmp = NEW(basic_val_t);
        tmp->valtype = BUNIT;
        $$ = tmp; 
    }
	;

list_value:
    basic_value ':' list_value {
        list_value_t* tmp = NEW(list_value_t);
        tmp->ls_type = LS_BASIC;
        tmp->opt.basic_val = $1;
        tmp->next = $3;
        $$ = tmp;
    }
    |'[' list_args ']' ':' list_value {
        list_value_t* tmp = NEW(list_value_t);
        tmp->ls_type = LS_LIST;
        tmp->opt.list_args_val = $2;
        tmp->next = $5;
        $$ = tmp;
    
    }
    | WILDSCORE ':' list_value {
        list_value_t* tmp = NEW(list_value_t);
        tmp->ls_type = LS_WLD;
        tmp->next = $3;
        $$ = tmp;
    
    }
    | built_list_value {
        list_value_t* tmp = NEW(list_value_t);
        tmp->ls_type = LS_BLT;
        tmp->opt.built_list_val = $1;
        $$ = tmp;
    
    }
	;

list_args:
         arg_value {
            list_args_t* tmp = NEW(list_args_t);
            tmp->arg = $1;
            $$ = tmp;
         }
         | arg_value ',' list_args {
            list_args_t* tmp = NEW(list_args_t);
            tmp->arg = $1;
            tmp->next = $3;
            $$ = tmp;
         }
         ;

built_list_value:
    '[' ']' {
        $$ = NEW(built_list_val_t);
    }
    | '[' list_args ']' {
        built_list_val_t* tmp = NEW(built_list_val_t);
        tmp->vals = $2;
        $$ = tmp;
    }
	;

funtype_decl:
    ID DOUBLECOLON funtype ';' {
        funtype_decl_t* tmp = NEW(funtype_decl_t);
        tmp->label = $1;
        tmp->type = $3;
        $$ = tmp;

    }
	;

funtype:
    basic_type {
        funtype_t* tmp = NEW(funtype_t);
        tmp->typeorder = T_BASIC;
        tmp->tp.btype = $1;
        $$ = tmp;
    }
    | '(' funtype ')' {
        funtype_t* tmp = NEW(funtype_t);
        tmp->typeorder = T_FUNC;
        tmp->tp.ftype = $2;
        $$ = tmp;
    }
    | basic_type RARROW funtype {
        funtype_t* tmp = NEW(funtype_t);
        tmp->typeorder = T_BASIC;
        tmp->tp.btype = $1;
        tmp->next = $3;
        $$ = tmp;
    }
	;

basic_type:
    INTEGER {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_INTEGER;
        $$ = tmp;
    }
    | FLOAT {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_FLOAT;
        $$ = tmp;
    }
    | BOOL {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_BOOL;
        $$ = tmp;
    }
    | '[' basic_type ']' {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_LIST;
        tmp->internal_list_type = $2;
        $$ = tmp;
    }
    | ID {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_VAR;
        $$ = tmp;
    }
    | '(' ')' {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_UNIT;
        $$ = tmp;
    }
	;

appexpr:
       appexpr nonapp {
            appexpr_t* tmp = NEW(appexpr_t);
            tmp->tp = A_APP;
            tmp->app_tp.app = $1;
            tmp->napp2 = $2;
            $$ = tmp;
       
       }
       | nonapp nonapp {
            appexpr_t* tmp = NEW(appexpr_t);
            tmp->tp = A_NAPP;
            tmp->app_tp.napp1 = $1;
            tmp->napp2 = $2;
            $$ = tmp;
       }
	;

nonapp:
      basic_value {
            nonapp_t* tmp = NEW(nonapp_t);
            tmp->tp = NA_BASIC;
            tmp->n_tp.bvalue = $1;
            $$ = tmp;
      }
      | '(' expr ')' {
            nonapp_t* tmp = NEW(nonapp_t);
            tmp->tp = NA_EXPR;
            tmp->n_tp.expr = $2;
            $$ = tmp;
      }
      ;

expr:
    op_prec1 {
        expr_t* tmp = NEW(expr_t);
        tmp->expr_tp = OP_EXPR;
        tmp->tp.op_expr = $1;
        $$ = tmp;
    
    }
    | appexpr {
        expr_t* tmp = NEW(expr_t);
        tmp->expr_tp = APP_EXPR;
        tmp->tp.appexpr = $1;
        $$ = tmp;
    }
    | ifexpr {
        expr_t* tmp = NEW(expr_t);
        tmp->expr_tp = IF_EXPR;
        tmp->tp.ifexpr = $1;
        $$ = tmp;
    }
    | yieldexpr {
        expr_t* tmp = NEW(expr_t);
        tmp->expr_tp = YIELD_EXPR;
        tmp->tp.yieldexpr = $1;
        $$ = tmp;
    }
	;

ifexpr:
    IF expr THEN '{' expr '}' ELSE '{' expr '}' {
        ifexpr_t* tmp = NEW(ifexpr_t);
        tmp->expr1 = $2;
        tmp->expr2 = $5;
        tmp->expr3 = $9;
        $$ = tmp;
    }
	;

yieldexpr:
    YIELD ifexpr {
        yieldexpr_t* tmp = NEW(yieldexpr_t);
        tmp->yield_tp = Y_IF;
        tmp->tp.ifexpr = $2;
        $$ = tmp;
    }
    | YIELD appexpr {
        yieldexpr_t* tmp = NEW(yieldexpr_t);
        tmp->yield_tp = Y_APP;
        tmp->tp.appexpr = $2;
        $$ = tmp;
    }
    | YIELD op_prec1 {
        yieldexpr_t* tmp = NEW(yieldexpr_t);
        tmp->yield_tp = Y_OP;
        tmp->tp.op_expr = $2;
        $$ = tmp;
    }
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

void print_errors() {
    list_error_t* cur = NULL;
    cur = error_list_root;
    // Printando erros
    while(cur != NULL) {
        printf("%s", cur->erro->msg); 
        cur = cur->next;
    }
    del_list(&error_list_root);
    printf("\n");

}

int main(int argc, char** argv) {

    if(argc > 1) {
        yyin = fopen(argv[1], "r");
    }

    yyparse();

    print_errors();


    return 0;
}
