/* 
 * Defining the data types
 * used in the generation of the 
 * abstract syntax tree
 *
 */
#ifndef DATAT_H
#define DATAT_H

typedef char* STR;
typedef struct a_pos_* A_pos;
typedef struct a_var_* A_var;
typedef struct a_exp_* A_exp;

typedef struct a_efield_* A_efield;

typedef struct a_explist_* A_explist;
typedef struct a_efieldList_* A_efieldList;

typedef struct a_decList_* A_decList;
typedef struct a_dec_* A_dec;

typedef struct a_nametylist_* A_nametyList;
typedef struct a_namety_* A_namety;
typedef struct a_ty_* A_ty;

typedef struct a_fieldList_* A_fieldList;
typedef struct a_field_* A_field;

typedef struct a_fundecList_* A_fundecList;
typedef struct a_fundec_* A_fundec;

typedef enum { 
	A_plusOp=0, A_minusOp, A_timesOp, 
	A_divideOp, A_eqOp, A_neqOp, 
	A_ltOp, A_gtOp, A_geOp, A_leOp, 
	A_andOp, A_orOp
} A_oper;

/* implementation: expr-ptr stack during absyn creation */
typedef struct a_expstack_* A_expstack;
typedef struct a_varstack_* A_varstack;

/* implementation: typlist (mcr) stack for scope issues */
typedef struct a_tylistStack_* A_tylistStack;

/* implementation: A_dec (vardec) stack */
typedef struct a_vardecStack_* A_vardecStack; 

/* implementation: A_FundecList stack */
typedef struct a_fundeclistStack_* A_fundeclistStack;

/* implementation: A_explist stack for scope issues */
typedef struct a_explistStack_* A_explistStack;

/* implementation: A_mutrecfn stack for scope issues */
typedef struct a_mutrecFnstate_* A_mutrecFnstate;

/* implementation: A_decList stack for scoped Let expressions */
typedef struct a_declistStack_* A_declistStack;

/* A_pos */
struct a_pos_ {
int* line;
int* col;
};

/* A_var */
struct a_var_ {
	A_pos pos;

	union var_type_{

        	struct simple_ {
        	STR    name;
		}simple;

		struct field_ {
        	A_var recname;
 	        STR   component;
		}field;

		struct subscript_ {
        	A_var aryname;
		A_exp component;
		}subscript;

	} vartype;

	enum {
	simple=1,
	field,
	subscript
	} kind;

};

/* A_exp */
struct a_exp_ {
	A_pos pos;

	union exp_type_ {
		struct varexp_ {
		A_var var;
		}varexp;	

		struct intexp_ {
		int i;
		}intexp;

		struct strexp_ {
		STR s;
		}strexp;

        	struct callexp_ {
		STR func_name;
		A_explist args;
		}callexp;
     
        	struct bopexp_ {
		A_oper oper;
		A_exp left;
		A_exp right;
		}bopexp;
     
		/* record creation */
        	struct recexp_{
		STR typ;
		A_efieldList fields;
		}recexp;
     
		/* array creation */
 	        struct aryexp_{
		STR typ;
		A_exp size;
		A_exp initval;
		}aryexp;
     
 	        struct seqexp_{
		A_explist seq;
		}seqexp;
     
        	struct asnexp_{
		A_var var;
		A_exp exp;
		}asnexp;
     
        	struct ifexp_{
		A_exp test;
		A_exp ThenBody;
		A_exp ElseBody;
		}ifexp;
     
 	        struct whlexp_{
		A_exp test;
		A_exp body;
		}whlexp;
     
        	struct forexp_{
		A_exp lo;
		A_exp hi;
		A_exp body;
		}forexp;
     
        	struct letexp_{
		A_decList decls;
		A_exp body;
		}letexp;

		}exptype ; 

		enum {
        	varexp=1,
		nilexp,
        	intexp,
		strexp,
        	callexp,
        	bopexp,
        	recexp,
		aryexp,
        	seqexp,
        	asnexp,
		ifexp,
		whlexp,
		brkexp,
		forexp,
		letexp
		} kind;
}; 

struct a_explist_ {
A_exp head;
A_explist tail;
};

