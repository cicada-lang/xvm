cc = gcc
ldflags =
cflags = -g -Wall -Wwrite-strings -Wextra -Werror -O2 -std=c99 -pedantic

src = ${shell find src -name '*.c'}
lib = ${patsubst src/%,lib/%,${patsubst %.c,%.o,${src}}}
bin = bin/xvm bin/xvm-test

.PHONY: all
all: ${bin}

.PHONY: run
run: bin/xvm
	./bin/xvm

.PHONY: test
test: bin/xvm-test
	./bin/xvm-test

${bin}: ${lib}
	$(cc) -c $(cflags) ${patsubst bin/%,%.c,$@} -o ${patsubst bin/%,%.o,$@}
	mkdir -p ${dir $@}; ${cc} ${ldflags} $^ ${patsubst bin/%,%.o,$@} -o $@

lib/%.o: src/%.c
	mkdir -p ${dir $@}; $(cc) -c $(cflags) $< -o $@

.PHONY: clean
clean:
	rm -f ${patsubst bin/%,%.o,${bin}}
	rm -rf lib bin
