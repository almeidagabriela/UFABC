#include <stdio.h>

void inserir_elementos(int array[], int n);
void ordenar_array(int array[], int n);
void mortrar_array(int array[], int n);
void buscar(int array[], int n);
int busca_binaria(int arr[], int n, int x);

int main ()
{
    int tamanho = 10;
    int array[tamanho];
    int opcao = 0;
    int validacao = 0;

    while (opcao != 4) {
        printf("\nMenu:\n");
        printf("1) Inserir elemento no array\n");
        printf("2) Apresentar array\n");
        printf("3) Informar elemento a ser buscado\n");
        printf("4) Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_elementos(array, tamanho);
                ordenar_array(array, tamanho);
                validacao = 1;
                break;
            case 2:
                if (validacao) {
                    printf("Array ordenado: ");
                    mortrar_array(array, tamanho);
                } else {
                    printf("Array nao foi preenchido, insira pela opcao 1 do menu.\n");
                }
                break;
            case 3:
                if (validacao) {
                    buscar(array, tamanho);
                } else {
                    printf("Array nao foi preenchido, insira pela opcao 1 do menu.\n");
                }
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Escolha uma opcao disponivel no menu!\n");
                break;
        }
    }

    return 0;
}

void inserir_elementos(int array[], int n) {
    printf("Insira %d elementos distintos no array:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}

void mortrar_array(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void ordenar_array(int array[], int n) {
    // Percorre o array
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            // Se a posição atual de j for maior que a seguinte, inverte as posições.
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void buscar(int array[], int n) {
    int elemento;
    int posicao;

    printf("Digite o elemento a ser buscado: ");
    scanf("%d", &elemento);
    posicao = busca_binaria(array, n, elemento);

    if (posicao != -1) {
        printf("O elemento %d foi encontrado na posicao %d.\n", elemento, posicao+1);
    } else {
        printf("O elemento %d nao foi encontrado no array.\n", elemento);
    }
}

int busca_binaria(int array[], int n, int elemento) {
    int inicio = 0; 
    int fim = n-1;

    while (inicio <= fim) {
        // Divide o array no meio
        int meio = (inicio+fim) / 2;

        // Verifica se o elemento está no meio
        if (array[meio] == elemento) {
            return meio;
        }
        // Verifica se o elemento é maior que o elemento do meio
        else if (array[meio] < elemento) {
            inicio = meio + 1;
        } 
        // Caso contrário: o elemento está na primeira metade.
        else {
            fim = meio - 1;
        }
    }
    return -1;
}