/* Expression debug (print) file 
 * for the lex yacc generator
 * of Tiger
 */

#include <stdio.h>
#include <string.h>
#include "absyn.h"
#include "pos_def.h"

extern FILE *yyout;

void prn_aexp(A_exp);
void prn_avar(A_var);
void prn_afieldList(A_fieldList); 
void prn_aty(A_ty); 
void prn_atyList(A_nametyList);
void prn_aexplist(A_explist);

struct DbgOper{
A_oper opval;
STR optype;
};

/* Defining some debug info for the expression operators */
#define MAXOP         13
struct DbgOper ShowOp[MAXOP] = {
	{A_plusOp,   "PLUS"},
	{A_minusOp,  "MINUS"},
	{A_timesOp,  "MUL"},
	{A_divideOp, "DIV"},
	{A_eqOp,     "EQ(COMP)"},
	{A_neqOp,    "NEQ(COMP)"},
	{A_ltOp,     "LESS THAN"},
	{A_gtOp,     "GRT THAN"},
	{A_geOp,     "GR EQ"},
	{A_leOp,     "LT EQ"},
	{A_andOp,    "AND OP"},
	{A_orOp,     "OR OP"},
	/* add more operators here */

	{MAXOP,      "!!NO SUCH OP!!"}
  };

#define ShowOpr(x)    (( ((x)>=0) & ((x) < MAXOP) ) ? \
                      ShowOp[(x)].optype : \
		      ShowOp[MAXOP-1].optype)

/*
 * Print statistics of the pointer
 * during insertion in absyn tree.
 */

void
print_stat(void *ptr)
{

}

void 
prn_avar(A_var a_var)
{
	switch(a_var->kind)
        {
	case simple:
                fprintf(yyout, "PRNSTAT-VAR: SIMPLE VAR (l:%d, c:%d): %s\n\n", *(a_var->pos->line),
                *(a_var->pos->col), a_var->vartype.simple.name);
	        return;

        case field:
 
                if(a_var->vartype.field.recname->kind == simple) { 
             
                fprintf(yyout, "PRNSTAT-VAR: FIELD VAR (l:%d, c:%d): %s and %s\n\n", *(a_var->pos->line),
                *(a_var->pos->col), a_var->vartype.field.recname->vartype.simple.name, 
	        a_var->vartype.field.component );
                return;

                }
                else
                {

                fprintf(yyout, "PRNSTAT: FIELD VAR (l:%d, c:%d): [SEE-NEXT] and %s\n", *(a_var->pos->line),
                *(a_var->pos->col),  
	        a_var->vartype.field.component );

                prn_avar(a_var->vartype.field.recname);
                break;
                } 

		/* why do I assume that there cannot be a subscript-var
		 * (array of records) that could be an element of this
		 * field-var?
		 */

        case subscript: 
                fprintf(yyout, "PRNSTAT: A SUBSCRIPT VAR (l:%d, c%d)\n", *(a_var->pos->line), 
                *(a_var->pos->col) );

                fprintf(yyout, "In subscript-var, the varname is as follows: \n");
                prn_avar(a_var->vartype.subscript.aryname);

                fprintf(yyout, "In subscript-var, the expression is as follows: \n");
                prn_aexp(a_var->vartype.subscript.component);

	        break;

	default:
	       fprintf(yyout, "\nPRNSTAT: No Match Found!\n");
	break;
        }

return;	
}

