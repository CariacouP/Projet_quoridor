#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>


#include "alexis.h"
#include "fonctions.h"
int main()
{   int choixMenu;
    char t;



    srand(time(NULL));

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
    printf("6 - afficher tableau\n");
    printf("7 - test programme alexis\n");

    scanf("%d",&choixMenu);
    switch (choixMenu)
    {
    case 1:{// appel de lancerNouvellePartie
        int nombreJoueur;
        int taillePlateau;
        t_joueur* joueurs[4];
        system("cls");
        color(0,15);
        printf("Combien de joueurs pour cette partie ?\n");
        fflush(stdin);
        scanf("%d",&nombreJoueur);
        if (nombreJoueur==4){
            printf("Quelle taille pour le plateau ?\n");
            fflush(stdin);
            scanf("%d",&taillePlateau);
        }
        lancerNouvellePartie(nombreJoueur, taillePlateau, joueurs);

        printf("\n ---C'est parti--- \n");
    }
        break;
    case 2: // appel de lancerPartiesauvegardee
        break;
    case 3: //appel de afficherAide
        break;
    case 4:  //appel de afficherScores
        break;
    case 5: //
        break;
    case 6:{
            t_coordonneeG *coorG;
            t_coordonneeM *coorM;
            coorG->ligne="A";
            coorG->colonne=5;
            coorM=coordonneGrilleVersCoordMatrice(coorG);
            printf("\nligne :");
            printf("%d\n",coorM->ligne);
            printf("colonne :");
            printf("%d",coorM->colonne);
    }

        break;

    case 7:{
        int matrice[17][17];
        //Demander la taille
        initialiserMatrice(matrice);
        deplacerPion(0,0,1,1,matrice);
        afficher(matrice);
        break;
        }
    default:
        printf("le choix selectionne n'existe pas ");
        break;


    }
    fflush(stdin);

    scanf("%c",&t);
    return 0;
}

