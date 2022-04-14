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

int get_min(NoArvore *raiz) {
    //Não verificamos se o ponteiro da raiz é nulo ou não (mas ta certo nesse cenário)
    if (raiz->esq == NULL){
        return raiz->chave;
    }else{
        return get_min(raiz->esq);
    }
}

NoArvore *remover(NoArvore *raiz, int chave) {
    //Verificar se a arvore é vazia
    if (raiz == NULL) return NULL;

    if (chave < raiz->chave){
        raiz->esq = remover(raiz->esq, chave);
    }else if (chave > raiz->chave) {
        raiz->dir = remover(raiz->dir, chave);
    }else{
        //Caso 1: nó folha
        /*
        if(raiz->esq == NULL && raiz->dir == NULL){
            free(raiz);
            return NULL;
        }
        */

        //<<<< O trecho de código abaixo trata dos casos 1 e 2 >>>>
        //Caso 2: 1 subárvore não nula
        if(raiz->esq == NULL){
            NoArvore *arvDir = raiz->dir;
            free(raiz);
            return arvDir;
        }
        if(raiz->dir == NULL){
            NoArvore *arvEsq = raiz->esq;
            free(raiz);
            return arvEsq;
        }

        //Caso 3: 2 subárvores não nulas
        int sucessor = get_min(raiz->dir); //função get_min percorre a arvore e retorna o menor valor
        raiz->chave = sucessor;
        raiz->dir = remover(raiz->dir, sucessor); //sucessor = menor valor da subarvore a direita
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

void percurso_emordem(NoArvore *raiz) {
    // Caso base: raiz nula
    if (raiz == NULL) return;

    percurso_emordem(raiz->esq);
    printf("%d ", raiz->chave);
    percurso_emordem(raiz->dir);
}

void percurso_preordem(NoArvore *raiz) {
    // Caso base: raiz nula
    if (raiz == NULL) return;

    // Primeiro visita o nó pra depois fazer o percurso
    printf("%d ", raiz->chave);
    percurso_preordem(raiz->esq);
    percurso_preordem(raiz->dir);
}

void percurso_posordem(NoArvore *raiz) {
    // Caso base: raiz nula
    if (raiz == NULL) return;

    // Primeiro faz o percurso pra depois visitar o nó
    percurso_posordem(raiz->esq);
    percurso_posordem(raiz->dir);
    printf("%d ", raiz->chave);
}

int main() {

    //Arvore
    NoArvore *tree = NULL;

    tree = inserir(tree, 50);
    tree = inserir(tree, 10);
    tree = inserir(tree, 80);
    tree = inserir(tree, 70);
    tree = inserir(tree, 90);
    tree = inserir(tree, 85);

    imprimir(tree, 0);
    printf("\n----------------------------\n");

    percurso_emordem(tree);
    printf("\n");

    percurso_preordem(tree);
    printf("\n");

    percurso_posordem(tree);
    printf("\n");

    /*
    tree = remover(tree, 10);
    tree = remover(tree, 50);

    imprimir(tree, 0);
    printf("\n");
    */

    return 0;
}