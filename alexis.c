#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include "fonctions.h"


void initialiserPlateau (int plateau[17][17])
{
    int i,j;
    for (i=0;i<17;i++)
    {
        for (j=0;j<17;j++)
        {
            plateau[i][j]=0;
           // printf("Ici\n");
        }
    }
}

void afficher(int plateau[17][17])//nécessaire ou pas ?
{
    //Demander la taille
    initialiserPlateau(plateau);
    int i,j;
    for (i=0;i<17;i++)
    {
        for (j=0;j<17;j++)
        {
            printf("%d",plateau[i][j]);
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

void deplacerPion(int i1,int j1,int plateau[17][17])
{
    int i,j;
    t_joueur *joueur;
    t_coordonneeM *coor=joueur->coordonneeMatrice;

    i=coor->ligne;
    j=coor->colonne;
    plateau[i1][j1]=joueur->pion;
    plateau[i][j]=0;
}

int verificationDeplacement(int i1,int j1,int plateau[17][17])// explique qui est i1 et j1 en commentaire
{
    t_joueur *joueur;
    t_coordonneeM *coor=joueur->coordonneeMatrice;
    int i,j;
    i=coor->ligne;
    j=coor->colonne;
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
    if(verifierBarriere(i,j,i1,j1,plateau)==1)
    {
        printf("une barriere empeche le deplacement");
        return(1);
    }
    return(0);//Si les conditions non valables ne sont pas verifiees, alors on valide la faisabilite
}

int verifierBarriere(int i,int j,int i1,int j1,int plateau[17][17])// va dans lee programme verificationDeplacement
{
    if (i!=i1)  // si le changement de case horizontal
    {
        if (plateau[(i+i1)/2]==1)//S il y a une barriere entre les deux cases
        {
            printf("il y a une barriere\n");
            return(1);
        }
    }
    if (j!=j1)  // si le changement de case est vertical
    {
        if (plateau[(j+j1)/2]==1)//S il y a une barriere entre les deux cases
        {
            printf("il y a une barriere\n");
            return(1);
        }
    }
    return(0);
}

int pionDansCase(int i1,int j1,int plateau[17][17])
{
    //si il y a un pion dans la case, il faut re saisir un endroit ou se deplacer et tout re verifier
    //Donc on va mettre verificationDeplacement ici
}
