#include <stdio.h>
#include <ctype.h>
#include <string.h>

int liczby,slowa;

void licz(char string[])
{
     for(int i = 0; i < strlen(string);i++)
         {
            
            if(isdigit(string[i]))
                liczby++;
            else if(string[i] == ' ')
                slowa++;
         }
}

int main()
{
    char string[100000] = {};

    while(fgets(string,100000,stdin)!=NULL)
    {
        liczby = 0, slowa = 1;
        licz(string);

        printf("%d %d\n", liczby, slowa-liczby);
    }
    
    return 0;
}