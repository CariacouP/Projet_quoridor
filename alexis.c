#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include "structures.h"
#include"fonctions.h"
#include"alexis.h"





void afficher9(int matrice[17][17])
{
    int i,j;
    for (i=0;i<17;i++)
    {
        for (j=0;j<17;j++)
        {
            printf("%d ",matrice[i][j]);
        }
        printf("\n");
    }
}

void afficher12(int matrice[23][23])
{
    
    int i,j;
    for (i=0;i<23;i++)
    {
        for (j=0;j<23;j++)
        {
            printf("%d ",matrice[i][j]);
        }
        printf("\n");
    }
}




int verificationDeplacement9(t_joueur joueur , t_coordonneeM coorVoulu,int matrice[17][17])
{
    int i,j,i1,j1;
    i1=coorVoulu.ligne;
    j1=coorVoulu.colonne;
    i=joueur.coordonneeMatrice.ligne;
    j=joueur.coordonneeMatrice.colonne;
    if ((i1%2==1)||(j1%2==1))
    {
        printf("le pion est dans la case barriere");
        return(1);//retourne faux si le pion est dans une case barriere
    }
    /* if (i!=i1)
    {
        if (abs(i-i1)>2)
        {
            gotoligcol(24,60);
            printf("Le pion est deplace trop loin");
            return(1);//le déplacement vertical est tro important
        }
    }
    if (j!=j1)
    {
        if (abs(j-j1)>2)
        {
            gotoligcol(24,60);
            printf("Le pion est deplace trop loin");
            return(1);//le deplacement horizontal est trop important
        }
    }
    if ((i!=i1)&&(j!=j1))
    {
        gotoligcol(24,60);
        printf("un pion ne peut pas se deplacer en diagonale");
        return(1);//Le pion ne se deplace pas en diagonale
    }*/
    if(sontCoteAcote(joueur.coordonneeGrille,coordoneeMatriceversCoordGrille(coorVoulu))==0){
        gotoligcol(24,60);
        printf("Les cases ne sont pas adjacentes");
        return 1;

    }
    if(verifierBarriere9(i,j,i1,j1,matrice)==1)
    {
        printf("une barriere empeche le deplacement");
        return(1);
    }
    return(0);//Si les conditions non valables ne sont pas verifiees, alors on valide la faisabilite
}

int verificationDeplacement12(t_joueur joueur , t_coordonneeM coorVoulu,int matrice[23][23])
{
    int i,j,i1,j1;
    i1=coorVoulu.ligne;
    j1=coorVoulu.colonne;
    i=joueur.coordonneeMatrice.ligne;
    j=joueur.coordonneeMatrice.colonne;
    if ((i1%2==1)||(j1%2==1))
    {
        gotoligcol(24,60);
        printf("le pion est dans la case barriere");
        return(1);//retourne faux si le pion est dans une case barriere
    }
   /* if (i!=i1)
    {
        if (abs(i-i1)>2)
        {
            gotoligcol(24,60);
            printf("Le pion est deplace trop loin");
            return(1);//le déplacement vertical est tro important
        }
    }
    if (j!=j1)
    {
        if (abs(j-j1)>2)
        {
            gotoligcol(24,60);
            printf("Le pion est deplace trop loin");
            return(1);//le deplacement horizontal est trop important
        }
    }
    if ((i!=i1)&&(j!=j1))
    {
        gotoligcol(24,60);
        printf("un pion ne peut pas se deplacer en diagonale");
        return(1);//Le pion ne se deplace pas en diagonale
    }*/
    if(sontCoteAcote(joueur.coordonneeGrille,coordoneeMatriceversCoordGrille(coorVoulu))==1){
        gotoligcol(24,60);
        printf("Les cases ne sont pas adjacentes");
        return 1;

    }
    if(verifierBarriere12(i,j,i1,j1,matrice)==1)
    {
        gotoligcol(24,60);
        printf("une barriere empeche le deplacement");
        return(1);
    }
    return(0);//Si les conditions non valables ne sont pas verifiees, alors on valide la faisabilite
}

