/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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




/* Copy the first part of user declarations.  */
#line 1 "tig.yac"

    /* The parser for the tiger language */

    /* There are no semantic actions associated with the grammar
       rules in this version of the parser */

    /* write additional comments here, in a
       structured format
     */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "absyn.h" 
#include "absyn_malloc.h"
#include "pos_def.h"
#include "prn_exp.h"	

FILE *llout;
extern FILE *yyin, *yyout;
extern int lxline; 

/* add this to avoid gcc's implicit function prototype legacy warning */
// extern int yylex(void); 
// #define yyerror  goto yyerrorlab

/* add to ignore macbook compilation errors with the lex/yacc version I'm using (implicit declarations) */
int yylex(void);
void yyerror(char* s);

/* sockets between lex n yacc */
extern int SEND_FALSE_FUNCTION;
extern int NULL_DECLIST;

#define Restore_MutRecState               if( (SEND_FALSE_FUNCTION=A_popMutRecState()) < 0)\
                                          { printf("<PARSE> : Internal error in restoring mutrec state\n"); \
                                            exit(0); }

/* forward definition of strmemcat */
char *strmemcat(char* source, char* dest);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 44 "tig.yac"
{

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
/* Line 193 of yacc.c.  */
#line 259 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 272 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   198

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  180

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    11,    14,    17,    20,    22,    24,
      26,    29,    31,    36,    38,    42,    46,    48,    54,    58,
      60,    62,    64,    67,    69,    76,    84,    93,   103,   108,
     113,   120,   125,   131,   135,   142,   146,   150,   154,   158,
     162,   166,   170,   174,   178,   182,   186,   190,   193,   195,
     197,   199,   201,   205,   207,   212,   216,   218,   222,   227,
     231,   233,   237,   241,   244,   248,   252,   254,   258,   260,
     264,   266,   270,   272,   276,   278,   282,   284,   288,   290,
     294,   296,   300,   302,   306,   308,   313,   318,   327
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    -1,     3,    55,    14,    73,    21,
      -1,    56,    55,    -1,    61,    55,    -1,    63,    55,    -1,
      61,    -1,    56,    -1,    63,    -1,    56,    57,    -1,    50,
      -1,     4,    22,    23,    58,    -1,    22,    -1,     9,    10,
      60,    -1,    25,    59,    26,    -1,    60,    -1,    59,    27,
      22,    24,    60,    -1,    22,    24,    60,    -1,     7,    -1,
       8,    -1,    22,    -1,    61,    62,    -1,    51,    -1,     6,
      22,    28,    29,    23,    73,    -1,     6,    22,    28,    59,
      29,    23,    73,    -1,     6,    22,    28,    29,    24,    60,
      23,    73,    -1,     6,    22,    28,    59,    29,    24,    60,
      23,    73,    -1,     5,    22,    46,    67,    -1,     5,    22,
      46,    66,    -1,     5,    22,    24,    60,    46,    67,    -1,
      60,    25,    65,    26,    -1,    65,    27,    22,    23,    67,
      -1,    22,    23,    67,    -1,    30,    67,    31,    60,    10,
      67,    -1,    68,    37,    67,    -1,    68,    38,    67,    -1,
      68,    39,    67,    -1,    68,    40,    67,    -1,    68,    23,
      67,    -1,    68,    32,    67,    -1,    68,    33,    67,    -1,
      68,    34,    67,    -1,    68,    36,    67,    -1,    68,    35,
      67,    -1,    68,    41,    67,    -1,    68,    42,    67,    -1,
      38,    67,    -1,    68,    -1,    47,    -1,    48,    -1,    69,
      -1,    28,    67,    29,    -1,    70,    -1,    69,    30,    67,
      31,    -1,    69,    49,    22,    -1,    22,    -1,    22,    28,
      29,    -1,    22,    28,    71,    29,    -1,    71,    27,    67,
      -1,    67,    -1,    69,    46,    72,    -1,    69,    46,    67,
      -1,    28,    29,    -1,    28,    74,    29,    -1,    74,    43,
      72,    -1,    72,    -1,    74,    43,    75,    -1,    75,    -1,
      74,    43,    78,    -1,    78,    -1,    74,    43,    76,    -1,
      76,    -1,    74,    43,    77,    -1,    77,    -1,    74,    43,
      70,    -1,    70,    -1,    74,    43,    54,    -1,    54,    -1,
      74,    43,    16,    -1,    16,    -1,    74,    43,    64,    -1,
      64,    -1,    74,    43,    67,    -1,    67,    -1,    11,    67,
      12,    73,    -1,    17,    67,    18,    73,    -1,    19,    22,
      46,    67,    20,    67,    18,    73,    -1,    11,    67,    12,
      73,    13,    73,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   150,   150,   164,   209,   220,   233,   245,   258,   284,
     314,   324,   337,   360,   368,   383,   402,   412,   433,   450,
     451,   452,   465,   474,   485,   520,   555,   592,   636,   660,
     681,   710,   732,   754,   782,   825,   853,   878,   904,   932,
     959,   986,  1013,  1040,  1067,  1095,  1121,  1149,  1159,  1181,
    1199,  1217,  1231,  1248,  1261,  1285,  1304,  1322,  1342,  1362,
    1377,  1397,  1415,  1450,  1469,  1499,  1517,  1524,  1537,  1544,
    1557,  1564,  1577,  1584,  1597,  1604,  1617,  1644,  1657,  1667,
    1683,  1696,  1708,  1717,  1729,  1745,  1769,  1794,  1832
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "let_kwd", "type_kwd", "var_kwd",
  "fn_kwd", "int_kwd", "string_kwd", "array_kwd", "of_kwd", "if_kwd",
  "then_kwd", "else_kwd", "in_kwd", "nil_kwd", "break_kwd", "while_kwd",
  "do_kwd", "for_kwd", "to_kwd", "end_kwd", "ident", "eq_op", "colon",
  "lbrace", "rbrace", "comma", "lparan", "rparan", "sqLbrace", "sqRbrace",
  "not_eq", "gr_op", "le_op", "le_eq_op", "gr_eq_op", "add_op", "minus_op",
  "mult_op", "div_op", "and_op", "or_op", "semicolon", "dquote", "squote",
  "asn_op", "pure_num", "pure_str", "period", "false_type_kwd",
  "false_function_kwd", "$accept", "tig_root", "let_decl", "decls",
  "type_decls", "type_decl", "ty_rhs", "tyfields", "typeid", "func_decls",
  "func_decl", "var_decl", "rec_defn", "rec_defn_param", "array_defn",
  "expv", "expliteral", "lvalue", "func_call", "parameter_list", "asn_exp",
  "expseq", "explist", "if_then_decl", "while_decl", "for_decl",
  "if_then_else_decl", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    55,    55,    55,    55,    55,    55,
      56,    56,    57,    58,    58,    58,    58,    59,    59,    60,
      60,    60,    61,    61,    62,    62,    62,    62,    63,    63,
      63,    64,    65,    65,    66,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    68,    68,    68,    69,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    76,    77,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     5,     2,     2,     2,     1,     1,     1,
       2,     1,     4,     1,     3,     3,     1,     5,     3,     1,
       1,     1,     2,     1,     6,     7,     8,     9,     4,     4,
       6,     4,     5,     3,     6,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     1,     1,
       1,     1,     3,     1,     4,     3,     1,     3,     4,     3,
       1,     3,     3,     2,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     4,     4,     8,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,    11,    23,     0,     8,     7,
       9,     1,     0,     0,     0,     4,    10,     0,     5,    22,
       6,     0,     0,     0,     0,     0,     0,    19,    20,    21,
       0,    56,     0,     0,     0,    49,    50,    29,    28,    48,
      51,    53,     0,    80,     0,     0,    56,    63,    78,     0,
      82,    84,    51,    53,    66,     0,    68,    72,    74,    70,
       3,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    64,     0,     0,
      13,     0,    12,    16,     0,     0,     0,    30,    57,    60,
       0,    52,     0,    39,    40,    41,    42,    44,    43,    35,
      36,    37,    38,    45,    46,     0,    55,     0,     0,     0,
       0,     0,    62,    61,    79,    77,    81,    83,    53,    65,
      67,    71,    73,    69,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,    54,    85,    86,     0,     0,    31,
       0,    14,    15,    18,    24,     0,     0,     0,     0,    59,
       0,     0,     0,    33,     0,     0,     0,    25,     0,    34,
      88,     0,     0,    26,    17,     0,     0,    32,    27,    87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     7,     8,    16,    92,    96,    49,     9,
      19,    10,    50,   121,    37,    38,    39,    40,    41,   100,
      54,    24,    55,    56,    57,    58,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -76
static const yytype_int16 yypact[] =
{
       4,    21,    61,   -76,   -14,   -76,   -76,    63,     9,    19,
      21,   -76,   -19,    53,    67,   -76,   -76,    75,   -76,   -76,
     -76,    22,   104,    76,    64,    79,    78,   -76,   -76,   -76,
      81,   108,   -16,   -16,   -16,   -76,   -76,   -76,   -76,   145,
     -15,   -76,   -16,   -76,   -16,    87,     8,   -76,   -76,   118,
     -76,   -76,   -26,   -76,   -76,    51,   -76,   -76,   -76,   -76,
     -76,    66,     6,   -16,   128,   115,   114,   -76,   -16,   -16,
     -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   124,   141,   136,   112,   137,   -16,   -76,   100,   150,
     -76,   139,   -76,   -76,   138,    -7,    49,   -76,   -76,   -76,
      83,   -76,    22,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   133,   -76,    53,    53,   -16,
     142,    94,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,    22,   103,    22,    53,    22,   147,
     117,   -16,   -76,   157,   -76,   158,   -76,   152,   -16,   -76,
     148,   -76,   -76,   -76,   -76,   151,   149,    53,    22,   -76,
     -16,    53,   -16,   -76,   165,    53,    22,   -76,   166,   -76,
     -76,   172,   -16,   -76,   -76,    53,    53,   -76,   -76,   -76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,   -21,    29,   -76,   -76,   -76,   101,    -3,   -76,
     -76,   -76,   105,   -76,   -76,   -23,   -76,   -22,   -20,   -76,
      27,   -75,   -76,   106,   107,   109,   110
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -22
static const yytype_int16 yytable[] =
{
      51,    52,    48,    53,    80,    21,    31,     1,    12,    65,
      66,    67,    32,    14,     4,    80,   137,   138,    30,    82,
      86,    83,    34,    81,     4,    17,     4,    22,    94,    27,
      28,    35,    36,   -21,    81,    95,    64,    15,    18,    20,
      97,    99,   145,   146,    29,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    93,     5,
       6,    11,   154,   122,    52,   127,    52,   125,   128,     5,
       6,     5,     6,    27,    28,    89,   139,    13,   140,     1,
      87,    23,   167,    27,    28,    60,   170,    42,    90,    25,
     173,    91,    43,    44,    88,    45,   147,    26,    46,   143,
     178,   179,    61,     1,    32,    47,    62,    27,    28,    84,
     141,    42,   142,   123,    34,   129,   124,    44,   159,    45,
     149,   150,    46,    35,    36,   163,    31,    63,    32,   152,
     139,   151,    32,   153,    33,   155,    64,   169,    34,   171,
     157,   158,    34,    85,   101,   102,   116,    35,    36,   177,
      31,    35,    36,   117,   118,   168,    32,    98,   119,   120,
     134,    94,   136,   174,   144,   148,    34,   160,    68,   156,
     164,   161,   162,   166,   165,    35,    36,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,   172,   175,
     176,     0,   135,   126,   130,   131,     0,   132,   133
};

static const yytype_int16 yycheck[] =
{
      23,    23,    23,    23,    30,    24,    22,     3,    22,    32,
      33,    34,    28,     4,     5,    30,    23,    24,    21,    42,
      46,    44,    38,    49,     5,     6,     5,    46,    22,     7,
       8,    47,    48,    25,    49,    29,    28,     8,     9,    10,
      63,    64,   117,   118,    22,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    61,    50,
      51,     0,   137,    86,    86,    88,    88,    88,    88,    50,
      51,    50,    51,     7,     8,     9,    27,    14,    29,     3,
      29,    28,   157,     7,     8,    21,   161,    11,    22,    22,
     165,    25,    16,    17,    43,    19,   119,    22,    22,   102,
     175,   176,    23,     3,    28,    29,    28,     7,     8,    22,
      27,    11,    29,    86,    38,    88,    16,    17,   141,    19,
      26,    27,    22,    47,    48,   148,    22,    46,    28,    26,
      27,   134,    28,   136,    30,   138,    28,   160,    38,   162,
      23,    24,    38,    25,    29,    31,    22,    47,    48,   172,
      22,    47,    48,    12,    18,   158,    28,    29,    46,    22,
      10,    22,    24,   166,    31,    23,    38,    10,    23,    22,
      22,    13,    20,    24,    23,    47,    48,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    23,    23,
      18,    -1,    91,    88,    88,    88,    -1,    88,    88
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    53,    54,     5,    50,    51,    55,    56,    61,
      63,     0,    22,    14,     4,    55,    57,     6,    55,    62,
      55,    24,    46,    28,    73,    22,    22,     7,     8,    22,
      60,    22,    28,    30,    38,    47,    48,    66,    67,    68,
      69,    70,    11,    16,    17,    19,    22,    29,    54,    60,
      64,    67,    69,    70,    72,    74,    75,    76,    77,    78,
      21,    23,    28,    46,    28,    67,    67,    67,    23,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      30,    49,    67,    67,    22,    25,    46,    29,    43,     9,
      22,    25,    58,    60,    22,    29,    59,    67,    29,    67,
      71,    29,    31,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    22,    12,    18,    46,
      22,    65,    67,    72,    16,    54,    64,    67,    70,    72,
      75,    76,    77,    78,    10,    59,    24,    23,    24,    27,
      29,    27,    29,    60,    31,    73,    73,    67,    23,    26,
      27,    60,    26,    60,    73,    60,    22,    23,    24,    67,
      10,    13,    20,    67,    22,    23,    24,    73,    60,    67,
      73,    67,    23,    73,    60,    23,    18,    67,    73,    73
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 150 "tig.yac"
    {

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<PARSE> AST ROOT REACHED at : %s\n", (yyval.strinfo.strval));
#endif
                           /* take out the final a_exp from stack ; this is the
                            * root pointer of the abstract syntax tree.
                            */

			   AST_root = A_popexp();

                           }
    break;

  case 3:
#line 164 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), "\n[Type]\n");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (5)].strinfo.strval));
                          
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), "\n");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (5)].strinfo.strval));
                          
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), "\n[Body]\n");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (5)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), "\n");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(5) - (5)].strinfo.strval));
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), "\n[END]\n\n");

                           Restore_MutRecState;
                           SEND_FALSE_FUNCTION=0;
                           NULL_DECLIST=1;

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<PARSE> EVALD a LET_decl (occurance %d,%d): %s\n", 
                           yylval.strinfo.pos[let_kwd_pos].line, 
                           yylval.strinfo.pos[let_kwd_pos].col, (yyval.strinfo.strval));
