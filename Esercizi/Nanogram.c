#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 5
#define MAX_COL 5

// static int livello;

int main ()
{
    int i=0;
    int j = 0;
    int **m;
    int** colonne;
    int** righe;

    // LETTURA DA FILE

    /** Array di puntatori di tipo INT*/
    m = malloc(MAX_ROW*sizeof(int*));
    righe = malloc(MAX_ROW* sizeof(int*));
    colonne = malloc(MAX_COL*sizeof(int*));

    /** Per ogni */
    for (i= 0;i<MAX_ROW;i++){
        m[i] = malloc(MAX_COL * sizeof(int));
        righe[i] = malloc(MAX_COL * sizeof(int));
        colonne[i] = malloc(MAX_COL * sizeof(int));
    }

    /** Inizializzazione matrice */
    for(i = 0; i< MAX_ROW; i++){
        for(j=0;j<MAX_COL;j++){
            m[i][j] = 0;
            righe[i][j] = 0;
            colonne[i][j] = 0;
        }
    }
    m[0][3]= 1;

    // setup numero di righe per riga
    righe[0][0] = 1;
    righe[1][0] = 3;
    righe[2][0] = 3;
    righe[3][0] = 1;
    righe[4][0] = 3;

    colonne[0][0] = 1;
    colonne[1][0] = 1;
    colonne[2][0] = 1;
    colonne[3][0] = 1;
    colonne[4][0] = 3;

    colonne[2][1] = 3;
    colonne[3][1] = 1;

    //printf("%d", strcmp(",",separatore));

    stampa_matrice(m);
    stampa_matrice(righe);
    stampa_matrice(colonne);

    printf("%d", verifica_vettore(m, righe,0,0));
    return 0;
}

void stampa_matrice(int** m){
    int i = 0;
    int j = 0;
    printf("\n");
    printf("____________\n");
    for(i = 0; i< MAX_ROW; i++){
        for(j=0;j<MAX_COL;j++){
            printf("%d ",m[i][j]) ;
        }
        printf("\n");
    }
     printf("____________\n");
}

/**
*   Controlla la coerenza del vettore pvet con il vettore psorgente
*   Ritorna 0 se sbagliato , 1 se corretto
*/
int verifica_vettore(int ** pmat, int** psorgente, int rowcol,int sourowcol){
    int i = 0;
    int j = 0;
    int contatore = 0;
    int prossimo_vuoto = 0;

    while(psorgente[sourowcol][j] != 0){
        for(i= 0; i< MAX_COL; i++){
            if (prossimo_vuoto == 1){

                if(pmat[rowcol][i]== 0){
                    prossimo_vuoto =1;
                }else{
                    prossimo_vuoto= 0;
                }
            }

            if(pmat[rowcol][i] != 0){
                contatore ++;
            }

            printf("%d \n",contatore);

            if (contatore == psorgente[sourowcol][j]){
                j++;
                contatore = 0;
                prossimo_vuoto = 1;
            }

            if(contatore > psorgente[sourowcol][j]){
                return 0;
            }

        } // end for

        if (contatore == 0 ){
            j++;
        }
    } // end while

    if (contatore != 0){
        return 0;
    }else{
        return 1;
    }

}
