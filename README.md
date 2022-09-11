# 📖 Verificador ortográfico

Este projeto consiste em um verificador ortográfico, um <a href="https://pt.wikipedia.org/wiki/Interface_de_linha_de_comandos">CLI</a> que recebe um texto como entrada e produz o mesmo texto em um novo arquivo de saída indicando palavras possivelmente incorretas. As palavras potencialmente incorretas são indicadas entre colchetes ([...]). Uma palavra é considerada potencialmente incorreta se não for encontrada em um arquivo de dicionário. O verificador ortográfico também sugere correções, indicando uma palavra mais próxima, e pode ser visualizada seguindo o seguinte modelo:

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

<details>
<summary><h2>🧩 ETAPAS DO DESENVOLVIMENTO DO PROJETO</h2></summary>

- [x] Configurações Iniciais
    - [x] Configuração de Arquivo [Makefile](Makefile)
    - [x] Funcionalidade para leitura dos arquivos em formato '.txt', pelo terminal
    - [x] Funcionalidade para gerar o arquivo de saída em formato '.txt' com nome especificado, passado como flag pelo terminal
- [ ] Ortografia
    - [x] Carregar vetor de palavras/árvore de prefixos
    - [x] Filtrar as palavras do arquivo de entrada(Obs: Incluindo aas com acentos)
    - [x] Funcionalidade para percorrer o arquivo de entrada e comparar as palavras filtradas com as do vetor([o dicionário](resource-file/brazilian.txt))
    - [ ] Funcionalidade para sugerir correções utilizando o algoritimo de `Levenshtein` + `Binary search`
- [x] Dicionário
    - [x] Leitura do arquivo (.txt) como dicionário de palavras
    - [x] Criar vetor de palavras com alocação dinânmica ou implementar a árvore de prefixos
    - [x] Busca binária para localização das palavras já armazenadas na memória
</details>

## ⚙ RODANDO O PROGRAMA
Para roda o <a href="https://pt.wikipedia.org/wiki/Interface_de_linha_de_comandos">CLI</a> no terminal linux basta seguir as seguintes instruções

```bash

$ ./ortografia -i input.txt -o output.txt

```
