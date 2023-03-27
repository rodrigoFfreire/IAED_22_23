## Exercício 2

Implemente um programa em C que leia uma sequência de palavras do standard
input e imprima as mesmas na ordem inversa.  O programa deverá imprimir uma
palavra por linha começando pela última palavra.

Poderá supor que a palavra nunca terá mais de 1000 caracteres, que não aparacem
mais que 10000 palavras e que cada palavra pode ser lida com `scanf("%s", s)`.

*Dica:* Guarde as palavras como um vector de strings.  Primeiro leia a palavra
dentro de uma string com um tamanho fixo e só depois aloca a string com o
tamanho adequado.

*Dica:* A chamada `scanf("%s", buffer)` devolve `1` se e só se a palavra foi lida
com sucesso, i.e. a leitura pode terminar se o valor devolvido não estiver `1`.

**Input**
```
abc foo bar
```

**Output**
```
bar
foo
abc
```
