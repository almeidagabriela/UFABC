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

void insertionsort(int *v, int n) {
    for(int i = 1; i < n; i++) {
        // Encaixar o elemento atual no subvetor que vem antes
        int item_atual = v[i];
        int indice_para_insercao = i;

        for(int k = i-1; k >= 0 && item_atual < v[k]; k--) {
            // Desloca o vetor para a direita até encontrar a posição correta para inserção
            v[k+1] = v[k];
            indice_para_insercao--;
        }

        // Insere o elemento
        v[indice_para_insercao] = item_atual;
    }
}

int main() {
    //inicializar a semente do rand
    srand(time(NULL));

    int tamanho = 10;
    int *vetor = vetor_aleatorio(tamanho);

    imprimir(vetor, tamanho);

    insertionsort(vetor, tamanho);
    imprimir(vetor, tamanho);

    free(vetor);

    return 0;
}