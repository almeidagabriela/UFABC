#include <stdio.h>

int main() {
    int n = 0, contador = 0, comparador = 0, indiceInicio = 0, indiceFim = 0;

    scanf("%d", &n);

    int vetor[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    for(int i = 0; i < n; i++){
        contador++;
        
        if(vetor[i] > vetor[i+1] || i == n-1){
            if(contador > comparador){
                comparador = contador;
                indiceInicio = i+1 - contador;
                indiceFim = i;

                if(i == n-1){
                    indiceFim = i;
                }
            }
            contador = 0;
        }
    }

    for(int i = indiceInicio; i <= indiceFim; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}