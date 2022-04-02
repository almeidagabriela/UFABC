#include <stdio.h>
#include <stdlib.h>
//#include "pilha.h"
//#include "fila.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
    int data;
    LinkedNode *next;
};

typedef struct PilhaDinamica PilhaDinamica;
struct PilhaDinamica {
    LinkedNode *topo;
};

typedef struct FilaDinamica FilaDinamica;
struct FilaDinamica {
    LinkedNode *inicio, *fim;
};

PilhaDinamica *criar_pilha() {
    PilhaDinamica *pilha = malloc(sizeof(PilhaDinamica));
    pilha->topo = NULL;
    return pilha;
}

int push(PilhaDinamica *pilha, int item){
    //Topo = inicio
    LinkedNode *novo_item = malloc(sizeof(LinkedNode));

    if(novo_item == NULL) return 0;

    novo_item->data = item;
    novo_item->next = pilha->topo;

    pilha->topo = novo_item;

    return 1;
}

int pop(PilhaDinamica *pilha, int *item){
    //Verifica se está vazia
    if(pilha->topo == NULL) return 0;

    LinkedNode *no = pilha->topo;
    pilha->topo = pilha->topo->next;

    *item = no->data;
    free(no);

    return 1;
}

void liberar_lista(LinkedNode *no){
    if(no == NULL) return;
    liberar_lista(no->next);
    free(no);
}

void liberar_pilha(PilhaDinamica *pilha){
    liberar_lista(pilha->topo);
    free(pilha);
}

FilaDinamica *criar_fila() {
    FilaDinamica *fila = malloc(sizeof(FilaDinamica));

    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

int enqueue(FilaDinamica *fila, char item) {
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

int dequeue(FilaDinamica *fila, char *item) {
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

void liberar_listaF(LinkedNode *no) {
    if (no == NULL) return;

    liberar_listaF(no->next);
    free(no);
}

void liberar_fila(FilaDinamica *fila) {
    liberar_listaF(fila->inicio);
    free(fila);
}

int main() {
    FilaDinamica *f = criar_fila();
    char ganhador = 'z', primeiro = 'z', segundo = 'z';

    for(int i = 1; i <= 15; i++){
        int m, n;
        scanf("%d %d", &m, &n);

        if(i <= 8){
            if(m > n){
                switch (i){
                    case 1:
                        ganhador = 'A';
                        break;
                    case 2:
                        ganhador = 'C';
                        break;
                    case 3:
                        ganhador = 'E';
                        break;
                    case 4:
                        ganhador = 'G';
                        break;
                    case 5:
                        ganhador = 'I';
                        break;
                    case 6:
                        ganhador = 'K';
                        break;
                    case 7:
                        ganhador = 'M';
                        break;
                    case 8:
                        ganhador = 'O';
                        break;
                }
                enqueue(f, ganhador);
            }else{
                switch (i){
                    case 1:
                        ganhador = 'B';
                        break;
                    case 2:
                        ganhador = 'D';
                        break;
                    case 3:
                        ganhador = 'F';
                        break;
                    case 4:
                        ganhador = 'H';
                        break;
                    case 5:
                        ganhador = 'J';
                        break;
                    case 6:
                        ganhador = 'L';
                        break;
                    case 7:
                        ganhador = 'N';
                        break;
                    case 8:
                        ganhador = 'P';
                        break;
                }
                enqueue(f, ganhador);
            }
        }else{
            char item = 'a';
            dequeue(f, &item);
            primeiro = item;
            dequeue(f, &item);
            segundo = item;

            if(m > n){
                enqueue(f, primeiro);
            }else{
                enqueue(f, segundo);
            }
        }
    }

    char item = 'a';
    dequeue(f, &item);
    liberar_fila(f);

    printf("%s", &item);

    return 0;
}