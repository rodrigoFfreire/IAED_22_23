## Exercício 1 (Utilização do valgrind)

1 - Faça `git pull` do seu repositório dos laboratórios ou faça download do
zip anexo ao guia de laboratório (Fenix).

2 - Compile o programa ex1.c com geração de informação para o debugger (`-g`):
```
$ gcc -ansi -pedantic -Wall -g -o ex1 ex1.c
```

3 - Execute o programa ex1 com o valgrind e verifique o output produzido:
```
$ valgrind ./ex1
```

4 - Corrija o programa ex1 de forma a que o valgrind não produza erros:

## Exercício 2 (Utilização do valgrind)

1 - Compile o programa ex2.c com geração de informação para o debugger (`-g`):
```
$ gcc -ansi -pedantic -Wall -g -o ex2 ex2.c
```

2 - Execute o programa ex2 com o valgrind e verifique o output produzido:
```
$ valgrind ./ex2 < ex2.in
```

3 - Corrija o programa ex2 de forma a que o valgrind não produza erros e
o programa leia correctamente 10 números e faça output da soma dos números
lidos.


## Exercício 3 (Utilização do valgrind)

1 - Compile o programa ex3.c com geração de informação para o debugger (`-g`):
```
$ gcc -ansi -pedantic -Wall -g -o ex3 ex3.c
```

2 - Execute o programa ex3 com o valgrind e verifique o output produzido:
```
$ valgrind ./ex3 < ex3.in
```

3 - Corrija o programa ex3 de forma a que o valgrind não produza erros e
o programa leia correctamente strings até 9 caracteres e faça output da cópia da string lida.
