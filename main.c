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
        printf("Bienvenue dans Quoridor !");
        printf("\n -- Menu -- \n");
        printf("1 - Lancer une nouvelle partie\n");
        printf("2 - reprendre une partie sauvegarde\n");
        printf("3 - Afficher l'aide\n");
        printf("4 - Afficher les scores des joueurs\n");
        printf("5 - Quitter le jeu\n");
        

        scanf("%d",&choixMenu);
        switch (choixMenu)
        {
        case 1:{// appel de lancerNouvellePartie
            int nombreJoueur;
            int taillePlateau;
            int rejouer=1;
            int pause;
            int quitterJeu=0;
            int memoire=1;
            int matrice9[17][17];
            int premiereSauvegardeMatrice9[17][17];
            int deuxiemeSauvegardeMatrice9[17][17];
            int matrice12[23][23];
            int premiereSauvegardeMatrice12[23][23];
            int deuxiemeSauvegardeMatrice12[23][23];
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
                    printf("Quelle taille pour le plateau ? (9 ou 12 uniquement) \n");
                    fflush(stdin);
                    scanf("%d",&taillePlateau);
                }while ( (taillePlateau!=9) && (taillePlateau!=12) ); // verifie que la taille du plateau correspond à 9 ou 12
            }
            else {
                taillePlateau=9;
            }
            
            lancerNouvellePartie(nombreJoueur, taillePlateau, joueurs);
            //intitialiation de la matrice dans laquelle seront géréer les deplacements
            
                while(rejouer==1 ) {

                    rejouer=0;
                    for (int m=0; m<nombreJoueur;m++){//on reinitialise le joueurs en gardant leur nom leur piion et leur score pour démarer une nouvelle partie
                        joueurs[m]=reinitialiserJoueur(m+1,joueurs,taillePlateau);
                    }       



                i= rand() % (nombreJoueur-1 + 1) + 1;
                if (taillePlateau==9){

                    initialiserMatrice9(matrice9,joueurs);
                    afficherJeu9(matrice9,joueurs);
                    int blocage=0;
                    
                    while(unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)==0 && quitterJeu==0){
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
                            
                            quitterJeu=jouerSontour9(i, joueurs ,deuxiemeSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice9,deuxiemeSauvegardeMatrice9);
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
                                quitterJeu=jouerSontour9(i, joueurs ,deuxiemeSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice9,deuxiemeSauvegardeMatrice9);

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
                            
                            quitterJeu=jouerSontour9(i, joueurs ,premiereSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice9,premiereSauvegardeMatrice9);
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
                                quitterJeu=jouerSontour9(i, joueurs ,premiereSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice9,premiereSauvegardeMatrice9);

                            }  
                        } 

                        i++;

                        if (i>nombreJoueur){
                            i=1;
                        }

                    


                    }

                    if (unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)!=0){
                         gotoligcol(26,60);
                        joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1]=changerScore(joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1],joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1].score+5);
                        printf("%s a remporte cette manche !",joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1].nom);
                        gotoligcol(27,60);
                        printf("voulez vous continuer a jouer ?  -1-oui  -2-non :");
                        scanf("%d",&rejouer);

                    }
                   
                }

                    
                else if (taillePlateau==12) {
                    initialiserMatrice12(matrice12,joueurs);
                    afficherJeu12(matrice12,joueurs);
                    int blocage=0;
                    while(unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)==0 && quitterJeu!=1 ) {
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
                            
                            quitterJeu=jouerSontour12(i, joueurs ,deuxiemeSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice12,deuxiemeSauvegardeMatrice12);
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
                                quitterJeu=jouerSontour12(i, joueurs ,deuxiemeSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice12,deuxiemeSauvegardeMatrice12);

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
                            
                            quitterJeu=jouerSontour12(i, joueurs ,premiereSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice12,premiereSauvegardeMatrice12);
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
                                quitterJeu=jouerSontour12(i, joueurs ,premiereSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice12,premiereSauvegardeMatrice12);

                            }  
                        } 

                        i++;

                        if (i>nombreJoueur){
                            i=1;
                        }
                        

                        

                    }
                    
                    if (unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)!=0){
                        gotoligcol(26,60);
                        joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1]=changerScore(joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1],joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1].score+5);
                        printf("%s a remporté cette manche !",joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1].nom);
                        gotoligcol(27,60);
                        printf("voulez vous continuer à jouer ?  -1-oui  -2-non :");
                        scanf("%d",&rejouer);

                    }
                }
            }
        }
            break;

            
        case 2: {
        system("cls");
        color(0,15);
        int pause;
        FILE* fichierIndex;
        char listeParties[256][256];
        char partieACharger[256];
        char tmp[256];
        int numeroPartie;
        int i=0;
        strcat((getcwd(tmp, 256)),"\\Parties_sauvegardee\\indexDesParties.txt");
        fichierIndex=fopen(tmp,"r");
        if (fichierIndex==NULL){
            printf("Erreur d’ouverture de fichier\n " );
             }
        else{
            while (!feof(fichierIndex)){
	            fscanf ( fichierIndex, "%s", listeParties[i]);
                printf ("%d %s \n ",i,listeParties[i]); 
                i++;
                }
            fclose(fichierIndex);
        }
        printf("quelle partie voulez vous continuer ? Saisissez un numero\n");
        scanf("%d",&numeroPartie);
        printf("%s\n",listeParties[numeroPartie]);
        strcpy(partieACharger,listeParties[numeroPartie]);
        
        //Récupération de la partie sauvegardee
        
        int quitterJeu=0;
        int memoire=1;
        int matrice9[17][17];
        int premiereSauvegardeMatrice9[17][17];
        int deuxiemeSauvegardeMatrice9[17][17];
        int matrice12[23][23];
        int premiereSauvegardeMatrice12[23][23];
        int deuxiemeSauvegardeMatrice12[23][23];
        t_joueur joueurs[4];
        t_joueur premiereSauvegardeJoueur[4];
        t_joueur deuxiemeSauvegardeJoueur[4];
        int nombreJoueur;
        int taillePlateau;
        
        FILE*fic;

        fic=fopen(partieACharger,"r");
        fscanf(fic,"%d",&taillePlateau);
        fscanf(fic,"%d",&nombreJoueur);
        // premier joueur
        fscanf(fic,"%s",joueurs[0].nom);
        fscanf(fic,"%d",&(joueurs[0].pion));
        fscanf(fic,"%d",&(joueurs[0].pionM));
        fscanf(fic,"%d",&(joueurs[0].coordonneeMatrice.ligne));
        fscanf(fic,"%d",&(joueurs[0].coordonneeMatrice.colonne));
        fscanf(fic,"%c",&(joueurs[0].coordonneeGrille.ligne));
        fscanf(fic,"%d",&(joueurs[0].coordonneeGrille.colonne));
        fscanf(fic,"%d",&(joueurs[0].score));
        fscanf(fic,"%d",&(joueurs[0].barriere_posees));
        fscanf(fic,"%d",&(joueurs[0].nbCoupAnnule));

        //deuxieme joueur

        fscanf(fic,"%s",joueurs[1].nom);
        fscanf(fic,"%d",&(joueurs[1].pion));
        fscanf(fic,"%d",&(joueurs[1].pionM));
        fscanf(fic,"%d",&(joueurs[1].coordonneeMatrice.ligne));
        fscanf(fic,"%d",&(joueurs[1].coordonneeMatrice.colonne));
        fscanf(fic,"%c",&(joueurs[1].coordonneeGrille.ligne));
        fscanf(fic,"%d",&(joueurs[1].coordonneeGrille.colonne));
        fscanf(fic,"%d",&(joueurs[1].score));
        fscanf(fic,"%d",&(joueurs[1].barriere_posees));
        fscanf(fic,"%d",&(joueurs[1].nbCoupAnnule));

        if(nombreJoueur==4){
            //3eme eventuel Joueur
            fscanf(fic,"%s",joueurs[2].nom);
            fscanf(fic,"%d",&(joueurs[2].pion));
            fscanf(fic,"%d",&(joueurs[2].pionM));
            fscanf(fic,"%d",&(joueurs[2].coordonneeMatrice.ligne));
            fscanf(fic,"%d",&(joueurs[2].coordonneeMatrice.colonne));
            fscanf(fic,"%c",&(joueurs[2].coordonneeGrille.ligne));
            fscanf(fic,"%d",&(joueurs[2].coordonneeGrille.colonne));
            fscanf(fic,"%d",&(joueurs[2].score));
            fscanf(fic,"%d",&(joueurs[2].barriere_posees));
            fscanf(fic,"%d",&(joueurs[2].nbCoupAnnule));


            //4eme eventuel joueur

             fscanf(fic,"%s",joueurs[3].nom);
            fscanf(fic,"%d",&(joueurs[3].pion));
            fscanf(fic,"%d",&(joueurs[3].pionM));
            fscanf(fic,"%d",&(joueurs[3].coordonneeMatrice.ligne));
            fscanf(fic,"%d",&(joueurs[3].coordonneeMatrice.colonne));
            fscanf(fic,"%c",&(joueurs[3].coordonneeGrille.ligne));
            fscanf(fic,"%d",&(joueurs[3].coordonneeGrille.colonne));
            fscanf(fic,"%d",&(joueurs[3].score));
            fscanf(fic,"%d",&(joueurs[3].barriere_posees));
            fscanf(fic,"%d",&(joueurs[3].nbCoupAnnule));
        }

        if(taillePlateau==9){
            for(i=0;i<17;i++)
            {
                for(int j=0;j<17;j++)
                {
                    fscanf(fic,"%d",&(matrice9[i][j]));
                }
            }
        }

        else if(taillePlateau==12){
            for(i=0;i<23;i++)
            {
                for(int j=0;j<23;j++)
                {
                    fscanf(fic,"%d",&(matrice12[i][j]));
                }
            }
        }
        fclose(fic);
        printf("%d\n",taillePlateau);
        printf("%d\n",nombreJoueur);
        printf("%s\n",joueurs[0].nom);
        printf("%c\n",joueurs[0].pionM);
        printf("%c",joueurs[0].coordonneeGrille.ligne);
        printf("%d",joueurs[0].coordonneeGrille.colonne);
        printf("%s\n",joueurs[1].nom);
        printf("%c\n",joueurs[1].pionM);
        printf("%c",joueurs[1].coordonneeGrille.ligne);
        printf("%d",joueurs[1].coordonneeGrille.colonne);

        afficher9(matrice9);
        //on jouer avec les donnes des joueurs sauvegardées
        
        
        
        int premierTour=1;
        int rejouer=1;
         while(rejouer==1 ) {

                    rejouer=0;
                    if(premierTour==0){
                        for (int m=0; m<nombreJoueur;m++){//on reinitialise le joueurs en gardant leur nom leur piion et leur score pour démarer une nouvelle partie
                            joueurs[m]=reinitialiserJoueur(m+1,joueurs,taillePlateau);
                        }       
                    }
                    


                i= rand() % (nombreJoueur-1 + 1) + 1;
                if (taillePlateau==9){
                    if(premierTour==0){
                        initialiserMatrice9(matrice9,joueurs);
                    }
                    premierTour=0;
                    afficherJeu9(matrice9,joueurs);
                    int blocage=0;
                    
                    while(unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)==0 || quitterJeu==0){
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
                            
                            quitterJeu=jouerSontour9(i, joueurs ,deuxiemeSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice9,deuxiemeSauvegardeMatrice9);
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
                                quitterJeu=jouerSontour9(i, joueurs ,deuxiemeSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice9,deuxiemeSauvegardeMatrice9);

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
                            
                            quitterJeu=jouerSontour9(i, joueurs ,premiereSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice9,premiereSauvegardeMatrice9);
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
                                quitterJeu=jouerSontour9(i, joueurs ,premiereSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice9,premiereSauvegardeMatrice9);

                            }  
                        } 

                        i++;

                        if (i>nombreJoueur){
                            i=1;
                        }

                    


                    }

                    if (unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)!=0){
                         gotoligcol(26,60);
                        joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1]=changerScore(joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1],joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1].score+5);
                        printf("%s a remporte cette manche !",joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1].nom);
                        gotoligcol(27,60);
                        printf("voulez vous continuer a jouer ?  -1-oui  -2-non :");
                        scanf("%d",&rejouer);

                    }
                   
                }

                    
                else if (taillePlateau==12) {
                    if(premierTour==0){
                        initialiserMatrice12(matrice12,joueurs);
                    }
                    premierTour=0;
                    afficherJeu12(matrice12,joueurs);
                    int blocage=0;
                    while(unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)==0|| quitterJeu ==0 ) {
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
                            
                            quitterJeu=jouerSontour12(i, joueurs ,deuxiemeSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice12,deuxiemeSauvegardeMatrice12);
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
                                quitterJeu=jouerSontour12(i, joueurs ,deuxiemeSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice12,deuxiemeSauvegardeMatrice12);

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
                            
                            quitterJeu=jouerSontour12(i, joueurs ,premiereSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice12,premiereSauvegardeMatrice12);
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
                                quitterJeu=jouerSontour12(i, joueurs ,premiereSauvegardeJoueur,nombreJoueur,taillePlateau,  matrice12,premiereSauvegardeMatrice12);

                            }  
                        } 

                        i++;

                        if (i>nombreJoueur){
                            i=1;
                        }
                        

                        

                    }
                    
                    if (unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)!=0){
                        gotoligcol(26,60);
                        joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1]=changerScore(joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1],joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1].score+5);
                        printf("%s a remporté cette manche !",joueurs[unJoueurEstArrivee(joueurs,taillePlateau,nombreJoueur)-1].nom);
                        gotoligcol(27,60);
                        printf("voulez vous continuer à jouer ?  -1-oui  -2-non :");
                        scanf("%d",&rejouer);

                    }
                }
            }
            scanf("%d",&pause);








        }break;
        case 3: //appel de afficherAide
         {
            int quitter;
            system("cls");
            color(0,15);
         do{
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
            printf("quitter ? -0- Non -1- oui :");
            scanf("%d",&quitter);
            
         }while (quitter==0);
        }
            break;
        case 4:  {
            system("cls");
            color(0,15);
            
            FILE* fichierIndex;
            char listeParties[256][256];
            char partieACharger[256];
            char tmp[256];
            int revenirMenu=0;
            int taillePlateau;
            int nombreJoueur;
            t_joueur joueurs[4];
            int numeroPartie;
            int i=0;
            strcat((getcwd(tmp, 256)),"\\Parties_sauvegardee\\indexDesParties.txt");
            fichierIndex=fopen(tmp,"r");
            if (fichierIndex==NULL){
                printf("Erreur d’ouverture de fichier\n " );
                }
            else{
                while (!feof(fichierIndex)){
                    fscanf ( fichierIndex, "%s", listeParties[i]);
                    printf ("%d %s \n ",i,listeParties[i]); 
                    i++;
                    }
                fclose(fichierIndex);
            }
            while(revenirMenu==0){
                printf("Tableau des scores des joueurs\n");
                for (int j=0;j<i;j++){
                    FILE *fic;
                    fic=fopen(listeParties[j],"r");
                    fscanf(fic,"%d",&taillePlateau);
                    fscanf(fic,"%d",&nombreJoueur);
                    // premier joueur
                    fscanf(fic,"%s",joueurs[0].nom);
                    fscanf(fic,"%d",&(joueurs[0].pion));
                    fscanf(fic,"%d",&(joueurs[0].pionM));
                    fscanf(fic,"%d",&(joueurs[0].coordonneeMatrice.ligne));
                    fscanf(fic,"%d",&(joueurs[0].coordonneeMatrice.colonne));
                    fscanf(fic,"%c",&(joueurs[0].coordonneeGrille.ligne));
                    fscanf(fic,"%d",&(joueurs[0].coordonneeGrille.colonne));
                    fscanf(fic,"%d",&(joueurs[0].score));
                    fscanf(fic,"%d",&(joueurs[0].barriere_posees));
                    fscanf(fic,"%d",&(joueurs[0].nbCoupAnnule));

                    //deuxieme joueur

                    fscanf(fic,"%s",joueurs[1].nom);
                    fscanf(fic,"%d",&(joueurs[1].pion));
                    fscanf(fic,"%d",&(joueurs[1].pionM));
                    fscanf(fic,"%d",&(joueurs[1].coordonneeMatrice.ligne));
                    fscanf(fic,"%d",&(joueurs[1].coordonneeMatrice.colonne));
                    fscanf(fic,"%c",&(joueurs[1].coordonneeGrille.ligne));
                    fscanf(fic,"%d",&(joueurs[1].coordonneeGrille.colonne));
                    fscanf(fic,"%d",&(joueurs[1].score));
                    fscanf(fic,"%d",&(joueurs[1].barriere_posees));
                    fscanf(fic,"%d",&(joueurs[1].nbCoupAnnule));

                    if(nombreJoueur==4){
                        //3eme eventuel Joueur
                        fscanf(fic,"%s",joueurs[2].nom);
                        fscanf(fic,"%d",&(joueurs[2].pion));
                        fscanf(fic,"%d",&(joueurs[2].pionM));
                        fscanf(fic,"%d",&(joueurs[2].coordonneeMatrice.ligne));
                        fscanf(fic,"%d",&(joueurs[2].coordonneeMatrice.colonne));
                        fscanf(fic,"%c",&(joueurs[2].coordonneeGrille.ligne));
                        fscanf(fic,"%d",&(joueurs[2].coordonneeGrille.colonne));
                        fscanf(fic,"%d",&(joueurs[2].score));
                        fscanf(fic,"%d",&(joueurs[2].barriere_posees));
                        fscanf(fic,"%d",&(joueurs[2].nbCoupAnnule));


                        //4eme eventuel joueur

                        fscanf(fic,"%s",joueurs[3].nom);
                        fscanf(fic,"%d",&(joueurs[3].pion));
                        fscanf(fic,"%d",&(joueurs[3].pionM));
                        fscanf(fic,"%d",&(joueurs[3].coordonneeMatrice.ligne));
                        fscanf(fic,"%d",&(joueurs[3].coordonneeMatrice.colonne));
                        fscanf(fic,"%c",&(joueurs[3].coordonneeGrille.ligne));
                        fscanf(fic,"%d",&(joueurs[3].coordonneeGrille.colonne));
                        fscanf(fic,"%d",&(joueurs[3].score));
                        fscanf(fic,"%d",&(joueurs[3].barriere_posees));
                        fscanf(fic,"%d",&(joueurs[3].nbCoupAnnule));
                    }    

                    for (int l;l<4;l++){
                        
                        printf("%s : %d\n",joueurs[l].nom,joueurs[l].score);
                    }
                }
                do {
                    printf("voulez vous revenir au menu ? (-1-oui -0- non) : ");
                    scanf("%d",&revenirMenu);
                }while ((revenirMenu!=1) && (revenirMenu!=0));
            }
        }
              break;
        case 5: //
            system("cls");
            color(0,15);
            printf("Merci d'avoir joue ! A bientot ");
            quitter=1;
            break;
        
        default:
            printf("le choix selectionne n'existe pas ");
            break;


        }
        fflush(stdin);

        
        
    }while (quitter==0);

    return 0;
}
    
