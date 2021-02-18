.DEFAULT_GOAL := all

$(shell mkdir -p bin)
NUMS :=  $(shell seq -s " bin/stack" 12 15)
NUMS := bin/stack$(NUMS)



all: $(NUMS)
bin/stack%: stack%/main.cpp stack%/stack.cpp stack%/*.h Makefile
	g++ $< $(word 2, $^) -o $@ -Wall
