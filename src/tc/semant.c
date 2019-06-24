#include <stdio.h>
#include <stdlib.h>

#include "../ast/absyn_def.h"
#include "symtab.h"
#include "semant.h"
#include "semant_utils.h"
#include <assert.h>

/**
 * File semant.c implements the semantic
 * type checker for the tiger language.
 *
 * Semant.c translates the abstract syntax
 * tree into an intermediate expression tree
 * (null for now), while performing a 
 * type-check along the way.
 *
 * Note - The new tree (expty) is used for the
 * type-check, even if the translated expression
 * is null for now.
 */

#ifdef RUN_AND_TEST_TC
A_exp AST_root = NULL;
#else
extern A_exp        AST_root;
#endif

/* Use expTy to allocate the TYPE of the expression */
struct expty expTy(Tr_exp exp, Ty_ty ty)
{
    struct expty e;
    e.exp = exp;
    e.ty = ty;
    return e;
}

/**
 * The following (mutually) recursive functions travel the AST
 * and do symbol-table generation and Type-Check the input based
 * on the restrictions we set for Tiger.
 */

struct expty transVar(S_table venv, S_table tenv, A_var v);
struct expty transExp(S_table venv, S_table tenv, A_exp e);
struct expty transDec(S_table venv, S_table tenv, A_dec d);
Ty_ty transTy(S_table tenv, A_ty a);

/**
 * The following are debug versions of AST parsers so we can
 * start moving fast and debug issues. Not for production but
 * good for debug.
 */
struct expty parseASTVar(S_table venv, S_table tenv, A_var v);
struct expty parseASTExp(S_table venv, S_table tenv, A_exp e);
struct expty parseASTDec(S_table venv, S_table tenv, A_dec d);

void EM_error(int pos, STR string);

#ifdef RUN_AND_TEST_TC
main()
#else
tc_main()
#endif
{

    /* This module integrates the abstract syntax tree created in the previous
     * phase with operations that will go in this phase:
     * 1. symbol table generation and usage
     * 2. type checking
     * 3. conversion to an IR represenation.
     */

    fprintf(stderr, "[semant]: semantic analysis and typecheck start\n");

    fprintf(stderr, "[semant]: initialize symbol table V\n");
    table symtab_v = TAB_empty();
    fprintf(stderr, "[semant]: initialize symbol table T\n");
    table symtab_t = TAB_empty();

    //fprintf(stderr, "[semant]: STARTING SEMANTIC ANALYSIS OF AST_ROOT NOW\n");
    fprintf(stderr, "[%s]: Tiger: STARTING SEMANTIC ANALYSIS OF AST_ROOT NOW\n", __FILE__);
    //transExp(symtab_v, symtab_t, AST_root);
    parseASTExp(symtab_v, symtab_t, AST_root);

    return;
}

/* definition of functions */
struct expty transExp(S_table venv, S_table tenv, A_exp e)
{
	fprintf(stderr, "[%s] %s:\n", __FILE__,  __PRETTY_FUNCTION__);
	struct expty tr_exp;

        assert(e);

