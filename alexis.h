#define FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct joueur
{
    char nom[20];
    int pion;
    int positionI;
    int positionJ;
    int score;
    int barriere_posees;
    int nbCoupAnnule;
}t_joueur;

void initialiserPlateau (int plateau[17][17]);
void afficher(int plateau[17][17]);
void deplacerPion(int i,int j,int i1,int j1,int plateau[17][17]);


//void saisieEmplacementJoueur(t_joueur *Ptjoueur);
int verificationDeplacement(int i1,int j1,int plateau[17][17]);
int verifierBarriere(int i,int j,int i1,int j1,int plateau[17][17]);
