# Verificador Ortografico

Este projeto consiste em um verificador ortográfico, um <a href="https://pt.wikipedia.org/wiki/Interface_de_linha_de_comandos">CLI</a> que recebe um texto como entrada e produz o mesmo texto em um novo arquivo de saída. As palavras potencialmente incorretas são indicadas entre colchetes ([...]). Uma palavra é considerada potencialmente incorreta se não for encontrada em um arquivo de dicionário. O verificador ortografico também sugerir correções, indicando uma plavra mais próxima, e pode ser visualizada seguindo o seguinte modelo:

```
Desenvolvimeto de [Sofware(Software)]
```

Exemplo de texto de entrada:
```
Para que o pocessador possa interromper a execução de uma tarefa
e retornar a ela mais tarde, sem corromper seu estado interno,
é necessário definir operações para salvar e restaurrar o
contexto da tarefa.

O ato de salvar os valores do contexto atual em seu TCB e
possivelmente restaurar o contexto de outra tarefa, previamente
salvo em outro TCB, é denominado "troca de contexto".
```
O programa deve gerar esta saída:

```
Para que o [pocessador (processador)] possa interromper a execução de uma tarefa
e retornar a ela mais tarde, sem corromper seu estado interno, 
é necessário definir operações para salvar e [restaurrar (restaurar)] o
contexto da tarefa.

O ato de salvar os valores do contexto atual em seu [TCB (aba)] e
possivelmente restaurar o contexto de outra tarefa, previamente
salvo em outro [TCB (aba)], é denominado "troca de contexto".
```

## ETAPAS DO PROJETO

- [x] CONFIGURAÇÕES INICIAIS
    - [x] CONFIGURAÇÃO DE ARQUIVO [MAKEFILE](Makefile)
    - [x] FUNCIONALIDADE PARA LEITURA DOS ARQUIVOS (.txt) PELO TERMINAL
    - [x] FUNCIONALIDADE PARA GERAR O ARQUIVO DE SAIDA (.txt) COM NOME ESPECIFICADO, PASSADO COMO ARGUMENTO PELO TERMINAL 
- [ ] ORTOGRAFIA
    - [x] CARREGAR VETOR DE PALAVRAS/ÁRVORE DE PREFIXOS
    - [x] FILTRAR AS PALAVRAS DO ARQUIVO DE ENTRADA(OBS: INCLUINDO AS COM ACENTOS)
    - [x] FUNCIONALIDADE PARA PERCORRER O ARQUIVO DE ENTRADA E COMPARAR AS PALAVRAS FILTRADAS COM AS DO VETOR([O DICIONÁRIO](resource-file/brazilian.txt))
    - [ ] FUNCIONALIDADE PARA SEGERIR CORREÇÃO UTILIZANDO O ALGORITIMO DE LEVENSHTEIN + BUSCA BINÁRIA
- [x] DICIONÁRIO
    - [x] LEITURA DO ARQUIVO (.txt) COMO DICIONÁRIO DE PALAVRAS
    - [x] CRIAR VETOR DE PALAVRAS COM ALOCAÇÃO DINÂMICA OU IMPLEMENTAR A ÁRVORE DE PREFIXOS
    - [x] BUSCA BINÁRIA PARA LOCALIZAÇÃO DAS PALAVRAS JA ARMAZENADAS NA MEMÓRIA

## RODANDO O PROGRAMA
Para roda o <a href="https://pt.wikipedia.org/wiki/Interface_de_linha_de_comandos">CLI</a> no terminal linux basta seguir as seguintes instruções

```bash

$ ./ortografica -i input.txt -o output.txt

```
