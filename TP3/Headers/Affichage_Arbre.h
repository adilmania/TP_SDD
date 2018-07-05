#ifndef AFFICHAGE_ARBRE_H_INCLUDED
#define AFFICHAGE_ARBRE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Fonction qui calcule le nombre de fils */

int Calcul_Nb_Fils(Element* pt);

/* Fonction qui affiche l'arbre */

void Affichage_Arbre(Element** t);

#endif
