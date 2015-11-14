#ifndef TYPES_H
#define TYPES_H

#include "ast.h"
#include "list_error.h"
#include "sym_table.h"
#include <string.h>
#include <stdlib.h>

int check_args(arg_t* arg, funtype_t* type);
void declare_args(args_t* args, sym_node_t* sym);

#endif

