CC = gcc
FLAGS = -std=gnu99 -O2 -Wall -Wextra
EXE = image_processing
ABC = 1

.PHONY: build run_task1 run_task2 run_task3 run_task4 run_bonus clean

build: image_processing

image_processing: main.o bmplib.o
	$(CC) main.o bmplib.o -o image_processing $(FLAGS)

main.o: main.c bmplib.h bmp_header.h
	$(CC) main.c -c -o main.o $(FLAGS)

bmplib.o: bmplib.c bmplib.h bmp_header.h
	$(CC) bmplib.c -c -o bmplib.o $(FLAGS)

run_task1: $(EXE)
	./$(EXE) 1

run_task2: $(EXE)
	./$(EXE) 2

run_task3: $(EXE)
	./$(EXE) 3

run_task4: $(EXE)
	./$(EXE) 4

run_bonus: $(EXE)
	./$(EXE) bonus

clean:
	rm -f *.o *.bmp $(EXE)