int verifierBarriere9(int i,int j,int i1,int j1,int matrice[17][17])// va dans lee programme verificationDeplacement, on a i1 et j1 les coordonnées visée et i, j les coordonées du joueur dans la matrice
{
    if ( (i==i1)&& (j<j1) )
    {
        if (matrice[i][j+1]==1)//S il y a une barriere entre les deux cases
        {
            gotoligcol(24,60);
            printf("il y a une barriere\n");
            return(1);
        }
    }
    
    else if ( (i==i1)&& (j>j1) )
    {
        if (matrice[i][j-1]==1)//S il y a une barriere entre les deux cases
        {
            gotoligcol(24,60);
            printf("il y a une barriere\n");
            return(1);
        }
    }

    else if ( (j==j1)&& (i<i1) )
    {
        if (matrice[i+1][j]==1)//S il y a une barriere entre les deux cases
        {
            gotoligcol(24,60);
            printf("il y a une barriere\n");
            return(1);
        }
    }

    else if ( (j==j1)&& (i>i1) )
    {
        if (matrice[i-1][j]==1)//S il y a une barriere entre les deux cases
        {
            gotoligcol(24,60);
            printf("il y a une barriere\n");
            return(1);
        }
    }


    return(0);
}

int verifierBarriere12(int i,int j,int i1,int j1,int matrice[23][23])// va dans lee programme verificationDeplacement, on a i1 et j1 les coordonnées visée et i, j les coordonées du joueur dans la matrice
{
    if ( (i==i1)&& (j<j1) )
    {
        if (matrice[i][j+1]==1)//S il y a une barriere entre les deux cases
        {
            gotoligcol(24,60);
            printf("il y a une barriere\n");
            return(1);
        }
    }
    
    else if ( (i==i1)&& (j>j1) )
    {
        if (matrice[i][j-1]==1)//S il y a une barriere entre les deux cases
        {
            gotoligcol(24,60);
            printf("il y a une barriere\n");
            return(1);
        }
    }

    else if ( (j==j1)&& (i<i1) )
    {
        if (matrice[i+1][j]==1)//S il y a une barriere entre les deux cases
        {
            gotoligcol(24,60);
            printf("il y a une barriere\n");
            return(1);
        }
    }

    else if ( (j==j1)&& (i>i1) )
    {
        if (matrice[i-1][j]==1)//S il y a une barriere entre les deux cases
        {
            gotoligcol(24,60);
            printf("il y a une barriere\n");
            return(1);
        }
    }


    return(0);
}

int PionDansCase9(t_coordonneeM cooraVerif,int matrice[17][17])
{
    
    //si il y a un pion dans la case, il faut re saisir un endroit ou se deplacer et tout re verifier
    
    if (matrice[cooraVerif.ligne][cooraVerif.colonne]!=0){
        return 1;
    }
    return 0;
   
}

int PionDansCase12(t_coordonneeM cooraVerif,int matrice[23][23])
{
    
    //si il y a un pion dans la case, il faut re saisir un endroit ou se deplacer et tout re verifier
    
    if (matrice[cooraVerif.ligne][cooraVerif.colonne]!=0){
        return 1;
    }
    return 0;
   
}

/*int verifiePassage(t_coordonneeM coorPion, int matrice[17][17])//vérifie si  le pion est entoure de pion ou de barriere
{
    int i,j;
    i=coorPion.ligne;
    j=coorPion.colonne;
    if ((i%2==1)&&(j%2==1))// si le pion est dans une case pion
    {
        if (((matrice[i+1][j]==1)||(matrice[i+2][j]>=2))&&((matrice[i-1][j]==1)||(matrice[i-2][j]>=2))&&((matrice[i][j+1]==1)||(matrice[i][j+2]>=2))&&((matrice[i][j-1]==1)||(matrice[i][j-2]>=2)))
            {//si le pion est entoure de barriere ou pion
                printf("le pion est entoure le deplacement ne peut pas se faire ici");
                return(1);
            }
        else
        {
            printf("le deplacement peut se faire");
            return(0);
        }
    }

}*/