void
prn_aexp(A_exp a_exp)
{
	switch(a_exp->kind)
        {

	case varexp:
		fprintf(yyout, "PRNSTAT-EXP: VAR EXP (l:%d, c:%d): (details below)\n",*(a_exp->pos->line),
                *(a_exp->pos->col));
	        prn_avar(a_exp->exptype.varexp.var);
	        break;


        case intexp: 
                fprintf(yyout, "PRNSTAT-EXP: INT EXP : %d\n", 
                a_exp->exptype.intexp.i);

                fprintf(yyout, "PRNSTAT-EXP: INT EXP (l:%d, c:%d)\n", *(a_exp->pos->line),
                *(a_exp->pos->col));

                fprintf(yyout, "\n");
	        return;

        case bopexp:
                fprintf(yyout, "PRNSTAT-EXP: BOP EXP (l:%d, c:%d): OpType=%s\n\n", *(a_exp->pos->line),
                *(a_exp->pos->col), ShowOpr(a_exp->exptype.bopexp.oper));

                fprintf(yyout," Printing about Left SubExp of %s now:\n", ShowOpr(a_exp->exptype.bopexp.oper));
                prn_aexp(a_exp->exptype.bopexp.left);

                fprintf(yyout," Printing about Right SubExp of %s now:\n", ShowOpr(a_exp->exptype.bopexp.oper));
                prn_aexp(a_exp->exptype.bopexp.right);

                return;

       case aryexp:
                fprintf(yyout, "PRNSTAT-EXP: ARRAY EXP (l:%d, c:%d) of type = \"%s\"\n\n", *(a_exp->pos->line),
                *(a_exp->pos->col), a_exp->exptype.aryexp.typ);

                fprintf(yyout, "ArraySize expression is as follows:\n");
                prn_aexp(a_exp->exptype.aryexp.size);

                fprintf(yyout, "ArrayInit expression is as follows:\n");
                prn_aexp(a_exp->exptype.aryexp.initval);
                return;

      case callexp:
                fprintf(yyout, "PRNSTAT-EXP: FUNC-CALL (l:%d, c:%d) of function \'%s\'\n\n", *(a_exp->pos->line),
                *(a_exp->pos->col), a_exp->exptype.callexp.func_name);

                fprintf(yyout, "Parameters passed to this function are as follows:\n");
                prn_aexplist(a_exp->exptype.callexp.args);
                return;

      case asnexp:
                fprintf(yyout, "PRNSTAT-EXP: ASN-EXP (l:%d, c:%d)\n\n", *(a_exp->pos->line),
                *(a_exp->pos->col));

                fprintf(yyout, "LHS of Assign Statement:\n");
                prn_avar(a_exp->exptype.asnexp.var);

                fprintf(yyout, "RHS of Assign Statement:\n");
                prn_aexp(a_exp->exptype.asnexp.exp);

                fprintf(yyout, "(End of Assign Statement)\n");

		return;

      case seqexp:
                fprintf(yyout, "PRNSTAT-EXP: SEQ-EXP (l:%d, c:%d)\n\n", *(a_exp->pos->line),
                *(a_exp->pos->col));

                fprintf(yyout, "BLOCK EXPRESSION STATEMENT IS AS FOLLOWS:\n");
                prn_aexplist(a_exp->exptype.seqexp.seq);

                return;

      case ifexp:
                fprintf(yyout, "PRNSTAT-EXP: IF-EXP (l:%d, c:%d)\n\n", *(a_exp->pos->line),
                *(a_exp->pos->col));

                fprintf(yyout, "IF TEST CONDITION EXPRESSION:\n");
                prn_aexp(a_exp->exptype.ifexp.test);

                fprintf(yyout, "IF THENBODY EXPRESSION:\n");
                prn_aexp(a_exp->exptype.ifexp.ThenBody);

                if(a_exp->exptype.ifexp.ElseBody != NULL) {
                fprintf(yyout, "IF ELSEBODY EXPRESSION:\n");
                prn_aexp(a_exp->exptype.ifexp.ElseBody);
                }

                fprintf(yyout, "END OF IF-EXP\n");
                return;

      case whlexp:
                fprintf(yyout, "PRNSTAT-EXP: WHILE-EXP (l:%d, c:%d)\n\n", *(a_exp->pos->line),
                *(a_exp->pos->col));
  
                fprintf(yyout, "WHILE TEST CONDITION EXPRESSION:\n");
                prn_aexp(a_exp->exptype.whlexp.test);

                fprintf(yyout, "WHILE MAIN BODY EXPRESSION:\n");
                prn_aexp(a_exp->exptype.whlexp.body);

		fprintf(yyout, "END OF WHILE-EXPRESSION\n");
                return;

      case brkexp:
                fprintf(yyout, "PRNSTAT-EXP: A BREAK-EXP at (l:%d, c:%d)\n\n", *(a_exp->pos->line),
                *(a_exp->pos->col));

                return;

      case forexp:
                fprintf(yyout, "PRNSTAT-EXP: FOR-EXP (l:%d, c:%d)\n\n", *(a_exp->pos->line),
                *(a_exp->pos->col));

                fprintf(yyout, "FOR LOOP EXPRESSION LO:\n");
                prn_aexp(a_exp->exptype.forexp.lo);

                fprintf(yyout, "FOR LOOP EXPRESSION HI:\n");
                prn_aexp(a_exp->exptype.forexp.hi);

                fprintf(yyout, "FOR LOOP EXPRESSION HI:\n");
                prn_aexp(a_exp->exptype.forexp.hi);

                fprintf(yyout, "FOR LOOP EXPRESSION MAIN BODY:\n");
                prn_aexp(a_exp->exptype.forexp.body);

		fprintf(yyout, "END OF FOR-EXPRESSION\n");
                return;

      case letexp:

                return;

        default:
	       fprintf(yyout, "PRNSTAT-EXP: No Match Found ! (kind=%d) \n", a_exp->kind);
	       break;

        }

return;
}

