echo "clang"
clang -o build/xvm -Wall -Wwrite-strings -Wextra -Werror -O2 -std=c99 -pedantic src/xvm.c src/dict/dict.c src/word/word.c

echo "gcc"
gcc -o build/xvm -Wall -Wwrite-strings -Wextra -Werror -O2 -std=c99 -pedantic src/xvm.c src/dict/dict.c src/word/word.c
