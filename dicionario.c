#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "dicionario.h"
char filename[] = "resource-file/brazilian.txt";

void DictionaryMain() {
	FILE *fileDictionary;
	openAndVerifyFile(&fileDictionary, filename, "r");

    /* O dicionário deve ser totalmente carregado em um vetor de palavras na memória
	 * RAM antes de ser usado, usando alocação dinâmica (os mais ousados podem tentar
	 * implementar este projeto usando uma árvore de prefixos).
	 */

    struct stat sb;
    if (stat(filename, &sb) == -1) {
        perror("> Error in struct stat");
        exit(1);
    }

    No *root = NULL;
    char *stringWord = (char*) malloc(sb.st_size);

    while (fscanf(fileDictionary, "%[^\n] ", stringWord) != EOF) {
		root = insert(root, stringWord);
    }

    printOut(root);

    // A localização das palavras no dicionário deve usar um algoritmo de busca binária.

    free(root);
	fclose(fileDictionary);
}

No* insert(No *root, char* word) {
    if(root == NULL) {
        No *novo = (No*) malloc(sizeof(No));
        strcpy(novo->pointWord, word);
        novo->left = NULL;
        novo->right = NULL;
        return novo;
    } else {
        if(strcmp(word, root->pointWord) < 0)
            root->left = insert(root->left, word);
        if(strcmp(word, root->pointWord) > 0)
            root->right = insert(root->right, word);
        return root;
    }
}

// Fins de teste
void printOut(No *root) {
    if(root != NULL) {
        printOut(root->left);
        printf("%s\n", root->pointWord);
        printOut(root->left);
    }
}

int search(No *raiz, char *chave) {
    if(raiz == NULL) {
        return 0;
    } else {
        if(strcmp(raiz->pointWord, chave) == 0)
            return 1;
        else {
            if(strcmp(chave, raiz->pointWord) < 0)
                return search(raiz->left, chave);
            else
                return search(raiz->right, chave);
        }
    }
}

int size(No *raiz) {
    if(raiz == NULL)
        return 0;
    else
        return 1 + size(raiz->left) + size(raiz->right);
}

int levenshtein(const char *s1, const char *s2) {
    unsigned int s1len, s2len, x, y, lastdiag, olddiag;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int column[s1len + 1];
    for (y = 1; y <= s1len; y++)
        column[y] = y;
    for (x = 1; x <= s2len; x++) {
        column[0] = x;
        for (y = 1, lastdiag = x - 1; y <= s1len; y++) {
            olddiag = column[y];
            column[y] = MIN3(column[y] + 1, column[y - 1] + 1, lastdiag + (s1[y-1] == s2[x - 1] ? 0 : 1));
            lastdiag = olddiag;
        }
    }
    return column[s1len];
}