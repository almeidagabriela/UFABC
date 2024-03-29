#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVetor(int *, int);
void printVetor(int *, int);

int main(){
    int *vet, n;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);

    vet = (int*) malloc(n * sizeof(int));

    preencheVetor(vet, n);
    printVetor(vet, n);
    free(vet);

    return 0;
}

void preencheVetor(int *v, int n){
    int i;

    srand(time(NULL));// Inicializa o gerador de número randomico
    for(i = 0; i < n; i++){
        v[i] = rand()%100; // Rand: gera um número randomico
    }
}

void printVetor(int *v, int n){
    int i;

    for(i = 0; i < n; i++){
        printf("%d %c", v[i], i < n-1 ?' ':'\n');
    }
}