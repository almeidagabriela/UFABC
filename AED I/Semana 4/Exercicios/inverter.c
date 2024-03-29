#include <stdlib.h>
#include <stdio.h>
//#include "inverter.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

LinkedNode* inverter(LinkedNode *inicio) {
    if(inicio == NULL){
        return inicio;
    }else{
        if(inicio != NULL){

            if(inicio->next->next != NULL){
                inicio->next = inverter(inicio->next);
            }

            if(inicio->next->next == NULL){
                inicio->next->next = inicio;
                inicio->next = NULL;
            }

            return inicio;
        }else{
            return inicio;
        }
    }
}

LinkedNode* inverter_lista(LinkedNode *inicio) {
    if(inicio != NULL && inicio->next != NULL){
        LinkedNode *atual = inicio;
        LinkedNode *auxiliar = NULL;

        while(atual->next != NULL){
            atual = atual->next;
        }

        inicio = inverter(inicio);

        auxiliar = atual;
        atual = inicio;
        inicio = auxiliar;
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

    imprimir(inicio);

    free(um);
    free(dois);
    free(tres);
    free(quatro);
    free(cinco);

    return 0;
}