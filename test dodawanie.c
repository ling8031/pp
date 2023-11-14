#include <stdio.h>
#include <stdlib.h>

#define SIZE 105

void reverse(int* A, int* R, int size)
{
    int i;
    for(i = 0; i < size; i++) R[i] = A[size-1-i];
}

void print(int* A, int size)
{
    int i;
    for(i = 0; i < size; i++) printf("%d",A[i]);
    printf("\n");
}

//s-znak konca liczby

int read(int *A,char s)
{
    int i,c;
    for(i = 0;(c = fgetc(stdin)) != s;i++)
    {
         A[i] = c - '0';
    }
    return i;

}

// x<y -1  x>y 1 x=y 0

int porownaj(int* X, int* Y,int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(X[i]!=Y[i]) break;
    }
    if(i == size) return 0;
    else
    {
        if(X[i]>Y[i]) return 1;
        return -1;
    }

}

int zwieksz(int* X, int size)
{
    int i = 0;
    while( 1 )
    {
        if(X[i]<9)
        {
            X[i]++;
            return size;
        }
        X[i] = 0;
        i++;
        if(i == size) {X[i] = 1; return size+1;}
    }
}

int dodaj(int* X, int* Y, int* W, int sizeX, int sizeY)
{
    int i = 0;
    int wX,wY;
    wX = wY = 0;

    int przekaz = 0;
    while( 1 )
    {
        if(i == sizeX)
        {  
            wX = 1;
            X[i] = 0;
        }
        
        if(i == sizeY)
        {  
            wY = 1;
            Y[i] = 0;
        }

        if(wX != 0 && wY != 0 && przekaz == 0) 
            return i-1;// koniec, nie ma co dodawać

        if(przekaz+X[i]+Y[i]<10)   // nie trzeba przekazywac
        {
            W[i] = X[i]+Y[i]+przekaz;
            i++;
            przekaz = 0;
        }
        else    // przekazywanie dalej
        {
            W[i] = (X[i]+Y[i]+przekaz)-10;
            przekaz+=1;
            i++;
        }
        
    }
    return -1;

}

int main()
{
    int A[SIZE],B[SIZE],S[SIZE*2],rA[SIZE],rB[SIZE],rS[SIZE*2];
    int a,n,m,s;

    for(int i = 0; i < SIZE; i++)
    {
        S[i] = 0;
    }

    scanf("%d",&a);

    for(int i = 0; i < a; i++)
    {
        n = read(A,' ');
        m = read(B,'\n');
        reverse(A,rA,n);
        reverse(B,rB,m);
        
        s = dodaj(rA,rB,S,n,m);

        printf("%d\n",s);

        reverse(S,rS,s);
        print(rS,s);
        print(S,s);

    }
    

    

    return 0;
}

