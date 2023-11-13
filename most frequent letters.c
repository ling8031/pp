#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ROZMIAR 'z'-'a' + 1

void policzMale(char string[],int size,int* tab)
{
    char znak;
    for(int i = 0; i < size;i++)
    {
        znak = string[i];
        if(islower(znak))
        {
            tab[znak-'a']++;
        }
    }
}

void policzDuze(char string[],int size,int* tab)
{
    char znak;
    for(int i = 0; i < size;i++)
    {
        znak = string[i];
        if(isupper(znak))
        {
            tab[znak-'A']++;
        }
    }
}

void wypisz(int* tab)
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        printf("%d %d\n",i,tab[i]);
    }
}

void mostFreq(const int* tab)
{
    int maks = 0;
    for(int i = 0; i < ROZMIAR; i++)
    {
        if(tab[i] > maks)
            maks = tab[i];
    }
    printf("%d ",maks);
}

int main()
{
    int male[ROZMIAR];
    int duze[ROZMIAR];
    for(int i = 0; i < ROZMIAR; i++)
    {
        male[i] = 0;
        duze[i] = 0;
    }

    char linia[100];
    int dlugosc;
    while(fgets(linia,100,stdin)!=NULL)
    {
        dlugosc = strlen(linia)-1; // liczba znakow oprzicz /n
        if(dlugosc%2==0) //parzysta dlugosc
        {
            policzMale(linia,dlugosc,male);
        }
        else if(dlugosc%2==1)
        {
            policzDuze(linia,dlugosc,duze);
        }
        
    }
   
    mostFreq(male);
    mostFreq(duze);

    return 0;
}