#include "structures.h"

int CheckPath( int grid[23][23], int taille, t_joueur joueur)
{
    int verifGrid[taille][taille];          // je cr�e un tableau imaginaire de la meme dimension que celle du jeu actuel
    for (int lig = 0; lig < taille; lig ++)          //je parcours les lignes
        {

            for (int col = 0; col < taille; col ++)          //je parcours les colonnes
            {
                verifGrid[lig][col] = 0;            // j'initialise chaque case � 0
            }
        }
    int ligJoueur = joueur.coordonneeMatrice.ligne / 2;         //comme pour les lignes c'est un char j'ai du traduire en chiffre
    int colJoueur = joueur.coordonneeMatrice.colonne / 2;
    verifGrid[ligJoueur][colJoueur]=1;                      // la ou le joueur se trouve je place un 1
    int nbCelluleModif=0;                                   // j'initialise le nombre de cellule du tableau avec des 0 modifi�es
    do
    {
        nbCelluleModif=0;
        for (int lig = 0; lig < taille; lig ++)              //je parcours les lignes du tableau
        {
            int ligMatrice = lig * 2;                   // je convertis dans la matrice
            for (int col = 0; col < taille; col ++)              // je parcours les colonnes du tableau
            {
                int colMatrice = col * 2;               // je convertis les colonnes dans la matrice
                if(verifGrid[lig][col] == 0)                // Si sur une case il y a un 0
                {
                    if((lig > 0 && verifGrid[lig - 1][col] == 1 && ligMatrice > 0 && grid[ligMatrice - 1][colMatrice] == 0)     // je v�rifie qu'on n'est pas tout � gauche, tout en bas, tout � droite ou tout en haut du plateau, que le joueur peut venir � c�t� de cette case mais aussi qu'il n'y a pas de barri�re autour
                       || (col > 0 && verifGrid[lig][col - 1] == 1 && colMatrice > 0 && grid[ligMatrice][colMatrice - 1] == 0)
                       || (lig < taille - 1 && verifGrid[lig + 1][col] == 1 && ligMatrice < taille * 2 - 1 && grid[ligMatrice + 1][colMatrice] == 0)
                       || (col < taille - 1 && verifGrid[lig][col + 1] == 1 && colMatrice < taille * 2 - 1 && grid[ligMatrice][colMatrice + 1] == 0))
                    {
                        verifGrid[lig][col] = 1;            // si une de ces conditions est v�rifi�e alors je marque la case d'un 1 pour dire que le joueur peut venir sur cette case
                        nbCelluleModif++;                   // j'incr�mente la valeur nombre de cellule modifi�e de 1
                    }
                }
            }
        }
    } while (nbCelluleModif > 0);               // tant qu'une cellule est modifi�e je continue

/*    for (col)
    {
        if (indexJoueur == 1  && verifGrid[8][col] == 1)
        {
            printf("Le joueur n'est pas bloque \n");
        }
        else
        {
            printf("Le joueur est bloque \n");
        }
    }
    return 0;*/
}

int CheckAllPath (int grid[23][23], int taille, t_joueur joueurs[4], int nbJoueurs) //Verification du chemin pour les 4 joueurs
{
    int nbBlocage = 0;                                            //nombre de joueurs bloqu�s
    for (int i = 0; i < nbJoueurs; i ++)
    {
       
        nbBlocage += CheckPath(grid, taille, joueurs[i] );
    }
    return nbBlocage == nbJoueurs;                              // si le nombre de blocage est egal aux nombres de joueurs le jeu s'arrete
}
