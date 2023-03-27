Considere que os algoritmos de ordenação ordenam sempre de forma não decrescente.

# Algoritmos de Ordenação Elementares

## Exercício 1 (BubbleSort)

Considere a aplicação do algoritmo *bubblesort* ao vector **a**:

**a** = { 20, 11, 16, 8, 21, 12, 10, 14, 17, 6 }

Supondo que em cada iteração o algoritmo percorre o vector da esquerda para a direita, qual o
conteúdo do vector **a** após as duas primeiras iterações?

## Exercício 2 (SelectionSort)

Considere a aplicação do algoritmo *selectionsort* ao vector **a**:

**a** = { 20, 11, 16, 8, 21, 12, 10, 14, 17, 6 }

Supondo que em cada iteração o algoritmo identifica o menor elemento e
o coloca na posição mais à esquerda, qual o conteúdo do vector **a**
após as três primeiras iterações?

## Exercício 3 (SelectionSort)

Resolva o exercício anterior, mas considerando uma variação do
algoritmo SelectionSort. Suponha que em cada iteração, o algoritmo
identifica o maior elemento e o coloca na posição mais à direita.
Qual o conteúdo do vector **a** após as três primeiras iterações?

## Exercício 4 (InsertionSort)

Considere a aplicação do algoritmo *insertionsort* ao vector **a**:

**a** = { 20, 11, 16, 8, 21, 12, 10, 14, 17, 6 }

Supondo que o algoritmo vai inserindo os elementos à esquerda,
qual o conteúdo do vector **a** após as três primeiras iterações?

## Exercício 5 (BubbleSort - Melhor Caso)

A complexidade assimptótica de pior caso do algoritmo *bubblesort*,
é *O(n²)*. E no melhor caso? Ilustre com um exemplo.


# Algoritmos de Ordenação Eficiente

### Exercício 6

Considere a implementação clássica da função `int partition (Item v[], int l, int r)` usada no algoritmo quicksort tal como apresentada nas aulas teóricas. Esta função recebe o vector `v` e as posições `left` e `right` que definem, respectivamente, os índices limite esquerdo e direito do vector a considerar na função. Suponha que o procedimento partition é invocado com os seguintes argumentos: `v = <13, 6, 5, 14, 12, 4, 16, 18, 7, 9, 10>`, `left = 0`, `right = 10`.  Considerando a posição `a[r]` como pivot, indique qual o conteúdo do vector `v` após a execução da função `partition`.


### Exercício 7

Considere o exercício anterior, mas onde os argumentos da função `partition` são os seguintes: `v =<20, 11, 16, 9, 12, 14, 17, 19, 13, 15>`, `left = 0` , `right = 9`. Qual o conteúdo do vector `v` após a execução do procedimento `partition`?

