#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *vetor_aleatorio(int n) {
    int *v = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        v[i] = rand() % 100; //Valor entre 0 e 99
    }

    return v;
}

void imprimir(int *v, int n) {
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    printf("\n");
}

void selection_sort(int *v, int n) {
    //Passar por todos os indices do inicio ao penultimo elemento
    for(int i = 0; i < n-1; i++) {
        //Verificar se o elemento atual é realmente o menor
        int indice_menor = i;

        for(int k = i+1; k < n; k++) {
            if(v[k] < v[indice_menor]){
                indice_menor = k;
            }
        }

        if(indice_menor != i) {
            int tmp = v[indice_menor];
            v[indice_menor] = v[i];
            v[i] = tmp;
        }
    }
}

int main() {
    //inicializar a semente do rand
    srand(time(NULL));

    int tamanho = 10;
    int *vetor = vetor_aleatorio(tamanho);

    imprimir(vetor, tamanho);

    selection_sort(vetor, tamanho);
    imprimir(vetor, tamanho);

    free(vetor);

    return 0;
}