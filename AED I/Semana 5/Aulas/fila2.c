#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
    int data;
    LinkedNode *next;
};

typedef struct FilaDinamica FilaDinamica;
struct FilaDinamica {
    LinkedNode *inicio, *fim;
};

FilaDinamica *criar_fila() {
    FilaDinamica *fila = malloc(sizeof(FilaDinamica));

    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

//Enfileirar
int enqueue(FilaDinamica *fila, int item) {
    //Inserção no final da fila | Remoção no inicio da fila
    LinkedNode *novo_item = malloc(sizeof(LinkedNode));

    //Se problema na alocação
    if(novo_item == NULL) return 0;

    novo_item->data = item;
    novo_item->next = NULL;

    //Se a fila não for vazia:
    if(fila->fim != NULL)
        fila->fim->next = novo_item;

    fila->fim = novo_item;

    //Caso o novo item for o primeiro elemento
    if(fila->inicio == NULL)
        fila->inicio = novo_item;

    return 1;
}

//Desenfileirar
int dequeue(FilaDinamica *fila, int *item) {
    //Verificar se a fila está vazia
    if(fila->inicio == NULL) return 0;

    LinkedNode *no = fila->inicio;
    *item = no->data;

    //Atualizar inicio
    fila->inicio = fila->inicio->next;

    //Tratamento para remover o ultimo elemento da lista
    if(fila->inicio == NULL)
        fila->fim = NULL;

    free(no);

    return 1;
}

// Liberar 1º Lista ligada 2º Estrutura da fila
void liberar_lista(LinkedNode *no) {
    if (no == NULL) return;

    liberar_lista(no->next);
    free(no);
}

void liberar_fila(FilaDinamica *fila) {
    liberar_lista(fila->inicio);
    free(fila);
}

int main() {
    FilaDinamica *f = criar_fila();
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

    item = 40;
    r = enqueue(f, item);
    printf("E %d : %d\n", item, r);

    item = 50;
    r = enqueue(f, item);
    printf("E %d : %d\n", item, r);

    for(int i = 0; i < 2; i++){
        item = -1;
        r = dequeue(f, &item);
        printf("D %d : %d\n", item, r);
    }

    item = 60;
    r = enqueue(f, item);
    printf("E %d : %d\n", item, r);

    item = 70;
    r = enqueue(f, item);
    printf("E %d : %d\n", item, r);

    for(int i = 0; i < 4; i++){
        item = -1;
        r = dequeue(f, &item);
        printf("D %d : %d\n", item, r);
    }

    //Liberar
    liberar_fila(f);

    return 0;
}