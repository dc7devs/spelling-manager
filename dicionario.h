#ifndef DICIONARIO_H_INCLUDED
#define DICIONARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * Dictionary(char keyword[]);
void openAndVerifyFile(FILE **filePGM, char filePath[], char operation[]) ;

#endif