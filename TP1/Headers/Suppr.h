#ifndef SUPPR_H_INCLUDED
#define SUPPR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/List_CH.h"

/*Fonction qui supprime les occurences d'une usine u dans la liste chaînée*/

void Suppression_Occurences(Liste *liste, int u);

/* Fonction qui supprime un élément de la liste chaînée à partir d'un pointeur courant et d'un pointeur précédent*/

void Suppression_Element(Liste* liste, Element* pt_prec, Element* pt_cour);

/* Fonction qui supprime un élément de la liste chaînée à partir d'un pointeur courant et d'un pointeur précédent*/

void Sauver_Dans_Un_Fichier(Liste* liste, char * fichier) ;

#endif
