#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void build_menu(char **data[],int n){
    int j = 0;

    if ( n < 0 || data[n][j] == NULL)
        return;

    build_menu(data,n-1);

    while( data[n][j] != NULL){
        if (n == 0){
            printf("( %s, ",data[n][j]);
        }else if(n == 2){
            printf("%s ), ",data[n][j]);
        }else{
            printf("%s, ",data[n][j]);
        }
        j++;
    }

}

// STRUCT

//  PROTOTIPO

void build_menu(char **data[],int n);

int main ()
{
    char *** base;

     int lunghezza_base,i ,ingredienti;

    lunghezza_base=3;
    ingredienti=3;

    base = malloc(lunghezza_base*sizeof(char***));

    for(i=0; i<lunghezza_base; i++)
    {
        base[i]= malloc(ingredienti*sizeof(char  **)); // alloco vettore ingredienti
    }
    base[0][0] = "pasta";
    base[0][1] = "riso";
    base[0][2] =  NULL;
    base[1][0] = "carne";
    base[1][1] = "pesce";
    base[1][2] = "formaggio";
    base[1][3] = NULL;
    base[2][0] = "gelato";
    base[2][1] = "torta";
    base[2][2] = NULL;

    build_menu(base,lunghezza_base-1);

    return 0;
}
