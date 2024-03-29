%{
    /* The parser for the tiger language */

    /* There are no semantic actions associated with the grammar
       rules in this version of the parser */

    /* write additional comments here, in a
       structured format
     */

#include <stdio.h>
#include <string.h>
#include "absyn.h" 
#include "absyn.c" 
#include "absyn_malloc.c" 
#include "pos_def.h"

FILE *llout;
extern FILE *yyin, *yyout;

void prn_aexp(A_exp);
void prn_avar(A_var);
void prn_afieldList(A_fieldList); 
void prn_aty(A_ty); 
void prn_atyList(A_nametyList);
void prn_aexplist(A_explist);

/* sockets between lex n yacc */
extern int SEND_FALSE_FUNCTION;
extern int NULL_DECLIST;

%}

%union{

 struct strinfo_{
 char *strval;
	struct pos_ {
 	int line;
 	int col;
	} pos[MAX_POS];
 }strinfo;

 struct intinfo_{
 int intval;
 int line;
 int col;
 }intinfo;
 
}

%token <strinfo.strval> let_kwd 
%token <strinfo.strval> type_kwd 
%token <strinfo.strval> var_kwd 
%token <strinfo.strval> fn_kwd 
%token <strinfo.strval> int_kwd 
%token <strinfo.strval> string_kwd 
%token <strinfo.strval> array_kwd
%token <strinfo.strval> of_kwd  
%token <strinfo.strval> if_kwd  
%token <strinfo.strval> then_kwd  
%token <strinfo.strval> else_kwd  
%token <strinfo.strval> in_kwd  
%token <strinfo.strval> nil_kwd  
%token <strinfo.strval> break_kwd  
%token <strinfo.strval> while_kwd  
%token <strinfo.strval> do_kwd  
%token <strinfo.strval> for_kwd  
%token <strinfo.strval> to_kwd  
%token <strinfo.strval> end_kwd  
%token <strinfo.strval> ident  
%token <strinfo.strval> eq_op 
%token <strinfo.strval> colon  
%token <strinfo.strval> lbrace  
%token <strinfo.strval> rbrace  
%token <strinfo.strval> comma  
%token <strinfo.strval> lparan  
%token <strinfo.strval> rparan  
%token <strinfo.strval> sqLbrace  
%token <strinfo.strval> sqRbrace  
%token <strinfo.strval> not_eq  
%token <strinfo.strval> gr_op  
%token <strinfo.strval> le_op  
%token <strinfo.strval> le_eq_op  
%token <strinfo.strval> gr_eq_op  
%token <strinfo.strval> add_op  
%token <strinfo.strval> minus_op 
%token <strinfo.strval> mult_op 
%token <strinfo.strval> div_op  
%token <strinfo.strval> and_op 
%token <strinfo.strval> or_op  
%token <strinfo.strval> semicolon  
%token <strinfo.strval> dquote  
%token <strinfo.strval> squote  
%token <strinfo.strval> asn_op  
%token <strinfo.strval> pure_num  
%token <strinfo.strval> pure_str
%token <strinfo.strval> period
%token <strinfo.strval> false_type_kwd
%token <strinfo.strval> false_function_kwd

%type  <strinfo.strval> tig_root
%type  <strinfo.strval> decls

%type  <strinfo.strval> type_decl
%type  <strinfo.strval> ty_rhs
%type  <strinfo.strval> tyfields
%type  <strinfo.strval> typeid

%type  <strinfo.strval> var_decl
%type  <strinfo.strval> func_decl

%type  <strinfo.strval> type_decls
%type  <strinfo.strval> func_decls

%type  <strinfo.strval> expv
%type  <strinfo.strval> expliteral
%type  <strinfo.strval> lvalue

%type  <strinfo.strval> func_call
%type  <strinfo.strval> parameter_list

%type  <strinfo.strval> expseq
%type  <strinfo.strval> explist

%type  <strinfo.strval> if_then_decl
%type  <strinfo.strval> if_then_else_decl
%type  <strinfo.strval> while_decl
%type  <strinfo.strval> for_decl

%type  <strinfo.strval> let_decl

