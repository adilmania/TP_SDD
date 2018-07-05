#ifndef INSERTION_ARBRE_H_INCLUDED
#define INSERTION_ARBRE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/Gestion_Arbre.h"

/* Fonction qui recherche une valeur dans un arbre trié */

Element* Recherche_Valeur(Element ** t, char valeur);

/* Fonction qui fait le parcours des fils d'un père donné */

Element* Parcours_Triee_Fils(Element* pere, char valeur);

/* Fonction qui insère une valeur dans un emplacement donné dans un arbre trié */

void Insertion_Triee(Element ** t, char W, char V);

#endif