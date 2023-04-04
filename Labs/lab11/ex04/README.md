### Exercício 4

Implemente em C um programa que leia uma linha de caracteres e guarda os caracteres numa lista __duplamente__ ligada.
Imprima `yes` se a linha for um palíndromo e imprima `no` no caso contrário.

A lista será representada pelas estrutura seguintes:

```
    typedef struct str_node  {
        struct str_node *next, *previous;
        char c;
    } node;

    typedef struct  {
        struct str_node *head, *last;
    } list;
```

e deverá ser manipulada pelas seguintes funções:

```
    list* mk_list();                 /* cria nova lista vazia */
    void  free_list(list *l);        /* liberta toda a memoria associada a lista */
    void  add_last(list *l, char c); /* adiciona o char c como o ultimo elemento da lista */
    int   is_paly(const list *ls);   /* calcula se a dada lista e um palindromo */
```

**Input**
```
abba
```

**Output**
```
yes
```

**Input**
```
abbx
```

**Output**
```
no
```

