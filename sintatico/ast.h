
struct program_t {
    lines_t* lines; 
};

struct lines_t {
    line_t* line;
    lines_t* lines;
};

struct fun_t {
    char* label;
    args_t* args;
    expr_t* expr;
    where_t* where_exp;
};

struct arg_t {
    list_t* listval;
    basic_val_t* basicval;
};

struct basic_val_t {
    enum { BINT, BFLOAT, BBOOL, BLABEL, BUNIT } valtype ;
    union {
        int intval;
        float floatval;
        int boolval;
        char* label;
    } val;
};

struct funtype_decl_t {
    char* label;
    funtype_t* type;
};

struct funtype_t {
    enum { tbasic, tfunc } typeorder ;
    union {
        basic_type_t* btype;
        funtype_t* ftype;
    } tp;
    funtype_t* next;
};

struct basic_type_t {
    enum { BT_INTEGER, BT_FLOAT, BT_BOOL, BT_LIST, BT_VAR, BT_UNIT } whichtype;
    basic_type_t* internal_list_type;
};

struct expr_t {
    enum { OP_EXPR, APP_EXPR, IF_EXPR, YIELD_EXPR } expr_tp;
    union {
        op_t* op_expr;
        appexpr_t* appexpr;
        ifexpr_t* ifexpr;
        yieldexpr_t* yieldexpr;
    } tp;
};

struct ifexpr_t {
    expr_t* expr1;
    expr_t* expr2;
    expr_t* expr3;
};

struct yieldexpr_t {
    enum { Y_IF, Y_APP, Y_OP } yield_tp;
    union {
        op_t* op_expr;
        appexpr_t* appexpr;
        ifexpr_t* ifexpr;
    } tp;
};

struct op_t {
    enum { O_BVALUE, O_LIST, O_EXPR, O_NEG, O_OR, O_AND, O_EQ, O_DIFF, O_LESS, O_LEQ, O_GREATER, O_GEQ, O_CONS, O_APPEND, O_PLUS, O_MINUS, O_MOD, O_TIMES, O_DIV } op_tp;
    union {
        expr_t* expr1;
        basic_val_t* bval;
        list_expr* lexpr;
    }
    expr_t* expr2; // NULL for op_tp < O_OR
    
};

struct listexpr_t {
    expr_t* expr;
    listexpr_t* next;
};

struct where_t {
    lines_t* lines;
};

struct appexpr_t {
    expr_t* expr1;
    expr_t* expr2;
};

struct list_t {
    enum { LBASIC, LLIST, LWILD } valtype ;
    union {
        list_t* listval;
        basic_val_t* basicval; 
    } val;
    list_t* next;
};

struct proc_t {
    char* label;
    args_t* args;
    stmts_t* stmts;
    where_t* where_exp;
}

struct stmts_t {
    stmt_t* stmt;
    stmts_t* stmts;
};

struct stmt_t {
    char* lhs;
    enum { STMT_EXPR, STMT_WH, STMT_IO } stmt_type;
    union {
        expr_t* expr;
        while_t* while_exp;
        io_t* io_exp;
     } body;
}

struct io_t {
    int type; // 0 = read / 1 = print
    expr_t* expr;
};

struct while_t {
    expr_t* expr;
    stmt_t* stmt;
};