%type  <strinfo.strval> rec_defn
%type  <strinfo.strval> rec_defn_param
%type  <strinfo.strval> array_defn

%%

       tig_root  :         let_decl {

#ifdef YDUMPTXT
                           fprintf(yyout, "\n(test) ROOT REACHED at : %s\n", $$);
#endif

                           };


       let_decl  :         let_kwd decls in_kwd expseq end_kwd {

                           $$ = strmemcat($$, "\n[Type]\n");
                           $$ = strmemcat($$, $2);
                          
                           $$ = strmemcat($$, "\n");
                           $$ = strmemcat($$, $3);
                          
                           $$ = strmemcat($$, "\n[Body]\n");
                           $$ = strmemcat($$, $4);

                           $$ = strmemcat($$, "\n");
                           $$ = strmemcat($$, $5);
                           $$ = strmemcat($$, "\n[END]\n\n");

                           SEND_FALSE_FUNCTION=0;
                           NULL_DECLIST=1;

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<BISON> EVALD a LET_decl (occurance %d,%d): %s\n", 
                           yylval.strinfo.pos[let_kwd_pos].line, 
                           yylval.strinfo.pos[let_kwd_pos].col, $$);
#endif
                           }

       /* *************************************

          Handling declarations here.

          These are grouped into 3:

          1. Type declarations.
          2. Variable declarations..
          3. Function declarations.

        * ****************************************/

       decls    :          type_decls decls
                           {
                             	/* pop tyList and add to current decList */
                             	/* (note: absyn_pos is not defined ..) */
#ifdef YDUMP_TYLIST
                           	fprintf(yyout, "MAIN BAPU TYPE DECL CONTD\n");
                             	prn_atyList(A_peeptyList(0));
#endif
                             	absyn_decList = A_DecList(A_TypeDec(absyn_pos, A_poptyList()),absyn_decList);
                           }
                 |         func_decls decls
                 |         var_decl decls 
                           {
#ifdef YDUMP_VLIST
                                fprintf(yyout, "VARLIST - ALSO ADDED (%s)\n",A_peepVardec(0)->dectype.vardec.var);
                                fprintf(yyout, "Expression associated with this var is as follows:\n");
                                prn_aexp(A_peepVardec(0)->dectype.vardec.init); 
                                fprintf(yyout,"END-OF-EXP\n\n");
#endif
                                absyn_decList = A_DecList(A_popVardec(), absyn_decList);
                           }
                 |         func_decls 
                 |         type_decls 
                           {
			     	/* pop tyList and add to a null decList */
                             	/* (note: absyn_pos is not defined ..) */

#ifdef YDUMP_TYLIST
                             	fprintf(yyout, "MAIN BAPU TYPE DECL START\n");
                             	prn_atyList(A_peeptyList(0));
#endif

                             	if(NULL_DECLIST) {
#ifdef YDUMP_TYLIST
                             	fprintf(yyout, "AVEC A NULL\n");
#endif
                             	absyn_decList = A_DecList(A_TypeDec(absyn_pos, A_poptyList()),NULL);
                             	NULL_DECLIST=0;
                             	}
		             	else {
#ifdef YDUMP_TYLIST
                             	fprintf(yyout, "AVEC THE OLD\n");
#endif
                             	absyn_decList = A_DecList(A_TypeDec(absyn_pos, A_poptyList()),absyn_decList);
                             	}
                           } 
                 |         var_decl
                           {
			   	if(NULL_DECLIST) {
#ifdef YDUMP_VLIST
                                fprintf(yyout, "VARLIST (LOOKS FIRST), ADDED TO NULL (%s)\n",
                                A_peepVardec(0)->dectype.vardec.var);
                                fprintf(yyout, "Expression associated with this var is as follows:\n");
                                prn_aexp(A_peepVardec(0)->dectype.vardec.init); 
                                fprintf(yyout,"END-OF-EXP\n\n");
#endif
                                absyn_decList = A_DecList(A_popVardec(), NULL);
			        NULL_DECLIST=0;
                                } else {
#ifdef YDUMP_VLIST
                                fprintf(yyout, "VARLIST (LOOKS FIRST), BUT ADDED TO OLD (%s)\n",
                                A_peepVardec(0)->dectype.vardec.var);
                                fprintf(yyout, "Expression associated with this var is as follows:\n");
                                prn_aexp(A_peepVardec(0)->dectype.vardec.init); 
                                fprintf(yyout,"END-OF-EXP\n\n");
#endif
                                absyn_decList = A_DecList(A_popVardec(), absyn_decList);
                                }
                           };

      /* *****************************************************
       * Collect a (possible) list of mutually recursive types
       * *****************************************************/

       type_decls:         type_decls type_decl { 
                           
		          /* pop, affect, push */
                          A_pushtyList(A_NametyList( absyn_namety, A_poptyList()));

#ifdef YDUMPMRC
			  fprintf(yyout, "GOING IN TYPE ;)\n"); 
#endif
                           } 

                 |         false_type_kwd { 

			   /* create new level */
			   A_pushtyList(NULL);
#ifdef YDUMPMRC
			   fprintf(yyout, "GOING IN TYPE (FRST, FALSE) ;)\n"); 
#endif
                           } ;

       /* ************************
        * A type declaration
        * ************************/

       type_decl:          type_kwd ident eq_op ty_rhs  {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4);
                         
		           absyn_pos->line = A_intdup(yylval.strinfo.pos[type_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[type_kwd_pos].col); 
                           absyn_namety    = A_Namety($2, absyn_ty_rhs);

                           /* store the first position in the type list
                              for the declaration sequence (A_DecList) */
                           
#ifdef YDUMPTXT
                           fprintf(yyout, "\n<BISON> EVALD a type_decl: %s\n", $$);                            
#endif
                           };

      ty_rhs  :            ident {

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[ident_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[ident_pos].col); 

                           absyn_ty_rhs = A_nameTy(absyn_pos, $1);

                           }
              |            array_kwd of_kwd typeid
                           {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[of_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[of_kwd_pos].col); 

                           absyn_ty_rhs = A_ArrayTy(absyn_pos, $3);
                           
                           }
              |            lbrace tyfields rbrace
                           {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[lbrace_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[lbrace_pos].col); 

                           absyn_ty_rhs = A_RecordTy(absyn_pos, absyn_fieldList);

#ifdef YDUMPTXT
                           prn_afieldList(absyn_ty_rhs->which.rectype.record);
#endif

                           };


      tyfields :           tyfields comma ident colon typeid
                           {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $5);

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[colon_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[colon_pos].col); 

                           absyn_fieldList = A_FieldList(A_Field(absyn_pos, $3, $5), absyn_fieldList);
                           }
                                                             
               |           ident colon typeid
                           {

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[colon_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[colon_pos].col); 

                           absyn_fieldList = NULL;
                           absyn_fieldList = A_FieldList(A_Field(absyn_pos, $1, $3), absyn_fieldList);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           };

             typeid:       int_kwd
                   |       string_kwd
                   |       ident;

       /* ********************************************************* 

         Handling function declarations: these are grouped into 4:

         1. Function with no input, no output (procedure)
         2. Function with some input, no output (procedure)
         3. Function with no input, some output (proper function)
         4. Function with some input, some output (proper function)

       *  **********************************************************/

       func_decls:         func_decls func_decl { 

#ifdef YDUMPMRCF
                           fprintf(yyout, "GOING IN FUNCTION\n"); 
#endif

                           }
                           | false_function_kwd { 

#ifdef YDUMPMRCF
                           fprintf(yyout, "GOING IN FUNCTION (FRST, FALSE) (F)\n"); 
#endif

                           } ;


       func_decl:          fn_kwd ident lparan rparan eq_op expseq {

                           /* 1. a procedure without input parameters */

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $5);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $6);

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<BISON> EVALD a function_decl (no input, no output): %s\n", $$);
#endif
                           }

                           /* 2. a procedure with input parameters */
    
                |          fn_kwd ident lparan tyfields rparan eq_op expseq {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $5);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $6);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $7);

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<BISON> EVALD a function_decl (some input, no output): %s\n", $$);
#endif
                           }

                           /* 3. A function without any input parameters */
               
                |          fn_kwd ident lparan rparan colon typeid eq_op expseq {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $5);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $6);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $7);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $8);

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<BISON> EVALD a function_decl (no input, some output): %s\n", $$);
#endif
                           }

                           /* 4. A function with some input parameters */

                |          fn_kwd ident lparan tyfields rparan colon typeid eq_op expseq {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $5);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $6);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $7);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $8);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $9);

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<BISON> EVALD a function_decl (some input, some output): %s\n", $$);
#endif
                           };


       /* ********************************  
          Handling variable declarations 
          ******************************** */

       var_decl:           var_kwd ident asn_op expv {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4);

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[var_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[var_kwd_pos].col); 
                           //A_pushVardec(A_VarDec(absyn_pos, $2, "undefined", A_peepexp(0)));
                           A_pushVardec(A_VarDec(absyn_pos, $2, "undefined", A_popexp(0)));

