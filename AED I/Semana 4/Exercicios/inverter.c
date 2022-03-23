#include <stdlib.h>
#include <stdio.h>
//#include "inverter.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

LinkedNode* inverter_lista(LinkedNode *inicio) {
    // Inverter dados do primeiro e ultimo OK
    if(inicio != NULL){
        LinkedNode *auxiliar = malloc(sizeof(LinkedNode));
        LinkedNode *atual = inicio;

        while(atual->next != NULL){
            atual = atual->next;
        }

        auxiliar->data = atual->data;
        atual->data = inicio->data;
        inicio->data = auxiliar->data;

        free(auxiliar);
    }

    

    return inicio;
}

void imprimir(LinkedNode *inicio) {
    LinkedNode *atual = inicio;

    while (atual != NULL){
        printf("%d ", atual->data);
        atual = atual->next;
    }

    printf("\n");
}

int main() {
    LinkedNode *um = malloc(sizeof(LinkedNode));
    LinkedNode *dois = malloc(sizeof(LinkedNode));
    LinkedNode *tres = malloc(sizeof(LinkedNode));
    LinkedNode *quatro = malloc(sizeof(LinkedNode));
    LinkedNode *cinco = malloc(sizeof(LinkedNode));
/*
    cinco->data = 55;
    cinco->next = NULL;
*/
    quatro->data = 44;
    quatro->next = NULL;

    tres->data = 33;
    tres->next = quatro;

    dois->data = 22;
    dois->next = tres;

    um->data = 11;
    um->next = dois;

    imprimir(um);

    LinkedNode *inicio = NULL;

    inicio = inverter_lista(um);

    imprimir(um);

    return 0;
}