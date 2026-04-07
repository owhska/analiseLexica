#include <ctype.h>
#include <string.h>
#include "token.h"
#include "identificador.h"

int reconhecerIdentificador(char *str){
    
    if (!isalpha(str[0]))
        return 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (!isalnum(str[i]))
            return 0;
    }

    return -1;

}

TokenType verificarPalavraReservada(char *str) {

    if (strcmp(str, "program") == 0) return KW_PROGRAM;
    if (strcmp(str, "var") == 0) return KW_VAR;
    if (strcmp(str, "integer") == 0) return KW_INTEGER;
    if (strcmp(str, "real") == 0) return KW_REAL;

    return ID;
}
