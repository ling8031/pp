#include <stdio.h>
#include <stdlib.h>


void wypisz_tab(const int *t,int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ",t[i]);
    }
}

void merge(int *t1,int n1, int *t2,int n2, int *dest,int dSize)
{
    int i,j,k;
    i = j = k = 0;
    while(k <= dSize-1)
    {
        if(t1[i]>t2[j] || i == n1)
        {
            dest[k] = t2[j];
            j++;
            k++;
        }
        else if(t1[i]<= t2[j] || j == n2)
        {
            dest[k] = t1[i];
            i++;
            k++;
        }
    }
}


int main()
{
    int n1,n2,*t1,*t2;

    scanf("%d %d",&n1,&n2);
    t1 = (int *) malloc(n1*sizeof(int));
    t2 = (int *) malloc(n2*sizeof(int));
    for(int i = 0; i < n1; i++)
    {
        scanf("%d",&(t1[i]));
    }
    for(int i = 0; i < n2; i++)
    {
        scanf("%d",&(t2[i]));
    }
    int dSize = n1+n2;
    int *wynik = (int *) malloc(dSize*sizeof(int));
    merge(t1,n1,t2,n2,wynik,dSize);
    wypisz_tab(wynik,dSize);

    free(wynik);
    free(t1);
    free(t2);
}