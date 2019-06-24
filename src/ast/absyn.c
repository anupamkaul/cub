/* This file lists the definitions
 * of the constructors defined in
 * absyn.h
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "absyn.h"
#include "absyn_malloc.h"

#ifdef DBGPRN_absyn_c
extern FILE* yyout; 
#endif

/****************************
*  Global Variables 
*****************************/

/* Listing the global pointers for the absyn tree */

A_var        absyn_var; 
A_exp        absyn_exp;
A_exp        absyn_exp_other; 

A_dec        absyn_dec;
//A_fundecList absyn_fundecList;
A_fundec     absyn_fundec; 

A_field      absyn_field;
A_fieldList  absyn_fieldList=NULL;

A_ty         absyn_ty_rhs; 
A_namety     absyn_namety;

A_nametyList absyn_typedcl_List=NULL; 
A_decList    absyn_decList=NULL;

A_explist    absyn_explist;
A_efieldList absyn_efieldList=NULL;
A_efield     absyn_efield;

A_pos        absyn_pos;

/* AST root pointer */
A_exp        AST_root;

/* stack of pointers (A_exp) */
A_expstack   absyn_expstack=NULL;

/* stack of pointers (A_var) */
A_varstack   absyn_varstack=NULL;

/* stack of pointers (A_nametyList) */
A_tylistStack absyn_tylistStack; /* (TBD) added NULL without testing */

/* stack of pointers (type A_dec, for vardecs) */
A_vardecStack absyn_vardecStack; /* (TBD) added NULL without testing */

/* stack of pointers (A_fundecList, for PMR fn collection) */
A_fundeclistStack absyn_fundeclistStack;

/* stack of pointers (type A_explist) */
A_explistStack  absyn_explistStack=NULL; 

/* stack of pointers (type Int for mutrec (Fn) indicator) */
A_mutrecFnstate absyn_mutrecFnstate; /* Each element holds 0/1 */

/* stack of pointers(A_decList) for nested Let expressions */
A_declistStack absyn_declistStack=NULL; /* global stack */

/** Note: Parsing the AST in debug mode led to the realization
  * that we should be using queues instead of stacks in the
  * following places.
  */

/* queue of A_nameTy elements */
A_nametyList a_nametylist_qhead;
A_nametyList a_nametylist_qtail;


/*************************************
 Function declarations (constructors) 
**************************************/

A_var A_SimpleVar     (A_pos pos, S_symbol sym);
A_var A_FieldVar      (A_pos pos, A_var var, S_symbol sym);
A_var A_SubscriptVar  (A_pos pos, A_var var, A_exp exp);

A_exp A_VarExp        (A_pos pos, A_var var);

A_exp A_NilExp        (A_pos pos);
A_exp A_IntExp        (A_pos pos, string i);
A_exp A_StringExp     (A_pos pos, string s);

A_exp A_CallExp       (A_pos pos, S_symbol func_name, A_explist args);
A_exp A_OpExp         (A_pos pos, A_oper oper, A_exp left, A_exp right);

A_exp A_RecordExp     (A_pos pos, S_symbol typ, A_efieldList fields);
A_exp A_ArrayExp      (A_pos pos, S_symbol typ, A_exp size, A_exp initval);

A_exp A_SeqExp        (A_pos pos, A_explist seq);
A_exp A_AssignExp     (A_pos pos, A_var var, A_exp exp);

A_exp A_IfExp         (A_pos pos, A_exp test, A_exp ThenBody, A_exp ElseBody);
A_exp A_WhileExp      (A_pos pos, A_exp test, A_exp body);
A_exp A_BreakExp      (A_pos pos);
A_exp A_ForExp        (A_pos pos, A_exp lo, A_exp hi, A_exp body);
A_exp A_LetExp        (A_pos pos, A_decList decls, A_exp body);

A_decList A_DecList   (A_dec head, A_decList tail);

/* Recursive list constructors for functions */

A_dec        A_FunctionDec(A_pos pos, A_fundecList function);
A_fundecList A_FundecList (A_fundec head, A_fundecList tail);
A_fundec     A_Fundec     (A_pos pos, S_symbol sym, A_fieldList params, S_symbol result, A_exp body);

A_field      A_Field      (A_pos, S_symbol name, S_symbol typ);
A_fieldList  A_FieldList  (A_field head, A_fieldList tail);

