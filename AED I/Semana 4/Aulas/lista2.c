#include <stdio.h>
#include <stdlib.h>

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
    int data;
    DLinkedNode *prev, *next;
};

DLinkedNode *inserir_final(DLinkedNode *inicio, int valor) {
    DLinkedNode *novo = malloc(sizeof(DLinkedNode));

    if(novo == NULL) return inicio;

    novo->data = valor;
    novo->prev = NULL;
    novo->next = NULL;

    //Verificar se a lista tem algum elemento
    if(inicio == NULL) return novo;

    DLinkedNode *anterior = NULL;
    DLinkedNode *atual = inicio;

    while(atual != NULL) {
        anterior = atual;
        atual = atual->next;
    }

    anterior->next = novo;
    novo->prev = anterior;

    return inicio;
}

DLinkedNode *remover(DLinkedNode *inicio, int valor) {
    //Percorrer a lista ligada em busca do elemento a ser removido
    DLinkedNode *atual = inicio;

    while(atual != NULL && atual->data != valor){
        atual = atual->next;
    }

    //Verificar se o ATUAL é diferente de NULO. Se for nulo, não encontramos o valor a ser removido.
    if(atual != NULL){
        DLinkedNode *anterior = atual->prev;
        DLinkedNode *proximo = atual->next;

        //Verificar se o anterior é ou não NULO
        if(anterior != NULL){
            anterior->next = proximo;
        }else{
            inicio = proximo;
        }

        if(proximo != NULL){
            proximo->prev = anterior;
        }

        free(atual);
    }

    return inicio;
}

void imprimir(DLinkedNode *inicio) {
    DLinkedNode *atual, *anterior = NULL;

    //Do inicio ao fim
    for(atual = inicio; atual != NULL; atual = atual->next){
        anterior = atual;
        printf("%d ", atual->data);
    }

    printf("\n");

    //Do fim ao inicio
    for(atual = anterior; atual != NULL; atual = atual->prev){
        printf("%d ", atual->data);
    }

    printf("\n");
}

void liberar_lista(DLinkedNode *inicio) {
    if (inicio == NULL) return;

    liberar_lista(inicio->next);
    free(inicio);
}

int main() {
    DLinkedNode *inicio = NULL;

    inicio = inserir_final(inicio, 10);
    inicio = inserir_final(inicio, 20);
    inicio = inserir_final(inicio, 30);
    inicio = inserir_final(inicio, 40);
    imprimir(inicio);

    inicio = remover(inicio, 10);
    imprimir(inicio);

    inicio = remover(inicio, 30);
    imprimir(inicio);

    inicio = remover(inicio, 40);
    imprimir(inicio);

    inicio = remover(inicio, 20);
    imprimir(inicio);

    inicio = inserir_final(inicio, 50);
    inicio = inserir_final(inicio, 60);
    imprimir(inicio);

    liberar_lista(inicio);

    return 0;
}