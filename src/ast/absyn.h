/* 
 * Absyn.h (constructor interface)
 *
 * Listing the constructors for generating the
 * abstract syntax tree for tiger
 *
 */
#ifndef ABSYN_H
#define ABSYN_H 
#include "absyn_def.h"

typedef char* S_symbol;
typedef char* string;

extern A_var A_SimpleVar     (A_pos pos, S_symbol sym);
extern A_var A_FieldVar      (A_pos pos, A_var var, S_symbol sym);
extern A_var A_SubscriptVar  (A_pos pos, A_var var, A_exp exp);

extern A_exp A_VarExp        (A_pos pos, A_var var);

extern A_exp A_NilExp        (A_pos pos);
extern A_exp A_IntExp        (A_pos pos, string i);
extern A_exp A_StringExp     (A_pos pos, string s);

extern A_exp A_CallExp       (A_pos pos, S_symbol func_name, A_explist args);
extern A_exp A_OpExp         (A_pos pos, A_oper oper, A_exp left, A_exp right);

extern A_exp A_RecordExp     (A_pos pos, S_symbol typ, A_efieldList fields);
extern A_exp A_ArrayExp      (A_pos pos, S_symbol typ, A_exp size, A_exp initval);

extern A_exp A_SeqExp        (A_pos pos, A_explist seq);
extern A_exp A_AssignExp     (A_pos pos, A_var var, A_exp exp);

extern A_exp A_IfExp         (A_pos pos, A_exp test, A_exp ThenBody, A_exp ElseBody);
extern A_exp A_WhileExp      (A_pos pos, A_exp test, A_exp body);
extern A_exp A_BreakExp      (A_pos pos);
extern A_exp A_ForExp        (A_pos pos, A_exp lo, A_exp hi, A_exp body);
extern A_exp A_LetExp        (A_pos pos, A_decList decls, A_exp body);

extern A_decList A_DecList   (A_dec head, A_decList tail);

/* Recursive list constructors for functions */

extern A_dec        A_FunctionDec(A_pos pos, A_fundecList function);
extern A_fundecList A_FundecList (A_fundec head, A_fundecList tail);
extern A_fundec     A_Fundec     (A_pos pos, S_symbol sym, A_fieldList params, S_symbol result, A_exp body);

extern A_field      A_Field      (A_pos, S_symbol name, S_symbol typ);
extern A_fieldList  A_FieldList  (A_field head, A_fieldList tail);

/* Recursive list constructors for Types */

extern A_ty         A_nameTy     (A_pos pos, S_symbol sym);
extern A_ty         A_RecordTy   (A_pos pos, A_fieldList record);
extern A_ty         A_ArrayTy    (A_pos pos, S_symbol array);

extern A_namety     A_Namety     (S_symbol sym, A_ty ty);  /* type a = b, where b may be one of the 3 types */
extern A_nametyList A_NametyList (A_namety head, A_nametyList tail);

extern A_dec        A_TypeDec    (A_pos, A_nametyList type);

/* For Var declaration */
extern A_dec        A_VarDec     (A_pos, S_symbol var, S_symbol typ, A_exp init);

/* remaining "list" constructors */

extern A_explist    A_ExpList    (A_exp head, A_explist tail);

extern A_efieldList A_EfieldList (A_efield head, A_efieldList tail);
extern A_efield     A_Efield     (S_symbol sym, A_exp exp);

/* end of constructor declarations */

/* Listing the global pointers for the absyn tree */

extern A_var        absyn_var; 
extern A_exp        absyn_exp;
extern A_exp        absyn_exp_other; 

extern A_dec        absyn_dec;
extern A_fundecList absyn_fundecList;
extern A_fundec     absyn_fundec; 

extern A_field      absyn_field;
extern A_fieldList  absyn_fieldList;

extern A_ty         absyn_ty_rhs; 
extern A_namety     absyn_namety;

extern A_nametyList absyn_typedcl_List; 
extern A_decList    absyn_decList;

extern A_explist    absyn_explist;
extern A_efieldList absyn_efieldList;
extern A_efield     absyn_efield;

extern A_fundec     absyn_fundec;

extern A_pos        absyn_pos;

/* AST root pointer */
extern A_exp        AST_root;

/* stack of pointers (A_exp) */
extern A_expstack   absyn_expstack;

extern void         A_pushexp(A_exp exp);
extern A_exp        A_popexp();
extern A_exp        A_peepexp(int level);

/* stack analysis: debug print */
extern void         Dbprn_expstack();

/* stack of pointers (A_var) */
extern A_varstack   absyn_varstack;

extern void         A_pushvar(A_var var);
extern A_var        A_popvar();
extern A_var        A_peepvar(int level);

/* stack of pointers (A_nametyList) */
extern A_tylistStack absyn_tylistStack; 

extern void          A_pushtyList(A_nametyList nametyList);
extern A_nametyList  A_poptyList();
extern A_nametyList  A_peeptyList(int level);

/* stack of pointers (type A_dec, for vardecs) */
extern A_vardecStack absyn_vardecStack; 

extern void          A_pushVardec(A_dec vardec);
extern A_dec         A_popVardec();
extern A_dec         A_peepVardec(int level);

/* stack of pointers (A_fundecList, for scoped PMR function lists) */
extern A_fundeclistStack absyn_fundeclistStack;

void          A_pushfnList(A_fundecList fundecList);
A_fundecList  A_popfnList();
A_fundecList  A_peepfnList(int level);

/* stack of pointers (type A_explist) */
extern A_explistStack  absyn_explistStack; 

extern void            A_pushexplist(A_explist explist);
extern A_explist       A_popexplist();
extern A_explist       A_peepexplist(int level);

/* stack of pointers (type Int for mutrec (Fn) indicator) */
extern A_mutrecFnstate absyn_mutrecFnstate;

extern void            A_pushMutRecState(int state);
extern int             A_popMutRecState();
extern int             A_peepMutRecState();

/* stack of pointers(A_decList, for scoped Let expressions) */
extern A_declistStack absyn_declistStack; /* global stack */

extern void            A_pushLetdecList(A_decList decList);
extern A_decList       A_popLetdecList();
extern A_decList       A_peepLetdecList(int level);

#endif





