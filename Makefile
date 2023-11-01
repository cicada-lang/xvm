cc = gcc
ldflags =
cflags = -g -Wall -Wwrite-strings -Wextra -Werror -O2 -std=c99 -pedantic

src = ${shell find src -name '*.c'}
lib = ${patsubst src/%,lib/%,${patsubst %.c,%.o,${src}}}
bin = bin/xvm

.PHONY: all
all: ${bin}

.PHONY: run
run: ${bin}
	time ./bin/xvm

${bin}: ${lib}
	mkdir -p ${dir $@}; ${cc} ${ldflags} $^ -o $@

lib/%.o: src/%.c
	mkdir -p ${dir $@}; $(cc) -c $(cflags) $< -o $@

.PHONY: clean
clean:
	rm -rf lib bin
