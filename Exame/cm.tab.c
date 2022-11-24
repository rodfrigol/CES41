/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "cm.y"

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedNum; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *s);


#line 89 "cm.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "cm.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ELSE = 3,                       /* ELSE  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_ID = 9,                         /* ID  */
  YYSYMBOL_NUM = 10,                       /* NUM  */
  YYSYMBOL_PLUS = 11,                      /* PLUS  */
  YYSYMBOL_MINUS = 12,                     /* MINUS  */
  YYSYMBOL_MULT = 13,                      /* MULT  */
  YYSYMBOL_DIV = 14,                       /* DIV  */
  YYSYMBOL_LT = 15,                        /* LT  */
  YYSYMBOL_LTE = 16,                       /* LTE  */
  YYSYMBOL_GT = 17,                        /* GT  */
  YYSYMBOL_GTE = 18,                       /* GTE  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_DIF = 20,                       /* DIF  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_SEMI = 22,                      /* SEMI  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_OP = 24,                        /* OP  */
  YYSYMBOL_CP = 25,                        /* CP  */
  YYSYMBOL_OB = 26,                        /* OB  */
  YYSYMBOL_CB = 27,                        /* CB  */
  YYSYMBOL_OBRACES = 28,                   /* OBRACES  */
  YYSYMBOL_CBRACES = 29,                   /* CBRACES  */
  YYSYMBOL_ERROR = 30,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_program = 32,                   /* program  */
  YYSYMBOL_decl_list = 33,                 /* decl_list  */
  YYSYMBOL_decl = 34,                      /* decl  */
  YYSYMBOL_var_decl = 35,                  /* var_decl  */
  YYSYMBOL_36_1 = 36,                      /* $@1  */
  YYSYMBOL_37_2 = 37,                      /* $@2  */
  YYSYMBOL_fun_decl = 38,                  /* fun_decl  */
  YYSYMBOL_params = 39,                    /* params  */
  YYSYMBOL_param_lista = 40,               /* param_lista  */
  YYSYMBOL_param = 41,                     /* param  */
  YYSYMBOL_comp_decl = 42,                 /* comp_decl  */
  YYSYMBOL_loc_decl = 43,                  /* loc_decl  */
  YYSYMBOL_stmt_list = 44,                 /* stmt_list  */
  YYSYMBOL_stmt = 45,                      /* stmt  */
  YYSYMBOL_exp_decl = 46,                  /* exp_decl  */
  YYSYMBOL_sel_decl = 47,                  /* sel_decl  */
  YYSYMBOL_it_decl = 48,                   /* it_decl  */
  YYSYMBOL_ret_decl = 49,                  /* ret_decl  */
  YYSYMBOL_exp = 50,                       /* exp  */
  YYSYMBOL_var = 51,                       /* var  */
  YYSYMBOL_simp_exp = 52,                  /* simp_exp  */
  YYSYMBOL_soma_exp = 53,                  /* soma_exp  */
  YYSYMBOL_termo = 54,                     /* termo  */
  YYSYMBOL_fator = 55,                     /* fator  */
  YYSYMBOL_ativ = 56,                      /* ativ  */
  YYSYMBOL_args = 57,                      /* args  */
  YYSYMBOL_arg_lista = 58,                 /* arg_lista  */
  YYSYMBOL_id = 59                         /* id  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   136

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    32,    32,    35,    47,    49,    50,    51,    53,    59,
      65,    65,    75,    75,    86,    95,   105,   106,   108,   120,
     122,   128,   134,   143,   153,   166,   178,   180,   192,   194,
     195,   196,   197,   198,   200,   201,   203,   209,   217,   224,
     228,   234,   241,   243,   244,   251,   258,   265,   272,   279,
     286,   293,   295,   302,   309,   311,   318,   325,   327,   328,
     329,   330,   334,   341,   342,   344,   356,   359
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ELSE", "IF", "INT",
  "RETURN", "VOID", "WHILE", "ID", "NUM", "PLUS", "MINUS", "MULT", "DIV",
  "LT", "LTE", "GT", "GTE", "EQ", "DIF", "ASSIGN", "SEMI", "COMMA", "OP",
  "CP", "OB", "CB", "OBRACES", "CBRACES", "ERROR", "$accept", "program",
  "decl_list", "decl", "var_decl", "$@1", "$@2", "fun_decl", "params",
  "param_lista", "param", "comp_decl", "loc_decl", "stmt_list", "stmt",
  "exp_decl", "sel_decl", "it_decl", "ret_decl", "exp", "var", "simp_exp",
  "soma_exp", "termo", "fator", "ativ", "args", "arg_lista", "id", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      34,   -69,    12,    12,    28,    56,   -69,   -69,   -69,   -69,
     -14,    69,   -69,   -69,   -69,    -2,    21,   -69,    -2,    26,
      12,    12,    81,    84,   -69,   -69,    83,   -69,    33,    85,
      82,    44,    86,    82,    88,    89,    90,   -69,   -69,    12,
     -69,    92,   -69,    96,   -69,   -69,    45,   -69,   -69,    12,
      12,   -69,     5,    70,    72,    95,     8,    97,   -69,   -69,
      -8,   -69,   -69,   -69,   -69,   -69,   -69,   -69,    98,    91,
     -69,    64,    87,   -69,   -69,    73,    -8,   -69,   100,    -8,
      99,   -69,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,   101,   -69,   102,   -69,   -69,
     -69,    87,    87,    66,    66,    66,    66,    66,    66,   -69,
     -69,   -69,   103,   106,   104,    36,    36,   -69,    -8,   -69,
     120,   -69,   -69,    36,   -69
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     7,     0,     0,     0,     0,     4,     5,     6,    67,
       0,     0,     1,     3,     8,     0,     0,     9,     0,     0,
       0,    17,     0,    16,    19,    10,     0,    12,    20,    21,
       0,     0,     0,     0,     0,     0,     0,    26,    14,     0,
      18,     0,    15,     0,    22,    23,    28,    11,    13,     0,
       0,    25,     0,     0,     0,     0,     0,     0,    61,    35,
       0,    24,    30,    27,    29,    31,    32,    33,     0,    59,
      42,    51,    54,    57,    60,    43,     0,    39,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,     0,     0,    40,     0,    58,    41,
      59,    52,    53,    46,    45,    47,    48,    49,    50,    55,
      56,    66,     0,    63,     0,     0,     0,    62,     0,    44,
      36,    38,    65,     0,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -69,   -69,   125,    63,   -69,   -69,   -69,   107,   -69,
     105,   -11,   -69,   -69,   -68,   -69,   -69,   -69,   -69,   -56,
     -18,   -69,     0,    19,    13,   -69,   -69,   -69,     4
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    32,    34,     8,    22,    23,
      24,    62,    46,    52,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   112,   113,    75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      78,     9,    58,    20,    80,    21,    10,    11,    14,    55,
      15,    56,    16,    57,     9,    58,    60,     9,    58,    38,
      95,     9,    42,    97,    28,    29,    99,    59,    12,    60,
      77,    25,    60,    37,    61,     1,    27,   111,   114,     2,
      55,     3,    56,    29,    57,     9,    58,   120,   121,    20,
      49,    39,    50,    53,    54,   124,    -2,     1,    59,    35,
      60,     2,   122,     3,    37,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,    83,    84,    83,    84,    85,
      86,    87,    88,    89,    90,   103,   104,   105,   106,   107,
     108,    17,    14,    18,    17,    19,    16,    93,    19,    94,
      91,    92,   101,   102,   109,   110,    30,    31,    33,    51,
      37,    36,    82,    41,    47,    43,    44,    45,    48,    76,
      81,    79,    96,   123,    98,    26,   115,   116,   117,   118,
      13,   119,     0,     0,     0,     0,    40
};

static const yytype_int8 yycheck[] =
{
      56,     9,    10,     5,    60,     7,     2,     3,    22,     4,
      24,     6,    26,     8,     9,    10,    24,     9,    10,    30,
      76,     9,    33,    79,    20,    21,    82,    22,     0,    24,
      22,    10,    24,    28,    29,     1,    10,    93,    94,     5,
       4,     7,     6,    39,     8,     9,    10,   115,   116,     5,
       5,     7,     7,    49,    50,   123,     0,     1,    22,    26,
      24,     5,   118,     7,    28,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    11,    12,    11,    12,    15,
      16,    17,    18,    19,    20,    85,    86,    87,    88,    89,
      90,    22,    22,    24,    22,    26,    26,    24,    26,    26,
      13,    14,    83,    84,    91,    92,    25,    23,    25,    46,
      28,    26,    21,    27,    22,    27,    27,    27,    22,    24,
      22,    24,    22,     3,    25,    18,    25,    25,    25,    23,
       5,    27,    -1,    -1,    -1,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     5,     7,    32,    33,    34,    35,    38,     9,
      59,    59,     0,    34,    22,    24,    26,    22,    24,    26,
       5,     7,    39,    40,    41,    10,    39,    10,    59,    59,
      25,    23,    36,    25,    37,    26,    26,    28,    42,     7,
      41,    27,    42,    27,    27,    27,    43,    22,    22,     5,
       7,    35,    44,    59,    59,     4,     6,     8,    10,    22,
      24,    29,    42,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    59,    24,    22,    50,    24,
      50,    22,    21,    11,    12,    15,    16,    17,    18,    19,
      20,    13,    14,    24,    26,    50,    22,    50,    25,    50,
      51,    54,    54,    53,    53,    53,    53,    53,    53,    55,
      55,    50,    57,    58,    50,    25,    25,    25,    23,    27,
      45,    45,    50,     3,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    34,    35,    35,
      36,    35,    37,    35,    38,    38,    39,    39,    40,    40,
      41,    41,    41,    41,    42,    43,    43,    44,    44,    45,
      45,    45,    45,    45,    46,    46,    47,    47,    48,    49,
      49,    50,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    53,    54,    54,    54,    55,    55,
      55,    55,    56,    57,    57,    58,    58,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     3,
       0,     7,     0,     7,     6,     6,     1,     1,     3,     1,
       2,     2,     4,     4,     4,     2,     0,     2,     0,     1,
       1,     1,     1,     1,     2,     1,     5,     7,     5,     2,
       3,     3,     1,     1,     4,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     1,
       1,     1,     4,     1,     0,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: decl_list  */
