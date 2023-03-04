# Laboratório 02

Os exercícios de laboratório são testados usando casos de input/output.
A sua solução tem que respeitar o formato de input e output para ser considerada correcta. Para cada exercício é fornecido um exemplo de input/output.

Nota: Todas as linhas no output têm que terminar com um caracter de final de linha.

## Exercício 1

(Maior de Três) Escreva um programa que determine e imprima o maior de três números inteiros dados pelo utilizador.

**Input**
```
1 2 3
```

**Output**
```
1
```


## Exercício 02

(Ordena 2) Escreva um programa que leia dois inteiros `N, M` e imprima o menor deles na primeira linha e o maior na segunda.

**Input**
```
6 2
```

**Output**
```
2
6
```


## Exercício 03

(Divisor) Escreva um programa que leia dois inteiros positivos `N, M` e imprima "yes" se `M` é um divisor de `N`, caso contrário, imprima "no".

**Input**
```
6 2
```

**Output**
```
yes
```


## Exercício 04

(Ordena 3) Escreva um programa que leia três inteiros e imprima-os por ordem na mesma linha.

O menor dos números deve aparecer como primeiro.

**Input**
```
6 1 2
```

**Output**
```
1 2 6
```


## Exercício 05

(Ciclo) Escreva um programa que leia um inteiro positivo `N` e imprima os números `1..N`, um por linha.

**Input**
```
4
```

**Output**
```
1
2
3
4
```


## Exercício 06

(Maior e Menor) Escreva um programa que determine o maior e o menor número de `N` números reais dados pelo utilizador. Considere que `N` é um valor pedido ao utilizador.

O resultado deve ser impresso com o comando `printf("min: %f, max: %f\n", min, max)`.

*Sugestão:` inicialize o maior e o menor com o primeiro valor lido.

**Input**
```
3 1.5 2.7 3
```

**Output**
```
min: 1.500000, max: 3.000000
```


## Exercício 07

(Divisores) Escreva um programa que pede ao utilizador um inteiro positivo `N` e imprima o número de divisores de `N`. Recorde que os números primos têm 2 divisores.


**Input**
```
8
```

**Output**
```
4
```

## Exercício 08

(Média) Escreva um programa que calcule e imprima a média de `N` números reais dados pelo utilizador.  O programa deverá primeiro pedir ao utilizador um inteiro `N`, representando a quantidade de números que vão ser introduzidos. Os números reais devem ser representados pelo tipo float. O resultado deve ser impresso com o comando `printf("%.2f", media);`.


**Input**
```
3 1.5 2.7 3
```

**Output**
```
2.40
```

## Exercício 09

(Conversão) Escreva um programa que pede ao utilizador um valor `N` correspondente a um certo período de tempo em segundos. O programa deverá apresentar no output esse período de tempo no formato `HH:MM:SS`.

*Sugestão:* utilize o operador que calcula o resto da divisão (`%`).

**Input**
```
120
```

**Output**
```
00:02:00
```

## Exercício 10

(Dígitos) Escreva um programa que pede ao utilizador um valor positivo `N`. No output, deverá mostrar o número de dígitos que compõem `N` (na primeira linha), assim como a soma dos dígitos de `N` (na segunda linha). Por exemplo, o número 12345 tem 5 dígitos e a soma desses dígitos é 15.

**Input**
```
123
```

**Output**
```
3
6
```
