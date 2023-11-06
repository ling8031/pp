#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main()
{
    int lines = 0, words = 1,n = 0,wrong=0;
    char c;
    
    while((c = getc(stdin))!= EOF)
    {
        n++;
        if(c == '\n')
        {
            lines++;
            if(wrong == 0)
                words++;
            wrong = 0;
        }
        else if(c == ' ')
        {
            if(wrong == 0)
                words++;

            wrong = 0;
        }
        else if(isalpha(c) == 0)
        {
            if(wrong == 0)
            {
                words++;
            }
            wrong = 1;
        }
        else if(isalpha(c) != 0)
            wrong = 0;

            
    }
   
    printf("%d %d %d",lines,words-1,n);

    return 0;
}