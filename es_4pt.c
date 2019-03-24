#include <stdio.h>
#include <stdlib.h>

#define LMAX 5

typedef struct nodo_t nodo;
static int contatore;
// STRUCT

struct nodo_t
{
    int key;
    nodo *childen[LMAX];
};

void visitLevelbyLevel(nodo* root,int l1,int l2);
void popola_albero(nodo* root,int,int);

int main ()
{
    int grado;
    contatore =0;
    nodo * root;

    root = malloc(sizeof(nodo));
    root->key= contatore;

    contatore++;
    popola_albero(root,0,LMAX);

    visitLevelbyLevel(root,2,3);
    //print_tree(root);
    return 0;
}

void visitLevelbyLevel(nodo* root,int l1,int l2)
{
    // Terminazione generale
    if( l2<=0){
         printf("\n%d\n",root->key );
         return;
    }

    //  non si sa mai
    if(l1> l2)
        return;
    // non si sa mai
    int i =0;
    for(i=0;i<LMAX; i++){
            if(root->childen[i] == NULL)
                return;
    }

    // Da quando l1 diventa 0 stampo fino a l2 = 0
    if ( l1 <=0){
        printf("%d\n",root->key );
    }

    // ricorro
    for(i=0;i<LMAX; i++){
            if(root->childen[i] != NULL)
                visitLevelbyLevel(root->childen[i],l1-1,l2-1);
    }

}

void print_tree(nodo* root){

    int i =0;
    for(i=0;i<LMAX; i++){
            if(root->childen[i] == NULL)
                return;
    }

    printf("  %d  ",root->key);
    printf("\n");
    for(i=0;i<LMAX; i++){
        print_tree(root->childen[i]);
    }


}

void popola_albero(nodo* root,int grado_act,int grado_max)
{
    int i,j;
    j=0;

   // terminazione con un livello in meno
   if (grado_act > grado_max){
       for(i = 0; i< grado_max ; i++){
            root->childen[i] = NULL;
       }

       return;
   }

   j=0;

    for (i=0;i<grado_max;i++)
    {
        while(j<grado_max)
        {
            root->childen[j] = malloc(grado_max*sizeof(nodo));
            root->childen[j]->key=contatore;
            //printf("\n %d di livello %d ",root->childen[j]->key,grado_act);
            j++;
        }
         contatore++;
        popola_albero(root->childen[i],grado_act+1,grado_max);
    }
}
