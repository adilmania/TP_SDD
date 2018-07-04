#include "../Headers/Suppr.h"

/**
 * \file      Suppr.c					
 * \author    Rousset & Mania
 * \date      12 March 2018
 * \brief     Définit les fonctions nécessaires pour la suppression 
 *            d'occurences d'une usine dans une liste chaînée, ainsi que 
 *            la fonction nécessaire pour sauvegarder les données de la liste 
 *            chaînée dans un fichier. 
**/

/* ----------------------Suppression_Occurences----------------------------
* Fonction de Suppression d'occurences d'une usine dans une liste chaînée

* Entrée :
	* liste		: Pointeur sur la tête de la liste chaînée
	* u 		: la valeur de l'usine à chercher

* Sortie:
	* Aucune
* ------------------------------------------------------------------ */

void Suppression_Occurences(Liste *liste, int u)
{
	Element* pt_cour = NULL;
	Element* pt_prec = NULL;

	if ( liste == NULL )
	{
		exit(EXIT_FAILURE);
	}

	pt_cour = liste -> premier;
	pt_prec = liste -> premier;
	while( pt_cour != NULL)
	{
		if (pt_cour -> indice_ligne == u)
		{
			Suppression_Element(liste,pt_prec, pt_cour);
			pt_cour = pt_prec -> suivant;
		}
		else
		{
			pt_prec = pt_cour;
			pt_cour = pt_prec -> suivant;
		}
	}
}

/* ----------------------Suppression_Element----------------------------
* Fonction qui supprime un élément de la liste chaînée à partir d'un pointeur courant et d'un pointeur précédent.

* Entrée :
	* liste		: Pointeur sur la tête de la liste chaînée
	* pt_prec 	: Pointeur précédent
	* pt_cour	: Pointeur courant

* Sortie:
	* Aucune
* ------------------------------------------------------------------ */

void Suppression_Element(Liste* liste, Element* pt_prec, Element* pt_cour)
{
	if (pt_prec == pt_cour) /* si le précédent est le pointeur de tête */
	{
		Element* adSupp = liste -> premier;
		liste -> premier = liste -> premier -> suivant;
		free(adSupp);
	}
	else
	{
		Element* adSupp = pt_cour;
		pt_prec -> suivant = pt_cour -> suivant;
		free(adSupp);
	}
	
}

/* ----------------------Sauver_Dans_Un_Fichier----------------------------
* Fonction de Sauvegarde dans un fichier

* Entrée :
	* liste		: Pointeur sur la tête de la liste chaînée
	* fichier 	: L'adresse du fichier

* Sortie:
	* Aucune
* ------------------------------------------------------------------ */

void Sauver_Dans_Un_Fichier(Liste* liste, char * fichier) 
{
  FILE * f = NULL;
  Element* pt_cour = liste->premier;
  
  f = fopen(fichier,"w+");

  if (f) {
    while (pt_cour) {
	  if(pt_cour->Cout != -1)
	  {
		  fprintf(f,"%d \n",pt_cour->Cout);
	  }		
      pt_cour = pt_cour->suivant;
    }
    fclose(f);
  }
}