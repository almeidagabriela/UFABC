#include <stdio.h>

void inserir_elementos(int array[], int n);
void mortrar_array(int array[], int n);
void mostrar_array_invertido(int array[], int n);

int main ()
{
    int tamanho = 8;
    int array[tamanho];
    int opcao = 0;
    int validacao = 0;

    while (opcao != 4) {
        printf("\nMenu:\n");
        printf("1) Inserir elemento no array\n");
        printf("2) Apresentar array original\n");
        printf("3) Apresentar array invertido\n");
        printf("4) Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_elementos(array, tamanho);
                validacao = 1;
                break;
            case 2:
                if (validacao) {
                    printf("Array original: ");
                    mortrar_array(array, tamanho);
                } else {
                    printf("Array nao foi preenchido, insira pela opcao 1 do menu.\n");
                }
                break;
            case 3:
                if (validacao) {
                    printf("Array invertido: ");
                    mostrar_array_invertido(array, tamanho);
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

void mostrar_array_invertido(int array[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", array[i]);
    }
    printf("\n");
}