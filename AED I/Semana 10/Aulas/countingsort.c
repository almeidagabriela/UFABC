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

// Parametros: vetor, comprimento, limite da faixa de valores que o countingsort assumirá
void countingsort(int *v, int n, int k) {
    // Alocar o vetor para contagem
    int c[k + 1]; //tamanho do vetor

    for(int i = 0; i < k + 1; i++) {
        c[i] = 0;
    }

    // Contagem de frequência
    for(int i = 0; i < n; i++) {
        c[v[i]]++;
    }

    // Somar frequências
    for(int i = 1; i < k + 1; i++) {
        c[i] += c[i - 1];
    }

    // Posicionar os valores do vetor de entrada no vetor de saída
    int saida[n];
    int atual; // valor atual
    for(int i = n -1; i >= 0; i--) {
        atual = v[i];
        saida[c[atual] - 1] = atual;
        c[atual]--;
    }

    //Copiar os elementos do vetor de saída no de entrada
    for(int i = 0; i < n; i++) {
        v[i] = saida[i];
    }
}

int main() {
    //inicializar a semente do rand
    srand(time(NULL));

    int tamanho = 10;
    int *vetor = vetor_aleatorio(tamanho);

    imprimir(vetor, tamanho);

    // Valores vão de 0 a 99 nesse exemplo
    countingsort(vetor, tamanho, 99);
    imprimir(vetor, tamanho);

    free(vetor);

    return 0;
}