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

void shellsort(int *v, int n) {
    int h = 1;// O valor inicial será 1/3 ou mais que o tamanho do vetor

    while(h < n / 3) h = 3 * h + 1;

    while(h >= 1) {
        for(int i = h; i < n; i++) {
            int item_atual = v[i];
            int indice_para_insercao = i;

            for(int k = i-h; k >= 0 && item_atual < v[k]; k-=h) {
                v[k+h] = v[k];
                indice_para_insercao-=h;
            }

            // Insere o elemento
            v[indice_para_insercao] = item_atual;
        }

        h = h / 3;
    }

}

int main() {
    //inicializar a semente do rand
    srand(time(NULL));

    int tamanho = 10;
    int *vetor = vetor_aleatorio(tamanho);

    imprimir(vetor, tamanho);

    shellsort(vetor, tamanho);
    imprimir(vetor, tamanho);

    free(vetor);

    return 0;
}