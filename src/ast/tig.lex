%{

/* Lexer for the Tiger Language:

   The lexer handles the following features
   of the tiger language:

   1. Tiger keywords
   2. Tiger type declaration symbols
   3. Tiger operators
   4. Tiger "other" symbols

   This version creates the file "ldump.txt"
   which graphically shows the lexer's recognition
   of various tokens in the input tiger file.

 */

#include <string.h>
#include "pos_def.h"
#include "y.tab.h"
#include "absyn.h"
extern FILE *llout;
char rec_cmt[100];    /* max 100 internally recursive comments */
int  lvl = 1;
int lxline=1;
int lxcol=1;

/* The curious increases of lxcol are like this:
 * count all the chars (space etc) and minus 1,
 * because lxcol init=1
 */

int SEND_FALSE_TYPE=1;
int SEND_FALSE_FUNCTION=1;

int NULL_DECLIST=0;

%}

%x    cmtmode

%%

^let([ ]|\n)    {

                 /* 1. Tiger KEYWORDS are handled in this section */

                /* token: let_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
		yylval.strinfo.pos[let_kwd_pos].line=lxline;
		yylval.strinfo.pos[let_kwd_pos].col=lxcol;
                yylval.strinfo.strval = strdup(yytext);
	
		lxcol+=3;	
   
                SEND_FALSE_TYPE=1; 

                A_pushMutRecState(SEND_FALSE_FUNCTION);
                SEND_FALSE_FUNCTION=1;

                NULL_DECLIST=1;
                return let_kwd;

                }

[ ]let([ ]|\n) { 
                /* token: let_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
		yylval.strinfo.pos[let_kwd_pos].line=lxline;
		yylval.strinfo.pos[let_kwd_pos].col=lxcol;
                yylval.strinfo.strval = strdup(yytext);

		lxcol+=4;	
 
                SEND_FALSE_TYPE=1;

                A_pushMutRecState(SEND_FALSE_FUNCTION);
                SEND_FALSE_FUNCTION=1;

                NULL_DECLIST=1;
                return let_kwd;

                }

^type([ ]|\n)   {
                if(SEND_FALSE_TYPE)
                {
                   /* return back to input */
                   unput(yytext[yyleng-1]);
                   unput(yytext[yyleng-2]);
                   unput(yytext[yyleng-3]);
                   unput(yytext[yyleng-4]);
                   unput(yytext[yyleng-5]);
                   unput(yytext[yyleng-6]);
                   yytext[yyleng-6] = '\0'; 
                        
                   yylval.strinfo.strval = strdup("false_type");

		   SEND_FALSE_TYPE=0;
                   return false_type_kwd;
                }
                else
                {
                /* token: type_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[type_kwd_pos].line=lxline;
		yylval.strinfo.pos[type_kwd_pos].col=lxcol;

		lxcol+=4;	
		//lxcol+=yyleng;	

                SEND_FALSE_FUNCTION=1;
                return type_kwd;
                }

                }

[ ]type([ ]|\n)    {

                if(SEND_FALSE_TYPE)
                {
                   /* return back to input */
                   unput(yytext[yyleng-1]);
                   unput(yytext[yyleng-2]);
                   unput(yytext[yyleng-3]);
                   unput(yytext[yyleng-4]);
                   unput(yytext[yyleng-5]);
                   unput(yytext[yyleng-6]);
                   yytext[yyleng-6] = '\0'; 
                        
                   yylval.strinfo.strval = strdup("false_type");

		   SEND_FALSE_TYPE=0;
                   return false_type_kwd;
                }
                else
                {
                /* token: type_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[type_kwd_pos].line=lxline;
		yylval.strinfo.pos[type_kwd_pos].col=lxcol;

		lxcol+=5;	
		//lxcol+=yyleng;	

                SEND_FALSE_FUNCTION=1;
                return type_kwd;
                }

                }


^var([ ]|\n)    {
                /* token: var_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[var_kwd_pos].line=lxline;
		yylval.strinfo.pos[var_kwd_pos].col=lxcol;

		lxcol+=3;

                SEND_FALSE_TYPE=1;	
                SEND_FALSE_FUNCTION=1;
                return var_kwd;

                }

[ ]var([ ]|\n)  {
                /* token: var_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[var_kwd_pos].line=lxline;
		yylval.strinfo.pos[var_kwd_pos].col=lxcol;

		lxcol+=4;	

                SEND_FALSE_TYPE=1;
                SEND_FALSE_FUNCTION=1;
                return var_kwd;

                }


^function([ ]|\n)    {
                if(SEND_FALSE_FUNCTION)
                {
		    /* return input to source */
                    unput(yytext[yyleng-1]);
                    unput(yytext[yyleng-2]);
                    unput(yytext[yyleng-3]);
                    unput(yytext[yyleng-4]);
                    unput(yytext[yyleng-5]);
                    unput(yytext[yyleng-6]);
                    unput(yytext[yyleng-7]);
                    unput(yytext[yyleng-8]);
                    unput(yytext[yyleng-9]);
                    unput(yytext[yyleng-10]);
		    yylval.strinfo.strval = strdup("false_function_kwd");
 
                    SEND_FALSE_FUNCTION=0;
                    return false_function_kwd;

                }
                else
                {
                /* token: fn_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[fn_kwd_pos].line=lxline;
		yylval.strinfo.pos[fn_kwd_pos].col=lxcol;

		lxcol+=8;	

                SEND_FALSE_TYPE=1;
                return fn_kwd;

                }
                }

[ ]function([ ]|\n)  {
                if(SEND_FALSE_FUNCTION)
                {
		    /* return input to source */
                    unput(yytext[yyleng-1]);
                    unput(yytext[yyleng-2]);
                    unput(yytext[yyleng-3]);
                    unput(yytext[yyleng-4]);
                    unput(yytext[yyleng-5]);
                    unput(yytext[yyleng-6]);
                    unput(yytext[yyleng-7]);
                    unput(yytext[yyleng-8]);
                    unput(yytext[yyleng-9]);
                    unput(yytext[yyleng-10]);
		    yylval.strinfo.strval = strdup("false_function_kwd");
 
                    SEND_FALSE_FUNCTION=0;
                    return false_function_kwd;

                }
                else
                {
                /* token: fn_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[fn_kwd_pos].line=lxline;
		yylval.strinfo.pos[fn_kwd_pos].col=lxcol;

		lxcol+=9;	

                SEND_FALSE_TYPE=1;
                return fn_kwd;
                }

                }


^int([ ]|\n)    {
                /* token: int_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[int_kwd_pos].line=lxline;
		yylval.strinfo.pos[int_kwd_pos].col=lxcol;

		lxcol+=3;	
                return int_kwd;

                }

[ ]int([ ]|\n)  {
                /* token: int_kwd */

                /* CHECK: In Yac, a stmt like array of int\n, the int_kwd is
                   not recognized unless I put a white-space after it before
                   skipping to the next line. */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[int_kwd_pos].line=lxline;
		yylval.strinfo.pos[int_kwd_pos].col=lxcol;

		lxcol+=4;	
                return int_kwd;

                }

