#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>
#include <sys/stat.h>

#include "dicionario.h"

int main(int argc, char *argv[]) {
	FILE *inputFile, *outputFile;
	openAndVerifyFile(&inputFile, argv[1], "r");
	openAndVerifyFile(&outputFile, argv[2], "w");
	
	struct stat file;
	if(stat(argv[1], &file) == -1) {
		perror("> Error stat!");
		exit(EXIT_FAILURE);
	}

	char CHAR_TEXT;[2];
	char *WORD_TEXT = (char*) malloc(file.st_size);
	regex_t er;
	int returnER;

	while (fscanf(inputFile, "%c", CHAR_TEXT) != EOF) {
		returnER = regcomp(&er, "[A-za-zÀ-ú]", 0);
		returnER = regexec(&er, CHAR_TEXT, 0, NULL, 0);

		fprintf(outputFile, "%c", CHAR_TEXT[0]);

		if(!returnER) {	
			strncat(WORD_TEXT, CHAR_TEXT, strlen(WORD_TEXT) +1);
		} else if (returnER == REG_NOMATCH) {
			if ((isspace(CHAR_TEXT[0]) != 0)) {
				if (strlen(WORD_TEXT) >= 3) {
					// passar palavra para a função de busca ao dicionario
				}
			}
		}
	}

	regfree(&er);
	free(WORD_TEXT);
	fclose(inputFile);
	fclose(outputFile);
	return 0;
}

void openAndVerifyFile(FILE **filePGM, char filePath[], char operation[]) {
    if(!(*filePGM = fopen(filePath, operation))) {
        perror("> Error opening file!");
        exit(1);
    }
}