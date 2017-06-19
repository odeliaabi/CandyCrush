#include "biblio.h"


///aleatoirement choisir un numéro de case du tableau couleurs
void remplirAlea(char grille[GRILLE_LIGNES][GRILLE_COLONNES],char couleurs[5])
{
    int alea;
    /*rand() donne un nombre aleatoire donc si on veut un aleatoire entre un min et un max :
    rand()%(max-min+1)+min*/
    int i,j;
    for(j=0; j<GRILLE_COLONNES; j++)
    {
        for(i=0; i<GRILLE_LIGNES; i++)
        {
            alea=rand()%5;
            grille[i][j]=couleurs[alea];
        }
    }
}



void afficherGrille(char grille[GRILLE_LIGNES][GRILLE_COLONNES])
{
    int i,j;

    for(i=0; i<GRILLE_LIGNES; i++)
    {

        for(j=0; j<GRILLE_COLONNES; j++)

        {

            if(grille[i][j]==BLEU)
            {
                Color(9,0);
                printf("%c ",grille[i][j]);
                Color(7,0);
            }

            if(grille[i][j]==VERT)
            {
                Color(10,0);
                printf("%c ",grille[i][j]);
                Color(7,0);
            }

            if(grille[i][j]==ROUGE)
            {
                Color(12,0);
                printf("%c ",grille[i][j]);
                Color(7,0);
            }

            if(grille[i][j]==JAUNE)
            {
                Color(14,0);
                printf("%c ",grille[i][j]);
                Color(7,0);
            }

            if(grille[i][j]==ORANGE)
            {
                Color(13,0);
                printf("%c ",grille[i][j]);
                Color(7,0);
            }

        }
        printf("\n");
    }
}



void remplirCouleur(char couleurs[5])
{
    couleurs[0]=ROUGE;
    couleurs[1]=BLEU;
    couleurs[2]=VERT;
    couleurs[3]=JAUNE;
    couleurs[4]=ORANGE;
}



void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
///9B 10Vert 12R 13Violet 14J

void gotoligcol(int lig,int col)
{
    COORD mycoord;
    mycoord.X=col;
    mycoord.Y=lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),mycoord);
}

void gogotoligcol(int lig, int col)
{
    gotoligcol(lig,(col*2));
}

void afficher_lettre(int lig, int col,char grille[lig][col])
{
    gogotoligcol(lig,col);
    if((grille[lig][col]==BLEU)||((minmaj(grille[lig][col]))==BLEU))
    {
        Color(9,0);
        printf("%c ",grille[lig][col]);
        Color(7,0);
    }
    if((grille[lig][col]==VERT)||((minmaj(grille[lig][col]))==VERT))
    {
        Color(10,0);
        printf("%c ",grille[lig][col]);
        Color(7,0);
    }
    if((grille[lig][col]==ROUGE)||((minmaj(grille[lig][col]))==ROUGE))
    {
        Color(12,0);
        printf("%c ",grille[lig][col]);
        Color(7,0);
    }
    if((grille[lig][col]==JAUNE)||((minmaj(grille[lig][col]))==JAUNE))
    {
        Color(14,0);
        printf("%c ",grille[lig][col]);
        Color(7,0);
    }
    if((grille[lig][col]==ORANGE)||((minmaj(grille[lig][col]))==ORANGE))
    {
        Color(13,0);
        printf("%c ",grille[lig][col]);
        Color(7,0);
    }
}

int compare(char grille[GRILLE_LIGNES][GRILLE_COLONNES],int lig, int col, char c)
{
    int tailleGroupe=0;
    int score=0;

    if(grille[lig][col]==c)
    {
        tailleGroupe++;
        grille[lig][col]=minmaj(grille[lig][col]);
        ///afficherscore(score,tailleGroupe);
        gogotoligcol(lig,col);
        printf("%c ",grille[lig][col]);


        if(col<GRILLE_COLONNES-1)
        {
            tailleGroupe += compare(grille,lig,col+1,c);
        }
        if(lig<GRILLE_LIGNES-1)
        {
            tailleGroupe += compare(grille,lig+1,col,c);
        }
        if(col>0)
        {
            tailleGroupe += compare(grille,lig,col-1,c);
        }
        if(lig>0)
        {
            tailleGroupe += compare(grille,lig-1,col,c);
        }

         gogotoligcol(lig,col);

    }
    return (tailleGroupe+1);

   }



