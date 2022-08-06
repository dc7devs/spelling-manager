#include "dicionario.h"

char filename[] = "resource-file/brazilian.txt";

// Carregar dicionário de palavra (declaração)
No* LoadDictionary() {
	FILE *FileDictionary;
	openAndVerifyFile(&FileDictionary, filename, "r");

    No *root = NULL;
    String keyword = (String)malloc(MAX_SIZE_WORD);

    while (fscanf(FileDictionary, "%[^\n] ", keyword) != EOF) {
        insert(&root, keyword);
    }

	fclose(FileDictionary);
    return root;
}

// Função de utilitário para criar um novo nó de árvore de pesquisa ternária
No* create(char character) {
    No* NewNo = (No*) malloc(sizeof( No ));
    NewNo->character = character;
    NewNo->left = NewNo->eq = NewNo->right = NULL;
    return NewNo;
}

// Função para inserir uma nova palavra em uma árvore de busca ternária
void insert(No **root, String keyword) {
    int sizeWord = strlen(keyword);
    if (!(*root))
        *root = create(*keyword);
    if ((*keyword) < (*root)->character)
        insert(&( (*root)->left ), keyword);
    else if ((*keyword) > (*root)->character)
        insert(&( (*root)->right ), keyword);
    else {
        if (*(keyword+1)) {
            insert(&((*root)->eq), keyword+1);
        }
    }
}

// Função para pesquisar uma determinada palavra na árvore de busca ternária
bool search(No *root, String keyword) {
    if (!root)
        return NULL;
 
    if (*keyword < root->character) {
        return search(root->left, keyword);

    } else if (*keyword > root->character) {

        return search(root->right, keyword);
    } else {
        if (*(keyword+1) == '\0') {
            return true;
        }
        return search(root->eq, keyword+1);
    }
}