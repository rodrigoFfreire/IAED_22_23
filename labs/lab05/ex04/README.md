## Exercício 04 (Tabelas bidimensionais - jogo do galo)

Considere um tabuleiro de jogo do galo de tamanho DxD, D<=MAXDIM, com MAXDIM=100.  Um jogador ganha se prencher 3 em linha, diagonal ou coluna.
Implemente um programa que decida qual dos dois jogadores ganhou.

O input é dado no standard input da seguinte forma: um número inteiro positivo D - a dimensão do tabuleiro, um número inteiro positivo N - o número de entradas preenchidas,
e N triplos H V C, onde H é a coordenada horizontal, V a coordenada vertical, com H e V números inteiros no intervalo 0..D-1, e C o carácter 'x' ou 'o'.

O programa deve imprimir o carácter 'x' se ganhou o jogador 'x', o carácter 'o' se ganhou o jogador 'o', ou o carácter '?' se os jogadores empataram.

*Sugestão:* Guarde o tabuleiro numa matriz `char tab[MAXDIM][MAXDIM]` e implemente a função `int ganha(int dim, char tab[MAXDIM][MAXDIM], char jogador)` que devolve 1 se `jogador` ganha, e que devolve 0 no caso contrário.

**Input**
```
3 5
0 0 x
2 2 o
1 0 x
2 1 o
2 0 x
```

**Output**
```
x
```
