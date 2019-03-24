#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Contatore globale per verifica*/
int c ;


void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void doit(char *a, int l, int r )
{
    unsigned int len_low;
    int i;
    len_low = strlen(a);
    if(r < len_low){
        printf("Le permutazioni possibili devono essere >= di %d \n", len_low);
        return;
    }

   if (l == len_low)
     inner_last(a,r);
   else
   {
       for (i = l; i <= len_low; i++)
       {
          swap(&a[l], &a[i]);
          doit(a, l+1, r);
          swap(&a[l], &a[i]);
       }
   }
}


void inner_last(char * str,  int j){
    unsigned int len= 0;
    len  = strlen(str);

    if(len == j){
        printf("%s\n",str);
        c++;
        return;
    }

    char * newstr = malloc(  (len+2)* sizeof(char) );

    int k = 0;
    for (k= 0; k<len; k++){
        strcpy( newstr, str);
        newstr[ len ] = str[k];
        newstr[ len +1 ] = '\0';
        inner_last(newstr, j);
    }
    free(newstr);

}

// STRUCT

//  PROTOTIPO


int main ()
{
    char base[] = "21143";

    doit(base,0, 5);
    printf("%d",c);

    return 0;
}
