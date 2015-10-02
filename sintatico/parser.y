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
    | '(' funtype ')' RARROW funtype {
        funtype_t* tmp = NEW(funtype_t);
        tmp->typeorder = T_FUNC;
        tmp->tp.ftype = $2;
        tmp->next = $5;
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

enum {
         WHILE_T, IO_T, STMT_T, STMTS_T, PROC_T, APPEXPR_T, NONAPP_T, WHERE_T, EXPRS_T, OP_T,
         YIELDEXPR_T, IFEXPR_T, EXPR_T, BASIC_TYPE_T, FUNTYPE_T, FUNTYPE_DECL_T, BASIC_VAL_T, ARG_T, 
         FUN_T, LINES_T, LINE_T, ARGS_T, PROGRAM_T, LIST_ARGS_T, BUILT_LIST_VAL_T, LIST_VALUE_T }
 union_type;

void ident(int lvl) {
    while(lvl) {
        printf(" ");
        lvl--;
    }
}

void print_tree(YYSTYPE node, char node_type, int lvl) {
    YYSTYPE tmp;
    memset(&tmp, 0, sizeof(YYSTYPE));
    switch(node_type) {
        case WHILE_T:
            ident(lvl); printf("| while_expr\n");
            tmp.expr_f = node.while_f->expr;
            ident(lvl + 1); printf("| (\n");
            print_tree(tmp, EXPR_T, lvl + 1);
            ident(lvl + 1); printf("| )\n");
            ident(lvl + 1); printf("| {\n");
            print_tree(tmp, STMTS_T, lvl + 1);
            ident(lvl + 1); printf("| }\n");
            break;
        case IO_T:
            ident(lvl); printf("| io_stmt\n");
            switch(node.io_f->opt) {
                case I_READINT:
                    ident(lvl + 1); printf("| READINT\n");
                    break;
                case I_READFLOAT:
                    ident(lvl + 1); printf("| READFLOAT\n");
                    break;
                case I_READBOOL:
                    ident(lvl + 1); printf("| READBOOL\n");
                    break;
                case I_PRINT:
                    ident(lvl + 1); printf("| PRINT\n");
                    tmp.expr_f = node.io_f->expr;
                    print_tree(tmp, EXPR_T, lvl + 1);
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case STMT_T:
            ident(lvl); printf("| stmt\n");
            switch(node.stmt_f->stmt_type) {
                case STMT_EXPR:
                    ident(lvl + 1); printf("| ID, %s\n", node.stmt_f->lhs);
                    ident(lvl + 1); printf("| LARROW\n");
                    tmp.expr_f = node.stmt_f->body.expr;
                    print_tree(tmp, EXPR_T, lvl + 1);
                    ident(lvl + 1); printf("| ;\n");
                    break;
                case STMT_WH:
                    ident(lvl + 1); printf("| ID, %s\n", node.stmt_f->lhs);
                    ident(lvl + 1); printf("| LARROW\n");
                    tmp.while_f = node.stmt_f->body.while_expr;
                    print_tree(tmp, WHILE_T, lvl + 1);
                    ident(lvl + 1); printf("| ;\n");
                    break;
                case STMT_IO:
                    ident(lvl + 1); printf("| ID, %s\n", node.stmt_f->lhs);
                    ident(lvl + 1); printf("| LARROW\n");
                    tmp.io_f = node.stmt_f->body.io_expr;
                    print_tree(tmp, IO_T, lvl + 1);
                    ident(lvl + 1); printf("| ;\n");
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case STMTS_T:
            ident(lvl); printf("| stmts\n");

            tmp.stmt_f = node.stmts_f->stmt;
            print_tree(tmp, STMT_T, lvl + 1);
            memset(&tmp, 0, sizeof(YYSTYPE));

            if(node.stmts_f->next != NULL) {
                tmp.stmts_f = node.stmts_f->next;
                print_tree(tmp, STMTS_T, lvl + 1);
            }
            break;
        case PROC_T:
            ident(lvl); printf("| procdecl\n");
            ident(lvl + 1); printf("| ID, %s\n", node.proc_f->label);
            if(node.proc_f->args != NULL) {
                tmp.args_f = node.proc_f->args;
                print_tree(tmp, ARGS_T, lvl + 1);
            }
            memset(&tmp, 0, sizeof(YYSTYPE));
            ident(lvl + 1); printf("| = ");
            ident(lvl + 1); printf("| DO ");

            ident(lvl + 1); printf("| { ");
            tmp.stmts_f = node.proc_f->stmts;
            print_tree(tmp, STMTS_T, lvl + 1);
            ident(lvl + 1); printf("| } ");
            memset(&tmp, 0, sizeof(YYSTYPE));

            if(node.proc_f->where_exp != NULL) {
                tmp.where_f = node.proc_f->where_exp;
                print_tree(tmp, WHERE_T, lvl + 1);
            }
            break;
        case APPEXPR_T:
            ident(lvl); printf("| appexpr\n");
            switch(node.appexpr_f->tp) {
                case A_APP:
                    tmp.appexpr_f = node.appexpr_f->app_tp.app;
                    print_tree(tmp, APPEXPR_T, lvl + 1);
                    break;
                case A_NAPP:
                    tmp.nonapp_f = node.appexpr_f->app_tp.napp1;
                    print_tree(tmp, NONAPP_T, lvl + 1);
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            memset(&tmp, 0, sizeof(YYSTYPE));
            tmp.nonapp_f = node.appexpr_f->napp2;
            print_tree(tmp, NONAPP_T, lvl + 1);
            break;
        case NONAPP_T:
            ident(lvl); printf("| nonapp\n");
            switch(node.nonapp_f->tp) {
                case NA_BASIC:
                    tmp.basic_val_f = node.nonapp_f->n_tp.bvalue;
                    print_tree(tmp, BASIC_VAL_T, lvl + 1);
                    break;
                case NA_EXPR:
                    tmp.expr_f = node.nonapp_f->n_tp.expr;
                    print_tree(tmp, EXPR_T, lvl + 1);
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case WHERE_T:
            ident(lvl); printf("| where_exp\n");
            ident(lvl + 1); printf("| WHERE\n");
            ident(lvl + 1); printf("| {\n");
            tmp.lines_f = node.where_f->lines;
            print_tree(tmp, LINES_T, lvl + 1);
            ident(lvl + 1); printf("| }\n");
            break;
        case EXPRS_T:
            ident(lvl); printf("| exprs\n");
            tmp.expr_f = node.exprs_f->expr;
            print_tree(tmp, EXPR_T, lvl + 1);
            memset(&tmp, 0, sizeof(YYSTYPE));
            if(node.exprs_f->next != NULL) {
                tmp.exprs_f = node.exprs_f->next;
                print_tree(tmp, EXPRS_T, lvl + 1);
            }
            break;
        case OP_T:
            ident(lvl); printf("| op_precN\n");
            static const char* operations[] = { "OR", "AND", "EQ", "DIFF", "LESS", "LEQ", "GREATER", "GEQ", "CONS", "APPEND", "PLUS", "MINUS", "MOD", "TIMES", "DIV" };
            if(node.op_f->op_tp >= O_OR) {
                tmp.op_f = node.op_f->opt.opt1;
                print_tree(tmp, OP_T, lvl + 1);
                memset(&tmp, 0, sizeof(YYSTYPE));
                ident(lvl + 1); printf("| %s\n", operations[node.op_f->op_tp - O_OR]);
                tmp.op_f = node.op_f->opt2;
                print_tree(tmp, OP_T, lvl + 1);
            } else {
                switch(node.op_f->op_tp) {
                    case O_BVALUE:
                        tmp.basic_val_f = node.op_f->opt.bval;
                        print_tree(tmp, BASIC_VAL_T, lvl + 1);
                        break;
                    case O_LIST:
                        tmp.exprs_f = node.op_f->opt.lexpr;
                        print_tree(tmp, EXPRS_T, lvl + 1);
                        break;
                    case O_EXPR:
                        tmp.expr_f = node.op_f->opt.expr;
                        ident(lvl + 1); printf("| (\n");
                        print_tree(tmp, EXPR_T, lvl + 1);
                        ident(lvl + 1); printf("| )\n");
                        break;
                    case O_NEG:
                        ident(lvl + 1); printf("| -\n");
                        tmp.op_f = node.op_f->opt.opt1;
                        print_tree(tmp, OP_T, lvl + 1);
                        break;
                    case O_NEXT:
                        tmp.op_f = node.op_f->opt.opt1;
                        print_tree(tmp, OP_T, lvl + 1);
                        break;
                    default:
                        printf("ERROR!"); 
                } 
            } 
            break;
        case YIELDEXPR_T:
            ident(lvl); printf("| yieldexpr\n");
            switch(node.yieldexpr_f->yield_tp) {
                case Y_IF:
                    tmp.ifexpr_f = node.yieldexpr_f->tp.ifexpr;
                    print_tree(tmp, IFEXPR_T, lvl + 1);
                    break;
                case Y_APP:
                    tmp.appexpr_f = node.yieldexpr_f->tp.appexpr;
                    print_tree(tmp, APPEXPR_T, lvl + 1);
                    break;
                case Y_OP:
                    tmp.op_f = node.yieldexpr_f->tp.op_expr;
                    print_tree(tmp, OP_T, lvl + 1);
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case IFEXPR_T:
            ident(lvl); printf("| ifexpr\n");
            ident(lvl + 1); printf("| IF\n");

            tmp.expr_f = node.ifexpr_f->expr1;
            print_tree(tmp, IFEXPR_T, lvl + 1);
            memset(&tmp, 0, sizeof(YYSTYPE));

            ident(lvl + 1); printf("| THEN\n");
            ident(lvl + 1); printf("| {\n");

            tmp.expr_f = node.ifexpr_f->expr2;
            print_tree(tmp, IFEXPR_T, lvl + 1);
            memset(&tmp, 0, sizeof(YYSTYPE));

            ident(lvl + 1); printf("| }\n");
            ident(lvl + 1); printf("| ELSE\n");
            ident(lvl + 1); printf("| {\n");

            tmp.expr_f = node.ifexpr_f->expr3;
            print_tree(tmp, IFEXPR_T, lvl + 1);
            memset(&tmp, 0, sizeof(YYSTYPE));
            ident(lvl + 1); printf("| }\n");
            break;
        case EXPR_T:
            ident(lvl); printf("| expr\n");
            switch(node.expr_f->expr_tp) {
                case OP_EXPR:
                    tmp.op_f = node.expr_f->tp.op_expr;
                    print_tree(tmp, OP_T, lvl + 1);
                    break;
                case APP_EXPR:
                    tmp.appexpr_f = node.expr_f->tp.appexpr;
                    print_tree(tmp, APPEXPR_T, lvl + 1);
                    break;
                case IF_EXPR:
                    tmp.ifexpr_f = node.expr_f->tp.ifexpr;
                    print_tree(tmp, IFEXPR_T, lvl + 1);
                    break;
                case YIELD_EXPR:
                    tmp.yieldexpr_f = node.expr_f->tp.yieldexpr;
                    print_tree(tmp, YIELDEXPR_T, lvl + 1);
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case BASIC_TYPE_T:
            ident(lvl); printf("| basic_type\n");
            switch(node.basic_type_f->whichtype) {
                case BT_INTEGER:
                    ident(lvl + 1); printf("| INTEGER\n");
                    break;
                case BT_FLOAT:
                    ident(lvl + 1); printf("| FLOAT\n");
                    break;
                case BT_BOOL:
                    ident(lvl + 1); printf("| BOOL\n");
                    break;
                case BT_UNIT:
                    ident(lvl + 1); printf("| (\n");
                    ident(lvl + 1); printf("| )\n");
                    break;
                case BT_VAR:
                    tmp.yieldexpr_f = node.expr_f->tp.yieldexpr;
                    print_tree(tmp, YIELDEXPR_T, lvl + 1);
                    break;
                case BT_LIST:
                    tmp.yieldexpr_f = node.expr_f->tp.yieldexpr;
                    print_tree(tmp, YIELDEXPR_T, lvl + 1);
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case FUNTYPE_T:
            ident(lvl); printf("| funtype\n");
            switch(node.funtype_f->typeorder) {
                case T_BASIC:
                    tmp.basic_type_f = node.funtype_f->tp.btype;
                    print_tree(tmp, BASIC_TYPE_T, lvl + 1);
                    break;
                case T_FUNC:
                    tmp.funtype_f = node.funtype_f->tp.ftype;
                    print_tree(tmp, FUNTYPE_T, lvl + 1);
                    memset(&tmp, 0, sizeof(YYSTYPE));
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            if(node.funtype_f->next != NULL) {
                tmp.funtype_f = node.funtype_f->next;
                print_tree(tmp, FUNTYPE_T, lvl + 1);
            }
            break;
        case FUNTYPE_DECL_T:
            ident(lvl); printf("| funtype_decl\n");
            ident(lvl + 1); printf("| ID, %s\n", node.funtype_decl_f->label);
            ident(lvl + 1); printf("| ::\n");

            tmp.funtype_f = node.funtype_decl_f->type;
            print_tree(tmp, FUNTYPE_T, lvl + 1);
            ident(lvl + 1); printf("| ;\n");
            break;
        case BASIC_VAL_T:
            ident(lvl); printf("| basic_value\n");
            switch(node.basic_val_f->valtype) {
                case BINT:
                    ident(lvl + 1); printf("| NUMBER, %d\n", node.basic_val_f->val.intval);
                    break;
                case BFLOAT:
                    ident(lvl + 1); printf("| FLOATNUM, %.4f\n", node.basic_val_f->val.floatval);
                    break;
                case BBOOL:
                    if(node.basic_val_f->val.intval) {
                        ident(lvl + 1); printf("| BOOLVAL, True\n");
                    } else {
                        ident(lvl + 1); printf("| BOOLVAL, False\n");
                    }
                    break;
                case BLABEL:
                    ident(lvl + 1); printf("| ID, %s\n", node.basic_val_f->val.label);
                    break;
                case BUNIT:
                    ident(lvl + 1); printf("| ( \n");;
                    ident(lvl + 1); printf("| ) \n");;
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case ARG_T:
            ident(lvl); printf("| arg_value\n");
            switch(node.arg_f->tp) {
                case AR_LIST:
                    tmp.list_value_f = node.arg_f->opt.listval;
                    print_tree(tmp, LIST_VALUE_T, lvl + 1);
                    break;
                case AR_BASIC:
                    tmp.basic_val_f = node.arg_f->opt.basicval;
                    print_tree(tmp, BASIC_VAL_T, lvl + 1);
                    break;
                case AR_ARG:
                    ident(lvl + 1); printf("| ( \n");;

                    tmp.arg_f = node.arg_f->opt.argval;
                    print_tree(tmp, ARG_T, lvl + 1);

                    ident(lvl + 1); printf("| ) \n");;
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case FUN_T:
            ident(lvl); printf("| fundecl\n");
            ident(lvl + 1); printf("| ID, %s\n", node.fun_f->label);
            if(node.fun_f->args != NULL) {
                tmp.args_f = node.fun_f->args;
                print_tree(tmp, ARGS_T, lvl + 1);
            }
            memset(&tmp, 0, sizeof(YYSTYPE));
            ident(lvl + 1); printf("| = ");

            ident(lvl + 1); printf("| { ");
            tmp.expr_f = node.fun_f->expr;
            print_tree(tmp, STMTS_T, lvl + 1);
            ident(lvl + 1); printf("| } ");
            memset(&tmp, 0, sizeof(YYSTYPE));

            if(node.proc_f->where_exp != NULL) {
                tmp.where_f = node.proc_f->where_exp;
                print_tree(tmp, WHERE_T, lvl + 1);
            }
            break;
        case LINES_T:
            ident(lvl); printf("| line_elems\n");
            tmp.line_f = node.lines_f->line;
            print_tree(tmp, LINE_T, lvl + 1);
            if(node.lines_f->next != NULL) {
                tmp.lines_f = node.lines_f->next;
                print_tree(tmp, LINES_T, lvl + 1);
            }
            break;
        case LINE_T:
            ident(lvl); printf("| line_elem\n");
            switch(node.line_f->opt_type) {
                case L_FUN:
                    tmp.fun_f = node.line_f->opt.fun;
                    print_tree(tmp, FUN_T, lvl + 1);
                    break;
                case L_PROC:
                    tmp.proc_f = node.line_f->opt.proc;
                    print_tree(tmp, PROC_T, lvl + 1);
                    break;
                case L_FUNTYPE:
                    tmp.funtype_decl_f = node.line_f->opt.funtype;
                    print_tree(tmp, FUNTYPE_DECL_T, lvl + 1);
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case ARGS_T:
            ident(lvl); printf("| args\n");
            if(node.args_f->arg != NULL) {
                tmp.arg_f = node.args_f->arg;
                print_tree(tmp, ARG_T, lvl + 1);
                if(node.args_f->next != NULL) {
                    tmp.args_f = node.args_f->next;
                    print_tree(tmp, ARGS_T, lvl + 1);
                }
            } else {
                ident(lvl + 1); printf("| WILDSCORE\n");
            }
            break;
        case PROGRAM_T:
            ident(lvl); printf("| program\n");
            tmp.lines_f = node.program_f->lines;
            print_tree(tmp, LINES_T, lvl + 1);
            break;
        case LIST_ARGS_T:
            ident(lvl); printf("| list_args\n");
            tmp.arg_f = node.list_args_f->arg;
            print_tree(tmp, ARG_T, lvl + 1);
            if(node.list_args_f->next != NULL) {
                tmp.list_args_f = node.list_args_f->next;
                print_tree(tmp, LIST_ARGS_T, lvl + 1);
            }
            break;
        case BUILT_LIST_VAL_T:
            ident(lvl); printf("| built_list_value\n");
            ident(lvl + 1); printf("| [\n");
            if(node.built_list_val_f->vals != NULL) {
                tmp.list_args_f = node.built_list_val_f->vals;
                print_tree(tmp, LIST_ARGS_T, lvl + 1);
            }
            ident(lvl + 1); printf("| ]\n");
            break;
        case LIST_VALUE_T:
            ident(lvl); printf("| list_value\n");
            switch(node.list_value_f->ls_type) {
                case LS_BASIC:
                    tmp.basic_val_f = node.list_value_f->opt.basic_val;
                    print_tree(tmp, BASIC_VAL_T, lvl + 1);
                    break;
                case LS_LIST:
                    ident(lvl + 1); printf("| [\n");
                    tmp.list_args_f = node.list_value_f->opt.list_args_val;
                    print_tree(tmp, BASIC_VAL_T, lvl + 1);
                    ident(lvl + 1); printf("| ]\n");
                    break;
                case LS_WLD:
                    ident(lvl + 1); printf("| WILDSCORE\n");
                    break;
                case LS_BLT:
                    tmp.built_list_val_f = node.list_value_f->opt.built_list_val;
                    print_tree(tmp, BUILT_LIST_VAL_T, lvl + 1);
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            memset(&tmp, 0, sizeof(YYSTYPE));
            ident(lvl + 1); printf("| :\n");
            tmp.list_value_f = node.list_value_f->next;
            print_tree(tmp, LIST_VALUE_T, lvl + 1);
            break;
    }


}

int main(int argc, char** argv) {

    if(argc > 1) {
        yyin = fopen(argv[1], "r");
    }

    yyparse();

    print_errors();


    return 0;
}
