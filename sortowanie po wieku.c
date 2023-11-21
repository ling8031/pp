#include <stdio.h>
#include <string.h>

struct OSOBA {
    char imie[105];
    int wiek;
};

void wczytaj(struct OSOBA* T,int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%s %d\n",T[i].imie,&(T[i].wiek));
    } 
}

void sortuj(struct OSOBA *T, int n)
{
    int i,j,temp;
    char S[105];
    for(i = 0; i<n;i++)
    for(j =0; j < n; j++)
    {
        if(T[i].wiek < T[j].wiek)
        {
            temp = T[j].wiek;
            T[j].wiek = T[i].wiek;
            T[i].wiek = temp;

            strcpy(S,T[i].imie);
            strcpy(T[i].imie,T[j].imie);
            strcpy(T[j].imie,S);
        }// zamien pozycje
    }
}

void wyswietl(struct OSOBA *T, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%s %d\n",T[i].imie, T[i].wiek);
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);


    struct OSOBA OS[100]; // tablica struktur

    wczytaj(OS,n);

    sortuj(OS,n);

    wyswietl(OS,n);
    
}