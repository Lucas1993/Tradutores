#include "list_error.h"

void add_error(list_error_t** root, comp_error_t* erro) {
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
