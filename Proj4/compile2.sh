
gcc -g -Wall -c -o radix.o radix.c
gcc -g -Wall -c -o deque.o deque.c
gcc -o radix radix.o deque.o -lcurses




