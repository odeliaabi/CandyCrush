#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"
#include <time.h>
#include <windows.h> ///gotoligcol()


int main()
{
    //declarer les 2 emetteurs pour les 2 tableaux

    char matrice[GRILLE_LIGNES][GRILLE_COLONNES];//emetteur pour la grille

    char color[5];//emetteur pour la colonne
    // appeler les 3 sous programmes: remplir tableau, remplir,alea, affricher grille)
    int tailleGroupe, groupe, lig, col,score;
    score=0;
    groupe=0;
    tailleGroupe=0;
    lig = 7;
    col =7;

    srand(time(NULL));
    remplirCouleur(color);// quand les noms sont differents entre brickletter et main, appeler la fonction et mettre entres parentheses le nom donne  en tant que parametre
    remplirAlea(matrice,color);
    ///do while
    afficherGrille(matrice);
    ///afficherscore(groupe,tailleGroupe);
    do
    {

     controler_touche(matrice,&score,&groupe,&lig,&col);


    }
    while(1==1);







    return 0;
}
