#ifndef LIST_CH_H_INCLUDED
#define LIST_CH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Déclaration d'un type élément de liste chaînée */
typedef struct Element Element;
struct Element{
    int indice_colonne; /* Indice de la colonne de l'élément */
    int indice_ligne; /* Indice de la ligne de l'élément */
    int Cout; /* Valeur de l'élément */
    Element * suivant; /* Pointeur sur l'élément suivant */
};

/* Déclaration d'un type liste chaînée */
typedef struct Liste Liste;
struct Liste{
   Element * premier; /* Pointeurs sur le premier élément de la liste */
};

/* Fonction qui Initialise une liste chaînée */

Liste* Initialisation();

/* Fonction qui Insère dans une liste chaînée */

void Insertion_Bloc(Liste *liste, double** mat, int i, int j, Element* prec, Element* cour);
void Insertion_Triee(Liste* liste, double** mat, int i, int j);
void Insertion_Matrice(Liste* liste, double** mat, int m, int n, int K);

/* Fonction qui supprime un le premier élément de la liste chaînée */

void Suppression_Debut(Liste* liste);

/* Fonction qui Affiche une liste chaînée */

void Afficher_Liste(Liste* liste);

/* Fonction qui libère la liste chaînée */

void Liberer_Liste(Liste* liste);

#endif
