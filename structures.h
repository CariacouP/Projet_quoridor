#ifndef STRUCTURES_H
#define STRUCTURES_H

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


#endif