#ifndef ALEXIS_H
#define ALEXIS_H
#include "structures.h"


void afficher9(int matrice[17][17]);
void afficher12(int matrice[23][23]);

void deplacerPion(t_coordonneeM coorVoulu,t_joueur joueur,int matrice[17][17]);


//void saisieEmplacementJoueur(t_joueur *Ptjoueur);
int verificationDeplacement(t_joueur joueur , t_coordonneeM coorVoulu,int matrice[17][17]);
int verifierBarriere(int i,int j,int i1,int j1,int matrice[17][17]);
int PionDansCase(t_coordonneeM cooraVerif,int matrice[17][17]);

int verifiePassage(t_coordonneeM coorPion, int matrice[17][17]);

#endif