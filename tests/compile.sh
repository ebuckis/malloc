#!/bin/sh
gcc test0.c -o test0
gcc test1.c -o test1
gcc test2.c -o test2
gcc test3a.c -o test3a
gcc test3b.c -o test3b
gcc test4.c -o test4
gcc test5.c -L. libft_malloc.so -o test5