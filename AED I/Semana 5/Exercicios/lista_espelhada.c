#include <stdlib.h>
#include <stdio.h>
//#include "lista.h"
//#include "lista_espelhada.h"
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

void liberar_listaF(LinkedNode *no) {
    if (no == NULL) return;

    liberar_listaF(no->next);
    free(no);
}

void liberar_fila(FilaDinamica *fila) {
    liberar_listaF(fila->inicio);
    free(fila);
}

int verificar_lista(LinkedNode *lista) {
    PilhaDinamica *p = criar_pilha();
    FilaDinamica *f = criar_fila();
    LinkedNode *atual = lista;
    int cont = 0, verifica = 0;

    while (atual != NULL){
        push(p, atual->data);
        enqueue(f, atual->data);
        atual = atual->next;
        cont++;
    }

    for(int i = 0; i < cont; i++){
        verifica = 1;

        if(p->topo->data != f->inicio->data){
            verifica = 0;
            i = cont;
        }

        int item = -1;
        pop(p, &item);

        item = -1;
        dequeue(f, &item);
    }

    liberar_pilha(p);
    liberar_fila(f);

    return verifica;
}

LinkedNode *inserir_final_r(LinkedNode *inicio, int valor){
    //CASO BASE
    // Se a lista ligada estiver vazia
    if(inicio == NULL){
        LinkedNode *novo = malloc(sizeof(LinkedNode));
        //Verificar se a alocação deu certo
        if(novo == NULL) return inicio;
        novo->data = valor;
        novo->next = NULL;
        return novo;
    }

    //Se a lista não for vazia
    inicio->next = inserir_final_r(inicio->next, valor);
    return inicio; //Caso não caia no caso base
}

int main() {

    LinkedNode *inicio = NULL;

    int n;
    scanf("%d", &n); //Leitura

    while(n != -1){
        inicio = inserir_final_r(inicio, n);
        scanf("%d", &n);
    }

    int retorno = verificar_lista(inicio);

    return 0;
}