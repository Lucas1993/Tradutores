#ifndef LIST_ERROR_H
#define LIST_ERROR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sym_table.h"

typedef struct comp_error_t {
    int type;
    char* msg;
    int line;
    int col;
} comp_error_t;

typedef struct list_error_t {
    comp_error_t* erro;
    struct list_error_t* next;
} list_error_t;

typedef struct not_found_t {
    sym_table_t* scope;
    char* label;
    int line;
    int col;
    struct not_found_t* next;
} not_found_t;

extern not_found_t* not_decl_ids;

void add_error(list_error_t** root, comp_error_t* erro);
comp_error_t* make_error(int type, char* msg, int line, int col);
void del_list(list_error_t* root);

void add_not_declared(sym_table_t* scope, char* label, int line, int col);
void check_all_undeclared();
#endif
