#define FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED



void initialiserPlateau (int plateau[17][17]);
void afficher(int plateau[17][17]);
void deplacerPion(int i,int j,int i1,int j1,int plateau[17][17]);


//void saisieEmplacementJoueur(t_joueur *Ptjoueur);
int verificationDeplacement(int i1,int j1,int plateau[17][17]);
int verifierBarriere(int i,int j,int i1,int j1,int plateau[17][17]);
