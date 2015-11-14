#include "types.h"
#define NEW(TYPE) memset(malloc(sizeof(TYPE)), 0, sizeof(TYPE))

extern int line;
extern int col;
extern list_error_t* error_list_root;

int check_args(arg_t* arg, funtype_t* type) {
    if (arg->list_tail == NULL) {
        switch(arg->tp) {
            case AR_INT:
                if(type->typeorder != T_BASIC || type->tp.btype->whichtype != BT_INTEGER ) 
                    return 0;
                break;
            case AR_FLOAT:
                if(type->typeorder != T_BASIC || type->tp.btype->whichtype != BT_FLOAT ) 
                    return 0;
                break;
            case AR_BOOL:
                if(type->typeorder != T_BASIC || type->tp.btype->whichtype != BT_BOOL ) 
                    return 0;
                break;
            case AR_UNIT:
                if(type->typeorder != T_BASIC || type->tp.btype->whichtype != BT_UNIT ) 
                    return 0;
                break;
            case AR_LIST:
                if(type->typeorder != T_BASIC || type->tp.btype->whichtype != BT_LIST ) 
                    return 0;
                break;
            default:
                break;
        }
    } else {
        arg_t* cur = arg;
        if (type->typeorder != T_BASIC || type->tp.btype->whichtype != BT_LIST) 
            return 0;

        while(cur->list_tail != NULL) {
            basic_type_t* internal = type->tp.btype->internal_list_type;

            switch(cur->tp) {
                case AR_INT:
                    if(internal->whichtype != BT_INTEGER ) 
                        return 0;
                    break;
                case AR_FLOAT:
                    if(internal->whichtype != BT_FLOAT ) 
                        return 0;
                    break;
                case AR_BOOL:
                    if(internal->whichtype != BT_BOOL ) 
                        return 0;
                    break;
                case AR_UNIT:
                    if(internal->whichtype != BT_UNIT ) 
                        return 0;
                    break;
                case AR_LIST:
                    if(internal->whichtype != BT_LIST ) 
                        return 0;
                    break;
                default:
                    break;
            }
            cur = cur->list_tail;
            if (cur->tp != AR_LIST || cur->tp != AR_UNDERSCORE || cur->tp != AR_LABEL) 
                return 0;

        } 
    }

    return 1;

}


void declare_args(args_t* args, sym_node_t* sym) {
    args_t* a_cur = args;
    funtype_t* f_cur = sym->type;
    int i = 0;
    int flag = 0;

    // Declara cada argumento da lista de argumentos
    while(a_cur != NULL) {
        flag = 0;
        i++;
        // Confere o número de argumentos
        if (f_cur == NULL || f_cur->next == NULL) {
            size_t sz = 140 + strlen(sym->label);
            char* msg = malloc(sz);

            sprintf(msg, "%d:%d: semantical error: wrong number of arguments on function \"%s\"\n", line, col, sym->label);
            comp_error_t* err = make_error(3, msg, line, col);
            add_error(&error_list_root, err);
            flag = 1;
            break;
        }

        // Se o argumento atual não é da forma x:xs
        if (a_cur->arg->list_tail == NULL) {
            if(check_args(a_cur->arg, f_cur) == 0) {
                size_t sz = 140 + strlen(sym->label);
                char* msg = malloc(sz);

                sprintf(msg, "%d:%d: semantical error: on function \"%s\": the type of parameter %d does not match the function signature\n", line, col, sym->label, i);
                comp_error_t* err = make_error(3, msg, line, col);
                add_error(&error_list_root, err);
                flag = 1;

                a_cur = a_cur->next;
                f_cur = f_cur->next;
                continue;
            }

            // Se o tipo for generico, casa com qualquer coisa
            if (a_cur->arg->tp == AR_LABEL) {
                if (f_cur->typeorder != T_BASIC) {
                    add_symbol(a_cur->arg->opt.label, f_cur->tp.ftype, line);
                } else {
                    funtype_t* tmp = NEW(funtype_t);
                    tmp->typeorder = T_BASIC;
                    tmp->tp.btype = f_cur->tp.btype;
                    add_symbol(a_cur->arg->opt.label, tmp, line);
                }
                
            } 

        // Se o argumento atual é da forma x:xs
        } else {

            arg_t* a_tmp = a_cur->arg;

            //Pega o tipo interno da lista
            funtype_t* tmp = NEW(funtype_t);
            tmp->typeorder = T_BASIC;
            tmp->tp.btype = f_cur->tp.btype->internal_list_type;
            // Pra cada elemento da lista, exceto o ultimo
            while(a_tmp->list_tail != NULL) {


                // Retira o resto da lista para a função de checagem funcionar
                arg_t* a_tmp2 = a_tmp->list_tail;
                a_tmp->list_tail = NULL;

                if(check_args(a_tmp, tmp) == 0) {
                    printf("\n\n%d/%d\n\n", a_tmp->tp, tmp->tp.btype->whichtype);
                    size_t sz = 140 + strlen(sym->label);
                    char* msg = malloc(sz);

                    sprintf(msg, "%d:%d: semantical error: on function \"%s\": the type of parameter %d does not match the function signature\n", line, col, sym->label, i);
                    comp_error_t* err = make_error(3, msg, line, col);
                    add_error(&error_list_root, err);
                    flag = 1;


                    a_tmp->list_tail = a_tmp2;
                    a_cur = a_cur->next;
                    f_cur = f_cur->next;
                    break;
                    
                }

                // Recupera o resto da lista
                a_tmp->list_tail = a_tmp2;

                if (a_tmp->tp == AR_LABEL) {
                    funtype_t* tmp2 = NEW(funtype_t);
                    memcpy(tmp2, tmp, sizeof(funtype_t));
                    add_symbol(a_tmp->opt.label, tmp2, line);
                }

                a_tmp = a_tmp->list_tail;
            }
            free(tmp);
            if (flag) continue;
            tmp = NEW(funtype_t);
            tmp->typeorder = T_BASIC;
            tmp->tp.btype = f_cur->tp.btype;
            if(check_args(a_tmp, tmp) == 0) {
                size_t sz = 140 + strlen(sym->label);
                char* msg = malloc(sz);

                sprintf(msg, "%d:%d: semantical error: on function \"%s\": the type of parameter %d does not match the function signature\n", line, col, sym->label, i);
                comp_error_t* err = make_error(3, msg, line, col);
                add_error(&error_list_root, err);
                flag = 1;
                
            } else {
                if (a_tmp->tp == AR_LABEL) {
                    add_symbol(a_tmp->opt.label, tmp, line); 
                }
            
            }

        }
        a_cur = a_cur->next;
        f_cur = f_cur->next;
    }
    if (f_cur->next != NULL && !flag) {
            size_t sz = 140 + strlen(sym->label);
            char* msg = malloc(sz);

            sprintf(msg, "%d:%d: semantical error: wrong number of arguments on function \"%s\"\n", line, col, sym->label);
            comp_error_t* err = make_error(3, msg, line, col);
            add_error(&error_list_root, err);
    }
}
