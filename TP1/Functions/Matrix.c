#include "../Headers/Matrix.h"

/**
 * \file      Matrix.c					
 * \author    Rousset & Mania
 * \date      12 March 2018
 * \brief     Définit les fonctions nécessaires pour la création 
 *            dynamique d'une matrice à partir d'un fichier lu en entrée.
**/

/* ----------------------Lecture_Initialisation_Remplissage_Matrice----------------------------
* Fonction qui lit un fichier, initialise une matrice et la remplit à partir des données du fichier.

* Entrée:

	* fichier	: L'adresse du fichier
    * mat		: Pointeur sur la matrice
	* m 		: Nombres de lignes
	* n 		: Nombres de colonnes
	
* Entrée/Sortie :

	* monscanner : Structure servant à garder les valeurs récupérées du fichier
* ------------------------------------------------------------------------------------------- */

Scanner Lecture_Initialisation_Remplissage_Matrice(char * fichier, double** mat,int m,int n,Scanner monscanner)
{

	FILE * f = NULL; /* On initialise le pointeur sur le fichier */

	f = fopen(fichier,"r+"); /* On ouvre le fichier */

	if (f != NULL) /*Si le fichier est ouvert*/
	{
		int i,j;

		fscanf(f,"%d %d",&m,&n); /* On lit le nombre de lignes & celui des colonnes */

		mat = (double**)malloc(sizeof(double*)*m); /* On Alloue les lignes */
		for(i=0;i<m;i++)
		{
		       mat[i]=(double*)malloc(sizeof(double*)*n); /* On Alloue les colonnes */
		}

		for(i=0;i<m;i++) /* On lit des éléments depuis le fichier */
		{
			for(j=0;j<n;j++)
			{
				fscanf(f,"%lf",&mat[i][j]); /* on remplit la matrice */
			}
		} 
		
		monscanner.mat = mat; /* On enregistre les valeurs */
		monscanner.m = m;
		monscanner.n = n;
		
		Affichage_Matrice(mat,m,n);  /* On Affiche la matrice */
		fclose(f); /* On ferme le fichier */

	}
	else  /* Si la lecture ne s'est pas bien passé */
	{

		printf("Erreur d'ouverture du fichier!\n");
		                          
	}
	return monscanner;
}

/* ----------------------Affichage_Matrice----------------------------
* Fonction d'Affichage de la matrice.

* Entrée:
	* mat	: Pointeur sur la matrice
	* m 	: Nombres de lignes
	* n 	: Nombres de colonnes

* Sortie:
	* Aucune
* ------------------------------------------------------------------ */

void Affichage_Matrice(double ** mat,int m,int n)
{
	int i,j;
	printf("\n Affichage de la matrice lue du fichier \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%.2f ",mat[i][j]); /* On affiche les éléments de la matrice */
		}
		printf("\n");
	}
}         
