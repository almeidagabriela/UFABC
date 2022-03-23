#include <stdio.h>

int main(){
    int n, val, soma = 0, multiplica = 0;

    scanf("%d\n", &n);

    int matA[n][n], matB[n][n], matAB[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &val);
            matA[i][j] = val;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &val);
            matB[i][j] = val;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                multiplica = matA[i][k] * matB[k][j];
                soma += multiplica;
            }
            matAB[i][j] = soma;
            soma = 0;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d%c", matAB[i][j], j < n-1?' ':'\n');
        }
    }

    return 0;
}