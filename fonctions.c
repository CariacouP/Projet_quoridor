#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "fonctions.h"
#define NC 100


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
///renvoie le pointeur de la chaine de caract�re saisie allou�e dynamiquement
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
    /*
    /// saisie des noms des joueurs
    char nomJoueur1=NULL;
    char nomJoueur2=NULL;
    char jetons[8]=[0x40,0x2A,0x23,0x26,0x25,0xA3,0x24,0x3F]; ///Listes des diff�rents jetons possible pour les joueurs
    int numeroJetonJ1=0;
    int numeroJetonJ2=0;

    printf("\nNom joueur 1: ");
    nomJoueur1=saisirChaine;
    printf("\nNom joueur 2: ");
    nomJoueur2=saisirChaine;

    numeroJetonJ1=rand()% 9;
    do      ///on verifie que les deux jetons sont les m�me.
    {
        numeroJetonJ2=rand()%9 ;
    }while (numeroJetonJ2==numeroJetonJ1);

    printf("joueur 1 : %s (%c)",nomJoueur1,jetons[numeroJetonJ1]);

*/

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


void afficherGrille(int m_tailleX,int m_tailleY)
{
    system("cls");
    int i,j,l,k;
    color(0,15);
    //LIGNE DU PLATEAU
    for (i=0; i<m_tailleY*2+2; i+=2)
    {
        for(j=0; j<m_tailleX*3+3; j+=3)
        {


            if (j!=m_tailleX*3)
            {
                gotoligcol(2+i,4+j);
                printf("%c",197);
                gotoligcol(2+i,2+j);
                printf("%c",196);
                printf("%c",196);
            }
            if (i!=m_tailleY*2)
            {
                gotoligcol(3+i,j+1);
                printf("%c",179);
            }
        }
    }
///On pose les 4 angles
    //Haut Gauche
    gotoligcol(2,1);
    printf("%c",218);
    //Bas Gauche
    gotoligcol(m_tailleY*2+2,1);
    printf("%c",192);
    //Haut Droite
    gotoligcol(2,m_tailleX*3+1);
    printf("%c",191);
    //Bas droite
    gotoligcol(m_tailleY*2+2,m_tailleX*3+1);
    printf("%c",217);
    ///On fait les contours speciaux du cadre
    //Cote Gauche et droite
    l=65;
    for (i=0; i<m_tailleY*2-2; i+=2)
    {
        gotoligcol(3+i,0);
        printf("%c",l); // on ajoute la lettre correspndante a la ligne à gauche du tableau
        gotoligcol(4+i,1); 
        printf("%c",195);
        //Droite
        gotoligcol(4+i,m_tailleX*3+1);
        printf("%c",180);
        l++;
    }
    
    gotoligcol(3+i,0);      //on ajoute la dernière lettre manquante
    printf("%c",l);
//Haut et bas
    k=1;
    for (i=0; i<m_tailleX*3-3; i+=3)
    {
        gotoligcol(2+m_tailleY*2,3+i+1);
        printf("%c",193);
        //Haut
        gotoligcol(1,2+i); //On ajoute le chiffre correspondant aux collones en haut du tableau
        printf("%d",k);
        gotoligcol(2,3+i+1);
        printf("%c",194);
        k++;
    }
    gotoligcol(1,2+i); //On ajoute le dernier  chiffre correspondant à la dernière collone en haut du tableau
    printf("%d",k);
}

void allerCase(char ligne, int colonne){
    int l;
    l=(int) ligne-64;
    gotoligcol(l*2+1,colonne*3);
    printf("%c",64);
}

void placerBarriere(char ligne, int colonne,int sens){
// place une barrière en fonction de la valeur du sens choisi (attention à bien blinder la saisie) en haut (1), à droite (2), en bas (3), gauche(4)
    int l;
    l=(int) ligne-64;
    switch(sens){
        case 1:
            gotoligcol(l*2,colonne*3);
            printf("B");
            break;
        case 2:
            gotoligcol(l*2+1,colonne*3+1);
            printf("B");
            break;
        case 3:
            gotoligcol(l*2+2,colonne*3);
            printf("B");
            break;
        case 4:
            gotoligcol(l*2+1,colonne*3-2);
            printf("B");
            break;
        default:
            printf("erreur dans la saisie du sens");
            break;
    }
}