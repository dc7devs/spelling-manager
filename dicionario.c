#include "dicionario.h"

char filename[] = "resource-file/brazilian.txt";

No* LoadDictionary() {
	FILE *FileDictionary;
	openAndVerifyFile(&FileDictionary, filename, "r");

    struct stat fDictionary;
    if (stat(filename, &fDictionary) == -1) {
        perror("> Error in struct stat");
        exit(1);
    }

    No *root = NULL;
    String keyword = (char*) malloc(fDictionary.st_size);

    while (fscanf(FileDictionary, "%[^\n ] ", keyword) != EOF) {
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
void insert(No **root, char *keyword) {
    int sizeWord = strlen(keyword);

    // Caso Base: A árvore está vazia
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
bool search(No *root, char *keyword) {
    if (!root)
        return false;
 
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