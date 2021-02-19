.DEFAULT_GOAL := all

$(shell mkdir -p bin)
NUMS := $(shell ls -1v -d stack* | sed 's/^/bin\//g')


all: bin/stack12 $(NUMS)
bin/stack%: stack%/main.cpp stack%/stack.cpp stack%/*.h
	g++ $< $(word 2, $^) -o $@ -Wall
