#include <stdio.h>
#include <stdlib.h>

void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortuj(int* tab,int n)
{
    for(int i = n-1; i >= 1; i--)
    {
        for(int j = 1; j <= i; j++)
        {
            if(tab[j-1]>tab[j])
            {
                swap(&tab[j-1],&tab[j]);
            }
        }
    }
}

int main()
{
    int n,k,temp;
    scanf("%d %d",&n,&k);

    int* tab = (int *)malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&temp);
        tab[i] = temp%k;
    } 

    sortuj(tab,n);

    for(int i = 0; i < n; i++)
    {
        printf("%d ",tab[i]);
    } 

    return 0;
}