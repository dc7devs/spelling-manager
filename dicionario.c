#include "dicionario.h"

#define SIZE_PALAVRAS 100 // alocação dinamica
#define LINHAS 10	  	  // alocação dinamica

char * Dictionary(char keyword[]) {
	FILE *fileDictionary;
	
	char dictionaryWord[SIZE_PALAVRAS];
	char *wordVector[LINHAS]; // malloc
	long int count;

	openAndVerifyFile(&fileDictionary, "resource-file/dictionary.txt", "r");

	// EXEMPLO
	for(int i=0; i<LINHAS; i++) {
		fgets(dictionaryWord, sizeof(dictionaryWord), fileDictionary);
		wordVector[i] = strdup(dictionaryWord);

		printf("%ld. %s", i, wordVector[i]);
	}

	/* O dicionário deve ser totalmente carregado em um vetor de palavras na memória
	 * RAM antes de ser usado, usando alocação dinâmica (os mais ousados podem tentar
	 * implementar este projeto usando uma árvore de prefixos).
	 */
	// A localização das palavras no dicionário deve usar um algoritmo de busca binária.

	// Procurar por keword ou a mais proxima de keyword
	fclose(fileDictionary);
	return *wordVector;
}
