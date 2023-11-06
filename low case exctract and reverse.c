#include <stdio.h>
#include <ctype.h>
#include <string.h>

void funkcja(char string[]);
void zamien(char string[], int iP, int iD);

int main()
{
    int n;
    scanf("%d",&n);
    char temp[100] = {};
    for(int i = 0; i < n; i++)
    {
        scanf("%s",&temp);
        funkcja(temp);
        printf("%s",temp);
    }
   
    return 0;
}

void funkcja(char string[])
{

    int n = strlen(string);

    int p = 0, k = n-1;
    
    while(p < k)
    {
        if(islower(string[p]) && islower(string[k]))
            zamien(string,p,k);
        else if(islower(string[p]))
            k--;
        else 
            p++;
    }
}
void zamien(char string[], int iP, int iD)
{
    char t = string[iP];
    string[iP] = string[iD];
    string[iD] = t;
}

