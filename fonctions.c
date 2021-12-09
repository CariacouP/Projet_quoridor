#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "structures.h"
#include "fonctions.h"
#include "alexis.h"
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




char *saisirChaine(){
///renvoie le pointeur de la chaine de caract�re saisie allou�e dynamiquement
    char *chaine;
    char temp[NC];
    fflush(stdin);
    gets(temp);
    chaine=(char*)malloc(sizeof(char)*strlen(temp)+1);
    strcpy(chaine,temp);
    return chaine;
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


void afficherGrilleVide(int m_tailleX,int m_tailleY)
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
    char lig=(coor.ligne);
    l=(int)lig-64;
    gotoligcol(l*2+1,(coor.colonne)*3);
    
}

void placerBarriere(t_coordonneeG coor,int sens){
// place une barrière en fonction de la valeur du sens choisi (attention à bien blinder la saisie) en haut (1), à droite (2), en bas (3), gauche(4)
    int l,col;
    l=(int) (coor.ligne) -64;
    col=(coor.colonne);
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
    (coorM.ligne)=((int) (coorG.ligne)-65)*2;
    (coorM.colonne)= (coorG.colonne)*2-2;
    return coorM;
}


t_coordonneeG coordoneeMatriceversCoordGrille(t_coordonneeM  coorM){
    t_coordonneeG  coorG;
    (coorG.ligne)=(char)(((coorM.ligne)/2)+65);
    (coorG.colonne)= ((coorM.colonne)/2)+1;
    return coorG;
}

t_coordonneeG remplircoordonneeG(int taillePlateau){
    // fonction de saisie de coordonees
    t_coordonneeG coor;
    char lig;
    int col;
   do{
        gotoligcol(40,60);
        fflush(stdin);
        printf("Ligne grille: ");
        scanf("%c",&lig);
        }while ( ( ((int) lig)<65 )|| ( ((int)lig )>(65+taillePlateau) ) );// on verifie que les valeurs saisies sont correct

    do{
        gotoligcol(42,60);
        printf("Colonne grille: ");
        fflush(stdin);
        scanf("%d",&col);
    }while( ( col<1) ||(col>taillePlateau)); //blindage de la saisie
    coor.ligne=lig;
    coor.colonne=col;
    return coor;
}

void afficherPiondepuisMatrice(t_coordonneeM coorM, t_joueur joueur ){
    int pion;
    t_coordonneeG coorG;
    coorG=coordoneeMatriceversCoordGrille(coorM);
    allerCase(coorG);
    pion=(joueur.pion);
    printf("%c", pion);
    joueur.coordonneeGrille=coorG;
}

void afficherCaseVideDepuisMatrice(t_coordonneeM coorM){
    t_coordonneeG coorG;
    coorG=coordoneeMatriceversCoordGrille(coorM);
    allerCase(coorG);
    printf(" ");
}