	switch(e->kind)
	{
		case varexp:
			{
				/* lvalue var (simple, array, record) at usage */
                                fprintf(stderr, "CASE OF VAREXP\n");
				tr_exp = transVar(venv, tenv, e->exptype.varexp.var);
			}
			break;


		case nilexp:
                                fprintf(stderr, "CASE OF NILEXP\n");
				break;

        	case intexp:
                                fprintf(stderr, "CASE OF INTEXP\n");
				break;

		case strexp:
                                fprintf(stderr, "CASE OF STREXP\n");
				break;

        	case callexp:
                                fprintf(stderr, "CASE OF CALLEXP\n");
				break;

        	case bopexp:
			{
				#define utype exptype
                                fprintf(stderr, "CASE OF BOPEXP\n");
				A_oper op = e->utype.bopexp.oper;
				struct expty left  = transExp(venv, tenv, e->utype.bopexp.left);
				struct expty right = transExp(venv, tenv, e->utype.bopexp.right);

				/* Note, need to parse ty_Name to its base_type when required */

				switch(e->utype.bopexp.oper)
				{
					case A_plusOp:
					case A_minusOp:
					case A_timesOp:

						if(left.ty->type != ty_Int || right.ty->type != ty_Int)
						{
						    /* utilize EM_error */
						    fprintf(stderr, "type mismatch arith oper at line %d\n", *(e->pos->line));
						    exit(0);
						}

						/* put higher (real vs int) and do conv of operands */
						/* note that add/mult/sub of 2 reals can be an int */

						tr_exp = expTy(NULL, Ty_Int());

					     break;

					case A_divideOp:

						/* I seperate the division case, for now, to find out
						 * if its possible to check for divide by zero condition
						 * statically. Maybe its during code-structure analysis.
						 */

						if(left.ty->type != ty_Int || right.ty->type != ty_Int)
						{
						    /* utilize EM_error */
						    fprintf(stderr, "type mismatch div oper at line %d\n", *(e->pos->line));
						    exit(0);
						}

						/* put higher (real vs int) and do conv of operands */
						/* note that division of 2 ints can be a real */

						tr_exp = expTy(NULL, Ty_Int());

					     break;

					case A_ltOp:
					case A_gtOp:
					case A_geOp:
					case A_leOp:

					     /* types here have to be comparable - I am choosing
					      * Ty_Int and Ty_STR. Ty_STR will do an implicit
					      * strcmp for the comparison during execution.
					      */

					        if(left.ty->type != right.ty->type)
						{
						    /* utilize EM_error */
						    fprintf(stderr, "type mismatch cmpr oper at line %d\n", *(e->pos->line));
						    exit(0);
						}

						if( (left.ty->type != ty_Int && left.ty->type != ty_String) ||
						    (right.ty->type != ty_Int && right.ty->type != ty_String))
						{
						    /* utilize EM_error */
						    fprintf(stderr, "type mismatch cmpr oper at line %d\n", *(e->pos->line));
						    exit(0);
						}

						/* The return type is Ty_Void */
						tr_exp = expTy(NULL, Ty_Void());

					     break;

					case A_eqOp:
					case A_neqOp:

					     /* I include here Ty_Int, Ty_STR, Ty_Record, Ty_Array
					      * and I MISS an [In_This_Set] construct for tiger ! 
					      */

                                		fprintf(stderr, "CASE OF EQEXP OR NEQEXP\n");
					        if(left.ty->type != right.ty->type)
						{
						    /* utilize EM_error */
						    fprintf(stderr, "type mismatch cmpr oper at line %d\n", *(e->pos->line));
						    exit(0);
						}

						if( (left.ty->type != ty_Int && left.ty->type != ty_String 
						    && left.ty->type != ty_Record && left.ty->type != ty_Array) 
						||
						    (right.ty->type != ty_Int && right.ty->type != ty_String
						    && right.ty->type != ty_Record && right.ty->type != ty_Array))
						{
						    /* utilize EM_error */
						    fprintf(stderr, "type mismatch cmpr oper at line %d\n", *(e->pos->line));
						    exit(0);
						}

						/* The return type is Ty_Void */
						tr_exp = expTy(NULL, Ty_Void());

					     break;

					case A_andOp:
					case A_orOp:
                                		fprintf(stderr, "CASE OF AND OR EXP\n");

					     /* types have to be ANDable and ORable. In the absence of 
					      * other numerical qtys like long, short, bytes, it can be
					      * Ty_Int only (directly or ultimately)
					      */

						if(left.ty->type != ty_Int || right.ty->type != ty_Int)
						{
						    /* utilize EM_error */
						    fprintf(stderr, "type mismatch arith oper at line %d\n", *(e->pos->line));
						    exit(0);
						}

						/* return type is Ty_Void */
						tr_exp = expTy(NULL, Ty_Void());

					     break;

					default:
					     fprintf(stderr, "un-handled type case for bin op %d\n", e->utype.bopexp.oper);
					     break;

				}

				break;
			}

        	case recexp:
                                fprintf(stderr, "CASE OF RECEXP\n");
				break;

		case aryexp:
                                fprintf(stderr, "CASE OF ARYEXP\n");
				break;

        	case seqexp:
                                fprintf(stderr, "CASE OF SEQEXP\n");
				break;

        	case asnexp:
                                fprintf(stderr, "CASE OF ASNEXP\n");
				break;

		case ifexp:
                                fprintf(stderr, "CASE OF IFEXP\n");
				break;

		case whlexp:
                                fprintf(stderr, "CASE OF WHLEXP\n");
				break;

		case brkexp:
                                fprintf(stderr, "CASE OF BRKEXP\n");
				break;

		case forexp:
                                fprintf(stderr, "CASE OF FOREXP\n");
				break;

		case letexp:
                                fprintf(stderr, "CASE OF LETEXP\n");
                        	fprintf(stderr, "[semant]: LET scope block at (%d,%d)\n", *(e->pos->line), *(e->pos->col));

				/* The Let expression has an initial declarations section
                         	* which binds some variables for this scope. We generate
                         	* symbol tables for locals at this point, and we use these
                         	* tables to evaluate the corresponding expression section
                         	* of this Let expression.
                         	*/


				break;

		default:
                                fprintf(stderr, "CASE OF DEFAULT\n");
				break;
			
	}

