cc = gcc
ldflags =
cflags = -g -Wall -Wwrite-strings -Wextra -Werror -O2 -std=c99 -pedantic

src = ${shell find src -name '*.c'}
lib = ${patsubst src/%,lib/%,${patsubst %.c,%.o,${src}}}
bin = xvm xvm-test

.PHONY: all
all: ${bin}

${bin}: ${lib}
	$(cc) -c $(cflags) $@.c -o $@.o
	mkdir -p bin; ${cc} ${ldflags} $@.o $^ -o bin/$@

lib/%.o: src/%.c
	mkdir -p ${dir $@}; $(cc) -c $(cflags) $< -o $@

.PHONY: clean
clean:
	rm -f ${patsubst %,%.o,${bin}}
	rm -rf lib bin