t_joueur deplacerPion9(t_coordonneeM coorVoulu,t_joueur joueur,int matrice[17][17])
{
    t_joueur joueurfin;
    int i,j,j1,i1;
    t_coordonneeM nouvellesCoor;
    i1= coorVoulu.ligne;
    j1=coorVoulu.colonne;
    i=joueur.coordonneeMatrice.ligne;
    j=joueur.coordonneeMatrice.colonne;
    if (verificationDeplacement9(joueur,coorVoulu,matrice)==0)
    //on verifie que le deplacement est possible
    {
         
            if (PionDansCase9(coorVoulu,matrice)==1)
            //Si il y a un pion dans la case visée
            {
                if ( (i==i1)&&(j1 > j) ){
                    // si la case visée est sur la meme ligne vers la droite
                    if (verifierBarriere9(i1,j1,i1,j1+2,matrice)==0){
                        // on verifie qu'il n'y a pas de barrière après le pion
                        matrice[i1][j1+2]=joueur.pionM;
                        matrice[i][j]=0;
                        joueurfin.coordonneeMatrice.ligne=i1;
                        joueurfin.coordonneeMatrice.colonne=j1+2;
                        joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                        joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;
                    }
                    else if (verifierBarriere9(i1,j1,i1,j1+2,matrice)==1){
                        //si il y a une barrière après le pion, on demande au joueur de choisir une nouvelle case immediatement au dessus ou en dessous du pion
                        do{
                            gotoligcol(19,60);
                            printf("choissez la case sur laquelle vous voulez aller, au dessus ou en desous du pion");
                            nouvellesCoor=coordonneGrilleVersCoordMatrice(remplircoordonneeG(9));
                        }while ( ( (nouvellesCoor.ligne!=i1-2) && (nouvellesCoor.ligne!=i1+2) ) || (nouvellesCoor.colonne!=j1) || (verifierBarriere9(i1,j1,nouvellesCoor.ligne,nouvellesCoor.colonne,matrice)==1) || (PionDansCase9(nouvellesCoor,matrice)==1) );

                            matrice[nouvellesCoor.ligne][nouvellesCoor.colonne]=joueur.pionM;
                            matrice[i][j]=0;
                            joueurfin.coordonneeMatrice.ligne=nouvellesCoor.ligne;
                            joueurfin.coordonneeMatrice.colonne=nouvellesCoor.colonne;
                            joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                            joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;
                    }


                }

                else if ( (i==i1)&&(j1 < j) ){
                    if (verifierBarriere9(i1,j1,i1,j1-2,matrice)==0){
                        matrice[i1][j1-2]=joueur.pionM;
                        matrice[i][j]=0;
                        joueurfin.coordonneeMatrice.ligne=i1;
                        joueurfin.coordonneeMatrice.colonne=j1-2;
                        joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                        joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;
                    }
                    else if (verifierBarriere9(i1,j1,i1,j1-2,matrice)==1){
                        do{
                            gotoligcol(19,60);
                            printf("choissez la case sur laquelle vous voulez aller, au dessus ou en desous du pion");
                            nouvellesCoor=coordonneGrilleVersCoordMatrice(remplircoordonneeG(9));
                        }while ( ( (nouvellesCoor.ligne!=i1-2) && (nouvellesCoor.ligne!=i1+2) ) || (nouvellesCoor.colonne!=j1) || (verifierBarriere9(i1,j1,nouvellesCoor.ligne,nouvellesCoor.colonne,matrice)==1) || (PionDansCase9(nouvellesCoor,matrice)==1) );

                            matrice[nouvellesCoor.ligne][nouvellesCoor.colonne]=joueur.pionM;
                            matrice[i][j]=0;
                            joueurfin.coordonneeMatrice.ligne=nouvellesCoor.ligne;
                            joueurfin.coordonneeMatrice.colonne=nouvellesCoor.colonne;
                            joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                            joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;
                    }


                }

                else if ( (j==j1)&&(i1 < i) ){
                    if (verifierBarriere9(i1,j1,i1-2,j1,matrice)==0){
                        matrice[i1-2][j1]=joueur.pionM;
                        matrice[i][j]=0;
                        joueurfin.coordonneeMatrice.ligne=i1-2;
                        joueurfin.coordonneeMatrice.colonne=j1;
                        joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                        joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;
                    }
                    else if (verifierBarriere9(i1,j1,i1-2,j1,matrice)==1){
                        do{
                            gotoligcol(19,60);
                            printf("choissez la case sur laquelle vous voulez aller, au dessus ou en desous du pion");
                            nouvellesCoor=coordonneGrilleVersCoordMatrice(remplircoordonneeG(9));
                        }while ( ( (nouvellesCoor.colonne!=j1-2) && (nouvellesCoor.colonne!=j1+2) ) || (nouvellesCoor.colonne!=i1) || (verifierBarriere9(i1,j1,nouvellesCoor.ligne,nouvellesCoor.colonne,matrice)==1) || (PionDansCase9(nouvellesCoor,matrice)==1) );

                            matrice[nouvellesCoor.ligne][nouvellesCoor.colonne]=joueur.pionM;
                            matrice[i][j]=0;
                            joueurfin.coordonneeMatrice.ligne=nouvellesCoor.ligne;
                            joueurfin.coordonneeMatrice.colonne=nouvellesCoor.colonne;
                            joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                            joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;
                    }
                }

                else if ( (j==j1)&&(i1 > i) ){
                    if (verifierBarriere9(i1,j1,i1+2,j1,matrice)==0){
                        matrice[i1+2][j1]=joueur.pionM;
                        matrice[i][j]=0;
                        joueurfin.coordonneeMatrice.ligne=i1+2;
                        joueurfin.coordonneeMatrice.colonne=j1;
                        joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                        joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;
                    }
                    else if (verifierBarriere9(i1,j1,i1+2,j1,matrice)==1){
                        do{
                            gotoligcol(24,60);
                            printf("choissez la case sur laquelle vous voulez aller, au dessus ou en desous du pion");
                            nouvellesCoor=coordonneGrilleVersCoordMatrice(remplircoordonneeG(9));
                        }while ( ( (nouvellesCoor.colonne!=j1-2) && (nouvellesCoor.colonne!=j1+2) ) || (nouvellesCoor.colonne!=i1) || (verifierBarriere9(i1,j1,nouvellesCoor.ligne,nouvellesCoor.colonne,matrice)==1) || (PionDansCase9(nouvellesCoor,matrice)==1) );

                            matrice[nouvellesCoor.ligne][nouvellesCoor.colonne]=joueur.pionM;
                            matrice[i][j]=0;
                            joueurfin.coordonneeMatrice.ligne=nouvellesCoor.ligne;
                            joueurfin.coordonneeMatrice.colonne=nouvellesCoor.colonne;
                            joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                            joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;
                    }


                }
                
            }
            
         else
            {
                
                matrice[coorVoulu.ligne][coorVoulu.colonne]=joueur.pionM;
                matrice[joueur.coordonneeMatrice.ligne][joueur.coordonneeMatrice.colonne]=0;
                joueurfin.coordonneeMatrice.ligne=coorVoulu.ligne;
                joueurfin.coordonneeMatrice.colonne=coorVoulu.colonne;
                joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;

            }
    }
    else if (verificationDeplacement9(joueur,coorVoulu,matrice)==1){

        nouvellesCoor= coordonneGrilleVersCoordMatrice(remplircoordonneeG(9));
        deplacerPion9(nouvellesCoor,joueur,matrice);
    }

   joueurfin.barriere_posees=joueur.barriere_posees;
   joueurfin.nbCoupAnnule=joueur.nbCoupAnnule;
   strcpy(joueurfin.nom,joueur.nom);
   joueurfin.pionM=joueur.pionM;
   joueurfin.pion=joueur.pion;
   joueurfin.score=joueur.score;
   return joueurfin;
}