t_joueur creerJoueur(int iemejoueur, int listePionUtilise[8], int taillePlateau){
    // on crée la fonction qui va définir un joueur intialement et lui donner ca position initial la variable "ième joueur" sers à décider à quel poisition il débute
    int i;
    t_joueur joueur;
    int listePions[8];
    int pion ;
    listePions[0]=0x40;
    listePions[1]=0x2A;
    listePions[2]=0x23;
    listePions[3]=0x26;
    listePions[4]=0x25;
    listePions[5]=0xA3;
    listePions[6]=0x24;
    listePions[7]=0x3F;



    t_coordonneeG coorG;
    t_coordonneeM coorM;


    printf("\n saisissez votre nom : ");
    fflush(stdin);
    gets(joueur.nom);
    joueur.score=0;
    joueur.barriere_posees=20;
    do     // on veut attriber un jeton aléatoirement tout en verifiant qu'il n'a pas déjà été attribué
    {
       pion=listePions[rand()%9] ;
    }while (pionsUtilise(listePionUtilise,pion)==1);
    
    while (listePionUtilise[i]==0){
        i++;
    }
    listePionUtilise[i]=pion;
    joueur.pion=pion;
    joueur.nbCoupAnnule=1;
    joueur.pionM=iemejoueur+1;
    switch (iemejoueur)
    {
    case 1 :
        coorG.ligne='A';
        coorG.colonne= 5;
        joueur.coordonneeGrille=coorG;
        coorM=coordonneGrilleVersCoordMatrice(coorG);
        joueur.coordonneeMatrice=coorM;

        break;
    case 2 :
       if (taillePlateau==9){
            coorG.ligne='I';
            coorG.colonne= 5;
            joueur.coordonneeGrille=coorG;
            coorM=coordonneGrilleVersCoordMatrice(coorG);
            joueur.coordonneeMatrice=coorM;
       }
       else if (taillePlateau==12){
            coorG.ligne='L';
            coorG.colonne= 6;
            joueur.coordonneeGrille=coorG;
            coorM=coordonneGrilleVersCoordMatrice(coorG);
            joueur.coordonneeMatrice=coorM;

       }
       break;
    case 3 :
        if (taillePlateau==9)  {
            coorG.ligne='E';
            coorG.colonne= 1;
            joueur.coordonneeGrille=coorG;
            coorM=coordonneGrilleVersCoordMatrice(coorG);
            joueur.coordonneeMatrice=coorM;
        }
        else if (taillePlateau==12){
            coorG.ligne='F';
            coorG.colonne= 1;
            joueur.coordonneeGrille=coorG;
            coorM=coordonneGrilleVersCoordMatrice(coorG);
            joueur.coordonneeMatrice=coorM;
        }
        else {
            printf("erreur de taille du tableau");
        }
        break;
    case 4:
         if (taillePlateau==9)  {
            coorG.ligne='E';
            coorG.colonne= 9;
            joueur.coordonneeGrille=coorG;
            coorM=coordonneGrilleVersCoordMatrice(coorG);
            joueur.coordonneeMatrice=coorM;
        }

        else if (taillePlateau==12){
            coorG.ligne='F';
            coorG.colonne= 12;
            joueur.coordonneeGrille=coorG;
            coorM=coordonneGrilleVersCoordMatrice(coorG);
            joueur.coordonneeMatrice=coorM;
        }

        else {
            printf("erreur de taille du tableau");
        }
    default:
        break;
    }
    return joueur;
}


int pionsUtilise(int listePionsUtilise[8],int pion){
    // verifie si le ion demandé est déjà utilisé par un joueur, renvoie une valeur booléenne

    for(int i=0;i<8;i++){
        if (pion==listePionsUtilise[i]){
            return 1;
        }
    }
    return 0;
}

void lancerNouvellePartie(int nombreJoueur,int taillePlateau,t_joueur joueur[4]){
///Lance une nouvelle partie et crée le nombre voulu de joueur 
    system("cls");
    color(0,15);
    int listePionUtilise[8];
    for (int i=0;i<8;i++){
                listePionUtilise[i]=0;
            }
    switch (nombreJoueur)
    {
    case 2 :
        printf(" \n creation du 1er joueur ");
        joueur[0]=creerJoueur(1, listePionUtilise,  taillePlateau);
        printf(" \n création du 2eme joueur ");
        joueur[1]=creerJoueur(2, listePionUtilise,  taillePlateau);
       break;
    case 4 :
        printf(" \n creation du 1er joueur ");
        joueur[0]=creerJoueur(1, listePionUtilise,  taillePlateau);
        
        printf(" \n creation du 2eme joueur ");
        joueur[1]=creerJoueur(2, listePionUtilise,  taillePlateau);

         printf(" \n creation du 3eme joueur ");
        joueur[2]=creerJoueur(3, listePionUtilise,  taillePlateau);
         
        printf(" \n creation du 4eme joueur ");
        joueur[3]=creerJoueur(4, listePionUtilise,  taillePlateau);
        
        break;
    default:
        break;
    }



}

