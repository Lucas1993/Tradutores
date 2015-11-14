#include "list_error.h"

extern list_error_t* error_list_root;
extern int has_errors;

void add_error(list_error_t** root, comp_error_t* erro) {
    has_errors = 1;
    if(root == NULL) exit(2);
    list_error_t* aux = NULL;
    aux = (list_error_t*) malloc(sizeof(list_error_t));
    /*memset(aux, 0, sizeof(list_error_t));*/
    if (aux == NULL) {
        exit(1);
    }
    aux->erro = erro;
    aux->next = NULL;
    if (*root == NULL) {
        *root = aux;
    } else {
        list_error_t* cur;
        cur = *root;
        while(cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = aux;
    }

    return;

}

comp_error_t* make_error(int type, char* msg, int line, int col) {
    comp_error_t* err = NULL;
    err = (comp_error_t*) malloc(sizeof(comp_error_t));
    /*memset(err, 0, sizeof(comp_error_t));*/
    if (err == NULL) {
        exit(1);
    }
    err->type = type;
    err->msg = msg;
    err->line = line;
    err->col = col;

    return err;
}

void del_list(list_error_t* root) {
    list_error_t* cur = NULL;
    list_error_t* next = NULL;
    cur = root;
    next = cur->next;
    while (cur != NULL) {
        if ((cur)->erro != NULL) {
            if ((cur)->erro->msg != NULL) {
                free((cur)->erro->msg);
                (cur)->erro->msg = NULL;
            }
            free((cur)->erro);
            (cur)->erro = NULL;
        }

        free(cur);
        cur = next;
        next = (next)->next;

    }

}

void add_not_declared(sym_table_t* scope, char* label, int line, int col) {
    not_found_t* aux = (not_found_t*) malloc(sizeof(not_found_t));
    memset(aux, 0, sizeof(not_found_t));

    aux->scope = scope;
    aux->label = label;
    aux->line = line;
    aux->col = col;

    if (not_decl_ids == NULL) {
        not_decl_ids = aux;
    } else {
        not_found_t* tmp = not_decl_ids;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = aux;
    }

}

void check_all_undeclared() {
    not_found_t* cur = not_decl_ids;
    while(cur != NULL) {
        sym_table_t* old_st = symtable;
        symtable = cur->scope;

        sym_node_t* node = get_symbol(cur->label);

        if (node == NULL) {
            size_t sz = 256 + strlen(cur->label);
            char* msg = malloc(sz);

            sprintf(msg, "%d:%d: semantical error: identifier %s not declared\n", cur->line, cur->col, cur->label);
            comp_error_t* err = make_error(3, msg, cur->line, cur->col);
            add_error(&error_list_root, err);
        }

        symtable = old_st;
        cur = cur->next;
    }
}