void controler_touche(char grille[GRILLE_LIGNES][GRILLE_COLONNES],int* plig, int* pcol, int* pscore, int* pgroupe)
{
    char touche;
    ///fonction qui detecte si on a tapé sur une touche du clavier
    if (kbhit())///fonction : saisir une touche mais sans l'afficher
    {
        touche = getch();
        if((touche==DROITE)||(touche==GAUCHE)||(touche==HAUT)||(touche==BAS))
        {
            ///si touche est GAUCHE et qu'on est pas au bord..
            if ((touche==GAUCHE)&&(*pcol>0))
            {
                (*pcol)--;///Mais pas *pcol-- car * prio sur -
            }
            if ((touche==DROITE)&&(*pcol<14))
            {
                (*pcol)++;
            }
            if ((touche==HAUT)&&(*plig>0))///Pas *pcol mais *pcol*2
            {
                (*plig)--;
            }
            if ((touche==BAS)&&(*plig<14))
            {
                (*plig)++;
            }
            gogotoligcol(*plig,*pcol);
        }
        if((touche==ESPACE)&&((grille[*plig][*pcol]>='A')&&(grille[*plig][*pcol]<='Z')))
        {
           compare(grille,*plig,*pcol,grille[*plig][*pcol]);

            ///detecter un groupe (identique à cette lettre) Attention compliqué avec les SP Supprimer un group et Gravité
            ///si groupe transformation en minuscule
            //compare(grille,*plig,*pcol,grille[*plig][*pcol]);
        }
        else if ((touche==ESPACE)&&((grille[*plig][*pcol]>='a')&&(grille[*plig][*pcol]<='z')))
        {
            supprimer(grille);
            gravite(grille);
            colonne(grille);

        }
        ///si on appuie sur espace Et qu'il y a un groupe en min, le supprimer
    }
}

char minuscule(char c)
{
    return c-'A'+'a';
}

char majuscule(char c)
{
    return c-'a'+'A';
}

char minmaj(char c)
{
    if((c>='a')&&(c<='z'))
    {
        c-= 'a' - 'A';
    }
    if((c>='A')&&(c<='Z'))
    {
        c+= 'a' - 'A';
    }
    return c;
}

void supprimer(char grille[GRILLE_LIGNES][GRILLE_COLONNES])
{
    int i,j;
    for(i=0; i<GRILLE_LIGNES; i++)
    {
        for(j=0; j<GRILLE_COLONNES; j++)
        {
            if((grille[i][j]>='a')&&(grille[i][j]<='z'))
            {
                grille[i][j]=' ';
                gogotoligcol(i,j);
                printf("%c ",grille[i][j]);
            }
        }
    }
}

void gravite(char grille[GRILLE_LIGNES][GRILLE_COLONNES])
{
int i, j, k;
for(k=0;k<GRILLE_LIGNES;k++)
{

     for(j=0;j<GRILLE_COLONNES;j++)
    {
       for(i=0;i<GRILLE_LIGNES;i++)
        {
            if((i==0)&&(grille[i+1][j]==' '))
            {
                grille[i][j]=' ';
                gogotoligcol(i,j);
                printf("%c ",grille[i][j]);
            }
           else if (grille[i][j]==' ')
            {
                grille[i][j]=grille[i-1][j];
                grille[i-1][j]=' ';
                gogotoligcol(i,j);
                printf("%c ",grille[i][j]);

            }
        }
    }

}


}


void colonne(char grille[GRILLE_LIGNES][GRILLE_COLONNES])
{
int i, j, k;
for(k=0;k<GRILLE_COLONNES;k++)
{

   for(j=0;j<GRILLE_COLONNES;j++)
    {
        for(i=0;i<=GRILLE_LIGNES;i++)
        {
            if((j==0)&&(grille[i][j+1]==' '))
            {
                grille[i][j+1]=grille[i][j];
                grille[i][j]=' ';
                gogotoligcol(i,j);
                printf("%c ",grille[i][j]);
            }

           else if (grille[i][j]==' ')
            {
                grille[i][j]=grille[i][j-1];
                grille[i][j-1]=' ';
                gogotoligcol(i,j);
                printf("%c ",grille[i][j]);

            }
        }
    }

}
}


