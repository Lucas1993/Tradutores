#include "list_error.h"

void add_error(list_error_t** root, comp_error_t* erro) {
    list_error_t* aux = NULL;
    aux = malloc(sizeof(list_error_t));
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

comp_error_t* make_error(int type, char* token, int line, int col) {
    comp_error_t* err = NULL;
    err = malloc(sizeof(comp_error_t));
    if (err == NULL) {
        exit(1);
    }
    err->type = type;
    char* str = malloc(strlen(token)+1);
    if (str == NULL) {
        exit(1);
    }
    strcpy(str, token);

    err->token = str;
    err->line = line;
    err->col = col;

    return err;
}

void del_list(list_error_t** root) {
    list_error_t* aux = NULL;
    if (root != NULL && (*root) != NULL) {
        if ((*root)->erro != NULL) {
            if ((*root)->erro->token != NULL) {
                free((*root)->erro->token);
            }
            free((*root)->erro);
        }
        if ((*root)->next != NULL) {
            aux = (*root)->next;
        }
        free(*root);
    }
    root = NULL;
    if (aux != NULL) {
        del_list(&aux);
    }

}
