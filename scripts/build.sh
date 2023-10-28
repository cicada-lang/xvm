echo "clang"
clang -o build/xvm -Wall -Wwrite-strings -Wextra -Werror -O2 -std=c2x -pedantic src/*.c

echo "gcc"
gcc -o build/xvm -Wall -Wwrite-strings -Wextra -Werror -O2 -std=c2x -pedantic src/*.c
