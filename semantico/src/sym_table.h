#ifndef SYMTABLE_H
#define SYMTABLE_H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

struct sym_table_t;
struct func_bodies;

typedef struct sym_node_t {
    char* label;
    int line;
    funtype_t* type;
    struct func_bodies* bodies;
    struct sym_node_t* next;
} sym_node_t;

typedef struct sym_table_t {
    sym_node_t* first_sym;
    struct sym_table_t* next;
} sym_table_t;

typedef struct func_bodies {
    sym_table_t* scope;
    struct func_bodies* next;
} func_bodies;

extern sym_table_t* symtable;

void enter_ctxt(sym_node_t* func);
void leave_ctxt();
sym_node_t* get_symbol(char* label);
void add_symbol(char* label, funtype_t* type, int line);
#endif
