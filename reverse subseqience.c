#include <stdio.h>

void wczytaj_tab(int *t, int n)
{
    int temp;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&temp);
        t[i] = temp;
        
    }
    printf("\n");
}

void wypisz_tab(int *tab, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }
     printf("\n");
}

int czySieMiesci(int x, int l, int u)
{
    if(x >= l && x <= u)
    return 0;
    else return -1;
}

void zamien(int *tab, int in1, int in2)
{
    int temp = tab[in1];
    tab[in1] = tab[in2];
    tab[in2] = temp;
}

void solve(int *tab, int n, int l, int u)
{
    int p = 0;
    int k = n-1;

    while(p < k)
    {
        if(czySieMiesci(tab[p],l,u)==0 && czySieMiesci(tab[k],l,u)==0)
        {
            zamien(tab,p,k);
            p++;
            k--;
        }
        else if(czySieMiesci(tab[p],l,u)==0)
        k--;
        else if(czySieMiesci(tab[k],l,u)==0)
        p++;
        else //zaden sie nie miesci
        {
            p++;
            k--;
        }
    }
}

int main()
{
    int n,l,u, *p = NULL;
    scanf("%d %d %d",&n,&l,&u);
        
    if(l > u)
        return -1;

    p =(int *) malloc(n*sizeof(int));
    if(p == NULL)
    {
        printf("Brak pamięci");
        return 1;
    }
    wczytaj_tab(p,n);
    solve(p,n,l,u);
    wypisz_tab(p,n);

   
    
   free(p);
    return 0;
}