/* Recursive list constructors for Types */

A_ty         A_nameTy     (A_pos pos, S_symbol sym);
A_ty         A_RecordTy   (A_pos pos, A_fieldList record);
A_ty         A_ArrayTy    (A_pos pos, S_symbol array);

A_namety     A_Namety     (S_symbol sym, A_ty ty);  /* type a = b, where b may be one of the 3 types */
A_nametyList A_NametyList (A_namety head, A_nametyList tail);

A_dec        A_TypeDec    (A_pos, A_nametyList type);

/* For Var declaration */
A_dec        A_VarDec     (A_pos, S_symbol var, S_symbol typ, A_exp init);

/* remaining "list" constructors */

A_explist    A_ExpList    (A_exp head, A_explist tail);

A_efieldList A_EfieldList (A_efield head, A_efieldList tail);
A_efield     A_Efield     (S_symbol sym, A_exp exp);

/* end of constructor declarations */

/* stack of pointers (A_exp) */

void         A_pushexp(A_exp exp);
A_exp        A_popexp();
A_exp        A_peepexp(int level);

/* stack analysis: debug print */
void         Dbprn_expstack();

/* stack of pointers (A_var) */

void         A_pushvar(A_var var);
A_var        A_popvar();
A_var        A_peepvar(int level);

/* stack of pointers (A_nametyList) */

void          A_pushtyList(A_nametyList nametyList);
A_nametyList  A_poptyList();
A_nametyList  A_peeptyList(int level);

/* stack of pointers (type A_dec, for vardecs) */

void          A_pushVardec(A_dec vardec);
A_dec         A_popVardec();
A_dec         A_peepVardec(int level);

/* stack of pointers (A_fundecList, for scoped PMR function lists) */

void          A_pushfnList(A_fundecList fundecList);
A_fundecList  A_popfnList();
A_fundecList  A_peepfnList(int level);

/* stack of pointers (type A_explist) */

void            A_pushexplist(A_explist explist);
A_explist       A_popexplist();
A_explist       A_peepexplist(int level);

/* stack of pointers (type Int for mutrec (Fn) indicator) */

void            A_pushMutRecState(int state);
int             A_popMutRecState();
int             A_peepMutRecState();

/* ****************************** 
*  Function Definitions   
* ******************************/

A_var A_SimpleVar(A_pos pos, S_symbol sym)
{
	A_var  x = Vmalloc(1);

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->vartype.simple.name=strdup(sym);
	x->kind=simple;

	return x;
}

A_var A_FieldVar(A_pos pos, A_var var, S_symbol sym)
{
	A_var x = Vmalloc(2);

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->vartype.field.recname=var;
	x->vartype.field.component=strdup(sym);
	x->kind=field;

	return x;
}

A_var A_SubscriptVar(A_pos pos, A_var var, A_exp exp)
{
	A_var x = Vmalloc(3);

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->vartype.subscript.aryname=var;
	x->vartype.subscript.component=exp;
	x->kind=subscript;

	return x;
}

A_exp A_VarExp(A_pos pos, A_var var)
{
	A_exp x = Emalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->exptype.varexp.var=var;
	x->kind=varexp;

	return x;
}

A_exp A_NilExp(A_pos pos)
{
	A_exp x = Emalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->kind=nilexp;

	return x;
}

A_exp A_IntExp(A_pos pos, string i)
{
	A_exp x = Emalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->exptype.intexp.i= atoi(strdup(i));
	x->kind=intexp;

	return x;
}

A_exp A_StringExp(A_pos pos, string s)
{
	A_exp x = Emalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->exptype.strexp.s=strdup(s);
	x->kind=strexp;

	return x;
}

A_exp A_CallExp(A_pos pos, S_symbol func_name, A_explist args)
{
	A_exp x = Emalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->exptype.callexp.func_name=strdup(func_name);
	x->exptype.callexp.args=args;
	x->kind=callexp;

	return x;
}


A_exp A_OpExp(A_pos pos, A_oper oper, A_exp left, A_exp right)
{
	A_exp x = Emalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->exptype.bopexp.oper=oper;
	x->exptype.bopexp.left=left;
	x->exptype.bopexp.right=right;
	x->kind=bopexp;

	return x;
}

