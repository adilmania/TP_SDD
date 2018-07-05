#include "../Headers/Arbre_V2.h"
#include "../Headers/Gestion_Pile.h"

/**
 * \file      Arbre_V2.c					
 * \author    Rousset & Mania
 * \date      12 June 2018
 * \brief     Définit les fonctions nécessaires pour réaliser
 *            la copie de l’arbre obtenu précedemment,
 *            en ajoutant l’adresse du père à chaque point. 
**/

/* ----------------------Creation_Cellule_V2----------------------------
* Fonction qui crée une cellule.

* Entrée :
 * ptpere : Pointeur sur le père de l'élément à créer.
 * moncaractere : Caractere de l'élément à insérer.

* Sortie :
 * element_V2 : Poniteur sur l'élément à créer.
* ------------------------------------------------------------------ */

Element_V2* Creation_Cellule_V2(Element_V2* pt_pere, char moncaractere)
{

	Element_V2* element_V2 = (Element_V2*) malloc (sizeof(Element_V2));

	if (element_V2 == NULL)
	{
		exit(EXIT_FAILURE);
	}

    element_V2 -> adpere = pt_pere;
	element_V2 -> lh = NULL;
	element_V2 -> lv = NULL;
	element_V2 -> valeur = moncaractere;

	return element_V2;

}

/* ----------------------Creation_Arbre_V2----------------------------
* Fonction qui crée un arbre à partir d'un arbre.

* Entrée :
 * t : Pointeur sur la tête de l'arbre existant.

* Entrée / Sortie :
 * t_V2 : Pointeur sur la tête de l'arbre créé.
* ------------------------------------------------------------------ */

Element_V2** Creation_Arbre_V2(Element** t,Element_V2** t_V2)
{
	Pile* ptpile = Init(TAILLE_MAX);		
	elt* element_pile = (elt*) malloc (sizeof(elt));

	int FIN = 0;

	Element_V2** pt_prec = t_V2;
	Element_V2** pt_cour = pt_prec;

	element_pile->adresse = *t;
    element_pile->nbfils = 0;

	printf("\n---------- CREATION ARBRE V2 (Représenation Préfixée) ---------\n"); 

	while( FIN == 0 )
	{

		while( element_pile->adresse != NULL )
		{
			printf("(-%c-) \n",((element_pile->adresse)->valeur));

			*pt_cour = Creation_Cellule_V2(*pt_prec,(element_pile->adresse)->valeur);
		
			empiler(ptpile,*element_pile);
			element_pile->adresse = ((element_pile->adresse)->lv);	

			pt_prec = pt_cour;
			pt_cour = &((*pt_cour)->lv);

		}

		if( !est_vide_p(ptpile) )
		{

			*element_pile = depiler(ptpile);
			element_pile->adresse = ((element_pile->adresse)->lh);

			pt_cour = &((*pt_prec)->lh);
			pt_prec = &((*pt_prec)->adpere);
			
		}
		else
		{
			FIN = 1;
		}

	}
	printf("----------------------------------------------------------------\n");
	
	free(element_pile);
	LibererPile(ptpile);

	return t_V2;
}

/* ----------------------Liberer_Arbre_V2----------------------------
* Fonction qui libère la memoire occupée par l'arbre

* Entrée :
 * t_V2 : Le pointeur sur la tête de l'arbre.

* Entrée/Sortie :
 * Aucune.
* ------------------------------------------------------------------ */

void Liberer_Arbre_V2(Element_V2** t_V2)
{

    Element_V2* pt_cour = *t_V2;
	Element_V2* pt_prec = pt_cour;
	Element_V2* pt_temp = NULL;

	int FIN = 0;

	while( FIN == 0 )
	{

		while( pt_cour != NULL )
		{
			pt_prec = pt_cour;
			pt_cour = ((pt_cour)->lv);
		}

		if( pt_prec != NULL )
		{

			pt_temp = pt_prec;

			if( ((pt_prec)->lh) != NULL )
			{
				pt_prec = ((pt_prec)->lh);
				pt_cour = ((pt_prec)->lv);
			}
			else
			{
				pt_prec = ((pt_prec)->adpere);
			}

			free(pt_temp);

		}
		else
		{
			FIN = 1;
		}

	}

	*t_V2 = NULL;

}