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

/*
void bubblesort(int *v, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int k = 0; k < n-1-i; k++) {
            if(v[k] > v[k+1]) {
                int tmp = v[k];
                v[k] = v[k+1];
                v[k+1] = tmp;
            }
        }
    }
}
*/

//bubblesort com parada antecipada
void bubblesort_es(int *v, int n) {
    int trocou = 1;

    for(int i = 0; i < n-1 && trocou; i++) {
        trocou = 0;

        for(int k = 0; k < n-1-i; k++) {
            if(v[k] > v[k+1]) {
                int tmp = v[k];
                v[k] = v[k+1];
                v[k+1] = tmp;

                trocou = 1;
            }
        }
    }
}

int main() {
    //inicializar a semente do rand
    srand(time(NULL));

    int tamanho = 10;
    int *vetor = vetor_aleatorio(tamanho);

    imprimir(vetor, tamanho);

    bubblesort_es(vetor, tamanho);
    imprimir(vetor, tamanho);

    free(vetor);

    return 0;
}