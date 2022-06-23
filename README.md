# orthography-generator
### Este projeto visa implementar um verificadr ortográfico simples que verifica se as palavras de um texto de entrada estão em um dicionário predefinido e sugere correções para as palavra não encontradas.

## PROJECT STEPS

- [x] CONFIGURAÇÕES INICIAIS
    - [x] CONFIGURAÇÃO DE ARQUIVO [MAKEFILE](./Makefile)
    - [x] FUNCIONALIDADE PARA LEITURA DOS ARQUIVOS (.txt) PELO TERMINAL
    - [x] FUNCIONALIDADE PARA GERAR O ARQUIVO DE SAIDA (.txt) COM NOME ESPECIFICADO, PASSADO COMO ARGUMENTO PELO TERMINAL 
- [ ] ORTOGRAFIA
    - [x] FILTRAR AS PALAVRAS DO ARQUIVO DE ENTRADA(OBS: INCLUINDO AS COM ACENTOS)
    - [ ] FUNÇÃO PARA PERCORRER O ARQUIVO DE ENTRADA E COMPARAR AS PALAVRAS COM AS DO VETOR([O DICIONÁRIO](./resource-file/dictionary.txt))
    - [ ] FUNÇÃO PARA SUGESTÃO DE CORREÇÃO UTILIZANDO O ALGORITIMO DE LEVENSHTEIN
- [ ] DICIONÁRIO
    - [ ] LEITURA DO ARQUIVO (.txt) COMO DICIONÁRIO DE PALAVRAS
    - [ ] CRIAR VETOR DE PALAVRAS COM ALOCAÇÃO DINÂMICA OU IMPLEMENTAR A ÁRVORE DE PREFIXOS
    - [ ] BUSCA BINÁRIA PARA LOCALIZAÇÃO DAS PALAVRAS JA ARMAZENADAS NA MEMÓRIA

## SUGGESTION CODE

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
