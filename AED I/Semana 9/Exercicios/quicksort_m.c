#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "quicksort_m.h"

int *vetor_aleatorio(int n) {
    int *v = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        v[i] = rand() % 1000; //Valor entre 0 e 99
    }

    return v;
}

void imprimir(int *v, int n) {
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    printf("\n");
}

int unidade (int *valor) {
    int novo;
    int resto = 0;

    novo = *valor / 10;
    resto = *valor % 10;

    *valor = novo;

    return resto;
}

int compara(int a, int b) {
    if(a == b) return 0;

    if(a < 10 && b > 10) return 0;
    if(a > 10 && b < 10) return 1;

    int a_novo = a, b_novo = b;
    int a_resto = 0;
    int b_resto = 0;
    int retorno = 0, continuar = 1;

    while(a_novo != 0  || b_novo != 0){
        a_resto = unidade(&a_novo);
        b_resto = unidade(&b_novo);

        switch(a_resto) {
            case 0:
                if(b_resto != 0){
                    retorno = 0;
                    continuar = 0;
                }
                break;
            case 5:
                if(b_resto == 0){
                    retorno = 1;
                    continuar = 0;
                }else if(b_resto != 5){
                    retorno = 0;
                    continuar = 0;
                }
                break;
            case 6:
                if(b_resto == 0 || b_resto == 5){
                    retorno = 1;
                    continuar = 0;
                }else if(b_resto != 6){
                    retorno = 0;
                    continuar = 0;
                }
                break;
            case 4:
                if(b_resto == 0 || b_resto == 5 || b_resto == 6){
                    retorno = 1;
                    continuar = 0;
                }else if(b_resto != 4){
                    retorno = 0;
                    continuar = 0;
                }
                break;
            case 8:
                if(b_resto == 0 || b_resto == 5 || b_resto == 6 || b_resto == 4){
                    retorno = 1;
                    continuar = 0;
                }else if(b_resto != 8){
                    retorno = 0;
                    continuar = 0;
                }
                break;
            case 9:
                if(b_resto == 0 || b_resto == 5 || b_resto == 6 || b_resto == 4 || b_resto == 8){
                    retorno = 1;
                    continuar = 0;
                }else if(b_resto != 9){
                    retorno = 0;
                    continuar = 0;
                }
                break;
            case 7:
                if(b_resto == 0 || b_resto == 5 || b_resto == 6 || b_resto == 4 || b_resto == 8 || b_resto == 9){
                    retorno = 1;
                    continuar = 0;
                }else if(b_resto != 7){
                    retorno = 0;
                    continuar = 0;
                }
                break;
            case 3:
                if(b_resto == 0 || b_resto == 5 || b_resto == 6 || b_resto == 4 || b_resto == 8 || b_resto == 9 || b_resto == 7){
                    retorno = 1;
                    continuar = 0;
                }else if(b_resto != 3){
                    retorno = 0;
                    continuar = 0;
                }
                break;
            case 1:
                if(b_resto == 0 || b_resto == 5 || b_resto == 6 || b_resto == 4 || b_resto == 8 || b_resto == 9 || b_resto == 7 || b_resto == 3){
                    retorno = 1;
                    continuar = 0;
                }else if(b_resto != 1){
                    retorno = 0;
                    continuar = 0;
                }
                break;
            case 2:
                if(b_resto == 0 || b_resto == 5 || b_resto == 6 || b_resto == 4 || b_resto == 8 || b_resto == 9 || b_resto == 7 || b_resto == 3 || b_resto == 1){
                    retorno = 1;
                    continuar = 0;
                }else if(b_resto != 2){
                    retorno = 0;
                    continuar = 0;
                }
                break;
        }
    }

    return retorno;
}

int particiona(int *v, int esq, int dir, int *comparador) {
    int pivo = v[dir];
    int ultimo_menores = esq - 1;

    for(int i = esq; i < dir; i++) {
        *comparador = *comparador + 1;

        if(compara(pivo, v[i])){
            ultimo_menores++;

            int aux = v[ultimo_menores];
            v[ultimo_menores] = v[i];
            v[i] = aux;
        }
    }

    ultimo_menores++;
    v[dir] = v[ultimo_menores];
    v[ultimo_menores] = pivo;

    return ultimo_menores;
}

void quick_sort(int *v, int esq, int dir, int *comparador) {
    if(esq < dir) {
        int i_pivo = particiona(v, esq, dir, comparador);

        quick_sort(v, esq, i_pivo - 1, comparador);
        quick_sort(v, i_pivo + 1, dir, comparador);
    }
}

int quicksortm(int *v, int n) {
    int comp = 0;
    int *comparador = &comp;

    quick_sort(v, 0, n-1, comparador);

    comp = *comparador;

    return comp;
}

int main() {
    //inicializar a semente do rand
    srand(time(NULL));

    int tamanho = 10;
    int *vetor = vetor_aleatorio(tamanho);

    imprimir(vetor, tamanho);

    int compara = quicksortm(vetor, tamanho);
    imprimir(vetor, tamanho);
    printf("Comparações: %d\n", compara);

    free(vetor);

    return 0;
}