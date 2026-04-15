
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 6 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void yyerror(const char *s);
int yylex();
extern FILE *yyin;
extern int yylineno;

FILE *output_file;

// Stack-based statement buffering for control flow
#define MAX_BUFFER_DEPTH 10
typedef struct {
    char buffer[50000];
    int pos;
} StatementBuffer;

StatementBuffer buffer_stack[MAX_BUFFER_DEPTH];
int buffer_depth = 0;  // 0 = no buffering, 1+ = buffering level
char temp_else_body[100000];  // Temporary storage for else body

void push_buffer() {
    if (buffer_depth < MAX_BUFFER_DEPTH - 1) {
        buffer_stack[buffer_depth].pos = 0;
        memset(buffer_stack[buffer_depth].buffer, 0, 50000);
        buffer_depth++;
    }
}

char* pop_buffer() {
    if (buffer_depth > 0) {
        buffer_depth--;
        return buffer_stack[buffer_depth].buffer;
    }
    return "";
}

void buffer_statement(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    if (buffer_depth > 0) {
        buffer_stack[buffer_depth - 1].pos += vsprintf(buffer_stack[buffer_depth - 1].buffer + buffer_stack[buffer_depth - 1].pos, fmt, args);
    } else {
        vfprintf(output_file, fmt, args);
    }
    va_end(args);
}

char* get_current_buffer() {
    if (buffer_depth > 0) {
        return buffer_stack[buffer_depth - 1].buffer;
    }
    return "";
}

// Track variable types
typedef struct {
    char name[50];
    char type[20];  // "int", "float", "string"
} VarType;

VarType vars[100];
int var_count = 0;

void add_var_type(const char *name, const char *type) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(vars[i].name, name) == 0) {
            strcpy(vars[i].type, type);
            return;
        }
    }
    strcpy(vars[var_count].name, name);
    strcpy(vars[var_count].type, type);
    var_count++;
}

char* get_var_type(const char *name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(vars[i].name, name) == 0) {
            return vars[i].type;
        }
    }
    return "int";
}

int in_function = 0;
int depth = 0;



/* Line 189 of yacc.c  */
#line 167 "parser.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLOAT = 259,
     CHAR = 260,
     STRING = 261,
     RETURN = 262,
     IF = 263,
     ELSE = 264,
     FOR = 265,
     PRINTF = 266,
     VOID = 267,
     NUMBER = 268,
     FLOAT_NUM = 269,
     ID = 270,
     STRING_LIT = 271,
     CHAR_LIT = 272,
     PLUS = 273,
     MINUS = 274,
     MUL = 275,
     DIV = 276,
     MOD = 277,
     ASSIGN = 278,
     SEMICOLON = 279,
     COMMA = 280,
     QUOTE = 281,
     LPAREN = 282,
     RPAREN = 283,
     LBRACE = 284,
     RBRACE = 285,
     LT = 286,
     GT = 287,
     LE = 288,
     GE = 289,
     EQ = 290,
     NE = 291,
     NOT = 292,
     AND = 293,
     OR = 294,
     INC = 295,
     DEC = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 99 "parser.y"

    char *str;
    int num;



