/* Header for some malloc utilities
 * for the compiler
 */

#ifndef ABSYN_MALLOC_H
#define ABSYN_MALLOC_H

extern A_var Vmalloc(int c);
extern A_exp Emalloc();
extern A_decList decListmalloc();
extern A_dec decmalloc();
extern A_fundecList FundecListmalloc();
extern A_fundec fundecmalloc();
extern A_field fieldmalloc();
extern A_fieldList fieldListmalloc();
extern A_ty tymalloc();
extern A_namety nametymalloc();
extern A_nametyList nametyListmalloc();
extern A_explist explistmalloc();
extern A_efieldList efieldListmalloc();
extern A_efield efieldmalloc();
extern A_pos  aposmalloc();
extern A_expstack estackmalloc();
extern A_varstack vstackmalloc();
int* A_intdup(int s);
extern A_tylistStack tylist_Stackmalloc();
extern A_vardecStack vardec_Stackmalloc();
extern A_fundeclistStack fundeclist_Stackmalloc();
extern A_declistStack A_declistStack_malloc();
extern A_explistStack A_explistStack_malloc();
extern A_mutrecFnstate   A_mutrecFnstate_malloc();
#endif 