#line 33 "cm.y"
                 { savedTree = yyvsp[0];}
#line 1214 "cm.tab.c"
    break;

  case 3: /* decl_list: decl_list decl  */
#line 36 "cm.y"
                 { 
                    YYSTYPE t = yyvsp[-1];
                    if (t != NULL)
                    { 
                      while (t->sibling != NULL)
                        t = t->sibling;
                      t->sibling = yyvsp[0];
                      yyval = yyvsp[-1]; 
                    }
                    else yyval = yyvsp[0];
                 }
#line 1230 "cm.tab.c"
    break;

  case 4: /* decl_list: decl  */
#line 47 "cm.y"
                    { yyval = yyvsp[0]; }
#line 1236 "cm.tab.c"
    break;

  case 5: /* decl: var_decl  */
#line 49 "cm.y"
                       { yyval = yyvsp[0]; }
#line 1242 "cm.tab.c"
    break;

  case 6: /* decl: fun_decl  */
#line 50 "cm.y"
                       { yyval = yyvsp[0]; }
#line 1248 "cm.tab.c"
    break;

  case 7: /* decl: error  */
#line 51 "cm.y"
                     { yyval = NULL; }
#line 1254 "cm.tab.c"
    break;

  case 8: /* var_decl: INT id SEMI  */