#endif

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[let_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[let_kwd_pos].col); 

                           /* pop decList and seqList(exp) here .. popexp shd retrieve SeqExp here */
                           A_pushexp(A_LetExp(absyn_pos, A_popLetdecList(), A_popexp()));

                           }
    break;

  case 4:
#line 210 "tig.yac"
    {
                             	/* pop tyList and add to current decList */
                             	/* (note: absyn_pos is not defined ..) */
#ifdef YDUMP_TYLIST
                           	fprintf(yyout, "<PARSE> MAIN TYPE DECL CONSTRUCT CONTD\n");
                             	prn_atyList(A_peeptyList(0));
#endif
                             	//absyn_decList = A_DecList(A_TypeDec(absyn_pos, A_poptyList()),absyn_decList);
                             	A_pushLetdecList(A_DecList(A_TypeDec(absyn_pos, A_poptyList()),A_popLetdecList()));
                           }
    break;

  case 5:
#line 220 "tig.yac"
    {

                           /* TO BE TESTED */
                            /* absyn_pos not defined */

#ifdef YDUMPFN
                                fprintf(yyout, "\n<PARSE> EVALD a func_decls decls construct: %s\n", (yyval.strinfo.strval));

#endif
                                //absyn_decList = A_DecList(A_FunctionDec(absyn_pos, A_popfnList()), absyn_decList);
                                A_pushLetdecList(A_DecList(A_FunctionDec(absyn_pos, A_popfnList()), A_popLetdecList()));

                           }
    break;

  case 6:
