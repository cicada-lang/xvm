cc = gcc
ldflags =
cflags = -g -Wall -Wwrite-strings -Wextra -Werror -O2 -std=c99 -pedantic

src = $(shell find src -name '*.c')
lib = $(filter-out lib/cli/%,$(patsubst src/%,lib/%,$(patsubst %.c,%.o,$(src))))
bin = bin/x bin/x-test

.PHONY: all
all: $(bin)

.PHONY: run
run: bin/x
	./bin/x

.PHONY: test
test: bin/x-test
	time -v ./bin/x-test

bin/x: $(lib) lib/cli/x.o
	mkdir -p $(dir $@); $(cc) $(ldflags) $^ -o $@

bin/x-test: ${lib} lib/cli/x-test.o
	mkdir -p $(dir $@); $(cc) $(ldflags) $^ -o $@

lib/%.o: src/%.c
	mkdir -p $(dir $@); $(cc) -c $(cflags) $< -o $@

.PHONY: clean
clean:
	rm -f *.o
	rm -rf lib bin
