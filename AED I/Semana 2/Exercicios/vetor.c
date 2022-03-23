#include "vetor.h"
#include <stdlib.h>

int *expandir_vetor(const int *vetor, int n_compactado, int *n_expandido) {
    *n_expandido = 0;
    int indice = 0;

    for(int i = 1; i < n_compactado; i+=2){
        *n_expandido += vetor[i];
    }

    int *vetor_expandido = malloc(sizeof(int) * *n_expandido);

    for(int i = 1; i < n_compactado; i+=2){
        for(int j = 1; j <= vetor[i]; j++){
            vetor_expandido[indice] = vetor[i-1];
            indice++;
        }
    }

    return vetor_expandido;
}