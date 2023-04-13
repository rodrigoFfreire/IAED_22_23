### Exercício 1

Implemente em C um programa que leia uma sequência de inteiros terminada por `0` e imprima a mesma sequência, mas invertida. 
O programa deve ser implementado usando listas ligadas. A lista será representada pela seguinte estrutura:

```
    typedef struct stru_node {
        struct stru_node *next;
        int v;
    } node;
```

e deverá ser manipulada pelas seguintes funções:

```
    /* remove the first element of the list and return the new head */
    node * pop(node * head);
    /* add integer e as the first element of the list and return the new head */
    node * push(node * head, int e);
    /* frees all memory associated with the list and returns NULL */
    node * destroy(node * head);
    /* print the elements of the integers in the list, one per line */
    void print(node * head);
```

**Input**
```
1 2 0
```

**Output**
```
2
1
```


# Evaluation

2023-04-09T23:37:00

## Test 1: [+ Accepted+].
## Test 2: [+ Accepted+].
## Test 3: [+ Accepted+].


## Number of passed tests: 3/3


Your code will not be reevaluated if you submit before 2023-04-09 23:38:00 @ Lisbon, Portugal. You need to wait 1 minute(s).

