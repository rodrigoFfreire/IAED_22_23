## PARTE I - Manipulação de vectores/tabelas

*Nota prévia:* Quando trabalhamos com vectores em C, é comum fazer erros que levam a [Segmentation Faults](https://en.wikipedia.org/wiki/Segmentation_fault). Se obtiver tal erro nos exercícios abaixo provavelmente terá uma gralha nos limites dos seus ciclos, ou seja, deverá estar a tentar aceder a um elemento de um vector que não existe.
Podem usar o programa `valgrind` para tentar identificar o problema.

---

## Exercício 01

(Gráfico horizontal) Escreva um programa que peça ao utilizador um número inteiro positivo `n < VECMAX`, onde `VECMAX=100`. Depois, leia `n` números inteiros positivos. No final o programa deverá escrever uma representação gráfica dos valores lidos como o que se segue. O gráfico apresentado é o exemplo para `n = 3` e valores `1 3 4`.

**Input**
```
3
1 3 4
```

**Output**
```
*
***
****
```


# Evaluation

2023-03-04T15:29:28

## Test 1: [+ Accepted+].
## Test 2: [+ Accepted+].
## Test 3: [+ Accepted+].


## Number of passed tests: 3/3


Your code will not be reevaluated if you submit before 2023-03-04 15:30:28 @ Lisbon, Portugal. You need to wait 1 minute(s).