	return tr_exp;
}

struct expty transVar(S_table venv, S_table tenv, A_var a_var)
{
	fprintf(stderr, "[%s] %s:\n", __FILE__,  __PRETTY_FUNCTION__);
	struct expty tr_exp;

	                /* TOO MANY COMMENTS, REMOVE THEM :- 
			 *
			 * In all cases, we check if the variable has been
			 * declared at this point; for an array-subscript, we
			 * check the type of expression in the subscript,
			 * while for record, we check if field is valid and
			 * exists, while matching the expanded field list. 
			 *
			 * These vars if existing, should have had their
			 * types identified and allocated at declaration.
			 *
			 */

			E_enventry var_entry;
			Ty_ty ty;

			/* note - 
			 * 1. need an interface for var_lookup, which conv to symbol,
			 * and performs the two tests for NULL and Not_Var
			 *
			 * 2. need a recursive fn to derive the varname for
			 * field or subscript vars?
			 *
			 * 3. need to define ActualType
			 * (recur for ty_name else return)
			 */

			switch(a_var->kind)
			{
			    case simple:
				    var_entry = TAB_lookup(venv, Symbol(a_var->vartype.simple.name));
				    if(var_entry == NULL)
				    {
		 			/* utilize EM_error */
		 			 fprintf(stderr, "Variable %s not declared at line %d\n", a_var->vartype.simple.name, *(a_var->pos->line));
		 			 exit(0);
				    }  

				    if(var_entry->type != E_varEntry)
				    {
		 			/* utilize EM_error */
					fprintf(stderr, "Illegal type namespace associated with variable %s at line %d\n", a_var->vartype.simple.name, *(a_var->pos->line));
					exit(0);
				    }

				    /* make sure we can pass ty of this struct instead of creating new type */
				    tr_exp = expTy(NULL, ActualType(tenv, var_entry->u.var.ty));

				break;

			    case field: 
			    case subscript:

				   tr_exp = expTy(NULL, tc_var(venv, tenv, a_var));

				break;

			    default:
				break;

			}

	return tr_exp;
}

struct expty transDec(S_table venv, S_table tenv, A_dec d)
{
	fprintf(stderr, "[%s] %s:\n", __FILE__,  __PRETTY_FUNCTION__);
	struct expty tr_exp;

	switch(d->kind)
	{
		case typedec:
			break;

		case vardec:
			break;

		case fundec:
			break;

		default:
			break;
	}

