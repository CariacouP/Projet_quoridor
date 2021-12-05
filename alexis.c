#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include"fonctions.h"


void initialiserMatrice (int matrice[17][17])
{
    int i,j;
    for (i=0;i<17;i++)
    {
        for (j=0;j<17;j++)
        {
            matrice[i][j]=0;
           // printf("Ici\n");
        }
    }
}

void afficher(int matrice[17][17])//nécessaire ou pas ?
{
    //Demander la taille
    initialiserMatrice(matrice);
    int i,j;
    for (i=0;i<17;i++)
    {
        for (j=0;j<17;j++)
        {
            printf("%d",matrice[i][j]);
        }
        printf("\n");
    }
}

/*void saisieEmplacementJoueur(t_joueur *Ptjoueur)//nouveau
{
    printf("saisir la position ligne du joueur");
    scanf("%d",&(Ptjoueur->positionI));
    printf("saisir la position colonne du joueur");
    scanf("%d",&(Ptjoueur->positionJ));
}*/

void deplacerPion(int i1,int j1,int matrice[17][17])
{
    int i,j;
    t_joueur joueur;
    t_coordonneeM coor;
    i=coor.ligne;
    j=coor.colonne;
    matrice[i1][j1]=joueur.pion;
    matrice[i][j]=0;
}

int verificationDeplacement(int i1,int j1,int matrice[17][17])
{
    t_joueur joueur;
    t_coordonneeM coor;
    int i,j;
    i=coor.ligne;
    j=coor.colonne;
    if ((i1%2==0)||(j1%2==0))
    {
        printf("le pion est dans la case barriere");
        return(1);//retourne faux si le pion est dans une case barriere
    }
    if (i!=i1)
    {
        if (abs(i-i1)>2)
        {
            printf("Le pion est deplace trop loin");
            return(1);//le déplacement vertical est tro important
        }
    }
    if (j!=j1)
    {
        if (abs(j-j1)>2)
        {
            printf("Le pion est deplace trop loin");
            return(1);//le deplacement horizontal est trop important
        }
    }
    if ((i!=i1)&&(j!=j1))
    {
        printf("un pion ne peut pas se deplacer en diagonale");
        return(1);//Le pion ne se deplace pas en diagonale
    }
    if(verifierBarriere(i,j,i1,j1,matrice)==1)
    {
        printf("une barriere empeche le deplacement");
        return(1);
    }
    return(0);//Si les conditions non valables ne sont pas verifiees, alors on valide la faisabilite
}

int verifierBarriere(int i,int j,int i1,int j1,int matrice[17][17])// va dans lee programme verificationDeplacement
{
    if (i!=i1)
    {
        if (matrice[(i+i1)/2]==1)//S il y a une barriere entre les deux cases
        {
            printf("il y a une barriere\n");
            return(1);
        }
    }
    if (j!=j1)
    {
        if (matrice[(j+j1)/2]==1)//S il y a une barriere entre les deux cases
        {
            printf("il y a une barriere\n");
            return(1);
        }
    }
    return(0);
}

int PionDansCase(int i1,int j1,int matrice[17][17])
{
    //si il y a un pion dans la case, il faut re saisir un endroit ou se deplacer et tout re verifier
    //Donc on va mettre verificationDeplacement ici
    if ((i1%2==0)||(j1%2==0))
    {
        printf("pas possible de placer un pion a ces coordonnees de barrierre");
        return(1);
    }
    else
    {
        if ((matrice[i1][j1]>=2)&&(matrice[i1][j1]<=4))
        {
            printf("il y a un pion dans la case");
            return(0);
        }
    }
}