#line 54 "cm.y"
              {
                yyval = newStmtNode(IntK);
                yyval->child[0] = newDeclExpNode(IdK, VarT, Variable);
                yyval->child[0]->attr.name = yyvsp[-1]->attr.name;
              }
#line 1264 "cm.tab.c"
    break;

  case 9: /* var_decl: VOID id SEMI  */
#line 60 "cm.y"
              {
                yyval = newStmtNode(VoidK);
                yyval->child[0] = newDeclExpNode(IdK, VarT, Variable);
                yyval->child[0]->attr.name = yyvsp[-1]->attr.name;
              }
#line 1274 "cm.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 65 "cm.y"
                            {savedNum = atoi(tokenString);}
#line 1280 "cm.tab.c"
    break;

  case 11: /* var_decl: INT id OB NUM $@1 CB SEMI  */
#line 66 "cm.y"
              {
                yyval = newStmtNode(IntK);
                yyval->child[0] = newDeclExpNode(IdK, VarT, Variable);
                yyval->child[0]->attr.name = yyvsp[-5]->attr.name;

                yyval->child[0]->child[0] = newDeclExpNode(NumK, VarT, -1);
                yyval->child[0]->child[0]->attr.val = savedNum;
                yyval->child[0]->child[0]->type = Integer;
              }