	return tr_exp;

}

Ty_ty transTy(S_table tenv, A_ty t)
{
	Ty_ty ty;

	switch(t->kind)
	{
		case name:
			break;

		case rec:
			break;

		case ary:
			break;

		default:
			break;
	}

	return ty;
}

/* Debug versions of AST parsers */

struct expty parseASTExp(S_table venv, S_table tenv, A_exp e)
{
	fprintf(stderr, "[%s] %s:\n", __FILE__,  __PRETTY_FUNCTION__);
	struct expty tr_exp;

        assert(e);

	switch(e->kind)
	{
		case varexp:
			{
				/* lvalue var (simple, array, record) at usage */
                                fprintf(stderr, "[%s]: CASE OF VAREXP\n", __FILE__);
				tr_exp = transVar(venv, tenv, e->exptype.varexp.var);
			}
			break;


		case nilexp:
                                fprintf(stderr, "[%s]: CASE OF NILEXP\n", __FILE__);
				break;

        	case intexp:
                                fprintf(stderr, "[%s]: CASE OF INTEXP\n", __FILE__);
				break;

		case strexp:
                                fprintf(stderr, "[%s]: CASE OF STREXP\n", __FILE__);
				break;

        	case callexp:
                                fprintf(stderr, "[%s]: CASE OF CALLEXP\n", __FILE__);
				break;

        	case bopexp:
			{
				#define utype exptype
                                fprintf(stderr, "CASE OF BOPEXP\n");
				A_oper op = e->utype.bopexp.oper;
				struct expty left  = transExp(venv, tenv, e->utype.bopexp.left);
				struct expty right = transExp(venv, tenv, e->utype.bopexp.right);

				/* Note, need to parse ty_Name to its base_type when required */

				switch(e->utype.bopexp.oper)
				{
					case A_plusOp:
					case A_minusOp:
					case A_timesOp:

						if(left.ty->type != ty_Int || right.ty->type != ty_Int)
						{
						    /* utilize EM_error */
						    fprintf(stderr, "type mismatch arith oper at line %d\n", *(e->pos->line));
						    exit(0);
						}

						/* put higher (real vs int) and do conv of operands */
						/* note that add/mult/sub of 2 reals can be an int */

						tr_exp = expTy(NULL, Ty_Int());

					     break;

					case A_divideOp:

						/* I seperate the division case, for now, to find out
						 * if its possible to check for divide by zero condition
						 * statically. Maybe its during code-structure analysis.
						 */

						if(left.ty->type != ty_Int || right.ty->type != ty_Int)
						{
						    /* utilize EM_error */
						    fprintf(stderr, "type mismatch div oper at line %d\n", *(e->pos->line));
						    exit(0);
						}

						/* put higher (real vs int) and do conv of operands */
						/* note that division of 2 ints can be a real */

						tr_exp = expTy(NULL, Ty_Int());

					     break;

					case A_ltOp:
					case A_gtOp:
					case A_geOp:
					case A_leOp:

					     /* types here have to be comparable - I am choosing
					      * Ty_Int and Ty_STR. Ty_STR will do an implicit
					      * strcmp for the comparison during execution.
					      */

					        if(left.ty->type != right.ty->type)
						{
						    /* utilize EM_error */
						    fprintf(stderr, "type mismatch cmpr oper at line %d\n", *(e->pos->line));
						    exit(0);
						}

						if( (left.ty->type != ty_Int && left.ty->type != ty_String) ||
						    (right.ty->type != ty_Int && right.ty->type != ty_String))
						{
						    /* utilize EM_error */
						    fprintf(stderr, "type mismatch cmpr oper at line %d\n", *(e->pos->line));
						    exit(0);
						}

						/* The return type is Ty_Void */
						tr_exp = expTy(NULL, Ty_Void());

					     break;

					case A_eqOp:
					case A_neqOp:

					     /* I include here Ty_Int, Ty_STR, Ty_Record, Ty_Array
					      * and I MISS an [In_This_Set] construct for tiger ! 
					      */

                                		fprintf(stderr, "CASE OF EQEXP OR NEQEXP\n");
					        if(left.ty->type != right.ty->type)
						{
						    /* utilize EM_error */
						    fprintf(stderr, "type mismatch cmpr oper at line %d\n", *(e->pos->line));
						    exit(0);
						}

						if( (left.ty->type != ty_Int && left.ty->type != ty_String 
						    && left.ty->type != ty_Record && left.ty->type != ty_Array) 
						||
						    (right.ty->type != ty_Int && right.ty->type != ty_String
						    && right.ty->type != ty_Record && right.ty->type != ty_Array))
						{
						    /* utilize EM_error */
						    fprintf(stderr, "type mismatch cmpr oper at line %d\n", *(e->pos->line));
						    exit(0);
						}

						/* The return type is Ty_Void */
						tr_exp = expTy(NULL, Ty_Void());

					     break;

					case A_andOp:
					case A_orOp:
                                		fprintf(stderr, "CASE OF AND OR EXP\n");

					     /* types have to be ANDable and ORable. In the absence of 
					      * other numerical qtys like long, short, bytes, it can be
					      * Ty_Int only (directly or ultimately)
					      */

						if(left.ty->type != ty_Int || right.ty->type != ty_Int)
						{
						    /* utilize EM_error */
						    fprintf(stderr, "type mismatch arith oper at line %d\n", *(e->pos->line));
						    exit(0);
						}

						/* return type is Ty_Void */
						tr_exp = expTy(NULL, Ty_Void());

					     break;

					default:
					     fprintf(stderr, "un-handled type case for bin op %d\n", e->utype.bopexp.oper);
					     break;

				}

				break;
			}

        	case recexp:
                                fprintf(stderr, "[%s]: CASE OF RECEXP\n", __FILE__);
				break;

		case aryexp:
                                fprintf(stderr, "[%s]: CASE OF ARYEXP\n", __FILE__);
				break;

        	case seqexp:
                                fprintf(stderr, "[%s]: CASE OF SEQEXP\n", __FILE__);
 
                                while(e->exptype.seqexp.seq) {
                                   tr_exp = parseASTExp(venv, tenv, e->exptype.seqexp.seq->head);
                                   e->exptype.seqexp.seq = e->exptype.seqexp.seq->tail;
                                }

				break;

        	case asnexp:
                                fprintf(stderr, "[%s]: CASE OF ASNEXP\n", __FILE__);
				break;

		case ifexp:
                                fprintf(stderr, "[%s]: CASE OF IFEXP\n", __FILE__);
				break;

		case whlexp:
                                fprintf(stderr, "[%s]: CASE OF WHLEXP\n", __FILE__);
				break;

		case brkexp:
                                fprintf(stderr, "[%s]: CASE OF BRKEXP\n", __FILE__);
				break;

		case forexp:
                                fprintf(stderr, "[%s]: CASE OF FOREXP\n", __FILE__);
				break;

		case letexp:
                                fprintf(stderr, "[%s]: CASE OF LETEXP\n", __FILE__);
                        	fprintf(stderr, "[%s]: LET scope block at (%d,%d)\n", __FILE__, *(e->pos->line), *(e->pos->col));

                               // From AST Tree Def: 
                               // let_decl  : let_kwd <decls> in_kwd <expseq> end_kwd 

			       /* The Let expression has an initial declarations section
                         	* which binds some variables for this scope. We generate
                         	* symbol tables for locals at this point, and we use these
                         	* tables to evaluate the corresponding expression section
                         	* of this Let expression.
                         	*/

                                A_decList parseDecList = e->exptype.letexp.decls;
                           
                                while(parseDecList) {
                                    tr_exp = parseASTDec(venv, tenv, parseDecList->head);
                                    parseDecList = parseDecList->tail;
                                }

                                A_exp parseLetBody = e->exptype.letexp.body;
                                tr_exp = parseASTExp(venv, tenv, parseLetBody);

				break;

		default:
                                fprintf(stderr, "CASE OF DEFAULT\n");
				break;
			
	}

