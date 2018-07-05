#ifndef GESTION_ARBRE_H_INCLUDED
#define GESTION_ARBRE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 69
#define BUFFER_SIZE (1024)

/* Déclaration d'un type élément de l'arbre */

typedef struct Element Element;
struct Element{
    char valeur; /* Caractère de l'arbre */
    Element * lv; /* Pointeur de l'élement fils (lien vertical) */
    Element * lh; /* Pointeur de l'élement suivant (lien horizontal) */
};

/* Fonction qui crée une cellule */

Element* Creation_Cellule(char moncaractere);

/* Fonction qui crée un arbre à partir d'un fichier */

Element** Lecture_Arbre(char * fichier, char buffer[BUFFER_SIZE], Element** t);

/* Fonction qui  libère la memoire occupée par l'arbre */

void Liberer_Arbre(Element** t);

#endif
