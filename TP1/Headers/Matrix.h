#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure des informations à scanner depuis le fichier */

typedef struct Scanner Scanner;
struct Scanner{
    double** mat; /* Pointeur sur la matrice */
    int m; /* Nombres de lignes */
    int n; /* Nombres de colonnes */
};

/* Fonction qui lit un fichier, initialise une matrice et la remplit à partir des données du fichier */

Scanner Lecture_Initialisation_Remplissage_Matrice(char * fichier, double** mat,int m,int n,Scanner monscanner);

/* Fonction d'Affichage de la matrice */

void Affichage_Matrice(double ** mat,int m,int n);

#endif
