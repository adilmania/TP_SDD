#include "./Headers/Matrix.h"
#include "./Headers/List_CH.h"
#include "./Headers/Suppr.h"

int main(int argc, char *argv[])
{

	if(argc>2)
	{
		int m = 0, n = 0;
		double ** mat = NULL;
		int K = atoi(argv[2]);

		Scanner myscanner;

		/* Initialisation de la liste chaînée des coûts */
		Liste* maliste = Initialisation();
		/* La lecture de la matrice des coûts à partir d'un fichier */
		myscanner = Lecture_Initialisation_Remplissage_Matrice(argv[1], mat, m ,n,myscanner);

		mat = myscanner.mat;
		m = myscanner.m;
		n = myscanner.n;

		/* Affichage de la liste chaînée vide */
		printf("\n Affichage de la liste chaînée vide \n");
		Afficher_Liste(maliste);

		/* Remplissage de la liste chaînée depuis la matrice puis affichage de la liste chaînée */
		Insertion_Matrice(maliste,mat,m,n,K);
		printf("\n Affichage de la liste chaînée après une insertion \n");
		Afficher_Liste(maliste);

		/* Suppression de quelques occurences puis affichage de la liste chaînée */
		Suppression_Occurences(maliste, 0);
		printf("\n Affichage de la liste chaînée après une suppression d'occurences de l'usine 0 \n");
		Afficher_Liste(maliste);

		/* Sauvegarde de la liste chaînée dans un fichier */
		Sauver_Dans_Un_Fichier(maliste,"Tests/file_res.txt");

	}
	else
	{

		printf("Veuillez entrer le bon nombre d'arguments!\n");

	}
    return 0;
}