void afficherJeu9(int matrice[17][17],t_joueur listejoueurs[4]){
    // fonction qui parcours la matrice pour un jeu de 9*9 et qui affiche le jeu sur la grille
    t_coordonneeM coorM,coorMpourPlacerBarriere;
    t_coordonneeG coorG;
    t_joueur joueurAPlacer;
    int i,j;
    afficherGrilleVide(9,9);
// affichage des pions des joueurs sur la grilles
    for (i=0;i<17;i+=2){
        for(j=0;j<17;j+=2){
            if (matrice[i][j]==1){
                printf("ERREUR UNE BARRIERE EST A L'INTERRIEUR D'UNE CASE");
            }
            else if (matrice[i][j]!=0){
                joueurAPlacer=listejoueurs[matrice[i][j]-2];
                coorM.ligne=i;
                coorM.colonne=j;
                afficherPiondepuisMatrice(coorM,joueurAPlacer);
            }
            else {
                coorM.ligne=i;
                coorM.colonne=j;
                coorG=coordoneeMatriceversCoordGrille(coorM);
                allerCase(coorG);
                printf(" ");
            }

        }
    }
// affichage des barrières sur la grille
    for (i=0;i<17;i++){
        for (j=1;j<17;j+=2){
            if (matrice[i][j]!=1 && matrice[i][j]!=0){
                printf("ERREUR UN pion  EST sur une barrière");
            }
            else if (matrice[i][j]==1){
                if (i%2==0){//si la barrière est vertical
                    coorMpourPlacerBarriere.ligne=i;
                    coorMpourPlacerBarriere.colonne=j-1;
                    coorG=coordoneeMatriceversCoordGrille(coorMpourPlacerBarriere);
                    placerBarriere(coorG,2);
                }

                else if (i%2!=0){ // si la barrière est horizontal
                    coorMpourPlacerBarriere.ligne=i-1;
                    coorMpourPlacerBarriere.colonne=j;
                    coorG=coordoneeMatriceversCoordGrille(coorMpourPlacerBarriere);
                    placerBarriere(coorG,1);
                }

            }
        }

    }
}
void afficherJeu12(int matrice[23][23],t_joueur listejoueurs[4]){
    // fonction qui parcours la matrice pour un jeu de 9*9 et qui affiche le jeu sur la grille
    t_coordonneeM coorM,coorMpourPlacerBarriere;
    t_coordonneeG coorG;
    t_joueur joueurAPlacer;
    int i,j;
    afficherGrilleVide(12,12);

// affichage des pions des joueurs sur la grilles
    for (i=0;i<23;i+=2){
        for(j=0;j<23;j+=2){
            if (matrice[i][j]==1){
                printf("ERREUR UNE BARRIERE EST A L'INTERRIEUR D'UNE CASE");
            }
            else if (matrice[i][j]!=0){
                joueurAPlacer=listejoueurs[matrice[i][j]-2];
                coorM.ligne=i;
                coorM.colonne=j;
                afficherPiondepuisMatrice(coorM,joueurAPlacer);
            }
            else if (matrice[i][j]==0){
                coorM.ligne=i;
                coorM.colonne=j;
                afficherCaseVideDepuisMatrice(coorM);

            }

        }
    }

// affichage des barrières sur la grille
    for (i=0;i<23;i++){
        for (j=1;j<23;j+=2){
            if (matrice[i][j]!=1 && matrice[i][j]!=0){
                printf("ERREUR UN pion  EST sur une barrière");
            }
            else if (matrice[i][j]==1){
                if (i%2==0){//si la barrière est vertical
                    coorMpourPlacerBarriere.ligne=i;
                    coorMpourPlacerBarriere.colonne=j-1;
                    coorG=coordoneeMatriceversCoordGrille(coorMpourPlacerBarriere);
                    placerBarriere(coorG,2);
                }

                else if (i%2!=0){ // si la barrière est horizontal
                    coorMpourPlacerBarriere.ligne=i-1;
                    coorMpourPlacerBarriere.colonne=j;
                    coorG=coordoneeMatriceversCoordGrille(coorMpourPlacerBarriere);
                    placerBarriere(coorG,1);
                }

            }
        }

    }

}

