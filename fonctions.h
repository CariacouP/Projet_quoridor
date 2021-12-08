#ifndef FONCTIONS_H
#define FONCTIONS_H
#include "structures.h"

/*typedef struct coordonneeM{
    int ligne;
    int colonne;
}t_coordonneeM;

typedef struct coordonneeG{
    char ligne ;
    int colonne;
}t_coordonneeG;

typedef struct joueur
{
    char nom[20];
    int pion;
    int pionM;
    t_coordonneeM coordonneeMatrice;
    t_coordonneeG coordonneeGrille;
    int score;
    int barriere_posees;
    int nbCoupAnnule;
} t_joueur ;

typedef struct barriereG{
    //objet barrière de de case de long, on donne le couple de coordoonée sur la matrice qui correspond
    t_coordonneeG coorG1;
    t_coordonneeG coorG2;
    int sens   ; // sens dans lequel sera posé la barrière (en haut (1), à droite (2), en bas (3), gauche(4))

}t_barriereG;
*/







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
t_joueur creerJoueur(int iemejoueur, int listePionUtilise[8], int taillePlateau);
t_coordonneeG remplircoordonneeG(int taillePlateau);

void lancerNouvellePartie(int nombreJoueur,int taillePlateau,t_joueur joueur[4]);

void afficherJeu9(int matrice[17][17],t_joueur listejoueurs[4]);
void afficherJeu12(int matrice[23][23],t_joueur listejoueurs[4]);

int pionsUtilise(int listePionsUtilise[8],int pion);
t_barriereG choixBarrierre(int taillePlateau);
void placerBarriereGdansMatrice(t_barriereG barriere, int matrice[17][17]);
void initialiserMatrice9 (int matrice[17][17],t_joueur joueur[4]);
void initialiserMatrice12 (int matrice[23][23],t_joueur joueur[4]);
void enregistrerPartie9(int matrice[17][17], t_joueur joueurs[4],int nombreJoueur );
void jouerSontour9(int iemeJoueur, t_joueur joueurs[4] ,int nombreJoueur,int taillePlateau,int matrice[17][17]);


#endif 