#line 1294 "cm.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 75 "cm.y"
                             {savedNum = atoi(tokenString);}
#line 1300 "cm.tab.c"
    break;

  case 13: /* var_decl: VOID id OB NUM $@2 CB SEMI  */
#line 76 "cm.y"
              {
                yyval = newStmtNode(VoidK);
                yyval->child[0] = newDeclExpNode(IdK, VarT, Variable);
                yyval->child[0]->attr.name = yyvsp[-5]->attr.name;

                yyval->child[0]->child[0] = newDeclExpNode(NumK, VarT, -1);
                yyval->child[0]->child[0]->attr.val = savedNum;
                yyval->child[0]->child[0]->type = Integer;
              }
#line 1314 "cm.tab.c"
    break;

  case 14: /* fun_decl: INT id OP params CP comp_decl  */
#line 87 "cm.y"
              {
                yyval = newStmtNode(IntK);
                yyval->child[0] = newDeclExpNode(IdK, FuncT, Function);
                yyval->child[0]->attr.name = yyvsp[-4]->attr.name;
                
                yyval->child[0]->child[0] = yyvsp[-2];
                yyval->child[0]->child[1] = yyvsp[0];
              }
#line 1327 "cm.tab.c"
    break;

  case 15: /* fun_decl: VOID id OP params CP comp_decl  */
#line 96 "cm.y"
              {
                yyval = newStmtNode(VoidK);
                yyval->child[0] = newDeclExpNode(IdK, FuncT, Function);
                yyval->child[0]->attr.name = yyvsp[-4]->attr.name;
                
                yyval->child[0]->child[0] = yyvsp[-2];
                yyval->child[0]->child[1] = yyvsp[0];
              }
#line 1340 "cm.tab.c"
    break;

  case 16: /* params: param_lista  */
#line 105 "cm.y"
                          { yyval = yyvsp[0]; }
#line 1346 "cm.tab.c"
    break;

  case 17: /* params: VOID  */
#line 106 "cm.y"
                   { yyval = NULL; }
#line 1352 "cm.tab.c"
    break;

  case 18: /* param_lista: param_lista COMMA param  */
#line 109 "cm.y"
                 { 
                    YYSTYPE t = yyvsp[-2];
                    if (t != NULL)
                    { 
                      while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = yyvsp[0];
                     yyval = yyvsp[-2];
                    }
                     else yyval = yyvsp[0];
                 }
#line 1368 "cm.tab.c"
    break;

  case 19: /* param_lista: param  */
#line 120 "cm.y"
                    { yyval = yyvsp[0]; }
#line 1374 "cm.tab.c"
    break;

  case 20: /* param: INT id  */