^string([ ]|\n) {
                /* token: string_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[string_kwd_pos].line=lxline;
		yylval.strinfo.pos[string_kwd_pos].col=lxcol;

		lxcol+=6;	
                return string_kwd;

                }

[ ]string([ ]|\n)  {
                /* token: string_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[string_kwd_pos].line=lxline;
		yylval.strinfo.pos[string_kwd_pos].col=lxcol;

		lxcol+=7;	
                return string_kwd;

                }


^array([ ]|\n)  {
                /* token: array_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[array_kwd_pos].line=lxline;
		yylval.strinfo.pos[array_kwd_pos].col=lxcol;

		lxcol+=5;	
                return array_kwd;

                }

[ ]array([ ]|\n)   {
                /* token: array_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[array_kwd_pos].line=lxline;
		yylval.strinfo.pos[array_kwd_pos].col=lxcol;

		lxcol+=6;	
                return array_kwd;

                }

^of([ ]|\n)     {
                /* token: of_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[of_kwd_pos].line=lxline;
		yylval.strinfo.pos[of_kwd_pos].col=lxcol;

		lxcol+=2;	
                return of_kwd;

                }

[ ]of([ ]|\n)   {
                /* token: of_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[of_kwd_pos].line=lxline;
		yylval.strinfo.pos[of_kwd_pos].col=lxcol;

		lxcol+=3;	
                return of_kwd;

                }

^if([ ]|\n)     {
                /* token: if_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[if_kwd_pos].line=lxline;
		yylval.strinfo.pos[if_kwd_pos].col=lxcol;

		lxcol+=2;	
                return if_kwd;

                }

[ ]if([ ]|\n)   {
                /* token: if_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[if_kwd_pos].line=lxline;
		yylval.strinfo.pos[if_kwd_pos].col=lxcol;

		lxcol+=3;	
                return if_kwd;

                }


^then([ ]|\n)   {
                /* token: then_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[then_kwd_pos].line=lxline;
		yylval.strinfo.pos[then_kwd_pos].col=lxcol;

		lxcol+=4;	
                return then_kwd;

                }

[ ]then([ ]|\n) {
                /* token: then_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[then_kwd_pos].line=lxline;
		yylval.strinfo.pos[then_kwd_pos].col=lxcol;

		lxcol+=5;	
                return then_kwd;

                }


^else([ ]|\n)   {
                /* token: else_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[else_kwd_pos].line=lxline;
		yylval.strinfo.pos[else_kwd_pos].col=lxcol;

		lxcol+=4;	
                return else_kwd;

                }

[ ]else([ ]|\n) {
                /* token: else_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[else_kwd_pos].line=lxline;
		yylval.strinfo.pos[else_kwd_pos].col=lxcol;

		lxcol+=5;	
                return else_kwd;

                }


^in([ ]|\n)     {
                /* token: in_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[in_kwd_pos].line=lxline;
		yylval.strinfo.pos[in_kwd_pos].col=lxcol;

		lxcol+=2;	
                return in_kwd;

                }

[ ]in([ ]|\n)   {
                /* token: in_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[in_kwd_pos].line=lxline;
		yylval.strinfo.pos[in_kwd_pos].col=lxcol;

		lxcol+=3;	
                return in_kwd;

                }


^nil([ ]|\n)    {
                /* token: nil_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[nil_kwd_pos].line=lxline;
		yylval.strinfo.pos[nil_kwd_pos].col=lxcol;

		lxcol+=3;	
                return nil_kwd;

                }

[ ]nil([ ]|\n)  {
                /* token: nil_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[nil_kwd_pos].line=lxline;
		yylval.strinfo.pos[nil_kwd_pos].col=lxcol;

		lxcol+=4;	
                return nil_kwd;

                }


^break([ ]|\n)  {
                /* token: break_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[break_kwd_pos].line=lxline;
		yylval.strinfo.pos[break_kwd_pos].col=lxcol;

		lxcol+=5;	
                return break_kwd;

                }

[ ]break([ ]|\n)   {
                /* token: break_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[break_kwd_pos].line=lxline;
		yylval.strinfo.pos[break_kwd_pos].col=lxcol;

		lxcol+=6;	
                return break_kwd;

                }

^while([ ]|\n)  {
                /* token: while_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[while_kwd_pos].line=lxline;
		yylval.strinfo.pos[while_kwd_pos].col=lxcol;

		lxcol+=5;	
                return while_kwd;

                }

[ ]while([ ]|\n)   {
                /* token: while_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[while_kwd_pos].line=lxline;
		yylval.strinfo.pos[while_kwd_pos].col=lxcol;

		lxcol+=6;	
                return while_kwd;

                }

^do([ ]|\n)     {
                /* token: do_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[do_kwd_pos].line=lxline;
		yylval.strinfo.pos[do_kwd_pos].col=lxcol;

		lxcol+=2;	
                return do_kwd;

                }

[ ]do([ ]|\n)   {
                /* token: do_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[do_kwd_pos].line=lxline;
		yylval.strinfo.pos[do_kwd_pos].col=lxcol;

		lxcol+=3;	
                return do_kwd;

                }


^for([ ]|\n)    {
                /* token: for_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[for_kwd_pos].line=lxline;
		yylval.strinfo.pos[for_kwd_pos].col=lxcol;

		lxcol+=3;	
                return for_kwd;

                }

[ ]for([ ]|\n)  {
                /* token: for_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[for_kwd_pos].line=lxline;
		yylval.strinfo.pos[for_kwd_pos].col=lxcol;

		lxcol+=4;	
                return for_kwd;

                }

\(for([ ]|\n)  {
                /* token: for_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[for_kwd_pos].line=lxline;
		yylval.strinfo.pos[for_kwd_pos].col=lxcol;

		lxcol+=4;	
                return for_kwd;

                }

^to([ ]|\n)     {
                /* token: to_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[to_kwd_pos].line=lxline;
		yylval.strinfo.pos[to_kwd_pos].col=lxcol;

		lxcol+=2;	
                return to_kwd;

                }

[ ]to([ ]|\n)   {
                /* token: to_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[to_kwd_pos].line=lxline;
		yylval.strinfo.pos[to_kwd_pos].col=lxcol;

		lxcol+=3;	
                return to_kwd;

                }

^end([ ]|\n)    {
                /* token: end_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';
                 
                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[end_kwd_pos].line=lxline;
		yylval.strinfo.pos[end_kwd_pos].col=lxcol;

		lxcol+=3;	
                return end_kwd;

                }

[ ]end([ ]|\n)  {
                /* token: end_kwd */

                if((yytext[yyleng-1] == '\n') || (yytext[yyleng-1] == ' '))
                {
                  /* return last-char to input */
                  unput(yytext[yyleng-1]);
                  yytext[yyleng-1] = '\0';

                  /* remove first white-space */
                  /* if(*yytext == ' ')  */
                  yytext = yytext++;

                }

                fprintf(llout, "%s^KWD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[end_kwd_pos].line=lxline;
		yylval.strinfo.pos[end_kwd_pos].col=lxcol;

		lxcol+=4;	
                return end_kwd;

                }


([A-Za-z][A-Za-z0-9_]*)   {

                /* token: ident */
                fprintf(llout, "%s^IDENT(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[ident_pos].line=lxline;
		yylval.strinfo.pos[ident_pos].col=lxcol;

		lxcol+=yyleng;	
                return ident;

                }

([\/][\*])      {

                /* no token */
                fprintf(llout, "<^CSt^ ");
                lxcol+=yyleng;
                BEGIN cmtmode;
                }


<cmtmode>([\*][\/])      {

                /* no token */
                fprintf(llout, " ^CEnd^>");
                lxcol+=yyleng;
                BEGIN INITIAL;
                }


=               {

                /* Tiger type-declaration symbols are
                   handled here  (equal, colon, lbrace, rbrace, comma)
                 */

                /* token: eq_op (type equalizer, and comparator) */

                fprintf(llout, "%s^EQ_OP(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[eq_op_pos].line=lxline;
		yylval.strinfo.pos[eq_op_pos].col=lxcol;

		lxcol+=1;	
                return eq_op;

                }


:               {

                /* token: colon */
                fprintf(llout, "%s^COLON(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[colon_pos].line=lxline;
		yylval.strinfo.pos[colon_pos].col=lxcol;

		lxcol+=1;	
                return colon;
                }

\{              {

                /* token: lbrace */
                fprintf(llout, "%s^LBRACE(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[lbrace_pos].line=lxline;
		yylval.strinfo.pos[lbrace_pos].col=lxcol;

		lxcol+=1;	
                return lbrace;
                }

\}              {

                /* token: rbrace */
                fprintf(llout, "%s^RBRACE(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[rbrace_pos].line=lxline;
		yylval.strinfo.pos[rbrace_pos].col=lxcol;

		lxcol+=1;	
                return rbrace;
                }

,               {

                /* token: comma */
                fprintf(llout, "%s^COMMA(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[comma_pos].line=lxline;
		yylval.strinfo.pos[comma_pos].col=lxcol;

		lxcol+=1;	
                return comma;
                }

\(              {

                /* Tiger Function/Array (extra) declaration symbols
                   are handled here (lparan, rparan, sqLbrace, sqRbrace) 
                 */

                /* token: lparan */
                fprintf(llout, "%s^LPARAN(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[lparan_pos].line=lxline;
		yylval.strinfo.pos[lparan_pos].col=lxcol;

		lxcol+=1;	
                return lparan;
                }

\)              {

                /* token: rparan */
                fprintf(llout, "%s^RPARAN(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[rparan_pos].line=lxline;
		yylval.strinfo.pos[rparan_pos].col=lxcol;

		lxcol+=1;	
                return rparan;
                }

\[             {

                /* token: sqLbrace */
                fprintf(llout, "%s^sqLbrace(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[sqLbrace_pos].line=lxline;
		yylval.strinfo.pos[sqLbrace_pos].col=lxcol;

		lxcol+=1;	
                return sqLbrace;
                }

\]             {

                /* token: sqRbrace */
                fprintf(llout, "%s^sqRbrace(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[sqRbrace_pos].line=lxline;
		yylval.strinfo.pos[sqRbrace_pos].col=lxcol;

		lxcol+=1;	
                return sqRbrace;
                }

\<\>            {

                /* token: not_eq */
                fprintf(llout, "%s^NOT_EQ_OP(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[not_eq_pos].line=lxline;
		yylval.strinfo.pos[not_eq_pos].col=lxcol;

		lxcol+=2;	
                return not_eq;
                }

\>              {

                /* token: gr_op */
                fprintf(llout, "%s^GR_OP(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[gr_op_pos].line=lxline;
		yylval.strinfo.pos[gr_op_pos].col=lxcol;

		lxcol+=1;	
                return gr_op;
                }

\<              {

                /* token: le_op */
                fprintf(llout, "%s^LE_OP(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[le_op_pos].line=lxline;
		yylval.strinfo.pos[le_op_pos].col=lxcol;

		lxcol+=1;	
                return le_op;
                }

\<=             {

                /* token: le_eq_op */
                fprintf(llout, "%s^LE_EQ_OP(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[le_eq_op_pos].line=lxline;
		yylval.strinfo.pos[le_eq_op_pos].col=lxcol;

		lxcol+=2;	
                return le_eq_op;
                }

\>=             {

                /* token: gr_eq_op */
                fprintf(llout, "%s^GR_EQ_OP(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[gr_eq_op_pos].line=lxline;
		yylval.strinfo.pos[gr_eq_op_pos].col=lxcol;

		lxcol+=2;	
                return gr_eq_op;
                }

\+              {

                /* token: add_op */
                fprintf(llout, "%s^ADD_OP(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[add_op_pos].line=lxline;
		yylval.strinfo.pos[add_op_pos].col=lxcol;

		lxcol+=1;	
                return add_op;
                }

-               {

                /* token: minus_op (two tokens: negation (unary) and subtraction (binary) */
                fprintf(llout, "%s^MINUS_OP(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[minus_op_pos].line=lxline;
		yylval.strinfo.pos[minus_op_pos].col=lxcol;

		lxcol+=1;	
                return minus_op;
                }

\*              {

                /* token: mult_op (no pointers) */
                fprintf(llout, "%s^MULT_OP(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[mult_op_pos].line=lxline;
		yylval.strinfo.pos[mult_op_pos].col=lxcol;

		lxcol+=1;	
                return mult_op;
                }

\/               {

                /* token: div_op */
                fprintf(llout, "%s^DIV_OP(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[div_op_pos].line=lxline;
		yylval.strinfo.pos[div_op_pos].col=lxcol;

		lxcol+=1;	
                return div_op;
                }

&               {

                /* token: and_op (logical, no address reference) */
                fprintf(llout, "%s^AND_OP(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[and_op_pos].line=lxline;
		yylval.strinfo.pos[and_op_pos].col=lxcol;

		lxcol+=1;	
                return and_op;
                }

\|              {

                /* token: or_op */
                fprintf(llout, "%s^OR_OP(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[or_op_pos].line=lxline;
		yylval.strinfo.pos[or_op_pos].col=lxcol;

		lxcol+=1;	
                return or_op;
                }

;               {

                /* token: semicolon */
                fprintf(llout, "%s^SEMICOLON(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[semicolon_pos].line=lxline;
		yylval.strinfo.pos[semicolon_pos].col=lxcol;

		lxcol+=1;	
                return semicolon;
                }

\"              {

                /* token: dquote */
                fprintf(llout, "%s^DQUOTE(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[dquote_pos].line=lxline;
		yylval.strinfo.pos[dquote_pos].col=lxcol;

		lxcol+=1;	
                return dquote;
                }

'               {

                /* token: squote */
                fprintf(llout, "%s^SQUOTE(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[squote_pos].line=lxline;
		yylval.strinfo.pos[squote_pos].col=lxcol;

		lxcol+=1;	
                return squote;
                }

:=              {

                /* token: asn_op */
                fprintf(llout, "%s^ASN_OP(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[asn_op_pos].line=lxline;
		yylval.strinfo.pos[asn_op_pos].col=lxcol;

		lxcol+=2;	
                return asn_op;
                }

[0-9]*          {

                /* token: pure_num */
                fprintf(llout, "%s^PURE_NUM(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[pure_num_pos].line=lxline;
		yylval.strinfo.pos[pure_num_pos].col=lxcol;

		lxcol+=yyleng;	
                return pure_num;
                }

\"[^"]*\"       {

                /* token: pure_str */
                fprintf(llout, "%s^PURE_STR(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[pure_str_pos].line=lxline;
		yylval.strinfo.pos[pure_str_pos].col=lxcol;

		lxcol+=yyleng;	
                return pure_str;
                }

\.              {
           
                /* token: period */
                fprintf(llout, "%s^PERIOD(%d,%d)^ ", yytext, lxline, lxcol);
                yylval.strinfo.strval = strdup(yytext);
		yylval.strinfo.pos[period_pos].line=lxline;
		yylval.strinfo.pos[period_pos].col=lxcol;

		lxcol+=1;	
                return period;

                }

.|\n            {
                	if(yytext[yyleng-1] == '\n') {
                	lxline++;
	       		lxcol=1;
                	}
                	else {
			lxcol++;
               		}

                fprintf(llout, "%s", yytext);
                }

%%


/* 1. TIG keywords */

/* let, type, var, function, int, string, array, of, if, then, else,
   in, nil, break, while, do, for, to, end */

/* 2. TIG type declaration symbols (other) */

/*  equal =, colon :, lbrace {, rbrace }, comma , */

/* 3. TIG extra symbols in function/array declaration */

/*  lparan (, rparan ), sqLbrace [, sqRbrace  */

/* 4. TIG other operators & symbols */

/*  negation -, comparison =,<>, >, <, <=, >=, arithmetic +,-,*,/, logic
    &, |, assignment :=, semicolon ; double-quote ",  single-quote ' */

/* 5. TIG literals and identifiers */

/*   int_literal (number), string_literal (double-quotes),
     other string literals are: \n, \t, \^c, \ddd, \", \\, \f___f\,
     identifier (standard variable)
 */

/*   NOTE: Though the general reg-exp for a keyword is:

     (^[ ]*|[ ]+)let(\n|[ ]+)              -> for keyword 'let'

     but simply writing 'let' has the same effect if
     all the sub-childs are declared before the parent (Id)
     in lex, carefully.

     one disadvantage in using the complete reg-exp is that
     all the extra tokens searched will also become part of the
     string and they will need to be stripped off, this may increase
     the lexing time.

     >> This fails at --notkwd-let .. such a thing should not be
     classified at all (here lex classifies it into an ID and a KWD).

     Solution:

     1. Keyword will begin with a sol OR a space
     2. Keyword will end with a space OR eol (\n)

     Thus, we have

     (^|[ ])lex([ ]|\n|$)

     However, this still misses the case:  let let

     (the second let's first char is 'eaten' by the prev let).

     Therefore the trailing space should be returned to the input by lex,
     in case of a keyword.

     Thus,

     1. Keyword will begin with a sol OR a space
     2. Keyword will end with a space OR eol (\n)
     3. Lex should push-back the end-char of the token back to input.
     4. Strip off the leading white-space from the keyword.

*/



