## Exercício 6 (facultativo)

Implemente em C um programa que leia uma linha do standard input e verifica se
os parênteses estão bem formatados, considerando os pares de parênteses `()`,
`[]`, `{}`.

Por exemplo, a string `"{[a]b(c)}()[]"` é uma string bem formatada, enquanto a
string `"(()"` não o é.  Se o input for bem formatado, o programa deverá
imprimir `"yes"`, e no caso contrário deverá imprimir `"no"`.

*Dica:* Podem aproveitar o `ex05` para resolver este exercício. Quando
encontrarem um parêntesis a abrir, coloque-o no stack; quando encontrar um
parêntesis a fechar verifica se o topo é um "match" e retira-o da pilha.  No
final a stack deverá ficar vazio.

*Dica:* Não é necessário guardar o input; é suficiente usar o stack.

**Input**
```
"{[a]b(c)}()[]"
```

**Output**
```
yes
```

**Input**
```
"(()"
```

**Output**
```
no
```
