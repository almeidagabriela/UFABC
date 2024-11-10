#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

typedef struct {
    int dados[TAMANHO];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void inicializar_fila(Fila *f);
int fila_vazia(Fila *f);
int fila_cheia(Fila *f);
void enfileirar(Fila *f, int valor);
int desenfileirar(Fila *f);
void mostrar_pilha(Fila *f);
void remover_pares(Fila *f1, Fila *f2);

int main() {
    Fila F1, F2;
    int opcao = 0, valor;
    inicializar_fila(&F1);
    inicializar_fila(&F2);

    while (opcao != 5) {
        printf("\nMenu:\n");
        printf("1) Inserir elemento na fila F1\n");
        printf("2) Apresentar fila F1 original\n");
        printf("3) Apresentar fila F1 apos a remocao dos numeros pares\n");
        printf("4) Apresentar a fila F2 com os numeros pares\n");
        printf("5) Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (!fila_cheia(&F1)) {
                    while(!fila_cheia(&F1)){
                        printf("Digite um elemento inteiro: ");
                        scanf("%d", &valor);
                        enfileirar(&F1, valor);
                    }
                } else {
                    printf("A fila F1 esta cheia.\n");
                }
                break;
            case 2:
                printf("Fila F1 original: ");
                mostrar_pilha(&F1);
                break;
            case 3:
                remover_pares(&F1, &F2);
                printf("Fila F1 apos remocao dos numeros pares: ");
                mostrar_pilha(&F1);
                break;
            case 4:
                printf("Fila F2 com numeros pares: ");
                mostrar_pilha(&F2);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Escolha uma opcao disponivel no menu!\n");
                break;
        }
    }

    return 0;
}

void inicializar_fila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

int fila_vazia(Fila *f) {
    return f->tamanho == 0;
}

int fila_cheia(Fila *f) {
    return f->tamanho == TAMANHO;
}

void enfileirar(Fila *f, int valor) {
    if (!fila_cheia(f)) {
        f->fim = (f->fim + 1) % TAMANHO;
        f->dados[f->fim] = valor;
        f->tamanho++;
    }
}

int desenfileirar(Fila *f) {
    if (!fila_vazia(f)) {
        int valor = f->dados[f->inicio];
        f->inicio = (f->inicio + 1) % TAMANHO;
        f->tamanho--;
        return valor;
    }
    return -1;
}

void mostrar_pilha(Fila *f) {
    if (fila_vazia(f)) {
        printf("Fila vazia.\n");
    } else {
        int i = f->inicio;
        int count = f->tamanho;
        while (count > 0) {
            printf("%d ", f->dados[i]);
            i = (i + 1) % TAMANHO;
            count--;
        }
        printf("\n");
    }
}

void remover_pares(Fila *f1, Fila *f2) {
    int count = f1->tamanho;

    for (int i = 0; i < count; i++) {
        int valor = desenfileirar(f1);

        if (valor % 2 == 0) {
            enfileirar(f2, valor);  // par > F2
        } else {
            enfileirar(f1, valor);  // impar > F1
        }
    }
}