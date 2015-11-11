#ifndef SYMTABLE_H
#define SYMTABLE_H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"


typedef struct sym_node_t {
    char* label;
    funtype_t* type;
    struct sym_node_t* next;
} sym_node_t;

typedef struct sym_table_t {
    sym_node_t* first_sym;
    struct sym_table_t* next;
} sym_table_t;


void enter_ctxt();
void leave_ctxt();
sym_node_t* get_symbol(char* label);
void add_symbol(char* label, funtype_t* type);
#endif
