#include "dicionario.h"

int main(int argc, String argv[]) {
	No* root = LoadDictionary(); // Carrega dicionario de palavras

	FILE *inputFile, *outputFile;
	openAndVerifyFile(&inputFile, argv[1], "r");
	openAndVerifyFile(&outputFile, argv[2], "w");

	char characterTxt[2];
	String wordTxt = (String)malloc(MAX_SIZE_WORD);
	strcpy(wordTxt, "");

	regex_t regex;
	int returnRegex;
	
	// percorrendo o arquivo caracter a caracter
	while (fscanf(inputFile, "%c", characterTxt) != EOF) {
		/*comparando e executando a regex com a palavra especifica de acordo com o padrão especificado;
		 * letras de A a Z(uppercase)
		 * letras de a a z(lowercase)
		 * À-ú (letras com ascentos, tanto lowercase como uppercase)
		*/
		returnRegex = regcomp(&regex, "[A-Za-zÀ-ú]", 0);
		returnRegex = regexec(&regex, characterTxt, 0, NULL, 0);

		if(returnRegex == REG_NOMATCH) { // Se o caracter não corresponder com o padrão regex
			if(strcmp(wordTxt, "") != 0) {
				String wordOut = changeLowerCase(wordTxt);
				wordOut[strlen(wordTxt)] = '\0';

				if(search(root, wordOut) || search(root, wordTxt)) {
					fprintf(outputFile, "%s", wordTxt);
				} else {
					fprintf(outputFile, "[%s]", wordTxt);
				}
				
				strcpy(wordTxt, "");
				free(wordOut);
			}

			fprintf(outputFile, "%c", characterTxt[0]);
		} else if (!returnRegex) { // Se o caracter corresponder com o padrão regex
			// se não for [' '\n\t\v\f\r]     se não for [0123456789]
		 	if(!isspace(characterTxt[0]) || !isdigit(characterTxt[0]))
				strncat(wordTxt, characterTxt, strlen(wordTxt) +1);
			strcpy(characterTxt, "");
		}
	}

	// liberação de memória e fechamento de arquivos
	regfree(&regex);
	free(wordTxt);
	free(root);

	fclose(inputFile);
	fclose(outputFile);
	return 0;
}

// Função para abrir arquivo (função de assistência)
void openAndVerifyFile(FILE **filePGM,  String filePath, String operation) {
    if(!(*filePGM = fopen(filePath, operation))) {
        perror("> Error opening file!");
        exit(1);
    }
}

// Função para transformar palavra em caixa baixa (função de assistência)
String changeLowerCase(String wordTBChange) {
	String changedWord = (String)malloc(sizeof(char)*MAX_SIZE_WORD);
	strcpy(changedWord, wordTBChange);
	
	for(int i=0; i<strlen(changedWord); i++) changedWord[i] = tolower(changedWord[i]);
	return changedWord;
}

// Função para medir distancia entre duas strings (função de assistência)
int levenshtein(const String s1, const String s2) {
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