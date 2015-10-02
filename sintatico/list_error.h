#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void add_error(list_error_t** root, comp_error_t* erro);
comp_error_t* make_error(int type, char* msg, int line, int col);
void del_list(list_error_t** root);