	return tr_exp;
}

struct expty parseASTVar(S_table venv, S_table tenv, A_var a_var)
{
	fprintf(stderr, "[%s] %s:\n", __FILE__,  __PRETTY_FUNCTION__);
	struct expty tr_exp;

	                /* TOO MANY COMMENTS, REMOVE THEM :- 
			 *
			 * In all cases, we check if the variable has been
			 * declared at this point; for an array-subscript, we
			 * check the type of expression in the subscript,
			 * while for record, we check if field is valid and
			 * exists, while matching the expanded field list. 
			 *
			 * These vars if existing, should have had their
			 * types identified and allocated at declaration.
			 *
			 */

			E_enventry var_entry;
			Ty_ty ty;

			/* note - 
			 * 1. need an interface for var_lookup, which conv to symbol,
			 * and performs the two tests for NULL and Not_Var
			 *
			 * 2. need a recursive fn to derive the varname for
			 * field or subscript vars?
			 *
			 * 3. need to define ActualType
			 * (recur for ty_name else return)
			 */

			switch(a_var->kind)
			{
			    case simple:
				    var_entry = TAB_lookup(venv, Symbol(a_var->vartype.simple.name));
				    if(var_entry == NULL)
				    {
		 			/* utilize EM_error */
		 			 fprintf(stderr, "Variable %s not declared at line %d\n", a_var->vartype.simple.name, *(a_var->pos->line));
		 			 exit(0);
				    }  

				    if(var_entry->type != E_varEntry)
				    {
		 			/* utilize EM_error */
					fprintf(stderr, "Illegal type namespace associated with variable %s at line %d\n", a_var->vartype.simple.name, *(a_var->pos->line));
					exit(0);
				    }

				    /* make sure we can pass ty of this struct instead of creating new type */
				    tr_exp = expTy(NULL, ActualType(tenv, var_entry->u.var.ty));

				break;

			    case field: 
			    case subscript:

				   tr_exp = expTy(NULL, tc_var(venv, tenv, a_var));

				break;

			    default:
				break;

			}

