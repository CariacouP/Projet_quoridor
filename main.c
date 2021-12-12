#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#include "structures.h"
#include "alexis.h"
#include "fonctions.h"
#include "pathfinder.h"

int main()
{   int choixMenu;
    int i=1;
    char t;



    srand(time(NULL));

    /*Plateau *p;
    p=malloc(sizeof(*p));
    p->m_tailleX=10;
    p->m_tailleY=10;
    afficherGrille(p);*/


/// affichage du menu d'entree
    system("cls");
    color(0,15);
    printf("Bienvenue dans Quoridor !");
    printf("\n -- Menu -- \n");
    printf("1 - Lancer une nouvelle partie\n");
    printf("2 - Reprendre une partie sauvegardee\n");
    printf("3 - Afficher l'aide\n");
    printf("4 - Afficher les scores des joueurs\n");
    printf("5 - Quitter le jeu\n");
    printf("6 - Afficher tableau\n");
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
        int blocage=0;
        do {
            blocage=CheckAllPath(matrice9, taillePlateau, joueurs, nombreJoueur);
            jouerSontour9(i, joueurs ,nombreJoueur,taillePlateau,  matrice9);
            gotoligcol(46,60);
            printf("coordonnees du joueur dans la matrice :  %d; %d",joueurs[i-1].coordonneeMatrice.ligne,joueurs[i-1].coordonneeMatrice.colonne);
            printf("coordonnees du joueur sur la grille :  %c; %d",joueurs[i-1].coordonneeGrille.ligne,joueurs[i-1].coordonneeGrille.colonne);

            i++;
            if (i>nombreJoueur){
                i=1;
            }

        }while(unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)==0 && blocage==0);
    }
        break;


    case 2: // appel de lancerPartiesauvegardee
        break;
    case 3: //appel de afficherAide
        {
        printf("Ce jeu se joue sur un plateau. Le but est d atteindre en premier le bord oppose a sa ligne de depart. \n");
        printf("En debut de partie, les barrieres sont remisees dans leur zone de stockage. \n");
        printf("Chaque joueur pose son pion au centre de sa ligne de depart (la premiere ligne face a lui). Un tirage au sort determine qui commence.\n");
        printf("A tour de role, chaque joueur choisit : de deplacer son pion d une case verticalement ou horizontalement, en avant ou en arriere\n");
        printf("de poser une de ses barrieres. Une barriere doit etre posee exactement entre deux blocs de 2 cases.\n");
        printf("Lorsqu il n a plus de barrieres, un joueur est oblige de deplacer son pion.\n");
        printf("La pose des barrieres a pour but de se creer son propre chemin ou de ralentir l adversaire, mais il est interdit de l enfermer dans une case.\n");
        printf("Quand 2 pions se retrouvent en vis a vis sur 2 cases voisines non separees par une barriere, le joueur dont c est le tour peut sauter par dessus son adversaire et se retrouver derriere lui.\n");
        printf("Si une barriere se trouve derriere le pion saute, le joueur peut choisir de bifurquer a droite ou a gauche du pion saute.\n");
        printf("Pour une partie a 4, en debut de partie, les 4 pions sont disposes au centre de chacun des 4 cotes du plateau et chaque joueur dispose de 5 barrieres.\n");
        printf("Les regles sont strictement identiques, mais on ne peut pas sauter plus d un pion a la fois.\n");
        }

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
