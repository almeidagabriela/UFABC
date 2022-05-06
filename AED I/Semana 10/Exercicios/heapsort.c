#include "heapsort.h"
#include "funcao_comparar.h"

void contador(int *comparador) {
    *comparador = *comparador + 1;
}

void max_heapfy(ItemVetor v[], int n, int i, int *comparador) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    int resultado = 0;

    if(esq < n){
        contador(comparador);

        resultado = comparar(v[esq], v[maior]);

        if(resultado > 0){
            maior = esq;
        }
    }

    if(dir < n) {
        contador(comparador);

        resultado = comparar(v[dir], v[maior]);

        if(resultado > 0){
            maior = dir;
        }
    }

    if(maior != i) {
        ItemVetor tmp = v[i];
        v[i] = v[maior];
        v[maior] = tmp;

        max_heapfy(v, n, maior, comparador);
    }
}

void build_max_heap(ItemVetor v[], int n, int *comparador) {
    for(int i = n/2 - 1; i >= 0; i--) {
        max_heapfy(v, n, i, comparador);
    }
}

int heapsort(ItemVetor v[], int n) {
    int comp = 0;
    int *comparador = &comp;

    build_max_heap(v, n, comparador);

    for(int i = n - 1; i > 0; i--) {
        ItemVetor tmp = v[i];
        v[i] = v[0];
        v[0] = tmp;

        max_heapfy(v, i, 0, comparador);
    }

    comp = *comparador;

    return comp;
}