#line 234 "tig.yac"
    {
#ifdef YDUMP_VLIST
                                fprintf(yyout, "<PARSE> VARLIST - ALSO ADDED (%s)\n",A_peepVardec(0)->dectype.vardec.var);
                                fprintf(yyout, "<PARSE> Expression associated with this var is as follows:\n");
                                prn_aexp(A_peepVardec(0)->dectype.vardec.init); 
                                fprintf(yyout,"<PARSE> END-OF-EXP\n\n");
#endif
                                //absyn_decList = A_DecList(A_popVardec(), absyn_decList);
                                A_pushLetdecList(A_DecList(A_popVardec(), A_popLetdecList()));

                           }
    break;

  case 7:
#line 245 "tig.yac"
    { 
                           /* TO BE TESTED */

                           /* maybe need to add the NULL_DECLIST syntax  .. why was it added really?
                            * investigate ..
                            */
#ifdef YDUMPFN
                                fprintf(yyout, "\n<PARSE> EVALD a func_decls (func_decls only) construct: %s\n", (yyval.strinfo.strval));

#endif
                                //absyn_decList = A_DecList(A_FunctionDec(absyn_pos, A_popfnList()), NULL);
                                A_pushLetdecList(A_DecList(A_FunctionDec(absyn_pos, A_popfnList()), NULL));
                           }
    break;

  case 8:
#line 259 "tig.yac"
    {
			     	/* pop tyList and add to a null decList */
                             	/* (note: absyn_pos is not defined ..) */

#ifdef YDUMP_TYLIST
                             	fprintf(yyout, "<PARSE> MAIN (type_decls) TYPE DECL START\n");
                             	prn_atyList(A_peeptyList(0));
#endif

                             	if(NULL_DECLIST) {
#ifdef YDUMP_TYLIST
                             	fprintf(yyout, "<PARSE> type_decls with NULL_DECLIST \n");
#endif
                             	//absyn_decList = A_DecList(A_TypeDec(absyn_pos, A_poptyList()),NULL);
                             	 A_pushLetdecList(A_DecList(A_TypeDec(absyn_pos, A_poptyList()),NULL));
                             	NULL_DECLIST=0;
                             	}
		             	else {
#ifdef YDUMP_TYLIST
                             	fprintf(yyout, "<PARSE> type_decls without NULL_DECLIST \n");
#endif
                             	//absyn_decList = A_DecList(A_TypeDec(absyn_pos, A_poptyList()),absyn_decList);
                             	A_pushLetdecList(A_DecList(A_TypeDec(absyn_pos, A_poptyList()),A_popLetdecList()));
                             	}
                           }
    break;

  case 9:
#line 285 "tig.yac"
    {
			   	if(NULL_DECLIST) {
#ifdef YDUMP_VLIST
                                fprintf(yyout, "<PARSE> VARLIST (LOOKS FIRST), ADDED TO NULL (%s)\n",
                                A_peepVardec(0)->dectype.vardec.var);
                                fprintf(yyout, "<PARSE> Expression associated with this var is as follows:\n");
                                prn_aexp(A_peepVardec(0)->dectype.vardec.init); 
                                fprintf(yyout,"<PARSE> END-OF-EXP\n\n");
#endif
                                //absyn_decList = A_DecList(A_popVardec(), NULL);
                                A_pushLetdecList(A_DecList(A_popVardec(), NULL));
			        NULL_DECLIST=0;
                                } else {
#ifdef YDUMP_VLIST
                                fprintf(yyout, "<PARSE> VARLIST (LOOKS FIRST), BUT ADDED TO OLD (%s)\n",
                                A_peepVardec(0)->dectype.vardec.var);
                                fprintf(yyout, "<PARSE> Expression associated with this var is as follows:\n");
                                prn_aexp(A_peepVardec(0)->dectype.vardec.init); 
                                fprintf(yyout,"<PARSE> END-OF-EXP\n\n");
#endif
                                //absyn_decList = A_DecList(A_popVardec(), absyn_decList);
                                A_pushLetdecList(A_DecList(A_popVardec(), A_popLetdecList()));
                                }
                           }
    break;

  case 10:
