#include <stdio.h>
#include <string.h>

void zamien(char str[]);

int main()
{
    char string[100000] = {};
    while(fgets(string,100000,stdin)!=NULL)
    {
        zamien(string);
        printf("%s\n",string);
    }
      
    return 0;
}

void zamien(char str[])
{
    int poczatek = 0;
    int koniec = strlen(str) - 1;
    char znak;

    while(poczatek < koniec)
    {
        znak = str[poczatek];
        str[poczatek] = str[koniec];
        str[koniec] = znak;
        poczatek++;
        koniec--;
    }
}