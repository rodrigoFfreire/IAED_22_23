## Exercício 1 (Utilização do depurador ou debugger)

1 - Entre na directoria `lab06/fact/` no seu repositório ou faça download do zip em anexo ao guia de laboratório (Fenix).

2 - Compile o programa factorial com geração de informação para o debugger (`-g`):
```
$ gcc -ansi -pedantic -Wall -g -o iter main.c iter.c
```

3 - Execute o programa iter dentro do debugger gdb e visualise o código fonte:
```
$ gdb iter
gdb> list
```

4 - Recorrendo ao debugger, insira um breakpoint no início da função main; imprima o valor da variável `n` e verifique que ainda não foi iniciada; execute a linha que contém essa instrução e verifique que a variável já contém o valor 5; modifique a variável para que seja calculado o factorial de 7; continue a execução do programa, agora que o valor da variável foi modificada, e verifique que foi calculado o factorial de 7:

```
gdb> break main
gdb> run
gdb> print n
gdb> next
gdb> print n
gdb> set n=7
gdb> continue
```

5 - Verifique os valores parciais do cálculo do factorial, colocando um breakpoint na instrução do ciclo for, imprimindo o valor da variável fact em cada iteração: 

```
gdb> list factorial
gdb> break 9
gdb> run
gdb> display fact
gdb> continue
gdb> continue
...
```


## Exercício 2 (Análise Assimptótica)

Considere a seguinte função de procura de um elemento num vector ordenado.
A função recebe um vector **a**, o número de elementos *n* e o valor *elem*
que se pretende encontrar no vector.

```
int search(int a[], int n, int elem) {
  int left = 0, right = n-1;
  int med;

  while (left <= right) {
    int med = (left + right) / 2;
    if (a[med] == elem)
      return med;
    else if (a[med] < elem)
      left = med+1;
    else
      right = med-1;
  }
  return -1;
}
```

Indique a complexidade assimptótica da função search numa análise de pior caso
e numa análise de melhor caso.

## Exercício 3 (Análise Assimptótica)

Indique a complexidade assimptótica da função abaixo numa análise de pior caso.
Indique ainda se o limite assimptótico é apertado ou se é apenas um limite superior.

```
int funcao (int a[], int n) {
  int i, sum = 0;

  for (i = 0; i < n/2; i++) 
    sum += a[i] + a[n-i-1];
  return sum;
}
```


## Exercício 4 (Análise Assimptótica)

Considere a função abaixo que recebe dois vectores (**a** e **b**) onde
*n* e *m* denotam o número de elementos dos vectores **a** e **b**, respectivamente.

```
int funcao (int a[], int n, int b[], int m) {
  int i = n-1, count = 0;

  while (i > 0) {
    for (j = 0; j < m; j++) {
      if (a[i] == b[j])
        count++;
    }
    i = i/2;
  }
  return count;
}
```

Indique a complexidade assimptótica da função em função de *n* e *m* numa análise de pior caso.


## Exercício 5 (Análise Assimptótica)

Considere a função abaixo que recebe dois inteiros *n* e *m*.

```
int funcao (int n, int m) {
  int i = 0, count = 0;

  while (i < n*n) {
    if (i % m == 0)
      count++;
    i++;
  }
  return count;
}
```

Indique a complexidade assimptótica da função numa análise de pior caso.


## Exercício 6 (Análise Assimptótica)

Considere a função abaixo que recebe dois inteiros *n* e *m*.

```
int funcao (int n, int m) {
  int i = 0, count = 0;

  if (n % m == 0)
    return 0;

  while (i < n) {
    if (i % m == 0)
      count++;
    i = i + 2;
  }
  return count;
}
```

Indique a complexidade assimptótica da função numa análise de pior caso e numa análise de melhor caso.
É possível estabelecer uma complexidade assimptótica apertada para esta função? Justifique.

