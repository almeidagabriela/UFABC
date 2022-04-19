#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *vetor_aleatorio(int n) {
    int *v = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        // Vetor aleatório
        v[i] = rand() % 100; //Valor entre 0 e 99

        // Vetor ordenado "Melhor caso"
        //v[i] = i;

        // Vetor em ordem descrescente "Pior caso"
        //v[i] = n-i;
    }

    return v;
}

void imprimir(int *v, int n) {
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    printf("\n");
}

int compara(int a, int b, int *count) {
    *count = *count + 1;
    return (a > b); // Crescente a > b; Descrescente a < b
}

int selection_sort(int *v, int n) {
    int count = 0;

    //Passar por todos os indices do inicio ao penultimo elemento
    for(int i = 0; i < n-1; i++) {
        //Verificar se o elemento atual é realmente o menor
        int indice_menor = i;

        for(int k = i+1; k < n; k++) {
            if(compara(v[indice_menor], v[k], &count)){
                indice_menor = k;
            }
        }

        if(indice_menor != i) {
            int tmp = v[indice_menor];
            v[indice_menor] = v[i];
            v[i] = tmp;
        }
    }

    return count;
}

int bubblesort_es(int *v, int n) {
    int trocou = 1, count = 0;

    for(int i = 0; i < n-1 && trocou; i++) {
        trocou = 0;

        for(int k = 0; k < n-1-i; k++) {
            if(compara(v[k], v[k+1], &count)) {
                int tmp = v[k];
                v[k] = v[k+1];
                v[k+1] = tmp;

                trocou = 1;
            }
        }
    }

    return count;
}

int insertionsort(int *v, int n) {
    int count = 0;

    for(int i = 1; i < n; i++) {
        // Encaixar o elemento atual no subvetor que vem antes
        int item_atual = v[i];
        int indice_para_insercao = i;

        for(int k = i-1; k >= 0 && compara(v[k], item_atual, &count); k--) {
            // Desloca o vetor para a direita até encontrar a posição correta para inserção
            v[k+1] = v[k];
            indice_para_insercao--;
        }

        // Insere o elemento
        v[indice_para_insercao] = item_atual;
    }

    return count;
}

int shellsort(int *v, int n) {
    int h = 1;// O valor inicial será 1/3 ou mais que o tamanho do vetor
    int count = 0;

    while(h < n / 3) h = 3 * h + 1;

    while(h >= 1) {
        for(int i = h; i < n; i++) {
            int item_atual = v[i];
            int indice_para_insercao = i;

            for(int k = i-h; k >= 0 && compara(v[k], item_atual, &count); k-=h) {
                v[k+h] = v[k];
                indice_para_insercao-=h;
            }

            // Insere o elemento
            v[indice_para_insercao] = item_atual;
        }

        h = h / 3;
    }

    return count;

}

int main() {
    //inicializar a semente do rand
    srand(time(NULL));

    int tamanho = 20;
    int *vetor = NULL;

    // Selection sort
    printf("Selection sort:\n");
    vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);

    int count = selection_sort(vetor, tamanho);
    imprimir(vetor, tamanho);
    printf("C = %d\n", count);
    free(vetor);

    // Bubble sort
    printf("\nBubble sort:\n");
    vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);

    count = bubblesort_es(vetor, tamanho);
    imprimir(vetor, tamanho);
    printf("C = %d\n", count);
    free(vetor);

    // Insertion sort
    printf("\nInsertion sort:\n");
    vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);

    count = insertionsort(vetor, tamanho);
    imprimir(vetor, tamanho);
    printf("C = %d\n", count);
    free(vetor);

    // Shell sort
    printf("\nShell sort:\n");
    vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);

    count = shellsort(vetor, tamanho);
    imprimir(vetor, tamanho);
    printf("C = %d\n", count);
    free(vetor);

    return 0;
}