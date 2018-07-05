#include "../Headers/Gestion_Arbre.h"
#include "../Headers/Gestion_Pile.h"
#include "../Headers/Affichage_Arbre.h"

/**
 * \file      Affichage_Arbre.c					
 * \author    Rousset & Mania
 * \date      12 June 2018
 * \brief     Définit les fonctions nécessaires pour l'affichage
 * 			  de l'arbre en représentation postfixée avec le nombre
 * 			  de fils. 
**/

/* ----------------------Calcul_Nb_Fils----------------------------
* Fonction qui calcule le nombre de fils

* Entrée :
 * pt : Pointeur sur la tête de la liste chaînée. 


* Sortie :
 * compt: Le compteur de nombre de fils.
* ------------------------------------------------------------------ */

int Calcul_Nb_Fils(Element* pt){

	int compt = 0;
	Element* pt_cour = pt->lv;

	while(pt_cour != NULL)
	{
		compt++;
		pt_cour = pt_cour->lh;
	}

	return compt;
}

/* ----------------------Affichage_Arbre----------------------------
* Fonction qui affiche les élements de l'arbre avec le nombre de fils

* Entrée :
 * t : Pointeur sur la tête de l'arbre. 

* Sortie :
 * Aucune.
* ------------------------------------------------------------------ */

void Affichage_Arbre(Element** t)
{
	Pile* ptpile = Init(TAILLE_MAX);

	elt* element_pile = (elt*) malloc (sizeof(elt));

	int FIN = 0;

	element_pile->adresse = *t;
    element_pile->nbfils = 0;

	printf("\n---------- AFFICHAGE ARBRE (Représenation Postfixée) -----------\n");

	while( FIN == 0 )
	{		
		while( element_pile->adresse != NULL )
		{			
			empiler(ptpile,*element_pile);
			element_pile->adresse = ((element_pile->adresse)->lv);	
		}

		if( !est_vide_p(ptpile) )
		{
			*element_pile = depiler(ptpile);
			(element_pile->nbfils) = Calcul_Nb_Fils((element_pile->adresse));
			printf("(%c,%d) \n",((element_pile->adresse)->valeur),((element_pile->nbfils)));
			element_pile->adresse = ((element_pile->adresse)->lh);
		}
		else
		{
			FIN = 1;
		}

	}
	printf("----------------------------------------------------------------\n");
	free(element_pile);
	LibererPile(ptpile);
}
