#include <stdio.h>
#include <stdlib.h>

typedef struct FilaCircular FilaCircular;
struct FilaCircular {
    int *itens;
    int tamanho, inicio, fim;
};

FilaCircular *criar_fila(int tamanho) {
    FilaCircular *fila = malloc(sizeof(FilaCircular));

    fila->itens = malloc(sizeof(int) * tamanho);
    fila->tamanho = tamanho;
    fila->inicio = 0;
    fila->fim = 0;

    return fila;
}

//Enfileirar
int enqueue(FilaCircular *fila, int item) {
    int novo_fim = (fila->fim + 1) % fila->tamanho;

    //Verifica se a fila está cheia
    if(novo_fim == fila->inicio) return 0;

    //Inserir elemento
    fila->itens[fila->fim] = item;
    fila->fim = novo_fim;

    return 1;
}

//Desenfileirar
int dequeue(FilaCircular *fila, int *item) {
    //Verifica se a fila está vazia
    if(fila->inicio == fila->fim) return 0;

    //Remover elemento
    *item = fila->itens[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->tamanho;

    //Mesma coisa que:
    /*
    int novo_inicio = (fila->inicio + 1) % fila->tamanho;
    fila->inicio = novo_inicio;
    */

    return 1;
}

// Liberar 1º Itens 2º Estrutura da fila
void liberar_fila(FilaCircular *fila) {
    free(fila->itens);
    free(fila);
}

int main() {
    FilaCircular *f = criar_fila(4); //Fila de tamanho 4
    int r, item;

    item = 10;
    r = enqueue(f, item);
    printf("E %d : %d\n", item, r);

    item = 20;
    r = enqueue(f, item);
    printf("E %d : %d\n", item, r);

    item = 30;
    r = enqueue(f, item);
    printf("E %d : %d\n", item, r);

    //A partir daqui já não consegue enfileirar, tamanho = 4 capacidade de enfileiramento = 3
    item = 40;
    r = enqueue(f, item);
    printf("E %d : %d\n", item, r); //Retorno = 0

    item = 50;
    r = enqueue(f, item);
    printf("E %d : %d\n", item, r); //Retorno = 0

    for(int i = 0; i < 2; i++){
        item = -1;
        r = dequeue(f, &item);
        printf("D %d : %d\n", item, r);
    }

    item = 60;
    r = enqueue(f, item);
    printf("E %d : %d\n", item, r); //Retorno = 0

    item = 70;
    r = enqueue(f, item);
    printf("E %d : %d\n", item, r); //Retorno = 0

    for(int i = 0; i < 4; i++){
        item = -1;
        r = dequeue(f, &item);
        printf("D %d : %d\n", item, r);
    }

    //Liberar
    liberar_fila(f);

    return 0;
}