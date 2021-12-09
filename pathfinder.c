#include "structures.h"

int CheckPath( int grid[23][23], int taille, t_joueur joueur, int indexJoueur)
{
    int verifGrid[taille][taille];
    for (int lig=0; lig<taille; lig++)
        {

            for (int col=0; col<taille; col++)
            {
                verifGrid[lig][col] = 0;
            }
        }
    int ligJoueur = joueur.coordonneeMatrice.ligne / 2;
    int colJoueur = joueur.coordonneeMatrice.colonne / 2;
    verifGrid[ligJoueur][colJoueur]=1;
    int nbCelluleModif=0;
    do
    {
        nbCelluleModif=0;
        for (int lig=0; lig<taille; lig++)
        {
            int ligMatrice = lig * 2;
            for (int col=0; col<taille; col++)
            {
                int colMatrice = col * 2;
                if(verifGrid[lig][col] == 0)
                {
                    if((lig > 0 && verifGrid[lig - 1][col] == 1 && grid[ligMatrice - 1][colMatrice] == 0)
                       || (col > 0 && verifGrid[lig][col - 1] == 1 && grid[ligMatrice][colMatrice - 1] == 0)
                       || (lig < taille - 1 && verifGrid[lig + 1][col] == 1 && grid[ligMatrice + 1][colMatrice] == 0)
                       || (col < taille - 1 && verifGrid[lig][col + 1] == 1 && grid[ligMatrice][colMatrice + 1] == 0))
                    {
                        verifGrid[lig][col] = 1;
                        nbCelluleModif++;
                    }
                }
            }
        }
    } while (nbCelluleModif > 0);

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

