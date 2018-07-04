EXE   = tp1
OBJ   = *.o
CC    = gcc
FLAGS = -ansi -pedantic -g -Wall -Wextra

$(EXE): main.o List_CH.o Matrix.o Suppr.o
	$(CC) $(OBJ) -o $(EXE)

main.o: main.c ./Headers/List_CH.h ./Headers/Matrix.h ./Headers/Suppr.h
	$(CC) -c main.c -o main.o $(FLAGS)

List_CH.o: ./Functions/List_CH.c ./Headers/List_CH.h
	$(CC) -c ./Functions/List_CH.c -o List_CH.o $(FLAGS)

Matrix.o: ./Functions/Matrix.c ./Headers/Matrix.h
	$(CC) -c ./Functions/Matrix.c -o Matrix.o $(FLAGS)

Suppr.o: ./Functions/Suppr.c ./Headers/Suppr.h
	$(CC) -c ./Functions/Suppr.c -o Suppr.o $(FLAGS)
		
clean:
	rm $(OBJ)