t_barriereG choixBarrierre(int taillePlateau){
    t_barriereG barriere;
    int sens;
    barriere.coorG1=remplircoordonneeG(taillePlateau);
    barriere.coorG2=remplircoordonneeG(taillePlateau);
    printf(" Choisissez l'orientation de la barrière par rapport aux 2 cases choisies en haut (1), à droite (2), en bas (3), gauche(4). Attention a choisir un sens possible");
    do {
        scanf("%d",&sens);
    }while ( ( (barriere.coorG1.ligne==barriere.coorG2.ligne) && ((sens==2)||(sens==4)) ) || ( (barriere.coorG1.colonne==barriere.coorG2.colonne) && ((sens==1)||(sens==3)) ) );
//on verifie que le sens saisie est possible ( si on a pris 2 cases horizontales on ne peut pas poser les barrières verticalement et vice versa)
    barriere.sens=sens;
    return barriere;

}

void placerBarriereGdansMatrice(t_barriereG barriere, int matrice[17][17]){

    t_coordonneeM coorM1;
    t_coordonneeM coorM2;
    int sens ;
    sens=barriere.sens;

    coorM1=coordonneGrilleVersCoordMatrice(barriere.coorG1);
    coorM2=coordonneGrilleVersCoordMatrice(barriere.coorG2);

    switch (sens){
        //on décale la barrière dans la bonne case de la matrice en fonction du sens dans lequel on a posé la barrière 
    case 1:
        coorM1.ligne-=1;
        coorM2.ligne-=1;
        break;
    case 2:
        coorM1.colonne+=1;
        coorM2.colonne+=1;
        break;
    case 3:
        coorM1.ligne+=1;
        coorM2.ligne+=1;
        break;
    case 4:
        coorM1.colonne-=1;
        coorM2.colonne-=1;
        break;
    
    default:
        break;
    }

    matrice[coorM1.ligne][coorM1.colonne]=1;
    matrice[coorM2.ligne][coorM2.colonne]=1;


}

void initialiserMatrice9 (int matrice[17][17],t_joueur joueur[4])
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
    
    for (i=0;i<4;i++){
        // On va placer les joueurs qui ont été intialisé et qui sont présent dans la liste de joueurs
        if (joueur[i].pionM<6 && joueur[i].pionM>1 ){
            // on verifie que le joueur i existe et été intitialisé correctement avant de traiter le cas
            matrice[joueur[i].coordonneeMatrice.ligne][joueur[i].coordonneeMatrice.colonne]=joueur[i].pionM;
        }
    }
}

void initialiserMatrice12 (int matrice[23][23],t_joueur joueur[4])
{
    int i,j;
    for (i=0;i<23;i++)
    {
        for (j=0;j<23;j++)
        {
            matrice[i][j]=0;
           // printf("Ici\n");
        }
    }

    for (i=0;i<4;i++){
        // On va placer les joueurs qui ont été intialisé et qui sont présent dans la liste de joueurs
        if (joueur[i].pionM<6 && joueur[i].pionM>1 ){
            // on verifie que le joueur i existe et été intitialisé correctement avant de traiter le cas
            matrice[joueur[i].coordonneeMatrice.ligne][joueur[i].coordonneeMatrice.colonne]=joueur[i].pionM;
        }
    }
}

