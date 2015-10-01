%{
#include <stdio.h>
#include "list_error.h"
#include "parser.tab.h"


int line = 1;
int col = 1;

list_error_t *error_list_root = NULL;


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
<INCOMMENT>"\n"                                     { line += 1; }
<INCOMMENT>.                                        { col += yyleng; }
_+{R_LETTER}({R_NUMBER}|{R_LETTER}|_)*              { return -1; }
_+{R_NUMBER}({R_NUMBER}|{R_LETTER}|_)*              { return -1; }
{R_NUMBER}+({R_LETTER}|_)({R_NUMBER}|{R_LETTER}|_)* { return -1; }
{R_LCBRACKET}                                       { return '{'; }
{R_RCBRACKET}                                       { return '}'; }
{R_LPAREN}                                          { return '('; }
{R_RPAREN}                                          { return ')'; }
{R_COLON}                                           { return ':'; }
{R_LARROW}                                          { return LARROW; }
{R_RARROW}                                          { return RARROW; }
{R_NOTEQUAL}                                        { return DIFF; }
{R_EQUALS}                                          { return EQUALS; }
{R_PLUS}                                            { return '+'; }
{R_MINUS}                                           { return '-'; }
{R_DIV}                                             { return '/'; }
{R_STAR}                                            { return '*'; }
{R_PERCENT}                                         { return '%'; }
{R_UNDERSCORE}                                      { return '_'; }
{R_DOUBLECOLON}                                     { return DOUBLECOLON; }
{R_LBRACKET}                                        { return '['; }
{R_RBRACKET}                                        { return ']'; }
{R_SEMICOLON}                                       { return ';'; }
{R_APPEND}                                          { return APPEND; }
{R_AND}                                             { return AND; }
{R_OR}                                              { return OR; }
{R_LESS}                                            { return '<'; }
{R_LESSEQ}                                          { return LEQ; }
{R_MORE}                                            { return '>'; }
{R_MOREEQ}                                          { return GEQ; }
{R_ATRIB}                                           { return '='; }
{R_COMMA}                                           { return ','; }
{R_YIELD}                                           { return YIELD; }
{R_INTEGER}                                         { return INTEGER; }
{R_FLOAT}                                           { return FLOAT; }
{R_BOOL}                                            { return BOOL; }
{R_DO}                                              { return DO; }
{R_IF}                                              { return IF; }
{R_THEN}                                            { return THEN; }
{R_ELSE}                                            { return ELSE; }
{R_WHILE}                                           { return WHILE; }
{R_READINT}                                         { return READINT; }
{R_READFLOAT}                                       { return READFLOAT; }
{R_READBOOL}                                        { return READBOOL; }
{R_PRINT}                                           { return PRINT; }
{R_BOOLVAL}                                         { return BOOLVAL; }
{R_LETTER}({R_NUMBER}|{R_LETTER}|_)*                { return ID; }
{R_NUMBER}+                                         { return NUMBER; }
{R_NUMBER}+'.'{R_NUMBER}+                           { return FLOATNUM; }
{WS}+                                               { col += yyleng; BEGIN(INITIAL); }
{NL}                                                { col = 1; line++; BEGIN(INITIAL);}
.                                                   { return -1; }


%%

int yywrap() { return 1; }

