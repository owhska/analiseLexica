# Analisador Léxico — MicroPascal

Trabalho prático da disciplina de Linguagens Formais, Autômatos e Compiladores — UCB, 1° semestre de 2026.

Implementa um analisador léxico para a linguagem **MicroPascal (µ-Pascal)** em C, baseado em um Autômato Finito Determinístico (AFD). Reconhece tokens, detecta erros léxicos e mantém uma Tabela de Símbolos.

## Arquivos

| Arquivo | Descrição |
|---|---|
| `main.c` | Ponto de entrada, loop principal de leitura e geração dos arquivos de saída |
| `lexer.c/h` | Função `getNextToken()` — núcleo do analisador |
| `afd_numero.c/h` | AFD para reconhecimento de inteiros, reais e notação científica |
| `identificador.c/h` | Reconhecimento de identificadores e palavras reservadas |
| `operadores.c/h` | Reconhecimento de operadores e símbolos |
| `token.c/h` | Definição da struct `Token` e enum `TokenType` |
| `ts.c/h` | Tabela de Símbolos |
| `grafico.dot` | Diagrama do AFD (Graphviz) |

## Compilar e executar

```bash
gcc main.c afd_numero.c identificador.c operadores.c lexer.c token.c ts.c -o main

./main <arquivo.pac>
```

## Saídas geradas

- `saida.lex` — todos os tokens reconhecidos com linha e coluna
- `saida.ts` — Tabela de Símbolos (identificadores e palavras reservadas)
- `saida.err` — erros léxicos encontrados

## Exemplo de saída (.lex)

```
<KW_PROGRAM, program, linha=1, coluna=1>
<ID, exemplo, linha=1, coluna=9>
<SMB_SEM, ;, linha=1, coluna=16>
```

