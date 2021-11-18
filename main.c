#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>


#include "fonctions.h"
int main()
{
    int choixMenu;




    srand(time(NULL))

    /*Plateau *p;
    p=malloc(sizeof(*p));
    p->m_tailleX=10;
    p->m_tailleY=10;
    afficherGrille(p);*/


/// affichage du menu d'entr�e
    system("cls");
    color(0,15);
    printf("Bienvenu dans Quoridor !");
    printf("\n -- Menu -- \n");
    printf("1 - Lancer une nouvelle partie\n");
    printf("2 - reprendre une partie sauvegard�e\n");
    printf("3 - Afficher l'aide\n");
    printf("4 - Afficher les scores des joueurs\n");
    printf("5 - Quitter le jeu\n");

    switch (choixMenu)
    {
    case 1:// appel de lancerNouvellePartie
        afficherGrille(12,12);
        break;
    case 2: // appel de lancerPartiesauvegardee
        break;
    case 3: //appel de afficherAide
        break;
    case 4:  //appel de afficherScores
        break;
    case 5: //
        break;
    default:
        printf("le chox selectionn� n'existe pas ");
        break;

    }


    return 0;
}
