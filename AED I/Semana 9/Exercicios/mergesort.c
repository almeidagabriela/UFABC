#include <stdio.h>
#include <stdlib.h>

void contador(int *comparador) {
    *comparador = *comparador + 1;
}

void imprimir(int *v, int n) {
    for(int i = 0; i < n; i++){
        printf("%d", v[i]);

        if(i != n-1){
            printf(" ");
        }
    }
    printf("\n");
}

void intercala(int *v, int esq_inicio, int esq_fim, int dir_fim, int *comparador) {
    int dir_inicio = esq_fim + 1;
    int esq = esq_inicio, dir = dir_inicio;
    int comp = dir_fim - esq_inicio + 1;
    int *v_aux = malloc(sizeof(int) * comp);

    for(int i = 0; i < comp; i++){
        if(esq > esq_fim) {
            v_aux[i] = v[dir++];
        }else if(dir > dir_fim) {
            v_aux[i] = v[esq++];
        }else if(v[esq] <= v[dir]){
            contador(comparador);
            v_aux[i] = v[esq++];
        }else{
            contador(comparador);
            v_aux[i] = v[dir++];
        }
    }

    for(int i = 0; i < comp; i++){
        v[esq_inicio + i] = v_aux[i];
    }

    free(v_aux);
}

void mergesort(int *v, int esq, int dir, int *comparador) {

    if (esq < dir) {
        int meio = (esq + dir) / 2;
        mergesort(v, esq, meio, comparador);
        mergesort(v, meio + 1, dir, comparador);

        intercala(v, esq, meio, dir, comparador);
    }
}

void merge_sort(int *v, int n, int *comparador) {
    mergesort(v, 0, n - 1, comparador);

    if(n-1 == 0){
        *comparador = 0;
    }
}

int main() {
    int n, n_lista, inicializador = 0;
    int *comparador = malloc(sizeof(int));

    scanf("%d", &n);

    int *v = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        scanf("%d", &n_lista);
        v[i] = n_lista;
    }

    merge_sort(v, n, comparador);
    imprimir(v, n);
    printf("Comparacoes: %d\n", *comparador);

    free(v);
    free(comparador);

    return 0;
}