#line 123 "cm.y"
              {
                yyval = newStmtNode(IntK);
                yyval->child[0] = newDeclExpNode(IdK, VarT, Variable);
                yyval->child[0]->attr.name = yyvsp[0]->attr.name;
              }
#line 1384 "cm.tab.c"
    break;

  case 21: /* param: VOID id  */
#line 129 "cm.y"
              {
                yyval = newStmtNode(VoidK);
                yyval->child[0] = newDeclExpNode(IdK, VarT, Variable);
                yyval->child[0]->attr.name = yyvsp[0]->attr.name;
              }
#line 1394 "cm.tab.c"
    break;

  case 22: /* param: INT id OB CB  */
#line 135 "cm.y"
              {
                yyval = newStmtNode(IntK);
                yyval->child[0] = newDeclExpNode(IdK, VarT, Variable);
                yyval->child[0]->attr.name = yyvsp[-2]->attr.name;

                yyval->child[0]->child[0] = newExpNode(NumK, -1);
                yyval->child[0]->child[0]->type = Integer;
              }
#line 1407 "cm.tab.c"
    break;

  case 23: /* param: VOID id OB CB  */
#line 144 "cm.y"
              {
                yyval = newStmtNode(VoidK);
                yyval->child[0] = newDeclExpNode(IdK, VarT, Variable);
                yyval->child[0]->attr.name = yyvsp[-2]->attr.name;

                yyval->child[0]->child[0] = newExpNode(NumK, -1);
                yyval->child[0]->child[0]->type = Integer;
              }
#line 1420 "cm.tab.c"
    break;

  case 24: /* comp_decl: OBRACES loc_decl stmt_list CBRACES  */
#line 154 "cm.y"
              { 
                YYSTYPE t = yyvsp[-2];
                if (t != NULL)
                { 
                  while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = yyvsp[-1];
                  yyval = yyvsp[-2];
                }
                else yyval = yyvsp[-1];
              }
#line 1436 "cm.tab.c"
    break;

  case 25: /* loc_decl: loc_decl var_decl  */
#line 167 "cm.y"
              { 
                YYSTYPE t = yyvsp[-1];
                if (t != NULL)
                { 
                  while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = yyvsp[0];
                  yyval = yyvsp[-1]; 
                }
                else yyval = yyvsp[0];
              }
#line 1452 "cm.tab.c"
    break;

  case 26: /* loc_decl: %empty  */
#line 178 "cm.y"
              {yyval = NULL;}
#line 1458 "cm.tab.c"
    break;

  case 27: /* stmt_list: stmt_list stmt  */
#line 181 "cm.y"
              { 
                YYSTYPE t = yyvsp[-1];
                if (t != NULL)
                { 
                  while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = yyvsp[0];
                  yyval = yyvsp[-1]; 
                }
                else yyval = yyvsp[0];
              }
#line 1474 "cm.tab.c"
    break;

  case 28: /* stmt_list: %empty  */
#line 192 "cm.y"
              {yyval = NULL;}
#line 1480 "cm.tab.c"
    break;

  case 29: /* stmt: exp_decl  */
#line 194 "cm.y"
                       { yyval = yyvsp[0]; }
#line 1486 "cm.tab.c"
    break;

  case 30: /* stmt: comp_decl  */
#line 195 "cm.y"
                        { yyval = yyvsp[0]; }
#line 1492 "cm.tab.c"
    break;

  case 31: /* stmt: sel_decl  */
#line 196 "cm.y"
                       { yyval = yyvsp[0]; }
#line 1498 "cm.tab.c"
    break;

  case 32: /* stmt: it_decl  */
#line 197 "cm.y"
                      { yyval = yyvsp[0]; }
#line 1504 "cm.tab.c"
    break;

  case 33: /* stmt: ret_decl  */
#line 198 "cm.y"
                       { yyval = yyvsp[0]; }
#line 1510 "cm.tab.c"
    break;

  case 34: /* exp_decl: exp SEMI  */
