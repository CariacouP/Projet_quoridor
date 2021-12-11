#include "structures.h"

int CheckPath( int grid[23][23], int taille, t_joueur joueur, int indexJoueur)
{
    int verifGrid[taille][taille];          // on crée un tableau imaginaire de la meme dimension que celle du jeu actuel
    for (int lig=0; lig<taille; lig++)          //on parcourt les lignes
        {

            for (int col=0; col<taille; col++)          //on parcourt les colonnes
            {
                verifGrid[lig][col] = 0;            // on initialise chaque case à 0
            }
        }
    int ligJoueur = joueur.coordonneeMatrice.ligne / 2;         //comme pour les lignes c'est un char j'ai du traduire en chiffre
    int colJoueur = joueur.coordonneeMatrice.colonne / 2;
    verifGrid[ligJoueur][colJoueur]=1;                      // la ou le joueur se trouve je place un 1
    int nbCelluleModif=0;                                   // j'initialise le nombre de cellule du tableau avec des 0 modifiées
    do
    {
        nbCelluleModif=0;
        for (int lig=0; lig<taille; lig++)              //je parcours les lignes du tableau
        {
            int ligMatrice = lig * 2;                   // je convertis dans la matrice
            for (int col=0; col<taille; col++)              // je parcours les colonnes du tableau
            {
                int colMatrice = col * 2;               // je convertis les colonnes dans la matrice
                if(verifGrid[lig][col] == 0)                // Si sur une case il y a un 0
                {
                    if((lig > 0 && verifGrid[lig - 1][col] == 1 && ligMatrice > 0 && grid[ligMatrice - 1][colMatrice] == 0)     // je vérifie qu'on n'est pas tout à gauche, tout en bas, tout à droite ou tout en haut du plateau, que le joueur peut venir à côté de cette case mais aussi qu'il n'y a pas de barrière autour
                       || (col > 0 && verifGrid[lig][col - 1] == 1 && colMatrice > 0 && grid[ligMatrice][colMatrice - 1] == 0)
                       || (lig < taille - 1 && verifGrid[lig + 1][col] == 1 && ligMatrice < taille * 2 - 1 && grid[ligMatrice + 1][colMatrice] == 0)
                       || (col < taille - 1 && verifGrid[lig][col + 1] == 1 && colMatrice < taille * 2 - 1 && grid[ligMatrice][colMatrice + 1] == 0))
                    {
                        verifGrid[lig][col] = 1;            // si une de ces conditions est vérifiée alors je marque la case d'un 1 pour dire que le joueur peut venir sur cette case
                        nbCelluleModif++;                   // j'incrémente la valeur nombre de cellule modifiée de 1
                    }
                }
            }
        }
    } while (nbCelluleModif > 0);               // tant qu'une cellule est modifiée je continue

    if
    return 0;
}

int CheckAllPath (int grid[23][23], int taille, t_joueur joueurs[4], int nbJoueurs) //Verification du chemin pour les 4 joueurs
{
    int nbBlocage=0;                                            //nombre de joueurs bloqués
    for (int i=0; i<nbJoueurs; i++)
    {
        nbBlocage += CheckPath(grid, taille, joueurs[i], i );       //on ajoute un chaque fois qu'un joueur est bloque
    }
    return nbBlocage == nbJoueurs;                              // si le nombre de blocage est egal aux nombres de joueurs le jeu s'arrete
}