void jouerSontour9(int iemeJoueur, t_joueur joueurs[4] ,int nombreJoueur,int taillePlateau, int matrice[17][17]){
    int choixAction;
    gotoligcol(2,60); // garder ces coordoonées en mémoir elles se toruve à l'extérieur à droite du plateau
    printf("Au tour de %s : %c ",joueurs[iemeJoueur-1].nom,joueurs[iemeJoueur-1].pion);
    gotoligcol(4,60);
    printf("score : %d",joueurs[iemeJoueur-1].score);
    gotoligcol(6,60);
    printf("nombre de barriere restante: %d",joueurs[iemeJoueur-1].barriere_posees);
    gotoligcol(8,60);
    printf("nombre de coups a annuler restant: %d",joueurs[iemeJoueur-1].nbCoupAnnule);
    gotoligcol(10,60);
    printf("quelle action voulez vous effectuer ?");
    gotoligcol(12,60);
    printf("1.Me deplacer");
    gotoligcol(14,60);
    printf("2.Poser une barriere");
    gotoligcol(16,60);
    printf("3.Annuler le coup du joueur precedent");
    gotoligcol(18,60);
    printf("4.Sauvegarder et quitter");
    gotoligcol(20,60);
    do{
        fflush(stdin);
        scanf("%d",choixAction);
    }while( (choixAction<1) && (choixAction>4) );

    switch (choixAction)
    {
    case 1:{
        t_coordonneeM coordonneeVoulu;
        t_coordonneeG coordonneeVouluG;
        gotoligcol(38,60);
        printf("Saisir les coordonees ou vous souhaitez vous déplacer");
        coordonneeVouluG=remplircoordonneeG(taillePlateau);
        coordonneeVoulu = coordonneGrilleVersCoordMatrice(coordonneeVouluG);
        deplacerPion(coordonneeVoulu,joueurs[iemeJoueur-1],matrice);
        afficher9(matrice);
        
        
    }
        break;
    case 2:
        gotoligcol(38,60);
        printf("Saisir les coordonees des deux case le long desquels sera la barrière ainsi que l'orientation par rapport a ces cases");
        choixBarrierre(taillePlateau);
        
        break;
    case 3:
       
        break;
    case 4:
       
        break;
    
    default:
        break;
    }


    

}

void enregistrerPartie9(int matrice[17][17], t_joueur joueurs[4],int nombreJoueur ){
    char nomPartie[20];
    char tmp[256];
    int i,j;
    FILE *fichier ;
    getcwd(tmp,256);
    strcat((getcwd(tmp, 256)),"\\Parties_sauvegardee\\");
    printf("%s",tmp);
    gotoligcol(22,60);
    printf("quel nom pour la partie (doit finir en .txt) ?");
    gotoligcol(24,60);
    fflush(stdin);
    gets(nomPartie);
    strcat(tmp,nomPartie);
    printf("%s",tmp);
    fichier=fopen( tmp,'w');
    if(fichier==NULL){
        printf("erreur d'ouverture du fichier");
    }
    else{

        for (i=0;i<nombreJoueur;i++){
            fprintf(fichier,"%s\n",joueurs[i].nom);
            fprintf(fichier,"%d\n",joueurs[i].pion);
            fprintf(fichier,"%d\n",joueurs[i].pionM);
            fprintf(fichier,"%d\n",joueurs[i].coordonneeMatrice.ligne);
            fprintf(fichier,"%d\n",joueurs[i].coordonneeMatrice.colonne);
            fprintf(fichier,"%c\n",joueurs[i].coordonneeGrille.ligne);
            fprintf(fichier,"%c\n",joueurs[i].coordonneeGrille.colonne);
            fprintf(fichier,"%d\n",joueurs[i].score);
            fprintf(fichier,"%d\n",joueurs[i].barriere_posees);
            fprintf(fichier,"%d\n",joueurs[i].nbCoupAnnule);

        }
        for (i=0;i<17;i++){
            for (j=0;j<17;j++){
                 fprintf(fichier,"%d\n",matrice[i][j]);

            }
        }
        fclose(fichier);
    }
}