#include <stdlib.h>
#include <stdio.h>
//#include "intercalar.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

LinkedNode* intercalar_listas(LinkedNode *inicio1, LinkedNode *inicio2) {
    LinkedNode *atual = inicio1;


    // NÃO ALOCAR NÓS mas usar auxliar pode rs

    // Ia até o final da lista 1 (se não for vazia né)
    // E add a referencia do primeiro ponto da lista 2
    

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
    quatro->data = 22;
    quatro->next = NULL;

    tres->data = 33;
    tres->next = quatro;

    dois->data = 44;
    dois->next = tres;

    um->data = 11;
    um->next = dois;

    LinkedNode *inicio2 = NULL;

    imprimir(um);

    LinkedNode *inicio = NULL;

    inicio = intercalar_listas(um, inicio2);

    imprimir(inicio);

    free(um);
    free(dois);
    free(tres);
    free(quatro);
    free(cinco);

    return 0;
}