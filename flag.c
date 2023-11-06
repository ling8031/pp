#include <stdio.h>

int main()
{
    int k;
    scanf("%d",&k);

    int n = 4*k+14;
    int polowka = n/2; // dla n = 1 -> 9
    int polowka2 = polowka/2;   // -> 4

    
    for(int i = 1; i <= n;i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j == 1 || j == n || j == polowka || j == polowka+1)
                printf("*");
            else if(i == 1 || i == n || i == polowka || i == polowka+1)
                printf("*");
            else if((j == polowka2+1 || j==polowka2+polowka+1) && ((i == polowka2 || i == polowka2+1 || i==polowka2+2) || (i == polowka+polowka2 || i  == polowka+polowka2+1 || i == polowka+polowka2+2 )))
                printf("*");
            else if((i == polowka2+1 || i==polowka2+polowka+1) && ((j == polowka2 || j == polowka2+1 || j==polowka2+2) || (j == polowka+polowka2 || j  == polowka+polowka2+1 || j == polowka+polowka2+2 )))
                printf("*");
            else 
                printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}