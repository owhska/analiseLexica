#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "afd_numero.h"
#include "identificador.h"

int main(){

    char teste[][20] = {
        "123",
        "12.5",
        "1.2E10",
        "1.2E-3",
        ".",
        "E10",
        "12E",
        "+-10",
        "x",
        "abc123",
        "program",
        "var"
    };

    int total = sizeof(teste) / sizeof(teste[0]);

    for (int i = 0; i < total; i++) {

        if (reconhecerNumeros(teste[i])) {
            printf("%s -> NUMERO\n", teste[i]);
        }
        else if (reconhecerIdentificador(teste[i])) {

            TokenType t = verificarPalavraReservada(teste[i]);

            if (t == ID)
                printf("%s -> ID\n", teste[i]);
            else
                printf("%s -> PALAVRA RESERVADA\n", teste[i]);
        }
        else {
            printf("%s -> INVALIDO\n", teste[i]);
        }
    }

    return 0;

}

