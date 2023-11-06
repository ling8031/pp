#include <stdio.h>



int main()
{
    int n;
    scanf("%d",&n);
    int half = 0, part = 1, line = 0, odstep;
    

    while(part <= n)
    {
        odstep = n*2-1-line;

        for(int i = 0; i < odstep; i++)   //odstepy po lewej
            printf(" ");

        if(line == 0)                          // tylko dla pierwszej
            printf("^^");

        else if(line+1 == part*2)   // koncowa linia danej czesci
        {
            for(int i = part*4; i > 0; i--) 
                printf("^");
        }
        else if(line > 0 && line < part*2)
        {
            while(half < 2)
            {
                printf("^");
                for(int i = line-1; i > 0; i--)
                    printf(" ");
                printf("^");
                half++;
            }
        }
        half = 0;
        line++;
        printf("\n");
        
        if(line == part*2)    // koniec czesci -> reset linii, zwiekszenie parta
        {
            line = 0;
            part++;
        }
    }

    

    return 0;
}