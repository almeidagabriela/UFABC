//#include "selectionsort.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

LinkedNode *selection_sort(LinkedNode *inicio, int *trocas, int *comparacoes) {
    LinkedNode *atual;
    LinkedNode *prox;
    *trocas = 0;
    *comparacoes = 0;

    if(inicio == NULL){
        return 0;
    }

    for(atual = inicio; atual->next != NULL; atual = atual->next){
        LinkedNode *menor = atual;

        for(prox = atual->next; prox != NULL; prox = prox->next) {
            *comparacoes = *comparacoes + 1;
            if(prox->data < menor->data){
                menor = prox;
            }
        }

        if(menor != atual) {
            LinkedNode *tmp = menor;
            *trocas = *trocas + 1;
            menor = atual;
            *trocas = *trocas + 1;
            atual = tmp;
            *trocas = *trocas + 1;

            /*LinkedNode *tmp = menor;
            menor = atual;
            atual = tmp;

            *trocas = *trocas + 1;*/
        }
    }

    return inicio;
}

int main() {
    return 0;
}