struct a_efieldList_ {
A_efield head;
A_efieldList tail;
};

struct a_efield_ {
A_exp exp;
STR   typ;
};

struct a_decList_ {
A_dec head;
A_decList tail;
};

/* A_dec */
struct a_dec_ {
	A_pos pos;
	union dec_type {

		struct typedec_{
		A_nametyList type;
		}typedec;

		struct vardec_{
		STR var;
		STR typ;
		A_exp init;
		}vardec;

		struct fundec_{
		A_fundecList function;
		}fundec;

	}dectype;

	enum {
        typedec=1,
	vardec,
	fundec
	}kind;

};

struct a_nametylist_ {
A_namety head;
A_nametyList tail;
};

/* nameTy: simple type a = b,
 * and b is strictly 
 * classified also as a type
 */

struct a_namety_ {
STR sym;
A_ty ty;
};

/* A_ty */
struct a_ty_ {
	A_pos pos;

	union which_{

		struct name_type_{
		STR sym;
		}nametype;

		struct rec_type_{
		A_fieldList record;
		}rectype;

		struct ary_type_{
		STR array;
		}arytype;

	}which;

	enum {
	name=1,
	rec,
	ary
        }kind;

};

struct a_fundecList_ {
A_fundec head;
A_fundecList tail;
};

struct a_fundec_ {
A_pos pos;
STR fname;
A_fieldList params;
STR result_type;
A_exp body;
};

struct a_fieldList_ {
A_field head;
A_fieldList tail;
};

struct a_field_ {
A_pos pos;
STR name;
STR typ;
};

/* 
 * A stack of (pointers to) expressions. This is done to account
 * for Yacc's way of discovering operands around non-unary operators
 * in expressions.
 *
 */

struct a_expstack_ {
A_exp exp;
A_expstack next;
};

struct a_varstack_ {
A_var var;
A_varstack next;
};

/* 
 * A stack of (pointers to) typelists. This is done to account
 * for discovery of declarations in yacc, which is based on 
 * the nesting of the LET scope. (inner-most to outer-most)
 *
 */

struct a_tylistStack_ {
A_nametyList  nametyList;
A_tylistStack next;
};

/* A stack of (pointers) to a_dec. (where a_dec => vardecs)
 *
 * This is done just because yacc will discover the vardecs 
 * only from the let-scope (inner-most to outer-most), and we must 
 * preserve the relevant vardecs for that let, by that time.
 *
 * (This is implementation dependent)
 */

struct a_vardecStack_ {
A_dec         vardec;
A_vardecStack next;
};

/* A stack of pointers to A_fundecList.
 *
 * As we keep collecting the relevant possible
 * mutually recursive function declaration list
 * within a let scope, we have to account for the
 * possibility of there being another let scope within
 * a function .. thus the function-list must be
 * preserved per scope; hence this stack.
 *
 */

struct a_fundeclistStack_  {
A_fundecList      fundecList;
A_fundeclistStack next;
};
 
/* A stack of pointers of type 'A_explist'. This is done in anticipation
 * that there will be scope issues when dealing with - nested function declarations
 * that have variable declarations whose expressions contain function-calls, and 
 * the nesting of function calls, inside expression sequences.
*/

struct a_explistStack_ {
A_explist      explist;
A_explistStack next;
};

/* The following stack is used to store the indicator-variable
 * that declares two functions to be possibly mutually recursive,
 * 
 * The stack in needed as a new state must commence with every
 * nested scope (Let) in the program, while the old state must be 
 * recovered when an inner Let Scope has been dealt with.
 *
 */

struct a_mutrecFnstate_ {
int             state;
A_mutrecFnstate next;
};

/* A stack of pointers to 'A_decList'. Each element of this stack
 * points to the declaration list (types, functions, vars) of the
 * current let expression. The reason to create such a stack is that
 * let expressions could be nested; and so each let expression must
 * be guaranteed to recieve the correct declaration list.
 *
 * An important assumption that I make is that Let expressions will
 * be discovered and evaluated, from the innermost scope first,
 * courtesy, the yacc mechanism.
 */

struct a_declistStack_ {
A_decList      decList;
A_declistStack next;
};

/* end of datatypes.h */
#endif
