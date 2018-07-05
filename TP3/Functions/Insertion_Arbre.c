#include "../Headers/Insertion_Arbre.h"
#include "../Headers/Gestion_File.h"

/**
 * \file      Insertion_Arbre.c					
 * \author    Rousset & Mania
 * \date      12 March 2018
 * \brief     Définit les fonctions nécessaires pour l'insertion d'un
 *            caractère dans un arbre fournit.
**/

/* ----------------------Recherche_Valeur----------------------------
* Fonction qui recherche une valeur dans un arbre trié

* Entrée :
 * t : Pointeur sur la tête de l'arbre. 
 * valeur	: la valeur à chercher.

* Sortie :
 * res : Pointeur sur la valeur si elle est trouvée, sinon NULL.
* ------------------------------------------------------------------ */

Element* Recherche_Valeur(Element ** t, char valeur){
	
  int FIN = 0;
  int BOOL = 0;
  int Err = 0;

  Element* pt_cour = *t;
  Element* pt_prec = *t;
  Element* res = NULL;
  Element* temp = NULL;

  File* file = init_file(TAILLE);

  while( !FIN && !BOOL )
  {

    while( pt_cour != NULL )
    {

      if( pt_cour->valeur == valeur )
      {
        BOOL = 1;
        res = pt_prec; 
      }

      if ( (pt_cour->lv) != NULL )
      {
        enfiler(file, pt_cour, &Err);
      }
      pt_cour = pt_cour->lh;

    }
    
    if( !est_vide_f(*file) )
    {
      temp = defiler(file, &Err);
      pt_prec = temp;
      pt_cour = (temp->lv);
    }
    else
    {
      FIN = 1;
    }

  }

  liberer_file(file);
  return res; 

}

/* ----------------------Parcours_Triee_Fils----------------------------
* Fonction qui fait le parcours des fils triés d'un père donné en 
  s'arrêtant dès qu'on trouve la valeur à chercher

* Entrée :
 * pere : Pointeur sur la tête de l'arbre. 
 * valeur	: la valeur à chercher.

* Sortie :
 * pt_prec : un pointeur sur la case précédente par rapport à celle trouvée
* ------------------------------------------------------------------ */

Element * Parcours_Triee_Fils(Element* pere, char valeur){

  Element* pt_cour = (pere->lv);
  Element* pt_prec = NULL;

  while ( pt_cour != NULL && ((pt_cour)->valeur) < valeur )
  {

    pt_prec = pt_cour;
    pt_cour = ((pt_cour)->lh) ;

  }

  return pt_prec;

}


/* ----------------------Insertion_Triee----------------------------
* Fonction d'insertion d'un caractère dans un arbre

* Entrée :
 * t : Pointeur sur la tête de l'arbre. 
 * W	: le caractère à insérer.
 * V : le caractère à chercher.

* Sortie :
 * Aucune.
* ------------------------------------------------------------------ */

void Insertion_Triee(Element ** t, char W, char V)
{

  Element* pere = NULL;
  Element* fils = NULL;
  Element* nouveau = NULL;

  pere = Recherche_Valeur(t, V);

  if( pere != NULL )
  {

    fils = Parcours_Triee_Fils(pere,W);
    nouveau = Creation_Cellule(W);

    if( fils == NULL )
    {
      nouveau->lh = pere->lv;
      pere->lv = nouveau;
    }
    else
    {
      nouveau->lh = fils->lh;
      fils->lh = nouveau;  
    }

  }

}