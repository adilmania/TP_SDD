#include "../Headers/Arbre_V2.h"
#include "../Headers/Parcours_Arbre_V2.h"

/**
 * \file      Parcours_Arbre_V2.c					
 * \author    Rousset & Mania
 * \date      12 June 2018
 * \brief     Fonction qui affiche les points de l’arbre obtenu 
 *            précedemment dans l’ordre postfixé.  
**/

/* ----------------------Parcours_Arbre_V2----------------------------
* Fonction qui initialise une liste chaînée.

* Entrée :
 * t_V2 : Pointeur sur la tête de l'arbre.

* Sortie :
 * Aucune.
* ------------------------------------------------------------------ */

void Parcours_Arbre_V2(Element_V2** t_V2)
{

    Element_V2* pt_cour = *t_V2;
	Element_V2* pt_prec = pt_cour;

	int FIN = 0;

	printf("\n---------- PARCOURS ARBRE V2 (Représenation Postfixée) ---------\n");

	while( FIN == 0 )
	{

		while( pt_cour != NULL )
		{
			pt_prec = pt_cour;
			pt_cour = ((pt_cour)->lv);
		}

		if( pt_prec != NULL )
		{

			printf("(--%c--) \n",((pt_prec)->valeur));

			if( ((pt_prec)->lh) != NULL )
			{
				pt_prec = ((pt_prec)->lh);
				pt_cour = ((pt_prec)->lv);
			}
			else
			{
				pt_prec = ((pt_prec)->adpere);
			}

		}
		else
		{
			FIN = 1;
		}

	}

	printf("----------------------------------------------------------------\n");

}
