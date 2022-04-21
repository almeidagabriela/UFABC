#include "ordenar.h"
#include "funcao_comparar.h"

void ordenar_vetor(ItemVetor v[], int n) {

    for(int i = 0; i < n-1; i++){
        int indice_menor = i;

        for(int k = i+1; k < n; k++){
            if(comparar(v[k], v[indice_menor]) < 0){
                indice_menor = k;
            }
        }

        if(indice_menor != i){
            ItemVetor aux = v[indice_menor];
            v[indice_menor] = v[i];
            v[i] = aux;
        }
    }
}