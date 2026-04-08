#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "afd_numero.h"
#include "identificador.h"
#include "operadores.h"
#include "lexer.h"
#include "token.h"
#include "ts.h"

int main(){
    char codigo[] = "program x x y if x z";
    int i = 0;
    int linha = 1;
    int coluna = 1;

    Token t;

    FILE *f = fopen("saida.lex", "w");

    if (f == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    FILE *err = fopen("saida.err", "w");

    while (codigo[i] != '\0') {
        Token t = getNextToken(codigo, &i, &linha, &coluna);

        printf("<%s, %s, linha=%d, coluna=%d>\n",
                tokenTypeToString(t.type),
                t.lexema,
                t.linha,
                t.coluna);

        fprintf(f, "<%s, %s, linha=%d, coluna=%d>\n",
                tokenTypeToString(t.type),
                t.lexema,
                t.linha,
                t.coluna);

        if (t.type == ERRO) {
            fprintf(err, "<%s, %s, linha=%d, coluna=%d>\n",
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

