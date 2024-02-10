#include <stdio.h>




int n = 10;
int a[7000][7000];




int main()
{



    int x;


    try_again:
    printf(" option 1. n = 1000\n ");
    printf("option 2. n = 2000\n ");
    printf("option 3. n = 3000\n ");
    printf("option 4. n = 4000\n ");
    printf("option 5. n = 5000\n ");
    printf("\nPlease select the vertices size option:-");

    scanf("%d",&x);

    system("cls");

    switch(x)
    {
        case 1: n=1000;
        break;
        case 2: n=2000;
        break;
        case 3: n=3000;
        break;
        case 4: n=4000;
        break;
        case 5: n=5000;
        break;
        default:
            printf("Please Try Again with a valid choice.\n");
            goto try_again;
    }


    double start = clock();
    srand(time(0));
    randomEdge(a,n);
    nonRepeatingEdge(a,n);
    AdjMatrix(a,n);

      double stop= clock()-start;

        printf("\n");
        showIndegree(a,n);
        printf("\n");
        showOutdegree(a,n);

    return 0;
}

void AdjMatrix(int a[n][n],int size)
    {
        for(int i=0; i<size; i++)
            for(int j=0;j<size; j++)
                for(int k=j;k<size;k++)
                    if(a[i][k]!=0)
                        a[i][k]=1;
    }


 void nonRepeatingEdge(int a[n][n],int x)
 {
     for(int i=0; i<x; i++)
            for(int j=0;j<x; j++)
                for(int k=j+1;k<x; k++)
                    if(a[i][j]== a[i][k])
                        a[i][k]=0;
 }

void randomEdge(int a[n][n],int x)
   {
    for(int i=0; i<x; i++)
        for(int j=0;j<x; j++)
            a[i][j]= rand()%x+1;
   }


void printAdjMatrix(int a[n][n],int x)
{
    for(int i=0; i<x; i++)
        {
            for(int j=0; j<x;j++)
            printf("%d ",a[i][j]);
            printf("\n");
        }
}

void showOutdegree(int a[n][n],int x)
{
    for(int i=0; i<x; i++){
        int sumO=0;
        for(int j=0;j<x; j++)
                sumO+=a[i][j];

    printf("\nV-%d out degree: %d",i+1,sumO);
    }
return 0;
}

void showIndegree(int a[n][n], int x)
{
    for(int i=0; i<x; i++){
        int sum1=0;
        for(int j=0;j<x; j++)
                sum1+=a[j][i];

    printf("\nV-%d In degree: %d",i+1,sum1);
    }




return 0;
}
