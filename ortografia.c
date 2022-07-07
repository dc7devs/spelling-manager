#include "dicionario.h"

int main(int argc, char *argv[]) {
	LoadDictionary();

	FILE *inputFile, *outputFile;
	openAndVerifyFile(&inputFile, argv[1], "r");
	openAndVerifyFile(&outputFile, argv[2], "w");
	
	struct stat file;
	if(stat(argv[1], &file) == -1) {
		perror("> Error stat!");
		exit(EXIT_FAILURE);
	}

	char CHAR_TEXT[2];
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
 				// passar palavra para a função de busca ao dicionario
			}
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