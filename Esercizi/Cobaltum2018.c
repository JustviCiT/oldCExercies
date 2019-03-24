#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* A,int* B){
    if (*A != *B){
            *A ^= *B;
            *B ^= *A;
            *A ^= *B;
    }
}

void print (int *woop, int dim){
    for(int i =0; i< dim; i++){
        printf("%d ",woop[i]);
    }
    printf("/n");
}

int check_increasing(int *A,int pos,int maxb){
    if (++pos  != maxb  ){
        if (A[pos]< A[pos+1])
            return 0;
    }
   return 1;
}

int main ()
{

    int A[] = { 5, 6, 7, 9, 10};
    int B[] = {1, 3, 6, 7, 9};
    int N = (sizeof (A) / A[0]);

   swap(&A[0],&B[0]);

   printf("%d %d /n", A[0],B[0]);
    return 0;
}
