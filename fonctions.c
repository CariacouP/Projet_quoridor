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

void allerCase(t_coordonneeG coor){
    int l;
    l=(int) coor.ligne-64;
    gotoligcol(l*2+1,coor.colonne*3);
    printf("%c",64);
}

void placerBarriere(t_coordonneeG coor,int sens){
// place une barrière en fonction de la valeur du sens choisi (attention à bien blinder la saisie) en haut (1), à droite (2), en bas (3), gauche(4)
    int l;
    l=(int) coor.ligne -64;
    col=coor.colonne
    switch(sens){
        case 1:
            gotoligcol(l*2,col*3);
            printf("B");
            break;
        case 2:
            gotoligcol(l*2+1,col*3+1);
            printf("B");
            break;
        case 3:
            gotoligcol(l*2+2,col*3);
            printf("B");
            break;
        case 4:
            gotoligcol(l*2+1,col*3-2);
            printf("B");
            break;
        default:
            printf("erreur dans la saisie du sens");
            break;
    }
}

t_coordonneeM coordonneGrilleVersCoordMatrice(t_coordonneeG coorG){
t_coordonneeM  coorM;
coorM.ligne=((int coorG->ligne)-65)*2
coorM.colonne= coorG->colonne*2
return coorM;
}


t_coordonneeG coordoneeMatriceversCoordGrille(t_coordonneeM  coorM){
    t_coordonneeG  coorG;
    coorG.ligne=(coorM+65)/2;
    cooG.colonne= colonneGrille/2;
    return coorG;
}


void afficherPiondepuisMatrice(t_coordonneeM coorM, t_joueur *joueur ){
    int pion;
    t_coordonneeG coorG;
    coorG=void coordoneeMatriceversCoordGrille(coorM,coorG);
    allerCase(coorG);
    pion=*(joueur->pion);
    printf("%c", pion);
    *(joueur->coordoneeGrille)=coorG;
}

t_joueur créerJoueur(int iemejoueur, char listePionUtilise[8], taillePlateau){ 
    // on crée la fonction qui va définir un joueur intialement et lui donner ca position initial la variable "ième joueur" sers à décider à quel poisition il débute
    int i
    t_joueur joueur;
    char listePions[8]=[0x40,0x2A,0x23,0x26,0x25,0xA3,0x24,0x3F];
    int pion ;
    t_coordonneeG coorG;
    t_coordonneeM coorM;


    printf("saisissez votre nom");
    jouer->nom=saisirChaine();
    joueur->score=0;
    joueur->barrière=20;
    do     // on veut attriber un jeton aléatoirement tout en verifiant qu'il n'a pas déjà été attribué
    {
       pion=listePions[rand()%9] ;
    }while (pionestUtilise(char[8] listePionsUtilise,pion)==1);
    while (listePionUtilise[i]=0){
        i++;
    }
    listePionsUtilise[i]=pion;
    joueur.nbCoupAnnule=1;
    switch (iemejoueur)
    {
    case 1 :
        coorG->ligne="A";
        cooreG->colonne= "5";
        joueur->coordonneegrillee=coorG;
        coorM=coordonneGrilleVersCoordMatrice(coorG);
        joueur->coordonneMatrice=coorM;

        break;
    case 2 
        coorG->ligne="I";
        cooreG->colonne= "5";
        joueur->coordonneegrillee=coorG;
        coorM=coordonneGrilleVersCoordMatrice(coorG);
        joueur->coordonneMatrice=coorM;
    case 3 :
        if (taillePlateau==9)  {
            coorG->ligne="E";
            cooreG->colonne= "1";
            joueur->coordonneegrillee=coorG;
            coorM=coordonneGrilleVersCoordMatrice(coorG);
            joueur->coordonneMatrice=coorM;
        }
        else if (taillePlateau==12){
            coorG->ligne="F";
            cooreG->colonne= "1";
            joueur->coordonneegrillee=coorG;
            coorM=coordonneGrilleVersCoordMatrice(coorG);
            joueur->coordonneMatrice=coorM;
        }
        else {
            printf("erreur de taille du tableau");
        }
        break;
    case 4:
         if (taillePlateau==9)  {
            coorG->ligne="E";
            cooreG->colonne= "12";
            joueur->coordonneegrillee=coorG;
            coorM=coordonneGrilleVersCoordMatrice(coorG);
            joueur->coordonneMatrice=coorM;
        }

        else if (taillePlateau==12){
            coorG->ligne="F";
            cooreG->colonne= "12";
            joueur->coordonneegrillee=coorG;
            coorM=coordonneGrilleVersCoordMatrice(coorG);
            joueur->coordonneMatrice=coorM;

        else {
            printf("erreur de taille du tableau");
        }
    default:
        break;
    }
    
}

int pionestUtilise(char[8] listePionsUtilise,pion){
    
    for(int i=0;i<;i++){
        if (pion==listePionUtilise[i]){
            return 1;
        }
    }
    return 0;
}
