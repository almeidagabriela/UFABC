#include <stdio.h>
#include <stdlib.h>

typedef struct PilhaEstatica PilhaEstatica;
struct PilhaEstatica {
    int *itens;
    int tamanho, topo;
};

PilhaEstatica *criar_pilha(int tamanho) {
    PilhaEstatica *pilha = malloc(sizeof(PilhaEstatica));

    pilha->itens = malloc(sizeof(int) * tamanho);
    pilha->tamanho = tamanho;
    pilha->topo = -1;

    return pilha;
}

int push(PilhaEstatica *pilha, int item) {
    // Verifica se a pilha está cheia
    if(pilha->topo == pilha->tamanho - 1) return 0;

    pilha->itens[++pilha->topo] = item; // ++ antes da variavel: primeiro incrementa, depois utiliza o valor incrementado
    // Mesma coisa que:
    /*
    pilha->itens[pilha->topo + 1] = item;
    pilha->topo++;
    */
    return 1;
}

int pop(PilhaEstatica *pilha, int *item) {
    // Verifica se a pilha está vazia
    if(pilha->topo == -1) return 0;

    //Elemento por referencia
    *item = pilha->itens[pilha->topo--];
    //Mesma coisa que:
    /*
    *item = pilha->itens[pilha->topo];
    pilha->topo--;
    */
    return 1;
}

//Liberar memoria: 1º Libera o vetor de itens 2º A estrutura da pilha
//Verifique vazamento de memória com o comando: valgrind ./pilha1.exe
void liberar_pilha(PilhaEstatica *pilha){
    free(pilha->itens);
    free(pilha);
}

int main() {
    PilhaEstatica *p = criar_pilha(4);
    int r, item;

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
    for(int i = 0; i < 5; i++){
        item = -1; // evitando erros com listas vazias;
        r = pop(p, &item);
        printf("D %d : %d\n", item, r);
    }

    liberar_pilha(p);

    return 0;
}