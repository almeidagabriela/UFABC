#include "valor_freq.h"

int valor_frequente(int v[], int n) {
    int contador = 0, repetido = 0, indiceVetor = -1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i] == v[j]){
                contador++;
            }
        }
        if(contador > repetido){
            indiceVetor = i;
            repetido = contador;
        }

        contador = 0;
    }

    return v[indiceVetor];
}