#line 314 "tig.yac"
    { 
                           
		          /* pop, affect, push */
                          A_pushtyList(A_NametyList( absyn_namety, A_poptyList()));

#ifdef YDUMPMRC
			  fprintf(yyout, "<PARSE> GOING IN TYPE FOR symbol %s \n", absyn_namety->sym); 
#endif
                           }
    break;

  case 11:
#line 324 "tig.yac"
    { 

			   /* create new level */
			   A_pushtyList(NULL);
#ifdef YDUMPMRC
			   fprintf(yyout, "<PARSE> GOING IN TYPE (FALSE, New Level) ;)\n"); 
#endif
                           }
    break;

  case 12:
#line 337 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (4)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (4)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (4)].strinfo.strval));
                         
		           absyn_pos->line = A_intdup(yylval.strinfo.pos[type_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[type_kwd_pos].col); 
                           absyn_namety    = A_Namety((yyvsp[(2) - (4)].strinfo.strval), absyn_ty_rhs);

                           /* store the first position in the type list
                              for the declaration sequence (A_DecList) */
                           
#ifdef YDUMPTXT
                           fprintf(yyout, "\n<PARSE> EVALD a type_decl: %s\n", (yyval.strinfo.strval));                            
#endif
                           }
    break;

  case 13:
#line 360 "tig.yac"
    {

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[ident_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[ident_pos].col); 

                           absyn_ty_rhs = A_nameTy(absyn_pos, (yyvsp[(1) - (1)].strinfo.strval));

                           }
    break;

  case 14:
#line 369 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[of_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[of_kwd_pos].col); 

                           absyn_ty_rhs = A_ArrayTy(absyn_pos, (yyvsp[(3) - (3)].strinfo.strval));
                           
                           }
    break;

  case 15:
#line 384 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[lbrace_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[lbrace_pos].col); 

                           absyn_ty_rhs = A_RecordTy(absyn_pos, absyn_fieldList);

#ifdef YDUMPTXT
                           prn_afieldList(absyn_ty_rhs->which.rectype.record);
#endif

                           }
    break;

  case 16:
#line 403 "tig.yac"
    {

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[ident_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[ident_pos].col); 

                           absyn_ty_rhs = A_nameTy(absyn_pos, (yyvsp[(1) - (1)].strinfo.strval));
                           }
    break;

  case 17:
#line 413 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (5)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (5)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (5)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(5) - (5)].strinfo.strval));

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[colon_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[colon_pos].col); 

                           absyn_fieldList = A_FieldList(A_Field(absyn_pos, (yyvsp[(3) - (5)].strinfo.strval), (yyvsp[(5) - (5)].strinfo.strval)), absyn_fieldList);
                           }
    break;

  case 18:
#line 434 "tig.yac"
    {

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[colon_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[colon_pos].col); 

                           absyn_fieldList = NULL;
                           absyn_fieldList = A_FieldList(A_Field(absyn_pos, (yyvsp[(1) - (3)].strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval)), absyn_fieldList);

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

                           }
    break;

  case 22:
#line 465 "tig.yac"
    { 

#ifdef YDUMPMRCF
                           fprintf(yyout, "<PARSE> GOING IN FUNCTION\n"); 
#endif
			   /* push to the current PMR list in the stack */
                          A_pushfnList(A_FundecList(absyn_fundec, A_popfnList()));

                           }
    break;

  case 23:
#line 474 "tig.yac"
    { 

#ifdef YDUMPMRCF
                           fprintf(yyout, "<PARSE> GOING IN FUNCTION (FALSE, New Level) (F)\n"); 
#endif
	                  /* create a new list of PMR stack level */
                          A_pushfnList(NULL);

                           }
    break;

  case 24:
#line 485 "tig.yac"
    {

                           /* 1. a procedure without input parameters */

                           /* mark the position */
		           absyn_pos->line = A_intdup(yylval.strinfo.pos[fn_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[fn_kwd_pos].col); 

                           absyn_fundec = A_Fundec(absyn_pos, (yyvsp[(1) - (6)].strinfo.strval), NULL, NULL, A_popexp());

                           /* collect for debug */
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (6)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (6)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (6)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(5) - (6)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(6) - (6)].strinfo.strval));


#ifdef YDUMPFN
                           fprintf(yyout, "\n<PARSE> EVALD a function_decl (no input, no output): %s\n", (yyval.strinfo.strval));

#endif
                           }
    break;

  case 25:
#line 520 "tig.yac"
    {

                           /* mark the position */
		           absyn_pos->line = A_intdup(yylval.strinfo.pos[fn_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[fn_kwd_pos].col); 

                           /* (check if absyn_fieldList works at this point, vs a stack of same) */
                           absyn_fundec = A_Fundec(absyn_pos, (yyvsp[(1) - (7)].strinfo.strval), absyn_fieldList, NULL, A_popexp());

                           /* collect for debug */
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (7)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (7)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (7)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(5) - (7)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(6) - (7)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(7) - (7)].strinfo.strval));

#ifdef YDUMPFN
                           fprintf(yyout, "\n<PARSE> EVALD a function_decl (some input, no output): %s\n", (yyval.strinfo.strval));
#endif
                           }
    break;

  case 26:
#line 555 "tig.yac"
    {

                           /* mark the position */
		           absyn_pos->line = A_intdup(yylval.strinfo.pos[fn_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[fn_kwd_pos].col); 

                           absyn_fundec = A_Fundec(absyn_pos, (yyvsp[(1) - (8)].strinfo.strval), NULL, (yyvsp[(6) - (8)].strinfo.strval), A_popexp());

                           /* collect for debug */
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (8)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (8)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (8)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(5) - (8)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(6) - (8)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(7) - (8)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(8) - (8)].strinfo.strval));

#ifdef YDUMPFN
                           fprintf(yyout, "\n<PARSE> EVALD a function_decl (no input, some output): %s\n", (yyval.strinfo.strval));
#endif
                           }
    break;

  case 27:
#line 592 "tig.yac"
    {

                           /* mark the position */
		           absyn_pos->line = A_intdup(yylval.strinfo.pos[fn_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[fn_kwd_pos].col); 

                           /* (check if absyn_fieldList works at this point, vs a stack of same) */
                           absyn_fundec = A_Fundec(absyn_pos, (yyvsp[(1) - (9)].strinfo.strval), absyn_fieldList, (yyvsp[(7) - (9)].strinfo.strval), A_popexp());

                           /* collect for debug */
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (9)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (9)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (9)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(5) - (9)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(6) - (9)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(7) - (9)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(8) - (9)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(9) - (9)].strinfo.strval));

