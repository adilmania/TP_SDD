#include "../Headers/Gestion_Pile.h"
#include "../Headers/Gestion_Arbre.h"

/**
 * \file      Gestion_Pile.c
 * \author    Rousset & Mania
 * \date      12 June 2018
 * \details   Ce fichier contient les fonctions de gestion d'une pile
**/

/* ----------------------------------------------------------------------------
* Init    crée une pile et renvoie son adresse			       			                
                                                                              
* Entrée :
	* taille		:	taille max de la pile à créer

* Sortie:
	* pile		:	pointeur sur la structure contenant la pile                                                        
---------------------------------------------------------------------------- */

Pile* Init(const int taille)
{
	Pile	* pile = NULL; 

	pile	=	(Pile *) malloc(sizeof(Pile));

	if (pile != NULL)
	{
		pile->p		=	(elt *) malloc(sizeof(elt)*taille);

		if (pile->p != NULL)
		{
			pile->taille_max	=	taille;
			pile->sommet	=	-1;
		}
		else
		{
			free(pile);
			pile = NULL;
		}
	}

	return pile;
}

/* ----------------------------------------------------------------------------
* empiler    empile un élement dans une pile       			                
                                                                              
* Entrée :
	* pile		:	pointeur sur une structure contenant la pile
	* element	:	l'élement à extraire

* Entrée/Sortie:
	* 0: un entier.                                                        
---------------------------------------------------------------------------- */

int empiler (Pile *pile, elt element)
{

	if (pile->taille_max > (pile->sommet + 1))
	{
		(pile->sommet)++;
		pile->p[pile->sommet]	=	element;
	}

	return 0;
}

/* ----------------------------------------------------------------------------
* sommet    retourne le sommet de la pile        			                
                                                                              
* Entrée :
	* pile		:	pointeur sur une structure contenant la pile

* Sortie:
	* element		:	code de retour, 0 si on n'a pas récupéré l'élément en haut de la pile, 1 si on l'a récupéré                                                        
---------------------------------------------------------------------------- */

elt* sommet (Pile* pile)
{
	elt* element = NULL;

	if ( !est_vide_p(pile) )
	{
		*element	=	pile->p[pile->sommet];
	}

	return element;
}

/* ----------------------------------------------------------------------------
* depiler    dépile un élement depuis une pile        			                
                                                                              
* Entrée :
	* pile		:	pointeur sur une structure contenant la pile
	* err		:	Booléen d'erreur (1 s'il y a une erreur et 0 sinon)

* Sortie:
	* element		:	l'élement à extraire                                                        
---------------------------------------------------------------------------- */

elt depiler (Pile *pile)
{

	elt element;

	if (!est_vide_p( pile))
	{
		element	=	pile->p[pile->sommet];
		(pile->sommet)--;
	}

	return element;
}


/* ----------------------------------------------------------------------------
* est_vide_p    vérifie si la pile est vide        			                
                                                                              
* Entrée :
	* pile		:	pointeur sur une structure contenant la pile

* Sortie:
	* 0 (faux) si la pile n'est pas vide et 1 (vrai) sinon                                                            
---------------------------------------------------------------------------- */

int		est_vide_p (Pile * pile)
{
	return (pile->sommet == -1)?1:0;
}

/* ----------------------------------------------------------------------------
* est_pleine_p    vérifie si la pile est pleine        			                
                                                                              
* Entrée :
	* pile		:	pointeur sur une structure contenant la pile

* Sortie:
	* 0 (faux) si la pile n'est pas pleine et 1 (vrai) sinon                                                            
---------------------------------------------------------------------------- */

int est_pleine_p(Pile * pile) 
{
  	return (pile->sommet == (pile->taille_max)-1)?1:0;
}

/* ----------------------------------------------------------------------------
* LibererPile    libère la pile            			                
                                                                              
* Entrée :
	* pile		:	pointeur sur une structure contenant la pile

* Sortie:
	* Aucune                                                            
---------------------------------------------------------------------------- */

void LibererPile(Pile * pile)
{
	free( (pile->p) );
	free( pile );
	pile = NULL;
}
