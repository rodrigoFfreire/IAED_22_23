## Exercício 1

Implemente um programa em C que leia uma palavra do standard input e que
imprima todos os sufixos dessa palavra.  O programa deverá imprimir um sufixo
por linha começando do mais comprido para o mais curto.

Poderá supor que a palavra nunca terá mais de 1000 caracteres.

*Dica:* Sugere-se utilização de aritmética de ponteiros, para poder avançar com
um ponteiro `p` representando os diferentes sufixos e passar esse ponteiro `p`
como parâmetro para a função `printf`.


**Input**
```
abc
```

**Output**
```
abc
bc
c
```