#ifdef YDUMPFN
                           fprintf(yyout, "\n<PARSE> EVALD a function_decl (some input, some output): %s\n", (yyval.strinfo.strval));
#endif
                           }
    break;

  case 28:
#line 636 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (4)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (4)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (4)].strinfo.strval));

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[var_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[var_kwd_pos].col); 
                           A_pushVardec(A_VarDec(absyn_pos, (yyvsp[(2) - (4)].strinfo.strval), "undefined", A_popexp(0)));

#ifdef YDUMP_VLIST
                           fprintf(yyout, "\n<PARSE> EVALD a var_decl (type expv): %s\n", (yyval.strinfo.strval));
#ifdef YDUMPTXT
                           fprintf(yyout, "<PARSE> TEST: %s\n", A_peepVardec(0)->dectype.vardec.var);
                           fprintf(yyout, "<PARSE> TEST (pos line IS WRONG): %d\n", *(A_peepVardec(0)->pos->line));
#endif
#endif
                                                        }
    break;

  case 29:
#line 660 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (4)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (4)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (4)].strinfo.strval));

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[var_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[var_kwd_pos].col); 
                           A_pushVardec(A_VarDec(absyn_pos, (yyvsp[(2) - (4)].strinfo.strval), "array_type", A_popexp()));

#ifdef YDUMP_VLIST
                           fprintf(yyout, "\n<PARSE> EVALD a var_decl (type array_defn): %s\n", (yyval.strinfo.strval));
#endif
                                                        }
    break;

  case 30:
#line 681 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (6)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (6)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (6)].strinfo.strval)); 

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(5) - (6)].strinfo.strval));
                           
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(6) - (6)].strinfo.strval));

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[var_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[var_kwd_pos].col); 
                           A_pushVardec(A_VarDec(absyn_pos, (yyvsp[(2) - (6)].strinfo.strval), (yyvsp[(4) - (6)].strinfo.strval), A_popexp()));

#ifdef YDUMP_VLIST
                           fprintf(yyout, "\n<PARSE> EVALD a var_decl (colon typeid equals expv): %s\n", (yyval.strinfo.strval));
#endif
                                                        }
    break;

  case 31:
#line 710 "tig.yac"
    {

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[lbrace_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[lbrace_pos].col); 

                           A_pushexp(A_RecordExp(absyn_pos, (yyvsp[(1) - (4)].strinfo.strval), absyn_efieldList));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (4)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (4)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (4)].strinfo.strval));

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<PARSE> EVALD a Rec Creation Statement: %s\n", (yyval.strinfo.strval));
#endif

                           }
    break;

  case 32:
#line 732 "tig.yac"
    {

                           absyn_efieldList=A_EfieldList(A_Efield((yyvsp[(3) - (5)].strinfo.strval), A_popexp()), 
                           absyn_efieldList);

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (5)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (5)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (5)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(5) - (5)].strinfo.strval));

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<PARSE> EVALD a Rec Creation Parm: %s\n", (yyval.strinfo.strval));
#endif
                           }
    break;

  case 33:
#line 754 "tig.yac"
    {

                           absyn_efieldList=A_EfieldList(A_Efield((yyvsp[(1) - (3)].strinfo.strval), A_popexp()),
                           NULL);

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

#ifdef YDUMPTXT
                           fprintf(yyout, "\n<PARSE> EVALD a Rec Creation Parm: %s\n", (yyval.strinfo.strval));
#endif
                           }
    break;

  case 34:
#line 782 "tig.yac"
    {

                           A_exp size, initval;

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (6)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (6)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (6)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(5) - (6)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(6) - (6)].strinfo.strval));

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[sqLbrace_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[sqLbrace_pos].col); 

#ifdef YDUMPTXT
                           fprintf(yyout, "<PARSE> Discovered an ARRAY DEFN: %s\n", (yyval.strinfo.strval));
#endif

                           initval = A_popexp();
                           size    = A_popexp();

                           A_pushexp(A_ArrayExp(absyn_pos, (yyvsp[(4) - (6)].strinfo.strval), size, initval));

                           }
    break;

  case 35:
#line 825 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));
#ifdef YDUMPEXP                          
                          fprintf(yyout, "<PARSE> ADD EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[add_op_pos].line,
                          yylval.strinfo.pos[add_op_pos].col, (yyval.strinfo.strval));

                          fprintf(yyout, "<PARSE> In the ADD EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "<PARSE> In the ADD EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[add_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[add_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_plusOp, A_popexp(), A_popexp()));
#ifdef PRN_STACK
                          Dbprn_expstack(); 
#endif
                           
                           }
    break;

  case 36:
#line 853 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

