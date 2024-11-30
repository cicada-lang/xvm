# XVM

XVM is a extensible virtual machine.

- Written in C and extensible by C.
- Use tagged values and a garbage collector.

## Usage

On Linux:

```
git clone https://github.com/cicada-lang/xvm
cd xvm
make
make test
```

The compiled `bin/x` is the command-line program.

```sh
x repl        # start the read-eval-print-loop
x run         # run a script
x version     # print version
x help        # print help
```

## Development

```sh
make all      # compile src/ files to lib/ and bin/
make run      # compile and run the command-line program
make test     # compile and run test
make clean    # clean up compiled files
```

## References

**Inspirations**:

- [uxn](https://100r.co/site/uxn.html)
- [dt](https://github.com/so-dang-cool/dt)

**Books**:

- [Scalable C](https://github.com/booksbyus/scalable-c)

**Articles**:

- [Thoughts on Forth Programming](https://readonly.link/articles/https://code-of-xvm.xieyuheng.com/docs/references/articles/thoughts-on-forth-programming.md)
- [Forth Methodology Applied to Programming](https://readonly.link/articles/https://code-of-xvm.xieyuheng.com/docs/references/articles/forth-methodology-applied-to-programming.md)

## Contributions

To make a contribution, fork this project and create a pull request.

Please read the [STYLE-GUIDE.md](STYLE-GUIDE.md) before you change the code.

Remember to add yourself to [AUTHORS](AUTHORS).
Your line belongs to you, you can write a little
introduction to yourself but not too long.

## License

[GPLv3](LICENSE)
