#include <stdio.h>

int main(){
    int n, val;

    scanf("%d\n", &n);

    int matA[n][n], matB[n][n], matSoma[n][n];

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
            matSoma[i][j] = matA[i][j] + matB[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d%c", matSoma[i][j], j < n-1?' ':'\n');
        }
    }

    return 0;
}