#ifdef YDUMP_VLIST
                           fprintf(yyout, "\n<BISON> EVALD a var_decl: %s\n", $$);
#ifdef YDUMPTXT
                           fprintf(yyout, "TEST: %s\n", A_peepVardec(0)->dectype.vardec.var);
                           fprintf(yyout, "TEST (pos line IS WRONG): %d\n", *(A_peepVardec(0)->pos->line));
#endif
#endif
                                                        }

                |          var_kwd ident asn_op array_defn {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4);

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[var_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[var_kwd_pos].col); 
                           //A_pushVardec(A_VarDec(absyn_pos, $2, "array_type", A_peepexp(0)));
                           A_pushVardec(A_VarDec(absyn_pos, $2, "array_type", A_popexp()));

#ifdef YDUMP_VLIST
                           fprintf(yyout, "\n<BISON> EVALD a var_decl: %s\n", $$);
#endif
                                                        }

      
              |           var_kwd ident colon typeid asn_op expv {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4); 

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $5);
                           
                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $6);

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[var_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[var_kwd_pos].col); 
                           //A_pushVardec(A_VarDec(absyn_pos, $2, $4, A_peepexp(0)));
                           A_pushVardec(A_VarDec(absyn_pos, $2, $4, A_popexp()));

#ifdef YDUMP_VLIST
                           fprintf(yyout, "\n<BISON> EVALD a var_decl: %s\n", $$);
