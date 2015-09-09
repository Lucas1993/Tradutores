%{
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>


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

using namespace std;

void handle_token(int token);

struct comp_error_t {
    int type;
    std::string msg;

    comp_error_t(int _type, std::string _msg) {
        type = _type;
        msg = _msg;
    }
};

std::vector<comp_error_t> error_list;

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

%%

{LCBRACKET}                              { return T_LCBRACKET; }
{RCBRACKET}                              { return T_RCBRACKET; }
{LPAREN}                                 { return T_LPAREN; }
{RPAREN}                                 { return T_RPAREN; }
{COLON}                                  { return T_COLON; }
{LARROW}                                 { return T_LARROW; }
{RARROW}                                 { return T_RARROW; }
{NOTEQUAL}                               { return T_NOTEQUAL; }
{EQUALS}                                 { return T_EQUALS; }
{PLUS}                                   { return T_PLUS; }
{MINUS}                                  { return T_MINUS; }
{DIV}                                    { return T_DIV; }
{STAR}                                   { return T_STAR; }
{PERCENT}                                { return T_PERCENT; }
{UNDERSCORE}                             { return T_UNDERSCORE; }
{DOUBLECOLON}                            { return T_DOUBLECOLON; }
{LBRACKET}                               { return T_LBRACKET; }
{RBRACKET}                               { return T_RBRACKET; }
{SEMICOLON}                              { return T_SEMICOLON; }
{APPEND}                                 { return T_APPEND; }
{AND}                                    { return T_AND; }
{OR}                                     { return T_OR; }
{LESS}                                   { return T_LESS; }
{LESSEQ}                                 { return T_LESSEQ; }
{MORE}                                   { return T_MORE; }
{MOREEQ}                                 { return T_MOREEQ; }
{ATRIB}                                  { return T_ATRIB; }
{COMMA}                                  { return T_COMMA; }
{YIELD}                                  { return T_YIELD; }
{INTEGER}                                { return T_INTEGER; }
{FLOAT}                                  { return T_FLOAT; }
{BOOLEAN}                                { return T_BOOLEAN; }
{DO}                                     { return T_DO; }
{IF}                                     { return T_IF; }
{THEN}                                   { return T_THEN; }
{ELSE}                                   { return T_ELSE; }
{WHILE}                                  { return T_WHILE; }
{READINT}                                { return T_READINT; }
{READFLOAT}                              { return T_READFLOAT; }
{READBOOL}                               { return T_READBOOL; }
{PRINT}                                  { return T_PRINT; }
{LETTER}({LETTER}|_)*                    { return T_ID; }
{NUMBER}+                                { return T_NUMBER; }
{NUMBER}+"."{NUMBER}+                    { return T_FLOATNUM; }
{WS}+                                    { col += yyleng; BEGIN(INITIAL); }
{NL}                                     { col = 1; line++; BEGIN(INITIAL); cout << "\n";}
.                                        { return -1; }


%%

int main(int argc, char *argv[]) {
	yyin = fopen(argv[1], "r");
    int token = 0;

    cout << "============== Tokens reconhecidos ============== \n";
    cout << endl;

    do {
        token = yylex();
        handle_token(token);
        printf(" ");
    } while(token);

    printf("\n");

    if(not error_list.empty()) {
        cout << endl;
        cout << "==================== ERROS =====================";
        cout << endl;
    }

    for(auto it = error_list.begin(); it != error_list.end(); it++) {
        cout << it->msg;
    }
    cout << endl;
}

void handle_token(int token) {

    col += yyleng;

    switch(token) {

        case(T_LCBRACKET):
            printf("T_LCBRACKET");
            break;
           
        case(T_RCBRACKET):
            printf("T_RCBRACKET");
            break;
           
        case(T_LPAREN):
            printf("T_LPAREN");
            break;
              
        case(T_RPAREN):
            printf("T_RPAREN");
            break;
              
        case(T_COLON):
            printf("T_COLON");
            break;
               
        case(T_LARROW):
            printf("T_LARROW");
            break;
              
        case(T_RARROW):
            printf("T_RARROW");
            break;
              
        case(T_NOTEQUAL):
            printf("T_NOTEQUAL");
            break;
            
        case(T_EQUALS):
            printf("T_EQUALS");
            break;
              
        case(T_PLUS):
            printf("T_PLUS");
            break;
                
        case(T_MINUS):
            printf("T_MINUS");
            break;
               
        case(T_DIV):
            printf("T_DIV");
            break;
                 
        case(T_STAR):
            printf("T_STAR");
            break;
                
        case(T_PERCENT):
            printf("T_PERCENT");
            break;
             
        case(T_UNDERSCORE):
            printf("T_UNDERSCORE");
            break;
          
        case(T_DOUBLECOLON):
            printf("T_DOUBLECOLON");
            break;
         
        case(T_LBRACKET):
            printf("T_LBRACKET");
            break;
            
        case(T_RBRACKET):
            printf("T_RBRACKET");
            break;
            
        case(T_SEMICOLON):
            printf("T_SEMICOLON");
            break;
           
        case(T_APPEND):
            printf("T_APPEND");
            break;
              
        case(T_AND):
            printf("T_AND");
            break;
                 
        case(T_OR):
            printf("T_OR");
            break;
                  
        case(T_LESS):
            printf("T_LESS");
            break;
                
        case(T_LESSEQ):
            printf("T_LESSEQ");
            break;
              
        case(T_MORE):
            printf("T_MORE");
            break;
                
        case(T_MOREEQ):
            printf("T_MOREEQ");
            break;
              
        case(T_ATRIB):
            printf("T_ATRIB");
            break;
               
        case(T_COMMA):
            printf("T_COMMA");
            break;
               
        case(T_YIELD):
            printf("T_YIELD");
            break;
               
        case(T_INTEGER):
            printf("T_INTEGER");
            break;
             
        case(T_FLOAT):
            printf("T_FLOAT");
            break;
               
        case(T_BOOLEAN):
            printf("T_BOOLEAN");
            break;
             
        case(T_DO):
            printf("T_DO");
            break;
                  
        case(T_IF):
            printf("T_IF");
            break;
                  
        case(T_THEN):
            printf("T_THEN");
            break;
                
        case(T_ELSE):
            printf("T_ELSE");
            break;
                
        case(T_WHILE):
            printf("T_WHILE");
            break;
               
        case(T_READINT):
            printf("T_READINT");
            break;
             
        case(T_READFLOAT):
            printf("T_READFLOAT");
            break;
           
        case(T_READBOOL):
            printf("T_READBOOL");
            break;
            
        case(T_PRINT):
            printf("T_PRINT");
            break;
               
        case(T_ID):
            printf("T_ID");
            break;
                  
        case(T_NUMBER):
            printf("T_NUMBER");
            break;
              
        case(T_FLOATNUM):
            printf("T_FLOATNUM");
            break;

        case(NEWLINE):
            break;

        case(WHITE):
            printf("QUEEE");
            break;

        case(0):
            break;
            
        default:
            std::string aux = "\n" ;
            aux += to_string(line);
            aux += ":";
            aux += to_string(col);
            aux += " Token não reconhecido \"";
            aux += yytext;
            aux += "\"";
            error_list.push_back(comp_error_t(0, aux));
            /*printf("\n%d:%d: Token não reconhecido ->%s<-", line, col, yytext);*/
            break;
         
     }

}
