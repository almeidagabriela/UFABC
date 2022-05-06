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

// parametros: vetor, tamanho e indice (posição que queremos verificar)
void max_heapfy(int *v, int n, int i) {
    // Indentificar quem é maior (o proprio elemento ou algum dos seus filhos)
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    // esq < n : verifica se o esq é um indice válido
    if(esq < n && v[esq] > v[maior]) {
        maior = esq;
    }

    if(dir < n && v[dir] > v[maior]) {
        maior = dir;
    }

    // Verificar se houve mudança
    if(maior != i) {
        int tmp = v[i];
        v[i] = v[maior];
        v[maior] = tmp;

        // Chamada recursiva no indice maior
        max_heapfy(v, n, maior);
    }
}

// recebe o vetor e seu comprimento
void build_max_heap(int *v, int n) {
    // Percorrer todos os nós que não são folha e aplicar a função max_heapfy
    // i inicia no primeiro elemento mais "ao fundo" que não é folha
    for(int i = n/2 - 1; i >= 0; i--) {
        max_heapfy(v, n, i);
    }
}

void heapsort(int *v, int n) {
    // Transformar vetor em heap de máximo
    build_max_heap(v, n);

    for(int i = n - 1; i > 0; i--) {
        // A cada interação: trocar primeiro com o ultimo (ultimo do escopo do heap)
        int tmp = v[i];
        v[i] = v[0];
        v[0] = tmp;

        // O comprimento do heap é reduzido em uma unidade a cada interação
        // O elemento 0 é aquele que pode não estar atendendo a propriedade do Heap de Máximo
        max_heapfy(v, i, 0);
    }
}

int main() {
    //inicializar a semente do rand
    srand(time(NULL));

    int tamanho = 10;
    int *vetor = vetor_aleatorio(tamanho);

    /*
    int *vetor = malloc(sizeof(int) * tamanho);
    vetor[0] = 22;
    vetor[1] = 33;
    vetor[2] = 44;
    vetor[3] = 88;
    vetor[4] = 99;
    vetor[5] = 11;
    vetor[6] = 55;
    */

    imprimir(vetor, tamanho);

    heapsort(vetor, tamanho);
    imprimir(vetor, tamanho);

    free(vetor);

    return 0;
}