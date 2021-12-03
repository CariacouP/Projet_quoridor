#define FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED


void afficherGrille(int m_tailleX,int m_tailleY);
void color(int couleurDuTexte,int couleurDeFond);
char* saisirChaine();
void lancerNouvellePartie();

void gotoligcol( int lig, int col );

void allerCase(char ligne, int colonne);
void placerBarriere(char ligne, int colonne,int sens);
void coordonneGrilleVersCoordMatrice(char ligneGrille, int colonneGrille,t_coordoneeM * coor);
void coordoneeMtriceversCoordGrille(char ligneGrille, int colonneGrille,t_coordoneeM * coor)

typedef struct coordoneeM{
    int ligne;
    int colonne;
}t_coordonneeM;

typedef struct coordoneeG{
    char ligne ;
    int colonne;
}t_coordonneeG;

typedef struct joueur
{
    char nom[20];
    int pion;
    t_coordonneeM coordonneeMatrice;
    t_coordonneeG coordoneeGrille;
    int score;
    int barriere_posees;
    int nbCoupAnnule;
} t_joueur ;