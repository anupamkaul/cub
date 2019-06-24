/* This file contains utility functions
 * for doing semantic analysis on the
 * tiger module.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semant.h"
#include "semant_utils.h"

/* *****************************************************************************
 *
 * Function name:	tc_var
 * Purpose:		type checks field and subscript vars during their usage.
 * First created:	03 Feb 2006
 *
 * *****************************************************************************/

Ty_ty tc_var(S_table venv, S_table tenv, A_var a_var)	
{
	/* collect all components of the variable (field or subscript) 
	 * parse in reverse order, starting from the base symbol
	 *
	 * We will use a stack to gather and process (if required)
	 * all the components of the field.
	 */

        /* note - the gathering of field components in reverse
	 * order could be a function.
	 */

	E_enventry var_entry;
	Ty_ty ty;

	typedef struct field_elements_ *r_elem;
	typedef struct field_elements_
	{
		STR     elm;
		int     ty_expect;
		r_elem  next; 
	} field_elements;
	A_var run_var = a_var;

	/* If we encounter a field variable, like a.b.c, we need
	 * to get the type of 'a' as ty_Rec, then make sure that
	 * the 'type of a' has fields b and c, and allocate the
	 * 'type of c' (actual) to our field variable
	 *
	 * During rec-declaration, check for duplicate symbol names(a & a)
	 * Also check that cannot have duplicate member names(a.b & a.b), etc.
	 */

	r_elem header;
	r_elem elm;

	/* push the first component */
	elm = (r_elem)malloc(sizeof(struct field_elements_));
	strcpy(run_var->vartype.field.component, elm->elm);
	elm->next = NULL;
	header = elm;

	run_var = run_var->vartype.field.recname;

	while(run_var->kind != simple)
	{
	    if(run_var->kind == field)
	    {
	        /* push the next component */
	    	elm = (r_elem)malloc(sizeof(struct field_elements_));
	    	strcpy(run_var->vartype.field.component, elm->elm);
		elm->ty_expect = ty_Record;
	    	elm->next = header;
		header = elm;

		run_var = run_var->vartype.field.recname;

	    }
	    else if(run_var->kind == subscript)
	    {

		/* array of records, as an element of a record
		 * should be possible. Check that its type is
		 * a record, if intermediate element. If its a
		 * last element, its type should be a predefined one.
		 *
		 * for its symbol, need to go one previous;
		 * if its simple var, exit, if its
		 * rec-var, take the component, if its an array,
		 * continue, with some type-checks on the expr.
		 *
		 * a.b.c[x] is ok
		 * a.b[x].d is ok
		 * a.b[x].c[x].d is ok
		 * a.b[x][x].d is ok
		 * a.b[x][x][x].d is ok?
		 */

		struct expty aryexp;

		while(run_var->kind == subscript)
		{

			/* 1. type check the expression in the paranthesis */
			aryexp = transExp(venv, tenv, run_var->vartype.subscript.component);
			if (aryexp.ty != ty_Int)
			{
		  		fprintf(stderr, "Array index type is not integer\n");
			}

			/* 2. check, if possible, that the index is within bounds */

			/* 3. Go to next symbol to the left */
			run_var = run_var->vartype.subscript.aryname;

			/* 4. Increase the stack (dummy ref) to ary-call. */
			
	    		elm = (r_elem)malloc(sizeof(struct field_elements_));
	    		strcpy("__DUMMY_ARRAY_REF__", elm->elm);
			elm->ty_expect = ty_Array;
	    		elm->next = header;
			header = elm;
		}

             	// check type(r->name/r->component) = record (to confirm an array of records) 
		// -can we check here, or is to be combined with the final check outside?
	    }
	    else
	    {
		fprintf(stderr, "Illegal type handling at line %d\n", *(a_var->pos->line));
		break;

	    }
	}

	/* make sure there is no conflict in the defn
	 * of 'simple', in the context of a_var & without */

	/* Handle case of simple variable */
	/* push the last component */

 	elm = (r_elem)malloc(sizeof(struct field_elements_));
 	strcpy(run_var->vartype.simple.name, elm->elm);
	elm->ty_expect = ty_String; /* check this */
   	elm->next = header;
	header = elm;

	/* Now we analyse what we have gathered: */

	/* Parse the stack to determine the following 
	 * 1. If the left most element was indeed a record type
	 * 2. If call semantics match those of the associated type, in the interation.
	 * 3. If the number of iterations exceed those of the predefined record.
	 * 4. Wherever it stops, check the type of last, and assign type.
	 */

	 /* [03.02.2k6] 
	  *
	  * Get reference to type of first element (from tenv), then parse 2 components:
	  * this runtime stack & the type entity for type-checking.
	  */

	 /* pop first element */
	 elm = header;
	 elm = elm->next;

	 /* 1. lookup in symbol table venv and see it exists.  */
	 /* (the following code is definitely a function) */

	    var_entry = TAB_lookup(venv, Symbol(run_var->vartype.simple.name));
	    if(var_entry == NULL)
	    {
		/* utilize EM_error */
	 	fprintf(stderr, "Record %s not declared at line %d\n", run_var->vartype.simple.name, *(run_var->pos->line));
	 	exit(0);
	    }  

	    if(var_entry->type != E_varEntry)
	    {
		/* utilize EM_error */
		fprintf(stderr, "Illegal type namespace associated with record %s at line %d\n", a_var->vartype.simple.name, *(run_var->pos->line));
		exit(0);
	    }

	 /* 2. lookup in symbol table tenv, check if record, and follow thread */
         /* use ActualType, and resolve names upto Ty_Rec, no further */

	   ty = ActualType(tenv, TAB_lookup(tenv, Symbol(elm->elm)));

	   if(ty->type != ty_Record)
	   {
           	/* Utilize EM_error */
	   	fprintf(stderr, "variable %s is not of type record, at line %d\n", elm->elm, *(run_var->pos->line));
	   	exit(0);
	   }

           /* loop now, to find if: 
	    * 'structure has a member of incorrect type,
	    * 'structure has a member of undeclared name,
	    * 'structure contains more elements than declared'
	    *  duplicate elements (this shd be at declaration)
	    */

	  /* [03.02.2k6] - think about making it a recursive function */

	   while(elm != NULL)
	   {
	 	  /* 1. parse Ty_FieldList to find matching symbol */

		   /* Note, we don't support #defines on struct elements, so
		    * all fields must now directly be type symbols
		    */

		   {
                   	Ty_fieldList ty_fldList;

			/* an assert, in unix, how is it done? */
			if(ty->type != ty_Record)
			{
				fprintf(stderr, "assert Ty=Rec failed for %s, type %d\n", elm->elm, ty->type);
				exit(0);
			}

                       	ty_fldList = ty->u.record;
		   	while(ty_fldList != NULL)
		   	{
		   		if(ty_fldList->head->sym == Symbol(elm->elm))
				break;

				ty_fldList = ty_fldList->tail;
		   	}

		   	if(ty_fldList == NULL)
		   	{
				/* Note, if we convert to symbols in elm itself, we will lose
				 * messages which reveal the structure/member name */

                       		/* Utilize EM_error */
				fprintf(stderr, "structure has no member named '%s' at line %d", elm->elm, *(run_var->pos->line));
				exit(0);
		   	}

                        /* 2. Check type, stored with expected type in our stack */
			/* This is a function, called ActualType */
			if(ty_fldList->head->ty->type == ty_Name)
			{
			  /* resolve upto Record, no further */
			}

			if(ty_fldList->head->ty->type != elm->ty_expect)
			{
                              	/* Utilize EM_error */
				fprintf(stderr, "structure has no member of type %d at line %d", elm->ty_expect, *(run_var->pos->line));
				exit(0);

			}

			/* Move to the next type, and get the next symbol from stack */
			ty = ActualType(tenv, ty_fldList->head->ty);
			elm = elm->next;

			/* 3. check for type element overflow */
			if(ty->type == ty_Int || ty->type == ty_String)
			{
			    if(elm != NULL)
			    {
				  if(elm->next != NULL)
				  {
				    fprintf(stderr, "struct contains too many members\n");
				    exit(0);
				  }
			    }

			    /* should resolve and exit from here 
			     * in any case
			     */
			}
		   }
	   }

	   /* Assign the type of the last element as the type of this 
	    * field-var invokation.
	    */

	
} /* end of tc_var */

/* Comments for Array var TC:
 *
 *
				* for all array checks, always check that the index is within bounds *

				* Unfortunately in our yacc script, a.b.c[x] is treated as an array-var
				* and a.b.c[x].d is treated as a record-var .. confirm, is it ok semantically? YES
				*
				* We probably need the same loop, except that the first element to be pushed
				* is an array, so we could generalize this.
				*
*
*/


