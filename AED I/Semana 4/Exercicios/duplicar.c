#include <stdlib.h>
//#include "duplicar.h"
#include <stdio.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
   int data;
   DLinkedNode *next, *prev;
};

void duplicar_pares1(LinkedNode *inicio) {
    LinkedNode *atual = inicio;

    while(atual != NULL){
        LinkedNode *novo = malloc(sizeof(LinkedNode));

        if(atual->data % 2 == 0){
            novo->data = atual->data;
            novo->next = atual->next;
            atual->next = novo;

            atual = novo->next;
        }else{
            atual = atual->next;
            free(novo);
        }
    }
}

void duplicar_pares2(DLinkedNode *inicio) {
    DLinkedNode *atual = inicio;

    while(atual != NULL){
        DLinkedNode *novo = malloc(sizeof(DLinkedNode));

        if(atual->data % 2 == 0){

            novo->data = atual->data;
            novo->next = atual->next;
            novo->prev = atual;

            if(novo->next != NULL){
                novo->next->prev = novo;
            }

            atual->next = novo;
            atual = novo->next;
        }else{
            atual = atual->next;
            free(novo);
        }
    }
}

void imprimir(LinkedNode *inicio) {
    LinkedNode *atual = inicio;

    while (atual != NULL){
        printf("%d ", atual->data);
        atual = atual->next;
    }

    printf("\n");
}

void imprimir2(DLinkedNode *inicio) {
    DLinkedNode *atual = inicio;

    while (atual != NULL){
        printf("%d ", atual->data);
        atual = atual->next;
    }

    printf("\n");
}

int main() {

    LinkedNode *inicio = malloc(sizeof(LinkedNode));
    LinkedNode *segundo = malloc(sizeof(LinkedNode));
    LinkedNode *terceiro = malloc(sizeof(LinkedNode));
    LinkedNode *quarto = malloc(sizeof(LinkedNode));

    DLinkedNode *inicio2 = malloc(sizeof(DLinkedNode));
    DLinkedNode *segundo2 = malloc(sizeof(DLinkedNode));
    DLinkedNode *terceiro2 = malloc(sizeof(DLinkedNode));
    DLinkedNode *quarto2 = malloc(sizeof(DLinkedNode));

    quarto->data = 4;
    quarto->next = NULL;

    terceiro->data = 3;
    terceiro->next = quarto;

    segundo->data = 2;
    segundo->next = terceiro;

    inicio->data = 10;
    inicio->next = segundo;

    duplicar_pares1(inicio);

    imprimir(inicio);

    free(inicio);
    free(segundo);
    free(terceiro);
    free(quarto);

    quarto2->data = 66;
    quarto2->next = NULL;

    terceiro2->data = 44;
    terceiro2->next = quarto2;

    segundo2->data = 22;
    segundo2->next = terceiro2;

    inicio2->data = 10;
    inicio2->next = segundo2;
    inicio2->prev = NULL;

    segundo2->prev = inicio2;
    terceiro2->prev = segundo2;
    quarto2->prev = terceiro2;

    duplicar_pares2(inicio2);

    imprimir2(inicio2);

    free(inicio2);
    free(segundo2);
    free(terceiro2);
    free(quarto2);

    return 0;
}