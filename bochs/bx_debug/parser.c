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

/* Substitute the variable and function names.  */
#define yyparse bxparse
#define yylex   bxlex
#define yyerror bxerror
#define yylval  bxlval
#define yychar  bxchar
#define yydebug bxdebug
#define yynerrs bxnerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BX_TOKEN_8BH_REG = 258,
     BX_TOKEN_8BL_REG = 259,
     BX_TOKEN_16B_REG = 260,
     BX_TOKEN_32B_REG = 261,
     BX_TOKEN_64B_REG = 262,
     BX_TOKEN_CS = 263,
     BX_TOKEN_ES = 264,
     BX_TOKEN_SS = 265,
     BX_TOKEN_DS = 266,
     BX_TOKEN_FS = 267,
     BX_TOKEN_GS = 268,
     BX_TOKEN_FLAGS = 269,
     BX_TOKEN_ON = 270,
     BX_TOKEN_OFF = 271,
     BX_TOKEN_CONTINUE = 272,
     BX_TOKEN_STEPN = 273,
     BX_TOKEN_STEP_OVER = 274,
     BX_TOKEN_NEXT_STEP = 275,
     BX_TOKEN_SET = 276,
     BX_TOKEN_DEBUGGER = 277,
     BX_TOKEN_LIST_BREAK = 278,
     BX_TOKEN_VBREAKPOINT = 279,
     BX_TOKEN_LBREAKPOINT = 280,
     BX_TOKEN_PBREAKPOINT = 281,
     BX_TOKEN_DEL_BREAKPOINT = 282,
     BX_TOKEN_ENABLE_BREAKPOINT = 283,
     BX_TOKEN_DISABLE_BREAKPOINT = 284,
     BX_TOKEN_INFO = 285,
     BX_TOKEN_QUIT = 286,
     BX_TOKEN_R = 287,
     BX_TOKEN_REGS = 288,
     BX_TOKEN_CPU = 289,
     BX_TOKEN_FPU = 290,
     BX_TOKEN_SSE = 291,
     BX_TOKEN_MMX = 292,
     BX_TOKEN_IDT = 293,
     BX_TOKEN_IVT = 294,
     BX_TOKEN_GDT = 295,
     BX_TOKEN_LDT = 296,
     BX_TOKEN_TSS = 297,
     BX_TOKEN_TAB = 298,
     BX_TOKEN_LINUX = 299,
     BX_TOKEN_DEBUG_REGS = 300,
     BX_TOKEN_CONTROL_REGS = 301,
     BX_TOKEN_SEGMENT_REGS = 302,
     BX_TOKEN_EXAMINE = 303,
     BX_TOKEN_XFORMAT = 304,
     BX_TOKEN_DISFORMAT = 305,
     BX_TOKEN_RESTORE = 306,
     BX_TOKEN_SETPMEM = 307,
     BX_TOKEN_SYMBOLNAME = 308,
     BX_TOKEN_QUERY = 309,
     BX_TOKEN_PENDING = 310,
     BX_TOKEN_TAKE = 311,
     BX_TOKEN_DMA = 312,
     BX_TOKEN_IRQ = 313,
     BX_TOKEN_DISASSEMBLE = 314,
     BX_TOKEN_INSTRUMENT = 315,
     BX_TOKEN_STRING = 316,
     BX_TOKEN_STOP = 317,
     BX_TOKEN_DOIT = 318,
     BX_TOKEN_CRC = 319,
     BX_TOKEN_TRACE = 320,
     BX_TOKEN_TRACEREG = 321,
     BX_TOKEN_TRACEMEM = 322,
     BX_TOKEN_SWITCH_MODE = 323,
     BX_TOKEN_SIZE = 324,
     BX_TOKEN_PTIME = 325,
     BX_TOKEN_TIMEBP_ABSOLUTE = 326,
     BX_TOKEN_TIMEBP = 327,
     BX_TOKEN_RECORD = 328,
     BX_TOKEN_PLAYBACK = 329,
     BX_TOKEN_MODEBP = 330,
     BX_TOKEN_PRINT_STACK = 331,
     BX_TOKEN_WATCH = 332,
     BX_TOKEN_UNWATCH = 333,
     BX_TOKEN_READ = 334,
     BX_TOKEN_WRITE = 335,
     BX_TOKEN_SHOW = 336,
     BX_TOKEN_LOAD_SYMBOLS = 337,
     BX_TOKEN_SYMBOLS = 338,
     BX_TOKEN_LIST_SYMBOLS = 339,
     BX_TOKEN_GLOBAL = 340,
     BX_TOKEN_WHERE = 341,
     BX_TOKEN_PRINT_STRING = 342,
     BX_TOKEN_NUMERIC = 343,
     BX_TOKEN_NE2000 = 344,
     BX_TOKEN_PIC = 345,
     BX_TOKEN_PAGE = 346,
     BX_TOKEN_HELP = 347,
     BX_TOKEN_CALC = 348,
     BX_TOKEN_VGA = 349,
     BX_TOKEN_PCI = 350,
     BX_TOKEN_COMMAND = 351,
     BX_TOKEN_GENERIC = 352,
     BX_TOKEN_RSHIFT = 353,
     BX_TOKEN_LSHIFT = 354,
     BX_TOKEN_REG_IP = 355,
     BX_TOKEN_REG_EIP = 356,
     BX_TOKEN_REG_RIP = 357,
     NEG = 358,
     NOT = 359
   };
#endif
/* Tokens.  */
#define BX_TOKEN_8BH_REG 258
#define BX_TOKEN_8BL_REG 259
#define BX_TOKEN_16B_REG 260
#define BX_TOKEN_32B_REG 261
#define BX_TOKEN_64B_REG 262
#define BX_TOKEN_CS 263
#define BX_TOKEN_ES 264
#define BX_TOKEN_SS 265
#define BX_TOKEN_DS 266
#define BX_TOKEN_FS 267
#define BX_TOKEN_GS 268
#define BX_TOKEN_FLAGS 269
#define BX_TOKEN_ON 270
#define BX_TOKEN_OFF 271
#define BX_TOKEN_CONTINUE 272
#define BX_TOKEN_STEPN 273
#define BX_TOKEN_STEP_OVER 274
#define BX_TOKEN_NEXT_STEP 275
#define BX_TOKEN_SET 276
#define BX_TOKEN_DEBUGGER 277
#define BX_TOKEN_LIST_BREAK 278
#define BX_TOKEN_VBREAKPOINT 279
#define BX_TOKEN_LBREAKPOINT 280
#define BX_TOKEN_PBREAKPOINT 281
#define BX_TOKEN_DEL_BREAKPOINT 282
#define BX_TOKEN_ENABLE_BREAKPOINT 283
#define BX_TOKEN_DISABLE_BREAKPOINT 284
#define BX_TOKEN_INFO 285
#define BX_TOKEN_QUIT 286
#define BX_TOKEN_R 287
#define BX_TOKEN_REGS 288
#define BX_TOKEN_CPU 289
#define BX_TOKEN_FPU 290
#define BX_TOKEN_SSE 291
#define BX_TOKEN_MMX 292
#define BX_TOKEN_IDT 293
#define BX_TOKEN_IVT 294
#define BX_TOKEN_GDT 295
#define BX_TOKEN_LDT 296
#define BX_TOKEN_TSS 297
#define BX_TOKEN_TAB 298
#define BX_TOKEN_LINUX 299
#define BX_TOKEN_DEBUG_REGS 300
#define BX_TOKEN_CONTROL_REGS 301
#define BX_TOKEN_SEGMENT_REGS 302
#define BX_TOKEN_EXAMINE 303
#define BX_TOKEN_XFORMAT 304
#define BX_TOKEN_DISFORMAT 305
#define BX_TOKEN_RESTORE 306
#define BX_TOKEN_SETPMEM 307
#define BX_TOKEN_SYMBOLNAME 308
#define BX_TOKEN_QUERY 309
#define BX_TOKEN_PENDING 310
#define BX_TOKEN_TAKE 311
#define BX_TOKEN_DMA 312
#define BX_TOKEN_IRQ 313
#define BX_TOKEN_DISASSEMBLE 314
#define BX_TOKEN_INSTRUMENT 315
#define BX_TOKEN_STRING 316
#define BX_TOKEN_STOP 317
#define BX_TOKEN_DOIT 318
#define BX_TOKEN_CRC 319
#define BX_TOKEN_TRACE 320
#define BX_TOKEN_TRACEREG 321
#define BX_TOKEN_TRACEMEM 322
#define BX_TOKEN_SWITCH_MODE 323
#define BX_TOKEN_SIZE 324
#define BX_TOKEN_PTIME 325
#define BX_TOKEN_TIMEBP_ABSOLUTE 326
#define BX_TOKEN_TIMEBP 327
#define BX_TOKEN_RECORD 328
#define BX_TOKEN_PLAYBACK 329
#define BX_TOKEN_MODEBP 330
#define BX_TOKEN_PRINT_STACK 331
#define BX_TOKEN_WATCH 332
#define BX_TOKEN_UNWATCH 333
#define BX_TOKEN_READ 334
#define BX_TOKEN_WRITE 335
#define BX_TOKEN_SHOW 336
#define BX_TOKEN_LOAD_SYMBOLS 337
#define BX_TOKEN_SYMBOLS 338
#define BX_TOKEN_LIST_SYMBOLS 339
#define BX_TOKEN_GLOBAL 340
#define BX_TOKEN_WHERE 341
#define BX_TOKEN_PRINT_STRING 342
#define BX_TOKEN_NUMERIC 343
#define BX_TOKEN_NE2000 344
#define BX_TOKEN_PIC 345
#define BX_TOKEN_PAGE 346
#define BX_TOKEN_HELP 347
#define BX_TOKEN_CALC 348
#define BX_TOKEN_VGA 349
#define BX_TOKEN_PCI 350
#define BX_TOKEN_COMMAND 351
#define BX_TOKEN_GENERIC 352
#define BX_TOKEN_RSHIFT 353
#define BX_TOKEN_LSHIFT 354
#define BX_TOKEN_REG_IP 355
#define BX_TOKEN_REG_EIP 356
#define BX_TOKEN_REG_RIP 357
#define NEG 358
#define NOT 359




/* Copy the first part of user declarations.  */
#line 5 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include "debug.h"