#endif
                                                        };

        
    /* record and array creation were added in the end .. so here they are .. */

           rec_defn:       typeid lbrace rec_defn_param rbrace {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4);

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<BISON> EVALD a Rec Creation Statement: %s\n", $$);
#endif

                           };

          rec_defn_param:  rec_defn_param comma ident eq_op expv {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $5);

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<BISON> EVALD a Rec Creation Parm: %s\n", $$);
#endif
                           }

                        |  ident eq_op expv {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<BISON> EVALD a Rec Creation Parm: %s\n", $$);
#endif
                           };


        /*  Array Defn: 

         *  The only change I am making is in the position of typeid. I place it after [ ] to 
         *  avoid a reduce/reduce conflict that I get from yac (ident -> typeid or lvalue).
         *
         *  This change does not cause any major deviations in denotational semantics
         *  of this construct, for tiger. 
         *
         *  eg:  var nvar := [ N + 2 ] intArray of 0 
         */

        array_defn:        sqLbrace expv sqRbrace typeid of_kwd expv {

                           A_exp size, initval;

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $5);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $6);

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[sqLbrace_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[sqLbrace_pos].col); 

                           fprintf(yyout, "Discovered an ARRAY DEFN: %s\n", $$);

                           initval = A_popexp();
                           size    = A_popexp();

                           A_pushexp(A_ArrayExp(absyn_pos, $4, size, initval));

                           };

       /*  ******************************************************** 
         Following are designs of valued-expressions.

          They include:
          1. Arithmetic expressions.
          2. Comparison expressions.
          3. Logical expressions.

           *******************************************************/

       expv:               expliteral add_op expv {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);
