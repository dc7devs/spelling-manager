# Verificador Ortografico

Este projeto visa implementar um verificador ortográfico, que recebe um texto como entrada e produz o mesmo texto na saída, com as palavras potencialmente incorretas indicadas entre colchetes ([...]). Uma palavra é considerada potencialmente incorreta se não for encontrada em um arquivo de dicionário.

Atividade
Construa um programa para verificar a ortografia das palavras de um texto lido da entrada padrão (stdin). A saída padrão (stdout) deve reproduzir fielmente o texto de entrada, mas colocando as palavras que não estão no dicionário entre colchetes. O dicionário está disponível no arquivo /usr/share/dict/brazilian (em distribuições Linux populares).

Consideram-se palavras como sequências contíguas de letras (A-Z, a-z) com ou sem acentos; os demais caracteres (números, espaços e outros símbolos) não fazem parte de palavras.

Por exemplo, para esta entrada:
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
Para que o [pocessador] possa interromper a execução de uma tarefa
e retornar a ela mais tarde, sem corromper seu estado interno, 
é necessário definir operações para salvar e [restaurrar] o
contexto da tarefa.

O ato de salvar os valores do contexto atual em seu [TCB] e
possivelmente restaurar o contexto de outra tarefa, previamente
salvo em outro [TCB], é denominado "troca de contexto".
```

## ETAPAS DO PROJETO

- [x] CONFIGURAÇÕES INICIAIS
    - [x] CONFIGURAÇÃO DE ARQUIVO [MAKEFILE](./Makefile)
    - [x] FUNCIONALIDADE PARA LEITURA DOS ARQUIVOS (.txt) PELO TERMINAL
    - [x] FUNCIONALIDADE PARA GERAR O ARQUIVO DE SAIDA (.txt) COM NOME ESPECIFICADO, PASSADO COMO ARGUMENTO PELO TERMINAL 
- [ ] ORTOGRAFIA
    - [x] FILTRAR AS PALAVRAS DO ARQUIVO DE ENTRADA(OBS: INCLUINDO AS COM ACENTOS)
    - [x] FUNÇÃO PARA PERCORRER O ARQUIVO DE ENTRADA E COMPARAR AS PALAVRAS COM AS DO VETOR([O DICIONÁRIO](./resource-file/dictionary.txt))
    - [ ] FUNÇÃO PARA SUGESTÃO DE CORREÇÃO UTILIZANDO O ALGORITIMO DE LEVENSHTEIN
- [x] DICIONÁRIO
    - [x] LEITURA DO ARQUIVO (.txt) COMO DICIONÁRIO DE PALAVRAS
    - [x] CRIAR VETOR DE PALAVRAS COM ALOCAÇÃO DINÂMICA OU IMPLEMENTAR A ÁRVORE DE PREFIXOS
    - [x] BUSCA BINÁRIA PARA LOCALIZAÇÃO DAS PALAVRAS JA ARMAZENADAS NA MEMÓRIA

## SUGESTÃO DE ALGORITIMO DE IMPLEMENTAÇÃO

```
ler o dicionário em um vetor de palavras
c = ler caractere da entrada
enquanto não for o fim da entrada faça
    // avançar até encontrar uma letra ou o fim da entrada
    enquanto (c não for uma letra) e (não for o fim da entrada) faça
        escrever c em stdout
        c = ler caractere da entrada
    fim enquanto
    // encontrou uma letra, ler a palavra inteira
    palavra = ""
    enquanto (c for uma letra) e (não for o fim da entrada) faça
        palavra = palavra + c
        c = ler caractere da entrada
    fim enquanto
    // tratar a palavra encontrada
    se palavra <> "" então
        se minúscula(palavra) está no dicionário então
            escrever palavra na saída
        senão
            escrever "[", palavra, "]" na saída
        fim se
    fim se
fim enquanto
```
