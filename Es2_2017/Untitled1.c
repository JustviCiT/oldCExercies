#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// Esercizio 2

typedef struct bst_t bst;
typedef struct list1_t list1;
typedef struct list2_t list2;

// STRUCT

struct bst_t
{
    char *modello;
    list1 *head;
    bst   *left;
    bst   *right;
};

struct list1_t
{
    char *concessionario;
    float prezzo;
    list1 *next;
};

struct list2_t
{
    char *modello; // aggiunto
    char *concessionario;
    float prezzo_min;
    list2 *next;
};


// gestito direttamente i nodi non il wrapper lista dei nodi
// quindi ho aggiustato i parametri di ingresso
void bst2list(bst *, list2 *,list2 *);

int main()
{
    char modello1[20];
    char modello2[20];
    char modello3[20];

    char concessionario_test1[20];
    char concessionario_test2[20];
    char concessionario_test3[20];

    list1 *list1_head1;
    list1 *list1_head2;
    list1 *list1_head3;
    list1 *list1_figlio1;
    list1 *list1_figlio2;
    list1 *list1_figlio3;
    list2 *list2_head;
    list2 *cur;
    list1 *curl1;
    bst  *bst_root;
    bst  *destra;
    bst  *sinistra;

    strcpy(modello1, "Modello1");
    strcpy(modello2, "Modello2");
    strcpy(modello3, "Modello3");

    strcpy(concessionario_test1, "Milano");
    strcpy(concessionario_test2, "Roma");
    strcpy(concessionario_test3, "Parigi");

    // Creazione di tre list1 per due nodi filgi

    list1_head1 = malloc(1*sizeof(list1));
    list1_head2 = malloc(1*sizeof(list1));
    list1_head3 = malloc(1*sizeof(list1));

    list1_figlio1 = malloc(1*sizeof(list1));
    list1_figlio2 = malloc(1*sizeof(list1));
    list1_figlio3 = malloc(1*sizeof(list1));

    list1_head1->concessionario = concessionario_test1;
    list1_head2->concessionario = concessionario_test2;
    list1_head3->concessionario = concessionario_test3;

    list1_figlio1->concessionario = concessionario_test2;
    list1_figlio2->concessionario = concessionario_test3;
    list1_figlio3->concessionario = concessionario_test1;

    list1_head1->prezzo = 50;
    list1_head2->prezzo = 10;
    list1_head3->prezzo = 30;

    list1_figlio1->prezzo = 40;
    list1_figlio2->prezzo = 60;
    list1_figlio3->prezzo = 10;

    list1_head1->next = list1_figlio1;
    list1_head2->next = list1_figlio2;
    list1_head3->next = list1_figlio3;

    list1_figlio1->next = NULL;
    list1_figlio2->next = NULL;
    list1_figlio3->next = NULL;

    list2_head = malloc(1*sizeof(list2));
    list2_head = NULL;


    // Creazione BST

    bst_root = malloc(1*sizeof(bst));
    destra = malloc(1*sizeof(bst));
    sinistra = malloc(1*sizeof(bst));

    bst_root->head = list1_head1;
    destra->head = list1_head2;
    sinistra->head = list1_head3;

    bst_root->left = sinistra;
    bst_root->right = destra;
    sinistra ->left = NULL;
    destra ->left = NULL;
    sinistra ->right = NULL;
    destra ->right = NULL;

    bst_root->modello = modello2;
    destra->modello = modello3;
    sinistra->modello = modello1;

    for(curl1 = bst_root->head; curl1 != NULL; curl1=curl1->next)
    {
        printf("\n bst_root : Modello: %s \n Concessionario  : %s \n Prezzo: %f \n",bst_root->modello,curl1->concessionario,curl1->prezzo);
    }

    for(curl1 = sinistra->head; curl1 != NULL; curl1=curl1->next)
    {
        printf("\n bst_sinistra : Modello: %s \n Concessionario  : %s \n Prezzo: %f\ng",sinistra->modello,curl1->concessionario,curl1->prezzo);
    }

    for(curl1 = destra->head; curl1 != NULL; curl1=curl1->next)
    {
        printf("\n bst_destra : Modello: %s \n Concessionario  : %s \n Prezzo: %f\n",destra->modello,curl1->concessionario,curl1->prezzo);
    }

    printf("\n\nStampo sol\n\n");
    bst2list(bst_root,list2_head,list2_head);
list2 *j;
     for(j=list2_head; j != NULL; j=j->next)
        {
            // stampo List2
            printf("\n Modello: %s \n Concessionario conveniente : %s \n Prezzo: %f\n\n",j->modello,j->concessionario,j->prezzo_min);
        }

    return 0;
}

void bst2list(bst *bst, list2 *head,list2 *tail)
{
// modificato visita da post-order a in-order per avere l'ordinamento crescente

    float p_min;
    list1 *i;
    char *min_c;
    char *min_m;
    list2 *dummy;
    list2 *j;

    min_c=malloc(20*sizeof(char));
    min_m=malloc(20*sizeof(char));
    if ( bst == NULL ) return;

    bst2list( bst->left,head,tail );

    // lavoro
    p_min = 9999999;
// cerco min prezzo modello
// corretto inizializzazione I
    for(i=bst->head; i != NULL; i=i->next)
    {
        if(i->prezzo<p_min)
        {
            p_min = i->prezzo;
            strcpy(min_c,i->concessionario);
            strcpy(min_m,bst->modello);
        }
    }

// creo nodo list2 dummy e metto le info trovate sopra

    dummy = malloc(1*sizeof(list2));
    dummy->prezzo_min = p_min;
    dummy->concessionario = min_c;
    dummy->modello = min_m;
    dummy->next = NULL; // aggiunto
   // printf("\n Modello: %s \n Concessionario conveniente : %s \n Prezzo: %f\n\n",dummy->modello,dummy->concessionario,dummy->prezzo_min);

// inserisco in coda
// corretta gestione cursori di list2

    if(head == NULL) // primo giro
    {
        head = dummy;
    }
    else
    {
        for(j=head; j != NULL; j=j->next)
        {
            {
                j->next = dummy;
                 stampo List2
                //printf("\n Modello: %s \n Concessionario conveniente : %s \n Prezzo: %f\n\n",dummy->modello,dummy->concessionario,dummy->prezzo_min);
                break;
            }
        }
    }


    bst2list( bst->right,head,tail );

    return;
}

