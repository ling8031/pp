#include <stdio.h>
#include <stdlib.h>

#define SIZE 105

int wczytaj(int* tablica, char znak)
{
    char c;
    int i = 0;
    while((c=getc(stdin)) != znak)
    {
        *(tablica+i) = c -'0';
        i++;
    }
    return i;
}

void wypisz(const int* tablica,int n)
{
    for(int i = 0; i < n; i++)
        printf("%d",*(tablica+i));
    printf("\n");
}

int* odwroc(int* tablica,int rozmiar)
{
    int* wynik = (int*)malloc(rozmiar*sizeof(int));
    for(int i = 0; i < rozmiar; i++)
    {
        wynik[i] = tablica[rozmiar-i-1];
    }
    return wynik;
}

int sumaLiczb(int *liczba1, int *liczba2, int n1, int n2, int *wynik)
{
    int rozmiar; // <- będziemy zwracać ile liczb jest w tablicy po dodaniu
    if(n1 > n2) rozmiar = n1;
    else rozmiar = n2;

    for(int i = 0; i < rozmiar; i++)
    {
            if(i >= n1)
                wynik[i] = liczba2[i];
            else if(i >= n2)
                wynik[i] = liczba1[i];    
            else
                wynik[i] = liczba1[i] + liczba2[i];
    }

    return rozmiar;
}

int przenies(int *tablica,int rozmiar)
{
    int i = 0, carry = 0;
     while( 1 )
    {
        tablica[i]+=carry;
        carry = 0;
        if(tablica[i]>9)
        {
          tablica[i]-=10;
          carry = 1;
        }
        i++;
        if(i == rozmiar)
        {
            if(carry == 0)
                return rozmiar;
            else 
            {
                tablica[i] = carry;
                return rozmiar+1;
            }
        }
    }
    return -1;
}

void rozwiaz(void)
{
    int l1[SIZE],l2[SIZE],*odw1,*odw2,suma[SIZE],*odwrSuma, sN;
    
    int n1 = wczytaj(l1,' ');
    int n2 = wczytaj(l2,'\n');
    
    odw1 = odwroc(l1,n1);
    odw2 = odwroc(l2,n2);
    sN = sumaLiczb(odw1,odw2,n1,n2,suma);
    int t = przenies(suma,sN);
    odwrSuma = odwroc(suma,t);
    wypisz(odwrSuma,t);
}

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i = 0; i < n; i++)
        rozwiaz();

    return 0;
}