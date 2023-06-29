#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void initiArray(int x[]);
void printArray(int x[]);
void sumdiff(int x[],int y[][5]);//in 2D matrix uppaer diagonal will contain the sum of elements pair and lower triangle will contain absolute difference.
void find(int x[],int y[][5]);

int main(void)
{
 int a[5];
 initiArray(a);
 printArray(a);
 puts("");
 int b[5][5];
 sumdiff(a,b);
 /*for(int i=0;i<5;i++)
 {
     for(int j=0;j<5;j++)
     {
         printf("%d ",b[i][j]);
     }
     puts("");
 }*/
 find(a,b);
}

void initiArray(int x[])
{
    srand(time(NULL));
    for(int i=0;i<5;i++)
    {
        x[i]=(rand()%11)-5;
    }
}

void printArray(int x[])
{
    for(int i=0;i<5;i++)
    {
        printf("%d ",x[i]);
    }
}

void sumdiff(int x[],int y[][5])
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(i==j)
            {
                y[i][j]=11;
            }
            else if(i<j)
            {
                y[i][j]=x[i]+x[j];
            }
            else
            {
                y[i][j]=abs(x[i]-x[j]);
            }
        }
    }
}

void find(int x[],int y[][5])
{
    int minsum=11;
    int minabdiff=11;
    int m=0;
    int n=0;
    for(int i=0;i<4;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(abs(y[i][j])<minsum)
            {
                minsum=abs(y[i][j]);
                minabdiff=y[j][i];
                m=i;
                n=j;
            }
            else if(abs(y[i][j])==minsum)
            {
                if(minabdiff<y[j][i])
                {
                  minabdiff=y[j][i];
                  m=i;
                  n=j;
                }
            }
        }
    }
    printf("The pair is %d and %d ,with sum %d and absolute difference %d",x[m],x[n],y[m][n],y[n][m]);
}
