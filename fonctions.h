#ifndef FONCTIONS_H
#define FONCTIONS_H
#include "structures.h"

void afficherGrilleVide(int m_tailleX,int m_tailleY);
void color(int couleurDuTexte,int couleurDeFond);
char* saisirChaine();
void lancerNouvellePartie();

void gotoligcol( int lig, int col );

void allerCase(t_coordonneeG coor);
void placerBarriere(t_coordonneeG coor,int sens);
t_coordonneeM coordonneGrilleVersCoordMatrice(t_coordonneeG coorG);
t_coordonneeG coordoneeMatriceversCoordGrille(t_coordonneeM  coorM);
void afficherPiondepuisMatrice(t_coordonneeM coorM, t_joueur joueur );
void afficherCaseVideDepuisMatrice(t_coordonneeM coorM);
t_joueur creerJoueur(int iemejoueur, t_joueur joueurs[4], int taillePlateau,int nombreJoueur);
t_coordonneeG remplircoordonneeG(int taillePlateau);

void lancerNouvellePartie(int nombreJoueur,int taillePlateau,t_joueur joueur[4]);
t_joueur reinitialiserJoueur(int iemeJoueur, t_joueur joueurs[4],int taillePlateau);

void afficherJeu9(int matrice[17][17],t_joueur listejoueurs[4]);
void afficherJeu12(int matrice[23][23],t_joueur listejoueurs[4]);

int pionsUtilise(t_joueur joueurs[4],int pion);
t_barriereG choixBarrierre(int taillePlateau);

void placerBarriereGdansMatrice9(t_barriereG barriere, int matrice[17][17]);
void placerBarriereGdansMatrice12(t_barriereG barriere, int matrice[23][23]);


void initialiserMatrice9 (int matrice[17][17],t_joueur joueur[4]);
void initialiserMatrice12 (int matrice[23][23],t_joueur joueur[4]);

void enregistrerPartie9(int matrice[17][17], t_joueur joueurs[4],int nombreJoueur );
void enregistrerPartie12(int matrice[23][23], t_joueur joueurs[4],int nombreJoueur );

int jouerSontour9(int iemeJoueur, t_joueur joueurs[4] ,t_joueur joueurCoupPrecedent[4],int nombreJoueur,int taillePlateau, int matrice[17][17],int matricePrecedente[17][17]);
int jouerSontour12(int iemeJoueur, t_joueur joueurs[4] ,t_joueur joueurCoupPrecedent[4],int nombreJoueur,int taillePlateau, int matrice[23][23],int matricePrecedente[23][23]);

int sontCoteAcote(t_coordonneeG case1,t_coordonneeG case2);
int unJoueurEstArrivee(t_joueur joueurs[4],int taillePlateau,int nombreJoueur);

t_joueur changerNombreBarriere(t_joueur joueur,int nbarriere);
t_joueur changerScore(t_joueur joueur,int nouveauScore);
t_joueur copieJoueur(t_joueur joueur);
t_joueur changerNbCoupAnnule(t_joueur joueur,int nouveauNbCOupAnnule);


#endif 