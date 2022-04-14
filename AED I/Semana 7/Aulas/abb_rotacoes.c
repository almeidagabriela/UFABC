#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    int altura;
    NoArvore *esq, *dir;
};

int altura(NoArvore *raiz) {
    if (raiz == NULL){
        return -1;
    }else{
        return raiz->altura;
    }
}

int calcula_fb(NoArvore *raiz) {
    return (altura(raiz->esq) - altura(raiz->dir));
}

int maior(int v1, int v2) {
    return (v1 > v2 ? v1 : v2);
}

NoArvore *rotaciona_direita(NoArvore *raiz) {
    //1º Armazenar ponteiro à esquerda da raiz
    NoArvore *filho_esq = raiz->esq;
    NoArvore *filho_esq_dir = filho_esq->dir;

    //2º Realizar a troca
    raiz->esq = filho_esq_dir;
    filho_esq->dir = raiz;

    //3º Atualizar alturas
    raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));
    filho_esq->altura = 1 + maior(altura(filho_esq->esq), altura(filho_esq->dir));

    return filho_esq;
}

NoArvore *rotaciona_esquerda(NoArvore *raiz) {
    //1º Armazenar ponteiro à direita da raiz
    NoArvore *filho_dir = raiz->dir;
    NoArvore *filho_dir_esq = filho_dir->esq;

    //2º Realizar a troca
    raiz->dir = filho_dir_esq;
    filho_dir->esq = raiz;

    //3º Atualizar alturas
    raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));
    filho_dir->altura = 1 + maior(altura(filho_dir->esq), altura(filho_dir->dir));

    return filho_dir;
}

NoArvore *inserir(NoArvore *raiz, int chave_nova) {
    //Caso base: Raiz vazia
    if(raiz == NULL) {
        NoArvore *novo_no = malloc(sizeof(NoArvore));
        novo_no->chave = chave_nova;
        novo_no->altura = 0;
        novo_no->esq  = NULL;
        novo_no->dir = NULL;
        return novo_no;
    }

    if(chave_nova < raiz->chave){
        raiz->esq = inserir(raiz->esq, chave_nova);
    }else if(chave_nova > raiz->chave){
        raiz->dir = inserir(raiz->dir, chave_nova);
    }

    raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir)); // maior valor que existir entre as alturas das subarvores esq e dir

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

    raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));

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

void liberar_arvore(NoArvore *raiz) {
    // Caso base: raiz nula
    if (raiz == NULL) return;

    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);
    free(raiz);
}

NoArvore *buscar(NoArvore *raiz, int chave) {
    if(raiz == NULL) return NULL;
    if(raiz->chave == chave) return raiz;

    if(chave < raiz->chave){
        return buscar(raiz->esq, chave);
    }else{
        return buscar(raiz->dir, chave);
    }
}

int main() {

    //Arvore
    NoArvore *tree = NULL;

    tree = inserir(tree, 10);
    tree = inserir(tree, 20);
    tree = inserir(tree, 30);
    tree = inserir(tree, 15);
    tree = inserir(tree, 5);
    /*
    tree = inserir(tree, 60);
    tree = inserir(tree, 25);
    tree = inserir(tree, 5);
    */

    imprimir(tree, 0);
    printf("\n----------------------------\n");

    //tree = rotaciona_direita(tree);
    tree = rotaciona_esquerda(tree);
    imprimir(tree, 0);
    printf("\n");

    liberar_arvore(tree);

    return 0;
}