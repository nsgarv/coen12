g++ -c -o maze.o maze.cpp
g++ -c -o deque.o deque.cpp
g++ -o maze deque.o maze.o -lcurses

