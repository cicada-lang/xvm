cc = gcc
ldflags =
cflags = -g -Wall -Wwrite-strings -Wextra -Werror -O2 -std=c11 -pedantic

src = $(shell find src -name '*.c')
lib = $(patsubst src/%,lib/%,$(patsubst %.c,%.o,$(src)))
bin = bin/x

.PHONY: all
all: bin/x

.PHONY: run
run: bin/x
	./bin/x

.PHONY: test
test: bin/x
	./bin/x self-test && ./bin/x run examples/*

bin/x: $(lib) lib/x.o
	mkdir -p $(dir $@); $(cc) $(ldflags) $^ -o $@

lib/%.o: src/%.c
	mkdir -p $(dir $@); $(cc) -c $(cflags) $< -o $@

.PHONY: clean
clean:
	rm -f *.o
	rm -rf lib bin
