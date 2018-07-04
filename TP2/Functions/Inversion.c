#include "../Headers/Inversion.h"

/**
 * \file      Inversion.c					
 * \author    Rousset & Mania
 * \date      6 March 2018
 * \brief     Définit les fonctions nécessaires pour la création 
 *            dynamique d'une matrice à partir d'un fichier lu en entrée.
 * \details   Ce fichier contient les fonctions permettant de lire un fichier 
 *            et à partir des valeurs lues de créer dynamiquement une matrice 
**/

/* ---------------------------------------------------------------------
* Fonction qui inverse une pile.

* Entrée:
	* pile		:	la pile à traiter
	* file		:   file permettant l'inversion

* Sortie:
	* Aucune
 * --------------------------------------------------------------------- */

void inversion(Pile *pile, File *file)
{
	int i     = 0,
	    err   = 0,
	    max_p = pile->sommet + 1,
	    max_f = 0;
	    
	if(pile->sommet != -1)
	{
		for(i=0;i<max_p;++i)
		{
			enfiler(file,depiler(pile,&err),&err);
		}
		max_f = file->tf;
		for(i=0;i<max_f;++i)
		{
			empiler(pile,defiler(file,&err),&err);
		}
	}
}