#include <stdio.h>

int main(){
    int n, val, cont = 0;
    float soma = 0, media = 0;

    scanf("%d\n", &n);

    int mat[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d\n", &val);
            mat[i][j] = val;
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d\n", mat[i][n-1-i]);
    }

    return 0;
}