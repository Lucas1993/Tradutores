%{
#include <stdio.h>
#include "list_error.h"


#define T_LCBRACKET      1   
#define T_RCBRACKET      2  
#define T_LPAREN         3  
#define T_RPAREN         4  
#define T_COLON          5  
#define T_LARROW         6  
#define T_RARROW         7  
#define T_NOTEQUAL       8  
#define T_EQUALS         9  
#define T_PLUS           10 
#define T_MINUS          11 
#define T_DIV            12 
#define T_STAR           13 
#define T_PERCENT        14 
#define T_UNDERSCORE     15 
#define T_DOUBLECOLON    16 
#define T_LBRACKET       17 
#define T_RBRACKET       18 
#define T_SEMICOLON      19 
#define T_APPEND         20 
#define T_AND            21 
#define T_OR             22 
#define T_LESS           23 
#define T_LESSEQ         24 
#define T_MORE           25 
#define T_MOREEQ         26 
#define T_ATRIB          27 
#define T_COMMA          28 
#define T_YIELD          29 
#define T_INTEGER        30 
#define T_FLOAT          31 
#define T_BOOLEAN        32 
#define T_DO             33 
#define T_IF             34 
#define T_THEN           35 
#define T_ELSE           36 
#define T_WHILE          37 
#define T_READINT        38 
#define T_READFLOAT      39 
#define T_READBOOL       40 
#define T_PRINT          41 
#define T_ID             42 
#define T_NUMBER         43 
#define T_FLOATNUM       44
#define NEWLINE          45
#define WHITE            46

int line = 1;
int col = 1;


void handle_token(int token);

list_error_t *error_list_root = NULL;


%}

WS            [\t ]
LCBRACKET     "{"
RCBRACKET     "}"
LPAREN        "("
RPAREN        ")"
COLON         ":"
LARROW        "<-"
RARROW        "->"
NOTEQUAL      "/="
EQUALS        "=="
PLUS          "+"
MINUS         "-"
DIV           "/"
STAR          "*"
PERCENT       "%"
UNDERSCORE    "_"
DOUBLECOLON   "::"
LBRACKET      "["
RBRACKET      "]"
SEMICOLON     ";"
APPEND        "++"
AND           "&&"
OR            "||"
LESS          "<"
LESSEQ        "<="
MORE          ">"
MOREEQ        ">="
ATRIB         "="
COMMA         ","
YIELD         "yield"
INTEGER       "Integer"
FLOAT         "Float"
BOOLEAN       "Bool"
DO            "do"
IF            "if"
THEN          "then"
ELSE          "else"
WHILE         "while"
READINT       "readInt"
READFLOAT     "readFloat"
READBOOL      "readBool"
PRINT         "print"
LETTER        [a-zA-Z]
NUMBER        [0-9]
NL            [\n\r]

%x INCOMMENT

%%


