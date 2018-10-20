CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -c -Iinclude

all: bin/main bin/testMain

bin/BinarySearchTreeAPI.o: src/BinarySearchTreeAPI.c
	$(CC) $(CFLAGS) src/BinarySearchTreeAPI.c -o bin/BinarySearchTreeAPI.o

bin/userDefined.o: src/userDefined.c
	$(CC) $(CFLAGS) src/userDefined.c -o bin/userDefined.o

bin/commandLoop.o: src/commandLoop.c
	$(CC) $(CFLAGS) src/commandLoop.c -o bin/commandLoop.o

bin/Rule.o:	src/Rule.c
	$(CC) $(CFLAGS) src/Rule.c -o bin/Rule.o

bin/main.o: src/main.c
	$(CC) $(CFLAGS) src/main.c -o bin/main.o

bin/main: bin/main.o bin/BinarySearchTreeAPI.o bin/userDefined.o bin/commandLoop.o bin/Rule.o
	$(CC) bin/main.o bin/BinarySearchTreeAPI.o bin/userDefined.o bin/commandLoop.o bin/Rule.o -o bin/runMe 

bin/testMain.o: src/testMain.c
	$(CC) $(CFLAGS) src/testMain.c -o bin/testMain.o 

bin/testMain: bin/testMain.o bin/userDefined.o bin/BinarySearchTreeAPI.o bin/commandLoop.o bin/Rule.o
	$(CC) bin/testMain.o bin/userDefined.o bin/BinarySearchTreeAPI.o bin/commandLoop.o bin/Rule.o -o bin/runTest

run:
	./bin/runMe testFile.txt

runTest:
	./bin/runTest

clean:
	rm bin/*.o
	rm bin/runMe
	rm bin/runTest
	
