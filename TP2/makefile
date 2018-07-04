EXE   = tp2
OBJ   = *.o
CC    = gcc
FLAGS = -ansi -pedantic -g -Wall -Wextra

$(EXE): main.o Gestion_Pile.o Gestion_File.o Inversion.o
	$(CC) $(OBJ) -o $(EXE)

main.o: main.c ./Headers/Gestion_Pile.h ./Headers/Gestion_File.h ./Headers/Inversion.h
	$(CC) -c main.c -o main.o $(FLAGS)

Gestion_Pile.o: ./Functions/Gestion_Pile.c ./Headers/Gestion_Pile.h
	$(CC) -c ./Functions/Gestion_Pile.c -o Gestion_Pile.o $(FLAGS)

Gestion_File.o: ./Functions/Gestion_File.c ./Headers/Gestion_File.h
	$(CC) -c ./Functions/Gestion_File.c -o Gestion_File.o $(FLAGS)

Inversion.o: ./Functions/Inversion.c ./Headers/Inversion.h
	$(CC) -c ./Functions/Inversion.c -o Inversion.o $(FLAGS)
		
clean:
	rm $(OBJ)

