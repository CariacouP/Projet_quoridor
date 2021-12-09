#include "structures.h"

int CheckPath( int grid[23][23], int taille, t_joueur joueur, int indexJoueur)
{
    return 0;
}

int CheckAllPath (int grid[23][23], int taille, t_joueur joueurs[4], int nbJoueurs)
{
    int nbBlocage=0;
    for (int i=0; i<nbJoueurs; i++)
    {
        nbBlocage += CheckPath(grid, taille, joueurs[i], i );
    }
    return nbBlocage == nbJoueurs;
}

