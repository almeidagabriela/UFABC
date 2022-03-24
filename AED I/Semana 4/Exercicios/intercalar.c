#include <stdlib.h>
#include <stdio.h>
//#include "intercalar.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

LinkedNode* intercalar_listas(LinkedNode *inicio1, LinkedNode *inicio2) {
    if(inicio1 != NULL && inicio2 != NULL){
        LinkedNode *atual = inicio1;
        LinkedNode *ultimo = inicio1;

        while(ultimo->next != NULL){
            ultimo = ultimo->next;
        }

        ultimo->next = inicio2;

        while(atual != NULL){
            LinkedNode *proximo = atual->next;

            while(proximo != NULL){
                if(atual->data > proximo->data){

                    int tempData = atual->data;
                    atual->data = proximo->data;
                    proximo->data = tempData;

                }
                proximo = proximo->next;
            }
            atual = atual->next;
        }

        return inicio1;

    }else if(inicio1 != NULL){
        return inicio1;
    }else if(inicio2 != NULL){
        return inicio2;
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

int main() {
    LinkedNode *um = malloc(sizeof(LinkedNode));
    LinkedNode *dois = malloc(sizeof(LinkedNode));
    LinkedNode *tres = malloc(sizeof(LinkedNode));
    LinkedNode *quatro = malloc(sizeof(LinkedNode));

    quatro->data = 22;
    quatro->next = NULL;

    tres->data = 33;
    tres->next = quatro;

    dois->data = 44;
    dois->next = tres;

    um->data = 11;
    um->next = dois;

    LinkedNode *inicio2 = malloc(sizeof(LinkedNode));
    inicio2->data = 12;
    inicio2->next = NULL;

    imprimir(um);

    LinkedNode *inicio = NULL;

    inicio = intercalar_listas(um, inicio2);

    imprimir(inicio);

    free(um);
    free(dois);
    free(tres);
    free(quatro);
    free(inicio2);

    return 0;
}