#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

void wypisz(const char* tablica,int n)
{
    for(int i = 0; i < n; i++)
        printf("%c",*(tablica+i));
    printf("\n");
}


int pierwszaIdentyfikator(char c)
{
    if(isalpha(c) || c=='_')
        return 1;
    else
        return 0;
}

int czyIdentyfikator(char c)
{
    if(isalnum(c) || c=='_')
        return 1;
    else
        return 0;
}

void dopisz(const char *zrodlo, int iP, int iK, char *cel, int *n) //funkcja ktora bedzie dopisywac dane slowo do buforu
{
    int i = iP;
    
    for(;i <= iK; i++)
    {
        printf("zwiekszone\n");
         cel[*n] = zrodlo[i];
        //cel[n] = 'a';
        (*n)++;
        
    }
}

void solve(const char *string, char *output)
{
    int zapelnienie = 0; //ile znakow jest juz w buforze
    
    int i = 0; // licznik znaków
    
    int dlugosc = 0; // dlugosc obecnie sprawdzanego slowa
    int spelnione = 0; // licznik na znaki, które spełniły warunek na bycie identyfikatorem
    int pierwsza = 1; // znacznik, czy sprawdzany znak to pierwszy znak slowa (trzeba sprawdzac bo warunki sie roznia)

    while(string[i] != '\0' && string[i] != EOF)
    {
        if(i+1 == strlen(string)) //ostatni znak inputu
        {
            if(spelnione == dlugosc) // jesli kazdy znak slowa jest zgodny z warunkami, czyli jest identyfikatorem
            {
               dopisz(string, i-dlugosc, i-1, output, &zapelnienie);
            }
        }
        
        if(string[i] == ' ' || string[i] == '\n') // reset slowa
        {
            if(spelnione == dlugosc) // jesli kazdy znak slowa jest zgodny z warunkami, czyli jest identyfikatorem
            {
               dopisz(string, i-dlugosc, i-1, output, &zapelnienie);
            }
            output[zapelnienie-1] = string[i]; // dopisanie tej spacji lub new linea do wyniku
            zapelnienie++;

            dlugosc = 0;
            pierwsza = 1;
            spelnione = 0;
        }
        else if(pierwsza)
        {
            if(pierwszaIdentyfikator(string[i]))
            {
                spelnione++;
            }
            pierwsza = 0;
        }
        else
        {
            if(czyIdentyfikator(string[i]))
            {
                spelnione++;
            }
        }
        i++;
        dlugosc++;
    }
    //dopisz(string,0,i-1,output,&zapelnienie);
    printf("%d\n",zapelnienie);
}

int main()
{
    char output[SIZE]; // to, co bedziemy wypiywac
    //wczytywanie
    
    char linia[SIZE];
    // while(fgets(linia,SIZE,stdin)!=NULL)
    // {
        
    // }
    // char wynik[10];
    // char test[] = "slowo";
    // char test2[] = "abcdef";
   
    // int a = 0;

    // dopisz(test,0,2,wynik,&a);
    // wypisz(wynik,6);
    // printf("%d\n",a);

    // dopisz(test2,3,5,wynik,&a);
    // wypisz(wynik,6);
    // printf("%d\n",a);

    char * wynik = (char *)malloc(100);
    char test[] = "testuawgidujagwhjkda lolz 1xd gosia _samosia .hashha";
    solve(test,wynik);
    wypisz(wynik,100);
   

    return 0;
}