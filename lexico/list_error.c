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

/*int main() {*/
    /*list_error_t* root = NULL;*/
    /*comp_error_t* err;*/
    /*comp_error_t* err2;*/


    /*err = make_error(0, "Teste", 0, 1);*/

    /*add_error(&root, err);*/
    /*err2 = make_error(0, "Teste2", 0, 1);*/
    /*add_error(&root, err2);*/

    /*printf("%s\n", root->next->erro->token);*/

    /*return 0;*/
/*}*/
