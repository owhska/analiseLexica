#!/bin/bash

rm -rf saida.err saida.ts saida.lex
gcc main.c afd_numero.c identificador.c operadores.c lexer.c token.c ts.c  -o main

