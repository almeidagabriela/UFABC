#include <stdio.h>
#include <stdlib.h>
//#include "pilha.h"
//#include "fila.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
    char data;
    LinkedNode *next;
};

typedef struct PilhaDinamica PilhaDinamica;
struct PilhaDinamica {
    LinkedNode *topo;
};

typedef struct FilaDinamica FilaDinamica;
struct FilaDinamica {
    LinkedNode *inicio, *fim;
};

PilhaDinamica *criar_pilha() {
    PilhaDinamica *pilha = malloc(sizeof(PilhaDinamica));
    pilha->topo = NULL;
    return pilha;
}

int push(PilhaDinamica *pilha, int item){
    //Topo = inicio
    LinkedNode *novo_item = malloc(sizeof(LinkedNode));

    if(novo_item == NULL) return 0;

    novo_item->data = item;
    novo_item->next = pilha->topo;

    pilha->topo = novo_item;

    return 1;
}

int pop(PilhaDinamica *pilha, char *item){
    //Verifica se está vazia
    if(pilha->topo == NULL) return 0;

    LinkedNode *no = pilha->topo;
    pilha->topo = pilha->topo->next;

    *item = no->data;
    free(no);

    return 1;
}

void liberar_lista(LinkedNode *no){
    if(no == NULL) return;
    liberar_lista(no->next);
    free(no);
}

void liberar_pilha(PilhaDinamica *pilha){
    liberar_lista(pilha->topo);
    free(pilha);
}

FilaDinamica *criar_fila() {
    FilaDinamica *fila = malloc(sizeof(FilaDinamica));

    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

int enqueue(FilaDinamica *fila, int item) {
    //Inserção no final da fila | Remoção no inicio da fila
    LinkedNode *novo_item = malloc(sizeof(LinkedNode));

    //Se problema na alocação
    if(novo_item == NULL) return 0;

    novo_item->data = item;
    novo_item->next = NULL;

    //Se a fila não for vazia:
    if(fila->fim != NULL)
        fila->fim->next = novo_item;

    fila->fim = novo_item;

    //Caso o novo item for o primeiro elemento
    if(fila->inicio == NULL)
        fila->inicio = novo_item;

    return 1;
}

int dequeue(FilaDinamica *fila, char *item) {
    //Verificar se a fila está vazia
    if(fila->inicio == NULL) return 0;

    LinkedNode *no = fila->inicio;
    *item = no->data;

    //Atualizar inicio
    fila->inicio = fila->inicio->next;

    //Tratamento para remover o ultimo elemento da lista
    if(fila->inicio == NULL)
        fila->fim = NULL;

    free(no);

    return 1;
}

void liberar_listaF(LinkedNode *no) {
    if (no == NULL) return;

    liberar_listaF(no->next);
    free(no);
}

void liberar_fila(FilaDinamica *fila) {
    liberar_listaF(fila->inicio);
    free(fila);
}

int main() {
    PilhaDinamica *p = criar_pilha();

    int cont = 0, verifica = 0, i = 0;
    char texto[200];

    scanf("%s", texto);

    while(texto[i] != '\0'){
        if(texto[i] == '(' || texto[i] == '[' || texto[i] == '{'){
            verifica = 0;
            push(p, texto[i]);
        }else if(texto[i] == ')' || texto[i] == ']' || texto[i] == '}'){
            char item = 'a';
            verifica = 0;

            if(p->topo != NULL){
                pop(p, &item);
            }

            switch(item){
                case '(':
                    if(texto[i] == ')'){
                        verifica = 1;
                    }else{
                        verifica = 0;
                    }
                    break;
                case '[':
                    if(texto[i] == ']'){
                        verifica = 1;
                    }else{
                        verifica = 0;
                    }
                    break;
                case '{':
                    if(texto[i] == '}'){
                        verifica = 1;
                    }else{
                        verifica = 0;
                    }
                    break;
            }

            if(verifica == 0){
                texto[i] = '\0';
            }
        }
        i++;
    }

    if(p->topo != NULL){
        verifica = 0;
    }

    liberar_pilha(p);

    if(verifica == 0){
        printf("NAO");
    }else{
        printf("SIM");
    }

    return 0;
}