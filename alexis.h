#define FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED



void afficher9(int matrice[17][17]);
void afficher12(int matrice[23][23]);

void deplacerPion(int i,int j,int i1,int j1,int matrice[17][17]);


//void saisieEmplacementJoueur(t_joueur *Ptjoueur);
int verificationDeplacement(int i1,int j1,int matrice[17][17]);
int verifierBarriere(int i,int j,int i1,int j1,int matrice[17][17]);
int PionDansCase(int i1,int j1,int matrice[17][17]);

int verifiePassage(int i, int j, int matrice[17][17]);
