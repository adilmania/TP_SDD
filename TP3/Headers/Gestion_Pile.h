#ifndef GEST_PILE_H_INCLUDED
#define GEST_PILE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "../Headers/Gestion_Arbre.h"

/* Définition des constants globales */
#define TAILLE 10

/* Déclaration d'un type élément de la pile */

typedef struct Element_PILE{
    Element* adresse; /* Adresse à Empiler */
    int  nbfils; /* Nombre de fils */
}elt;

/* Définition de la structure Pile */

typedef struct PPile
{
	int		taille_max;
	int		sommet;
	elt*    p;
}Pile;

/* Fonction qui crée une pile et renvoie son adresse */

Pile* Init(const int taille);

/* Fonction qui empile un élement dans une pile */

int	empiler	(Pile *pile, elt element);

/* Fonction qui dépile un élement depuis une pile */

elt depiler (Pile *pile);

/* Fonction qui retourne le sommet de la pile */

elt* sommet	(Pile* pile);

/* Fonction qui vérifie si la pile est vide */

int est_vide_p(Pile * pile);

/* Fonction qui vérifie si la pile est pleine */

int est_pleine_p(Pile * pile);

/* Fonction qui permet de libérer une pile */

void LibererPile(Pile * pile);

#endif 
