#include <stdio.h>
#include <stdlib.h>
#define MAX_VET 5

// mat,vet_sol , best_vet_sol,best_k,k (numero interruttori presi)

void risolvi (int**  ,int* ,int ,int ,int* ,int* ,int,int);
void attiva (int** ,int ,int ,int ,int );
// int check (int** ,int ,int ,int ,int );
int verifica_sol (int** ,int );
// void stampa_mat (int** ,int);
void stampa_vet (int*,int);
// gestione vettore sol
void resetsoluzione(int* ,int );
void removesoluzione(int* ,int );
void add_soluzione(int * ,int ,int );

void iniz_vett(char* ,int);
const char * get_stringa_p (int, char**, int);

int main()
{
    int** mat;
    int* vet_sol;
    int* best_vet_sol;
    int k;
    int best_k;

    int n,i,j;

    n = 3;
    k = 0;
    best_k = 99;

    mat=malloc(n*sizeof(int*));

    for (i= 0; i<n; i++)
    {
        mat[i] = malloc(n * sizeof(int));
    }

    /** Inizializzazione matrice */
    for(i = 0; i< n; i++)
    {
        for(j=0; j<n; j++)
        {
            mat[i][j] = 0;
        }
    }

    vet_sol=malloc(MAX_VET*sizeof(int));
    best_vet_sol=malloc(MAX_VET*sizeof(int));

    for (i= 0; i<MAX_VET; i++)
    {
        vet_sol[i] = 99;
        best_vet_sol[i] = 99;
    }

    mat[0][0] = 0;
    mat[0][1] = 0;
    mat[0][2] = 0;

    mat[1][0] = 1;
    mat[1][1] = 1;
    mat[1][2] = 1;

    mat[2][0] = 0;
    mat[2][1] = 0;
    mat[2][2] = 0;


    char * vettore_test;
    vettore_test = malloc(30 * sizeof(char));
    iniz_vett(vettore_test,30);
    for(i=0;i<30; i++){
            printf("%d",vettore_test[i]);
    }
    char **vs;
    vs = malloc( 30 * sizeof(char*) );
    for(i=0;i<30;i++){
        vs[i] = malloc( 30* sizeof(char) );
        strcpy(vs[i] , "xxx");
    }

    char * x;
    x = get_stringa_p(4,vs,30);
    printf("%s",x);

    /*
    add_soluzione(vet_sol,MAX_VET,1);
    add_soluzione(vet_sol,MAX_VET,2);
    add_soluzione(vet_sol,MAX_VET,3);
    add_soluzione(vet_sol,MAX_VET,4);
    add_soluzione(vet_sol,MAX_VET,5);
    removesoluzione(vet_sol,MAX_VET);
    removesoluzione(vet_sol,MAX_VET);
    removesoluzione(vet_sol,MAX_VET);
    removesoluzione(vet_sol,MAX_VET);
    stampa_vet(vet_sol,MAX_VET);
    */

    //risolvi(mat,vet_sol,n,k,best_vet_sol,&best_k,0,0);
    // stampo solo
    //printf("Il num di interrutori e' : %d \nLa matrice e' : \n",best_k);
    //stampa_vet(best_vet_sol,MAX_VET);

    return 0;
}

void iniz_vett(char* dummy,int max_p){
    int i = 0;
    for(i=0;i<max_p; i++){
        dummy[i] = 0;
    }
    return ;
}
/**
    @param posizione indice del prodotto  da 0 a (max_p-1)
    @param vet_decode vettore contenente le stringhe di prodotti
    @param max_p lunghezza del vettore vet_decode
*/
const char * get_stringa_p (int posizione, char** vet_decode, int max_p){
    int i=0;
    char* ritorno;
    ritorno = malloc(50 * sizeof(char) );
    strcpy(ritorno, "");

    if( posizione > (max_p-1) || posizione < 0 )
        return ;

    printf("%s\n",vet_decode[posizione]);
    printf("%s\n",ritorno);

    strcpy(ritorno, vet_decode[posizione]);
    return ritorno;
}

void risolvi (int**  mat,int* vet_sol,int n,int k,int* best_vet_sol,int* best_k,int riga,int colonna)
{
    int i,j;

    if(verifica_sol(mat,n)==1)
    {
        //stampa_vet(vet_sol,MAX_VET);
        // verifico se numero interruttori è il migliore
        if(k < *best_k)
        {
            // memorizzo soluzione
            *best_k = k;
            // copio matrice
            for(i = 0; i< MAX_VET; i++)
            {
                best_vet_sol[i] = vet_sol[i] ;
            }
            printf("Soluzione minima trovata con k : %d \n",*best_k);
            //stampa_vet(vet_sol,n);
        }

        return;
    }

    if(k>3)
    {
        return; // interrompo la ricorsione
    }


    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            // attivo interrutore su riga
            attiva(mat,n,1,i,j);
            add_soluzione(vet_sol,MAX_VET,i);
            risolvi(mat,vet_sol,n,k+1,best_vet_sol,best_k,i,j);
            removesoluzione(vet_sol,MAX_VET);
            attiva(mat,n,1,i,j);

            // attivo interrutore su colonna
            attiva(mat,n,2,i,j);
            add_soluzione(vet_sol,MAX_VET,-j);
            risolvi(mat,vet_sol,n,k+1,best_vet_sol,best_k,i,j);
            removesoluzione(vet_sol,MAX_VET);
            attiva(mat,n,2,i,j);
        }
    }
}

