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

int main()
{
    int A[SIZE],R[SIZE];
    int n,m;
    
    n = read(A,'\n');
    reverse(A,R,n);

    m = zwieksz(R,n); // m - dlugosc nowej liczby n lub n+1

    reverse(R,A,m);
    print(A,m);

    return 0;
}