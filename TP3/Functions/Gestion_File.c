#include "../Headers/Gestion_File.h"

/**
 * \file      Gestion_File.c					
 * \author    Rousset & Mania
 * \date      12 June 2018
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
		file->f		=	(Element **) malloc(sizeof(Element*)*taille);

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
* Fonction qui enfile un élement dans une file.
*
* Entrée:
 	* file		:	la file à traiter
 	* element	:	l'élement à enfiler

* Entrée/Sortie:
 	* err		:	Booléen d'erreur (1 s'il y a une erreur et 0 sinon)
 * ------------------------------------------------------------------ */

int		enfiler (File *file, Element* element, int *err)
{
    *err	= 1;

	if (file->tf_max > file->tf )
	{
		(file->tf)++;
		file->f[(file->fin +1) % file->tf_max]	=	element;
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

/* ----------------------------------------------------------------------------
* Fonction qui vérifie si la file est pleine.
*
* Entrée:
 	* file		:	la file à traiter

* Sortie:
 	* 0 si la file n'est pas vide et 1 sinon
 * ---------------------------------------------------------------------------- */

int		est_pleine_f (const File file)
{
	return (file.tf) >= (file.tf_max);
}

/* ---------------------------------------------------------------------
* Fonction qui défile un élement depuis une file.

* Entrée:
	* err		:	Booléen d'erreur (1 s'il y a une erreur et 0 sinon)
 	* file		:	la file à traiter

* Sortie:
	* element	:	l'élement à extraire
 * --------------------------------------------------------------------- */

Element* defiler (File *file, int *err)
{
	Element* element = NULL;

	*err = 1;

	if (!est_vide_f(*file))
	{
		(file->tf)--;
		element	= file->f[file->deb];
		file->deb = (file->deb + 1) % file->tf_max;
		*err	=	0;
	}

	return element;
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