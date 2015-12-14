#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "yacc.y"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "../buffend.h"
#include "parser.h"

extern char* yytext[];
extern FILE * yyin;
extern FILE* outFile_p;

int yywrap() {
    return 1;
}

#line 19 "yacc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int intval;
    double floatval;
    int subtok;
    char *strval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 49 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INSERT 257
#define INTO 258
#define VALUES 259
#define SELECT 260
#define FROM 261
#define WHERE 262
#define COMPARISON 263
#define JOIN 264
#define ON 265
#define CREATE 266
#define TABLE 267
#define INTEGER 268
#define VARCHAR 269
#define DOUBLE 270
#define CHAR 271
#define PRIMARY 272
#define KEY 273
#define REFERENCES 274
#define DATABASE 275
#define DROP 276
#define OBJECT 277
#define NUMBER 278
#define VALUE 279
#define QUIT 280
#define LIST_TABLES 281
#define LIST_TABLE 282
#define ALPHANUM 283
#define CONNECT 284
#define HELP 285
#define LIST_DBASES 286
#define CLEAR 287
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    9,   17,
   10,   16,   12,   13,    7,    8,   15,   14,   19,    1,
   11,   18,   20,   20,   22,   22,   23,   21,   21,   24,
   24,   24,   25,    3,   26,   26,   28,   30,   28,   28,
   28,   27,   29,   29,   29,   31,   32,   33,   34,    5,
   35,   36,    4,   37,   38,    6,   40,    2,   39,   39,
   44,   44,   45,   41,   43,   47,   43,   49,   50,   46,
   48,   48,   48,   48,   42,   52,   42,   51,   54,   53,
};
static const short yylen[] = {                            2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    0,    2,    1,
    1,    1,    1,    1,    2,    1,    1,    1,    0,   10,
    1,    1,    0,    3,    1,    3,    1,    1,    3,    1,
    1,    1,    0,    8,    3,    5,    1,    0,    5,    1,
    1,    1,    0,    2,    5,    1,    1,    0,    0,    6,
    0,    0,    6,    0,    0,    6,    0,    8,    1,    1,
    1,    3,    1,    1,    0,    0,    3,    0,    0,    5,
    1,    1,    1,    1,    0,    0,    5,    1,    0,    4,
};
static const short yydefred[] = {                         0,
    0,   67,    0,    0,   20,   21,   26,    0,    0,   28,
   27,   22,   23,   24,   31,    0,    1,    2,    3,    4,
    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
   15,   16,   17,   29,    0,   43,   61,   58,   64,   25,
   19,    0,   73,   69,    0,   70,    0,    0,    0,    0,
    0,   32,    0,    0,    0,    0,   62,   59,   65,    0,
    0,   74,    0,   72,    0,    0,    0,    0,   37,    0,
    0,    0,   86,    0,   52,    0,    0,   63,   60,   66,
   34,    0,    0,    0,   76,    0,    0,   47,   48,   50,
   51,    0,   36,   41,   40,   42,    0,    0,   88,    0,
    0,   68,   44,    0,    0,    0,    0,    0,    0,    0,
   81,   84,   83,   82,   77,   78,    0,   54,   56,    0,
    0,   30,   39,   89,   87,    0,    0,    0,   46,    0,
    0,   49,   57,    0,    0,   79,   55,   90,   80,
};
static const short yydgoto[] = {                         16,
   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
   27,   28,   29,   30,   31,   32,   33,   53,   42,   61,
   97,   70,   71,   98,   48,   76,   77,   92,  107,  104,
  120,  134,   50,   67,   49,   66,   51,   68,   45,   35,
   63,   74,   86,   46,   47,  115,  101,  116,  126,  139,
  100,   84,  125,  130,
};
static const short yysindex[] = {                       -40,
 -252,    0, -260, -250,    0,    0,    0, -266, -254,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -39,    0,    0,    0,    0,    0,
    0, -249,    0,    0, -234,    0,  -15, -249, -240, -239,
 -238,    0,    6, -230, -228,    6,    0,    0,    0, -226,
 -209,    0, -212,    0, -224,   -4,   -4,   -4,    0,   16,
   14,    6,    0, -203,    0,   16, -227,    0,    0,    0,
    0, -226, -243, -217,    0,   -4,   -4,    0,    0,    0,
    0, -256,    0,    0,    0,    0,   16,   18,    0, -202,
 -257,    0,    0,    6, -208, -213,   22,   -4, -243, -257,
    0,    0,    0,    0,    0,    0, -211,    0,    0,   28,
 -224,    0,    0,    0,    0, -194,   16, -207,    0, -192,
 -257,    0,    0,   31, -257,    0,    0,    0,    0,
};
static const short yyrindex[] = {                        73,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -187,    0,    0,    0,
    0,    0, -184,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -57,    0,    0,    0,    0,    0,    0,    0,
   35,    0,    0,   19,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    4,    0,    0,    0,    0,    0,   36,    0,    0,
    0,    0,    0,    0,    0,    0,   38,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -54,  -48,  -66,    0,    0,    0,    0,   32,    0,    0,
  -28,    1,    0,    0,    0,  -37,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   27,    0,    0,    0, -101,    0,    0,
    0,    0,    0,    0,
};
#define YYTABLESIZE 247
static const short yytable[] = {                         13,
   14,   85,   44,   81,   60,   34,   36,   65,  124,   87,
   40,   78,   79,   80,   37,  105,   38,  106,   15,  111,
  112,  113,   41,   83,   39,  114,   54,   52,   55,  136,
  108,  102,  103,  138,   94,   95,   57,   58,   59,   96,
   88,   89,   90,   91,   53,   13,   62,   53,   43,   72,
   69,   73,   75,  122,   15,  117,   14,   82,   85,   99,
  132,  109,  110,  119,  118,  121,  127,  128,  131,  133,
  135,  137,   18,   71,   33,   35,   38,   75,   45,   56,
  123,   64,   93,  129,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   85,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    1,    0,    0,    2,
    0,    0,    0,    0,    0,    3,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    4,    5,   43,    0,    6,
    7,    8,    0,    9,   10,   11,   12,
};
static const short yycheck[] = {                         40,
   41,   59,   42,   70,   53,  258,  267,   56,  110,   76,
  277,   66,   67,   68,  275,  272,  267,  274,   59,  277,
  278,  279,  277,   72,  275,  283,  261,  277,   44,  131,
   97,   86,   87,  135,  278,  279,  277,  277,  277,  283,
  268,  269,  270,  271,   41,   40,  277,   44,  277,  259,
  277,  264,  277,  108,   59,  104,   41,   44,  262,  277,
  127,   44,  265,  277,  273,   44,  278,   40,  263,  277,
  263,   41,    0,  261,  259,   41,   41,   59,   41,   48,
  109,   55,   82,  121,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  262,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,  260,
   -1,   -1,   -1,   -1,   -1,  266,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  276,  277,  277,   -1,  280,
  281,  282,   -1,  284,  285,  286,  287,
};
#define YYFINAL 16
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 287
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'",0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INSERT",
"INTO","VALUES","SELECT","FROM","WHERE","COMPARISON","JOIN","ON","CREATE",
"TABLE","INTEGER","VARCHAR","DOUBLE","CHAR","PRIMARY","KEY","REFERENCES",
"DATABASE","DROP","OBJECT","NUMBER","VALUE","QUIT","LIST_TABLES","LIST_TABLE",
"ALPHANUM","CONNECT","HELP","LIST_DBASES","CLEAR",
};
static const char *yyrule[] = {
"$accept : start",
"start : insert",
"start : select",
"start : create_table",
"start : create_database",
"start : drop_table",
"start : drop_database",
"start : table_attr",
"start : list_tables",
"start : connection",
"start : exit_program",
"start : semicolon",
"start : parentesis_open",
"start : parentesis_close",
"start : help_pls",
"start : list_databases",
"start : clear",
"start : qualquer_coisa",
"start :",
"connection : CONNECT OBJECT",
"qualquer_coisa : OBJECT",
"exit_program : QUIT",
"clear : CLEAR",
"parentesis_open : '('",
"parentesis_close : ')'",
"table_attr : LIST_TABLE OBJECT",
"list_tables : LIST_TABLES",
"list_databases : LIST_DBASES",
"help_pls : HELP",
"$$1 :",
"insert : INSERT INTO $$1 table opt_column_list VALUES parentesis_open value_list parentesis_close semicolon",
"semicolon : ';'",
"table : OBJECT",
"opt_column_list :",
"opt_column_list : parentesis_open column_list parentesis_close",
"column_list : column",
"column_list : column ',' column_list",
"column : OBJECT",
"value_list : value",
"value_list : value ',' value_list",
"value : VALUE",
"value : NUMBER",
"value : ALPHANUM",
"$$2 :",
"create_table : CREATE TABLE $$2 table parentesis_open table_column_attr parentesis_close semicolon",
"table_column_attr : column_create type attribute",
"table_column_attr : column_create type attribute ',' table_column_attr",
"type : INTEGER",
"$$3 :",
"type : VARCHAR $$3 parentesis_open NUMBER parentesis_close",
"type : DOUBLE",
"type : CHAR",
"column_create : OBJECT",
"attribute :",
"attribute : PRIMARY KEY",
"attribute : REFERENCES table_fk '(' column_fk ')'",
"table_fk : OBJECT",
"column_fk : OBJECT",
"$$4 :",
"$$5 :",
"drop_table : DROP TABLE $$4 OBJECT $$5 semicolon",
"$$6 :",
"$$7 :",
"create_database : CREATE DATABASE $$6 OBJECT $$7 semicolon",
"$$8 :",
"$$9 :",
"drop_database : DROP DATABASE $$8 OBJECT $$9 semicolon",
"$$10 :",
"select : SELECT $$10 opt_columns_list FROM table_select opt_join opt_condition semicolon",
"opt_columns_list : '*'",
"opt_columns_list : columns_list",
"columns_list : columns",
"columns_list : columns ',' columns_list",
"columns : OBJECT",
"table_select : OBJECT",
"opt_condition :",
"$$11 :",
"opt_condition : WHERE $$11 condition",
"$$12 :",
"$$13 :",
"condition : predicate $$12 COMPARISON predicate $$13",
"predicate : OBJECT",
"predicate : ALPHANUM",
"predicate : VALUE",
"predicate : NUMBER",
"opt_join :",
"$$14 :",
"opt_join : JOIN $$14 table_join ON join_condition",
"table_join : OBJECT",
"$$15 :",
"join_condition : predicate $$15 COMPARISON predicate",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 11:
#line 36 "yacc.y"
	{GLOBAL_PARSER.consoleFlag = 1; return 0;}
break;
case 19:
#line 45 "yacc.y"
	{connect(*yytext); GLOBAL_PARSER.consoleFlag = 1; return 0;}
break;
case 20:
#line 47 "yacc.y"
	{GLOBAL_PARSER.consoleFlag = 1; GLOBAL_PARSER.noerror = 0; return 0;}
break;
case 21:
#line 50 "yacc.y"
	{exit(0);}
break;
case 22:
#line 52 "yacc.y"
	{clear(); GLOBAL_PARSER.consoleFlag = 1; return 0;}
break;
case 23:
#line 54 "yacc.y"
	{GLOBAL_PARSER.parentesis++;}
break;
case 24:
#line 56 "yacc.y"
	{GLOBAL_PARSER.parentesis--;}
break;
case 25:
#line 59 "yacc.y"
	{
    if(connected.conn_active) {
        printTable(yylval.strval);
        GLOBAL_PARSER.consoleFlag = 1;
    } else
        notConnected();
    return 0;
}
break;
case 26:
#line 69 "yacc.y"
	{
    if(connected.conn_active) {
        printTable(NULL);
        GLOBAL_PARSER.consoleFlag = 1;
    } else
        notConnected();
    return 0;
}
break;
case 27:
#line 79 "yacc.y"
	{
    showDB();
    GLOBAL_PARSER.consoleFlag = 1;
    return 0;
}
break;
case 28:
#line 86 "yacc.y"
	{help(); GLOBAL_PARSER.consoleFlag = 1; return 0;}
break;
case 29:
#line 93 "yacc.y"
	{setMode(OP_INSERT);}
break;
case 30:
#line 93 "yacc.y"
	{
    if (GLOBAL_PARSER.col_count == GLOBAL_PARSER.val_count || GLOBAL_DATA.columnName == NULL)
        GLOBAL_DATA.N = GLOBAL_PARSER.val_count;
    else {
        printf("ERROR: The column counter doesn't match the value counter.\n");
        GLOBAL_PARSER.noerror=0;
    }
    return 0;
}
break;
case 32:
#line 105 "yacc.y"
	{setObjName(yytext);}
break;
case 37:
#line 111 "yacc.y"
	{setColumnInsert(yytext);}
break;
case 40:
#line 115 "yacc.y"
	{setValueInsert(yylval.strval, 'D');}
break;
case 41:
#line 116 "yacc.y"
	{setValueInsert(yylval.strval, 'I');}
break;
case 42:
#line 117 "yacc.y"
	{setValueInsert(yylval.strval, 'S');}
break;
case 43:
#line 120 "yacc.y"
	{setMode(OP_CREATE_TABLE);}
break;
case 44:
#line 120 "yacc.y"
	{
    GLOBAL_DATA.N = GLOBAL_PARSER.col_count;

    return 0;
}
break;
case 47:
#line 128 "yacc.y"
	{setColumnTypeCreate('I');}
break;
case 48:
#line 129 "yacc.y"
	{setColumnTypeCreate('S');}
break;
case 49:
#line 129 "yacc.y"
	{setColumnSizeCreate(yylval.strval);}
break;
case 50:
#line 130 "yacc.y"
	{setColumnTypeCreate('D');}
break;
case 51:
#line 131 "yacc.y"
	{setColumnTypeCreate('C');}
break;
case 52:
#line 133 "yacc.y"
	{setColumnCreate(yytext);}
break;
case 54:
#line 136 "yacc.y"
	{setColumnPKCreate();}
break;
case 56:
#line 139 "yacc.y"
	{setColumnFKTableCreate(yytext);}
break;
case 57:
#line 141 "yacc.y"
	{setColumnFKColumnCreate(yytext);}
break;
case 58:
#line 144 "yacc.y"
	{setMode(OP_DROP_TABLE);}
break;
case 59:
#line 144 "yacc.y"
	{setObjName(yytext);}
break;
case 60:
#line 144 "yacc.y"
	{return 0;}
break;
case 61:
#line 147 "yacc.y"
	{setMode(OP_CREATE_DATABASE);}
break;
case 62:
#line 147 "yacc.y"
	{setObjName(yytext);}
break;
case 63:
#line 147 "yacc.y"
	{return 0;}
break;
case 64:
#line 150 "yacc.y"
	{setMode(OP_DROP_DATABASE);}
break;
case 65:
#line 150 "yacc.y"
	{setObjName(yytext);}
break;
case 66:
#line 150 "yacc.y"
	{return 0;}
break;
case 67:
#line 153 "yacc.y"
	{setMode(OP_SELECT);}
break;
case 68:
#line 153 "yacc.y"
	{return 0;}
break;
case 69:
#line 155 "yacc.y"
	{setColumnSelect(yytext);}
break;
case 73:
#line 159 "yacc.y"
	{setColumnSelect(yytext);}
break;
case 74:
#line 161 "yacc.y"
	{setObjName(yytext);}
break;
case 75:
#line 163 "yacc.y"
	{setWhere(0);}
break;
case 76:
#line 163 "yacc.y"
	{setWhere(1);}
break;
case 78:
#line 165 "yacc.y"
	{setSelectCondition(0, yytext);}
break;
case 79:
#line 165 "yacc.y"
	{setSelectCondition(2, yytext);}
break;
case 80:
#line 165 "yacc.y"
	{setWhere(2);}
break;
case 81:
#line 167 "yacc.y"
	{setAuxT('O');}
break;
case 82:
#line 168 "yacc.y"
	{setAuxT('A');}
break;
case 83:
#line 169 "yacc.y"
	{setAuxT('V');}
break;
case 84:
#line 170 "yacc.y"
	{setAuxT('N');}
break;
case 85:
#line 172 "yacc.y"
	{setJoin(0);}
break;
case 86:
#line 172 "yacc.y"
	{setJoin(1);}
break;
case 88:
#line 174 "yacc.y"
	{setJoinObjName(yytext);}
break;
case 89:
#line 176 "yacc.y"
	{setSelectCondition(0, yytext);}
break;
case 90:
#line 176 "yacc.y"
	{setSelectCondition(2, yytext);}
break;
#line 867 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
