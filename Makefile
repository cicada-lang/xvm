cc = gcc
ldflags =
cflags = -g -Wall -Wwrite-strings -Wextra -Werror -O2 -std=c99 -pedantic

src = ${shell find src -name '*.c'}
lib = ${patsubst src/%,lib/%,${patsubst %.c,%.o,${src}}}

.PHONY: all
all: ${bin}

.PHONY: run
run: bin/x
	./bin/x

.PHONY: test
test: bin/x-test
	time -v ./bin/x-test

bin/x: ${lib} x.o
	mkdir -p ${dir $@}; ${cc} ${ldflags} $^ -o $@

bin/x-test: ${lib} x-test.o
	mkdir -p ${dir $@}; ${cc} ${ldflags} $^ -o $@

%.o: %.c
	$(cc) -c $(cflags) $< -o $@

lib/%.o: src/%.c
	mkdir -p ${dir $@}; $(cc) -c $(cflags) $< -o $@

.PHONY: clean
clean:
	rm -f *.o
	rm -rf lib bin
