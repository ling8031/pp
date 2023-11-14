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

int read(int *A)
{
    int i,c;
    for(i = 0;(c = fgetc(stdin)) != '\n';i++)
    {
         A[i] = c - '0';
    }
    return i;

}

int main()
{
    int A[SIZE],R[SIZE];
    int n;
    
    n = read(A);
    reverse(A,R,n);
    print(R,n);
    
    

    return 0;
}