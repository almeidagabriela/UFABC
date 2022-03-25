#include <stdlib.h>
#include <stdio.h>
//#include "editar_dna.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   char data;
   LinkedNode *next;
};

void remover(LinkedNode *inicio, int qtd){
    LinkedNode *atual = inicio;
    LinkedNode *remover;

    for(int i = 0; i < qtd; i++){
        remover = atual;
        atual = atual->next;
        free(remover);
    }
}

LinkedNode *editar_dna(LinkedNode *dna_original, LinkedNode *seq_edicao) {
    LinkedNode *atual = dna_original;
    LinkedNode *anterior = NULL;
    LinkedNode *edicao = seq_edicao;

    int cont = 0;
    int qtdEdicao = 0;

    while(edicao != NULL){
        switch (edicao->data){
            case 'A':
                edicao->data = 'T';
                break;
            case 'C':
                edicao->data = 'G';
                break;
            case 'T':
                edicao->data = 'A';
                break;
            case 'G':
                edicao->data = 'C';
                break;
        }

        qtdEdicao++;
        edicao = edicao->next;
    }

    if(edicao != seq_edicao){
        edicao = seq_edicao;
    }

    while(atual->next != NULL){
        if(atual->next->data == edicao->data){
            cont++;

            if(edicao->next != NULL){
                edicao = edicao->next;
            }

            if(cont == 1){
                anterior = atual;
            }
        }else{
            if(edicao != seq_edicao){
                edicao = seq_edicao;
            }
            cont = 0;
        }

        if(cont == qtdEdicao){
            remover(anterior->next, qtdEdicao);

            LinkedNode *temp = atual->next->next;

            //cont = 0;
            //while(cont < qtdEdicao){
                //LinkedNode *excluindo =  anterior->next;
                //anterior->next = excluindo->next;

                //free(excluindo);

               // cont++;
            //}

            //anterior->next = temp;
            atual = temp;

            //dna_original = temp;
        }

        atual = atual->next;
    }

    return dna_original;
}

void imprimir(LinkedNode *inicio) {
    LinkedNode *atual = inicio;


    while (atual != NULL){
        printf("%s ", &atual->data);
        atual = atual->next;
    }

    printf("\n");
}

int main() {
    LinkedNode *dna1 = malloc(sizeof(LinkedNode));
    LinkedNode *dna2 = malloc(sizeof(LinkedNode));
    LinkedNode *dna3 = malloc(sizeof(LinkedNode));
    LinkedNode *dna4 = malloc(sizeof(LinkedNode));
    LinkedNode *dna5 = malloc(sizeof(LinkedNode));
    LinkedNode *dna6 = malloc(sizeof(LinkedNode));
    LinkedNode *dna7 = malloc(sizeof(LinkedNode));
    LinkedNode *dna8 = malloc(sizeof(LinkedNode));
    LinkedNode *dna9 = malloc(sizeof(LinkedNode));
    LinkedNode *dna10 = malloc(sizeof(LinkedNode));
    LinkedNode *dna11 = malloc(sizeof(LinkedNode));
    LinkedNode *dna12 = malloc(sizeof(LinkedNode));
    LinkedNode *dna13 = malloc(sizeof(LinkedNode));
    LinkedNode *dna14 = malloc(sizeof(LinkedNode));

    dna14->data = 'A';
    dna14->next = NULL;

    dna13->data = 'T';
    dna13->next = dna14;

    dna12->data = 'C';
    dna12->next = dna13;

    dna11->data = 'T';
    dna11->next = dna12;

    dna10->data = 'T';
    dna10->next = dna11;

    dna9->data = 'G';
    dna9->next = dna10;

    dna8->data = 'C';
    dna8->next = dna9;

    dna7->data = 'G';
    dna7->next = dna8;

    dna6->data = 'C';
    dna6->next = dna7;

    dna5->data = 'A';
    dna5->next = dna6;

    dna4->data = 'T';
    dna4->next = dna5;

    dna3->data = 'G';
    dna3->next = dna4;

    dna2->data = 'C';
    dna2->next = dna3;

    dna1->data = 'A';
    dna1->next = dna2;

    imprimir(dna1);

    LinkedNode *edicao1 = malloc(sizeof(LinkedNode));
    LinkedNode *edicao2 = malloc(sizeof(LinkedNode));
    LinkedNode *edicao3 = malloc(sizeof(LinkedNode));

    edicao3->data = 'A';
    edicao3->next = NULL;

    edicao2->data = 'C';
    edicao2->next = edicao3;

    edicao1->data = 'G';
    edicao1->next = edicao2;

    LinkedNode *inicio = NULL;

    inicio = editar_dna(dna1, edicao1);

    imprimir(inicio);

    free(dna1);
    free(dna2);
    free(dna3);
    free(dna4);
    free(dna5);
    free(dna6);
    free(dna7);
    free(dna8);
    free(dna9);
    free(dna10);
    free(dna11);
    free(dna12);
    free(dna13);
    free(dna14);

    free(edicao1);
    free(edicao2);
    free(edicao3);

    return 0;
}