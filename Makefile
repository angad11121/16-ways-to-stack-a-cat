.DEFAULT_GOAL := all

NUMS :=  $(shell seq -s " bin/stack" 0 3)
NUMS := bin/stack$(NUMS)

all: $(NUMS)

bin/stack%: stack%/main.cpp stack%/stack.cpp stack%/stack.h
	g++ $< $(word 2, $^) -o $@
