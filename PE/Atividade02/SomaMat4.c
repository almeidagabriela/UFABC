#include <stdio.h>

int main(){
    int n, val, soma = 0;

    scanf("%d\n", &n);

    int mat[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &val);
            mat[i][j] = val;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j < n-1-i){
                soma += mat[i][j];
            }
        }
    }

    printf("%d\n", soma);

    return 0;
}