#define FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
typedef struct coordonneeM{
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
    t_coordonneeM *coordonneeMatrice;
    t_coordonneeG *coordonneeGrille;
    int score;
    int barriere_posees;
    int nbCoupAnnule;
} t_joueur ;






void afficherGrille(int m_tailleX,int m_tailleY);
void color(int couleurDuTexte,int couleurDeFond);
char* saisirChaine();
void lancerNouvellePartie();

void gotoligcol( int lig, int col );

void allerCase(t_coordonneeG *coor);
void placerBarriere(t_coordonneeG *coor,int sens);
t_coordonneeM *coordonneGrilleVersCoordMatrice(t_coordonneeG *coorG);
t_coordonneeG* coordoneeMatriceversCoordGrille(t_coordonneeM * coorM);
void afficherPiondepuisMatrice(t_coordonneeM* coorM, t_joueur *joueur );
t_joueur *creerJoueur(int iemejoueur, int listePionUtilise[8], int taillePlateau);

void lancerNouvellePartie(int nombreJoueur,int taillePlateau,t_joueur *joueur[4]);