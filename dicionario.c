#include "dicionario.h"

char filename[] = "resource-file/brazilian.txt";

void LoadDictionary() {
	FILE *fileDictionary;
	openAndVerifyFile(&fileDictionary, filename, "r");

    struct stat sb;
    if (stat(filename, &sb) == -1) {
        perror("> Error in struct stat");
        exit(1);
    }

    root = NULL;
    String keyword = (char*) malloc(sb.st_size);

    while (fscanf(fileDictionary, "%[^\n ] ", keyword) != EOF) {
        insert(&root, keyword);
    }

    // TESTES BUSCA =================================================================================== //

    // time_t t_ini, t_fim;
    // float tempo;
    
    // t_ini = time(NULL);

    // String wordOut = (char*) malloc(sb.st_size);
    // printf("%d", search(root, "carrilhões", wordOut));

    // t_fim = time(NULL); 

    // tempo = difftime(t_fim, t_ini); 
    // printf("\nTempo: %.3f", tempo);

    // TESTES BUSCA =================================================================================== //

	fclose(fileDictionary);
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

// Função para pesquisar uma determinada palavra em uma árvore de busca ternária
bool search(No *root, char *keyword, char *linkword) {
    if (!root)
        return false;
 
    if (*keyword < root->character) {
        return search(root->left, keyword, linkword);

    } else if (*keyword > root->character) {
        return search(root->right, keyword, linkword);
    } else {
        if (*(keyword+1) == '\0') {
            *linkword = root->character;
            *(linkword+1) = '\0';
            return true;
        }

        *linkword = root->character;
        *linkword++;
        return search(root->eq, keyword+1, linkword);
    }
}