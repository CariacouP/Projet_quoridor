//#include <stdio.h>
//#include <stdlib.h>


void initialiserPlateau (int* plateau[17][17])
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


void deplacerPion(int i,int j,int i1,int j1,int* plateau[17][17])
{
    plateau[i1][j1]=1;
    plateau[i][j]=0;
}

void afficher(int* plateau[17][17])
{
    int i,j;
    for (i=0;i<17;i++)
    {
        for (j=0;j<17;j++)
        {
            if (plateau[i][j]==1
                {
                    printf("%c",'P');
                }
        }
    }
}

int main()
{
    int* plateau[17][17];
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
    return 0;
}

void placerBarriere(char ligne, int colonne)
{
    if((ligne%2!=0)&&(colonne%2!=0)&&(ligne<17)&&(colonne!=17))
    {
        if (plateau[ligne][colonne]!=0)
        {
            plateau[ligne][colonne]=0;
        }
        else
        {
            printf("erreur il y a deja une barriere ! ");
        }
    }
    else
    {
        printf("c est l endroit ou on place les pions pas de barriere ! ");
    }
}

void allerCase(char ligne, int colonne)
{
    if((ligne%2==0)&&(colonne%2==0)&&(ligne<17)&&(colonne<17))
    {
        if()//La case entre celle ou il est et celle ou il veut aller il y a une barriere... il faut une fonction case à l'instant t.
        {
            printf("impossible de se deplacer il y a une barriere et tu n es pas un fantome voyons...");
        }
        if(plateau[ligne][colonne]==pion)//creer une fonction booleenne qui renvoie true si pion correspond à un carac de pion, false sinon.
        {
            printf("il y a deja un pion a cet endroit, choisir de sauter le pion ou d annuler");
            int i=1;
            while (i>0)
            {
                allerCase(ligne1,colonne1);
                if((abs(ligne1-ligne)>1)||(abs(colonne1-colonne)>1)||((abs(ligne1-ligne)+abs(colonne1-colonne)>1)))
                {
                    printf("saisie incorrecte la case est trop eloignee");
                }
                else
                {
                    plateau[ligne][colonne]=pion; //le pion du joueur concerné
                }
            }
        }
        
    }
}