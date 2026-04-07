#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "afd_numero.h"
#include "identificador.h"
#include "operadores.h"

int main(){

    char testes[][10] = {
        ":=",
        "<=",
        "<>",
        "+",
        "-",
        "*",
        "/",
        ";",
        "(",
        ":",
        "."
    };

    int total = sizeof(testes) / sizeof(testes[0]);

    for (int i = 0; i < total; i++) {
        TokenType t = reconhecerOperador(testes[i]);

        if (t != ERRO)
            printf("%s -> OPERADOR/SIMBOLO\n", testes[i]);
        else
            printf("%s -> INVALIDO\n", testes[i]);
    }
    return 0;
}