#if BX_DEBUGGER


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
#line 13 "parser.y"
{
  char    *sval;
  Bit64u   uval;
  bx_bool  bval;
}
/* Line 187 of yacc.c.  */
#line 326 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 339 "y.tab.c"

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
# if YYENABLE_NLS
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
#define YYFINAL  271
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  118
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  255
/* YYNRULES -- Number of states.  */
#define YYNSTATES  490

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   359

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     112,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   115,     2,     2,     2,     2,   109,     2,
     116,   117,   107,   103,     2,   104,     2,   108,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   114,     2,
       2,   113,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   106,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   105,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   110,   111
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    48,    50,    52,    54,    56,    58,
      60,    62,    64,    66,    68,    70,    72,    74,    76,    78,
      80,    82,    84,    86,    88,    90,    92,    94,    96,    98,
      99,   101,   103,   105,   107,   109,   111,   113,   115,   117,
     119,   121,   125,   129,   133,   137,   140,   144,   148,   151,
     155,   158,   162,   166,   170,   173,   177,   181,   185,   188,
     193,   198,   203,   206,   210,   214,   219,   224,   230,   233,
     237,   240,   243,   247,   250,   255,   261,   267,   273,   279,
     285,   291,   294,   300,   303,   307,   311,   314,   318,   323,
     326,   329,   333,   337,   341,   347,   353,   359,   365,   369,
     373,   377,   381,   385,   390,   394,   400,   408,   412,   416,
     420,   421,   423,   426,   429,   432,   435,   438,   441,   444,
     448,   452,   456,   459,   464,   468,   472,   475,   480,   486,
     490,   494,   499,   503,   506,   510,   515,   519,   524,   530,
     534,   540,   544,   548,   552,   557,   561,   565,   569,   573,
     577,   581,   585,   589,   593,   597,   601,   605,   609,   613,
     617,   621,   625,   629,   633,   637,   641,   645,   649,   653,
     657,   661,   665,   669,   673,   677,   681,   685,   689,   693,
     697,   701,   705,   709,   713,   717,   721,   725,   729,   732,
     736,   738,   740,   742,   744,   746,   748,   750,   752,   754,
     756,   760,   764,   768,   772,   776,   780,   784,   788,   792,
     795,   798,   802,   804,   806,   808,   810,   812,   814,   816,
     818,   820,   822,   824,   828,   832,   836,   840,   844,   848,
     852,   856,   860,   864,   867,   870
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     119,     0,    -1,   119,   120,    -1,   120,    -1,   139,    -1,
     140,    -1,   141,    -1,   142,    -1,   143,    -1,   146,    -1,
     148,    -1,   149,    -1,   150,    -1,   151,    -1,   152,    -1,
     154,    -1,   153,    -1,   144,    -1,   145,    -1,   155,    -1,
     156,    -1,   157,    -1,   158,    -1,   159,    -1,   160,    -1,
     161,    -1,   162,    -1,   163,    -1,   164,    -1,   165,    -1,
     166,    -1,   167,    -1,   131,    -1,   132,    -1,   133,    -1,
     130,    -1,   124,    -1,   125,    -1,   126,    -1,   127,    -1,
     134,    -1,   135,    -1,   129,    -1,   128,    -1,   136,    -1,
     137,    -1,   138,    -1,   168,    -1,   169,    -1,    -1,   112,
      -1,    15,    -1,    16,    -1,    32,    -1,    33,    -1,     8,
      -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,    13,
      -1,    72,    88,   112,    -1,    71,    88,   112,    -1,    73,
      61,   112,    -1,    74,    61,   112,    -1,    75,   112,    -1,
      81,    96,   112,    -1,    81,    61,   112,    -1,    81,   112,
      -1,    91,   171,   112,    -1,    70,   112,    -1,    65,   121,
     112,    -1,    66,   121,   112,    -1,    67,   121,   112,    -1,
      76,   112,    -1,    76,    88,   112,    -1,    77,    62,   112,
      -1,    77,    17,   112,    -1,    77,   112,    -1,    77,    32,
     171,   112,    -1,    77,    79,   171,   112,    -1,    77,    80,
     171,   112,    -1,    78,   112,    -1,    78,   171,   112,    -1,
      82,    61,   112,    -1,    82,    61,    88,   112,    -1,    82,
      85,    61,   112,    -1,    82,    85,    61,    88,   112,    -1,
      86,   112,    -1,    87,    88,   112,    -1,    17,   112,    -1,
      18,   112,    -1,    18,    88,   112,    -1,    19,   112,    -1,
      21,    59,   121,   112,    -1,    21,    53,   113,    88,   112,
      -1,    21,     4,   113,   171,   112,    -1,    21,     3,   113,
     171,   112,    -1,    21,     5,   113,   171,   112,    -1,    21,
       6,   113,   171,   112,    -1,    21,     7,   113,   171,   112,
      -1,    24,   112,    -1,    24,   170,   114,   170,   112,    -1,
      25,   112,    -1,    25,   171,   112,    -1,    25,    61,   112,
      -1,    26,   112,    -1,    26,   171,   112,    -1,    26,   107,
     171,   112,    -1,    23,   112,    -1,    84,   112,    -1,    84,
      61,   112,    -1,    30,    26,   112,    -1,    30,    34,   112,
      -1,    30,    38,   147,   147,   112,    -1,    30,    39,   147,
     147,   112,    -1,    30,    40,   147,   147,   112,    -1,    30,
      41,   147,   147,   112,    -1,    30,    43,   112,    -1,    30,
      42,   112,    -1,    30,    14,   112,    -1,    30,    44,   112,
      -1,    30,    83,   112,    -1,    30,    83,    61,   112,    -1,
      30,    89,   112,    -1,    30,    89,    91,    88,   112,    -1,
      30,    89,    91,    88,   122,    88,   112,    -1,    30,    90,
     112,    -1,    30,    94,   112,    -1,    30,    95,   112,    -1,
      -1,    88,    -1,   122,   112,    -1,    35,   112,    -1,    37,
     112,    -1,    36,   112,    -1,    47,   112,    -1,    46,   112,
      -1,    45,   112,    -1,    27,    88,   112,    -1,    28,    88,
     112,    -1,    29,    88,   112,    -1,    31,   112,    -1,    48,
      49,   171,   112,    -1,    48,    49,   112,    -1,    48,   171,
     112,    -1,    48,   112,    -1,    51,    61,    61,   112,    -1,
      52,    88,    88,    88,   112,    -1,    54,    55,   112,    -1,
      56,    57,   112,    -1,    56,    57,    88,   112,    -1,    56,
      58,   112,    -1,    59,   112,    -1,    59,   171,   112,    -1,
      59,   171,   171,   112,    -1,    59,    50,   112,    -1,    59,
      50,   171,   112,    -1,    59,    50,   171,   171,   112,    -1,
      59,    68,   112,    -1,    59,    69,   113,    88,   112,    -1,
      60,    62,   112,    -1,    60,    96,   112,    -1,    63,    88,
     112,    -1,    64,    88,    88,   112,    -1,    92,    31,   112,
      -1,    92,    17,   112,    -1,    92,    18,   112,    -1,    92,
      19,   112,    -1,    92,    24,   112,    -1,    92,    25,   112,
      -1,    92,    26,   112,    -1,    92,    27,   112,    -1,    92,
      28,   112,    -1,    92,    29,   112,    -1,    92,    23,   112,
      -1,    92,    75,   112,    -1,    92,    64,   112,    -1,    92,
      65,   112,    -1,    92,    66,   112,    -1,    92,    67,   112,
      -1,    92,    51,   112,    -1,    92,    70,   112,    -1,    92,
      72,   112,    -1,    92,    71,   112,    -1,    92,    76,   112,
      -1,    92,    73,   112,    -1,    92,    74,   112,    -1,    92,
      82,   112,    -1,    92,    84,   112,    -1,    92,   122,   112,
      -1,    92,    35,   112,    -1,    92,    37,   112,    -1,    92,
      36,   112,    -1,    92,    47,   112,    -1,    92,    46,   112,
      -1,    92,    52,   112,    -1,    92,    59,   112,    -1,    92,
      77,   112,    -1,    92,    78,   112,    -1,    92,    48,   112,
      -1,    92,    60,   112,    -1,    92,    21,   112,    -1,    92,
      91,   112,    -1,    92,    30,   112,    -1,    92,    81,   112,
      -1,    92,    93,   112,    -1,    92,    92,   112,    -1,    92,
     112,    -1,    93,   171,   112,    -1,    88,    -1,     4,    -1,
       3,    -1,     5,    -1,     6,    -1,     7,    -1,   123,    -1,
     100,    -1,   101,    -1,   102,    -1,   170,   103,   170,    -1,
     170,   104,   170,    -1,   170,   107,   170,    -1,   170,   108,
     170,    -1,   170,    98,   170,    -1,   170,    99,   170,    -1,
     170,   105,   170,    -1,   170,   106,   170,    -1,   170,   109,
     170,    -1,   115,   170,    -1,   104,   170,    -1,   116,   170,
     117,    -1,    88,    -1,    61,    -1,     4,    -1,     3,    -1,
       5,    -1,     6,    -1,     7,    -1,   123,    -1,   100,    -1,
     101,    -1,   102,    -1,   171,   114,   171,    -1,   171,   103,
     171,    -1,   171,   104,   171,    -1,   171,   107,   171,    -1,
     171,   108,   171,    -1,   171,    98,   171,    -1,   171,    99,
     171,    -1,   171,   105,   171,    -1,   171,   106,   171,    -1,
     171,   109,   171,    -1,   115,   171,    -1,   104,   171,    -1,
     116,   171,   117,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   137,   137,   138,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   194,   195,   200,   201,   206,   207,   208,   209,   210,
     211,   216,   221,   229,   237,   245,   253,   258,   263,   271,
     279,   287,   295,   303,   311,   316,   324,   330,   336,   341,
     346,   351,   356,   361,   369,   374,   379,   384,   392,   400,
     408,   416,   421,   429,   437,   442,   447,   451,   455,   459,
     463,   470,   475,   480,   485,   490,   495,   500,   505,   513,
     521,   526,   534,   539,   544,   549,   554,   559,   564,   569,
     574,   579,   584,   589,   594,   599,   604,   609,   614,   619,
     627,   628,   631,   639,   647,   655,   663,   671,   679,   687,
     695,   702,   710,   718,   723,   728,   733,   741,   749,   757,
     765,   770,   775,   783,   788,   793,   798,   803,   808,   813,
     818,   826,   831,   839,   847,   855,   860,   865,   870,   875,
     880,   885,   890,   895,   900,   905,   910,   915,   920,   926,
     932,   938,   946,   951,   956,   961,   966,   971,   976,   981,
     986,   991,   996,  1001,  1006,  1011,  1016,  1021,  1030,  1039,
    1045,  1058,  1066,  1076,  1081,  1097,  1109,  1119,  1124,  1132,
    1150,  1151,  1152,  1153,  1154,  1155,  1156,  1157,  1158,  1159,
    1160,  1161,  1162,  1163,  1164,  1165,  1166,  1167,  1168,  1169,
    1170,  1171,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,
    1194,  1195,  1196,  1197,  1198,  1199
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BX_TOKEN_8BH_REG", "BX_TOKEN_8BL_REG",
  "BX_TOKEN_16B_REG", "BX_TOKEN_32B_REG", "BX_TOKEN_64B_REG",
  "BX_TOKEN_CS", "BX_TOKEN_ES", "BX_TOKEN_SS", "BX_TOKEN_DS",
  "BX_TOKEN_FS", "BX_TOKEN_GS", "BX_TOKEN_FLAGS", "BX_TOKEN_ON",
  "BX_TOKEN_OFF", "BX_TOKEN_CONTINUE", "BX_TOKEN_STEPN",
  "BX_TOKEN_STEP_OVER", "BX_TOKEN_NEXT_STEP", "BX_TOKEN_SET",
  "BX_TOKEN_DEBUGGER", "BX_TOKEN_LIST_BREAK", "BX_TOKEN_VBREAKPOINT",
  "BX_TOKEN_LBREAKPOINT", "BX_TOKEN_PBREAKPOINT",
  "BX_TOKEN_DEL_BREAKPOINT", "BX_TOKEN_ENABLE_BREAKPOINT",
  "BX_TOKEN_DISABLE_BREAKPOINT", "BX_TOKEN_INFO", "BX_TOKEN_QUIT",
  "BX_TOKEN_R", "BX_TOKEN_REGS", "BX_TOKEN_CPU", "BX_TOKEN_FPU",
  "BX_TOKEN_SSE", "BX_TOKEN_MMX", "BX_TOKEN_IDT", "BX_TOKEN_IVT",
  "BX_TOKEN_GDT", "BX_TOKEN_LDT", "BX_TOKEN_TSS", "BX_TOKEN_TAB",
  "BX_TOKEN_LINUX", "BX_TOKEN_DEBUG_REGS", "BX_TOKEN_CONTROL_REGS",
  "BX_TOKEN_SEGMENT_REGS", "BX_TOKEN_EXAMINE", "BX_TOKEN_XFORMAT",
  "BX_TOKEN_DISFORMAT", "BX_TOKEN_RESTORE", "BX_TOKEN_SETPMEM",
  "BX_TOKEN_SYMBOLNAME", "BX_TOKEN_QUERY", "BX_TOKEN_PENDING",
  "BX_TOKEN_TAKE", "BX_TOKEN_DMA", "BX_TOKEN_IRQ", "BX_TOKEN_DISASSEMBLE",
  "BX_TOKEN_INSTRUMENT", "BX_TOKEN_STRING", "BX_TOKEN_STOP",
  "BX_TOKEN_DOIT", "BX_TOKEN_CRC", "BX_TOKEN_TRACE", "BX_TOKEN_TRACEREG",
  "BX_TOKEN_TRACEMEM", "BX_TOKEN_SWITCH_MODE", "BX_TOKEN_SIZE",
  "BX_TOKEN_PTIME", "BX_TOKEN_TIMEBP_ABSOLUTE", "BX_TOKEN_TIMEBP",
  "BX_TOKEN_RECORD", "BX_TOKEN_PLAYBACK", "BX_TOKEN_MODEBP",
  "BX_TOKEN_PRINT_STACK", "BX_TOKEN_WATCH", "BX_TOKEN_UNWATCH",
  "BX_TOKEN_READ", "BX_TOKEN_WRITE", "BX_TOKEN_SHOW",
  "BX_TOKEN_LOAD_SYMBOLS", "BX_TOKEN_SYMBOLS", "BX_TOKEN_LIST_SYMBOLS",
  "BX_TOKEN_GLOBAL", "BX_TOKEN_WHERE", "BX_TOKEN_PRINT_STRING",
  "BX_TOKEN_NUMERIC", "BX_TOKEN_NE2000", "BX_TOKEN_PIC", "BX_TOKEN_PAGE",
  "BX_TOKEN_HELP", "BX_TOKEN_CALC", "BX_TOKEN_VGA", "BX_TOKEN_PCI",
  "BX_TOKEN_COMMAND", "BX_TOKEN_GENERIC", "BX_TOKEN_RSHIFT",
  "BX_TOKEN_LSHIFT", "BX_TOKEN_REG_IP", "BX_TOKEN_REG_EIP",
  "BX_TOKEN_REG_RIP", "'+'", "'-'", "'|'", "'^'", "'*'", "'/'", "'&'",
  "NEG", "NOT", "'\\n'", "'='", "':'", "'!'", "'('", "')'", "$accept",
  "commands", "command", "BX_TOKEN_TOGGLE_ON_OFF", "BX_TOKEN_REGISTERS",
  "BX_TOKEN_SEGREG", "timebp_command", "record_command",
  "playback_command", "modebp_command", "show_command", "page_command",
  "ptime_command", "trace_command", "trace_reg_command",
  "trace_mem_command", "print_stack_command", "watch_point_command",
  "symbol_command", "where_command", "print_string_command",
  "continue_command", "stepN_command", "step_over_command", "set_command",
  "breakpoint_command", "blist_command", "slist_command", "info_command",
  "optional_numeric", "regs_command", "fpu_regs_command",
  "mmx_regs_command", "sse_regs_command", "segment_regs_command",
  "control_regs_command", "debug_regs_command", "delete_command",
  "bpe_command", "bpd_command", "quit_command", "examine_command",
  "restore_command", "setpmem_command", "query_command", "take_command",
  "disassemble_command", "instrument_command", "doit_command",
  "crc_command", "help_command", "calc_command", "vexpression",
  "expression", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,    43,    45,   124,    94,    42,    47,    38,
     358,   359,    10,    61,    58,    33,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   118,   119,   119,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   121,   121,   122,   122,   123,   123,   123,   123,   123,
     123,   124,   124,   125,   126,   127,   128,   128,   128,   129,
     130,   131,   132,   133,   134,   134,   135,   135,   135,   135,
     135,   135,   135,   135,   136,   136,   136,   136,   137,   138,
     139,   140,   140,   141,   142,   142,   142,   142,   142,   142,
     142,   143,   143,   143,   143,   143,   143,   143,   143,   144,
     145,   145,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     147,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   159,   159,   159,   160,   161,   162,
     163,   163,   163,   164,   164,   164,   164,   164,   164,   164,
     164,   165,   165,   166,   167,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   169,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     2,     3,     3,     2,     3,
       2,     3,     3,     3,     2,     3,     3,     3,     2,     4,
       4,     4,     2,     3,     3,     4,     4,     5,     2,     3,
       2,     2,     3,     2,     4,     5,     5,     5,     5,     5,
       5,     2,     5,     2,     3,     3,     2,     3,     4,     2,
       2,     3,     3,     3,     5,     5,     5,     5,     3,     3,
       3,     3,     3,     4,     3,     5,     7,     3,     3,     3,
       0,     1,     2,     2,     2,     2,     2,     2,     2,     3,
       3,     3,     2,     4,     3,     3,     2,     4,     5,     3,
       3,     4,     3,     2,     3,     4,     3,     4,     5,     3,
       5,     3,     3,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     3,     0,    36,    37,    38,    39,    43,
      42,    35,    32,    33,    34,    40,    41,    44,    45,    46,
       4,     5,     6,     7,     8,    17,    18,     9,    10,    11,
      12,    13,    14,    16,    15,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    47,    48,
      90,     0,    91,    93,     0,     0,     0,     0,     0,     0,
       0,   109,   212,   211,   213,   214,   215,    55,    56,    57,
      58,    59,    60,   210,   217,   218,   219,     0,   101,     0,
       0,   216,     0,   235,   234,   236,   237,   238,   233,   232,
     240,   241,   242,     0,   103,     0,     0,   239,     0,   233,
       0,   106,     0,     0,     0,     0,     0,     0,     0,   130,
     130,   130,   130,     0,     0,     0,     0,     0,     0,     0,
       0,   142,   133,   135,   134,   138,   137,   136,     0,   146,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   153,
       0,     0,     0,     0,     0,    51,    52,     0,     0,     0,
      70,     0,     0,     0,     0,    65,     0,    74,     0,     0,
       0,     0,     0,    78,    82,     0,     0,     0,    68,     0,
       0,     0,   110,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   208,     0,
       0,     1,     2,   132,    92,     0,     0,     0,     0,     0,
       0,     0,   230,   229,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   254,   253,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,     0,
       0,   107,   139,   140,   141,   120,   112,   113,   131,   130,
     130,   130,   130,   119,   118,   121,     0,   122,     0,   124,
     127,   128,   129,   144,     0,   145,     0,     0,   149,     0,
     150,   152,   156,     0,   159,     0,     0,   154,     0,   161,
     162,   163,     0,    71,    72,    73,    62,    61,    63,    64,
      75,    77,     0,    76,     0,     0,    83,    67,    66,     0,
      84,     0,   111,    89,    69,   166,   167,   168,   202,   175,
     169,   170,   171,   172,   173,   174,   204,   165,   191,   193,
     192,   195,   194,   200,   181,   196,   197,   201,   177,   178,
     179,   180,   182,   184,   183,   186,   187,   176,   185,   198,
     199,   205,   188,   189,   203,   207,   206,   190,   209,     0,
       0,     0,     0,     0,     0,    94,   231,   224,   225,   220,
     221,   226,   227,   222,   223,   228,     0,   255,   248,   249,
     244,   245,   250,   251,   246,   247,   252,   243,   108,     0,
       0,     0,     0,   123,     0,   143,   147,     0,   151,   157,
       0,     0,   245,   155,   164,    79,    80,    81,    85,     0,
      86,    97,    96,    98,    99,   100,    95,   102,   114,   115,
     116,   117,   125,     0,   148,   158,   160,    87,     0,   126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    52,    53,   197,    54,   147,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,   319,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   132,   148
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -145
static const yytype_int16 yypact[] =
{
     758,  -103,   -42,   -72,    68,   -70,    85,   371,   337,   -41,
     -38,   -37,    19,   -43,  -145,  -145,   -31,   -30,   -28,    -9,
      -8,    -2,   354,    44,    24,    52,   -46,    18,   -52,    27,
      29,    23,    23,    23,    -1,    40,    41,    74,    76,    32,
     -36,   -13,   485,   -48,    -5,   -47,    45,    70,   544,   836,
     544,  -145,   656,  -145,    47,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,    48,  -145,  -145,    43,    59,    61,    67,    69,    71,
      23,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,   658,  -145,   658,
     658,  -145,  1038,  -145,  -145,  -145,  -145,  -145,    78,  -145,
    -145,  -145,  -145,   544,  -145,   544,   544,  -145,   462,  -145,
     544,  -145,   827,    79,    80,    81,    82,    83,    84,    93,
      93,    93,    93,    94,    98,    99,   -29,   -57,   101,   103,
     115,  -145,  -145,  -145,  -145,  -145,  -145,  -145,   502,  -145,
     846,   127,   124,   116,   -34,   117,   519,   119,   120,  -145,
     142,   122,   123,   125,   144,  -145,  -145,   126,   140,   141,
    -145,   143,   147,   148,   149,  -145,   150,  -145,   151,   544,
     152,   544,   544,  -145,  -145,   858,   153,   154,  -145,   -11,
     175,   155,  -145,  -145,   161,   870,   163,   164,   165,   166,
     167,   168,   179,   191,   192,   193,   194,   195,   196,   197,
     198,   211,   212,   214,   218,   219,   220,   221,   222,   223,
     225,   226,   239,   240,   241,   242,   243,   244,   256,   257,
     258,   259,   260,   261,   275,   276,   277,   285,  -145,   288,
     882,  -145,  -145,  -145,  -145,   544,   544,   544,   544,   544,
     311,   290,  -145,  -145,   313,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,  -145,   292,   292,   287,   544,
     544,   544,   544,   544,   544,   544,   544,   544,  -145,   544,
     894,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,    93,
      93,    93,    93,  -145,  -145,  -145,   295,  -145,   320,  -145,
    -145,  -145,  -145,  -145,   906,  -145,   297,   322,  -145,   301,
    -145,  -145,  -145,   213,  -145,   326,   544,  -145,   918,  -145,
    -145,  -145,   312,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,   930,  -145,   942,   954,  -145,  -145,  -145,   314,
    -145,    12,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,   966,
     978,   990,  1002,  1014,   315,  -145,  -145,  -145,  -145,    33,
      33,    33,    33,  -145,  -145,  -145,  1062,  -145,   292,   292,
     100,   100,   100,   100,   292,   292,   292,  1050,  -145,   316,
     317,   319,   321,  -145,     4,  -145,  -145,   323,  -145,  -145,
    1026,   324,   484,  -145,  -145,  -145,  -145,  -145,  -145,   328,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,   335,  -145,  -145,  -145,  -145,   331,  -145
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,   187,   -25,   -49,    -4,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -144,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -124,    -7
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -255
static const yytype_int16 yytable[] =
{
     269,   152,   131,   282,   208,   283,   284,   198,   199,   100,
     191,   184,   185,   216,   221,   180,   320,   321,   322,   209,
     190,   133,   134,   135,   136,   137,   117,   118,   119,   120,
     121,   122,   326,   156,   328,   215,    14,    15,   195,   196,
     103,   225,   111,   270,   192,   157,   101,   153,   217,   210,
     154,   155,   206,   158,   339,   329,   219,   159,   160,   161,
     162,   163,   164,   165,   218,   222,   211,   212,   186,   171,
     102,   104,   105,   106,   107,   108,   207,   369,   340,   149,
     220,   172,   173,   327,   174,   281,   187,   188,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   213,
     469,   370,   166,   175,   176,   181,   139,   183,   167,   168,
     177,   200,   182,   169,   170,   193,   482,   194,   140,   141,
     142,   109,   143,   131,   470,   131,   131,   110,   201,   202,
     189,   285,   286,   145,   146,   203,   296,   204,   297,   298,
     291,   292,   293,   310,   205,   133,   134,   135,   136,   137,
     117,   118,   119,   120,   121,   122,   275,   223,   224,   273,
     274,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   334,   276,   123,   277,   449,   450,   451,   452,   343,
     278,   318,   279,   348,   280,   124,   125,   126,   336,   127,
     295,   312,   313,   314,   315,   316,   317,   128,   299,   300,
     129,   130,   362,   149,   364,   365,   323,   305,   306,   307,
     324,   325,   337,   330,   309,   331,   133,   134,   135,   136,
     137,   117,   118,   119,   120,   121,   122,   332,   338,   341,
     139,   344,   352,   345,   349,   350,   371,   351,   353,   272,
     299,   300,   140,   141,   142,   301,   346,   303,   304,   305,
     306,   307,   354,   355,   347,   356,   309,   145,   146,   357,
     358,   359,   360,   361,   363,   367,   368,   372,   419,   420,
     421,   422,   423,   373,   149,   375,   376,   377,   378,   379,
     380,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   381,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   139,   447,   382,   383,   384,   385,   386,   387,   388,
     389,   299,   300,   140,   141,   142,   301,   346,   303,   304,
     305,   306,   307,   390,   391,   459,   392,   309,   145,   146,
     393,   394,   395,   396,   397,   398,   460,   399,   400,   462,
     133,   134,   135,   136,   137,   117,   118,   119,   120,   121,
     122,   401,   402,   403,   404,   405,   406,   133,   134,   135,
     136,   137,   117,   118,   119,   120,   121,   122,   407,   408,
     409,   410,   411,   412,   133,   134,   135,   136,   137,   117,
     118,   119,   120,   121,   122,   299,   300,   413,   414,   415,
     301,   302,   303,   304,   305,   306,   307,   416,   149,   424,
     417,   309,   425,   178,   437,   483,   309,   453,   454,   456,
     457,   285,   286,   458,   461,   149,   287,   288,   289,   290,
     291,   292,   293,   488,   464,   139,   468,   476,   478,   479,
     426,   480,   138,   481,     0,   484,   486,   140,   141,   142,
     487,   143,   139,   489,   150,     0,     0,     0,     0,   151,
       0,     0,   145,   146,   140,   141,   142,     0,   143,   139,
       0,     0,     0,     0,     0,     0,   179,     0,     0,   145,
     146,   140,   141,   142,     0,   143,     0,     0,     0,     0,
       0,     0,     0,   144,     0,     0,   145,   146,   133,   134,
     135,   136,   137,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,   133,   134,   135,   136,   137,
     117,   118,   119,   120,   121,   122,     0,     0,     0,     0,
       0,     0,   133,   134,   135,   136,   137,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,   133,   134,   135,
     136,   137,   117,   118,   119,   120,   121,   122,     0,     0,
     299,   300,     0,   149,     0,   301,   302,   303,   304,   305,
     306,   307,     0,   139,   308,     0,   309,     0,     0,     0,
     149,     0,  -254,  -254,     0,   140,   141,   142,     0,   143,
     139,  -254,  -254,  -254,     0,     0,     0,   214,   309,     0,
     145,   146,   140,   141,   142,   149,   143,   139,     0,     0,
       0,     0,     0,     0,   333,     0,     0,   145,   146,   140,
     141,   142,     0,   143,     0,     0,     0,     0,     0,     0,
       0,   342,   139,     0,   145,   146,     0,     0,     0,     0,
       0,     0,     0,     0,   140,   141,   142,     0,   143,     0,
       0,     0,     0,     0,     0,     0,   271,     0,     0,   145,
     146,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,     0,     1,     2,     3,     0,     4,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,    19,    20,    21,    22,     0,     0,    23,    24,     0,
      25,     0,    26,     0,     0,    27,    28,     0,     0,    29,
      30,    31,    32,    33,     0,     0,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     0,     0,    43,    44,     0,
      45,     0,    46,    47,     0,     0,   123,    48,    49,    50,
       0,     0,     0,     0,     0,     0,     0,     0,   124,   125,
     126,     0,   127,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,   129,   130,     1,     2,     3,     0,     4,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,    16,    17,    18,     0,     0,     0,     0,
       0,     0,     0,    19,    20,    21,    22,     0,     0,    23,
      24,     0,    25,     0,    26,     0,     0,    27,    28,     0,
       0,    29,    30,    31,    32,    33,     0,     0,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     0,     0,    43,
      44,     0,    45,     0,    46,    47,     0,     0,     0,    48,
      49,    50,     0,   226,   227,   228,     0,   229,     0,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    14,    15,
      51,   239,   240,   241,     0,     0,     0,     0,     0,     0,
       0,     0,   242,   243,   244,     0,     0,   245,   246,     0,
       0,     0,     0,     0,     0,   247,   248,     0,     0,     0,
     249,   250,   251,   252,     0,     0,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,     0,   262,   263,     0,
     264,     0,     0,     0,     0,   299,   300,   265,   266,   267,
     301,   302,   303,   304,   305,   306,   307,     0,     0,   311,
       0,   309,     0,     0,   299,   300,     0,     0,   268,   301,
     302,   303,   304,   305,   306,   307,   299,   300,   335,     0,
     309,   301,   302,   303,   304,   305,   306,   307,   299,   300,
     366,     0,   309,   301,   302,   303,   304,   305,   306,   307,
     299,   300,   374,     0,   309,   301,   302,   303,   304,   305,
     306,   307,   299,   300,   418,     0,   309,   301,   302,   303,
     304,   305,   306,   307,   299,   300,   448,     0,   309,   301,
     302,   303,   304,   305,   306,   307,   299,   300,   455,     0,
     309,   301,   302,   303,   304,   305,   306,   307,   299,   300,
     463,     0,   309,   301,   302,   303,   304,   305,   306,   307,
     299,   300,   465,     0,   309,   301,   302,   303,   304,   305,
     306,   307,   299,   300,   466,     0,   309,   301,   302,   303,
     304,   305,   306,   307,   299,   300,   467,     0,   309,   301,
     302,   303,   304,   305,   306,   307,   299,   300,   471,     0,
     309,   301,   302,   303,   304,   305,   306,   307,   299,   300,
     472,     0,   309,   301,   302,   303,   304,   305,   306,   307,
     299,   300,   473,     0,   309,   301,   302,   303,   304,   305,
     306,   307,   299,   300,   474,     0,   309,   301,   302,   303,
     304,   305,   306,   307,   299,   300,   475,     0,   309,   301,
     302,   303,   304,   305,   306,   307,   285,   286,   485,     0,
     309,   287,   288,   289,   290,   291,   292,   293,   299,   300,
       0,     0,   294,   301,   302,   303,   304,   305,   306,   307,
     285,   286,     0,     0,   309,   287,   288,   289,   290,   291,
     292,   293,     0,     0,   477
};

static const yytype_int16 yycheck[] =
{
      49,     8,     6,   127,    17,   129,   130,    32,    33,   112,
      62,    57,    58,    61,    61,    22,   160,   161,   162,    32,
      27,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    61,    14,    91,    42,    32,    33,    15,    16,
     112,    48,   112,    50,    96,    26,    88,    88,    96,    62,
      88,    88,    88,    34,    88,   112,    61,    38,    39,    40,
      41,    42,    43,    44,   112,   112,    79,    80,    50,   112,
     112,     3,     4,     5,     6,     7,   112,    88,   112,    61,
      85,   112,   112,   112,   112,   110,    68,    69,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,   112,
      88,   112,    83,   112,   112,    61,    88,    55,    89,    90,
     112,   112,    88,    94,    95,    88,   112,    88,   100,   101,
     102,    53,   104,   127,   112,   129,   130,    59,    88,    88,
     112,    98,    99,   115,   116,    61,   143,    61,   145,   146,
     107,   108,   109,   150,   112,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,   113,   112,    88,   112,
     112,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   178,   113,    88,   113,   319,   320,   321,   322,   186,
     113,    88,   113,   190,   113,   100,   101,   102,    61,   104,
     112,   112,   112,   112,   112,   112,   112,   112,    98,    99,
     115,   116,   209,    61,   211,   212,   112,   107,   108,   109,
     112,   112,    88,   112,   114,   112,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,   112,   112,   112,
      88,   112,    88,   113,   112,   112,    61,   112,   112,    52,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   112,   112,   112,   112,   114,   115,   116,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   275,   276,
     277,   278,   279,   112,    61,   112,   112,   112,   112,   112,
     112,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   112,   299,   300,   301,   302,   303,   304,   305,   306,
     307,    88,   309,   112,   112,   112,   112,   112,   112,   112,
     112,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   112,   112,   112,   112,   114,   115,   116,
     112,   112,   112,   112,   112,   112,   343,   112,   112,   346,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,   112,   112,   112,   112,   112,   112,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,   112,   112,
     112,   112,   112,   112,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    98,    99,   112,   112,   112,
     103,   104,   105,   106,   107,   108,   109,   112,    61,    88,
     112,   114,   112,    49,   117,   454,   114,   112,    88,   112,
      88,    98,    99,   112,    88,    61,   103,   104,   105,   106,
     107,   108,   109,    88,   112,    88,   112,   112,   112,   112,
     117,   112,    61,   112,    -1,   112,   112,   100,   101,   102,
     112,   104,    88,   112,   107,    -1,    -1,    -1,    -1,   112,
      -1,    -1,   115,   116,   100,   101,   102,    -1,   104,    88,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,
     116,   100,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,    -1,    -1,   115,   116,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      98,    99,    -1,    61,    -1,   103,   104,   105,   106,   107,
     108,   109,    -1,    88,   112,    -1,   114,    -1,    -1,    -1,
      61,    -1,    98,    99,    -1,   100,   101,   102,    -1,   104,
      88,   107,   108,   109,    -1,    -1,    -1,   112,   114,    -1,
     115,   116,   100,   101,   102,    61,   104,    88,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    -1,    -1,   115,   116,   100,
     101,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    88,    -1,   115,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,   102,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,   115,
     116,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    17,    18,    19,    -1,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    -1,    -1,    51,    52,    -1,
      54,    -1,    56,    -1,    -1,    59,    60,    -1,    -1,    63,
      64,    65,    66,    67,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    -1,    81,    82,    -1,
      84,    -1,    86,    87,    -1,    -1,    88,    91,    92,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
     102,    -1,   104,    -1,    -1,    -1,    -1,    -1,   112,    -1,
      -1,    -1,    -1,   115,   116,    17,    18,    19,    -1,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    -1,    -1,    51,
      52,    -1,    54,    -1,    56,    -1,    -1,    59,    60,    -1,
      -1,    63,    64,    65,    66,    67,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    -1,    81,
      82,    -1,    84,    -1,    86,    87,    -1,    -1,    -1,    91,
      92,    93,    -1,    17,    18,    19,    -1,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
     112,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    -1,    81,    82,    -1,
      84,    -1,    -1,    -1,    -1,    98,    99,    91,    92,    93,
     103,   104,   105,   106,   107,   108,   109,    -1,    -1,   112,
      -1,   114,    -1,    -1,    98,    99,    -1,    -1,   112,   103,
     104,   105,   106,   107,   108,   109,    98,    99,   112,    -1,
     114,   103,   104,   105,   106,   107,   108,   109,    98,    99,
     112,    -1,   114,   103,   104,   105,   106,   107,   108,   109,
      98,    99,   112,    -1,   114,   103,   104,   105,   106,   107,
     108,   109,    98,    99,   112,    -1,   114,   103,   104,   105,
     106,   107,   108,   109,    98,    99,   112,    -1,   114,   103,
     104,   105,   106,   107,   108,   109,    98,    99,   112,    -1,
     114,   103,   104,   105,   106,   107,   108,   109,    98,    99,
     112,    -1,   114,   103,   104,   105,   106,   107,   108,   109,
      98,    99,   112,    -1,   114,   103,   104,   105,   106,   107,
     108,   109,    98,    99,   112,    -1,   114,   103,   104,   105,
     106,   107,   108,   109,    98,    99,   112,    -1,   114,   103,
     104,   105,   106,   107,   108,   109,    98,    99,   112,    -1,
     114,   103,   104,   105,   106,   107,   108,   109,    98,    99,
     112,    -1,   114,   103,   104,   105,   106,   107,   108,   109,
      98,    99,   112,    -1,   114,   103,   104,   105,   106,   107,
     108,   109,    98,    99,   112,    -1,   114,   103,   104,   105,
     106,   107,   108,   109,    98,    99,   112,    -1,   114,   103,
     104,   105,   106,   107,   108,   109,    98,    99,   112,    -1,
     114,   103,   104,   105,   106,   107,   108,   109,    98,    99,
      -1,    -1,   114,   103,   104,   105,   106,   107,   108,   109,
      98,    99,    -1,    -1,   114,   103,   104,   105,   106,   107,
     108,   109,    -1,    -1,   112
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    18,    19,    21,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    45,
      46,    47,    48,    51,    52,    54,    56,    59,    60,    63,
      64,    65,    66,    67,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    81,    82,    84,    86,    87,    91,    92,
      93,   112,   119,   120,   122,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     112,    88,   112,   112,     3,     4,     5,     6,     7,    53,
      59,   112,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    88,   100,   101,   102,   104,   112,   115,
     116,   123,   170,     3,     4,     5,     6,     7,    61,    88,
     100,   101,   102,   104,   112,   115,   116,   123,   171,    61,
     107,   112,   171,    88,    88,    88,    14,    26,    34,    38,
      39,    40,    41,    42,    43,    44,    83,    89,    90,    94,
      95,   112,   112,   112,   112,   112,   112,   112,    49,   112,
     171,    61,    88,    55,    57,    58,    50,    68,    69,   112,
     171,    62,    96,    88,    88,    15,    16,   121,   121,   121,
     112,    88,    88,    61,    61,   112,    88,   112,    17,    32,
      62,    79,    80,   112,   112,   171,    61,    96,   112,    61,
      85,    61,   112,   112,    88,   171,    17,    18,    19,    21,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    35,
      36,    37,    46,    47,    48,    51,    52,    59,    60,    64,
      65,    66,    67,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    81,    82,    84,    91,    92,    93,   112,   122,
     171,     0,   120,   112,   112,   113,   113,   113,   113,   113,
     113,   121,   170,   170,   170,    98,    99,   103,   104,   105,
     106,   107,   108,   109,   114,   112,   171,   171,   171,    98,
      99,   103,   104,   105,   106,   107,   108,   109,   112,   114,
     171,   112,   112,   112,   112,   112,   112,   112,    88,   147,
     147,   147,   147,   112,   112,   112,    61,   112,    91,   112,
     112,   112,   112,   112,   171,   112,    61,    88,   112,    88,
     112,   112,   112,   171,   112,   113,   104,   112,   171,   112,
     112,   112,    88,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   171,   112,   171,   171,   112,   112,   112,    88,
     112,    61,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   171,
     171,   171,   171,   171,    88,   112,   117,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   117,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   112,   147,
     147,   147,   147,   112,    88,   112,   112,    88,   112,   112,
     171,    88,   171,   112,   112,   112,   112,   112,   112,    88,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   122,   112,   112,   112,   112,    88,   112
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
# if YYLTYPE_IS_TRIVIAL
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
        case 50:
#line 189 "parser.y"
    {
      }
    break;

  case 52:
#line 196 "parser.y"
    { (yyval.bval)=(yyvsp[(1) - (1)].bval); }
    break;

  case 54:
#line 202 "parser.y"
    { (yyval.sval)=(yyvsp[(1) - (1)].sval); }
    break;

  case 60:
#line 212 "parser.y"
    { (yyval.uval)=(yyvsp[(1) - (1)].uval); }
    break;

  case 61:
#line 217 "parser.y"
    {
          bx_dbg_timebp_command(0, (yyvsp[(2) - (3)].uval));
          free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 62:
#line 222 "parser.y"
    {
          bx_dbg_timebp_command(1, (yyvsp[(2) - (3)].uval));
          free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 63:
#line 230 "parser.y"
    {
          bx_dbg_record_command((yyvsp[(2) - (3)].sval));
          free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 64:
#line 238 "parser.y"
    {
          bx_dbg_playback_command((yyvsp[(2) - (3)].sval));
          free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 65:
#line 246 "parser.y"
    {
          bx_dbg_modebp_command();
          free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 66:
#line 254 "parser.y"
    {
          bx_dbg_show_command((yyvsp[(2) - (3)].sval));
          free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 67:
#line 259 "parser.y"
    {
          bx_dbg_show_param_command((yyvsp[(2) - (3)].sval));
          free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 68:
#line 264 "parser.y"
    {
          bx_dbg_show_command(0);
          free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 69:
#line 272 "parser.y"
    {
          bx_dbg_xlate_address((yyvsp[(2) - (3)].uval));
          free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 70:
#line 280 "parser.y"
    {
          bx_dbg_ptime_command();
          free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 71:
#line 288 "parser.y"
    {
          bx_dbg_trace_command((yyvsp[(2) - (3)].bval));
          free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 72:
#line 296 "parser.y"
    {
          bx_dbg_trace_reg_command((yyvsp[(2) - (3)].bval));
          free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 73:
#line 304 "parser.y"
    {
          bx_dbg_trace_mem_command((yyvsp[(2) - (3)].bval));
          free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 74:
#line 312 "parser.y"
    {
          bx_dbg_print_stack_command(16);
          free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 75:
#line 317 "parser.y"
    {
          bx_dbg_print_stack_command((yyvsp[(2) - (3)].uval));
          free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 76:
#line 325 "parser.y"
    {
          watchpoint_continue = 0;
          dbg_printf("Will stop on watch points\n");
          free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 77:
#line 331 "parser.y"
    {
          watchpoint_continue = 1;
          dbg_printf("Will not stop on watch points (they will still be logged)\n");
          free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 78:
#line 337 "parser.y"
    {
          bx_dbg_print_watchpoints();
          free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 79:
#line 342 "parser.y"
    {
          bx_dbg_watch(0, (yyvsp[(3) - (4)].uval)); /* BX_READ */
          free((yyvsp[(1) - (4)].sval)); free((yyvsp[(2) - (4)].sval));
      }
    break;

  case 80:
#line 347 "parser.y"
    {
          bx_dbg_watch(0, (yyvsp[(3) - (4)].uval)); /* BX_READ */
          free((yyvsp[(1) - (4)].sval)); free((yyvsp[(2) - (4)].sval));
      }
    break;

  case 81:
#line 352 "parser.y"
    {
          bx_dbg_watch(1, (yyvsp[(3) - (4)].uval)); /* BX_WRITE */
          free((yyvsp[(1) - (4)].sval)); free((yyvsp[(2) - (4)].sval));
      }
    break;

  case 82:
#line 357 "parser.y"
    {
          bx_dbg_unwatch_all();
          free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 83:
#line 362 "parser.y"
    {
          bx_dbg_unwatch((yyvsp[(2) - (3)].uval));
          free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 84:
#line 370 "parser.y"
    {
        bx_dbg_symbol_command((yyvsp[(2) - (3)].sval), 0, 0);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 85:
#line 375 "parser.y"
    {
        bx_dbg_symbol_command((yyvsp[(2) - (4)].sval), 0, (yyvsp[(3) - (4)].uval));
        free((yyvsp[(1) - (4)].sval)); free((yyvsp[(2) - (4)].sval));
      }
    break;

  case 86:
#line 380 "parser.y"
    {
        bx_dbg_symbol_command((yyvsp[(3) - (4)].sval), 1, 0);
        free((yyvsp[(1) - (4)].sval)); free((yyvsp[(2) - (4)].sval)); free((yyvsp[(3) - (4)].sval));
      }
    break;

  case 87:
#line 385 "parser.y"
    {
        bx_dbg_symbol_command((yyvsp[(3) - (5)].sval), 1, (yyvsp[(4) - (5)].uval));
        free((yyvsp[(1) - (5)].sval)); free((yyvsp[(2) - (5)].sval)); free((yyvsp[(3) - (5)].sval));
      }
    break;

  case 88:
#line 393 "parser.y"
    {
        bx_dbg_where_command();
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 89:
#line 401 "parser.y"
    {
        bx_dbg_print_string_command((yyvsp[(2) - (3)].uval));
        free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 90:
#line 409 "parser.y"
    {
        bx_dbg_continue_command();
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 91:
#line 417 "parser.y"
    {
        bx_dbg_stepN_command(1);
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 92:
#line 422 "parser.y"
    {
        bx_dbg_stepN_command((yyvsp[(2) - (3)].uval));
        free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 93:
#line 430 "parser.y"
    {
        bx_dbg_step_over_command();
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 94:
#line 438 "parser.y"
    {
        bx_dbg_set_auto_disassemble((yyvsp[(3) - (4)].bval));
        free((yyvsp[(1) - (4)].sval)); free((yyvsp[(2) - (4)].sval));
      }
    break;

  case 95:
#line 443 "parser.y"
    {
        bx_dbg_set_symbol_command((yyvsp[(2) - (5)].sval), (yyvsp[(4) - (5)].uval));
        free((yyvsp[(1) - (5)].sval)); free((yyvsp[(2) - (5)].sval));
      }
    break;

  case 96:
#line 448 "parser.y"
    { 
        bx_dbg_set_reg8l_value((yyvsp[(2) - (5)].uval), (yyvsp[(4) - (5)].uval));
      }
    break;

  case 97:
#line 452 "parser.y"
    { 
        bx_dbg_set_reg8h_value((yyvsp[(2) - (5)].uval), (yyvsp[(4) - (5)].uval));
      }
    break;

  case 98:
#line 456 "parser.y"
    { 
        bx_dbg_set_reg16_value((yyvsp[(2) - (5)].uval), (yyvsp[(4) - (5)].uval));
      }
    break;

  case 99:
#line 460 "parser.y"
    { 
        bx_dbg_set_reg32_value((yyvsp[(2) - (5)].uval), (yyvsp[(4) - (5)].uval));
      }
    break;

  case 100:
#line 464 "parser.y"
    { 
        bx_dbg_set_reg64_value((yyvsp[(2) - (5)].uval), (yyvsp[(4) - (5)].uval));
      }
    break;

  case 101:
#line 471 "parser.y"
    {
        bx_dbg_vbreakpoint_command(bkAtIP, 0, 0);
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 102:
#line 476 "parser.y"
    {
        bx_dbg_vbreakpoint_command(bkRegular, (yyvsp[(2) - (5)].uval), (yyvsp[(4) - (5)].uval));
        free((yyvsp[(1) - (5)].sval));
      }
    break;

  case 103:
#line 481 "parser.y"
    {
        bx_dbg_lbreakpoint_command(bkAtIP, 0);
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 104:
#line 486 "parser.y"
    {
        bx_dbg_lbreakpoint_command(bkRegular, (yyvsp[(2) - (3)].uval));
        free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 105:
#line 491 "parser.y"
    {
        bx_dbg_lbreakpoint_symbol_command((yyvsp[(2) - (3)].sval));
        free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 106:
#line 496 "parser.y"
    {
        bx_dbg_pbreakpoint_command(bkAtIP, 0);
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 107:
#line 501 "parser.y"
    {
        bx_dbg_pbreakpoint_command(bkRegular, (yyvsp[(2) - (3)].uval));
        free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 108:
#line 506 "parser.y"
    {
        bx_dbg_pbreakpoint_command(bkRegular, (yyvsp[(3) - (4)].uval));
        free((yyvsp[(1) - (4)].sval));
      }
    break;

  case 109:
#line 514 "parser.y"
    {
        bx_dbg_info_bpoints_command();
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 110:
#line 522 "parser.y"
    {
        bx_dbg_info_symbols_command(0);
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 111:
#line 527 "parser.y"
    {
        bx_dbg_info_symbols_command((yyvsp[(2) - (3)].sval));
        free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 112:
#line 535 "parser.y"
    {
        bx_dbg_info_bpoints_command();
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 113:
#line 540 "parser.y"
    {
        bx_dbg_info_registers_command(BX_INFO_GENERAL_PURPOSE_REGS | BX_INFO_FPU_REGS | BX_INFO_SSE_REGS);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 114:
#line 545 "parser.y"
    {
        bx_dbg_info_idt_command((yyvsp[(3) - (5)].uval), (yyvsp[(4) - (5)].uval));
        free((yyvsp[(1) - (5)].sval)); free((yyvsp[(2) - (5)].sval));
      }
    break;

  case 115:
#line 550 "parser.y"
    {
        bx_dbg_info_ivt_command((yyvsp[(3) - (5)].uval), (yyvsp[(4) - (5)].uval));
        free((yyvsp[(1) - (5)].sval)); free((yyvsp[(2) - (5)].sval));
      }
    break;

  case 116:
#line 555 "parser.y"
    {
        bx_dbg_info_gdt_command((yyvsp[(3) - (5)].uval), (yyvsp[(4) - (5)].uval));
        free((yyvsp[(1) - (5)].sval)); free((yyvsp[(2) - (5)].sval));
      }
    break;

  case 117:
#line 560 "parser.y"
    {
        bx_dbg_info_ldt_command((yyvsp[(3) - (5)].uval), (yyvsp[(4) - (5)].uval));
        free((yyvsp[(1) - (5)].sval)); free((yyvsp[(2) - (5)].sval));
      }
    break;

  case 118:
#line 565 "parser.y"
    {
        bx_dbg_dump_table();
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 119:
#line 570 "parser.y"
    {
        bx_dbg_info_tss_command();
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 120:
#line 575 "parser.y"
    {
        bx_dbg_info_flags();
        free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 121:
#line 580 "parser.y"
    {
        bx_dbg_info_linux_command();
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 122:
#line 585 "parser.y"
    {
        bx_dbg_info_symbols_command(0);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 123:
#line 590 "parser.y"
    {
        bx_dbg_info_symbols_command((yyvsp[(3) - (4)].sval));
        free((yyvsp[(1) - (4)].sval)); free((yyvsp[(2) - (4)].sval)); free((yyvsp[(3) - (4)].sval));
      }
    break;

  case 124:
#line 595 "parser.y"
    {
        bx_dbg_info_ne2k(-1, -1);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 125:
#line 600 "parser.y"
    {
        free((yyvsp[(1) - (5)].sval)); free((yyvsp[(2) - (5)].sval)); free((yyvsp[(3) - (5)].sval));
        bx_dbg_info_ne2k((yyvsp[(4) - (5)].uval), -1);
      }
    break;

  case 126:
#line 605 "parser.y"
    {
        free((yyvsp[(1) - (7)].sval)); free((yyvsp[(2) - (7)].sval)); free((yyvsp[(3) - (7)].sval)); free((yyvsp[(5) - (7)].sval));
        bx_dbg_info_ne2k((yyvsp[(4) - (7)].uval), (yyvsp[(6) - (7)].uval));
      }
    break;

  case 127:
#line 610 "parser.y"
    {
        bx_dbg_info_pic();
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 128:
#line 615 "parser.y"
    {
        bx_dbg_info_vga();
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 129:
#line 620 "parser.y"
    {
        bx_dbg_info_pci();
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 130:
#line 627 "parser.y"
    { (yyval.uval) = EMPTY_ARG; }
    break;

  case 132:
#line 632 "parser.y"
    {
        bx_dbg_info_registers_command(BX_INFO_GENERAL_PURPOSE_REGS);
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 133:
#line 640 "parser.y"
    {
        bx_dbg_info_registers_command(BX_INFO_FPU_REGS);
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 134:
#line 648 "parser.y"
    {
        bx_dbg_info_registers_command(BX_INFO_MMX_REGS);
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 135:
#line 656 "parser.y"
    {
        bx_dbg_info_registers_command(BX_INFO_SSE_REGS);
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 136:
#line 664 "parser.y"
    {
        bx_dbg_info_segment_regs_command();
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 137:
#line 672 "parser.y"
    {
        bx_dbg_info_control_regs_command();
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 138:
#line 680 "parser.y"
    {
        bx_dbg_info_debug_regs_command();
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 139:
#line 688 "parser.y"
    {
        bx_dbg_del_breakpoint_command((yyvsp[(2) - (3)].uval));
        free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 140:
#line 696 "parser.y"
    {
        bx_dbg_en_dis_breakpoint_command((yyvsp[(2) - (3)].uval), 1);
        free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 141:
#line 703 "parser.y"
    {
        bx_dbg_en_dis_breakpoint_command((yyvsp[(2) - (3)].uval), 0);
        free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 142:
#line 711 "parser.y"
    {
        bx_dbg_quit_command();
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 143:
#line 719 "parser.y"
    {
        bx_dbg_examine_command((yyvsp[(1) - (4)].sval), (yyvsp[(2) - (4)].sval),1, (yyvsp[(3) - (4)].uval), 1);
        free((yyvsp[(1) - (4)].sval)); free((yyvsp[(2) - (4)].sval));
      }
    break;

  case 144:
#line 724 "parser.y"
    {
        bx_dbg_examine_command((yyvsp[(1) - (3)].sval), (yyvsp[(2) - (3)].sval),1, 0, 0);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 145:
#line 729 "parser.y"
    {
        bx_dbg_examine_command((yyvsp[(1) - (3)].sval), NULL,0, (yyvsp[(2) - (3)].uval), 1);
        free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 146:
#line 734 "parser.y"
    {
        bx_dbg_examine_command((yyvsp[(1) - (2)].sval), NULL,0, 0, 0);
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 147:
#line 742 "parser.y"
    {
        bx_dbg_restore_command((yyvsp[(2) - (4)].sval), (yyvsp[(3) - (4)].sval));
        free((yyvsp[(1) - (4)].sval)); free((yyvsp[(2) - (4)].sval)); free((yyvsp[(3) - (4)].sval));
      }
    break;

  case 148:
#line 750 "parser.y"
    {
        bx_dbg_setpmem_command((yyvsp[(2) - (5)].uval), (yyvsp[(3) - (5)].uval), (yyvsp[(4) - (5)].uval));
        free((yyvsp[(1) - (5)].sval));
      }
    break;

  case 149:
#line 758 "parser.y"
    {
        bx_dbg_query_command((yyvsp[(2) - (3)].sval));
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 150:
#line 766 "parser.y"
    {
        bx_dbg_take_command((yyvsp[(2) - (3)].sval), 1);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 151:
#line 771 "parser.y"
    {
        bx_dbg_take_command((yyvsp[(2) - (4)].sval), (yyvsp[(3) - (4)].uval));
        free((yyvsp[(1) - (4)].sval)); free((yyvsp[(2) - (4)].sval));
      }
    break;

  case 152:
#line 776 "parser.y"
    {
        bx_dbg_take_command((yyvsp[(2) - (3)].sval), 1);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 153:
#line 784 "parser.y"
    {
        bx_dbg_disassemble_current(NULL);
        free((yyvsp[(1) - (2)].sval));
      }
    break;

  case 154:
#line 789 "parser.y"
    {
        bx_dbg_disassemble_command(NULL, (yyvsp[(2) - (3)].uval), (yyvsp[(2) - (3)].uval));
        free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 155:
#line 794 "parser.y"
    {
        bx_dbg_disassemble_command(NULL, (yyvsp[(2) - (4)].uval), (yyvsp[(3) - (4)].uval));
        free((yyvsp[(1) - (4)].sval));
      }
    break;

  case 156:
#line 799 "parser.y"
    {
        bx_dbg_disassemble_current((yyvsp[(2) - (3)].sval));
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 157:
#line 804 "parser.y"
    {
        bx_dbg_disassemble_command((yyvsp[(2) - (4)].sval), (yyvsp[(3) - (4)].uval), (yyvsp[(3) - (4)].uval));
        free((yyvsp[(1) - (4)].sval)); free((yyvsp[(2) - (4)].sval));
      }
    break;

  case 158:
#line 809 "parser.y"
    {
        bx_dbg_disassemble_command((yyvsp[(2) - (5)].sval), (yyvsp[(3) - (5)].uval), (yyvsp[(4) - (5)].uval));
        free((yyvsp[(1) - (5)].sval)); free((yyvsp[(2) - (5)].sval));
      }
    break;

  case 159:
#line 814 "parser.y"
    {
        bx_dbg_disassemble_switch_mode();
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 160:
#line 819 "parser.y"
    {
        bx_dbg_set_disassemble_size((yyvsp[(4) - (5)].uval));
        free((yyvsp[(1) - (5)].sval)); free((yyvsp[(2) - (5)].sval));
      }
    break;

  case 161:
#line 827 "parser.y"
    {
        bx_dbg_instrument_command((yyvsp[(2) - (3)].sval));
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 162:
#line 832 "parser.y"
    {
        bx_dbg_instrument_command((yyvsp[(2) - (3)].sval));
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
      }
    break;

  case 163:
#line 840 "parser.y"
    {
        bx_dbg_doit_command((yyvsp[(2) - (3)].uval));
        free((yyvsp[(1) - (3)].sval));
      }
    break;

  case 164:
#line 848 "parser.y"
    {
        bx_dbg_crc_command((yyvsp[(2) - (4)].uval), (yyvsp[(3) - (4)].uval));
        free((yyvsp[(1) - (4)].sval));
      }
    break;

  case 165:
#line 856 "parser.y"
    {
         dbg_printf("q|quit|exit - quit debugger and emulator execution\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 166:
#line 861 "parser.y"
    {
         dbg_printf("c|cont|continue - continue executing\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 167:
#line 866 "parser.y"
    {
         dbg_printf("s|step|stepi [count] - execute #count instructions (default is one instruction)\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 168:
#line 871 "parser.y"
    {
         dbg_printf("n|next|p - execute instruction stepping over subroutines\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 169:
#line 876 "parser.y"
    {
         dbg_printf("vb|vbreak <seg:offset> - set a virtual address instruction breakpoint\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 170:
#line 881 "parser.y"
    {
         dbg_printf("lb|lbreak <addr> - set a linear address instruction breakpoint\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 171:
#line 886 "parser.y"
    {
         dbg_printf("p|pb|break|pbreak <addr> - set a physical address instruction breakpoint\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 172:
#line 891 "parser.y"
    {
         dbg_printf("d|del|delete <n> - delete a breakpoint\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 173:
#line 896 "parser.y"
    {
         dbg_printf("bpe <n> - enable a breakpoint\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 174:
#line 901 "parser.y"
    {
         dbg_printf("bpd <n> - disable a breakpoint\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 175:
#line 906 "parser.y"
    {
         dbg_printf("blist - list all breakpoints (same as 'info break')\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 176:
#line 911 "parser.y"
    {
         dbg_printf("modebp - toggles mode switch breakpoint\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 177:
#line 916 "parser.y"
    {
         dbg_printf("crc <addr1> <addr2> - show CRC32 for physical memory range addr1..addr2\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 178:
#line 921 "parser.y"
    {
         dbg_printf("trace on  - print disassembly for every executed instruction\n");
         dbg_printf("trace off - disable instruction tracing\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 179:
#line 927 "parser.y"
    {
         dbg_printf("trace-reg on  - print all registers before every executed instruction\n");
         dbg_printf("trace-reg off - disable registers state tracing\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 180:
#line 933 "parser.y"
    {
         dbg_printf("trace-mem on  - print all memory accesses occured during instruction execution\n");
         dbg_printf("trace-mem off - disable memory accesses tracing\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 181:
#line 939 "parser.y"
    {
         dbg_printf("restore <param_name> [path] - restore bochs root param from the file\n");
         dbg_printf("for example:\n");
         dbg_printf("restore \"cpu0\" - restore CPU #0 from file \"cpu0\" in current directory\n");
         dbg_printf("restore \"cpu0\" \"/save\" - restore CPU #0 from file \"cpu0\" located in directory \"/save\"\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 182:
#line 947 "parser.y"
    {
         dbg_printf("ptime - print current time (number of ticks since start of simulation)\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 183:
#line 952 "parser.y"
    {
         dbg_printf("sb <delta> - insert a time breakpoint delta instructions into the future\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 184:
#line 957 "parser.y"
    {
         dbg_printf("sba <time> - insert breakpoint at specific time\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 185:
#line 962 "parser.y"
    {
         dbg_printf("print-stack [num_words] - print the num_words top 16 bit words on the stack\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 186:
#line 967 "parser.y"
    {
         dbg_printf("record <filename> - record console input to file filename\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 187:
#line 972 "parser.y"
    {
         dbg_printf("playback <filename> - playback console input from file filename\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 188:
#line 977 "parser.y"
    {
         dbg_printf("ldsym [global] <filename> [offset] - load symbols from file\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 189:
#line 982 "parser.y"
    {
         dbg_printf("slist [string] - list symbols whose preffix is string (same as 'info symbols')\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 190:
#line 987 "parser.y"
    {
         dbg_printf("r|reg|regs|registers - list of CPU registers and their contents (same as 'info registers')\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 191:
#line 992 "parser.y"
    {
         dbg_printf("fp|fpu| - print FPU state\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 192:
#line 997 "parser.y"
    {
         dbg_printf("mmx - print MMX state\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 193:
#line 1002 "parser.y"
    {
         dbg_printf("sse|xmm - print SSE state\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 194:
#line 1007 "parser.y"
    {
         dbg_printf("sreg - show segment registers\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 195:
#line 1012 "parser.y"
    {
         dbg_printf("creg - show control registers\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 196:
#line 1017 "parser.y"
    {
         dbg_printf("setpmem <addr> <datasize> <val> - set physical memory location of size 'datasize' to value 'val'\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 197:
#line 1022 "parser.y"
    {
         dbg_printf("u|disasm|disassemble [/count] <start> <end> - disassemble instructions for given linear address\n");
         dbg_printf("    Optional 'count' is the number of disassembled instructions\n");
         dbg_printf("u|disasm|disassemble switch-mode - switch between Intel and AT&T disassembler syntax\n");
         dbg_printf("u|disasm|disassemble size = n - tell debugger what segment size [16|32|64] to use\n");
         dbg_printf("       when \"disassemble\" command is used.\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 198:
#line 1031 "parser.y"
    {
         dbg_printf("watch - print current watch point status\n");
         dbg_printf("watch stop - stop simulation when a watchpoint is encountred\n");
         dbg_printf("watch continue - do not stop the simulation when watch point is encountred\n");
         dbg_printf("watch r|read addr - insert a read watch point at physical address addr\n");
         dbg_printf("watch w|write addr - insert a write watch point at physical address addr\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 199:
#line 1040 "parser.y"
    {
         dbg_printf("unwatch      - remove all watch points\n");
         dbg_printf("unwatch addr - remove a watch point\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 200:
#line 1046 "parser.y"
    {
         dbg_printf("x  /nuf <addr> - examine memory at linear address\n");
         dbg_printf("xp /nuf <addr> - examine memory at physical address\n");
         dbg_printf("    nuf is a sequence of numbers (how much values to display)\n");
         dbg_printf("    and one or more of the [mxduotcsibhwg] format specificators:\n");
         dbg_printf("    x,d,u,o,t,c,s,i select the format of the output (they stand for\n");
         dbg_printf("        hex, decimal, unsigned, octal, binary, char, asciiz, instr)\n");
         dbg_printf("    b,h,w,g select the size of a data element (for byte, half-word,\n");
         dbg_printf("        word and giant word)\n");
         dbg_printf("    m selects an alternative output format (memory dump)\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 201:
#line 1059 "parser.y"
    {
         dbg_printf("instrument start - calls bx_instr_start() callback\n");
         dbg_printf("instrument stop  - calls bx_instr_stop () callback\n");
         dbg_printf("instrument reset - calls bx_instr_reset() callback\n");
         dbg_printf("instrument print - calls bx_instr_print() callback\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 202:
#line 1067 "parser.y"
    {
         dbg_printf("set <regname> = <expr> - set register value to expression\n");
         dbg_printf("set $reg = val - set CPU register to value val\n");
         dbg_printf("set $auto_disassemble = 1 - cause debugger to disassemble current instruction\n");
         dbg_printf("       every time execution stops\n");
         dbg_printf("set u|disasm|disassemble on  - same as 'set $auto_disassemble = 1'\n");
         dbg_printf("set u|disasm|disassemble off - same as 'set $auto_disassemble = 0'\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 203:
#line 1077 "parser.y"
    {
         dbg_printf("page <laddr> - show linear to physical xlation for linear address laddr\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 204:
#line 1082 "parser.y"
    {
         dbg_printf("info break - show information about current breakpoint status\n");
         dbg_printf("info idt - show interrupt descriptor table\n");
         dbg_printf("info ivt - show interrupt vector table\n");
         dbg_printf("info gdt - show global descriptor table\n");
         dbg_printf("info tss - show current task state segment\n");
         dbg_printf("info tab - show page tables\n");
         dbg_printf("info eflags - show decoded EFLAGS register\n");
         dbg_printf("info symbols [string] - list symbols whose prefix is string\n");
         dbg_printf("info pic - show PICs registers\n");
         dbg_printf("info ne2000 - show NE2000 registers\n");
         dbg_printf("info vga - show vga registers\n");
         dbg_printf("info pci - show i440fx PCI state\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 205:
#line 1098 "parser.y"
    {
         dbg_printf("show <command> - toggles show symbolic info (calls to begin with)\n");
         dbg_printf("show - shows current show mode\n");
         dbg_printf("show mode - show, when processor switch mode\n");
         dbg_printf("show int - show, when interrupt is happens\n");
         dbg_printf("show call - show, when call is happens\n");
         dbg_printf("show off - toggles off symbolic info\n");
         dbg_printf("show dbg-all - turn on all show flags\n");
         dbg_printf("show dbg-none - turn off all show flags\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 206:
#line 1110 "parser.y"
    {
         dbg_printf("calc|? <expr> - calculate a expression and display the result.\n");
         dbg_printf("    'expr' can reference any general-purpose and segment\n");
         dbg_printf("    registers, use any arithmetic and logic operations, and\n");
         dbg_printf("    also the special ':' operator which computes the linear\n");
         dbg_printf("    address for a segment:offset (in real and v86 mode) or\n");
         dbg_printf("    of a selector:offset (in protected mode) pair.\n");
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 207:
#line 1120 "parser.y"
    {
         bx_dbg_print_help();
         free((yyvsp[(1) - (3)].sval));free((yyvsp[(2) - (3)].sval));
       }
    break;

  case 208:
#line 1125 "parser.y"
    {
         bx_dbg_print_help();
         free((yyvsp[(1) - (2)].sval));
       }
    break;

  case 209:
#line 1133 "parser.y"
    {
     bx_dbg_calc_command((yyvsp[(2) - (3)].uval));
     free((yyvsp[(1) - (3)].sval));
   }
    break;

  case 210:
#line 1150 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (1)].uval); }
    break;

  case 211:
#line 1151 "parser.y"
    { (yyval.uval) = bx_dbg_get_reg8l_value((yyvsp[(1) - (1)].uval)); }
    break;

  case 212:
#line 1152 "parser.y"
    { (yyval.uval) = bx_dbg_get_reg8h_value((yyvsp[(1) - (1)].uval)); }
    break;

  case 213:
#line 1153 "parser.y"
    { (yyval.uval) = bx_dbg_get_reg16_value((yyvsp[(1) - (1)].uval)); }
    break;

  case 214:
#line 1154 "parser.y"
    { (yyval.uval) = bx_dbg_get_reg32_value((yyvsp[(1) - (1)].uval)); }
    break;

  case 215:
#line 1155 "parser.y"
    { (yyval.uval) = bx_dbg_get_reg64_value((yyvsp[(1) - (1)].uval)); }
    break;

  case 216:
#line 1156 "parser.y"
    { (yyval.uval) = bx_dbg_get_selector_value((yyvsp[(1) - (1)].uval)); }
    break;

  case 217:
#line 1157 "parser.y"
    { (yyval.uval) = bx_dbg_get_ip (); }
    break;

  case 218:
#line 1158 "parser.y"
    { (yyval.uval) = bx_dbg_get_eip(); }
    break;

  case 219:
#line 1159 "parser.y"
    { (yyval.uval) = bx_dbg_get_instruction_pointer(); }
    break;

  case 220:
#line 1160 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) + (yyvsp[(3) - (3)].uval); }
    break;

  case 221:
#line 1161 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) - (yyvsp[(3) - (3)].uval); }
    break;

  case 222:
#line 1162 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) * (yyvsp[(3) - (3)].uval); }
    break;

  case 223:
#line 1163 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) / (yyvsp[(3) - (3)].uval); }
    break;

  case 224:
#line 1164 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) >> (yyvsp[(3) - (3)].uval); }
    break;

  case 225:
#line 1165 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) << (yyvsp[(3) - (3)].uval); }
    break;

  case 226:
#line 1166 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) | (yyvsp[(3) - (3)].uval); }
    break;

  case 227:
#line 1167 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) ^ (yyvsp[(3) - (3)].uval); }
    break;

  case 228:
#line 1168 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) & (yyvsp[(3) - (3)].uval); }
    break;

  case 229:
#line 1169 "parser.y"
    { (yyval.uval) = !(yyvsp[(2) - (2)].uval); }
    break;

  case 230:
#line 1170 "parser.y"
    { (yyval.uval) = -(yyvsp[(2) - (2)].uval); }
    break;

  case 231:
#line 1171 "parser.y"
    { (yyval.uval) = (yyvsp[(2) - (3)].uval); }
    break;

  case 232:
#line 1176 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (1)].uval); }
    break;

  case 233:
#line 1177 "parser.y"
    { (yyval.uval) = bx_dbg_get_symbol_value((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));}
    break;

  case 234:
#line 1178 "parser.y"
    { (yyval.uval) = bx_dbg_get_reg8l_value((yyvsp[(1) - (1)].uval)); }
    break;

  case 235:
#line 1179 "parser.y"
    { (yyval.uval) = bx_dbg_get_reg8h_value((yyvsp[(1) - (1)].uval)); }
    break;

  case 236:
#line 1180 "parser.y"
    { (yyval.uval) = bx_dbg_get_reg16_value((yyvsp[(1) - (1)].uval)); }
    break;

  case 237:
#line 1181 "parser.y"
    { (yyval.uval) = bx_dbg_get_reg32_value((yyvsp[(1) - (1)].uval)); }
    break;

  case 238:
#line 1182 "parser.y"
    { (yyval.uval) = bx_dbg_get_reg64_value((yyvsp[(1) - (1)].uval)); }
    break;

  case 239:
#line 1183 "parser.y"
    { (yyval.uval) = bx_dbg_get_selector_value((yyvsp[(1) - (1)].uval)); }
    break;

  case 240:
#line 1184 "parser.y"
    { (yyval.uval) = bx_dbg_get_ip (); }
    break;

  case 241:
#line 1185 "parser.y"
    { (yyval.uval) = bx_dbg_get_eip(); }
    break;

  case 242:
#line 1186 "parser.y"
    { (yyval.uval) = bx_dbg_get_instruction_pointer(); }
    break;

  case 243:
#line 1187 "parser.y"
    { (yyval.uval) = bx_dbg_get_laddr ((yyvsp[(1) - (3)].uval), (yyvsp[(3) - (3)].uval)); }
    break;

  case 244:
#line 1188 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) + (yyvsp[(3) - (3)].uval); }
    break;

  case 245:
#line 1189 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) - (yyvsp[(3) - (3)].uval); }
    break;

  case 246:
#line 1190 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) * (yyvsp[(3) - (3)].uval); }
    break;

  case 247:
#line 1191 "parser.y"
    { (yyval.uval) = ((yyvsp[(3) - (3)].uval) != 0) ? (yyvsp[(1) - (3)].uval) / (yyvsp[(3) - (3)].uval) : 0; }
    break;

  case 248:
#line 1192 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) >> (yyvsp[(3) - (3)].uval); }
    break;

  case 249:
#line 1193 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) << (yyvsp[(3) - (3)].uval); }
    break;

  case 250:
#line 1194 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) | (yyvsp[(3) - (3)].uval); }
    break;

  case 251:
#line 1195 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) ^ (yyvsp[(3) - (3)].uval); }
    break;

  case 252:
#line 1196 "parser.y"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) & (yyvsp[(3) - (3)].uval); }
    break;

  case 253:
#line 1197 "parser.y"
    { (yyval.uval) = !(yyvsp[(2) - (2)].uval); }
    break;

  case 254:
#line 1198 "parser.y"
    { (yyval.uval) = -(yyvsp[(2) - (2)].uval); }
    break;

  case 255:
#line 1199 "parser.y"
    { (yyval.uval) = (yyvsp[(2) - (3)].uval); }
    break;


/* Line 1267 of yacc.c.  */
#line 3644 "y.tab.c"
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


#line 1202 "parser.y"


#endif  /* if BX_DEBUGGER */
/* The #endif is appended by the makefile after running yacc. */
