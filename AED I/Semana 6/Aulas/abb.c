#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    NoArvore *esq, *dir;
};

NoArvore *inserir(NoArvore *raiz, int chave_nova) {
    //Caso base: Raiz vazia
    if(raiz == NULL) {
        NoArvore *novo_no = malloc(sizeof(NoArvore));
        novo_no->chave = chave_nova;
        novo_no->esq  = NULL;
        novo_no->dir = NULL;
        return novo_no;
    }

    if(chave_nova < raiz->chave){
        raiz->esq = inserir(raiz->esq, chave_nova);
    }else if(chave_nova > raiz->chave){
        raiz->dir = inserir(raiz->dir, chave_nova);
    }

    return raiz;
}

void imprimir(NoArvore* raiz, int profundidade) {
    if (raiz == NULL) return;

    imprimir(raiz->dir, profundidade + 1);

    printf("\n");

    for(int i = 0; i < profundidade; i++) printf("    ");
    printf("%d", raiz->chave);

    imprimir(raiz->esq, profundidade + 1);
}

int main() {

    //Arvore
    NoArvore *tree = NULL;

    tree = inserir(tree, 50);
    tree = inserir(tree, 10);
    tree = inserir(tree, 80);
    tree = inserir(tree, 70);
    tree = inserir(tree, 90);

    imprimir(tree, 0);
    printf("\n");

    return 0;
}