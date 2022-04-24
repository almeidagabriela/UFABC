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

void intercala(int *v, int esq_inicio, int esq_fim, int dir_fim) {
    int dir_inicio = esq_fim + 1;
    int esq = esq_inicio, dir = dir_inicio; // esq: percorre vetor da esquerda | dir: percorre vetor da direita
    int comp = dir_fim - esq_inicio + 1;
    int *v_aux = malloc(sizeof(int) * comp);

    for(int i = 0; i < comp; i++){
        // Verificar se os indices esq ou dir passaram dos limites dos vetores percorridos pelos mesmos
        if(esq > esq_fim) {
            v_aux[i] = v[dir++]; //Pega o elemento e depois incrementa
        }else if(dir > dir_fim) {
            v_aux[i] = v[esq++];
        }else if(v[esq] <= v[dir]){
            v_aux[i] = v[esq++];
        }else{
            v_aux[i] = v[dir++];
        }
    }

    for(int i = 0; i < comp; i++){
           v[esq_inicio + i] = v_aux[i];
    }

    free(v_aux);
}

// Função auxiliar
void mergesort(int *v, int esq, int dir) {
    // Verificar se há pelo menos dois elementos no escopo
    if (esq < dir) {
        int meio = (esq + dir) / 2; // Ponto medio entre esq e dir
        mergesort(v, esq, meio); // Vetor da esqueda
        mergesort(v, meio + 1, dir); // Vetor da direita
        intercala(v, esq, meio, dir);
    }
}

// Função principal
void merge_sort(int *v, int n) {
    mergesort(v, 0, n - 1);
}

int main() {
    //inicializar a semente do rand
    srand(time(NULL));

    int tamanho = 10;

    //Teste da função "intercala"
    /*
    int *vetor = malloc(sizeof(int) * tamanho);
    vetor[0] = 5;
    vetor[1] = 9;
    vetor[2] = 10;
    vetor[3] = 25;
    vetor[4] = 36;
    vetor[5] = 2;
    vetor[6] = 7;
    vetor[7] = 8;
    vetor[8] = 40;
    vetor[9] = 507;
    imprimir(vetor, tamanho);

    intercala(vetor, 0, 4, 9);
    imprimir(vetor, tamanho);
    */

    int *vetor = vetor_aleatorio(tamanho);

    imprimir(vetor, tamanho);

    merge_sort(vetor, tamanho);
    imprimir(vetor, tamanho);

    free(vetor);

    return 0;
}