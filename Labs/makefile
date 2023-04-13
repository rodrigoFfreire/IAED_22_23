SHELL := /bin/bash
CC= gcc
CFLAGS= -Wall -Wextra -Werror -ansi -pedantic
COMPILED="\e[1;32m $< Successfully compiled!\e[0m"
AVAILABLE="\e[1;36mAvailable Source Files:\e[0m"

all: $(wildcard */*/*.c) $(wildcard */*.c)
	@echo -e $(AVAILABLE)
	@for i in $^; do echo $${i::-2}; done

%: %.c
	$(CC) $(CFLAGS) $< -o $@.o
	@echo -e $(COMPILED)

clean:
	rm -rf */ex*.o */*/ex*.o
