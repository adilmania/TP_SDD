EXE   = tp3
OBJ   = *.o
CC    = gcc
FLAGS = -ansi -pedantic -g -Wall -Wextra

$(EXE): main.o Gestion_Arbre.o Gestion_Pile.o Gestion_File.o Affichage_Arbre.o Arbre_V2.o Parcours_Arbre_V2.o Insertion_Arbre.o
	$(CC) $(OBJ) -o $(EXE)

main.o: main.c ./Headers/Gestion_Arbre.h ./Headers/Gestion_Pile.h ./Headers/Gestion_File.h ./Headers/Affichage_Arbre.h ./Headers/Arbre_V2.h ./Headers/Parcours_Arbre_V2.h ./Headers/Insertion_Arbre.h
	$(CC) -c main.c -o main.o $(FLAGS)

Gestion_Arbre.o: ./Functions/Gestion_Arbre.c ./Headers/Gestion_Arbre.h
	$(CC) -c ./Functions/Gestion_Arbre.c -o Gestion_Arbre.o $(FLAGS)

Gestion_Pile.o: ./Functions/Gestion_Pile.c ./Headers/Gestion_Pile.h
	$(CC) -c ./Functions/Gestion_Pile.c -o Gestion_Pile.o $(FLAGS)

Gestion_File.o: ./Functions/Gestion_File.c ./Headers/Gestion_File.h
	$(CC) -c ./Functions/Gestion_File.c -o Gestion_File.o $(FLAGS)

Affichage_Arbre.o: ./Functions/Affichage_Arbre.c ./Headers/Affichage_Arbre.h
	$(CC) -c ./Functions/Affichage_Arbre.c -o Affichage_Arbre.o $(FLAGS)

Insertion_Arbre.o: ./Functions/Insertion_Arbre.c ./Headers/Insertion_Arbre.h
	$(CC) -c ./Functions/Insertion_Arbre.c -o Insertion_Arbre.o $(FLAGS)

Parcours_Arbre_V2.o: ./Functions/Parcours_Arbre_V2.c ./Headers/Parcours_Arbre_V2.h
	$(CC) -c ./Functions/Parcours_Arbre_V2.c -o Parcours_Arbre_V2.o $(FLAGS)

Arbre_V2.o: ./Functions/Arbre_V2.c ./Headers/Arbre_V2.h
	$(CC) -c ./Functions/Arbre_V2.c -o Arbre_V2.o $(FLAGS)
		
clean:
	rm $(OBJ)

