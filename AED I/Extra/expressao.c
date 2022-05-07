#include <stdlib.h>
#include <stdio.h>
//#include "expressao.h"
//#include "pilha.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
    double data;
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

int push(PilhaDinamica *pilha, double item){
    //Topo = inicio
    LinkedNode *novo_item = malloc(sizeof(LinkedNode));

    if(novo_item == NULL) return 0;

    novo_item->data = item;
    novo_item->next = pilha->topo;

    pilha->topo = novo_item;

    return 1;
}

int pop(PilhaDinamica *pilha, double *item){
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

int calcular_posfixa(char *expressao, double *resultado) {
    PilhaDinamica *p = criar_pilha();

    int tamanho = 0, verifica = 0, valida = 1;
    double item1 = 0, item2 = 0, item3 = 0;

    int j = 0;
    while(expressao[j] != '\0'){
        tamanho++;
        j++;
    }

    for(int i = 0; i < tamanho && valida != 0; i++) {
        if(expressao[i] >= 48 && expressao[i] <= 57) {
            verifica++;
            push(p, expressao[i]-48);
        }

        switch(expressao[i]) {
            case 'h':
                if(verifica >= 1){
                    pop(p, &item1);

                    *resultado = (item1) * 3;

                    push(p, *resultado);

                    valida = 1;
                }else{
                    valida = 0;
                }

                break;
            case '+':
                if(verifica >= 2){
                    pop(p, &item1);
                    pop(p, &item2);

                    *resultado = (item2) + (item1);

                    push(p, *resultado);

                    valida = 1;
                    verifica--;
                }else{
                    valida = 0;
                }
                break;
            case '-':
                if(verifica >= 2){
                    pop(p, &item1);
                    pop(p, &item2);

                    *resultado = (item2) - (item1);

                    push(p, *resultado);

                    verifica--;
                    valida = 1;
                }else{
                    valida = 0;
                }

                break;
            case 'f':
                if(verifica >= 3){
                    pop(p, &item1);
                    pop(p, &item2);
                    pop(p, &item3);

                    *resultado = (item3*item3) - (item2/2) + item1;

                    push(p, *resultado);

                    verifica -= 2;
                    valida = 1;
                }else{
                    valida = 0;
                }

                break;
            case 'g':
                if(verifica >= 3){
                    pop(p, &item1);
                    pop(p, &item2);
                    pop(p, &item3);

                    *resultado = (item3 * item2) + item1;

                    push(p, *resultado);

                    verifica -= 2;
                    valida = 1;
                }else{
                    valida = 0;
                }

                break;
        }
    }

    liberar_pilha(p);

    if(verifica != 1) {
        valida = 0;
    }

    return valida;
}

int main() {
    PilhaDinamica *p = criar_pilha();

    char expressao[100];
    double resultado = 0, item1 = 0, item2 = 0, item3 = 0;
    int tamanho = 0, verifica = 0, valida = 1;

    scanf("%s", expressao);

    int j = 0;
    while(expressao[j] != '\0'){
        tamanho++;
        j++;
    }

    for(int i = 0; i < tamanho && valida != 0; i++) {
        if(expressao[i] >= 48 && expressao[i] <= 57) {
            verifica++;
            push(p, expressao[i]-48);
        }

        switch(expressao[i]) {
            case 'h':
                if(verifica >= 1){
                    pop(p, &item1);

                    resultado = (item1) * 3;

                    push(p, resultado);

                    valida = 1;
                    //verifica = 1;
                }else{
                    valida = 0;
                }

                break;
            case '+':
                if(verifica >= 2){
                    pop(p, &item1);
                    pop(p, &item2);

                    resultado = (item2) + (item1);

                    push(p, resultado);

                    valida = 1;
                    verifica--;
                }else{
                    valida = 0;
                }
                break;
            case '-':
                if(verifica >= 2){
                    pop(p, &item1);
                    pop(p, &item2);

                    resultado = (item2) - (item1);

                    push(p, resultado);

                    verifica--;
                    valida = 1;
                }else{
                    valida = 0;
                }

                break;
            case 'f':
                if(verifica >= 3){
                    pop(p, &item1);
                    pop(p, &item2);
                    pop(p, &item3);

                    resultado = (item3*item3) - (item2/2) + item1;

                    push(p, resultado);

                    verifica -= 2;
                    valida = 1;
                }else{
                    valida = 0;
                }

                break;
            case 'g':
                if(verifica >= 3){
                    pop(p, &item1);
                    pop(p, &item2);
                    pop(p, &item3);

                    resultado = (item3 * item2) + item1;

                    push(p, resultado);

                    verifica -= 2;
                    valida = 1;
                }else{
                    valida = 0;
                }

                break;
        }
    }

    printf("Verifica: %d\n", verifica);
    printf("Valida: %d\n", valida);
    printf("Resultado: %lf\n", resultado);

    liberar_pilha(p);

    return 0;
}