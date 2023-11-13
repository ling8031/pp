#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(char string[], int p ,int k);

int nonIdFirstChar(char c)
{
    if((isalnum(c)==0 && c != '_') || (isdigit(c)==1))
        return 1;
    else return 0;
}

int nonIdChar(char c)
{
    if(isalnum(c)==0 && c != '_')
        return 1;
    else return 0;
}


void funkcja(char *str)
{
    int dlugosc = 0;
    int wrong = 0;
    int i = 0;
    int pierwszyZnak = 1;
    while(str[i]!=EOF)
    {
        if(str[i] == ' ' || str[i] == '\n' ||  i==strlen(str))
        {

            if(wrong > 0)
            {
                reverse(str, i-dlugosc,i-1);
            }
                
            wrong = 0;
            pierwszyZnak = 1;
            i++;
            dlugosc = 0;
        }
        else if(wrong != 0)
        {
            i++;
            dlugosc++;
        }
        else if(pierwszyZnak == 1)
        {
            if(nonIdFirstChar(str[i])==1)
            {
                wrong++;
            }
                
            pierwszyZnak = 0;
            i++;
            dlugosc++;
        }
        else
        {
            if(nonIdChar(str[i])==1)
            {
               wrong++;
            }
                
            i++;
            dlugosc++;
        }
    }
}

void reverse(char string[], int p ,int k)
{
    char temp;

    while(p < k)
    {
        temp = string[p];
        string[p] = string[k];
        string[k] = temp;

        p++;
        k--;
    }
}

int main()
{
    char linia[10000000];
    while(fgets(linia,10000000,stdin)!=NULL)
    {
        funkcja(linia);
        printf("%s",linia);
    }

    return 0;
}