#line 200 "cm.y"
                       { yyval = yyvsp[-1]; }
#line 1516 "cm.tab.c"
    break;

  case 35: /* exp_decl: SEMI  */
#line 201 "cm.y"
                   { yyval = yyvsp[0]; }
#line 1522 "cm.tab.c"
    break;

  case 36: /* sel_decl: IF OP exp CP stmt  */
#line 204 "cm.y"
              { 
                yyval = newStmtNode(IfK);
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
              }
#line 1532 "cm.tab.c"
    break;

  case 37: /* sel_decl: IF OP exp CP stmt ELSE stmt  */
#line 210 "cm.y"
              { 
                yyval = newStmtNode(IfK);
                yyval->child[0] = yyvsp[-4];
                yyval->child[1] = yyvsp[-2];
                yyval->child[2] = yyvsp[0];
              }
#line 1543 "cm.tab.c"
    break;

  case 38: /* it_decl: WHILE OP exp CP stmt  */
#line 218 "cm.y"
              {
                yyval = newStmtNode(WhileK);
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
              }
#line 1553 "cm.tab.c"
    break;

  case 39: /* ret_decl: RETURN SEMI  */
#line 225 "cm.y"
              {
                yyval = newStmtNode(ReturnK);
              }
#line 1561 "cm.tab.c"
    break;

  case 40: /* ret_decl: RETURN exp SEMI  */
#line 229 "cm.y"
              {
                yyval = newStmtNode(ReturnK);
                yyval->child[0] = yyvsp[-1];
              }
#line 1570 "cm.tab.c"
    break;

  case 41: /* exp: var ASSIGN exp  */
#line 235 "cm.y"
              {
                yyval = newExpNode(OpK, -1);
                yyval->attr.op = ASSIGN;
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
              }
#line 1581 "cm.tab.c"
    break;

  case 42: /* exp: simp_exp  */
#line 241 "cm.y"
                       { yyval = yyvsp[0]; }
#line 1587 "cm.tab.c"
    break;

  case 43: /* var: id  */
#line 243 "cm.y"
                 { yyval = yyvsp[0]; }
#line 1593 "cm.tab.c"
    break;

  case 44: /* var: id OB exp CB  */
#line 245 "cm.y"
              {
                yyval = newExpNode(IdK, Variable);
                yyval->attr.name = yyvsp[-3]->attr.name;
                yyval->child[0] = yyvsp[-1];
              }
#line 1603 "cm.tab.c"
    break;

  case 45: /* simp_exp: soma_exp LTE soma_exp  */
#line 252 "cm.y"
              {
                  yyval = newExpNode(OpK, -1);
                  yyval->attr.op = LTE;
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0];
              }
#line 1614 "cm.tab.c"
    break;

  case 46: /* simp_exp: soma_exp LT soma_exp  */
#line 259 "cm.y"
              {
                  yyval = newExpNode(OpK, -1);
                  yyval->attr.op = LT;
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0];
              }
#line 1625 "cm.tab.c"
    break;

  case 47: /* simp_exp: soma_exp GT soma_exp  */
#line 266 "cm.y"
              {
                  yyval = newExpNode(OpK, -1);
                  yyval->attr.op = GT;
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0];
              }
#line 1636 "cm.tab.c"
    break;

  case 48: /* simp_exp: soma_exp GTE soma_exp  */
#line 273 "cm.y"
              {
                  yyval = newExpNode(OpK, -1);
                  yyval->attr.op = GTE;
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0];
              }
#line 1647 "cm.tab.c"
    break;

  case 49: /* simp_exp: soma_exp EQ soma_exp  */
#line 280 "cm.y"
              {
                  yyval = newExpNode(OpK, -1);
                  yyval->attr.op = EQ;
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0];
              }
#line 1658 "cm.tab.c"
    break;

  case 50: /* simp_exp: soma_exp DIF soma_exp  */
