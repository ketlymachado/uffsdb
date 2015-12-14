#define INSERT 257
#define INTO 258
#define VALUES 259
#define SELECT 260
#define FROM 261
#define WHERE 262
#define COMPARISON 263
#define CREATE 264
#define TABLE 265
#define INTEGER 266
#define VARCHAR 267
#define DOUBLE 268
#define CHAR 269
#define PRIMARY 270
#define KEY 271
#define REFERENCES 272
#define DATABASE 273
#define DROP 274
#define OBJECT 275
#define NUMBER 276
#define VALUE 277
#define QUIT 278
#define LIST_TABLES 279
#define LIST_TABLE 280
#define ALPHANUM 281
#define CONNECT 282
#define HELP 283
#define LIST_DBASES 284
#define CLEAR 285
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