/* Line 214 of yacc.c  */
#line 251 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 263 "parser.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   451

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNRULES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,    15,    16,    19,    21,    24,
      28,    34,    38,    44,    48,    54,    58,    64,    69,    73,
      77,    83,    91,    97,   101,   104,   105,   115,   116,   132,
     133,   134,   140,   141,   152,   156,   160,   164,   168,   172,
     176,   180,   184,   188,   192,   196,   200,   204,   207,   211,
     213,   215,   217,   219,   221,   224,   227,   231
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    44,    -1,    -1,     3,    15,    27,    28,
      29,    45,    46,    30,    -1,    -1,    47,    48,    -1,    49,
      -1,    48,    49,    -1,     3,    15,    24,    -1,     3,    15,
      23,    55,    24,    -1,     4,    15,    24,    -1,     4,    15,
      23,    55,    24,    -1,     5,    15,    24,    -1,     5,    15,
      23,    17,    24,    -1,     6,    15,    24,    -1,     6,    15,
      23,    16,    24,    -1,    15,    23,    55,    24,    -1,    15,
      40,    24,    -1,    15,    41,    24,    -1,    11,    27,    55,
      28,    24,    -1,    11,    27,    55,    25,    55,    28,    24,
      -1,    11,    27,    56,    28,    24,    -1,     7,    55,    24,
      -1,     7,    24,    -1,    -1,     8,    27,    55,    28,    29,
      50,    48,    30,    52,    -1,    -1,    10,    27,    15,    23,
      55,    24,    55,    24,    15,    40,    28,    29,    51,    48,
      30,    -1,    -1,    -1,     9,    29,    53,    48,    30,    -1,
      -1,     9,     8,    27,    55,    28,    29,    54,    48,    30,
      52,    -1,    55,    18,    55,    -1,    55,    19,    55,    -1,
      55,    20,    55,    -1,    55,    21,    55,    -1,    55,    22,
      55,    -1,    55,    31,    55,    -1,    55,    32,    55,    -1,
      55,    33,    55,    -1,    55,    34,    55,    -1,    55,    35,
      55,    -1,    55,    36,    55,    -1,    55,    38,    55,    -1,
      55,    39,    55,    -1,    37,    55,    -1,    27,    55,    28,
      -1,    13,    -1,    14,    -1,    16,    -1,    17,    -1,    15,
      -1,    15,    40,    -1,    15,    41,    -1,    55,    25,    55,
      -1,    56,    25,    55,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   122,   122,   126,   126,   134,   134,   144,   145,   149,
     153,   157,   161,   165,   169,   173,   177,   181,   184,   187,
     190,   209,   263,   266,   269,   272,   272,   280,   280,   286,
     288,   288,   292,   292,   301,   306,   311,   316,   321,   326,
     331,   336,   341,   346,   351,   356,   361,   366,   371,   374,
     377,   380,   383,   386,   389,   394,   402,   462
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "STRING",
  "RETURN", "IF", "ELSE", "FOR", "PRINTF", "VOID", "NUMBER", "FLOAT_NUM",
  "ID", "STRING_LIT", "CHAR_LIT", "PLUS", "MINUS", "MUL", "DIV", "MOD",
  "ASSIGN", "SEMICOLON", "COMMA", "QUOTE", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "LT", "GT", "LE", "GE", "EQ", "NE", "NOT", "AND", "OR", "INC",
  "DEC", "$accept", "program", "function", "$@1", "block", "$@2",
  "statements", "statement", "$@3", "$@4", "else_part", "$@5", "$@6",
  "expr", "printf_args", 0
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
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    45,    44,    47,    46,    48,    48,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    50,    49,    51,    49,    52,
      53,    52,    54,    52,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     8,     0,     2,     1,     2,     3,
       5,     3,     5,     3,     5,     3,     5,     4,     3,     3,
       5,     7,     5,     3,     2,     0,     9,     0,    15,     0,
       0,     5,     0,    10,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     1,     1,     1,     2,     2,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     3,     5,
       0,     0,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     7,     0,     0,     0,     0,    49,    50,
      53,    51,    52,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     9,     0,    11,     0,    13,
       0,    15,    54,    55,     0,    47,     0,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,     0,     0,     0,
       0,    48,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     0,     0,     0,     0,     0,
       0,    17,    10,    12,    14,    16,    25,     0,    56,    20,
      57,    22,     0,     0,     0,     0,     0,    21,    29,     0,
       0,    26,     0,     0,    30,     0,     0,     0,     0,     0,
       0,    27,     0,    31,     0,    32,     0,     0,    28,     0,
      29,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    22,    23,   112,   134,
     121,   127,   137,    36,    73
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -90
static const yytype_int16 yypact[] =
{
       1,    -2,    29,   -90,    28,   -90,    34,    45,   -90,   -90,
      31,   436,   -90,    48,    64,    67,    68,   105,    63,    76,
      79,    37,   436,   -90,   -13,    26,    33,    35,   -90,   -90,
     -20,   -90,   -90,   -90,   120,   120,   152,   120,    92,   120,
     120,    86,    88,   -90,   120,   -90,   120,   -90,    96,   -90,
      99,   -90,   -90,   -90,   174,   -90,   120,   120,   120,   120,
     120,   -90,   120,   120,   120,   120,   120,   120,   120,   120,
     196,    93,   130,   -19,   218,   -90,   -90,   240,   262,   101,
     102,   -90,    32,    32,   -90,   -90,   -90,    -3,    -3,    -3,
      -3,    -3,    -3,   402,   394,    98,   120,   120,   104,   120,
     106,   -90,   -90,   -90,   -90,   -90,   -90,   284,   306,   -90,
     372,   -90,   436,   120,   107,    36,   328,   -90,   114,   123,
      -7,   -90,   100,   112,   -90,   113,   120,   436,   115,   350,
      65,   -90,   116,   -90,   436,   -90,    81,   436,   -90,    94,
     114,   -90
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,   -90,   -90,   -90,   -90,   -89,   -22,   -90,   -90,
       3,   -90,   -90,   -32,   -90
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      43,   123,    54,    55,     1,    70,    99,    72,    74,   100,
      44,    45,    77,     4,    78,    56,    57,    58,    59,    60,
      52,    53,   124,   115,    82,    83,    84,    85,    86,     5,
      87,    88,    89,    90,    91,    92,    93,    94,   130,    13,
      14,    15,    16,    17,    18,   136,    19,    20,   139,    46,
      47,    21,    58,    59,    60,     6,    48,    49,    50,    51,
      40,    12,     7,    24,   107,   108,   118,   110,    13,    14,
      15,    16,    17,    18,     8,    19,    20,    41,    42,    25,
      21,   116,    26,    27,    13,    14,    15,    16,    17,    18,
      37,    19,    20,    43,   129,   133,    21,    13,    14,    15,
      16,    17,    18,    38,    19,    20,    39,    71,    43,    21,
      75,   138,    76,    79,    43,    80,    96,    43,    28,    29,
      30,    31,    32,   120,   140,   104,   105,   106,   109,    33,
     111,   117,    34,    28,    29,    30,    31,    32,   122,   126,
     125,   128,    35,   141,   131,   135,     0,    34,    56,    57,
      58,    59,    60,     0,     0,    97,     0,    35,    98,     0,
       0,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      56,    57,    58,    59,    60,     0,    61,     0,     0,     0,
       0,     0,     0,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    56,    57,    58,    59,    60,     0,     0,     0,
       0,     0,    81,     0,     0,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    56,    57,    58,    59,    60,     0,
       0,     0,     0,     0,    95,     0,     0,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    56,    57,    58,    59,
      60,     0,   101,     0,     0,     0,     0,     0,     0,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    56,    57,
      58,    59,    60,     0,   102,     0,     0,     0,     0,     0,
       0,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      56,    57,    58,    59,    60,     0,   103,     0,     0,     0,
       0,     0,     0,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    56,    57,    58,    59,    60,     0,   113,     0,
       0,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    56,    57,    58,    59,    60,     0,
       0,     0,     0,     0,   114,     0,     0,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    56,    57,    58,    59,
      60,     0,   119,     0,     0,     0,     0,     0,     0,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    56,    57,
      58,    59,    60,     0,     0,     0,     0,     0,   132,     0,
       0,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      56,    57,    58,    59,    60,     0,     0,     0,     0,     0,
       0,     0,     0,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    56,    57,    58,    59,    60,     0,     0,     0,
      56,    57,    58,    59,    60,    62,    63,    64,    65,    66,
      67,     0,    68,    62,    63,    64,    65,    66,    67,    13,
      14,    15,    16,    17,    18,     0,    19,    20,     0,     0,
       0,    21
};

