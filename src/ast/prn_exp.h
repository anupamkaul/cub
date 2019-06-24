/* Header file for making disponible
 * the print functions for the package
 */

#ifndef prn_exp_h
#define prn_exp_h  1

extern void prn_aexp(A_exp);
extern void prn_avar(A_var);
extern void prn_afieldList(A_fieldList); 
extern void prn_aty(A_ty); 
extern void prn_atyList(A_nametyList);
extern void prn_aexplist(A_explist);

//extern struct DbgOper ShowOp[];

#endif
/* end of prn_exp.h */
