### Exercício 5

Implemente uma calculadora para Notação polaca (também denominada notação de prefixo) inversa
([https://en.wikipedia.org/wiki/Reverse_Polish_notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)),
onde  o operador segue os operandos. Por exemplo, `(3+4)` é `3 4 +`; `(3+4) * 5` é `3 4 + 5 *`.
A expressão é dada no standard input como uma sequência de palavras. O programa deverá imprimir o resultado numa linha separada.


**Dica:** Os resultados intermédios podem ser guardados numa pilha.

**Dica:** A função `atoi` pode ser usada para converter uma string no `int`.


**Input**
```
7 2 + 1 +
```

**Output**
```
10
```
