#!/bin/sh
gcc tests/test0.c -o test0
gcc tests/test1.c -o test1
gcc tests/test2.c -o test2
gcc tests/test3a.c -o test3a
gcc tests/test3b.c -o test3b
gcc tests/test4.c -o test4
gcc tests/test5.c -L. libft_malloc.so -o test5