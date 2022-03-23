//#include "numeros_matriz.h"
#include <stdio.h>

void remover_numeros_matriz(int l, int c, int n_linhas, int n_colunas, int m[n_linhas][n_colunas]) {
    int valorInicial = m[l][c];
    int contador = 0;

     m[l][c] = 0;

    if(l != n_linhas-1){
        if(m[l+1][c] == valorInicial){
            remover_numeros_matriz(l+1, c, n_linhas, n_colunas, m);
            m[l+1][c] = 0;
        }
    }

    if(l != 0){
        if(m[l-1][c] == valorInicial){
            remover_numeros_matriz(l-1, c, n_linhas, n_colunas, m);
            m[l-1][c] = 0;
        }
    }

    if(c != n_colunas-1){
        if(m[l][c+1] == valorInicial){
            remover_numeros_matriz(l, c+1, n_linhas, n_colunas, m);
            m[l][c+1] = 0;
        }
    }

    if(c != 0){
        if(m[l][c-1] == valorInicial){
            remover_numeros_matriz(l, c-1, n_linhas, n_colunas, m);
            m[l][c-1] = 0;
        }
    }
}

int main() {
    int l = 2, c = 0, n_linhas = 5, n_colunas = 5, m[5][5];

    for(int i = 0; i < n_linhas; i++){
        for(int j = 0; j < n_linhas; j++){
            scanf("%d", &m[i][j]);
        }
    }

    remover_numeros_matriz(l, c, n_linhas, n_colunas, m);

    for(int i = 0; i < n_linhas; i++){
        for(int j = 0; j < n_linhas; j++){
            printf("%d ", m[i][j]);
        }

        printf("\n");
    }

    return 0;
}