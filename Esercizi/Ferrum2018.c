#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(int A[], int N){
    int i = 0;
    int conta = N;
    int firstsum = 0;
    int beginV = 0;
    int endV = N-1;
    int darkflag = 0;

    for(i;i<N;i++){
        firstsum += A[i];
    }
    if (firstsum >= 0)
        return conta;

    if (firstsum<0){
        while(1){
                printf("conta  : %d",conta);
                if (beginV >= endV ||
                    firstsum>= 0)
                    return conta;

                if (A[beginV] <0){
                    firstsum -= A[beginV];
                    conta -= 1;
                    beginV++;
                    darkflag = 1;
                }
                if (A[endV] <0){
                    firstsum -= A[endV];
                    conta -= 1;
                    endV --;
                    darkflag = 1;
                }
                if (darkflag == 0){
                    firstsum -= A[endV];
                    conta -= 1;
                    endV--;
                }else{
                    darkflag = 0;
                }
        }

    }

    return conta;
}


int main ()
{
    int base[] = {-1, 0};
    int n = sizeof(base)/sizeof(base[0]);
    printf("sol: %d",n);
    int sol = solution(base,n);

    printf("sol: %d",sol);
    return sol;
}