A_exp A_RecordExp(A_pos pos, S_symbol typ, A_efieldList fields)
{
	A_exp x = Emalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->exptype.recexp.typ=strdup(typ);
	x->exptype.recexp.fields=fields;
	x->kind=recexp;

	return x;
}

A_exp A_ArrayExp(A_pos pos, S_symbol typ, A_exp size, A_exp initval)
{
	A_exp x = Emalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->exptype.aryexp.typ=strdup(typ);
	x->exptype.aryexp.size=size;
	x->exptype.aryexp.initval=initval;
	x->kind=aryexp;

	return x;
}

A_exp A_SeqExp(A_pos pos, A_explist seq)
{
	A_exp x = Emalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->exptype.seqexp.seq=seq;
	x->kind=seqexp;

	return x;
}

A_exp A_AssignExp(A_pos pos, A_var var, A_exp exp)
{
	A_exp x = Emalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->exptype.asnexp.var=var;
	x->exptype.asnexp.exp=exp;
	x->kind=asnexp;

	return x;
}

A_exp A_IfExp(A_pos pos, A_exp test, A_exp ThenBody, A_exp ElseBody)
{
	A_exp x = Emalloc();
	
	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->exptype.ifexp.test=test;
	x->exptype.ifexp.ThenBody=ThenBody;
	x->exptype.ifexp.ElseBody=ElseBody;
	x->kind=ifexp;

	return x;
}

A_exp A_WhileExp(A_pos pos, A_exp test, A_exp body)
{
	A_exp x = Emalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->exptype.whlexp.test=test;
	x->exptype.whlexp.body=body;
	x->kind=whlexp;

	return x;
}

A_exp A_BreakExp(A_pos pos)
{
	A_exp x = Emalloc();
	
	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));
	x->kind=brkexp;

	return x;
}

A_exp A_ForExp(A_pos pos, A_exp lo, A_exp hi, A_exp body)
{
	A_exp x = Emalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->exptype.forexp.lo=lo;
	x->exptype.forexp.hi=hi;
	x->exptype.forexp.body=body;
	x->kind=forexp;

	return x;
}

A_exp A_LetExp(A_pos pos, A_decList decls, A_exp body)
{
	A_exp x = Emalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

        //DEBUG
	//printf("[AST GEN]: LET STATEMENT: line=%d, col=%d\n",*(x->pos->line),*(x->pos->col)); 

	x->exptype.letexp.decls=decls;
	x->exptype.letexp.body=body;
	x->kind=letexp;

	return x;
}

A_decList A_DecList(A_dec head, A_decList tail)
{
	A_decList x = decListmalloc();
	x->head=head;
        x->tail=tail;
        return x;
}

/* Recursive list constructor-definitions for functions */
A_dec A_FunctionDec(A_pos pos, A_fundecList function)
{
	A_dec x = decmalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->dectype.fundec.function=function;
	x->kind=fundec;

	return x;
}

A_fundecList A_FundecList(A_fundec head, A_fundecList tail)
{
	A_fundecList x = FundecListmalloc();
	x->head=head;
	x->tail=tail;
	return x;
}

A_fundec A_Fundec(A_pos pos, S_symbol sym, A_fieldList params, S_symbol result, A_exp body)
{
	A_fundec x = fundecmalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->fname=strdup(sym);
	x->params=params;
	x->result_type=result;
	x->body=body;

	return x;
}

A_field A_Field(A_pos pos, S_symbol name, S_symbol typ)
{
	A_field x = fieldmalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->name=strdup(name);
	x->typ=strdup(typ);
	return x;
}

A_fieldList A_FieldList(A_field head, A_fieldList tail)
{
	A_fieldList x = fieldListmalloc();
	x->head=head;
	x->tail=tail;
	return x;
}

/* Recursive list constructor-definitions for Types */
A_ty A_nameTy (A_pos pos, S_symbol sym)
{
	A_ty x = tymalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->which.nametype.sym=strdup(sym);
	x->kind=name;
	return x;
}

A_ty A_RecordTy(A_pos pos, A_fieldList record)
{
	A_ty x = tymalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->which.rectype.record=record;
	x->kind=rec;
	return x;
}

A_ty A_ArrayTy(A_pos pos, S_symbol array)
{
	A_ty x = tymalloc();

	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->which.arytype.array=strdup(array);
	x->kind=ary;
	return x;
}

