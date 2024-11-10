#include <stdio.h>

#define TAMANHO 8

typedef struct {
    int dados[TAMANHO];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *p);
int pilha_vazia(Pilha *p);
int pilha_cheia(Pilha *p);
void empilhar(Pilha *p, int valor);
int desempilhar(Pilha *p);
void mostrar_pilha(Pilha *p);
void remover_pares(Pilha *p1, Pilha *p2);

int main() {
    Pilha P1, P2;
    int opcao = 0, valor;
    inicializar_pilha(&P1);
    inicializar_pilha(&P2);

    while (opcao != 5) {
        printf("\nMenu:\n");
        printf("1) Inserir elemento na pilha\n");
        printf("2) Apresentar pilha original\n");
        printf("3) Apresentar pilha apos a remocao dos numeros pares\n");
        printf("4) Apresentar a pilha de numeros pares\n");
        printf("5) Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (!pilha_cheia(&P1)) {
                    // Enquanto a pilha não estiver completa
                    while(!pilha_cheia(&P1)){
                        printf("Digite um elemento inteiro: ");
                        scanf("%d", &valor);
                        empilhar(&P1, valor);
                    }
                } else {
                    printf("A pilha esta cheia.\n");
                }
                break;
            case 2:
                printf("Pilha P1 original: ");
                mostrar_pilha(&P1);
                break;
            case 3:
                remover_pares(&P1, &P2);
                printf("Pilha P1 apos remocao dos numeros pares: ");
                mostrar_pilha(&P1);
                break;
            case 4:
                printf("Pilha P2 de numeros pares: ");
                mostrar_pilha(&P2);
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

void inicializar_pilha(Pilha *p) {
    p->topo = -1;
}

int pilha_vazia(Pilha *p) {
    return p->topo == -1;
}

int pilha_cheia(Pilha *p) {
    return p->topo == TAMANHO - 1;
}

void empilhar(Pilha *p, int valor) {
    if (!pilha_cheia(p)) {
        p->dados[++(p->topo)] = valor;
    }
}

int desempilhar(Pilha *p) {
    if (!pilha_vazia(p)) {
        return p->dados[(p->topo)--];
    }
    return -1;
}

void mostrar_pilha(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia.\n");
    } else {
        for (int i = 0; i <= p->topo; i++) {
            printf("%d ", p->dados[i]);
        }
        printf("\n");
    }
}

void remover_pares(Pilha *p1, Pilha *p2) {
    Pilha temp;
    inicializar_pilha(&temp);

    // Remove os elementos da pilha inicial
    while (!pilha_vazia(p1)) {
        int valor = desempilhar(p1);
        empilhar(&temp, valor);
    }

    // Separando pares e impares em pilhas distintas
    while (!pilha_vazia(&temp)) {
        int valor = desempilhar(&temp);

        // Se resto da divisão for 0 então é Par
        if (valor % 2 == 0) {
            empilhar(p2, valor);  // Par > P2
        } else {
            empilhar(p1, valor);  // Impar > P1
        }
    }
}