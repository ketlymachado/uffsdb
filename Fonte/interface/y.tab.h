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
extern YYSTYPE yylval;
