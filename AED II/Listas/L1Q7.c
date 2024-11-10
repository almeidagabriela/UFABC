#include <stdio.h>

#define TAMANHO 9

void inserir_elemento(int array[], int *tamanho);
void mostrar_array(int array[], int tamanho);
void encontrar_moda(int array[], int tamanho);

int main() {
    int array[TAMANHO];
    int tamanho = 0;
    int opcao = 0;

    while (opcao != 4) {
        printf("\nMenu:\n");
        printf("1) Inserir elemento no array\n");
        printf("2) Apresentar array\n");
        printf("3) Apresentar a moda e a quantidade de repeticoes\n");
        printf("4) Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (tamanho < TAMANHO) {
                    while(tamanho < TAMANHO){
                        inserir_elemento(array, &tamanho);
                    }
                } else {
                    printf("O array esta cheio.\n");
                }
                break;
            case 2:
                mostrar_array(array, tamanho);
                break;
            case 3:
                encontrar_moda(array, tamanho);
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

void inserir_elemento(int array[], int *tamanho) {
    printf("Digite um elemento inteiro: ");
    scanf("%d", &array[*tamanho]);
    (*tamanho)++;
}

void mostrar_array(int array[], int tamanho) {
    printf("Array: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void encontrar_moda(int array[], int tamanho) {
    int contagemMax = 0;
    int moda = array[0];
    int contagem;

    for (int i = 0; i < tamanho; i++) {
        contagem = 0;

        for (int j = 0; j < tamanho; j++) {
            // A cada iteração, caso o valor se repita, soma 1
            if (array[i] == array[j]) {
                contagem++;
            }
        }

        // Define a moda
        if (contagem > contagemMax) {
            contagemMax = contagem;
            moda = array[i];
        }
    }

    printf("A moda e %d e se repete %d vezes.\n", moda, contagemMax);
}