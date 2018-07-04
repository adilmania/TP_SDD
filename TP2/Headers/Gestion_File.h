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
	elt	   *f;
}File;

/* Fonction qui crée une file et renvoie son adresse */
File*	init_file (const int taille);

/* Fonction qui enfile une valeur dans une file */
int		enfiler (File *file, elt valeur, int *err);

/* Fonction qui vérifie si la file est vide */
int		est_vide_f (const File file);

/* Fonction qui défile une valeur depuis une file */
int		defiler (File *file, int *err);

/* Fonction qui permet de libérer une file */
void	liberer_file (File *file);

/* Fonction qui affiche une file */
void	afficher_file (const File file); 

#endif
