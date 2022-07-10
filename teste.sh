#!/bin/bash
ARQUIVOS=$(ls input-file)
SAIDA="output-file"

if [ ! -d "$SAIDA" ]; 
then
  mkdir $SAIDA
fi

for i in $ARQUIVOS;
do
	echo -e "$(tput setaf 2 && tput bold)Rodando programa para $i...$(tput sgr 0)\n"

    NEW_NAME=${i%.txt}.txt
	time ./ortografia input-file/$i $SAIDA/$NEW_NAME
done