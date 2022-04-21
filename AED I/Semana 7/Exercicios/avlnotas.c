#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    int nota;
    int altura;
    NoArvore *esq, *dir;
};

// Obter altura
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

void imprimirBalanceamento(NoArvore *raiz, int tipo) {
    if(tipo == 1){
        //Rotaciona direita
        printf("[x=%d y=%d z=%d]\n", raiz->chave, raiz->esq->chave, raiz->esq->esq->chave);
    }else if(tipo == 2) {
        //Rotaciona esquerda
        printf("[x=%d y=%d z=%d]\n", raiz->chave, raiz->dir->chave, raiz->dir->dir->chave);
    }
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

// Balanceamento
NoArvore *balancear(NoArvore *raiz, int *verifica) {
    int fb = calcula_fb(raiz);

    if (fb > 1) {
        *verifica = *verifica + 1;

        if(calcula_fb(raiz->esq) < 0){
            printf("[No desbalanceado: %d", raiz->esq->chave);
            printf("]\n");
            printf("[Rotacao: DE]\n");
            imprimirBalanceamento(raiz->esq, 2);
            raiz->esq = rotaciona_esquerda(raiz->esq);
        }else{
            printf("[No desbalanceado: %d", raiz->chave);
            printf("]\n");
            printf("[Rotacao: SD]\n");
            imprimirBalanceamento(raiz, 1);
        }

        raiz = rotaciona_direita(raiz);
    }

    if (fb < -1) {
        *verifica = *verifica + 1;

        if(calcula_fb(raiz->dir) > 0){
            printf("[No desbalanceado: %d", raiz->esq->chave);
            printf("]\n");
            printf("[Rotacao: DD]\n");
            imprimirBalanceamento(raiz->dir, 1);
            raiz->dir = rotaciona_direita(raiz->dir);
        }else{
            printf("[No desbalanceado: %d", raiz->chave);
            printf("]\n");
            printf("[Rotacao: SE]\n");
            imprimirBalanceamento(raiz, 2);
        }

        raiz = rotaciona_esquerda(raiz);
    }

    return raiz;
}

// Inserção
NoArvore *inserir(NoArvore *raiz, int chave_nova, int nota_nova, int *verifica) {
    int *ver = verifica;

    if(raiz == NULL) {
        NoArvore *novo_no = malloc(sizeof(NoArvore));
        novo_no->chave = chave_nova;
        novo_no->nota = nota_nova;
        novo_no->altura = 0;
        novo_no->esq  = NULL;
        novo_no->dir = NULL;
        return novo_no;
    }

    if(chave_nova < raiz->chave){
        raiz->esq = inserir(raiz->esq, chave_nova, nota_nova, ver);
    }else if(chave_nova > raiz->chave){
        raiz->dir = inserir(raiz->dir, chave_nova, nota_nova, ver);
    }

    raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));

    return balancear(raiz, ver);
}

int get_min(NoArvore *raiz) {
    if (raiz->esq == NULL){
        return raiz->chave;
    }else{
        return get_min(raiz->esq);
    }
}

// Remoção
NoArvore *remover(NoArvore *raiz, int chave) {
    //Verificar se a arvore é vazia
    if (raiz == NULL) return NULL;

    if (chave < raiz->chave){
        raiz->esq = remover(raiz->esq, chave);
    }else if (chave > raiz->chave) {
        raiz->dir = remover(raiz->dir, chave);
    }else{
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

        int sucessor = get_min(raiz->dir);
        raiz->chave = sucessor;
        raiz->dir = remover(raiz->dir, sucessor);
    }

    raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));

    //return balancear(raiz);
    return raiz; // Só pra rodar o balancear

}


// Busca
NoArvore *buscar(NoArvore *raiz, int chave, int *cont) {
    *cont = *cont + 1;

    if(raiz == NULL) return NULL;
    if(raiz->chave == chave) return raiz;

    if(chave < raiz->chave){
        return buscar(raiz->esq, chave, cont);
    }else{
        return buscar(raiz->dir, chave, cont);
    }
}

// Imprimir
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

    char indice;
    int ra, nota, cont = 0, verifica = 0;

    scanf("%c", &indice);
    scanf("%d %d", &ra, &nota);

    tree = inserir(tree, ra, nota, &verifica);
    if(verifica == 0){
        printf("[Ja esta balanceado]\n");
    }
    verifica = 0;

    while(indice != 'P'){
        scanf("%c", &indice);

        if(indice == 'I'){
            scanf("%d %d", &ra, &nota);
            tree = inserir(tree, ra, nota, &verifica);

            if(verifica == 0){
                printf("[Ja esta balanceado]\n");
            }

            verifica = 0;
        }else if(indice == 'B'){
            scanf("%d", &ra);
            NoArvore *no = buscar(tree, ra, &cont);

            if(no == NULL){
                printf("C=%d Nota=-1\n", cont);
            }else{
                printf("C=%d Nota=%d\n", cont, no->nota);
            }
            cont = 0;

        }else if(indice == 'A') {
            printf("A=%d\n", altura(tree));
        }else if(indice == 'P') {
            printf("[");
            percurso_posordem(tree);
            printf("]\n");
        }
    }

    liberar_arvore(tree);

    return 0;
}