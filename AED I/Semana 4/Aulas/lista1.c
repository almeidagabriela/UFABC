#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
    int data;
    LinkedNode *next;
};

void imprimir(LinkedNode *inicio) {
    LinkedNode *atual = inicio;

    while (atual != NULL){
        printf("%d ", atual->data); // ou = printf("%d ", (*atual).data);
        atual = atual->next;
    }

    printf("\n");
}

void imprimir2(LinkedNode *inicio) {
    LinkedNode *atual;

    for(atual = inicio; atual != NULL; atual = atual->next){
        printf("%d ", atual->data);
    }

    printf("\n");
}

LinkedNode *inserir_final(LinkedNode *inicio, int valor){
    LinkedNode *novo = malloc(sizeof(LinkedNode));

    //Verificar se o novo foi alocado com sucesso
    if(novo == NULL) return inicio;

    novo->data = valor;
    novo->next = NULL;

    //Verificar se a lista é vazia
    if(inicio == NULL) return novo;

    //Percorrer lista
    LinkedNode *anterior = NULL;
    LinkedNode *atual = inicio;

    //Quando o atual for NULO quer dizer que chegamos ao fim da lista
    while(atual != NULL){
        anterior = atual;
        atual = atual->next;
    }
    anterior->next = novo;

    return inicio;
}

LinkedNode *inserir_final_r(LinkedNode *inicio, int valor){
    //CASO BASE
    // Se a lista ligada estiver vazia
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

LinkedNode *remover(LinkedNode *inicio, int valor){
    
}

LinkedNode *remover_r(LinkedNode *inicio, int valor){
    if(inicio == NULL) return NULL;

    //inicio sendo o elemento que queremos remover
    if(inicio->data == valor){
        LinkedNode *temp = inicio->next;
        free(inicio);
        return temp;
    }

    //Percorrer lista
    inicio->next = remover_r(inicio->next, valor);
    return inicio;
}

void liberar_lista(LinkedNode *inicio){
    if(inicio == NULL) return;

    liberar_lista(inicio->next);
    free(inicio);
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
    LinkedNode *inicio = NULL;

    int n;
    scanf("%d", &n); //Leitura

    while(n != -1){
        inicio = inserir_final_r(inicio, n);
        scanf("%d", &n);
    }

    imprimir(inicio);

    liberar_lista2(inicio);

    return 0;
}