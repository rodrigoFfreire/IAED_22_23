# Exercícios

Este laboratório assume que tem acesso a um ambiente de trabalho Linux com o seguinte software instalado:

- compilador de C: [gcc](https://en.wikipedia.org/wiki/GNU_Compiler_Collection)

- editor: [Visual Studio Code](https://code.visualstudio.com/)

- sistema de controlo de versões: [git](https://en.wikipedia.org/wiki/Git)

***

1. Gere a chave SSH
    -  Siga os passos indicados no [exemplo de gerar chave ssh](https://gitlab.rnl.tecnico.ulisboa.pt/iaed-23/iaed-23/-/tree/master/docs/generate_key.pdf)

2. Introduza a chave pública SSH no GitLab
    -  Siga os passos indicados no [exemplo de definir chave ssh no GitLab da RNL](https://gitlab.rnl.tecnico.ulisboa.pt/iaed-23/iaed-23/-/tree/master/docs/define_key.pdf)

3. Clone o repositório dos laboratórios
    -  Siga os passos indicados no [exemplo de clonar o repositório do GitLab](https://gitlab.rnl.tecnico.ulisboa.pt/iaed-23/iaed-23/-/tree/master/docs/clone_repo.pdf)


4. O primeiro programa em C

    Abra o ficheiro `ex01.c`. Copie o seguinte código, e guarde-o:

```
#include <stdio.h>

int main()
{
  printf("Hello World!\n");
  return 0;
}
```

Abra um terminal e experimente compilar e correr, escrevendo no terminal (no mesmo ponto da árvore de directórios em que está o ficheiro `ex01.c`):
```
$ gcc -ansi -pedantic -Wall ex01.c
```
(A utilização das opções `" -ansi -pedantic -Wall"` é sempre recomendada no âmbito desta cadeira.)

Foi criado um ficheiro executável `a.out` com o programa que escreveu.

Encontre o ficheiro criado listando o directório corrente com o comando:
```
$ ls -l
```
Pode agora executar o programa criado:
```
$ ./a.out
```
O executável pode ser nomeado durante a compilação com a opção `-o`:
```
$ gcc -ansi -pedantic -Wall -o ex01 ex01.c
$ ./ex01
```

5. Actualize o repositório no GitLab e verifique o resultado da avaliação
    -  Siga as instruções indicadas no [exemplo de actualizar o repositório](https://gitlab.rnl.tecnico.ulisboa.pt/iaed-23/iaed-23/-/tree/master/docs/update_repo.pdf)

6. Introduza vários tipos de erros e verifique o resultado da avaliação
    - Repita os passos do ponto anterior para actualizar o repositório e ver a sua submissão avaliada
