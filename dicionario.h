#ifndef DICIONARIO_H_INCLUDED
#define DICIONARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#define MAX_SIZE_WORD 47

typedef char* String;

// Arvore ternária
typedef struct no {
    int character;
    struct no *left, *eq, *right;
} No;

// Funções de assistencia
void openAndVerifyFile(FILE **filePGM, String filePath, String operation);
int levenshtein(const String s1, const String s2);
String changeLowerCase(String changedWord);

No* LoadDictionary();

// Funções relativas a arvore ternária
No* create(char character);
void insert(No **root, String keyword);
bool search(No *root, String keyword);

#endif
