# Copyright (C) 2021, Pedro Reis dos Santos
.SUFFIXES: .in .out .diff
MAKEFLAGS += --no-print-directory # No entering and leaving messages
SHELL := /bin/bash # Execute command with bash
OK="\x1b[1;32mtest $< PASSED\x1b[0m"
KO="\x1b[1;31mtest $< FAILED\x1b[0m"
EXE=../projeto1/proj1
LOG=tests.log

all:: clean # run regression tests
	@rm -f $(LOG)
	@for i in `ls t*.in | sed -e "s/in/diff/"`; do $(MAKE) $(MFLAGS) $$i; done
	@echo "`wc -l < $(LOG)` tests passed"

.in.diff:
	@-$(EXE) < $< | diff - $*.out > $@
	@if [ `wc -l < $@` -eq 0 ]; then echo -e $(OK); echo $* >> $(LOG); else echo -e $(KO); fi;

clean::
	@rm -f *.diff $(LOG)

