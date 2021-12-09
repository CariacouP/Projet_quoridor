#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#include "structures.h"
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
        int matrice9[17][17];
        int matrice12[23][23];
        t_coordonneeM coorNouvelle;
        t_barriereG barriere;
        
        
        t_joueur joueurs[4];
        system("cls");
        color(0,15);
        printf("Combien de joueurs pour cette partie ?\n");
        do{
            fflush(stdin);
            scanf("%d",&nombreJoueur);
        }while (nombreJoueur!=2 && nombreJoueur!=4);
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
        //intitialiation de la matrice dans laquelle seront géréer les deplacements
        if (taillePlateau==9){
            
            initialiserMatrice9(matrice9,joueurs);
            
            }
        else if (taillePlateau==12) {
            
            initialiserMatrice12(matrice12,joueurs);
            }
        afficherGrilleVide(taillePlateau,taillePlateau);
        if (taillePlateau==9){
            afficherJeu9(matrice9,joueurs);
        }
        else if (taillePlateau==12){
            afficherJeu12(matrice12,joueurs);

        }
        
        //coorNouvelle=coordonneGrilleVersCoordMatrice( remplircoordonneeG(taillePlateau));
        
        //deplacerPion9(coorNouvelle,joueurs[0],matrice9);
       // barriere=choixBarrierre(taillePlateau);
        //placerBarriereGdansMatrice(barriere,matrice9);
        
        
        //afficherJeu9(matrice9,joueurs);

        jouerSontour9(1, joueurs ,nombreJoueur,taillePlateau,  matrice9);
        
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
        



        break;
        }
    case 7:{
        int plateau[17][17];
        t_joueur joueurs[4];
        //Demander la taille
        initialiserMatrice9(plateau,joueurs);
        //deplacerPion(0,0,1,1,plateau);
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
