
gcc -g -Wall -c -o maze.o maze.c
gcc -g -Wall -c -o deque.o deque.c
gcc -o maze maze.o deque.o -lcurses



