run_main: build ./build/main
	./build/main

./build/main: ./build/main.o ./build/fms.o ./build/fms_data.o
	gcc -o ./build/main ./build/main.o ./build/fms.o ./build/fms_data.o -lm

./build/main.o: ./src/main.c
	gcc -g -Wall -lm -o ./build/main.o -c ./src/main.c

./build/fms.o: ./src/fms.c
	gcc -g -Wall -lm -o ./build/fms.o -c ./src/fms.c

./build/fms_data.o: ./src/fms_data.c
	gcc -g -Wall -lm -o ./build/fms_data.o -c ./src/fms_data.c

build:
	mkdir ./build