void Dbprn_expstack()
{
  A_expstack x = absyn_expstack;
  int lev=1;
  fprintf(yyout, " * * * * * * * STACK CONTENTS BEGIN * * * * *\n");

  while(x != NULL)
  {
  fprintf(yyout, " * * * * * * * LEVEL %d * * * * *\n", lev++);
  prn_aexp(x->exp);
  x=x->next;
  }

  fprintf(yyout, " * * * * * * * STACK CONTENTS END * * * * *\n\n");
  return;

}

void prn_afieldList(A_fieldList a_fieldList)
{

fprintf(yyout, "FIELD LIST DETAILS:\n");
A_fieldList x = a_fieldList;
while(x != NULL) {
        fprintf(yyout, "symbol %s for type %s\n", x->head->name,
        x->head->typ);
        x = x->tail;
}
fprintf(yyout, "[END]\n");

}

void prn_aty(A_ty a_ty)
{

A_ty x = a_ty;
switch(x->kind)
{
 case rec:
          fprintf(yyout, " TYPE RHS: RECORD TYPE\n");
          prn_afieldList(x->which.rectype.record);
          break;

 case ary:
          fprintf(yyout, " TYPE RHS: ARRAY TYPE\n");
          fprintf(yyout, " array: %s\n",x->which.arytype.array);
          break;

 case name:
          fprintf(yyout, " TYPE RHS: ID TYPE\n");
          fprintf(yyout, " id: %s\n",x->which.nametype.sym); 
          break;

}


}


void prn_atyList(A_nametyList a_nametyList)
{
A_nametyList x = a_nametyList;
int tyno=0;

fprintf(yyout, "\n\n");

fprintf(yyout, "NEW TYPE LIST DETAILS\n");
while(x != NULL)
{ 
	tyno++;
	fprintf(yyout, "%d TYPE HEADER\n", tyno);
	fprintf(yyout, " TYPE LHS = %s\n", x->head->sym);
	prn_aty(x->head->ty);

x=x->tail;
}

fprintf(yyout, "[END TYPE LIST]\n");
fprintf(yyout, "\n\n");

}

void prn_aexplist(A_explist explist)
{
A_explist x = explist;
int listele=0;

fprintf(yyout, "\n");

fprintf(yyout,"Expression List:\n");
fprintf(yyout,"------------------\n");

while(x != NULL)
{
 listele++;
 fprintf(yyout, "[EXPLIST] expression no. %d is as follows: \n", listele);
 prn_aexp(x->head);
 x=x->tail;
}
fprintf(yyout, "[end expression list]\n");
fprintf(yyout, "\n\n");

} 

