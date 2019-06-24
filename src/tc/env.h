#ifndef env_h
#define env_h

#include "symtab.h"
#include "types.h"

/**
 * env.h: declares the environment (binding pointer)
 * for variables and functions. This env binding will
 * contain all the information necessary to type-check
 * Variables and Functions in tiger.
 */

/* This file specifically declares the binding
 * structure for function and variable declarations.
 *
 * The binding structure for type declarations is 
 * defined in types.c
 */

typedef struct E_enventry_* E_enventry;

struct E_enventry_
{
    enum 
    {
	E_varEntry,
	E_funEntry
    } type;

    union
    {
	struct var_
	{
	    Ty_ty ty;
	} var;

	struct fun_
	{
	    Ty_tyList formals;
	    Ty_ty result;
	} fun;

    } u;
};

/* constructors for filling up the env structure */

E_enventry E_VarEntry(Ty_ty ty);
E_enventry E_FunEntry(Ty_tyList formals, Ty_ty result);

/* base environments */

/* (fill up base env and return symbol tables) */
table E_base_tenv(void);
table E_base_venv(void);

#endif
