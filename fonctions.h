#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
typedef struct Plateau Plateau;
struct Plateau
{
    int m_tailleX;
    int m_tailleY;
    int score;
    char** matrice;
};

typedef struct joueur
{
    char* nom;
    int jeton;


}

void afficherGrille(Plateau *plateau);
void color(int couleurDuTexte,int couleurDeFond);
char* saisirChaine();
void lancerNouvellePartie();

void gotoligcol( int lig, int col );
#endif // FONCTIONS_H_INCLUDED
