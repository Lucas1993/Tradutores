#include "sym_table.h"

sym_table_t* symtable = NULL;

void enter_ctxt() {
    sym_table_t* aux = malloc(sizeof(sym_table_t));
    aux->next = symtable;
    symtable = aux;
}

void leave_ctxt() {
    sym_table_t* aux;
    if (symtable == NULL) {
        exit(3);
    }
    aux = symtable->next;

    sym_node_t* cur = symtable->first_sym;

    while(cur != NULL) {
        sym_node_t* tmp = cur->next;
        free(cur);
        cur = tmp;
    }

    symtable = aux;
}

void add_symbol(char* label, funtype_t* type) {
    if(symtable == NULL) exit(2);
    sym_node_t* aux = NULL;
    aux = (sym_node_t*) malloc(sizeof(sym_node_t));

    if (aux == NULL) {
        exit(1);
    }
    aux->label = label;
    aux->type = type;
    aux->next = NULL;
    if (symtable->first_sym == NULL) {
        symtable->first_sym = aux;
    } else {
        sym_node_t* cur;
        cur = symtable->first_sym;
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
sym_node_t* get_symbol(char* label) {
    sym_node_t* cur = NULL;
    sym_table_t* st = symtable;
    int found = 0;
    while (st != NULL && !found) {
        cur = st->first_sym;
        while(cur != NULL) {
            if (strcmp(cur->label, label) == 0) {
                found = 1;
                break;
            } 
            cur = cur->next;
        }
        st = st->next; 
    }
    return cur; 
}

/*int main() {*/
    
    /*enter_ctxt();*/
    /*char* txt; */

    /*txt = strdup("aa");*/
    /*add_symbol(txt, NULL);*/

    /*txt = strdup("bb");*/
    /*add_symbol(txt, NULL);*/

    /*enter_ctxt();*/
    /*txt = strdup("cc");*/
    /*add_symbol(txt, NULL);*/

    /*sym_node_t* aux = get_symbol("aa");*/
    /*if (aux) {*/
        /*printf("%s", aux->label);*/
    /*} else {*/
        /*printf("loko");*/
    /*}*/
    /*leave_ctxt();*/
    /*leave_ctxt();*/


    /*return 0;*/
/*}*/
