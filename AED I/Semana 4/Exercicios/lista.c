#include <stdio.h>
#include <stdlib.h>
//#include "lista.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

void contar(LinkedNode *inicio, int *qtd, int *soma) {
    LinkedNode *atual;
    *qtd = 0;
    *soma = 0;

    for(atual = inicio; atual != NULL; atual = atual->next){
           *qtd = *qtd + 1;
           *soma += atual->data;
    }

    free(atual);
}

void imprimir1(LinkedNode *inicio) {
    // Impressao nao deve incluir espaco apos ultimo caractere
    // Deve ser incluido um \n ao final da impressao

    LinkedNode *atual;

    for(atual = inicio; atual != NULL; atual = atual->next){
        if(atual->next == NULL){
            printf("%d\n", atual->data);
        }else{
            printf("%d ", atual->data);
        }
    }

    free(atual);
}

void imprimeLinha(LinkedNode *inicio){
    if(inicio == NULL) return;

    imprimeLinha(inicio->next);
    printf("%d ", inicio->data);
}

void imprimir2(LinkedNode *inicio) {
    // Impressao nao deve incluir espaco apos ultimo caractere
    // Deve ser incluido um \n ao final da impressao

    imprimeLinha(inicio->next);
    printf("%d", inicio->data);
    printf("\n");
}

int main() {

    int *qtd = 0;
    int *soma = 0;

    LinkedNode *lista = NULL;
    LinkedNode *lista2 = NULL;
    LinkedNode *lista3 = NULL;

    lista3->data = 3;
    lista3->next = NULL;

    lista2->data = 2;
    lista2->next = lista3;

    lista->data = 1;
    lista->next = lista2;

    imprimir1(lista);

    free(lista);
    free(lista2);
    free(lista3);

    return 0;
}