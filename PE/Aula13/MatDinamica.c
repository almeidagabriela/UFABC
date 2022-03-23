#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheMat(int **, int, int);
void mostraMat(int **, int, int);

int main(){
    int **mat, n, m;

    scanf("%d %d", &n, &m);

    // Declarando um vetor que guarda endereços de inteiros
    // Ou seja, estamos construindo matrizes.
    mat = (int**) malloc(n*sizeof(int*));

    for(int i = 0; i < n; i++){
        mat[i] = (int*) malloc(n*sizeof(int));
    }

    preencheMat(mat, n, m);
    mostraMat(mat, n, m);

    return 0;
}

void preencheMat(int **m, int l, int c){
    int i, j;
    // Numeros randomicos
    srand(time(NULL));

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            m[i][j] = rand()%10; //Gerando de 0 a 9
        }
    }
}

void mostraMat(int **m, int l, int c){
    int i, j;

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("%d%c", m[i][j], j < c-1?' ':'\n');
        }
    }
}