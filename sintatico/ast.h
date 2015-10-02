typedef struct while_t          while_t;
typedef struct io_t             io_t;
typedef struct stmt_t           stmt_t;
typedef struct stmts_t          stmts_t;
typedef struct proc_t           proc_t;
typedef struct appexpr_t        appexpr_t;
typedef struct where_t          where_t;
typedef struct exprs_t          exprs_t;
typedef struct op_t             op_t;
typedef struct yieldexpr_t      yieldexpr_t;
typedef struct ifexpr_t         ifexpr_t;
typedef struct expr_t           expr_t;
typedef struct basic_type_t     basic_type_t;
typedef struct funtype_t        funtype_t;
typedef struct funtype_decl_t   funtype_decl_t;
typedef struct basic_val_t      basic_val_t;
typedef struct arg_t            arg_t;
typedef struct fun_t            fun_t;
typedef struct lines_t          lines_t;
typedef struct line_t           line_t;
typedef struct args_t           args_t;
typedef struct program_t        program_t;
typedef struct list_args_t      list_args_t;
typedef struct built_list_val_t built_list_val_t;
typedef struct nonapp_t         nonapp_t;
typedef struct list_value_t     list_value_t;
typedef struct id_list_t        id_list_t;

struct program_t {
    lines_t* lines; 
};

struct lines_t {
    line_t* line;
    lines_t* next;
};

struct line_t {
    enum { L_FUN, L_PROC, L_FUNTYPE } opt_type;
    union {
        fun_t* fun;
        proc_t* proc;
        funtype_decl_t* funtype;
    } opt;
};

struct fun_t {
    char* label;
    args_t* args;
    expr_t* expr;
    where_t* where_exp;
};

struct args_t {
    arg_t* arg;
    args_t* next;
};

struct arg_t {
    enum { AR_LIST, AR_BASIC, AR_ARG } tp;
    union {
        list_value_t* listval;
        basic_val_t* basicval;
        arg_t* argval;
    } opt;
};

struct basic_val_t {
    enum { BINT, BFLOAT, BBOOL, BLABEL, BID, BUNIT } valtype ;
    union {
        int intval;
        float floatval;
        int boolval;
        char* label;
        id_list_t* ids;
    } val;
};

struct list_value_t {
    enum { LS_BASIC, LS_LIST, LS_WLD, LS_BLT } ls_type;
    union {
        basic_val_t* basic_val;
        list_args_t* list_args_val;
        built_list_val_t* built_list_val;
    } opt;
    list_value_t* next;
};

struct built_list_val_t {
    list_args_t* vals;
};

struct list_args_t {
    arg_t* arg;
    list_args_t* next;
};

struct funtype_decl_t {
    char* label;
    funtype_t* type;
};

struct funtype_t {
    enum { T_BASIC, T_FUNC } typeorder ;
    union {
        basic_type_t* btype;
        funtype_t* ftype;
    } tp;
    funtype_t* next;
};

struct basic_type_t {
    enum { BT_INTEGER, BT_FLOAT, BT_BOOL, BT_LIST, BT_VAR, BT_UNIT } whichtype;
    char* label;
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
    enum { O_BVALUE, O_LIST, O_EXPR, O_NEG, O_NEXT, O_OR, O_AND, O_EQ, O_DIFF, O_LESS, O_LEQ, O_GREATER, O_GEQ, O_CONS, O_APPEND, O_PLUS, O_MINUS, O_MOD, O_TIMES, O_DIV } op_tp;
    union {
        op_t* opt1;
        expr_t* expr;
        basic_val_t* bval;
        exprs_t* lexpr;
    } opt;
    op_t* opt2; // NULL for op_tp < O_OR
    
};

struct exprs_t {
    expr_t* expr;
    exprs_t* next;
};

struct where_t {
    lines_t* lines;
};

struct appexpr_t {
    enum { A_APP, A_NAPP } tp;
    union {
        appexpr_t* app;
        nonapp_t* napp1;
    } app_tp;

    nonapp_t* napp2;
};

struct nonapp_t {
    enum { NA_BASIC, NA_EXPR } tp;
    union {
        basic_val_t* bvalue;
        expr_t* expr;
    } n_tp;
};

struct id_list_t {
    char* label;
    id_list_t* next;
};

struct proc_t {
    char* label;
    args_t* args;
    stmts_t* stmts;
    where_t* where_exp;
};

struct stmts_t {
    stmt_t* stmt;
    stmts_t* next;
};

struct stmt_t {
    char* lhs;
    enum { STMT_EXPR, STMT_WH, STMT_IO } stmt_type;
    union {
        expr_t* expr;
        while_t* while_expr;
        io_t* io_expr;
     } body;
};

struct io_t {
    enum { I_READINT, I_READFLOAT, I_READBOOL, I_PRINT } opt;
    expr_t* expr;
};

struct while_t {
    expr_t* expr;
    stmts_t* stmts;
};
