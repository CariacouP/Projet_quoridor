#ifndef ALEXIS_H
#define ALEXIS_H
#include "structures.h"


void afficher9(int matrice[17][17]);
void afficher12(int matrice[23][23]);



//void saisieEmplacementJoueur(t_joueur *Ptjoueur);
int verificationDeplacement9(t_joueur joueur , t_coordonneeM coorVoulu,int matrice[17][17]);
int verificationDeplacement12(t_joueur joueur , t_coordonneeM coorVoulu,int matrice[23][23]);

int verifierBarriere9(int i,int j,int i1,int j1,int matrice[17][17]);
int verifierBarriere12(int i,int j,int i1,int j1,int matrice[23][23]);

int PionDansCase9(t_coordonneeM cooraVerif,int matrice[17][17]);
int PionDansCase12(t_coordonneeM cooraVerif,int matrice[23][23]);

//int verifiePassage9(t_coordonneeM coorPion, int matrice[17][17]);

t_joueur deplacerPion9(t_coordonneeM coorVoulu,t_joueur joueur,int matrice[17][17]);
t_joueur deplacerPion12(t_coordonneeM coorVoulu,t_joueur joueur,int matrice[23][23]);


#endif