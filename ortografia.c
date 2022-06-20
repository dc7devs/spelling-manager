#include "dicionario.h"

int main(int argc, char *argv[]) {
	FILE *inputFile;
	openAndVerifyFile(&inputFile, argv[1], "r");
	
	Dictionary("");

	fclose(inputFile);
	return 0;
}

void openAndVerifyFile(FILE **filePGM, char filePath[], char operation[]) {
    if(!(*filePGM = fopen(filePath, operation))) {
        printf("> Error opening file!");
        exit(1);
    }
}