#ifdef YDUMPEXP                          
                          fprintf(yyout, "<PARSE> MINUS EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[minus_op_pos].line,
                          yylval.strinfo.pos[minus_op_pos].col, (yyval.strinfo.strval));

                          fprintf(yyout, "<PARSE> In the MINUS EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "<PARSE> In the MINUS EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif
		          absyn_pos->line = A_intdup(yylval.strinfo.pos[minus_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[minus_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_minusOp, A_popexp(), A_popexp()));
                           
                           }
    break;

  case 37:
#line 878 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

#ifdef YDUMPEXP                          
                          fprintf(yyout, "<PARSE> MULT EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[mult_op_pos].line,
                          yylval.strinfo.pos[mult_op_pos].col, (yyval.strinfo.strval));

                          fprintf(yyout, "<PARSE> In the MULT EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "<PARSE> In the MULT EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[mult_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[mult_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_timesOp, A_popexp(), A_popexp()));

                           }
    break;

  case 38:
#line 904 "tig.yac"
    {
			   
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

#ifdef YDUMPEXP                          
                          fprintf(yyout, "<PARSE> DIV EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[add_op_pos].line,
                          yylval.strinfo.pos[div_op_pos].col, (yyval.strinfo.strval));

                          fprintf(yyout, "<PARSE> In the DIV EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "<PARSE> In the DIV EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[div_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[div_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_divideOp, A_popexp(), A_popexp()));

                           }
    break;

  case 39:
#line 932 "tig.yac"
    {
			   
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));
                       
#ifdef YDUMPEXP                          
                          fprintf(yyout, "<PARSE> EQUAL COMPARE EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[eq_op_pos].line,
                          yylval.strinfo.pos[eq_op_pos].col, (yyval.strinfo.strval));

                          fprintf(yyout, "<PARSE> In the EQ-COMP EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "<PARSE> In the EQ-COMP EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[eq_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[eq_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_eqOp, A_popexp(), A_popexp()));

                           }
    break;

  case 40:
#line 959 "tig.yac"
    {
			   
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

#ifdef YDUMPEXP                          
                          fprintf(yyout, "<PARSE> NEQ COMPARE EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[not_eq_pos].line,
                          yylval.strinfo.pos[not_eq_pos].col, (yyval.strinfo.strval));

                          fprintf(yyout, "<PARSE> In the NEQ-COMP EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "<PARSE> In the NEQ-COMP EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[not_eq_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[not_eq_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_neqOp, A_popexp(), A_popexp()));
                           
                           }
    break;

  case 41:
#line 986 "tig.yac"
    {
			   
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

#ifdef YDUMPEXP                          
                          fprintf(yyout, "<PARSE> GR-COMP EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[gr_op_pos].line,
                          yylval.strinfo.pos[gr_op_pos].col, (yyval.strinfo.strval));

                          fprintf(yyout, "<PARSE> In the GR-COMP EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "<PARSE> In the GR-COMP EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[gr_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[gr_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_gtOp, A_popexp(), A_popexp()));
                           
                           }
    break;

  case 42:
#line 1013 "tig.yac"
    {
			   
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

#ifdef YDUMPEXP                          
                          fprintf(yyout, "<PARSE> LT-COMP EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[le_op_pos].line,
                          yylval.strinfo.pos[le_op_pos].col, (yyval.strinfo.strval));

                          fprintf(yyout, "<PARSE> In the LT-COMP EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "<PARSE> In the LT-COMP EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[le_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[le_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_ltOp, A_popexp(), A_popexp()));
                           
                           }
    break;

  case 43:
#line 1040 "tig.yac"
    {
			   
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

#ifdef YDUMPEXP                          
                          fprintf(yyout, "<PARSE> GR-EQ-COMP EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[gr_eq_op_pos].line,
                          yylval.strinfo.pos[gr_eq_op_pos].col, (yyval.strinfo.strval));

                          fprintf(yyout, "<PARSE> In the GR-EQ-COMP EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "<PARSE> In the GR-EQ-COMP EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[gr_eq_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[gr_eq_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_geOp, A_popexp(), A_popexp()));
                           
                           }
    break;

  case 44:
#line 1067 "tig.yac"
    {
			   
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

#ifdef YDUMPEXP                          
                          fprintf(yyout, "<PARSE> LT-EQ-COMP EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[le_eq_op_pos].line,
                          yylval.strinfo.pos[le_eq_op_pos].col, (yyval.strinfo.strval));

                          fprintf(yyout, "<PARSE> In the LT-EQ-COMP EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "<PARSE> In the LT-EQ-COMP EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[le_eq_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[le_eq_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_leOp, A_popexp(), A_popexp()));
                           
                           }
    break;

  case 45:
#line 1095 "tig.yac"
    {
			   
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

#ifdef YDUMPEXP                          
                          fprintf(yyout, "<PARSE> LOG-AND EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[and_op_pos].line,
                          yylval.strinfo.pos[and_op_pos].col, (yyval.strinfo.strval));

                          fprintf(yyout, "<PARSE> In the LOG-AND EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "<PARSE> In the LOG-AND EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[and_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[and_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_andOp, A_popexp(), A_popexp()));
                           
                           }
    break;

  case 46:
#line 1121 "tig.yac"
    {
			   
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

#ifdef YDUMPEXP                          
                          fprintf(yyout, "<PARSE> LOG-OR EXP (l:%d, c:%d): %s\n", yylval.strinfo.pos[or_op_pos].line,
                          yylval.strinfo.pos[or_op_pos].col, (yyval.strinfo.strval));

                          fprintf(yyout, "<PARSE> In the LOG-OR EXP, exp_left:\n");
			  prn_aexp(A_peepexp(0));
                           
                          fprintf(yyout, "<PARSE> In the LOG-OR EXP, exp_right:\n");
			  prn_aexp(A_peepexp(1));
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[or_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[or_op_pos].col); 

		          A_pushexp(A_OpExp(absyn_pos, A_orOp, A_popexp(), A_popexp()));
                           
                           }
    break;

  case 47:
#line 1149 "tig.yac"
    { 
                       
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (2)].strinfo.strval));

                           }
    break;

  case 48:
#line 1160 "tig.yac"
    {
#ifdef YDUMPEXP                          
                           fprintf(yyout, "\n<PARSE> Discovered an EXPLITERAL: %s\n", (yyval.strinfo.strval));
#endif
                           }
    break;

  case 49:
#line 1181 "tig.yac"
    {

#ifdef YDUMPEXP                          
			  fprintf(yyout,"\n<PARSE> EXPLITERAL (pure num): %s (%d, %d)\n", (yyval.strinfo.strval), 
                          yylval.strinfo.pos[pure_num_pos].line, yylval.strinfo.pos[pure_num_pos].col);
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[pure_num_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[pure_num_pos].col); 

                          A_pushexp(A_IntExp(absyn_pos, (yyval.strinfo.strval)));

#ifdef PRN_STACK
                          Dbprn_expstack(); 
#endif

			  }
    break;

  case 50:
#line 1199 "tig.yac"
    {

#ifdef YDUMPEXP                          
			  fprintf(yyout,"\n<PARSE> EXPLITERAL (pure string literal): %s (%d, %d)\n", (yyval.strinfo.strval), 
                          yylval.strinfo.pos[pure_num_pos].line, yylval.strinfo.pos[pure_num_pos].col);
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[pure_str_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[pure_str_pos].col); 

                          A_pushexp(A_StringExp(absyn_pos, (yyval.strinfo.strval)));

#ifdef PRN_STACK
                          Dbprn_expstack(); 
#endif

			  }
    break;

  case 51:
#line 1217 "tig.yac"
    {

#ifdef YDUMPEXP                          
			  fprintf(yyout,"\n<PARSE> EXPLITERAL (lvalue): %s\n", (yyval.strinfo.strval));
#endif

                          A_pushexp(A_VarExp(absyn_pos, A_popvar() ));

#ifdef PRN_STACK
                          Dbprn_expstack(); 
#endif

			  }
    break;

  case 52:
#line 1231 "tig.yac"
    {

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

                          /* How do we represent priority
                           * of execution on the AST?
                           */

                          }
    break;

  case 54:
#line 1261 "tig.yac"
    {

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[ident_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[ident_pos].col); 

			  A_pushvar(A_SubscriptVar(absyn_pos, A_popvar(), A_popexp())); 

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (4)].strinfo.strval));

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (4)].strinfo.strval));

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (4)].strinfo.strval));

#ifdef YDUMPVAR                          
                          fprintf(yyout, "<PARSE> SUBSCRIPT VAR (l:%d, c:%d): %s\n", yylval.strinfo.pos[ident_pos].line,
                          yylval.strinfo.pos[ident_pos].col, (yyval.strinfo.strval));

                          prn_avar(A_peepvar(0));
#endif

                          }
    break;

  case 55:
