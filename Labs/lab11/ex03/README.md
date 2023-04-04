### Exercício 3

Implemente em C um programa que leia uma sequência de strings sem espaços terminada por a string `"x"` e imprima a mesma sequência, mas invertida. O programa deve ser implementado usando listas ligadas. Podem assumir que cada string tem no máximo 1000 caracteres. Entretanto, deve-se só alocar memória suficiente para as strings dadas.

A lista será representada pela seguinte estrutura:

```
    typedef struct stru_node {
        struct stru_node *next;
        char *v;
    } node;
```

e deverá ser manipulada pelas seguintes funções definidas no exercício 1:

```
    /* remove the first element of the list and return the new head */
    node * pop(node *head);
    /* add string e as the first element of the list and return the new head */
    node * push(node *head, const char *e);
    /* frees all memory associated with the list and returns NULL */
    node * destroy(node *head);
    /* print the elements of the integers in the list, one per line */
    void print(node *head);
```

**Nota:** Não se esquecam, no __pop__, de libertar as strings alocadas no __push__.


**Input**
```
bye hello x
```

**Output**
```
hello
bye
```
