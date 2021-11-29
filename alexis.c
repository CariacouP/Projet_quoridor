#include <stdio.h>
#include <stdlib.h>


void initialiserPlateau (int* plateau[17][17])
{
    int i,j;
    for (i=0;i<17;i++)
    {
        for (j=0;j<17;j++)
        {
            *(plateau[i][j])=0;
           // printf("Ici\n");
        }
    }
}


void deplacerPion(int i,int j,int i1,int j1,int* plateau[17][17])
{
    *(plateau[i1][j1])=1;
    *(plateau[i][j])=0;
}

void afficher(int* plateau[17][17])
{
    int i,j;
    for (i=0;i<17;i++)
    {
        for (j=0;j<17;j++)
        {
            if (*(plateau[i][j])==1)
                {
                    printf("%c",'P');
                }
        }
    }
}
/*
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
*/