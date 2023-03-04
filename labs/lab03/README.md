# Laboratório 03

Os exercícios de laboratório são testados usando casos de input/output.
A sua solução tem que respeitar o formato de input e output para ser considerada correcta. Para cada exercício é fornecido um exemplo de input/output.

Nota: Todas as linhas no output têm que terminar com um caracter de final de linha.

## Exercício 01

(Quadrado de Números) Escreva um programa que desenhe um quadrado de números como o que se segue utilizando a função `void quadrado(int N);`. O valor de `N`, dado pelo utilizador, deverá ser obrigatoriamente maior ou igual 2. O tab (carácter `'\t'`) deve ser usado como o separador. O quadrado apresentado é o exemplo para `N = 5`.

**Input**
```
5
```

**Output**
```
1       2       3       4      5
2       3       4       5      6
3       4       5       6      7
4       5       6       7      8
5       6       7       8      9
```

*Dica:* `echo 5 | ./ex01` pode ser usado para rapidamente testar o programa.

## Exercício 02

(Pirâmide de Números) Escreva um programa que desenhe uma pirâmide de números utilizando a função `void piramide(int N);`. O valor de `N`, dado pelo utilizador, deverá ser obrigatoriamente superior ou igual 2. O espaço (carácter `' '`) deve ser usado como o separador.
A pirâmide apresentada é o exemplo para `N = 5`.

**Input**
```
5
```

**Output**
```
        1
      1 2 1
    1 2 3 2 1
  1 2 3 4 3 2 1
1 2 3 4 5 4 3 2 1
```

## Exercício 03

(Cruz diagonal) Escreva um programa que desenhe uma cruz nas diagonais utilizando a função `void cruz(int N);`.  O asterisco (carácter `'*'`) deve ser usado para desenhar a cruz; hífen (carácter `'-'`) deve ser usado como o separador. As cruzes apresentadas são os exemplos para `N = 3` e `N=8`.

**Input**
```
3
```

**Output**
```
* - *
- * -
* - *
```

**Input**
```
8
```

**Output**
```
* - - - - - - *
- * - - - - * -
- - * - - * - -
- - - * * - - -
- - - * * - - -
- - * - - * - -
- * - - - - * -
* - - - - - - *
```

## Exercício 04

(Números) Escreva um programa que leia uma sequência de números separados por espaços e novas linhas,
e imprima a mesma sequência, mas os números no output não deverão conter 0 no início, por exemplo, `007` deverá imprimir `7`.

A excepção é o número 0, que se deverá imprimir como 0.
A sequência no input termina com `EOF`.

*Atenção:* Os valores dos números poderão ser superiores ao valor máximo do tipo `int` ou qualquer tipo primitivo em C.

*Dica:* a função `int getchar()` pode ser usada para ler um carácter.

**Input**
```
01 3 02 000 027770
```

**Output**
```
1 3 2 0 27770
```


## Exercício 05

(Mensagens) Escreva um programa que leia uma sequência de mensagens e imprima-as, uma por linha.
Cada mensagem é delimitada pelas aspas (carácter `"`). A mensagem pode conter uma "escape sequence" - o carácter perde significado especial se for precedido pelo caracter `\` (backslash). Por exemplo, o input `"a\"foo\\bar\""` corresponde à mensagem `a"foo\bar"`. Assim o backslash permite incluir aspas na mensagem tal como a própria backslash.

*Dica:* utilize o conceito de estado como fizemos no contador de palavras na aula teórica.

**Input**
```
"foo" "bar" "baz zap"
```

**Output**
```
foo
bar
baz zap
```


## Exercício 06

(Divisível) Escreva um programa que leia um número inteiro positivo a partir do input (como uma sequência de caráteres até 100 chars) e que decide se o número lido é divisível por 9.

Se o número for divisível por 9, o programa deverá imprimir a mensagem `yes`, e deverá imprimir `no` no caso contrário.

*Atenção:* Os valores dos números podem ser superiores ao valor máximo do tipo `int` ou de qualquer tipo primitivo em C.

*Dica:* Um número é divisível por 9 se e só se a soma dos seus algarismos for divisível por 9. Por exemplo, a soma dos algarismos do número 729 é 18, pelo que é divisível por 9. O facto pode ser observado pela equação seguinte: 7 x 100 + 2 x 10 + 9 = (7 x 99 + __7__) + (2 x 9 + __2__) + 9.

**Input**
```
16
```

**Output**
```
no
```

**Input**
```
729
```

**Output**
```
yes
```


## Exercício 07

(Calculadora) Escreva um programa que receba uma sequência de números e operadores (`+`, `-`) representando uma expressão aritmética e retorna o resultado dessa expressão aritmética.

A sequência no input termina com `\n`.

Pode supor que cada dois números são sempre separados por `espaço, operador, espaço`, ie, `' op '`, para qualquer um dos 2 operadores acima.

_Exemplo_: No input `70 + 22 - 3` deverá retornar `89`.

_Dica:_ Deverá começar por converter uma sequência de algarismos (carácteres) para um número inteiro.

**Input**
```
9 - 3 + 2 - 5
```

**Output**
```
3
```
