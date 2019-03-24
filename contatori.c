#include <stdio.h>
#include <string.h>

void isCaC(int  c){
    printf("%d\n",c);
}


int main(){
    int c = 20;

    printf("%d\n",c);
    printf("%d\n",c+1);
    printf("%d\n",c++);
    printf("%d\n",--c);
    printf("%d\n",c);

    printf("\n");

    isCaC(c);
    isCaC(c+1 );
    isCaC(c++);
    isCaC(--c );
    isCaC(c);

    return 22;
}