static const yytype_int16 yycheck[] =
{
      22,     8,    34,    35,     3,    37,    25,    39,    40,    28,
      23,    24,    44,    15,    46,    18,    19,    20,    21,    22,
      40,    41,    29,   112,    56,    57,    58,    59,    60,     0,
      62,    63,    64,    65,    66,    67,    68,    69,   127,     3,
       4,     5,     6,     7,     8,   134,    10,    11,   137,    23,
      24,    15,    20,    21,    22,    27,    23,    24,    23,    24,
      23,    30,    28,    15,    96,    97,    30,    99,     3,     4,
       5,     6,     7,     8,    29,    10,    11,    40,    41,    15,
      15,   113,    15,    15,     3,     4,     5,     6,     7,     8,
      27,    10,    11,   115,   126,    30,    15,     3,     4,     5,
       6,     7,     8,    27,    10,    11,    27,    15,   130,    15,
      24,    30,    24,    17,   136,    16,    23,   139,    13,    14,
      15,    16,    17,     9,    30,    24,    24,    29,    24,    24,
      24,    24,    27,    13,    14,    15,    16,    17,    15,    27,
      40,    28,    37,   140,    29,    29,    -1,    27,    18,    19,
      20,    21,    22,    -1,    -1,    25,    -1,    37,    28,    -1,
      -1,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    18,    19,    20,    21,
      22,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    18,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    18,    19,    20,    21,    22,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    18,    19,    20,    21,
      22,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    31,    32,    33,    34,    35,
      36,    -1,    38,    31,    32,    33,    34,    35,    36,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    15
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    43,    44,    15,     0,    27,    28,    29,    45,
      46,    47,    30,     3,     4,     5,     6,     7,     8,    10,
      11,    15,    48,    49,    15,    15,    15,    15,    13,    14,
      15,    16,    17,    24,    27,    37,    55,    27,    27,    27,
      23,    40,    41,    49,    23,    24,    23,    24,    23,    24,
      23,    24,    40,    41,    55,    55,    18,    19,    20,    21,
      22,    24,    31,    32,    33,    34,    35,    36,    38,    39,
      55,    15,    55,    56,    55,    24,    24,    55,    55,    17,
      16,    28,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    28,    23,    25,    28,    25,
      28,    24,    24,    24,    24,    24,    29,    55,    55,    24,
      55,    24,    50,    24,    28,    48,    55,    24,    30,    24,
       9,    52,    15,     8,    29,    40,    27,    53,    28,    55,
      48,    29,    28,    30,    51,    29,    48,    54,    30,    48,
      30,    52
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 3:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    {
        fprintf(output_file, "#include <stdio.h>\nint main() {\n");
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    {
        fprintf(output_file, "    return 0;\n}\n");
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    {
        push_buffer();
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    {
        char *buffered = pop_buffer();
        fprintf(output_file, "%s", buffered);
        (yyval.str) = "";
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    {
        buffer_statement("    int %s = 0;\n", (yyvsp[(2) - (3)].str));
        add_var_type((yyvsp[(2) - (3)].str), "int");
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {
        buffer_statement("    int %s = %s;\n", (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].str));
        add_var_type((yyvsp[(2) - (5)].str), "int");
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {
        buffer_statement("    float %s = 0.0;\n", (yyvsp[(2) - (3)].str));
        add_var_type((yyvsp[(2) - (3)].str), "float");
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    {
        buffer_statement("    float %s = %s;\n", (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].str));
        add_var_type((yyvsp[(2) - (5)].str), "float");
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {
        buffer_statement("    char %s = '\\0';\n", (yyvsp[(2) - (3)].str));
        add_var_type((yyvsp[(2) - (3)].str), "char");
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {
        buffer_statement("    char %s = %s;\n", (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].str));
        add_var_type((yyvsp[(2) - (5)].str), "char");
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    {
        buffer_statement("    char *%s = \"\";\n", (yyvsp[(2) - (3)].str));
        add_var_type((yyvsp[(2) - (3)].str), "string");
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 177 "parser.y"
    {
        buffer_statement("    char *%s = %s;\n", (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].str));
        add_var_type((yyvsp[(2) - (5)].str), "string");
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {
        buffer_statement("    %s = %s;\n", (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].str));
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    {
        buffer_statement("    %s++;\n", (yyvsp[(1) - (3)].str));
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 187 "parser.y"
    {
        buffer_statement("    %s--;\n", (yyvsp[(1) - (3)].str));
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    {
        char *val = (yyvsp[(3) - (5)].str);
        char *type = get_var_type(val);
        if (val[0] == '"') {
            buffer_statement("    printf(%s);\n", val);
        } else if (strchr(val, '.') != NULL) {
            buffer_statement("    printf(\"%%f\\n\", %s);\n", val);
        } else {
            if (strcmp(type, "float") == 0) {
                buffer_statement("    printf(\"%%f\\n\", %s);\n", val);
            } else if (strcmp(type, "string") == 0) {
                buffer_statement("    printf(\"%%s\\n\", %s);\n", val);
            } else if (strcmp(type, "char") == 0) {
                buffer_statement("    printf(\"%%c\\n\", %s);\n", val);
            } else {
                buffer_statement("    printf(\"%%d\\n\", %s);\n", val);
            }
        }
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 209 "parser.y"
    {
        char *first = (yyvsp[(3) - (7)].str);
        char *second = (yyvsp[(5) - (7)].str);
        char *type_first = get_var_type(first);
        char *type_second = get_var_type(second);
        
        // Check if first is a string literal
        int first_is_string = (first[0] == '"');
        int second_is_string = (second[0] == '"');
        
        if (first_is_string && !second_is_string) {
            // printf("label:", variable)
            char *type = get_var_type(second);
            if (strchr(second, '.') != NULL) {
                buffer_statement("    printf(\"%%s%%f\", %s, %s);\n", first, second);
            } else if (strcmp(type, "float") == 0) {
                buffer_statement("    printf(\"%%s%%f\", %s, %s);\n", first, second);
            } else if (strcmp(type, "string") == 0) {
                buffer_statement("    printf(\"%%s%%s\", %s, %s);\n", first, second);
            } else if (strcmp(type, "char") == 0) {
                buffer_statement("    printf(\"%%s%%c\", %s, %s);\n", first, second);
            } else {
                buffer_statement("    printf(\"%%s%%d\", %s, %s);\n", first, second);
            }
        } else if (!first_is_string && second_is_string) {
            // printf(variable, "label:")
            char *type = get_var_type(first);
            if (strchr(first, '.') != NULL) {
                buffer_statement("    printf(\"%%f%%s\", %s, %s);\n", first, second);
            } else if (strcmp(type, "float") == 0) {
                buffer_statement("    printf(\"%%f%%s\", %s, %s);\n", first, second);
            } else if (strcmp(type, "string") == 0) {
                buffer_statement("    printf(\"%%s%%s\", %s, %s);\n", first, second);
            } else if (strcmp(type, "char") == 0) {
                buffer_statement("    printf(\"%%c%%s\", %s, %s);\n", first, second);
            } else {
                buffer_statement("    printf(\"%%d%%s\", %s, %s);\n", first, second);
            }
        } else if (second_is_string) {
            // Both strings
            buffer_statement("    printf(\"%%s%%s\", %s, %s);\n", first, second);
        } else {
            // Both variables
            char *type_first_actual = get_var_type(first);
            char *type_second_actual = get_var_type(second);
            if (strcmp(type_first_actual, "float") == 0 && strcmp(type_second_actual, "float") == 0) {
                buffer_statement("    printf(\"%%f%%f\", %s, %s);\n", first, second);
            } else if (strcmp(type_first_actual, "string") == 0 || strcmp(type_second_actual, "string") == 0) {
                buffer_statement("    printf(\"%%s%%s\", %s, %s);\n", first, second);
            } else {
                buffer_statement("    printf(\"%%d%%d\", %s, %s);\n", first, second);
            }
        }
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    {
        buffer_statement("%s", (yyvsp[(3) - (5)].str));
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 266 "parser.y"
    {
        buffer_statement("    return %s;\n", (yyvsp[(2) - (3)].str));
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 269 "parser.y"
    {
        buffer_statement("    return 0;\n");
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 272 "parser.y"
    {push_buffer();;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 272 "parser.y"
    {
        char *if_body = pop_buffer();
        buffer_statement("    if (%s) {\n%s    }\n", (yyvsp[(3) - (9)].str), if_body);
        if (strlen(temp_else_body) > 0) {
            buffer_statement("%s", temp_else_body);
            temp_else_body[0] = '\0';
        }
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    {push_buffer();;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    {
        char *loop_body = pop_buffer();
        buffer_statement("    for (%s = %s; %s; %s++) {\n%s    }\n", (yyvsp[(3) - (15)].str), (yyvsp[(5) - (15)].str), (yyvsp[(7) - (15)].str), (yyvsp[(9) - (15)].str), loop_body);
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    {push_buffer();;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    {
        char *else_body = pop_buffer();
        sprintf(temp_else_body, "    else {\n%s    }\n", else_body);
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 292 "parser.y"
    {push_buffer();;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 292 "parser.y"
    {
        char *elseif_body = pop_buffer();
        char temp[100000];
        sprintf(temp, "    else if (%s) {\n%s    }\n%s", (yyvsp[(4) - (10)].str), elseif_body, temp_else_body);
        strcpy(temp_else_body, temp);
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 301 "parser.y"
    {
        char *result = malloc(100);
        sprintf(result, "(%s + %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str) = result;
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 306 "parser.y"
    {
        char *result = malloc(100);
        sprintf(result, "(%s - %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str) = result;
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 311 "parser.y"
    {
        char *result = malloc(100);
        sprintf(result, "(%s * %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str) = result;
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 316 "parser.y"
    {
        char *result = malloc(100);
        sprintf(result, "(%s / %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str) = result;
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 321 "parser.y"
    {
        char *result = malloc(100);
        sprintf(result, "(%s %% %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str) = result;
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 326 "parser.y"
    {
        char *result = malloc(100);
        sprintf(result, "(%s < %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str) = result;
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 331 "parser.y"
    {
        char *result = malloc(100);
        sprintf(result, "(%s > %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str) = result;
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 336 "parser.y"
    {
        char *result = malloc(100);
        sprintf(result, "(%s <= %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str) = result;
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 341 "parser.y"
    {
        char *result = malloc(100);
        sprintf(result, "(%s >= %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str) = result;
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 346 "parser.y"
    {
        char *result = malloc(100);
        sprintf(result, "(%s == %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str) = result;
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 351 "parser.y"
    {
        char *result = malloc(100);
        sprintf(result, "(%s != %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str) = result;
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 356 "parser.y"
    {
        char *result = malloc(100);
        sprintf(result, "(%s && %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str) = result;
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 361 "parser.y"
    {
        char *result = malloc(100);
        sprintf(result, "(%s || %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str) = result;
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 366 "parser.y"
    {
        char *result = malloc(100);
        sprintf(result, "(!%s)", (yyvsp[(2) - (2)].str));
        (yyval.str) = result;
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 371 "parser.y"
    {
        (yyval.str) = (yyvsp[(2) - (3)].str);
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 374 "parser.y"
    {
        (yyval.str) = (yyvsp[(1) - (1)].str);
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 377 "parser.y"
    {
        (yyval.str) = (yyvsp[(1) - (1)].str);
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 380 "parser.y"
    {
        (yyval.str) = (yyvsp[(1) - (1)].str);
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 383 "parser.y"
    {
        (yyval.str) = (yyvsp[(1) - (1)].str);
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 386 "parser.y"
    {
        (yyval.str) = (yyvsp[(1) - (1)].str);
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 389 "parser.y"
    {
        char *result = malloc(100);
        sprintf(result, "(%s++)", (yyvsp[(1) - (2)].str));
        (yyval.str) = result;
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 394 "parser.y"
    {
        char *result = malloc(100);
        sprintf(result, "(%s--)", (yyvsp[(1) - (2)].str));
        (yyval.str) = result;
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 402 "parser.y"
    {
        char *result = malloc(2000);
        char *fmt = malloc(500);
        char *args = malloc(500);
        
        fmt[0] = '\0';
        args[0] = '\0';
        
        // First argument
        char *val1 = (yyvsp[(1) - (3)].str);
        char *type1 = get_var_type(val1);
        
        if (val1[0] == '"') {
            strcat(fmt, "%s");
            strcat(args, val1);
        } else if (strchr(val1, '.') != NULL || strcmp(type1, "float") == 0) {
            strcat(fmt, "%f");
            strcat(args, val1);
        } else if (strcmp(type1, "string") == 0) {
            strcat(fmt, "%s");
            strcat(args, val1);
        } else if (strcmp(type1, "char") == 0) {
            strcat(fmt, "%c");
            strcat(args, val1);
        } else {
            strcat(fmt, "%d");
            strcat(args, val1);
        }
        
        // Second argument
        char *val2 = (yyvsp[(3) - (3)].str);
        char *type2 = get_var_type(val2);
        
        if (val2[0] == '"') {
            strcat(fmt, "%s");
            strcat(args, ",");
            strcat(args, val2);
        } else if (strchr(val2, '.') != NULL || strcmp(type2, "float") == 0) {
            strcat(fmt, "%f");
            strcat(args, ",");
            strcat(args, val2);
        } else if (strcmp(type2, "string") == 0) {
            strcat(fmt, "%s");
            strcat(args, ",");
            strcat(args, val2);
        } else if (strcmp(type2, "char") == 0) {
            strcat(fmt, "%c");
            strcat(args, ",");
            strcat(args, val2);
        } else {
            strcat(fmt, "%d");
            strcat(args, ",");
            strcat(args, val2);
        }
        
        sprintf(result, "    printf(\"%s\", %s);\n", fmt, args);
        free(fmt);
        free(args);
        (yyval.str) = result;
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 462 "parser.y"
    {
        char *result = malloc(2000);
        char *prev = (yyvsp[(1) - (3)].str);
        char *val = (yyvsp[(3) - (3)].str);
        char *type = get_var_type(val);
        
        // Extract format and args from previous
        char fmt[500];
        char args[500];
        sscanf(prev, "    printf(\"%[^\"]\", %[^)]", fmt, args);
        
        if (val[0] == '"') {
            strcat(fmt, "%s");
        } else if (strchr(val, '.') != NULL || strcmp(type, "float") == 0) {
            strcat(fmt, "%f");
        } else if (strcmp(type, "string") == 0) {
            strcat(fmt, "%s");
        } else if (strcmp(type, "char") == 0) {
            strcat(fmt, "%c");
        } else {
            strcat(fmt, "%d");
        }
        
        strcat(args, ",");
        strcat(args, val);
        
        sprintf(result, "    printf(\"%s\", %s);\n", fmt, args);
        free(prev);
        (yyval.str) = result;
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2294 "parser.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 494 "parser.y"


void yyerror(const char *s) {
    printf("Error on line %d: %s\n", yylineno, s);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file.c>\n", argv[0]);
        printf("\nExample: %s sample1.c\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input) {
        printf("Error: Cannot open file '%s'\n", argv[1]);
        return 1;
    }

    output_file = fopen("generated.c", "w");
    if (!output_file) {
        printf("Error: Cannot create output file\n");
        fclose(input);
        return 1;
    }

    yyin = input;
    
    int parse_result = yyparse();
    
    fclose(input);
    fclose(output_file);

    if (parse_result != 0) {
        fprintf(stderr, "Parse error in '%s'\n", argv[1]);
        return 1;
    }

    char outfile[50];
    static int counter = 0;
    sprintf(outfile, "out_%d.exe", counter++);
    
    char cmd[200];
    sprintf(cmd, "gcc generated.c -o %s 2>nul", outfile);
    int compile_result = system(cmd);
    
    if (compile_result != 0) {
        fprintf(stderr, "Compilation error\n");
        return 1;
    }
    
    system(outfile);

    return 0;
}

