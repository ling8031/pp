#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(char string[], int p ,int k);

int warunekNaPierwsze(char c)
{
    if(isalpha(c) == 0 && c!='_')
        return 0;
    else return 1;
}

int warunekNaReszte(char c)
{
    if((isalnum(c) == 0) && (c != '_'))
        return 0;
    else return 1;
}


void funkcja(char *str)
{
    int dlugosc = 0;
    int wrong = 0;
    int i = 0;
    int pierwszyZnak = 1;
    while(str[i]!=EOF)
    {
        
        if(pierwszyZnak == 1)
        {
            if(warunekNaPierwsze(str[i])==0)
                wrong++;
            pierwszyZnak = 0;
            i++;
            dlugosc++;
        }
        else if(str[i] == ' ' || str[i] == '\n' ||  i==strlen(str))
        {
            if(wrong == 0)
            {
                reverse(str, i-dlugosc,i-1);
            }
                
            wrong = 0;
            pierwszyZnak = 1;
            i++;
            dlugosc = 0;
        }
        else
        {
            if(warunekNaReszte(str[i])==0)
                wrong++;
            i++;
            dlugosc++;
        }
    }
}

void reverse(char string[], int p ,int k)
{
    int poczatek = p;
    int koniec = k;
    char temp;

    while(poczatek < koniec)
    {
        temp = string[poczatek];
        string[poczatek] = string[koniec];
        string[koniec] = temp;

        poczatek++;
        koniec--;
    }
}

int main()
{
    char linia[100];
    while(fgets(linia,100,stdin)!=NULL)
    {
        funkcja(linia);
        printf("%s",linia);
    }

    return 0;
}