t_joueur deplacerPion12(t_coordonneeM coorVoulu,t_joueur joueur,int matrice[23][23])
{
    t_joueur joueurfin;
    int i,j,j1,i1;
    t_coordonneeM nouvellesCoor;
    i1= coorVoulu.ligne;
    j1=coorVoulu.colonne;
    i=joueur.coordonneeMatrice.ligne;
    j=joueur.coordonneeMatrice.colonne;
    if (verificationDeplacement12(joueur,coorVoulu,matrice)==0)
    //on verifie que le deplacement est possible
    {
         
            if (PionDansCase12(coorVoulu,matrice)==1)
            //Si il y a un pion dans la case visée
            {
                if ( (i==i1)&&(j1 > j) ){
                    // si la case visée est sur la meme ligne vers la droite
                    if (verifierBarriere12(i1,j1,i1,j1+2,matrice)==0){
                        // on verifie qu'il n'y a pas de barrière après le pion
                        matrice[i1][j1+2]=joueur.pionM;
                        matrice[i][j]=0;
                        joueurfin.coordonneeMatrice.ligne=i1;
                        joueurfin.coordonneeMatrice.colonne=j1+2;
                        joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                        joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;
                    }
                    else if (verifierBarriere12(i1,j1,i1,j1+2,matrice)==1){
                        //si il y a une barrière après le pion, on demande au joueur de choisir une nouvelle case immediatement au dessus ou en dessous du pion
                        do{
                            gotoligcol(24,60);
                            printf("choissez la case sur laquelle vous voulez aller, au dessus ou en desous du pion");
                            nouvellesCoor=coordonneGrilleVersCoordMatrice(remplircoordonneeG(12));
                        }while ( ( (nouvellesCoor.ligne!=i1-2) && (nouvellesCoor.ligne!=i1+2) ) || (nouvellesCoor.colonne!=j1) || (verifierBarriere12(i1,j1,nouvellesCoor.ligne,nouvellesCoor.colonne,matrice)==1) || (PionDansCase12(nouvellesCoor,matrice)==1) );

                            matrice[nouvellesCoor.ligne][nouvellesCoor.colonne]=joueur.pionM;
                            matrice[i][j]=0;
                            joueurfin.coordonneeMatrice.ligne=nouvellesCoor.ligne;
                            joueurfin.coordonneeMatrice.colonne=nouvellesCoor.colonne;
                            joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                            joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;
                    }


                }

                else if ( (i==i1)&&(j1 < j) ){
                    if (verifierBarriere12(i1,j1,i1,j1-2,matrice)==0){
                        matrice[i1][j1-2]=joueur.pionM;
                        matrice[i][j]=0;
                        joueurfin.coordonneeMatrice.ligne=i1;
                        joueurfin.coordonneeMatrice.colonne=j1-2;
                        joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                        joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;
                    }
                    else if (verifierBarriere12(i1,j1,i1,j1-2,matrice)==1){
                        do{
                           gotoligcol(24,60);
                            printf("choissez la case sur laquelle vous voulez aller, au dessus ou en desous du pion");
                            nouvellesCoor=coordonneGrilleVersCoordMatrice(remplircoordonneeG(12));
                        }while ( ( (nouvellesCoor.ligne!=i1-2) && (nouvellesCoor.ligne!=i1+2) ) || (nouvellesCoor.colonne!=j1) || (verifierBarriere12(i1,j1,nouvellesCoor.ligne,nouvellesCoor.colonne,matrice)==1) || (PionDansCase12(nouvellesCoor,matrice)==1) );

                            matrice[nouvellesCoor.ligne][nouvellesCoor.colonne]=joueur.pionM;
                            matrice[i][j]=0;
                            joueurfin.coordonneeMatrice.ligne=nouvellesCoor.ligne;
                            joueurfin.coordonneeMatrice.colonne=nouvellesCoor.colonne;
                            joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                            joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;
                    }


                }

                else if ( (j==j1)&&(i1 < i) ){
                    if (verifierBarriere12(i1,j1,i1-2,j1,matrice)==0){
                        matrice[i1-2][j1]=joueur.pionM;
                        matrice[i][j]=0;
                        joueurfin.coordonneeMatrice.ligne=i1-2;
                        joueurfin.coordonneeMatrice.colonne=j1;
                        joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                        joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;
                    }
                    else if (verifierBarriere12(i1,j1,i1-2,j1,matrice)==1){
                        do{
                            gotoligcol(24,60);
                            printf("choissez la case sur laquelle vous voulez aller, au dessus ou en desous du pion");
                            nouvellesCoor=coordonneGrilleVersCoordMatrice(remplircoordonneeG(12));
                        }while ( ( (nouvellesCoor.colonne!=j1-2) && (nouvellesCoor.colonne!=j1+2) ) || (nouvellesCoor.colonne!=i1) || (verifierBarriere12(i1,j1,nouvellesCoor.ligne,nouvellesCoor.colonne,matrice)==1) || (PionDansCase12(nouvellesCoor,matrice)==1) );

                            matrice[nouvellesCoor.ligne][nouvellesCoor.colonne]=joueur.pionM;
                            matrice[i][j]=0;
                            joueurfin.coordonneeMatrice.ligne=nouvellesCoor.ligne;
                            joueurfin.coordonneeMatrice.colonne=nouvellesCoor.colonne;
                            joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                            joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;  
                    }
                }

                else if ( (j==j1)&&(i1 > i) ){
                    if (verifierBarriere12(i1,j1,i1+2,j1,matrice)==0){
                        matrice[i1+2][j1]=joueur.pionM;
                        matrice[i][j]=0;
                        joueurfin.coordonneeMatrice.ligne=i1+2;
                        joueurfin.coordonneeMatrice.colonne=j1;
                        joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                        joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;
                    }
                    else if (verifierBarriere12(i1,j1,i1+2,j1,matrice)==1){
                        do{
                            gotoligcol(24,60);
                            printf("choissez la case sur laquelle vous voulez aller, au dessus ou en desous du pion");
                            nouvellesCoor=coordonneGrilleVersCoordMatrice(remplircoordonneeG(12));
                        }while ( ( (nouvellesCoor.colonne!=j1-2) && (nouvellesCoor.colonne!=j1+2) ) || (nouvellesCoor.colonne!=i1) || (verifierBarriere12(i1,j1,nouvellesCoor.ligne,nouvellesCoor.colonne,matrice)==1) || (PionDansCase12(nouvellesCoor,matrice)==1) );

                            matrice[nouvellesCoor.ligne][nouvellesCoor.colonne]=joueur.pionM;
                            matrice[i][j]=0;
                            joueurfin.coordonneeMatrice.ligne=nouvellesCoor.ligne;
                            joueurfin.coordonneeMatrice.colonne=nouvellesCoor.colonne;
                            joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                            joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;  
                    }


                }
                
            }
            
         else
            {
                
                matrice[coorVoulu.ligne][coorVoulu.colonne]=joueur.pionM;
                matrice[joueur.coordonneeMatrice.ligne][joueur.coordonneeMatrice.colonne]=0;
                joueurfin.coordonneeMatrice.ligne=coorVoulu.ligne;
                joueurfin.coordonneeMatrice.colonne=coorVoulu.colonne;
                joueurfin.coordonneeGrille.ligne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).ligne;
                joueurfin.coordonneeGrille.colonne=coordoneeMatriceversCoordGrille(joueurfin.coordonneeMatrice).colonne;

            }
    }
    else if (verificationDeplacement12(joueur,coorVoulu,matrice)==1){
        nouvellesCoor= coordonneGrilleVersCoordMatrice(remplircoordonneeG(12));
        deplacerPion12(nouvellesCoor,joueur,matrice);
    }

   joueurfin.barriere_posees=joueur.barriere_posees;
   joueurfin.nbCoupAnnule=joueur.nbCoupAnnule;
   strcpy(joueurfin.nom,joueur.nom);
   joueurfin.pionM=joueur.pionM;
   joueurfin.pion=joueur.pion;
   joueurfin.score=joueur.score;
   return joueurfin;
}




