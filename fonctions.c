#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "fonctions.h"


void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


void gotoligcol( int lig, int col )
{
// ressources
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}




char* saisirChaine()
///tenvoie le pointeur de la chaine de caractère saisie allouée dynamiquement
{
    char* chaine;
    char temp[NC];
    fflush(stdin);
    gets(temp);


    chaine=(char*)malloc(sizeof(char)*strlen(temp)+1);

    strcpy(chaine,temp);


    return chaine;


}


void lancerNouvellePartie()
///Lance une nouvelle partie
{
    /// saisie des noms des joueurs
    char *nomJoueur1=NULL;
    char *nomJoueur2=NULL;
    char jetons[8]=[0x40,0x2A,0x23,0x26,0x25,0xA3,0x24,0x3F]; ///Listes des différents jetons possible pour les joueurs
    int numeroJetonJ1=0;
    int numeroJetonJ2=0;

    printf("\nNom joueur 1: ");
    nomJoueur1=saisirChaine;
    printf("\nNom joueur 2: ");
    nomJoueur2=saisirChaine;

    numeroJetonJ1=rand()% 9;
    do      ///on verifie que les deux jetons sont les même.
    {
        numeroJetonJ2=rand()% ;
    }while numeroJetonJ2==numeroJetonJ1;

    printf("joueur 1 : %s (%c)",nomJoueur1,jetons[numeroJetonJ1])



}

void lancerPartiesauvegardee()
{

}

void afficherAide()
{

}

void afficherScores()
{

}




void afficherGrille(Plateau *plateau)
{
    system("cls");
    int i,j;
    color(0,15);
    //LIGNE DU PLATEAU
    for (i=0; i<plateau->m_tailleY*2+2; i+=2)
    {
        for(j=0; j<plateau->m_tailleX*2+2; j+=2)
        {


            if (j!=plateau->m_tailleX*2)
            {
                gotoligcol(2+i,3+j);
                printf("%c",197);
                gotoligcol(2+i,2+j);
                printf("%c",196);
            }
            if (i!=plateau->m_tailleY*2)
            {
                gotoligcol(3+i,1+j);
                printf("%c",179);
            }
        }
    }
///On pose les 4 angles
    //Haut Gauche
    gotoligcol(2,1);
    printf("%c",218);
    //Bas Gauche
    gotoligcol(plateau->m_tailleY*2+2,1);
    printf("%c",192);
    //Haut Droite
    gotoligcol(2,plateau->m_tailleX*2+1);
    printf("%c",191);
    //Bas droite
    gotoligcol(plateau->m_tailleY*2+2,plateau->m_tailleX*2+1);
    printf("%c",217);
    ///On fait les contours speciaux du cadre
    //Cote Gauche et droite
    for (i=0; i<plateau->m_tailleY*2-2; i+=2)
    {
        gotoligcol(4+i,1);
        printf("%c",195);
        //Droite
        gotoligcol(4+i,plateau->m_tailleX*2+1);
        printf("%c",180);
    }
//Haut et bas
    for (i=0; i<plateau->m_tailleX*2-2; i+=2)
    {
        gotoligcol(2+plateau->m_tailleY*2,3+i);
        printf("%c",193);
        //Haut
        gotoligcol(2,3+i);
        printf("%c",194);
    }
}
