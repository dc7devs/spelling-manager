# orthography-generator
### Spelling manager where it receives input text and provides suggestions for possibly misspelled words

## PROJECT STEPS

- [ ] CONFIGURAÇÕES INICIAIS
    - [x] CONFIGURAR ARQUIVO [MAKEFILE](./Makefile)
    - [ ] FUNCIONALIDADE PARA LEITURA DO ARQUIVOS (.txt) PELO TERMINAL
    - [ ] FUNCIONALIDADE PARA GERAR O ARQUIVO DE SAIDA (.txt) COM NOME ESPECIFICADO PELO TERMINAL 
- [ ] ORTOGRAFIA
    - [ ] FUNÇÃO PARA PERCORRER O ARQUIVO DE ENTRADA E COMPRAR AS PALAVRAS COM AS DO VETOR(O DICIONÁRIO)
    - [ ] FUNÇÃO PARA SUGESTÃO DE CORREÇÃO UTILIZANDO O ALGOTIMO DE LEVENSHTEIN
- [ ] DICIONARIO
    - [ ] LEITURA DO ARQUIVO COMO DICIONÁRIO DE PALAVRAS
    - [ ] CRIAR VETOR DE PALAVRAS COM ALOCAÇÃO DINAMICA OU IMPLEMENTAR A ÁRVORE DE PREFIXOS
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