#include "../Headers/Gestion_File.h"


/**
 * \file      Gestion_File.c					
 * \author    Rousset & Mania
 * \date      6 March 2018
 * \brief     Définit les fonctions nécessaires pour la création 
 *            dynamique d'une matrice à partir d'un fichier lu en entrée.
 * \details   Ce fichier contient les fonctions permettant de lire un fichier 
 *            et à partir des valeurs lues de créer dynamiquement une matrice.
**/

/* ------------------------------------------------------------------
* Fonction qui crée une file et renvoie son adresse.

* Entrée:
	* taille	:	taille max de la file à créer
	
* Sortie :
 	* file		:	pointeur sur une structure contenant la file
* ------------------------------------------------------------------- */
File*	init_file (const int taille)
{
	File*   file = NULL;

	file	=	(File *) malloc(sizeof(File));

	if (file != NULL)
	{
		file->f		=	(elt *) malloc(sizeof(elt)*taille);

		if (file->f != NULL)
		{
			file->tf_max	=	taille;
			file->tf		=	0;
			file->fin	    =	taille-1;
			file->deb	    =	0;
		}
		else
		{
			free(file);
			file = NULL;
		}
	}

	return file;
}

/* -------------------------------------------------------------------
* Fonction qui enfile une valeur dans une file.
*
* Entrée:
 	* file		:	la file à traiter
 	* valeur	:	la valeur à enfiler

* Entrée/Sortie:
 	* err		:	Booléen d'erreur (1 s'il y a une erreur et 0 sinon)
 * ------------------------------------------------------------------ */

int		enfiler (File *file, elt valeur, int *err)
{
    *err	= 1;

	if (file->tf_max > file->tf )
	{
		(file->tf)++;
		file->f[(file->fin +1) % file->tf_max]	=	valeur;
		(file->fin)                             = (file->fin +1) % file->tf_max;
	    *err										=	0;
	}

	return *err;
}

/* ----------------------------------------------------------------------------
* Fonction qui vérifie si la file est vide.
*
* Entrée:
 	* file		:	la file à traiter

* Sortie:
 	* res		:	resultat à retourner (0 si la liste n'est pas vide et 1 sinon)
 * ---------------------------------------------------------------------------- */

int		est_vide_f (const File file)
{
	int res = 0;

	if (file.tf == 0)
		res = 1;

	return res;
}

/* ---------------------------------------------------------------------
* Fonction qui défile une valeur depuis une file.

* Entrée:
	* err		:	Booléen d'erreur (1 s'il y a une erreur et 0 sinon)
 	* file		:	la file à traiter

* Sortie:
	* valeur	:	la valeur à extraire
 * --------------------------------------------------------------------- */

int		defiler (File *file, int *err)
{
	elt		valeur = 0;

	*err = 1;

	if (!est_vide_f(*file))
	{
		(file->tf)--;
		valeur	=	file->f[file->deb];
		file->deb = (file->deb + 1) % file->tf_max;
		*err	=	0;
	}

	return valeur;
}

/* ----------------------------------------------------------------------
* Fonction qui affiche une file.

* Entrée:
	* file		:	pointeur sur une structure contenant la file

* Sortie :
	* Aucune
* ----------------------------------------------------------------------- */

void	 afficher_file (const File file)
{
	int 	i = 0;
	printf("  |     |\n");
	for(i = file.fin; i >= file.deb; i--)
		printf("  |%d    |\n", file.f[i]);
}

/* -----------------------------------------------------------
* Fonction qui permet de libérer une file.

* Entrée:
 * file		:	pointeur sur une structure contenant la file

* Sortie :
	* Aucune 
* ------------------------------------------------------------ */

void	liberer_file (File *file)
{
		free(file->f);
		free(file);
}