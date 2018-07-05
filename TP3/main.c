#include "./Headers/Gestion_Arbre.h"
#include "./Headers/Gestion_Pile.h"
#include "./Headers/Affichage_Arbre.h"
#include "./Headers/Arbre_V2.h"
#include "./Headers/Parcours_Arbre_V2.h"
#include "./Headers/Insertion_Arbre.h"

int main(int argc, char *argv[])
{

	if(argc>1)
	{

		Element * pt_de_tete = NULL;
		Element_V2 * pt_de_tete_V2 = NULL;

		Element ** pttete = NULL;
		Element_V2 ** pttete_V2 = NULL;

		char buffer[BUFFER_SIZE];
	
		pttete = Lecture_Arbre(argv[1],buffer,&pt_de_tete);

		Affichage_Arbre(pttete);

		pttete_V2 = Creation_Arbre_V2(&pt_de_tete,&pt_de_tete_V2);

		Affichage_Arbre(pttete);

		Parcours_Arbre_V2(pttete_V2);

		Affichage_Arbre(pttete);

		Insertion_Triee(pttete,'y','t');

		Affichage_Arbre(pttete);

		Liberer_Arbre(pttete);

		Liberer_Arbre_V2(pttete_V2);

		Affichage_Arbre(pttete);

	}
	else
	{

		printf("Veuillez entrer le bon nombre d'arguments!\n");

	}
    return 0;
}
