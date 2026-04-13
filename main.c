#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "afd_numero.h"
#include "identificador.h"
#include "operadores.h"
#include "lexer.h"
#include "token.h"
#include "ts.h"

int main(int argc, char *argv[]){

    if (argc < 2) {
        printf("Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }

    FILE *entrada = fopen(argv[1], "r");
    if (entrada == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    char codigo[10000];
    int tamanho = fread(codigo, 1, sizeof(codigo) - 1, entrada);
    codigo[tamanho] = '\0';
    fclose(entrada);
    int i = 0;
    int linha = 1;
    int coluna = 1;

    Token t;

    inicializarTS();

    FILE *f = fopen("saida.lex", "w");

    if (f == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    FILE *err = fopen("saida.err", "w");

    while (codigo[i] != '\0') {
        Token t = getNextToken(codigo, &i, &linha, &coluna);

        if (t.type == ERRO && strcmp(t.lexema, "EOF") == 0) {
            break;
        }

        printf("<%s, %s> %d %d\n",
                tokenTypeToString(t.type),
                t.lexema,
                t.linha,
                t.coluna);

        fprintf(f, "<%s, %s> %d %d\n",
                tokenTypeToString(t.type),
                t.lexema,
                t.linha,
                t.coluna);

        if (t.type == ERRO) {
            fprintf(err, "<%s, %s> %d %d\n",
                    tokenTypeToString(t.type),
                    t.lexema,
                    t.linha,
                    t.coluna);
        }


    }

    salvarTS();
    fclose(err);
    fclose(f);

    return 0;
}

