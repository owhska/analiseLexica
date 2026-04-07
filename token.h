#ifndef TOKEN_H
#define TOKEN_H


typedef enum {
    KW_PROGRAM, KW_VAR, KW_INTEGER, KW_REAL,
    ID, NUM_INT, NUM_REAL,
    OP_ASS, OP_AD, OP_MIN, OP_EQ, OP_NE, OP_LT,
    OP_LE, OP_GT, OP_GE, OP_MUL, OP_DIV,
    SMB_SEM, SMB_COM, SMB_OPA, SMB_CPA,
    SMB_COL, SMB_DOT, SMB_OBC, SMB_CBC,
    ERRO
} TokenType;

typedef struct{
    TokenType type;
    char lexema[100];
    int linha;
    int coluna;
} Token;

#endif
