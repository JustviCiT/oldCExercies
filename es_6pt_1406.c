#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 8
#define MAX_COL 9
#define K 4
// caso U tutto a zero e K fisso

//  PROTOTIPO

void cover(int** m,int n,int k);
void reset_all();  // funzione che prende SOL e U e li resetta
int check_u (); // 1-TUTTIZERI (Presi)  0-altrimenti
int check_sol (); // 1- il vettore sol non ha righe al suo interno, non è stata trovata soluzione  0-altrimenti
void stampa_U();   // helper stampo il vettore U
void stampa_SOL(int **m); // helper stampo il vettore SOL


// static int livello;

/**  il vettore sol e' della stessa dimensione del massimo dei sottoinsiemi */
static int sol_l = K;
static int* sol;
/**  il vettore u e' grande */
static int u_l = 8;
static int* u;

int main ()
{
    int i=0;
    int j = 0;
    int **m;
    sol =  malloc(sol_l * sizeof(int) );
    u = malloc( u_l *sizeof(int) );

    /** Array di puntatori di tipo INT*/
    m = malloc(MAX_ROW*sizeof(int*));

    /** Per ogni */
    for (i= 0;i<MAX_ROW;i++){
        m[i] = malloc(MAX_COL * sizeof(int));
    }

    /** Inizializzazione matrice */
    for(i = 0; i< MAX_ROW; i++){
        for(j=0;j<MAX_COL;j++){
            m[i][j] = 0;
        }
    }

    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[0][3] = 0;

    m[1][0] = 2;
    m[1][1] = 3;
    m[1][2] = 7;
    m[1][3] = 0;

    m[2][0] = 7;
    m[2][1] = 8;
    m[2][2] = 0;

    m[3][0] = 5;
    m[3][1] = 6;
    m[3][2] = 0;

    m[4][0] = 6;
    m[4][1] = 7;
    m[4][2] = 8;
    m[4][3] = 0;

    m[5][0] = 1;
    m[5][1] = 2;
    m[5][2] = 3;
    m[5][3] = 4;
    m[5][4] = 5;

    m[6][0] = 3;
    m[6][1] = 4;
    m[6][2] = 0;

    m[7][0] = 4;
    m[7][1] = 5;
    m[7][2] = 6;
    m[7][3] = 0;

/**    m[3][0] = 3;
    m[3][1] = 4;
    m[3][2] = 0;

    m[4][0] = 4;
    m[4][1] = 5;
    m[4][2] = 6;
    m[4][3] = 0; **/

    reset_all();
    cover(m, MAX_ROW-1 , K);
    if (check_sol() == 1)
        printf("Non e' stata trovata alcuna soluzione \n");
    return 0;
}


void reset_all()
{
    int i;

    // reset U
    for(i=0; i<u_l; i++)
    {
        u[i] = i+1;
    }

    //reset SOL

    for(i=0; i<sol_l; i++)
    {
        sol[i]=-1;
    }
    return;
}

void cover(int** m,int n,int k)
{

    int i,j,flg_marchiaU, p = 0;

    flg_marchiaU=0;

    // terminazioni


    if(check_u() == 1)
    {
        stampa_SOL(m);
        // vinto, stampo SOL
        //for (i=0; i<sol_l; i++)
        //{
         //   printf("Riga %d della matrice",sol[i]);
        //}
        return;
    }else{
        reset_all();
    }

     if(n<0)
    {
        //printf("Non ho piu righe della matrice da esaminare livello di k : %d",k);
        return;
    }


    // ciclo righe matrice ( leggo al contrario per sfruttare il parametro delle righe da leggere e rendere dinamica l'esclusione delle righe
    /** Ad ogni riga in modo decrescente */
    for(i=n; i>=0; i--)
    {
        j=0;
        while(m[i][j] != 0)
        {
            // verifico se la cella è gia "presa" in U

            if(u[m[i][j]-1] == 0 )
            {
                flg_marchiaU = 0;
                break; // esco dal while valore della riga gia presente in U
            }

            flg_marchiaU = 1;
            j++;
        }

        if(flg_marchiaU == 1)
        {
            j=0;
            while(m[i][j] != 0)
            {
                u[m[i][j]-1] = 0;
                //stampa_U();
                j++;
            }
            sol[p]= i; // inserisco dentro sol la riga I , la soluzione dovra' essere letta al rovescio
            p++;
            flg_marchiaU = 0;
        }

        if(p == k){
            // richiamo cover giusto per stampare i sottoinsiemi
            cover(m,n-1,k);
            break;
        }
    }
    //reset_all();
    //cover(m,n-1,k);
}

int check_u()
{
    int i;

    for(i=0; i<u_l; i++)
    {
        if(u[i] > 0)
        {
            return 0;
        }
    }
    return 1;
}

void stampa_U(){
    int i = 0;
    for(i=0; i<u_l; i++){
        printf("%d ",u[i]);
    }
    printf("\n");
}

/** Stampa la soluzione in base alle righe contenute dentro al vettore SOL*/
void stampa_SOL(int **m){
    int i=sol_l-1;
    int j = 0;
    for(i;i>=0;--i){
        printf("( ");
        for(j=0; j < MAX_COL;j++){
            printf("%d ,", m[ sol[i] ][j] );
        }
        printf(" )\n");
    }
}

int check_sol(){
    int i = 0;
    for(i; i< sol_l; i++){
        if( sol[i] == -1)
            return 1;
    }
    return 0;
}

