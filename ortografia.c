#include "dicionario.h"

int main(int argc, char *argv[]) {
	No* root = LoadDictionary(); // Carregar dicionario de palavras

	FILE *inputFile, *outputFile;
	openAndVerifyFile(&inputFile, argv[1], "r");
	openAndVerifyFile(&outputFile, argv[2], "w");

	char CHAR_TEXT[2];
	String WORD_TEXT = (char*)malloc(MAX_SIZE_WORD);
	strcpy(WORD_TEXT, "");

	regex_t er;
	int returnER;

	while (fscanf(inputFile, "%c", CHAR_TEXT) != EOF) {
		returnER = regcomp(&er, "[A-Za-zÀ-ú]", 0);
		returnER = regexec(&er, CHAR_TEXT, 0, NULL, 0);

		if(returnER == REG_NOMATCH) {
			if(strcmp(WORD_TEXT, "") != 0) {
				String wordOut = changeLowerCase(WORD_TEXT);

				wordOut[strlen(WORD_TEXT)] = '\0';

				if(search(root, wordOut) || search(root, WORD_TEXT)) {
					fprintf(outputFile, "%s", WORD_TEXT);
				} else {
					sprintf(wordOut, "[%s]", WORD_TEXT);
					fprintf(outputFile, "[%s]", WORD_TEXT);
				}
				
				strcpy(WORD_TEXT, "");
				free(wordOut);
			}

			fprintf(outputFile, "%c", CHAR_TEXT[0]);
		} else if (!returnER) {
			//se não [' '\n\t\v\f\r]        se [0123456789]
		 	if(!isspace(CHAR_TEXT[0]) || !isdigit(CHAR_TEXT[0]))
				strncat(WORD_TEXT, CHAR_TEXT, strlen(WORD_TEXT) +1);
			strcpy(CHAR_TEXT, "");
		}
	}

	regfree(&er);
	free(WORD_TEXT);
	free(root);

	fclose(inputFile);
	fclose(outputFile);
	return 0;
}

void openAndVerifyFile(FILE **filePGM,  char filePath[], char operation[]) {
    if(!(*filePGM = fopen(filePath, operation))) {
        perror("> Error opening file!");
        exit(1);
    }
}

String changeLowerCase(char wordTBChange[]) {
	char *changedWord = (char*)malloc(sizeof(char)*MAX_SIZE_WORD);
	strcpy(changedWord, wordTBChange);

	for(int i=0; i<strlen(changedWord); i++) changedWord[i] = tolower(changedWord[i]);
	return changedWord;
}

// usar para medir distancia entre duas strings
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