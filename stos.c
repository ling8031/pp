#include <stdio.h>


void operacja(char znak, int liczba, int tablica[], int *indeks)
{
    if(znak == '+') // dodawanie
    {
        if(*indeks <= 9)
        {
            tablica[*indeks] = liczba;
            printf(":)\n");
            (*indeks)++;
        }
        else
        {
            printf(":(\n");
        }
    }


    if(znak == '-') // odejmowanie
        {
            if(*indeks == 0) // stos jest pusty
            {
                printf(":(\n");
            }
            else 
            {
                printf("%d\n",tablica[*indeks-1]);
                (*indeks)--;
            }
        }
    }

int main()
{
    int stos[10];
    int indeks = 0; // miejsce w które wspisujemy, czyli puste

    // wczytywanie 
    int liczba;
    char znak;

    while( (znak=getc(stdin))!=EOF)
    {
        if(znak == '\n')
            continue;
        else
        {
            scanf("%d",&liczba);

            // printf("znak: %c ",znak);
            // printf(" liczba: %d\n",liczba);
            operacja(znak,liczba,&(stos[0]),&indeks);

        }

    }

    return 0;
}