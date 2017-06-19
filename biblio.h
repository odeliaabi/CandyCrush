#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<conio.h>

#define GAUCHE 'q'
#define DROITE 'd'
#define BAS 's'
#define HAUT 'z'

#define ESPACE ' '

#define ROUGE 'R'
#define BLEU 'B'
#define VERT 'V'
#define JAUNE 'J'
#define ORANGE 'O'

#define GRILLE_LIGNES 15
#define GRILLE_COLONNES 15

/// Prototypes des sous programmes

/// rempli aleatoirement une grille donnée
/// @param grille
void remplirAlea(char grille[GRILLE_LIGNES][GRILLE_COLONNES],char couleurs[5]);

void afficherGrille(char grille[GRILLE_LIGNES][GRILLE_COLONNES]);

///remplir tableau de 5 caractères
///@param couleurs
void remplirCouleur(char couleurs[5]);

void Color(int couleurDuTexte,int couleurDeFond);
void gotoligcol(int lig,int col);
void gogotoligcol(int lig, int col);
///sous programme fonction touche (gere la grille enfonction de la touche
///on affiche a chaque fois la grille, 1) gerer la grille 2) afficher grille
///qd on selectionne une case, si cases de la meme couleur on les met en min
///@param la grille, coordonnées du curseur (pointeur), score, groupe (scores = sortie et peuvent varier donc pointeur)
void controler_touche(char grille[GRILLE_LIGNES][GRILLE_COLONNES],int* plig, int* pcol, int* score, int* groupe);
int compare(char grille[GRILLE_LIGNES][GRILLE_COLONNES],int lig, int col, char c);
void afficher_lettre(int lig, int col, char grille[GRILLE_LIGNES][GRILLE_COLONNES]);
char minmaj(char c);
char majuscule(char c);
char minuscule(char c);
void supprimer(char grille[GRILLE_LIGNES][GRILLE_COLONNES]);
void gravite(char grille[GRILLE_LIGNES][GRILLE_COLONNES]);
void colonne(char grille[GRILLE_LIGNES][GRILLE_COLONNES]);

#endif // BIBLIO_H_INCLUDED
