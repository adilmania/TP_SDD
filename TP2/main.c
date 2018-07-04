#include "./Headers/Gestion_Pile.h"
#include "./Headers/Gestion_File.h"
#include "./Headers/Inversion.h"


int main()
{

	Pile* p    = NULL;
	File* f    = NULL;
	int taille    = 0,
	    i         = 0,
	    val       = 0,
	    err       = 0,
        booleen   = 0,
        x         = 0;
    
    printf("\n Pour procéder à la suite, entrez la taille nécessaire pour stocker vos données: ");
    scanf("%d",&taille);
    p = Init(taille);
    f = init_file(taille);
	do{
		printf("\n-------------------------Menu-------------------------\n");
		printf("|1- Entrez 1 pour afficher la pile;                   |\n");
		printf("|2- Entrez 2 pour afficher la file;                   |\n");
		printf("|3- Entrez 3 pour empiler des éléments dans la pile;  |\n");
		printf("|4- Entrez 4 pour enfiler des éléments dans la file;  |\n");
		printf("|5- Entrez 5 pour dépiler un élément de la pile;      |\n");
		printf("|6- Entrez 6 pour défiler un élément de la file;      |\n");
		printf("|7- Entrez 7 pour afficher le sommet d'une pile;      |\n");
		printf("|8- Entrez 8 pour vérifier si la pile est vide;       |\n");
		printf("|9- Entrez 9 pour vérifier si la file est vide;       |\n");
		printf("|10-Entrez 10 pour inverser une pile;                 |\n");
		printf("|0- Entrez 0 pour quitter  	         	      |\n");
		printf("------------------------------------------------------\n");
		
		do{
			scanf("%d",&x);
		}while(x<0 || x>10);
		err = 0;
		
		switch(x){
			case 1:
				afficher_pile(*p);
				break;
			case 2:
				afficher_file(*f);
				break;
			case 3:
			    printf("\nEntrez l'élément à empiler: ");
			    scanf("%d",&i);
				empiler(p,i,&err);
				if(err)
					printf("Erreur: la pile est pleine.\n");
				else
					afficher_pile(*p);
				break;
			case 4:
				printf("\nEntrez l'élément à enfiler: ");
			    scanf("%d",&i);
				enfiler(f,i,&err);
				if(err)
					printf("Erreur: la file est pleine.\n");
				else
					afficher_file(*f);
				break;
			case 5:
				val = depiler(p,&err);
				if(err)
					printf("Erreur: la pile est vide.\n");
				else
				{
					afficher_pile(*p);
					printf("\n La valeur dépilée est: %d",val);
				}
				break;
			case 6:
				val = defiler(f,&err);
				if(err)
					printf("Erreur: la file est vide.\n");
				else
				{
					afficher_file(*f);
					printf("\n La valeur défilée est %d",val);
				}
				break;
			case 7:
				val = sommet(p,&err);
				if(err)
					printf("Erreur: la pile est vide.\n");
				else
					printf("\n La valeur du sommet est: %d",val);
				break;
			case 8:
				booleen = est_vide_p(p);
				if(booleen)
					printf("La pile est vide.\n");
				else
				{
					printf("La pile est non vide.\n");
					afficher_pile(*p);
				}
				break;
			case 9:
				booleen = est_vide_f(*f);
				if(booleen)
					printf("La file est vide.\n");
				else
				{
					printf("La file est non vide.\n");
					afficher_file(*f);
				}
				break;
			case 10:
				inversion(p,f);
				afficher_pile(*p);
				break;
			}
	
	}while(x);
    LibererPile(p);
    liberer_file(f);
	return 0;
     
}