	return tr_exp;
}

struct expty parseASTDec(S_table venv, S_table tenv, A_dec d)
{
	fprintf(stderr, "[%s] %s:\n", __FILE__,  __PRETTY_FUNCTION__);
	struct expty tr_exp;

	switch(d->kind)
	{
		case typedec:
                        fprintf(stderr, "[%s]: CASE OF TYPE DECLS\n", __FILE__);

                        while(d->dectype.typedec.type) {
                            fprintf(stderr, "[%s]: TYPE DECL for symbol %s (NEEDS HANDLING)\n", __FILE__, d->dectype.typedec.type->head->sym);

                            // Discover if the type is pre-defined 

                            // Chicken n Egg: We need to define Standard Types first. This symbol should either be a standard type or be a symbol that ultimately boils down to a standard type (unless we support prototyping)..

                            if (d->dectype.typedec.type->head->ty->kind == 1) { /* type is a name */
                            fprintf(stderr, "[%s]: is of Type %d with symbol name (%s)\n", __FILE__, d->dectype.typedec.type->head->ty->kind, d->dectype.typedec.type->head->ty->which.nametype.sym);
                            }

                            // Go to the next type
                            d->dectype.typedec.type = d->dectype.typedec.type->tail;
                        }
			break;

		case vardec:
                        fprintf(stderr, "CASE OF VAR DECLS -- UNHANDLED\n");
			break;

		case fundec:
                        fprintf(stderr, "CASE OF FUNC DECLS -- UNHANDLED\n");
			break;

		default:
                        fprintf(stderr, "CASE OF UNKNOWN DECLS !!!\n");
			break;
	}

	return tr_exp;

}

/* end of file semant.c */
