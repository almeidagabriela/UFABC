#include <stdio.h>
#include <stdlib.h>

void min_heapfy(int *v, int n, int i) {
    int menor = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if(esq < n && v[esq] < v[menor]) {
        menor = esq;
    }

    if(dir < n && v[dir] < v[menor]) {
        menor = dir;
    }

    if(menor != i) {
        int tmp = v[i];
        v[i] = v[menor];
        v[menor] = tmp;

        min_heapfy(v, n, menor);
    }
}

void build_min_heap(int *v, int n) {
    for(int i = n/2 - 1; i >= 0; i--) {
        min_heapfy(v, n, i);
    }
}

void max_heapfy(int *v, int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if(esq < n && v[esq] > v[maior]) {
        maior = esq;
    }

    if(dir < n && v[dir] > v[maior]) {
        maior = dir;
    }

    if(maior != i) {
        int tmp = v[i];
        v[i] = v[maior];
        v[maior] = tmp;

        max_heapfy(v, n, maior);
    }
}

void build_max_heap(int *v, int n) {
    for(int i = n/2 - 1; i >= 0; i--) {
        max_heapfy(v, n, i);
    }
}

void copia_vetor(int *v1, int *v2, int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        v2[i] = v1[i];
    }
}

int verifica_heap(int *v1, int *v2, int tamanho) {
    int retorno = 0;

    for(int i = 0; i < tamanho; i++) {
        if(v1[i] == v2[i]) {
            retorno = 1;
        }else{
            retorno = 0;
            break;
        }
    }

    return retorno;
}

int main() {
    int tamanho = 0, min = 0, max = 0;

    scanf("%d", &tamanho);

    int *vetor = malloc(sizeof(int) * tamanho);
    int *vetor_min = malloc(sizeof(int) * tamanho);
    int *vetor_max = malloc(sizeof(int) * tamanho);

    for(int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    copia_vetor(vetor, vetor_min, tamanho);
    copia_vetor(vetor, vetor_max, tamanho);

    build_min_heap(vetor_min, tamanho);
    build_max_heap(vetor_max, tamanho);

    min = verifica_heap(vetor, vetor_min, tamanho);
    max = verifica_heap(vetor, vetor_max, tamanho);

    if(min) {
        printf("1\n");
    }else if(max) {
        printf("2\n");
    }else{
        printf("0\n");
    }

    free(vetor);
    free(vetor_min);
    free(vetor_max);

    return 0;
}