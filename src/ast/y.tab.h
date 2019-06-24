/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    let_kwd = 258,
    type_kwd = 259,
    var_kwd = 260,
    fn_kwd = 261,
    int_kwd = 262,
    string_kwd = 263,
    array_kwd = 264,
    of_kwd = 265,
    if_kwd = 266,
    then_kwd = 267,
    else_kwd = 268,
    in_kwd = 269,
    nil_kwd = 270,
    break_kwd = 271,
    while_kwd = 272,
    do_kwd = 273,
    for_kwd = 274,
    to_kwd = 275,
    end_kwd = 276,
    ident = 277,
    eq_op = 278,
    colon = 279,
    lbrace = 280,
    rbrace = 281,
    comma = 282,
    lparan = 283,
    rparan = 284,
    sqLbrace = 285,
    sqRbrace = 286,
    not_eq = 287,
    gr_op = 288,
    le_op = 289,
    le_eq_op = 290,
    gr_eq_op = 291,
    add_op = 292,
    minus_op = 293,
    mult_op = 294,
    div_op = 295,
    and_op = 296,
    or_op = 297,
    semicolon = 298,
    dquote = 299,
    squote = 300,
    asn_op = 301,
    pure_num = 302,
    pure_str = 303,
    period = 304,
    false_type_kwd = 305,
    false_function_kwd = 306
  };
#endif
/* Tokens.  */
#define let_kwd 258
#define type_kwd 259
#define var_kwd 260
#define fn_kwd 261
#define int_kwd 262
#define string_kwd 263
#define array_kwd 264
#define of_kwd 265
#define if_kwd 266
#define then_kwd 267
#define else_kwd 268
#define in_kwd 269
#define nil_kwd 270
#define break_kwd 271
#define while_kwd 272
#define do_kwd 273
#define for_kwd 274
#define to_kwd 275
#define end_kwd 276
#define ident 277
#define eq_op 278
#define colon 279
#define lbrace 280
#define rbrace 281
#define comma 282
#define lparan 283
#define rparan 284
#define sqLbrace 285
#define sqRbrace 286
#define not_eq 287
#define gr_op 288
#define le_op 289
#define le_eq_op 290
#define gr_eq_op 291
#define add_op 292
#define minus_op 293
#define mult_op 294
#define div_op 295
#define and_op 296
#define or_op 297
#define semicolon 298
#define dquote 299
#define squote 300
#define asn_op 301
#define pure_num 302
#define pure_str 303
#define period 304
#define false_type_kwd 305
#define false_function_kwd 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 36 "tig.yac" /* yacc.c:1909  */


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
 

#line 174 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
