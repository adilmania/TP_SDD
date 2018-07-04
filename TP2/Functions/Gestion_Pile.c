#include "../Headers/Gestion_Pile.h"

/**
 * \file      Gestion_Pile.c
 * \author    Rousset & Mania
 * \date      06 March 2018
 * \details   Ce fichier contient les fonctions de gestion d'une pile
 */

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
* empiler    empile une valeur dans une pile       			                
                                                                              
* Entrée :
	* pile		:	pointeur sur une structure contenant la pile
	* valeur		:	la valeur à extraire

* Entrée/Sortie:
	* err		:	Booléen d'erreur (1 s'il y a une erreur et 0 sinon)	                                                        
---------------------------------------------------------------------------- */

int		empiler (Pile *pile, elt valeur, int* err)
{
	*err	= 1;

	if (pile->taille_max > (pile->sommet + 1))
	{
		(pile->sommet)++;
		pile->p[pile->sommet]	=	valeur;
	    *err				    =	0;
	}

	return *err;
}

/* ----------------------------------------------------------------------------
* sommet    retourne le sommet de la pile        			                
                                                                              
* Entrée :
	* pile		:	pointeur sur une structure contenant la pile
	* err		:	Booléen d'erreur (1 s'il y a une erreur et 0 sinon)

* Sortie:
	* valeur		:	code de retour, 0 si on n'a pas récupéré l'élément en haut de la pile, 1 si on l'a récupéré                                                        
---------------------------------------------------------------------------- */

int		sommet (Pile* pile, int *err)
{
	elt 	valeur = 0;

	*err = 1;

	if ( !est_vide_p(pile) )
	{
		valeur	=	pile->p[pile->sommet];
		*err	=	0;
	}

	return valeur;
}

/* ----------------------------------------------------------------------------
* depiler    dépile une valeur depuis une pile        			                
                                                                              
* Entrée :
	* pile		:	pointeur sur une structure contenant la pile
	* err		:	Booléen d'erreur (1 s'il y a une erreur et 0 sinon)

* Sortie:
	* valeur		:	la valeur à extraire                                                        
---------------------------------------------------------------------------- */

int		depiler (Pile* pile, int *err)
{
	elt		valeur = 0;

	*err = 1;

	if (!est_vide_p( pile))
	{
		valeur	=	pile->p[pile->sommet];
		(pile->sommet)--;
		*err	=	0;
	}

	return valeur;
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

/* ----------------------------------------------------------
* Fonction qui affiche une pile.

* Entrée :
	* pile		:	pointeur sur une structure contenant la pile

* Sortie:
	* Aucune
* ----------------------------------------------------------- */

void	 afficher_pile (const Pile pile)
{
	int 	i = 0;
    printf("  |     |\n");
	for(i = 0; i <= pile.sommet; i++)
		printf("  |%d    |\n", pile.p[pile.sommet - i]);
	printf("  ———————\n");
}