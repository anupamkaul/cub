#ifndef _SEMANT_H
#define _SEMANT_H

#include "types.h"
#include "env.h"
#include "../ast/absyn.h"

/**
 * File semant.h contains external
 * declarations used by the semantic
 * type checker for tiger.
 */

/* expTy contains the translated expression
 * after the typecheck of the entire tiger
 * expression. Evaluated to NULL in chap5.
 * 
 * Will be followed up in later chapters.
 */

/* To be replaced by definition :- */
#define ActualType(x, y) (y)

typedef void* Tr_exp;

struct expty
{
    Ty_ty ty;     /* Type of the expression */
    Tr_exp exp;   /* Translated expression (NULL in chap5) */
};

/* define S_table environment
 * (in terms of table [symtab.c] )
 */

#include "symtab.h"
#define S_table table

/* constructor */
struct expty expTy(Tr_exp exp, Ty_ty ty);

#endif

/* end of semant.h */
