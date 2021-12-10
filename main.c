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
    int quitter=0;
    char t;



    srand(time(NULL));

    /*Plateau *p;
    p=malloc(sizeof(*p));
    p->m_tailleX=10;
    p->m_tailleY=10;
    afficherGrille(p);*/


/// affichage du menu d'entr�e
    do {
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
            int rejouer;
            int memoire=1;
            int matrice9[17][17];
            int premiereSauvegardeMatrice9[17][17];
            int deuxiemeSauvegardeMatrice9[17][17];
            int matrice12[23][23];
            int premiereSauvegardeMatrice12[23][23];
            int deuxiemeSauvegardeMatrice12[23][23];
            t_coordonneeM coorNouvelle;
            t_barriereG barriere;
            t_joueur joueurs[4];
            t_joueur premiereSauvegardeJoueur[4];
            t_joueur deuxiemeSauvegardeJoueur[4];
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
            
                do {
                i= rand() % (nombreJoueur-1 + 1) + 1;
                if (taillePlateau==9){

                    initialiserMatrice9(matrice9,joueurs);
                    afficherJeu9(matrice9,joueurs);
                    int blocage=0;
                    
                    do {
                        if (memoire==1){
                            blocage=CheckAllPath(matrice9, taillePlateau, joueurs, nombreJoueur);
                            
                            for (int j=0; j<4;j++){
                                premiereSauvegardeJoueur[j]=copieJoueur(joueurs[j]);
                            }

                            for(int l=0;l<17;l++){
                                for (int k=0;k<17;k++){
                                    premiereSauvegardeMatrice9[l][k]=matrice9[l][k];
                                }
                            }
                            
                            jouerSontour9(i, joueurs ,deuxiemeSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice9,deuxiemeSauvegardeMatrice9);
                            memoire=2;
                            gotoligcol(46,60);
                            if (blocage>0){
                                for (int j=0; j<4;j++){
                                joueurs[j]=copieJoueur(premiereSauvegardeJoueur[j]);
                                }

                                for(int l=0;l<17;l++){
                                    for (int k=0;k<17;k++){
                                    matrice9[l][k]= premiereSauvegardeMatrice9[l][k];
                                    }
                                }
                                gotoligcol(26,60);
                                printf("le chemin est bloqué veuillez rejouer");
                                jouerSontour9(i, joueurs ,deuxiemeSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice9,deuxiemeSauvegardeMatrice9);

                            }
                        }

                        else if (memoire==2){
                            blocage=CheckAllPath(matrice9, taillePlateau, joueurs, nombreJoueur);
                            
                            for (int j=0; j<4;j++){
                                deuxiemeSauvegardeJoueur[j]=copieJoueur(joueurs[j]);
                            }

                            for(int l=0;l<17;l++){
                                for (int k=0;k<17;k++){
                                    deuxiemeSauvegardeMatrice9[l][k]=matrice9[l][k];
                                }
                            }
                            
                            jouerSontour9(i, joueurs ,premiereSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice9,premiereSauvegardeMatrice9);
                            memoire=1;

                            if (blocage>0){
                                for (int j=0; j<4;j++){
                                joueurs[j]=copieJoueur(deuxiemeSauvegardeJoueur[j]);
                                }

                                for(int l=0;l<17;l++){
                                    for (int k=0;k<17;k++){
                                    matrice9[l][k]=  deuxiemeSauvegardeMatrice9[l][k];
                                    }
                                }
                                gotoligcol(26,60);
                                printf("le chemin est bloqué veuillez rejouer");
                                jouerSontour9(i, joueurs ,premiereSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice9,premiereSauvegardeMatrice9);

                            }  
                        } 

                        i++;

                        if (i>nombreJoueur){
                            i=1;
                        }

                        

                    }while(unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)==0 );

                    if (unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)!=0){
                         gotoligcol(26,60);
                        joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1]=changerScore(joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1],joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1].score+5);
                        printf("%s a remporté cette manche !",joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1].nom);
                        gotoligcol(27,60);
                        printf("voulez vous continuer à jouer ?  -1-oui  -2-non :");
                        scanf("%d",&rejouer);

                    }

                
                }

                    
                else if (taillePlateau==12) {
                    initialiserMatrice12(matrice12,joueurs);
                    afficherJeu12(matrice12,joueurs);
                    int blocage=0;
                    do {
                        if (memoire==1){
                            blocage=CheckAllPath(matrice12, taillePlateau, joueurs, nombreJoueur);
                            
                            for (int j=0; j<4;j++){
                                premiereSauvegardeJoueur[j]=copieJoueur(joueurs[j]);
                            }

                            for(int l=0;l<23;l++){
                                for (int k=0;k<23;k++){
                                    premiereSauvegardeMatrice12[l][k]=matrice12[l][k];
                                }
                            }
                            
                            jouerSontour12(i, joueurs ,deuxiemeSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice12,deuxiemeSauvegardeMatrice12);
                            memoire=2;
                            gotoligcol(46,60);
                            if (blocage>0){
                                for (int j=0; j<4;j++){
                                joueurs[j]=copieJoueur(premiereSauvegardeJoueur[j]);
                                }

                                for(int l=0;l<23;l++){
                                    for (int k=0;k<23;k++){
                                    matrice9[l][k]= premiereSauvegardeMatrice12[l][k];
                                    }
                                }
                                gotoligcol(26,60);
                                printf("le chemin est bloqué veuillez rejouer");
                                jouerSontour12(i, joueurs ,deuxiemeSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice12,deuxiemeSauvegardeMatrice12);

                            }
                        }

                        else if (memoire==2){
                            blocage=CheckAllPath(matrice9, taillePlateau, joueurs, nombreJoueur);
                            
                            for (int j=0; j<4;j++){
                                deuxiemeSauvegardeJoueur[j]=copieJoueur(joueurs[j]);
                            }

                            for(int l=0;l<23;l++){
                                for (int k=0;k<23;k++){
                                    deuxiemeSauvegardeMatrice12[l][k]=matrice12[l][k];
                                }
                            }
                            
                            jouerSontour12(i, joueurs ,premiereSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice12,premiereSauvegardeMatrice12);
                            memoire=1;

                            if (blocage>0){
                                for (int j=0; j<4;j++){
                                joueurs[j]=copieJoueur(deuxiemeSauvegardeJoueur[j]);
                                }

                                for(int l=0;l<23;l++){
                                    for (int k=0;k<23;k++){
                                    matrice12[l][k]=  deuxiemeSauvegardeMatrice12[l][k];
                                    }
                                }
                                gotoligcol(26,60);
                                printf("le chemin est bloqué veuillez rejouer");
                                jouerSontour12(i, joueurs ,premiereSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice12,premiereSauvegardeMatrice12);

                            }  
                        } 

                        i++;

                        if (i>nombreJoueur){
                            i=1;
                        }

                        

                    }while(unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)==0 );
                    
                    if (unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)!=0){
                        gotoligcol(26,60);
                        joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1]=changerScore(joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1],joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1].score+5);
                        printf("%s a remporté cette manche !",joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1].nom);
                        gotoligcol(27,60);
                        printf("voulez vous continuer à jouer ?  -1-oui  -2-non :");
                        scanf("%d",&rejouer);

                    }
                }
            }while(rejouer==1);
        }
            break;

            
        case 2: // appel de lancerPartiesauvegardee
            break;
        case 3: //appel de afficherAide
            break;
        case 4:  //appel de afficherScores
            break;
        case 5: //
            system("cls");
            color(0,15;);
            printf("Merci d'avoir joué ! A bientot ");
            quitter=1;
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
    }while (quitter==0);
}
    
