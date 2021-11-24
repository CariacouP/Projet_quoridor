#define FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED


void afficherGrille(int m_tailleX,int m_tailleY);
void color(int couleurDuTexte,int couleurDeFond);
char* saisirChaine();
void lancerNouvellePartie();

void gotoligcol( int lig, int col );

void allerCase(char ligne, int colonne);
void placerBarriere(char ligne, int colonne,int sens);