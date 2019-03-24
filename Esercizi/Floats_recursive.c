#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Contatore globale per verifica*/
int c ;

struct appggio {
    float max;
    float min;
    float diff;
} app;

void swap(float *x, float *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

float contaDiff(float a[], int len){
    float max=0.0, min = 0.0;
    float temp_diff=0.0, differenza=999999.0;
    float somma=0.0;
    int i=0;

    for(i;i<len;i++){
        temp_diff = 0;
        somma += a[i];
        if( somma>= max){
            max = somma;
        }
        if( somma<=min){
            min = somma;
        }
        differenza = max - min;
    }
    return differenza;
}

/**
    @param a  Array di float su cui si lavora
*/
void doit(float a[], int l, unsigned int len_low, float res[] )
{
    int i = 0;
    float diff=0;
    float diffsecond = 0;
   if (l == len_low){
      diff = contaDiff(a,len_low);
      diffsecond = contaDiff(res,len_low);
      if(diff < diffsecond ){
        copyarray(res, a,len_low );
      }
     c++;
   }else{
       for (i = l; i < len_low; i++)
       {
          swap(&a[l], &a[i]);
          doit(a, l+1,len_low,res);
          swap(&a[l], &a[i]);
       }
   }
    copyarray(a, res,len_low );
}

void printiT(float a[], int len_low){
    int i = 0;
    for(i; i<len_low; i++){
        printf("%.3f ",a[i]);
    }
    printf("\n");
}
/**
    A e B sono due array di dimensione len.
    Su A viene copiato B.
*/
void copyarray(float *a, float *b,unsigned int len ){
    int i = 0;
    for(i = 0 ; i< len;i++){
        a[i] = b[i];
    }
}

int main ()
{
    float base[] = {1.400, 2.200, -3.300, -4.100,  -5.100};
    float basetwo[] = {1.400, 2.200, -3.300, -4.100,  -5.100};
    float somma = 0;
    float diff = 0 ;
    int i = 0;
    for(i;i<5;i++){
        somma += base[i];
    }
    printf("%.3f \n",somma);

    doit(base,0, 5,basetwo);
    diff = contaDiff(base,5);
    printf("%.3f \n",diff);
    printiT(base,5);

    //printf("%d",c);

    return 0;
}
