# X Script

X Script is a pure postfix scripting language.

- It is trivially extensible by C, to be used as scripting language for C/C++ projects.
- It has NO garbage collector, it allocates and frees memory directly.
- It uses a simple linear type system for resource management.

## Usage

On Linux:

```
git clone https://github.com/xieyuheng/x-script
cd x-script
make
```

The compiled `bin/x` is the command-line program.

```sh
x repl       # start the read-eval-print-loop
x run        # run a script
x version    # print version
x help       # print help
```

## Development

```sh
make all      # compile src/ files to lib/ and bin/
make run      # compile and run the interpreter
make test     # compile and run test
make clean    # clean up compiled files
```

## References

**Books**:

- [Scalable C](https://github.com/booksbyus/scalable-c)

**Tools**:

- [Makefile tutorial](https://makefiletutorial.com)
- [Makefile manual](https://www.gnu.org/software/make/manual/make.html)

**Articles**:

- [Thoughts on Forth Programming](https://readonly.link/articles/https://code-of-x-script.fidb.app/docs/references/articles/thoughts-on-forth-programming.md)
- [Forth Methodology Applied to Programming](https://readonly.link/articles/https://code-of-x-script.fidb.app/docs/references/articles/forth-methodology-applied-to-programming.md)

## Contributions

To make a contribution, fork this project and create a pull request.

Please read the [STYLE-GUIDE.md](STYLE-GUIDE.md) before you change the code.

Remember to add yourself to [AUTHORS](AUTHORS).
Your line belongs to you, you can write a little
introduction to yourself but not too long.

## License

[GPLv3](LICENSE)
