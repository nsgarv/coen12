gcc -g -Wall -c -o huffman.o huffman.c
gcc -g -Wall -c -o pack.o pack.c
gcc -o huffman huffman.o tree.o pack.o	
