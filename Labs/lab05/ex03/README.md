## Exercício 03 (Portfólio financeiro - estruturas)

Considere uma estrutura representando um título financeiro (`Stock`) composta por um nome (máximo 10 caracteres sem espaços), valor (float), e percentagem de rendimento anual (float). Implemente um programa que leia uma sequencia de títulos e imprima o título com o maior rendimento.

O input é dado no standard input da seguinte forma: um número inteiro positivo N, e N triplos Nome Valor Taxa. O título deve ser impresso numa única linha em que os atributos do título são separados por espaços e os números do tipo float são impressos usando `%.2f`. Pode assumir que o portfólio não tem mais do que 1000 títulos, e que não é vazio.

**Input**
```
2
IBM 10 1
Oracle 10 2
```

**Output**
```
Oracle 10.00 2.00
```
