#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void inserir_elementos(struct Node** head, int valor);
void exibir_lista(struct Node* head);
void liberar_lista(struct Node** head);

int main() 
{
    struct Node* head = NULL;
    int opcao, valor;

    do {
        printf("\nMenu:\n");
        printf("1) Inserir elemento\n");
        printf("2) Exibir lista\n");
        printf("3) Liberar lista\n");
        printf("4) Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Insira um elemento: ");
                scanf("%d", &valor);
                inserir_elementos(&head, valor);
                break;
            case 2:
                exibir_lista(head);
                break;
            case 3:
                liberar_lista(&head);
                break;
            case 4:
                liberar_lista(&head);
                printf("Saindo...\n");
                break;
            default:
                printf("Escolha uma opcao disponivel no menu!\n");
        }
    } while (opcao != 4);

    return 0;
}

void inserir_elementos(struct Node** head, int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    if (!novoNo) {
        printf("Erro ao alocar memoria.\n");
        return;
    }
    novoNo->data = valor;
    novoNo->next = *head;
    *head = novoNo;
    printf("%d inserido com sucesso.\n", valor);
}

void exibir_lista(struct Node* head) {
    if (head == NULL) {
        printf("Lista vazia, insira elementos...\n");
        return;
    }

    printf("Lista: ");

    struct Node* atual = head;
    while (atual != NULL) {
        printf("%d; ", atual->data);
        atual = atual->next;
    }
}

void liberar_lista(struct Node** head) {
    struct Node* atual = *head;
    struct Node* proximo;

    while (atual != NULL) {
        proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    *head = NULL;

    printf("Memoria liberada!\n");
}