#line 1285 "tig.yac"
    {

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[ident_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[ident_pos].col); 

			  A_pushvar(A_FieldVar(absyn_pos, A_popvar(), (yyvsp[(3) - (3)].strinfo.strval))); 

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

#ifdef YDUMPVAR                          
                          fprintf(yyout, "<PARSE> FIELD VAR (l:%d, c:%d): %s\n", yylval.strinfo.pos[ident_pos].line,
                          yylval.strinfo.pos[ident_pos].col, (yyval.strinfo.strval));

                          //prn_avar(absyn_var);
#endif

                          }
    break;

  case 56:
#line 1304 "tig.yac"
    {

#ifdef YDUMPVAR                          
                          fprintf(yyout, "<PARSE> SIMPLE VAR (l:%d, c:%d): %s\n", yylval.strinfo.pos[ident_pos].line,
                          yylval.strinfo.pos[ident_pos].col, (yyval.strinfo.strval));
                          //prn_avar(absyn_var);
#endif

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[ident_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[ident_pos].col); 

			  A_pushvar(A_SimpleVar(absyn_pos, (yyval.strinfo.strval))); 

                          }
    break;

  case 57:
#line 1322 "tig.yac"
    {

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[ident_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[ident_pos].col); 

                          /* Since there is no explist at this point, so just affect an A_exp
                           * and add it to the stack at this point. Pass NULL for the explist
                           * arguement */

                          A_pushexp(A_CallExp(absyn_pos, (yyvsp[(1) - (3)].strinfo.strval), NULL)); 

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

#ifdef YDUMPTXT
                          fprintf(yyout, "\n<PARSE> EVALD a func call: %s", (yyval.strinfo.strval));
#endif
 
                          }
    break;

  case 58:
#line 1342 "tig.yac"
    {

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[ident_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[ident_pos].col); 

                          /* Pop out the latest explist (from stack), affect it on A_exp (func_call)
                           * and push the new A_exp on its stack.
                           */

                          A_pushexp(A_CallExp(absyn_pos, (yyvsp[(1) - (4)].strinfo.strval), A_popexplist()));

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (4)].strinfo.strval));
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (4)].strinfo.strval));
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (4)].strinfo.strval));

#ifdef YDUMPTXT
                          fprintf(yyout, "\n<PARSE> EVALD a func call: %s\n", (yyval.strinfo.strval));
#endif
                          }
    break;

  case 59:
#line 1362 "tig.yac"
    {

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

                          /* Pop, affect, push */
			  A_pushexplist(A_ExpList(A_popexp(), A_popexplist()));
#ifdef YDUMPTXT
                          fprintf(yyout, "\n<PARSE> EVALD a parameter list for a func call: %s\n", (yyval.strinfo.strval));
#endif

                          }
    break;

  case 60:
#line 1377 "tig.yac"
    {

                          /* Push, raise level in the stack */
                          A_pushexplist(A_ExpList(A_popexp(),NULL));

#ifdef YDUMPTXT
                          fprintf(yyout, "\n<PARSE> EVALD a (simple, no comma) parameter list for a func call: %s\n", (yyval.strinfo.strval));
#endif
		          }
    break;

  case 61:
#line 1397 "tig.yac"
    {

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[asn_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[asn_op_pos].col); 

			  A_pushexp(A_AssignExp(absyn_pos, A_popvar(), A_popexp())); 
#ifdef YASNEXP
                          fprintf(yyout, "<PARSE> On adding the asn-exp,\n");
                          prn_aexp(A_peepexp(0));
#endif

                         }
    break;

  case 62:
#line 1415 "tig.yac"
    {

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[asn_op_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[asn_op_pos].col); 

			  A_pushexp(A_AssignExp(absyn_pos, A_popvar(), A_popexp())); 

#ifdef YASNEXP
                          fprintf(yyout, "<PARSE> On adding the asn-exp,\n");
                          prn_aexp(A_peepexp(0));
#endif

                         }
    break;

  case 63:
#line 1450 "tig.yac"
    {

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (2)].strinfo.strval));

                          /* pos is defined to be lparan position */

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[lparan_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[lparan_pos].col); 
         
                          /* explist is NULL */
                          A_pushexp(A_SeqExp(absyn_pos, NULL));

#ifdef YEXPSEQ
                          fprintf(yyout, "<PARSE> GRABBING AN EXPSEQ LIST HERE (NULL CASE):\n");
                          prn_aexp(A_peepexp(0));
#endif

                          }
    break;

  case 64:
#line 1469 "tig.yac"
    {

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

		          absyn_pos->line = A_intdup(yylval.strinfo.pos[lparan_pos].line);
                          absyn_pos->col  = A_intdup(yylval.strinfo.pos[lparan_pos].col); 

                          /* Pop and add the latest explist  */
                          A_pushexp(A_SeqExp(absyn_pos, A_popexplist()) );

#ifdef YEXPSEQ
                          fprintf(yyout, "<PARSE> GRABBING AN EXPSEQ LIST HERE (NON-EMPTY):\n");
                          prn_aexp(A_peepexp(0));
#endif

                          }
    break;

  case 65:
#line 1499 "tig.yac"
    {

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), "\n");
                          (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

                          /* Pop, affect and re-push on the explist stack */
			  A_pushexplist(A_ExpList(A_popexp(), A_popexplist()));

#ifdef YASNEXP
                          fprintf(yyout, "<PARSE> On discovering the asn-exp,\n");
                          prn_aexplist(A_peepexplist(0));
#endif

                          }
    break;

  case 66:
#line 1517 "tig.yac"
    {

                          /* Push new level in explist stack */
                          A_pushexplist(A_ExpList(A_popexp(),NULL));

                          }
    break;

  case 67:
#line 1524 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), "\n");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

                          /* Pop, affect and re-push on the explist stack */
			  A_pushexplist(A_ExpList(A_popexp(), A_popexplist()));

                          }
    break;

  case 68:
#line 1537 "tig.yac"
    {

                          /* Push new level in explist stack */
                          A_pushexplist(A_ExpList(A_popexp(),NULL));

                          }
    break;

  case 69:
#line 1544 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), "\n");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

                          /* Pop, affect and re-push on the explist stack */
			  A_pushexplist(A_ExpList(A_popexp(), A_popexplist()));

                          }
    break;

  case 70:
#line 1557 "tig.yac"
    {

                          /* Push new level in explist stack */
                          A_pushexplist(A_ExpList(A_popexp(),NULL));

                          }
    break;

  case 71:
#line 1564 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), "\n");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

                          /* Pop, affect and re-push on the explist stack */
			  A_pushexplist(A_ExpList(A_popexp(), A_popexplist()));

                          }
    break;

  case 72:
#line 1577 "tig.yac"
    {

                          /* Push new level in explist stack */
                          A_pushexplist(A_ExpList(A_popexp(),NULL));

                          }
    break;

  case 73:
