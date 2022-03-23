#include <stdio.h>

int main() {
    int n = 0;
    int contador = 0;

    scanf("%d", &n);

    int vetor[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    for(int i = 0; i < n; i++){
        double divisao = vetor[i];

        while(divisao > 1){
            divisao = divisao/2;
        }

        if(divisao == 1){
            contador++;
        }
    }

    printf("%d", contador);

    return 0;
}