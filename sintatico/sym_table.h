#ifndef SYMTABLE_H
#define SYMTABLE_H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"


typedef struct sym_node_t {
    char* label;
    struct sym_node_t* next;
    funtype_t* type;
} sym_node_t;

sym_node_t* get_symbol(sym_node_t* root, char* label);
void add_symbol(sym_node_t** root, char* label, funtype_t* type);
#endif
