## Algoritmos de Ordenação Eficiente

### Exercício 1

Diga quais dos seguintes vectores corresponde a um amontoado (heap)?

- `<40, 15, 20, 17, 14, 11, 18>`
- `<40, 20, 15, 17, 14, 18, 11>`
- `<40, 25, 28, 23, 21, 24, 26>`
- `<50, 40, 19, 30, 31, 20, 18>`
- `<60, 30, 50, 10, 25, 20, 40>`

### Exercício 2

A primeira operação do algoritmo heapsort é transformar o vector num amontoado. Considere que o vector de entrada do algoritmo é `<20, 11, 16, 9, 12, 14, 17, 19, 13, 15>`.

- Indique o conteúdo do vector após o passo de transformação num amontoado.
- Indique o conteúdo do vector após os dois maiores elementos terem sido ordenados (colocados na sua posição final), durante a operação de ordenação (heapsort).

### Exercício 3

Qual o conteúdo do seguinte vector `<25, 19, 23, 15, 18, 16, 21, 12>` depois de os dois primeiros elementos (i.e. os dois maiores) terem sido ordenados, utilizando o algoritmo de ordenação heapsort?

### Exercício 4

- (Radix LSD) Considere a aplicação do algoritmo radix sort LSD, em que cada passo os elementos são ordenados considerando um dígito, ao seguinte vector:

`<48372, 62309, 83861, 91874, 18913, 33829, 47812, 95954, 52377, 22394, 56108, 60991>`

Qual é o terceiro número da sequência, após o algoritmo ter considerado três digitos?

### Exercício 5

- (Radix MSD) Considere o seguinte vector de números inteiros sem sinal de 6 bits:

`<32, 2, 34, 9, 6, 1, 20, 18, 10>`

Qual o conteúdo do vector após os primeiros dois passos do algoritmo de ordenação radix sort MSD, em que em cada passo os elementos são ordenados considerando 2 bits?

Nota: considere que o algoritmo é baseado numa versão estável do algoritmo counting sort. O algoritmo deve apenas processar os 6 bits menos significativos de cada número, independentemente dos números poderem ser guardados em palavras com maior número de bits.


## Filas de Prioridade

### Exercício 6

Considere uma fila de prioridades que está inicialmente vazia.
Considere ainda que a fila de prioridades é implementada por um
vector `v[DIM]` (onde DIM = 10) organizado com as propriedades
dos amontoados.

Suponha que adiciona sequencialmente um conjunto de items à fila
cujas chaves são as seguintes:
`< 3, 10, 4, 5, 8, 12, 14, 9 >`

Indique o conteúdo do vector `v[DIM]` após cada passo de inserção
de um elemento.


### Exercício 7

Considere a fila de prioridade inicalmente vazia. Indique o conteúdo da fila
após inserir ordenadamente todos os elementos do vetor `v[DIM]` do exercício
anterior e remover dois elementos da fila resultante da inserção. 

Nota: Lembre-se que numa fila de prioridades, a operação de remoção
retira sempre o elemento de maior prioridade.
