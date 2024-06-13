run_main: build ./build/main
	./build/main

./build/main: ./build/main.o ./build/test.o ./build/test_data.o
	gcc -o ./build/main -lc ./build/main.o ./build/test.o ./build/test_data.o

./build/%.o: ./%.c
	gcc -g -Wall -o $@ -c $<

./build/test.o: ./src/test.c
	gcc -g -Wall -o ./build/test.o -c ./src/test.c

./build/test_data.o: ./src/test_data.c
	gcc -g -Wall -o ./build/test_data.o -c ./src/test_data.c

build:
	mkdir ./build