"/*"                                        { BEGIN(INCOMMENT); }
<INCOMMENT>"*/"                             { BEGIN(INITIAL); }
<INCOMMENT>.                                { col += yyleng; }
<INCOMMENT>\n                               { line += 1; }
_+{LETTER}({NUMBER}|{LETTER}|_)*            { return -1; }
_+{NUMBER}({NUMBER}|{LETTER}|_)*            { return -1; }
{NUMBER}+({LETTER}|_)({NUMBER}|{LETTER}|_)* { return -1; }
{LCBRACKET}                                 { return T_LCBRACKET; }
{RCBRACKET}                                 { return T_RCBRACKET; }
{LPAREN}                                    { return T_LPAREN; }
{RPAREN}                                    { return T_RPAREN; }
{COLON}                                     { return T_COLON; }
{LARROW}                                    { return T_LARROW; }
{RARROW}                                    { return T_RARROW; }
{NOTEQUAL}                                  { return T_NOTEQUAL; }
{EQUALS}                                    { return T_EQUALS; }
{PLUS}                                      { return T_PLUS; }
{MINUS}                                     { return T_MINUS; }
{DIV}                                       { return T_DIV; }
{STAR}                                      { return T_STAR; }
{PERCENT}                                   { return T_PERCENT; }
{UNDERSCORE}                                { return T_UNDERSCORE; }
{DOUBLECOLON}                               { return T_DOUBLECOLON; }
{LBRACKET}                                  { return T_LBRACKET; }
{RBRACKET}                                  { return T_RBRACKET; }
{SEMICOLON}                                 { return T_SEMICOLON; }
{APPEND}                                    { return T_APPEND; }
{AND}                                       { return T_AND; }
{OR}                                        { return T_OR; }
{LESS}                                      { return T_LESS; }
{LESSEQ}                                    { return T_LESSEQ; }
{MORE}                                      { return T_MORE; }
{MOREEQ}                                    { return T_MOREEQ; }
{ATRIB}                                     { return T_ATRIB; }
{COMMA}                                     { return T_COMMA; }
{YIELD}                                     { return T_YIELD; }
{INTEGER}                                   { return T_INTEGER; }
{FLOAT}                                     { return T_FLOAT; }
{BOOLEAN}                                   { return T_BOOLEAN; }
{DO}                                        { return T_DO; }
{IF}                                        { return T_IF; }
{THEN}                                      { return T_THEN; }
{ELSE}                                      { return T_ELSE; }
{WHILE}                                     { return T_WHILE; }
{READINT}                                   { return T_READINT; }
{READFLOAT}                                 { return T_READFLOAT; }
{READBOOL}                                  { return T_READBOOL; }
{PRINT}                                     { return T_PRINT; }
{LETTER}({NUMBER}|{LETTER}|_)*              { return T_ID; }
{NUMBER}+                                   { return T_NUMBER; }
{NUMBER}+"."{NUMBER}+                       { return T_FLOATNUM; }
{WS}+                                       { col += yyleng; BEGIN(INITIAL); }
{NL}                                        { col = 1; line++; BEGIN(INITIAL); printf("\n");}
.                                           { return -1; }


%%

int main(int argc, char *argv[]) {
	yyin = fopen(argv[1], "r");
    list_error_t* cur = NULL;
    int token = 0;

    printf("============== Tokens reconhecidos ============== \n\n");

    do {
        token = yylex();
        if(token) {
            handle_token(token);
        }
        printf(" ");
    } while(token);

    printf("\n");

    if(error_list_root != NULL) {
        printf("\n");
        printf("==================== ERROS =====================");
        printf("\n");
    }

    cur = error_list_root;
    while(cur != NULL) {
        printf("\n%d:%d Token não identificado: \'%s\'", cur->erro->line, cur->erro->col, cur->erro->token); 
        cur = cur->next;
    }
    printf("\n");
}

void handle_token(int token) {


    static char const* tokens[] = {0, "T_LCBRACKET", "T_RCBRACKET" , "T_LPAREN" , "T_RPAREN" , "T_COLON" , "T_LARROW" , "T_RARROW" , "T_NOTEQUAL" , "T_EQUALS", "T_PLUS", "T_MINUS", "T_DIV",
    "T_STAR" , "T_PERCENT" , "T_UNDERSCORE" , "T_DOUBLECOLON" , "T_LBRACKET" , "T_RBRACKET" , "T_SEMICOLON" , "T_APPEND" , "T_AND" , "T_OR" , "T_LESS" , "T_LESSEQ" , "T_MORE" , "T_MOREEQ" ,
    "T_ATRIB" , "T_COMMA" , "T_YIELD" , "T_INTEGER" , "T_FLOAT" , "T_BOOLEAN" , "T_DO" , "T_IF" , "T_THEN" , "T_ELSE" , "T_WHILE" , "T_READINT" , "T_READFLOAT" , "T_READBOOL" , "T_PRINT" , 
    "T_ID" , "T_NUMBER" , "T_FLOATNUM"};

    if(token == 42) {
        printf("<%s, '%s'>", tokens[token], yytext);
    } else if(token == 43) {
        printf("<%s, %d>", tokens[token], atoi(yytext));
    } else if(token == 44) {
        printf("<%s, %.2f>", tokens[token], atof(yytext));
    } else if(token > 0 && token <= 44) {
        printf("<%s>", tokens[token]);
    } else {
        comp_error_t* err = make_error(0, yytext, line, col);
        add_error(&error_list_root, err);
    }
    col += yyleng;

}