#ifdef YDUMPEXP                          
                          fprintf(yyout, "ADD EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[add_op_pos].line,
                          yylval.strinfo.pos[add_op_pos].col, $$);

                          fprintf(yyout, "In the ADD EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "In the ADD EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[add_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[add_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_plusOp, A_popexp(), A_popexp()));
#ifdef PRN_STACK
                          Dbprn_expstack(); 
#endif
                           
                           }

           |              expliteral minus_op expv {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

#ifdef YDUMPEXP                          
                          fprintf(yyout, "MINUS EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[minus_op_pos].line,
                          yylval.strinfo.pos[minus_op_pos].col, $$);

                          fprintf(yyout, "In the MINUS EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "In the MINUS EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif
		          absyn_pos->line = A_intdup(yylval.strinfo.pos[minus_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[minus_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_minusOp, A_popexp(), A_popexp()));
                           
                           }

           |               expliteral mult_op expv {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

#ifdef YDUMPEXP                          
                          fprintf(yyout, "MULT EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[mult_op_pos].line,
                          yylval.strinfo.pos[mult_op_pos].col, $$);

                          fprintf(yyout, "In the MULT EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "In the MULT EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[mult_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[mult_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_timesOp, A_popexp(), A_popexp()));

                           }

           |               expliteral div_op expv {
			   
                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

#ifdef YDUMPEXP                          
                          fprintf(yyout, "DIV EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[add_op_pos].line,
                          yylval.strinfo.pos[div_op_pos].col, $$);

                          fprintf(yyout, "In the DIV EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "In the DIV EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[div_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[div_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_divideOp, A_popexp(), A_popexp()));

                           } 

           /*  Comparison operators are handled next */
            
           |               expliteral eq_op expv {
			   
                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);
                       
#ifdef YDUMPEXP                          
                          fprintf(yyout, "EQUAL COMPARE EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[eq_op_pos].line,
                          yylval.strinfo.pos[eq_op_pos].col, $$);

                          fprintf(yyout, "In the EQ-COMP EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "In the EQ-COMP EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[eq_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[eq_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_eqOp, A_popexp(), A_popexp()));

                           } 

 
           |               expliteral not_eq expv {
			   
                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

#ifdef YDUMPEXP                          
                          fprintf(yyout, "NEQ COMPARE EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[not_eq_pos].line,
                          yylval.strinfo.pos[not_eq_pos].col, $$);

                          fprintf(yyout, "In the NEQ-COMP EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "In the NEQ-COMP EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[not_eq_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[not_eq_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_neqOp, A_popexp(), A_popexp()));
                           
                           } 

           
           |               expliteral gr_op expv {
			   
                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

#ifdef YDUMPEXP                          
                          fprintf(yyout, "GR-COMP EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[gr_op_pos].line,
                          yylval.strinfo.pos[gr_op_pos].col, $$);

                          fprintf(yyout, "In the GR-COMP EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "In the GR-COMP EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[gr_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[gr_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_gtOp, A_popexp(), A_popexp()));
                           
                           } 


           |               expliteral le_op expv {
			   
                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

#ifdef YDUMPEXP                          
                          fprintf(yyout, "LT-COMP EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[le_op_pos].line,
                          yylval.strinfo.pos[le_op_pos].col, $$);

                          fprintf(yyout, "In the LT-COMP EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "In the LT-COMP EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[le_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[le_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_ltOp, A_popexp(), A_popexp()));
                           
                           } 


           |               expliteral gr_eq_op expv {
			   
                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

#ifdef YDUMPEXP                          
                          fprintf(yyout, "GR-EQ-COMP EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[gr_eq_op_pos].line,
                          yylval.strinfo.pos[gr_eq_op_pos].col, $$);

                          fprintf(yyout, "In the GR-EQ-COMP EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "In the GR-EQ-COMP EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[gr_eq_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[gr_eq_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_geOp, A_popexp(), A_popexp()));
                           
                           } 

           
           |               expliteral le_eq_op expv {
			   
                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

#ifdef YDUMPEXP                          
                          fprintf(yyout, "LT-EQ-COMP EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[le_eq_op_pos].line,
                          yylval.strinfo.pos[le_eq_op_pos].col, $$);

                          fprintf(yyout, "In the LT-EQ-COMP EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "In the LT-EQ-COMP EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[le_eq_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[le_eq_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_leOp, A_popexp(), A_popexp()));
                           
                           } 

          /* boolean(logical) operators are handled next */

           |               expliteral and_op expv {
			   
                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

#ifdef YDUMPEXP                          
                          fprintf(yyout, "LOG-AND EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[and_op_pos].line,
                          yylval.strinfo.pos[and_op_pos].col, $$);

                          fprintf(yyout, "In the LOG-AND EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "In the LOG-AND EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[and_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[and_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_andOp, A_popexp(), A_popexp()));
                           
                           } 

           |               expliteral or_op expv {
			   
                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

#ifdef YDUMPEXP                          
                          fprintf(yyout, "LOG-OR EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[or_op_pos].line,
                          yylval.strinfo.pos[or_op_pos].col, $$);

                          fprintf(yyout, "In the LOG-OR EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "In the LOG-OR EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[or_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[or_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_orOp, A_popexp(), A_popexp()));
                           
                           }

           /*  handle negation of an expression */

           |               minus_op expv { 
                       
                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           }  

 
           /* and finally the expression primaries */

           |               expliteral 
                           {
#ifdef YDUMPEXP                          
                           fprintf(yyout, "Discovered an EXPLITEral: %s\n", $$);
#endif
                           }
                           ;

           /* **************************************

              expliteral covers the following:

              1. pure numbers
              2. strings (identifiers, as lvalue)
              3. any expv inside paranthesis
              4. array subscipt (as lvalue)
              5. record field (as lvalue)
              6. function call

              ***************************************/


       expliteral:        pure_num {

#ifdef YDUMPEXP                          
			  fprintf(yyout,"3. EXPLITERAL (pure num): %s (%d, %d)\n", $$, 
                          yylval.strinfo.pos[pure_num_pos].line, yylval.strinfo.pos[pure_num_pos].col);
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[pure_num_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[pure_num_pos].col); 

                          A_pushexp(A_IntExp(absyn_pos, $$));

#ifdef PRN_STACK
                          Dbprn_expstack(); 
#endif

			  }

                 |        lvalue {

#ifdef YDUMPEXP                          
			  fprintf(yyout,"3. EXPLITERAL (lvalue): %s\n", $$);
#endif

                          A_pushexp(A_VarExp(absyn_pos, A_popvar() ));

#ifdef PRN_STACK
                          Dbprn_expstack(); 
#endif

			  }
		 
                 |        lparan expv rparan {

                          $$ = strmemcat($$, " ");
                          $$ = strmemcat($$, $2);

                          $$ = strmemcat($$, " ");
                          $$ = strmemcat($$, $3);

                          } 

                 |        func_call;

    /* ********************************************************
       
       lvalue is anything that can be read from or written to.
       Note that lvalue covers here only the following:

       1. An array subscript.
       2. A record field
       3. Any simple identifier.

    *  *********************************************************/

    lvalue:               lvalue sqLbrace expv sqRbrace {

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[ident_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[ident_pos].col); 

			  A_pushvar(A_SubscriptVar(absyn_pos, A_popvar(), A_popexp())); 

                          $$ = strmemcat($$, $2);

                          $$ = strmemcat($$, " ");
                          $$ = strmemcat($$, $3);

                          $$ = strmemcat($$, " ");
                          $$ = strmemcat($$, $4);

#ifdef YDUMPVAR                          
                          fprintf(yyout, "SUBSCRIPTVAR (l:%d, c:%d): %s\n", yylval.strinfo.pos[ident_pos].line,
                          yylval.strinfo.pos[ident_pos].col, $$);

                          prn_avar(A_peepvar(0));
#endif

                          }

          |               lvalue period ident {

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[ident_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[ident_pos].col); 

			  A_pushvar(A_FieldVar(absyn_pos, A_popvar(), $3)); 

                          $$ = strmemcat($$, $2);
                          $$ = strmemcat($$, $3);

#ifdef YDUMPVAR                          
                          fprintf(yyout, "2. FIELD VAR (l:%d, c:%d): %s\n", yylval.strinfo.pos[ident_pos].line,
                          yylval.strinfo.pos[ident_pos].col, $$);

                          //prn_avar(absyn_var);
#endif

                          } 

         |                ident {

#ifdef YDUMPVAR                          
                          fprintf(yyout, "1. SIMPLE VAR (l:%d, c:%d): %s\n", yylval.strinfo.pos[ident_pos].line,
                          yylval.strinfo.pos[ident_pos].col, $$);
                          //prn_avar(absyn_var);
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[ident_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[ident_pos].col); 

			  A_pushvar(A_SimpleVar(absyn_pos, $$)); 

                          }
                          ;

         /* Function call syntax */

         func_call:       ident lparan rparan {

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[ident_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[ident_pos].col); 

                          /* Since there is no explist at this point, so just affect an A_exp
                           * and add it to the stack at this point. Pass NULL for the explist
                           * arguement */

                          A_pushexp(A_CallExp(absyn_pos, $1, NULL)); 

                          $$ = strmemcat($$, $2);
                          $$ = strmemcat($$, $3);

#ifndef YDUMPTXT
                          fprintf(yyout, "\n<BISON> EVALD a func call: %s", $$);
#endif
 
                          }

                  |       ident lparan parameter_list rparan {

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[ident_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[ident_pos].col); 

                          /* Pop out the latest explist (from stack), affect it on A_exp (func_call)
                           * and push the new A_exp on its stack.
                           */

                          A_pushexp(A_CallExp(absyn_pos, $1, A_popexplist()));

                          $$ = strmemcat($$, $2);
                          $$ = strmemcat($$, $3);
                          $$ = strmemcat($$, $4);

#ifndef YDUMPTXT
                          fprintf(yyout, "\n<BISON> EVALD a func call: %s\n", $$);
#endif
                          };

         parameter_list:  parameter_list comma expv {

                          $$ = strmemcat($$, " ");
                          $$ = strmemcat($$, $2);

                          $$ = strmemcat($$, " ");
                          $$ = strmemcat($$, $3);

                          /* Pop, affect, push */
			  A_pushexplist(A_ExpList(A_popexp(), A_popexplist()));

                          }
                       |  expv {

                          /* Push, raise level in the stack */
                          A_pushexplist(A_ExpList(A_popexp(),NULL));

		          };


        /* Expseq is a sequence of expressions, seperated by semicolons, and expseq
           begins and ends with paranthesis .. ( exp ; exp ; exp ; ... exp )
         */


         expseq :         lparan rparan {

                          $$ = strmemcat($$, " ");
                          $$ = strmemcat($$, $2);

                          }
                |         lparan explist rparan {

                          $$ = strmemcat($$, " ");
                          $$ = strmemcat($$, $2);

                          $$ = strmemcat($$, " ");
                          $$ = strmemcat($$, $3);

                          };

         explist:         explist semicolon expv {

                          $$ = strmemcat($$, " ");
                          $$ = strmemcat($$, $2);

                          $$ = strmemcat($$, "\n");
                          $$ = strmemcat($$, $3);

                          }
               |          expv  
          
               |          explist semicolon if_then_decl {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, "\n");
                           $$ = strmemcat($$, $3);

                          }
               |          if_then_decl

               |          explist semicolon if_then_else_decl {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, "\n");
                           $$ = strmemcat($$, $3);

                          }
               |          if_then_else_decl

               |          explist semicolon while_decl {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, "\n");
                           $$ = strmemcat($$, $3);

                          }
               |          while_decl

               |          explist semicolon for_decl {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, "\n");
                           $$ = strmemcat($$, $3);

                          }
               |          for_decl 

               |          explist semicolon func_decl {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, "\n");
                           $$ = strmemcat($$, $3);

                          }
               |          func_decl

               |          explist semicolon let_decl {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, "\n");
                           $$ = strmemcat($$, $3);

                           SEND_FALSE_FUNCTION=0;

                          }
               |          let_decl {

                           SEND_FALSE_FUNCTION=0;

                          }



               /* the 'break' keyword must be semantically checked: it
                  should occur only within a loop construct */
   
               |          explist semicolon break_kwd {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, "\n");
                           $$ = strmemcat($$, $3);

                          }
               |          break_kwd


               /* record creation statements */

               |          explist semicolon rec_defn {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, "\n");
                           $$ = strmemcat($$, $3);

                          }
               |          rec_defn ;


  /* Following are the elements of expuv(implicit). The unvalued expressions are:
     1. If-Then (Else)                    <in explist, and call explist>
     2. For statement.                    <in explist, and call explist>
     3. While-do statement.               <in explist, and call explist>
     4. Break kwd.                        <in explist, and call explist>
     5. Record creation, array creation.  <in explist, and call explist>
  */

   
  if_then_decl:            if_kwd expv then_kwd expseq {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4);

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<BISON> EVALD an if_then_decl: %s\n", $$);
#endif

                           };

            
              /*  
              |            if_kwd expv then_kwd expv {


                           expv -> s/r conflict with expseq (lparan) and expv->expliteral (lparan)

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4);

                           }; 

             */

 while_decl   :            while_kwd expv do_kwd expseq {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4);

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<BISON> EVALD a while_decl: %s\n", $$);
#endif

                           }

 for_decl    :             for_kwd ident asn_op expv to_kwd expv do_kwd expseq {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4);
                           
                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $5);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $6);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $7);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $8);

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<BISON> EVALD a for_loop_decl: %s\n", $$);
#endif

                           }

 
  if_then_else_decl:       if_kwd expv then_kwd expseq else_kwd expseq {

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $2);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $3);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $4);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $5);

                           $$ = strmemcat($$, " ");
                           $$ = strmemcat($$, $6);

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<BISON> EVALD an if_then_else_decl: %s\n", $$);
#endif

                          };


