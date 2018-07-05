#ifndef __FILE_H__
#define __FILE_H__

#include "../Headers/Gestion_Pile.h"

/* Définition de la structure File */

typedef struct FFile
{
	int		tf_max;		
	int		tf;
	int		deb;
	int		fin;
	Element **f;
}File;

/* Fonction qui crée une file et renvoie son adresse */
File*	init_file (const int taille);

/* Fonction qui enfile un élement dans une file */
int		enfiler (File *file, Element* element, int *err);

/* Fonction qui vérifie si la file est vide */
int		est_vide_f (const File file);

/* Fonction qui vérifie si la file est pleine */
int		est_pleine_f (const File file);

/* Fonction qui défile un élement depuis une file */
Element* defiler (File *file, int *err);

/* Fonction qui permet de libérer une file */
void	liberer_file (File *file);

#endif