void stampa_mat (int** mat,int n)
{
    int i,j;

    for(i = 0; i< n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

void attiva (int** mat,int n,int riga_colonna,int riga,int colonna)
{
    int i,j;

    if(riga_colonna ==1)
    {
        // swiccio riga

        for(j=0; j<n; j++)
        {
            if(mat[riga][j] == 0)
            {
                mat[riga][j] = 1;
            }
            else
            {
                mat[riga][j] = 0;
            }
        }
    }
    else
    {
        for(i=0; i<n; i++)
        {
            if(mat[i][colonna] == 0)
            {
                mat[i][colonna] = 1;
            }
            else
            {
                mat[i][colonna] = 0;
            }
        }

    }
    return;
}


int verifica_sol (int** mat,int n)
{
    int vittoria,i,j;

    vittoria = 1;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(mat[i][j] == 0)
            {
                vittoria = 0;
                return vittoria;
            }
        }
    }


    return vittoria;
}



void resetsoluzione(int* k,int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        k[i] = 99;
    }
    return;
}

//prima volta che becco un <> 99 metto 99 e esco loop decresenet

void removesoluzione(int* k,int n)
{
    n--;
    while (n>0)
    {
        if(k[n] != 99)
        {
            k[n] = 99;
            break;
        }
        n--;
    }
    return;
}

/** Prende in ingresso  row_col  R 1 2 3  C -1 -2 -3**/
void add_soluzione(int * k,int n,int row_col)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(k[i] == 99 )
        {
            k[i] = row_col;
            return;
        }
    }
}

void stampa_vet(int* k,int n)
{
    int i = 0;

    for(i=0; i<n; i++)
    {
        printf(" %d ",k[i]);
    }
    printf("\n");
    return;
}
/***

#include <stdio.h>
#include <string.h>
#define n 3
#define max_ricorsioni 4

typedef struct obj_sol  sol;
struct obj_sol{
    int key;
    char c;
};

void print_matrice(int **pm){
    int i,j;

    printf("\n");
    for(i=0;i<n; i++){
        for(j=0;j<n; j++){
            printf(" %d ",pm[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void xor_row(int **pm, int pnumero){
    if(pnumero > n || pnumero < 0)
        return;

    int i;
    for(i=0; i<n;i++){
        pm[pnumero][i] = pm[pnumero][i]  ^ 1;
    }
}

void xor_col(int **pm, int pnumero){
    if(pnumero > n || pnumero < 0)
        return;

    int i;
    for(i=0; i<n;i++){
        pm[i][pnumero] = pm[i][pnumero]  ^ 1;
    }
}

// ritorna 0 se va tutto BENE, 1 altrimenti
int check_solution(int ** pm){
    int i,j,sbagliato = 0;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(pm[i][j] == 0){
                sbagliato = 1;
                return sbagliato;
            }
        }
    }
    return sbagliato;
}

void print_solution(sol * x){
    int i;
    for(i=0;i<max_ricorsioni;i++){
        if(x[i].key == 999){
            printf("--");
        }else{
            printf("%c%d",x[i].c,x[i].key);
        }
    }
    printf("\n");
}

void add_solution(sol *x,char c, int row_col){
    int i;
    for(i=0;i<max_ricorsioni;i++){
        if(x[i].key == 999){
            x[i].c = c;
            x[i].key = row_col;
            break;
        }
    }
}

void remove_solution(sol *x){
    int i;
    for(i=max_ricorsioni-1;i>=0;i--){
        if(x[i].key != 999){
            x[i].c = ' ';
            x[i].key = 999;
            break;
        }
    }
}

void reset_solution(sol * x){
    int i;
    for(i=0;i<max_ricorsioni;i++){
        x[i].c = ' ';
        x[i].key = 999;
    }
}

int risolvi(int **m, int k,sol * x){
    if(check_solution(m) == 0){
        print_solution(x);
    }

    if(k <= 0){
        return;
    }
    int i;

    for(i=0;i<n;i++){
        xor_row(m,i);
        add_solution(x,'R',i);
        risolvi(m,k-1,x);
        remove_solution(x);
        xor_row(m,i);
    }

    for(i=0;i<n;i++){
        xor_col(m,i);
        add_solution(x,'C',i);
        risolvi(m,k-1,x);
        remove_solution(x);
        xor_col(m,i);
    }

}

int main(){
    int i,j;
    int **m;
    sol * soluzioni;

    soluzioni = malloc(max_ricorsioni*sizeof(sol));

    m = (int**) malloc(n*sizeof(int*));
    for(i=0; i<n; i++){
        m[i] = (int*) malloc(n*sizeof(int));
    }

    // popola la matrice
    for(i=0; i<n; i++){
        for(j=0;j<n;j++){
            m[i][j] = 0;
        }
    }

    m[0][0] = 1;
    m[0][1] = 1;
    m[0][2] = 1;
    m[1][0] = 1;
    m[1][1] = 1;
    m[1][2] = 1;
    m[2][0] = 1;
    m[2][1] = 1;
    m[2][2] = 1;
    //m[2][1] = 1;
    reset_solution(soluzioni);

    print_matrice(m);
    risolvi(m,max_ricorsioni,soluzioni);

    return 0;
}




**/





