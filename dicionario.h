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
#include <sys/stat.h>

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

typedef char* String;

typedef struct no {
    int character;
    struct no *left, *eq, *right;
} No;

No *root;

void openAndVerifyFile(FILE **filePGM, char filePath[], char operation[]);
int levenshtein(const char *s1, const char *s2);

void LoadDictionary();

No* create(char character);
void insert(No **root, char *keyword);
bool search(No *root, char *keyword, char *linkword);

#endif
