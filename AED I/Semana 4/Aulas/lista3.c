#include <stdio.h>
#include <stdlib.h>

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
    int data;
    DLinkedNode *prev, *next;
};

typedef struct ListaLigada ListaLigada;
struct ListaLigada {
    DLinkedNode *inicio, *fim;
};


void inserir_final(ListaLigada *lista, int valor) {
    DLinkedNode *novo = malloc(sizeof(DLinkedNode));

    if(novo == NULL) return;

    novo->data = valor;
    novo->prev = NULL;
    novo->next = NULL;

    //Verificar se a lista tem algum elemento
    if(lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        novo->prev = lista->fim;
        lista->fim->next = novo;
        lista->fim = novo;
    }

}

void remover(ListaLigada *lista, int valor) {
    //Percorrer a lista ligada em busca do elemento a ser removido
    DLinkedNode *atual = lista->inicio;

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
            lista->inicio = proximo;
        }

        if(proximo != NULL){
            proximo->prev = anterior;
        }else{
            lista->fim = anterior;
        }

        free(atual);
    }
}

void imprimir(ListaLigada *lista) {
    DLinkedNode *atual;

    //Do inicio ao fim
    for(atual = lista->inicio; atual != NULL; atual = atual->next){
        printf("%d ", atual->data);
    }

    printf("\n");

    //Do fim ao inicio
    for(atual = lista->fim; atual != NULL; atual = atual->prev){
        printf("%d ", atual->data);
    }

    printf("\n");
}

void liberar_lista(DLinkedNode *inicio) {
    if (inicio == NULL) return;

    liberar_lista(inicio->next);
    free(inicio);
}

ListaLigada *criar_lista() {
    ListaLigada *lista = malloc(sizeof(ListaLigada));
    lista->inicio = NULL;

    return lista;
}

int main() {
    ListaLigada *lista = criar_lista();

    inserir_final(lista, 10);
    inserir_final(lista, 20);
    inserir_final(lista, 30);
    inserir_final(lista, 40);
    imprimir(lista);

    remover(lista, 10);
    imprimir(lista);

    remover(lista, 30);
    imprimir(lista);

    remover(lista, 40);
    imprimir(lista);

    remover(lista, 20);
    imprimir(lista);

    inserir_final(lista, 50);
    inserir_final(lista, 60);
    imprimir(lista);

    liberar_lista(lista->inicio);
    free(lista);

    return 0;
}