#include "../Headers/List_CH.h"

/**
 * \file      List_CH.c					
 * \author    Rousset & Mania
 * \date      12 March 2018
 * \brief     Définit les fonctions nécessaires pour la création d'une liste chaînée contenant les K coûts
 *            les plus faibles et leurs indices dans la matrice, son affichage et sa libération.
**/


/* ----------------------Initialisation----------------------------
* Fonction qui Initialise une liste chaînée.

* Entrée :
 * Aucune.

* Sortie :
 * liste : Pointeur sur la tête de la liste chaînée.
* ------------------------------------------------------------------ */


Liste* Initialisation()
{
	Liste* liste = malloc(sizeof(*liste));
	Element* element = malloc(sizeof(*element));

	if ( liste == NULL || element == NULL)
	{
		exit(EXIT_FAILURE);
	}

	element -> indice_colonne = -1;
	element -> indice_ligne = -1;
	element -> Cout = -1;
	element -> suivant = NULL;

	liste -> premier = element;

	return liste;
}

/* ----------------------Insertion_Bloc----------------------------
* Fonction qui insère un bloc dans une liste chaînée à partir du bloc précédent et suivant.

* Entrée :
 * liste : Pointeur sur la tête de la liste chaînée.
 * prec : Pointeur sur l'élément précédant celui à insérer dans la liste chaînée.
 * cour : Pointeur sur l'élément suivant celui à insérer dans la liste chaînée.
 * mat : Pointeur sur la matrice.
 * i : Indice de ligne de l'élément à insérer dans la liste chaînée.
 * j : Indice de colonne de l'élément à insérer dans la liste chaînée.

* Sortie :
 * Aucune.
* ------------------------------------------------------------------ */

void Insertion_Bloc(Liste* liste, double** mat, int i, int j, Element* prec, Element* cour)
{
    Element* nouveau = malloc(sizeof(*nouveau));
 
    if ( liste == NULL  || nouveau == NULL )
    {
        exit(EXIT_FAILURE);
    }
 
	nouveau -> indice_ligne = i;
	nouveau -> indice_colonne = j;
	nouveau -> Cout = mat[i][j];
	
	if ( prec == liste -> premier && prec == cour) /* si le precedent est le pointeur de tête */
	{
		nouveau -> suivant = liste -> premier; /* Insetion en tête */
		liste -> premier = nouveau;
	}
	else
	{
		nouveau -> suivant = prec -> suivant; /* Insetion normale */
		prec -> suivant = nouveau;
	}

}

/* ----------------------Insertion_Triee----------------------------
* Fonction d'Insertion des blocs dans l'ordre décroissant pour les coûts de la matrice.

* Entrée :
 * liste : Pointeur sur la tête de la liste chaînée.
 * mat : Pointeur sur la matrice.
 * i : Indice de ligne de l'élément à insérer dans la liste chaînée.
 * j : Indice de colonne de l'élément à insérer dans la liste chaînée.

* Sortie :
 * Aucune.
/* ------------------------------------------------------------------ */

void Insertion_Triee(Liste* liste, double** mat, int i, int j)
{

	Element* pt_cour = NULL;
	Element* pt_prec = NULL;

	if ( liste == NULL )
	{
		exit(EXIT_FAILURE);
	}

	pt_cour = liste -> premier;
	pt_prec = liste -> premier;

	while( pt_cour != NULL && mat[i][j] < (pt_cour->Cout) )
	{
		pt_prec = pt_cour;
		pt_cour = pt_cour -> suivant;
	}

	Insertion_Bloc(liste,mat,i,j,pt_prec,pt_cour);

} 

/* ----------------------Insertion_Matrice----------------------------
* Fonction d'Insertion des K coûts les plus faibles dans la liste chaînée

* Entrée :
 * liste : Pointeur sur la tête de la liste chaînée. 
 * mat	: Pointeur sur la matrice.
 * m : Nombres de lignes.
 * n : Nombres de colonnes.
 * K : Nombre d'éléments à insérer dans la liste chaînée.

* Sortie :
 * Aucune.
* ------------------------------------------------------------------ */

void Insertion_Matrice(Liste* liste, double** mat, int m, int n, int K)
{
	int compteur = 0;
	int i,j;

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			Insertion_Triee(liste,mat,i,j);
			compteur++;
			if( compteur > K )
			{
				Suppression_Debut(liste);
			}
		}
	}
}

/* ----------------------Suppression_Debut----------------------------
* Fonction qui supprime le premier élément de la liste chaînée

* Entrée :
 * liste : Pointeur sur la tête de la liste chaînée.

* Sortie :
 * Aucune.
* ------------------------------------------------------------------ */

void Suppression_Debut(Liste* liste)
{
	if(liste == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (liste->premier != NULL)
	{
		Element* adSupp = liste -> premier;
		liste -> premier = liste -> premier -> suivant;
		free(adSupp);
	}
}

/* ----------------------Afficher_Liste----------------------------
* Fonction d'Affichage de la liste chaînée.

* Entrée :
 * liste : Pointeur sur la tête de la liste chaînée.

* Sortie :
 * Aucune.
* ------------------------------------------------------------------ */

void Afficher_Liste(Liste* liste)
{
	Element * actuel = liste -> premier;

	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}

	while (actuel != NULL)
	{
		if ( actuel -> indice_ligne != -1 )
		{
			printf("[ Ligne: %d, Colonne: %d, Cout: %d ] -> \n", actuel->indice_ligne, actuel->indice_colonne, actuel->Cout);
		}
		actuel = actuel -> suivant;
	}
	printf("-> NULL \n");
}

/* ----------------------Liberer_Liste----------------------------
* Fonction qui libère la liste chaînée.

* Entrée :
 * liste : Pointeur sur la tête de la liste chaînée.
 
* Sortie :
 * Aucune 
* ------------------------------------------------------------------ */

void Liberer_Liste(Liste* liste)
{
	Element * temp = liste -> premier;

	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}

	while ( (liste->premier) != NULL)
	{
		temp = liste -> premier;
		liste -> premier = temp -> suivant;
		free(temp);
		
	}
	printf("NULL \n");
}