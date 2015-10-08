%{
#include <stdio.h>
#include "ast.h"
#include "list_error.h"
#include "sym_table.h"
#include "parser.tab.h"


int line = 1;
int col = 1;

int has_errors = 0;
list_error_t* error_list_root = NULL;
sym_node_t* symtable = NULL;
void lex_error();


%}

WS            [\t ]
R_LCBRACKET     "{"
R_RCBRACKET     "}"
R_LPAREN        "("
R_RPAREN        ")"
R_COLON         ":"
R_LARROW        "<-"
R_RARROW        "->"
R_NOTEQUAL      "/="
R_EQUALS        "=="
R_PLUS          "+"
R_MINUS         "-"
R_DIV           "/"
R_STAR          "*"
R_PERCENT       "%"
R_UNDERSCORE    "_"
R_DOUBLECOLON   "::"
R_LBRACKET      "["
R_RBRACKET      "]"
R_SEMICOLON     ";"
R_APPEND        "++"
R_AND           "&&"
R_OR            "||"
R_LESS          "<"
R_LESSEQ        "<="
R_MORE          ">"
R_MOREEQ        ">="
R_ATRIB         "="
R_COMMA         ","
R_YIELD         "yield"
R_INTEGER       "Integer"
R_FLOAT         "Float"
R_BOOL          "Bool"
R_DO            "do"
R_IF            "if"
R_THEN          "then"
R_ELSE          "else"
R_WHILE         "while"
R_WHERE         "where"
R_READINT       "readInt"
R_READFLOAT     "readFloat"
R_READBOOL      "readBool"
R_PRINT         "print"
R_BOOLVAL       ("True"|"False")
R_LETTER        [a-zA-Z]
R_NUMBER        [0-9]
NL            [\n\r]

%x INCOMMENT

%%


"/*"                                                { BEGIN(INCOMMENT); }
<INCOMMENT>"*/"                                     { BEGIN(INITIAL); }
<INCOMMENT>"\n"                                     { col = 1; line += 1; }
<INCOMMENT>.                                        { col += yyleng; }
_+{R_LETTER}({R_NUMBER}|{R_LETTER}|_)*              { col += yyleng; yylval.str = "err"; lex_error(); return ID; }
_+{R_NUMBER}({R_NUMBER}|{R_LETTER}|_)*              { col += yyleng; yylval.intval = -1; lex_error(); return NUMBER;}
{R_NUMBER}+({R_LETTER}|_)({R_NUMBER}|{R_LETTER}|_)* { col += yyleng; yylval.str = "err"; lex_error(); return ID; }
{R_LCBRACKET}                                       { col += yyleng; return '{'; }
{R_RCBRACKET}                                       { col += yyleng; return '}'; }
{R_LPAREN}                                          { col += yyleng; return '('; }
{R_RPAREN}                                          { col += yyleng; return ')'; }
{R_COLON}                                           { col += yyleng; return ':'; }
{R_LARROW}                                          { col += yyleng; return LARROW; }
{R_RARROW}                                          { col += yyleng; return RARROW; }
{R_NOTEQUAL}                                        { col += yyleng; return DIFF; }
{R_EQUALS}                                          { col += yyleng; return EQUALS; }
{R_PLUS}                                            { col += yyleng; return '+'; }
{R_MINUS}                                           { col += yyleng; return '-'; }
{R_DIV}                                             { col += yyleng; return '/'; }
{R_STAR}                                            { col += yyleng; return '*'; }
{R_PERCENT}                                         { col += yyleng; return '%'; }
{R_UNDERSCORE}                                      { col += yyleng; return WILDSCORE; }
{R_DOUBLECOLON}                                     { col += yyleng; return DOUBLECOLON; }
{R_LBRACKET}                                        { col += yyleng; return '['; }
{R_RBRACKET}                                        { col += yyleng; return ']'; }
{R_SEMICOLON}                                       { col += yyleng; return ';'; }
{R_APPEND}                                          { col += yyleng; return APPEND; }
{R_AND}                                             { col += yyleng; return AND; }
{R_OR}                                              { col += yyleng; return OR; }
{R_LESS}                                            { col += yyleng; return '<'; }
{R_LESSEQ}                                          { col += yyleng; return LEQ; }
{R_MORE}                                            { col += yyleng; return '>'; }
{R_MOREEQ}                                          { col += yyleng; return GEQ; }
{R_ATRIB}                                           { col += yyleng; return '='; }
{R_COMMA}                                           { col += yyleng; return ','; }
{R_YIELD}                                           { col += yyleng; return YIELD; }
{R_INTEGER}                                         { col += yyleng; return INTEGER; }
{R_FLOAT}                                           { col += yyleng; return FLOAT; }
{R_BOOL}                                            { col += yyleng; return BOOL; }
{R_DO}                                              { col += yyleng; return DO; }
{R_IF}                                              { col += yyleng; return IF; }
{R_THEN}                                            { col += yyleng; return THEN; }
{R_ELSE}                                            { col += yyleng; return ELSE; }
{R_WHILE}                                           { col += yyleng; return WHILE; }
{R_WHERE}                                           { col += yyleng; return WHERE; }
{R_READINT}                                         { col += yyleng; return READINT; }
{R_READFLOAT}                                       { col += yyleng; return READFLOAT; }
{R_READBOOL}                                        { col += yyleng; return READBOOL; }
{R_PRINT}                                           { col += yyleng; return PRINT; }
{R_BOOLVAL}                                         { col += yyleng; yylval.boolval = strcmp("True", yytext) != 0; return BOOLVAL; }
{R_LETTER}({R_NUMBER}|{R_LETTER}|_)*                { col += yyleng; yylval.str = strdup(yytext); return ID; }
{R_NUMBER}+                                         { col += yyleng; yylval.intval = atoi(yytext); return NUMBER; }
{R_NUMBER}+'.'{R_NUMBER}+                           { col += yyleng; yylval.floatval = atof(yytext); return FLOATNUM; }
{WS}+                                               { col += yyleng; BEGIN(INITIAL); }
{NL}                                                { col = 1; line++; BEGIN(INITIAL);}
.                                                   { lex_error(); }


%%

int yywrap() { return 1; }

void lex_error() {
    has_errors = 1;
    const char* def = " lexical error, unexpected ";
    size_t sz = strlen(def) + strlen(yytext) + 20;
    char* msg = malloc(sz);

    sprintf(msg, "%d:%d:%s '%s'", line, col, def, yytext);
    
    comp_error_t* err = make_error(0, msg, line, col);
    add_error(&error_list_root, err);
}

