#ifndef DICIONARIO_H_INCLUDED
#define DICIONARIO_H_INCLUDED

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

typedef struct no {
    char *pointWord;
    struct no *left, *right;
} No;

void DictionaryMain();

void openAndVerifyFile(FILE **filePGM, char filePath[], char operation[]);
int levenshtein(const char *s1, const char *s2);

void printOut(No *root); // Fins de teste
No* insert(No *root, char *word);
int search(No *raiz, char *chave);
int size(No *raiz);

#endif