A_namety A_Namety(S_symbol sym, A_ty ty)  /* type a = b, where b may be one of the 3 types */
{
	A_namety x = nametymalloc();
	x->sym=strdup(sym);
	x->ty=ty;
	return x;
}

A_nametyList A_NametyList(A_namety head, A_nametyList tail)
{
	A_nametyList x = nametyListmalloc();
	x->head=head;
	x->tail=NULL;

        assert(head!=NULL);

        if (NULL==tail) {
            a_nametylist_qhead = x;
            a_nametylist_qtail = x;
        } else {
            a_nametylist_qtail->tail = x;
            a_nametylist_qtail = x;

        }
	return a_nametylist_qhead;
}

A_dec A_TypeDec(A_pos pos, A_nametyList type)
{
	A_dec x = decmalloc();
	
	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->dectype.typedec.type=type;
	x->kind=typedec;
	return x;
}

/* For Var declaration */
A_dec A_VarDec(A_pos pos, S_symbol var, S_symbol typ, A_exp init)
{
	A_dec x = decmalloc();
	
	x->pos = aposmalloc();
	x->pos->line = A_intdup(*(pos->line));
	x->pos->col  = A_intdup(*(pos->col));

	x->dectype.vardec.var=strdup(var);
	x->dectype.vardec.typ=strdup(typ);
	x->dectype.vardec.init=init;
        return x;
}

/* remaining "list" constructor definitions */
A_explist A_ExpList(A_exp head, A_explist tail)
{
	A_explist x = explistmalloc();
	x->head=head;
	x->tail=tail;
	return x;
}

A_efieldList A_EfieldList(A_efield head, A_efieldList tail)
{
	A_efieldList x = efieldListmalloc();
	x->head=head;
	x->tail=tail;
	return x;
}

A_efield A_Efield(S_symbol sym, A_exp exp)
{
	A_efield x = efieldmalloc();
	x->typ=strdup(sym);
	x->exp=exp;
	return x;
}

/* end of constructor definitions */

/* Expr-stack push-pop implementations,
 * on a global stack (absyn_stackexp ptr)
 *
 * Note that this stack only stores pointers,
 * so mem shd be ok.
 */

/* Functions for stack of pointers (A_exp) 
 * acting on a global absyn stack.
 */

void A_pushexp(A_exp exp)
{
   A_expstack x = estackmalloc();

   x->exp=exp;
   x->next=absyn_expstack;
   absyn_expstack=x;
   return;
}

A_exp A_popexp()
{
  if(absyn_expstack == NULL) return NULL;

  A_exp exp = absyn_expstack->exp;
  absyn_expstack = absyn_expstack->next;
  return exp;
}

A_exp A_peepexp(int level)
{
  if(absyn_expstack == NULL) return NULL;
  A_expstack x = absyn_expstack;

  while(level>0)
  {
	  x=x->next;
	  level--;
  }
  return x->exp;
}

/* functions for stack of pointers (A_var) 
 * acting on a global absyn stack.
 */

void A_pushvar(A_var var)
{
   A_varstack x = vstackmalloc();

   x->var=var;
   x->next=absyn_varstack;
   absyn_varstack=x;
   return;
}

A_var A_popvar()
{
  if(absyn_varstack == NULL) return NULL;

  A_var var = absyn_varstack->var;
  absyn_varstack = absyn_varstack->next;
  return var;
}

A_var A_peepvar(int level)
{
  if(absyn_varstack == NULL) return NULL;
  A_varstack x = absyn_varstack;

  while(level>0)
  {
	  x=x->next;
	  level--;
  }
  return x->var;
}

/* functions for stack of pointers (A_nametyList) 
 * acting on a global absyn stack
 */

void A_pushtyList(A_nametyList nametyList)
{
   A_tylistStack x = tylist_Stackmalloc();

   x->nametyList=nametyList;
   x->next=absyn_tylistStack;
   absyn_tylistStack=x;
   return;
}

A_nametyList A_poptyList()
{
  if(absyn_tylistStack == NULL) return NULL;

  A_nametyList nametyList = absyn_tylistStack->nametyList;
  absyn_tylistStack = absyn_tylistStack->next;
  return nametyList;
}

A_nametyList A_peeptyList(int level)
{
  if(absyn_tylistStack == NULL) return NULL;
  A_tylistStack x = absyn_tylistStack;

  while(level>0)
  {
	  x=x->next;
	  level--;
  }
  return x->nametyList;
}

