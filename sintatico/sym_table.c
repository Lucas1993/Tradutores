#include "sym_table.h"

void add_symbol(sym_node_t** root, char* label, funtype_t* type) {
    if(root == NULL) exit(2);
    sym_node_t* aux = NULL;
    aux = (sym_node_t*) malloc(sizeof(sym_node_t));

    if (aux == NULL) {
        exit(1);
    }
    aux->label = label;
    aux->type = type;
    aux->next = NULL;
    if (*root == NULL) {
        *root = aux;
    } else {
        sym_node_t* cur;
        cur = *root;
        while(cur->next != NULL) {
            if (strcmp(cur->label, label) == 0) {
                return;
            }
            cur = cur->next;
        }
        if (strcmp(cur->label, label) == 0) {
            return;
        }
        cur->next = aux;
    }

    return;
}

sym_node_t* get_symbol(sym_node_t* root, char* label) {
    sym_node_t* cur = NULL;
    if (root != NULL) {
        cur = root;
        while(cur != NULL) {
            if (strcmp(cur->label, label) == 0) {
                break;
            } 
            cur = cur->next;
        }
        
    }
    return cur; 
}
