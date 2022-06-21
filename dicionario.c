#include "dicionario.h"

void DictionaryMain() {
	FILE *fileDictionary;
	openAndVerifyFile(&fileDictionary, "resource-file/Brazilian.txt", "r");

	/* O dicionário deve ser totalmente carregado em um vetor de palavras na memória
	 * RAM antes de ser usado, usando alocação dinâmica (os mais ousados podem tentar
	 * implementar este projeto usando uma árvore de prefixos).
	 */
	// A localização das palavras no dicionário deve usar um algoritmo de busca binária.

	fclose(fileDictionary);
}

void SearchWord(char keyword[]) {
	
	// Procurar por keword ou a mais proxima de keyword
}