/* functions for stack of pointers (A_dec, case vardecs) 
 * acting on a global absyn stack
 */

void A_pushVardec(A_dec vardec)
{
   A_vardecStack x = vardec_Stackmalloc();

   x->vardec=vardec;
   x->next=absyn_vardecStack;
   absyn_vardecStack=x;
   return;
}

A_dec A_popVardec()
{
  if(absyn_vardecStack == NULL) return NULL;

  A_dec vardec = absyn_vardecStack->vardec;
  absyn_vardecStack = absyn_vardecStack->next;
  return vardec;
}

A_dec A_peepVardec(int level)
{
  if(absyn_vardecStack == NULL) return NULL;
  A_vardecStack x = absyn_vardecStack;

  while(level>0)
  {
	  x=x->next;
	  level--;
  }
  return x->vardec;
}

/* functions for stack of pointers (A_fundecList, case PMR fn collection) 
 * acting on a global absyn stack
 */

void A_pushfnList(A_fundecList fundecList)
{
   A_fundeclistStack x = fundeclist_Stackmalloc();

   x->fundecList=fundecList;
   x->next=absyn_fundeclistStack;
   absyn_fundeclistStack=x;
   return;
}

A_fundecList A_popfnList()
{
  if(absyn_fundeclistStack == NULL) return NULL;

  A_fundecList fundecList = absyn_fundeclistStack->fundecList;
  absyn_fundeclistStack = absyn_fundeclistStack->next;
  return fundecList;
}

A_fundecList A_peepfnList(int level)
{
  if(absyn_fundeclistStack == NULL) return NULL;
  A_fundeclistStack x = absyn_fundeclistStack;

  while(level>0)
  {
	  x=x->next;
	  level--;
  }
  return x->fundecList;
}

/* Functions for stack of pointers (A_explist)
 * acting on a global absyn stack
 */


void            A_pushexplist(A_explist explist)
{
  A_explistStack x = A_explistStack_malloc();
  x->explist = explist;
  x->next    = absyn_explistStack;
  absyn_explistStack = x;
}


A_explist       A_popexplist()
{
  if(absyn_explistStack == NULL) return NULL;

  A_explist x        = absyn_explistStack->explist;
  absyn_explistStack = absyn_explistStack->next;
  return x;
}
A_explist       A_peepexplist(int level)
{
  if(absyn_explistStack == NULL) return NULL;
  A_explistStack x = absyn_explistStack;

  while(level>0)
  {
	  x=x->next;
	  level--;
  }
  return x->explist;
}

/* Function for stack of MutRecIndicators(Fn),
 * acting on a global stack */

void            A_pushMutRecState(int state)
{
  A_mutrecFnstate x = A_mutrecFnstate_malloc();

  /* Note, must create a new int-var here (A_intdup?) */
  x->state = state;
  x->next    = absyn_mutrecFnstate;
  absyn_mutrecFnstate = x;
}

int             A_popMutRecState()
{
  if(absyn_mutrecFnstate == NULL) return -1;

  int x               = absyn_mutrecFnstate->state;
  absyn_mutrecFnstate = absyn_mutrecFnstate->next;
  return x;
}

int             A_peepMutRecState(int level)
{
  if(absyn_mutrecFnstate == NULL) return -1;
  A_mutrecFnstate x = absyn_mutrecFnstate;

  while(level>0)
  {
	  x=x->next;
	  level--;
  }
  return x->state;
}

/* functions for stack of pointers (A_decList), acting
 * on a global stack
 */

void            A_pushLetdecList(A_decList decList)
{
  A_declistStack x = A_declistStack_malloc();
  x->decList = decList;
  x->next    = absyn_declistStack;
  absyn_declistStack = x;
}

A_decList       A_popLetdecList()
{
  if(absyn_declistStack == NULL) return NULL;

  A_decList x        = absyn_declistStack->decList;
  absyn_declistStack = absyn_declistStack->next;
  return x;

}

A_decList       A_peepLetdecList(int level)
{
  if(absyn_declistStack == NULL) return NULL;
  A_declistStack x = absyn_declistStack;

  while(level>0)
  {
	  x=x->next;
	  level--;
  }
  return x->decList;

}

#ifdef ABSYN_TEST
main()
{

}
#endif 

