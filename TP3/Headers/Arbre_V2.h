#ifndef ARBRE_V2_H_INCLUDED
#define ARBRE_V2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/Gestion_Arbre.h"

#define TAILLE_MAX 69
#define BUFFER_SIZE (1024)

/* Déclaration d'un type élément de l'arbre */

typedef struct Element_V2 Element_V2;
struct Element_V2{
    char valeur; /* Caractère de l'arbre */
    Element_V2 * adpere; /* Adresse du Père */
    Element_V2 * lv; /* Pointeur de l'élement fils (lien vertical) */
    Element_V2 * lh; /* Pointeur de l'élement suivant (lien horizontal) */
};

/* Fonction qui crée une cellule */

Element_V2* Creation_Cellule_V2(Element_V2* pt_pere, char moncaractere);

/* Fonction qui crée un arbre à partir d'un arbre */

Element_V2** Creation_Arbre_V2(Element** t,Element_V2** t_V2);

/* Fonction qui libère la memoire occupée par l'arbre */

void Liberer_Arbre_V2(Element_V2** t_V2);

#endif