#line 287 "cm.y"
              {
                  yyval = newExpNode(OpK, -1);
                  yyval->attr.op = DIF;
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0];
              }
#line 1669 "cm.tab.c"
    break;

  case 51: /* simp_exp: soma_exp  */
#line 293 "cm.y"
                       { yyval = yyvsp[0]; }
#line 1675 "cm.tab.c"
    break;

  case 52: /* soma_exp: soma_exp PLUS termo  */
#line 296 "cm.y"
              {
                  yyval = newExpNode(OpK, -1);
                  yyval->attr.op = PLUS;
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0];
              }
#line 1686 "cm.tab.c"
    break;

  case 53: /* soma_exp: soma_exp MINUS termo  */
#line 303 "cm.y"
              {
                  yyval = newExpNode(OpK, -1);
                  yyval->attr.op = MINUS;
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0];
              }
#line 1697 "cm.tab.c"
    break;

  case 54: /* soma_exp: termo  */
#line 309 "cm.y"
                    { yyval = yyvsp[0]; }
#line 1703 "cm.tab.c"
    break;

  case 55: /* termo: termo MULT fator  */
#line 312 "cm.y"
              {
                  yyval = newExpNode(OpK, -1);
                  yyval->attr.op = MULT;
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0];
              }
#line 1714 "cm.tab.c"
    break;

  case 56: /* termo: termo DIV fator  */
#line 319 "cm.y"
              {
                  yyval = newExpNode(OpK, -1);
                  yyval->attr.op = DIV;
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0];
              }
#line 1725 "cm.tab.c"
    break;

  case 57: /* termo: fator  */
#line 325 "cm.y"
                    { yyval = yyvsp[0]; }
#line 1731 "cm.tab.c"
    break;

  case 58: /* fator: OP exp CP  */
#line 327 "cm.y"
                        { yyval = yyvsp[-1]; }
#line 1737 "cm.tab.c"
    break;

  case 59: /* fator: var  */
#line 328 "cm.y"
                  { yyval = yyvsp[0]; }
#line 1743 "cm.tab.c"
    break;

  case 60: /* fator: ativ  */
#line 329 "cm.y"
                   { yyval = yyvsp[0]; }
#line 1749 "cm.tab.c"
    break;

  case 61: /* fator: NUM  */
#line 330 "cm.y"
                  { yyval = newExpNode(NumK, -1);
                    yyval->type = Integer;
                    yyval->attr.val = atoi(tokenString); }
#line 1757 "cm.tab.c"
    break;

  case 62: /* ativ: id OP args CP  */
#line 335 "cm.y"
              {
                yyval = newExpNode(IdK, Ativation);
                yyval->attr.name = yyvsp[-3]->attr.name;
                yyval->child[0] = yyvsp[-1];
              }
#line 1767 "cm.tab.c"
    break;

  case 63: /* args: arg_lista  */
#line 341 "cm.y"
                        { yyval = yyvsp[0];}
#line 1773 "cm.tab.c"
    break;

  case 64: /* args: %empty  */
#line 342 "cm.y"
              {yyval = NULL;}
#line 1779 "cm.tab.c"
    break;

  case 65: /* arg_lista: arg_lista COMMA exp  */
#line 345 "cm.y"
              { 
                YYSTYPE t = yyvsp[-2];
                if (t != NULL)
                { 
                  while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = yyvsp[0];
                  yyval = yyvsp[-2]; 
                }
                else yyval = yyvsp[0];
              }
#line 1795 "cm.tab.c"
    break;

  case 66: /* arg_lista: exp  */
#line 356 "cm.y"
                  { yyval = yyvsp[0];}
#line 1801 "cm.tab.c"
    break;

  case 67: /* id: ID  */
#line 359 "cm.y"
                 {yyval = newExpNode(IdK, Variable);
                  yyval->attr.name = copyString(tokenString);
                  yyval->lineno = lineno;}
#line 1809 "cm.tab.c"
    break;


#line 1813 "cm.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 364 "cm.y"


int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}

