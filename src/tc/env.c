#include <stdio.h>
#include <stdlib.h>
#include "env.h"

/**
 * env.c: contains the implementation of
 * the environment module for functions and
 * variables.
 */


E_enventry E_VarEntry(Ty_ty ty)
{
    E_enventry varEntry = (E_enventry)malloc(sizeof(struct E_enventry_));

    varEntry->type = E_varEntry;
    varEntry->u.var.ty = ty;
    return varEntry;
}


E_enventry E_FunEntry(Ty_tyList formals, Ty_ty result)
{
    E_enventry funEntry = (E_enventry)malloc(sizeof(struct E_enventry_));

    funEntry->type = E_funEntry;
    funEntry->u.fun.formals=formals;
    funEntry->u.fun.result=result;
    return funEntry;
}

/* base environments */

/* (fill up base env and return symbol tables) */

/* init: declare the standard Tiger library
 * functions with these 2 functions..
 */

table E_base_tenv(void)
{
    table t;
    return t;
}

table E_base_venv(void)
{
    table t;
    return t;
}

