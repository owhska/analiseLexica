#include <stdio.h>
#include <string.h>
#include "ts.h"

#define MAX_TS 100

Simbolo tabela[MAX_TS];
int tamanhoTS = 0;

int existe(char *lexema) {
    for (int i = 0; i < tamanhoTS; i++) {
        if (strcmp(tabela[i].lexema, lexema) == 0)
            return 1;
    }
    return 0;
}

void adicionarSimbolo(char *lexema, TokenType tipo) {
    if (!existe(lexema)) {
        strcpy(tabela[tamanhoTS].lexema, lexema);
        tabela[tamanhoTS].tipo = tipo;
        tamanhoTS++;
    }
}

void salvarTS() {
    FILE *f = fopen("saida.ts", "w");

    for (int i = 0; i < tamanhoTS; i++) {
        fprintf(f, "%s\n", tabela[i].lexema);
    }

    fclose(f);
}
