CC=gcc
CFLAGS=-Wall -Wextra -Werror -ansi -pedantic

all:
	$(CC) $(CFLAGS) *.c -o proj2

sanitize:
	$(CC) -fsanitize=address $(CFLAGS) *.c -o proj2


clean:
	rm -f *.o proj2 proj2.exe

