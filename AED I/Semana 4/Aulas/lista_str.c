#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* TIPO;

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
    TIPO data;
    LinkedNode *next;
};

void imprimir(LinkedNode *inicio) {
    LinkedNode *atual = inicio;

    while (atual != NULL){
        printf("[%s] ", atual->data);
        atual = atual->next;
    }

    printf("\n");
}

LinkedNode *inserir_final(LinkedNode *inicio, TIPO valor){
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

void liberar_lista(LinkedNode *inicio){
    if(inicio == NULL) return;

    liberar_lista(inicio->next);
    free(inicio->data); //Liberando a string também!
    free(inicio);
}

int main() {
    LinkedNode *inicio = NULL;

    //Leitura
    int n;
    scanf("%d ", &n); //Acrescentando o caracter de espaço para o programa não fazer a leitura do \n

    for(int i = 0; i < n; i++){
        char *texto = malloc(sizeof(char) * 100);
        fgets(texto, 100, stdin);
        texto[strlen(texto)-1] = 0; // desconsiderando o \n


        //Add string na lista ligada
        inicio = inserir_final(inicio, texto);
    }

    imprimir(inicio);

    liberar_lista(inicio);

    return 0;
}