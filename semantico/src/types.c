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

    while(a_cur != NULL) {
        i++;
        if (f_cur == NULL || f_cur->next == NULL) {
            size_t sz = 256;
            char* msg = malloc(sz);

            sprintf(msg, "%d:%d: semantical error: wrong number of arguments\n", line, col);
            comp_error_t* err = make_error(3, msg, line, col);
            add_error(&error_list_root, err);
            flag = 1;
            break;
        }
        if(check_args(a_cur->arg, f_cur) == 0) {
            size_t sz = 256;
            char* msg = malloc(sz);

            sprintf(msg, "%d:%d: semantical error: argument %d is of the wrong type\n", line, col, i);
            comp_error_t* err = make_error(3, msg, line, col);
            add_error(&error_list_root, err);
            flag = 1;
            break;
        }
        if (a_cur->arg->list_tail == NULL) {
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
        } else {
            arg_t* a_tmp = a_cur->arg;
            while(a_tmp->list_tail != NULL) {
                if (a_tmp->tp == AR_LABEL) {
                    funtype_t* tmp = NEW(funtype_t);
                    tmp->typeorder = T_BASIC;
                    tmp->tp.btype = f_cur->tp.btype->internal_list_type;
                    add_symbol(a_tmp->opt.label, tmp, line);
                }
                a_tmp = a_tmp->list_tail;
            }
            if (a_tmp->tp == AR_LABEL) {
                funtype_t* tmp = NEW(funtype_t);
                tmp->typeorder = T_BASIC;
                tmp->tp.btype = f_cur->tp.btype;
                add_symbol(a_tmp->opt.label, tmp, line); 
            }
        }
        a_cur = a_cur->next;
        f_cur = f_cur->next;
    }
    if (f_cur->next != NULL && !flag) {
            size_t sz = 256;
            char* msg = malloc(sz);

            sprintf(msg, "%d:%d: semantical error: wrong number of arguments\n", line, col);
            comp_error_t* err = make_error(3, msg, line, col);
            add_error(&error_list_root, err);
    }
}