%%

/* Definition of yacc's main follows: */
main (int argc, char *argv[]) {

FILE *tfin, *tfout;

absyn_pos = aposmalloc();
absyn_pos->line = A_intdup(0);
absyn_pos->col  = A_intdup(0); 

if(argc == 1) {
fprintf(stderr, "tparse: input file name required");
exit(1);
}

tfin = fopen(argv[1], "r");

if(tfin == NULL) {
fprintf(stderr, "tparse: input %s does not exist\n", argv[1]);
exit(1);
}

tfout =  fopen("ydump.txt", "w");
llout =  fopen("ldump.txt", "w");

if(tfout == NULL) {
fprintf(stderr, "tparse: not enough space for fopen\n");
exit(1);
}

if(llout == NULL) {
fprintf(stderr, "tparse: not enough space for fopen\n");
exit(1);
}

yyin = tfin;
yyout = tfout;

while(!(feof(yyin))) {
yyparse();
};

fclose(llout);
fclose(yyout);
fclose(yyin);

free(absyn_pos);

} /* end of main */

yyerror(s)
char *s;
{
fprintf(stderr, "tparse error: %s\n", s);
}

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
                fprintf(yyout, "PRNSTAT-EXP: BOP EXP (l:%d, c:%d): OpType=%d\n\n", *(a_exp->pos->line),
                *(a_exp->pos->col), a_exp->exptype.bopexp.oper);

                fprintf(yyout," Printing about Left SubExp now:\n");
                prn_aexp(a_exp->exptype.bopexp.left);

                fprintf(yyout," Printing about Right SubExp now:\n");
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

fprintf(yyout, "\n\n");

fprintf(yyout,"Parameter List Details\n");
fprintf(yyout,"-----------------------\n");

while(x != NULL)
{
 listele++;
 fprintf(yyout, "expression no. %d is as follows: \n", listele);
 prn_aexp(x->head);
 x=x->tail;
}
fprintf(yyout, "[end expression list]\n");
fprintf(yyout, "\n\n");

} 

/* The problem with strcat was that I was not
 * checking for memory of $$ .. this gave rise
 * to memleaks during AST creation .. 
 *
 * Here is a version of strcat ..
 * which checks for mem internally and avoids
 * the user's caution to explicitly check for
 * mem
 */

char *strmemcat(char *source,  char *dest)
{
  int len = strlen(source);
  char *ret = (char *)realloc(source, strlen(source) + strlen(dest) + 2);
  char *head=ret;

  if( ret == NULL) { /* realloc failure */
  printf("No space for strmemcat\n");
  exit(0);
  }

  while(len>0) {
  ret++; len--;
  }

  while(*dest != '\0') {
  *ret= *dest;
  ret++; dest++;
  }
  *ret = '\0';
  return head;
}

