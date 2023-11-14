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

int main()
{
    int A[SIZE],B[SIZE];
    int c,n,m,odp;
    
    n = read(A,' ');
    m = read(B,'\n');

    if(n < m) {printf("<\n");return 0;}
    if(n > m) {printf(">\n");return 0;};

    odp = porownaj(A,B,n);
    if(odp == -1) printf("<\n");
    else if(odp == 1) printf(">n\n");
    else printf("=\n");
    
    
    

    return 0;
}