#include "dicionario.h"

char filename[] = "resource-file/brazilian.txt";

No* LoadDictionary() {
	FILE *FileDictionary;
	openAndVerifyFile(&FileDictionary, filename, "r");

    No *root = NULL;
    String keyword = (char*)malloc(MAX_SIZE_WORD);

    while (fscanf(FileDictionary, "%[^\n] ", keyword) != EOF) {
        insert(&root, keyword);
    }

	fclose(FileDictionary);
    return root;
}

// void insert(No **list, char *keyword) {
//     No *NewAssistent, *NewElement = (No*)malloc(sizeof(No));

//     if(NewElement) {
//         strcpy(NewElement->word, keyword);
//         NewElement->next = NULL;
//         if(!(*list))
//             (*list) = NewElement;
//         else {
//             NewAssistent = (*list);

//             char *strNewElement, *strNewAssistent = (char*)malloc(sizeof(char)*MAX_SIZE_WORD);
//             strcpy(strNewElement, changeLowerCase(NewElement->word));
            
//             while(NewAssistent->next && strcmp(NewElement->word, NewAssistent->word) > 0) {
//                 NewAssistent = NewAssistent->next;
//                 strcpy(strNewElement, changeLowerCase(NewAssistent->word));
//             }
//             NewElement->next = NewAssistent->next;
//             NewAssistent->next = NewElement;
//         }
//     } else
//         printf("\033[0;31m> Error in allocating memory to NewElement! :(\033[0m\n");
// }

// String search(No *list, char *keyword, unsigned long int start, unsigned long int end) {
//     unsigned long int center;

//     size_t similarity=strlen(keyword);
//     String similarWord;

//     if(start<=end) {
//         center = (start + end) / 2;
//         if(strcmp(keyword, (list+center)->word) == 0)
//             return (list+center)->word;
//         else {
//             if(strcmp(keyword, (list+center)->word) < 0) {
//                 if(similarity > levenshtein(keyword, (list+center)->word)) {
//                     similarity = levenshtein(keyword, (list+center)->word);
//                     strcpy(similarWord, (list+center)->word);
//                 }
//                 return search(list, keyword, start, center-1);
//             } else {
//                 if(similarity > levenshtein(keyword, (list+center)->word)) {
//                     similarity = levenshtein(keyword, (list+center)->word);
//                     strcpy(similarWord, (list+center)->word);
//                 }
//                 return search(list, keyword, center+1, end);
//             }
//         }
//     }
//     return similarWord;
// }

// WITH TREE
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