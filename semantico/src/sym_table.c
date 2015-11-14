#include "sym_table.h"
#define NEW(TYPE) memset(malloc(sizeof(TYPE)), 0, sizeof(TYPE))


/* Cria um novo escopo e aponta a symbol table atual para ele. 
 * Se uma função é passada (contexto não global), ela é associada ao contexto.
 * Se esta função já possui um contexto associado, não é criado um novo, apenas
 * a troca é feita. */
void enter_ctxt(sym_node_t* func) {
    if (func != NULL) {
        if (func->bodies == NULL) {
            sym_table_t* aux = NEW(sym_table_t);
            aux->next = symtable;
            symtable = aux;
            func_bodies* bod = NEW(func_bodies);
            bod->scope = aux;
            func->bodies = bod;
        } else {
            sym_table_t* scope = NEW(sym_table_t);
            scope->next = symtable;
            symtable = scope;
            func_bodies* bod = NEW(func_bodies);
            bod->scope = scope;

            func_bodies* cur = func->bodies;
            while(cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = bod;
        }
    } else {
        sym_table_t* aux = NEW(sym_table_t);
        aux->next = symtable;
        symtable = aux; 
    }
}

void leave_ctxt() {
    sym_table_t* aux;
    if (symtable == NULL) {
        exit(3);
    }
    aux = symtable->next;

    /*sym_node_t* cur = symtable->first_sym;*/

    /*while(cur != NULL) {*/
        /*sym_node_t* tmp = cur->next;*/
        /*free(cur);*/
        /*cur = tmp;*/
    /*}*/

    symtable = aux;
}

void add_symbol(char* label, funtype_t* type, int line) {
    if(symtable == NULL) exit(2);
    sym_node_t* aux = NULL;
    aux = NEW(sym_node_t);

    if (aux == NULL) {
        exit(1);
    }
    aux->label = label;
    aux->type = type;
    aux->line = line;
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
