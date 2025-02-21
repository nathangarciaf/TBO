all: 
	gcc -g -Wall -o main *.c

run: 
	./main input/moby.txt

valgrind:
	valgrind --leak-check=full ./main input/moby.txt