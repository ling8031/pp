#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* toRoman(int num);

int znak(char c)
{
    switch(c)
    {
        case 'M':
        return 1000;
        break;
        case 'D':
        return 500;
        break;
        case 'C':
        return 100;
        break;
        case 'L':
        return 50;
        break;
        case 'X':
        return 10;
        break;
        case 'V':
        return 5;
        break;
        case 'I':
        return 1;
        break;
    }
}

int wartosc(char string[], int p, int k)
{
    int n = k-p+1;
    int *tab = (int *) malloc(n*sizeof(int));
    
    for(int i = 0; i+p <= k; i++)
    {
        tab[i] = znak(string[i+p]);
       // printf("%c -> %d\n",string[i],znak(string[i]));
    }

    int wynik = 0;
    
    for(int i = 0; i < n; i++)
    {
       // printf("%d\n",wynik);
        int s1 = tab[i];
        if(i + 1 < n)
        {
            int s2 = tab[i+1];

            if(s1 >= s2)
            {
                wynik += s1;
            }
            else
            {
                wynik = wynik - s1 + s2;
                i++;
            }
        }
        else
        {
             wynik += s1;
        }
        
    }

    return wynik;

    free(tab);
}

int operation(int a, char op, int b)
{
    switch(op)
    {
        case '*':
        return a*b;
        break;
        case '+':
        return a+b;
        break;
        case '-':
        return a-b;
        break;
        case '/':
        return a/b;
        break;
    }
    return -1;
}


void solve(char string[])
{
   
    int p1,k1;
    int p2,k2;
   
    char op;
   
    int i = 0;

    int pierwszy = 1;

    p1 = 0;

    while(i < strlen(string))
    {
        if(isalpha(string[i])==0 && string[i] != ' ' && string[i] != '\0')
            op = string[i];
        while(string[i]!=' ')
            i++;
        if(pierwszy == 1)
        {
            k1 = i-1;
            pierwszy = 0;
        }
        
        i++;
        
    }
    p2 = k1 + 4;
    k2 = strlen(string)-2;

    //dlugosci sie zgadzaja | poczatki i konce tez
    int l1 = k1-p1+1; 
    int l2 = k2-p2+1;
    printf("%d %d\n",l1,l2);
    char *str1 = (char *)malloc(l1*sizeof(char));
    char *str2 = (char *)malloc(l2*sizeof(char));

    strcpy(str1,string);

    // for(int i = 0; i < l1; i++)
    // {
    //     str1[i] = string[i];
    // }
  
    // for(int i = 0; i < l2; i++)
    // {
    //     str2[i] = string[p2+i];
    // }
    //OK

    printf("%s |||  %s\n", (str1), (str2));
     // printf("%d %d", wartosc(str1,p1,k1),wartosc(str2,p2,k2));
    //  printf("\n");

    // int wynik = operation(wartosc(str1),op,wartosc(str2));

    // printf("%d",wynik);

    // char* wypisz;



    // if(wynik > 3999 || wynik < 0)
    //     printf("-");
    // else 
    // {
    //     wypisz = toRoman(wynik);
    //     for(int i = 0; i < strlen(wypisz);i++)
    //         printf("%c",wypisz[i]);
    // }

    // wypisz = toRoman(wynik);
    //  for(int i = 0; i < strlen(wypisz);i++)
    //      printf("%c",wypisz[i]);
}

char* toRoman(int num)
{
    char* tab;
    char odp[100];
    int i=0;

    while(num != 0)
    {

        if (num >= 1000)       // 1000 - m
        {
            odp[i]='M';
            num -= 1000;
            i++;
        }

        else if (num >= 900)   // 900 -  cm
        {
           odp[i] = 'C';
           odp[i+1] = 'M';
           num -= 900;
           i+=2;
        }        

        else if (num >= 500)   // 500 - d
        {           
           odp[i]='d';
           num -= 500;
           i++;
        }

        else if (num >= 400)   // 400 -  cd
        {
           odp[i] = 'C';
           odp[i+1] = 'D';
           num -= 400;
           i+=2;
        }

        else if (num >= 100)   // 100 - c
        {
           odp[i]='c';
           num -= 100;    
            i++;                   
        }

        else if (num >= 90)    // 90 - xc
        {
            odp[i] = 'X';
           odp[i+1] = 'C';
           num -= 90;       
           i+=2;                                       
        }

        else if (num >= 50)    // 50 - l
        {
           odp[i]='l';
           num -= 50;     
            i++;                                                                
        }

        else if (num >= 40)    // 40 - xl
        {
            odp[i] = 'X';
            odp[i+1] = 'L';         
            num -= 40;
            i+=2;
        }

        else if (num >= 10)    // 10 - x
        {
            odp[i]='x';
            num -= 10;     
            i++;      
        }

        else if (num >= 9)     // 9 - ix
        {
            odp[i] = 'I';
            odp[i+1] = 'X';
            num -= 9;      
            i+=2;                   
        }

        else if (num >= 5)     // 5 - v
        {
            odp[i]='v';
            num -= 5;     
            i++;                                
        }


        else if (num >= 4)     // 4 - iv
        {
            odp[i] = 'I';
            odp[i+1] = 'V';
            num -= 4;    
            i+=2;                                                        
        }

        else if (num >= 1)     // 1 - i
        {
            odp[i]='i';
            num -= 1;    
            i++;                                                                               
        }
    }

    tab = (char *)malloc(i*sizeof(char));
    strcpy(tab,odp);
    return tab;
}

int main()
{
    char linia[10000];
    while(fgets(linia,10000,stdin)!=NULL)
    {
        solve(linia);
    }
 
//    char test[] = "CDX";
//    printf("%d",wartosc(test));
   
    return 0;

}