#include <stdio.h>
#include <stdlib.h>
//#include "mergesort_string.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   char *data; // ponteiro para um vetor de char com uma string
   LinkedNode *next;
};

void contador(int *comparador) {
    *comparador = *comparador + 1;
}

LinkedNode *inserir_final_r(LinkedNode *inicio, char *valor){

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

void liberar_lista(LinkedNode *inicio){
    LinkedNode *atual = inicio;
    LinkedNode *remover;

    while(atual != NULL){
        remover = atual;
        atual = atual->next;
        free(remover);
    }
}

LinkedNode *acha_meio(LinkedNode *inicio, LinkedNode *fim) {
    LinkedNode *atual = inicio;
    int qtd_elementos = 0, meio = 0;

    while(atual != fim && atual != NULL){
        qtd_elementos++;
        atual = atual->next;
    }

    qtd_elementos = qtd_elementos - 1;
    atual = inicio;
    meio = qtd_elementos / 2;

    for(int i = 0; i < meio; i++) {
        atual = atual->next;
    }

    return atual;
}

LinkedNode *acha_fim(LinkedNode *inicio) {
    if(inicio == NULL || inicio->next == NULL) return inicio;

    LinkedNode *atual = inicio;
    int qtd_elementos = 0;

    while(atual != NULL){
        qtd_elementos++;
        atual = atual->next;
    }
    atual = inicio;

    for(int i = 0; i < qtd_elementos-1; i++) {
        atual = atual->next;
    }

    return atual;
}

int compara_string (char* a, char* b) {
    int retorno = 0;
    char *x = a, *y = b;

    while (*x != '\0' || *y != '\0') {
        if (*x == *y) {
            x++;
            y++;
        }else if(*x > *y) {
            retorno = 1;
            break;
        }else if(*x < *y) {
            retorno = 0;
            break;
        }
    }

    return retorno;
}

LinkedNode *intercala(LinkedNode *esq_inicio, LinkedNode *esq_fim, LinkedNode *dir_fim, int *comparador) {
    LinkedNode *dir_inicio = esq_fim->next;
    LinkedNode *esq = esq_inicio, *dir = dir_inicio;

    LinkedNode *atual = esq_inicio;
    LinkedNode *lista_aux = NULL;

    while(atual != dir_fim){

        if(compara_string(esq->data, esq_fim->data)) {
            lista_aux = inserir_final_r(lista_aux, dir->data);

            dir = dir->next;
        }else if(compara_string(dir->data, dir_fim->data)) {
            lista_aux = inserir_final_r(lista_aux, esq->data);

            esq = esq->next;
        }else if(esq->data <= dir->data){
            contador(comparador);
            lista_aux = inserir_final_r(lista_aux, esq->data);

            esq = esq->next;
        }else{
            contador(comparador);
            lista_aux = inserir_final_r(lista_aux, dir->data);

            dir = dir->next;
        }

        atual = atual->next;
    }

    atual = esq_inicio;

    while(atual != dir_fim) {

        LinkedNode *substitui_lista = lista_aux;
        lista_aux = lista_aux->next;

        atual->data = substitui_lista->data;

        atual = atual->next;

        free(substitui_lista);
    }

    return esq_inicio;
}

LinkedNode *merge_sort(LinkedNode *inicio, LinkedNode *fim, int *comparador) {
    if(inicio == NULL || inicio->next == NULL || inicio == fim) return inicio;

    LinkedNode *atual = inicio;
    LinkedNode *a_fim = fim;
    LinkedNode *meio = acha_meio(atual, fim);

    merge_sort(atual, meio, comparador);
    merge_sort(meio->next, fim, comparador);

    atual = intercala(atual, meio, a_fim, comparador);

    return atual;
}

LinkedNode *mergesort(LinkedNode *inicio, int *comparacoes) {
    LinkedNode *fim = acha_fim(inicio);

    inicio = merge_sort(inicio, fim, comparacoes);
    return inicio;
}

//Listas TESTES
void imprimir(LinkedNode *inicio) {
    LinkedNode *atual = inicio;

    while (atual != NULL){
        char *data = atual->data;
        printf("%s ", data);
        atual = atual->next;
    }

    printf("\n");
}

void liberar_lista2(LinkedNode *inicio){
    LinkedNode *atual = inicio;
    LinkedNode *remover;

    while(atual != NULL){
        remover = atual;
        atual = atual->next;
        free(remover);
    }
}

int main() {
    int *comparador = malloc(sizeof(int));

    // Lista ligada ------------------------
    LinkedNode *inicio = NULL;

    char n[20] = "C", m[20] = "B", o[20] = "A", p[20] = "D", q[20] = "E";

    inicio = inserir_final_r(inicio, n);
    inicio = inserir_final_r(inicio, m);
    inicio = inserir_final_r(inicio, o);
    inicio = inserir_final_r(inicio, p);
    //inicio = inserir_final_r(inicio, q);

    imprimir(inicio);
    // Fim Lista ligada --------------------

    inicio = mergesort(inicio, comparador);
    //printf("Meio: %s\n", meio->data);
    printf("Comparacoes: %d\n", *comparador);
    imprimir(inicio);

    free(comparador);
    liberar_lista(inicio);

    return 0;
}