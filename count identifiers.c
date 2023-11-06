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

int ifIdentifierLine(char *string) //dla calej linii
{
    
    int wynik = 0;
    int wrong = 0;
    int i = 0;
    int pierwszyZnak = 1;
    while(1)
    {
        if(i+1==strlen(string))
        {
            if(wrong == 0)
                wynik++;
                
            break;
        }
        
        if(pierwszyZnak == 1)
        {
            if(warunekNaPierwsze(string[i])==0)
                wrong++;
            pierwszyZnak = 0;
            i++;
        }
        else if(string[i] == ' ') //nowe slowo
        {
            if(wrong == 0)
                wynik++;
            wrong = 0;
            pierwszyZnak = 1;
            i++;
        }
        else
        {
            if(warunekNaReszte(string[i])==0)
                wrong++;
            i++;
        }
    }
    return wynik;
}



int main()
{
    char linia[100000];
    while(fgets(linia,100000,stdin)!=NULL)
    {
        printf("%d\n",ifIdentifierLine(linia));
    }

  
    return 0;
}