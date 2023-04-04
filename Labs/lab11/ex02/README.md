### Exercício 2

Implemente em C um programa que leia uma linha de caracteres e imprime `yes` se a linha for um palíndromo e imprima `no` no caso contrário.

*Dica:* Reutilize a lista ligada do `ex01`. Adicionalmente implemente as funções:

```
    int is_eq(node *h1, node *h2);   /* compara duas listas */
    node * rev(node * head);         /* devolve uma nova lista que corresponda a lista dada invertida */
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
