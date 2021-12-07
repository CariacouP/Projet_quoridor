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
        t_joueur joueurs[4];
        system("cls");
        color(0,15);
        printf("Combien de joueurs pour cette partie ?\n");
        fflush(stdin);
        scanf("%d",&nombreJoueur);
        if (nombreJoueur==4){
            do{
                printf("Quelle taille pour le plateau ?\n");
                fflush(stdin);
                scanf("%d",&taillePlateau);
            }while ( (taillePlateau!=9) && (taillePlateau!=12) ); // verifie que la taille du plateau correspond à 9 ou 12
        }
        else {
            taillePlateau=9;
        }
        
        lancerNouvellePartie(nombreJoueur, taillePlateau, joueurs);
        printf("coordonnee du 2eme joeur dans la matrice: ligne : %d colonne: %d, son pion :%d \n",joueurs[1].coordonneeMatrice.ligne,joueurs[1].coordonneeMatrice.colonne, joueurs[1].pionM);

        if (taillePlateau==9){
            int matrice[17][17];
            initialiserMatrice9(matrice,joueurs);
            afficher9(matrice);
            }
        else if (taillePlateau==12) {
            int matrice[23][23];
            initialiserMatrice12(matrice,joueurs);
            afficher12(matrice);
            }
        
        //intitialiation de la matrice dans laquelle seront géréer les deplacements
        
        }


        printf("\n ---C'est parti--- \n");
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
            t_coordonneeG coorG;
            t_coordonneeM coorM;
            t_joueur joueurs[4];
            lancerNouvellePartie(2,9,joueurs);
            printf("\n Nom joueur 1: ");
            puts(joueurs[0].nom);
            printf("\n Nom joueur 2: ");
            puts(joueurs[1].nom);


        break;
        }
    case 7:{
        int plateau[17][17];
        t_joueur joueurs[4];
        //Demander la taille
        initialiserMatrice9(plateau,joueurs);
        deplacerPion(0,0,1,1,plateau);
        afficher9(plateau);
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
