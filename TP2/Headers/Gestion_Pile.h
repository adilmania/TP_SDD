#ifndef GEST_PILE_H_INCLUDED
#define GEST_PILE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/* Définition des constants globales */
#define TAILLE 10

/* Le type du type des valeurs utilisées */
typedef int elt;

/* Définition de la structure Pile */

typedef struct PPile
{
	int		taille_max;
	int		sommet;
	elt*    p;
}Pile;

/* Fonction qui crée une pile et renvoie son adresse */

Pile* Init(const int taille);

/* Fonction qui empile une valeur dans une pile */

int	empiler	(Pile *pile, elt valeur, int *err);

/* Fonction qui dépile une valeur depuis une pile */

int	depiler	(Pile *pile, int *err);

/* Fonction qui retourne le sommet de la pile */

int	sommet	(Pile* pile, int *err);

/* Fonction qui vérifie si la pile est vide */

int est_vide_p(Pile * pile);

/* Fonction qui permet de libérer une pile */

void LibererPile(Pile * pile);

/* Fonction qui affiche une pile */

void afficher_pile (const Pile pile);

#endif 
