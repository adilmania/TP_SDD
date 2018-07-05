#include "../Headers/Gestion_Arbre.h"
#include "../Headers/Gestion_Pile.h"
#include "../Headers/Gestion_File.h"

/**
 * \file      Gestion_Arbre.c					
 * \author    Rousset & Mania
 * \date      12 June 2018
 * \brief     Définit la fonction nécessaire pour la création d'une
 * 			  cellule, ainsi que la fonction de la gestion de l'arbre,
 * 			  en ce qui concerne sa création à partir d'un fichier. 
**/

/* ----------------------Creation_Cellule----------------------------
* Fonction de creation d'une cellule.

* Entrée :
 * moncaractere : Le caractère à mettre dans la cellule à créer. 

* Sortie :
 * element : l'adresse de la cellule créee. 
* ------------------------------------------------------------------ */

Element* Creation_Cellule(char moncaractere)
{

	Element* element = (Element*) malloc (sizeof(Element));

	if (element == NULL)
	{
		exit(EXIT_FAILURE);
	}

	element -> lh = NULL;
	element -> lv = NULL;
	element -> valeur = moncaractere;

	return element;

}

/* ----------------------Lecture_Arbre----------------------------
* Fonction qui crée un arbre à partir d'un fichier

* Entrée :
 * fichier : Pointeur sur le fichier.
 * buffer	: Chaîne de caractère permettant de lire le fichier.

* Entrée/Sortie :
 * t : Le pointeur sur la tête de l'arbre.
* ------------------------------------------------------------------ */

Element** Lecture_Arbre(char * fichier, char buffer[BUFFER_SIZE], Element** t)
{
	FILE * f = NULL; /* On initialise le pointeur sur le fichier */

	f = fopen(fichier,"r+"); /* On ouvre le fichier */

	printf("\n---------- LECTURE ARBRE -----------\n");

	if (f != NULL) /*Si le fichier est ouvert*/
	{
		Pile* ptpile;
		
		Element ** pt_prec = t;
		
		elt* element_pile = (elt*) malloc (sizeof(elt));

		int compteur = 1;

		ptpile = Init(TAILLE_MAX);
		
		fgets(buffer,BUFFER_SIZE,f);

		while( buffer[compteur] != '\n')
		{

			switch(buffer[compteur])
			{

				case '(':

					element_pile->adresse = *pt_prec;
					empiler(ptpile,*element_pile);
					pt_prec = &((*pt_prec)->lv);
					break;

				case ')':

					if( !est_vide_p(ptpile) )
					{
						*element_pile = depiler(ptpile);
						pt_prec = &((element_pile->adresse)->lh);
					}
					break;

				case ',':

					pt_prec = &((*pt_prec)->lh);
					break;

				default:

					printf("Test: %c \n",buffer[compteur]);
					*  pt_prec = Creation_Cellule(buffer[compteur]);
			}
			compteur++;
		}
		LibererPile(ptpile);
		free(element_pile);
		fclose(f); /* On ferme le fichier */

	}
	else  /* Si la lecture ne s'est pas bien passé */
	{

		printf("Erreur d'ouverture du fichier!\n");
		                          
	}
	printf("-----------------------------------\n");
	return t;
}

/* ----------------------Liberer_Arbre----------------------------
* Fonction qui libère la memoire occupée par l'arbre

* Entrée :
 * t : Le pointeur sur la tête de l'arbre.

* Entrée/Sortie :
 * Aucune.
* ------------------------------------------------------------------ */

void Liberer_Arbre(Element** t)
{
	Pile* ptpile = Init(TAILLE_MAX);

	elt* element_pile = (elt*) malloc (sizeof(elt));
	Element* pt_temp = NULL;

	int FIN = 0;

	element_pile->adresse = *t;
    element_pile->nbfils = 0;

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
			pt_temp = (element_pile->adresse); 
			element_pile->adresse = ((element_pile->adresse)->lh);
			free(pt_temp);

		}
		else
		{
			FIN = 1;
		}

	}
	LibererPile(ptpile);
	free(element_pile);
	*t = NULL;
}