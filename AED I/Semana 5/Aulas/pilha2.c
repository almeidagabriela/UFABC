#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
    int data;
    LinkedNode *next;
};

typedef struct PilhaDinamica PilhaDinamica;
struct PilhaDinamica {
    LinkedNode *topo;
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

int pop(PilhaDinamica *pilha, int *item){
    //Verifica se está vazia
    if(pilha->topo == NULL) return 0;

    LinkedNode *no = pilha->topo;
    pilha->topo = pilha->topo->next;

    *item = no->data;
    free(no);

    return 1;
}

// Libera 1º Lista ligada 2º Estrutura da pilha
//Verifique vazamento de memória com o comando: valgrind ./pilha2.exe
void liberar_lista(LinkedNode *no){
    if(no == NULL) return;
    liberar_lista(no->next);
    free(no);
}

void liberar_pilha(PilhaDinamica *pilha){
    liberar_lista(pilha->topo);
    free(pilha);
}

int main(){
    PilhaDinamica *p = criar_pilha(); //Instancia a pilha (alocar na memoria)
    int r, item; // r é o retorno da função, indica se deu certo ou não

    //Empilhar
    item = 10;
    r = push(p, item);
    printf("E %d : %d\n", item, r);

    item = 20;
    r = push(p, item);
    printf("E %d : %d\n", item, r);

    item = 30;
    r = push(p, item);
    printf("E %d : %d\n", item, r);

    item = 40;
    r = push(p, item);
    printf("E %d : %d\n", item, r);

    item = 50;
    r = push(p, item);
    printf("E %d : %d\n", item, r);

    //Desempilhar
    for(int i = 0; i < 2; i++){
        item = -1; // evitando erros com listas vazias;
        r = pop(p, &item);
        printf("D %d : %d\n", item, r);
    }

    liberar_pilha(p);

    return 0;
}