#include <stdio.h>

void preencheVet(int *, int);

int main(){
    int n, m, vetM[300], qtdCompradas = 0, falta = 0;

    scanf("%d", &n); //Espaços

    scanf("%d", &m); //Compradas

    preencheVet(vetM, m);

    int igual = -1;

    for(int j = 1; j <= n; j++){
        for(int i = 0; i < m; i++){
            if(vetM[i] == j && igual == -1){
                qtdCompradas++;
                igual = j;
            }
        }
        igual = -1;
    }

    falta = n - qtdCompradas;
    printf("%d\n", falta);

    return 0;
}

void preencheVet(int *v, int n){
    for(int i = 0; i < n; i++){
        scanf("%d\n", &v[i]);
    }
}