#line 1584 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), "\n");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

                          /* Pop, affect and re-push on the explist stack */
			  A_pushexplist(A_ExpList(A_popexp(), A_popexplist()));

                          }
    break;

  case 74:
#line 1597 "tig.yac"
    {

                          /* Push new level in explist stack */
                          A_pushexplist(A_ExpList(A_popexp(),NULL));

                          }
    break;

  case 75:
#line 1604 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), "\n");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

                          /* Pop, affect and re-push on the explist stack */
			  A_pushexplist(A_ExpList(A_popexp(), A_popexplist()));

                          }
    break;

  case 76:
#line 1617 "tig.yac"
    {

                          /* Push new level in explist stack */
                          A_pushexplist(A_ExpList(A_popexp(),NULL));

                          }
    break;

  case 77:
#line 1644 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), "\n");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

                          /* Pop, affect and re-push on the explist stack */
			  A_pushexplist(A_ExpList(A_popexp(), A_popexplist()));

                          }
    break;

  case 78:
#line 1657 "tig.yac"
    {

                          /* Push new level in explist stack */
                          A_pushexplist(A_ExpList(A_popexp(),NULL));

                          }
    break;

  case 79:
#line 1667 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), "\n");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[break_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[break_kwd_pos].col); 

                           /* Pop, affect and re-push on the explist stack */
			   A_pushexplist(A_ExpList(A_BreakExp(absyn_pos), A_popexplist()));

                          }
    break;

  case 80:
#line 1683 "tig.yac"
    {

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[break_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[break_kwd_pos].col); 

                           /* Push new level in explist stack */
                           A_pushexplist(A_ExpList(A_BreakExp(absyn_pos),NULL));

                          }
    break;

  case 81:
#line 1696 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), "\n");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

                          /* Pop, affect and re-push on the explist stack */
			  A_pushexplist(A_ExpList(A_popexp(), A_popexplist()));

                          }
    break;

  case 82:
#line 1708 "tig.yac"
    {

                          /* Push new level in explist stack */
                          A_pushexplist(A_ExpList(A_popexp(),NULL));

                          }
    break;

  case 83:
#line 1717 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (3)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), "\n");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (3)].strinfo.strval));

                          /* Pop, affect and re-push on the explist stack */
			  A_pushexplist(A_ExpList(A_popexp(), A_popexplist()));

                          }
    break;

  case 84:
#line 1729 "tig.yac"
    {

                          /* Push new level in explist stack */
                          A_pushexplist(A_ExpList(A_popexp(),NULL));

                          }
    break;

  case 85:
#line 1745 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (4)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (4)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (4)].strinfo.strval));

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[if_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[if_kwd_pos].col); 

                           /* need to validate the order of the exp-pop (condn,  then-body, else-body) */
                           A_pushexp(A_IfExp(absyn_pos, A_popexp(), A_popexp(), NULL) );

#ifdef YDUMPIF
                           fprintf(yyout, "\n<PARSE> EVALD an if_then_decl: %s\n", (yyval.strinfo.strval));
                           prn_aexp(A_peepexp(0));
#endif

                           }
    break;

  case 86:
#line 1769 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (4)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (4)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (4)].strinfo.strval));

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[while_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[while_kwd_pos].col); 

                           /* need to validate the order of the pop-exp */
                           A_pushexp(A_WhileExp(absyn_pos, A_popexp(), A_popexp()) );

                           /* TO BE TESTED */
#ifdef YDUMPWHL
                           fprintf(yyout, "\n<PARSE> EVALD a while_decl: %s\n", (yyval.strinfo.strval));
                           prn_aexp(A_peepexp(0));
#endif

                           }
    break;

  case 87:
#line 1794 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (8)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (8)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (8)].strinfo.strval));
                           
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(5) - (8)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(6) - (8)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(7) - (8)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(8) - (8)].strinfo.strval));

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[for_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[for_kwd_pos].col); 

                           /* need to validate the order of the pop-exp */
                           A_pushexp(A_ForExp(absyn_pos, A_popexp(), A_popexp(), A_popexp()));

                           /* TO BE TESTED */
#ifdef YDUMPFOR
                           fprintf(yyout, "\n<PARSE> EVALD a FOR_LOOP_decl: %s\n", (yyval.strinfo.strval));
                           prn_aexp(A_peepexp(0));
#endif

                           }
    break;

  case 88:
#line 1832 "tig.yac"
    {

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(2) - (6)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(3) - (6)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(4) - (6)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(5) - (6)].strinfo.strval));

                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), " ");
                           (yyval.strinfo.strval) = (char*) strmemcat((yyval.strinfo.strval), (yyvsp[(6) - (6)].strinfo.strval));

		           absyn_pos->line = A_intdup(yylval.strinfo.pos[if_kwd_pos].line);
                           absyn_pos->col  = A_intdup(yylval.strinfo.pos[if_kwd_pos].col); 

                           /* need to validate the order of the exp-pop (condn,  then-body, else-body) */
                           A_pushexp(A_IfExp(absyn_pos, A_popexp(), A_popexp(), A_popexp()) );

                           /* TO BE TESTED (core dump + live examples) */

#ifdef YDUMPIF
                           fprintf(yyout, "\n<PARSE> EVALD an if_then_else_decl: %s\n", (yyval.strinfo.strval));
                           prn_aexp(A_peepexp(0));
#endif

                          }
    break;


/* Line 1267 of yacc.c.  */
#line 3403 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1865 "tig.yac"


/* Definition of yacc's main follows: */

#ifdef RUN_AND_TEST_AST
int main (int argc, char *argv[]) { 

#else
int ast_main (int argc, char *argv[]) {

#endif

FILE *tfin, *tfout;

absyn_pos = aposmalloc();
absyn_pos->line = A_intdup(0);
absyn_pos->col  = A_intdup(0); 

if(argc == 1) {
fprintf(stderr, "<PARSE> : input file name required\n");
exit(1);
}

tfin = fopen(argv[1], "r");

if(tfin == NULL) {
fprintf(stderr, "<PARSE> : input %s does not exist\n", argv[1]);
exit(1);
}

tfout =  fopen("ydump.txt", "w");
llout =  fopen("ldump.txt", "w");

if(tfout == NULL) {
fprintf(stderr, "<PARSE> : not enough space for fopen\n");
exit(1);
}

if(llout == NULL) {
fprintf(stderr, "<PARSE> : not enough space for fopen\n");
exit(1);
}

yyin = tfin;
yyout = tfout;

while(!(feof(yyin))) {
yyparse();
};

fprintf(stderr, "<PARSE> : finished parsing yacc tree. AST should be ready\n");

fclose(llout);
fclose(yyout);
fclose(yyin);

free(absyn_pos);

return 0;

} /* end of main */

void yyerror(s)
char *s;
{
fprintf(stderr, "<PARSE> (Error) At line %d: %s\n", lxline, s);
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
  printf("<PARSE> : No space for strmemcat\n");
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


