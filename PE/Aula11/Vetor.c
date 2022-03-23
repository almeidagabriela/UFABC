#include <stdio.h>

int main(){
    int vet[] = {80,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < 10; i++){
        printf("%d%c", vet[i], i < 9?' ':'\n');
    }

    int bytes = 0;

    for(int i = 0; i < 10; i++){
        printf("vet + %d bytes: %p\n", bytes, vet+i); // %p mostra o endereço que o vetor está alocado na memória
        printf("*vet + %d bytes: %d\n", bytes, *(vet+i));
        printf("&vet[%d]: %p\n", i, &vet[i]);

        bytes+=4;
    }

/*
    printf("vet: %p\n", vet); // %p mostra o endereço que o vetor está alocado na memória
    printf("*vet: %d\n", *vet);
    printf("&vet[0]: %p\n", &vet[0]);

    printf("vet + 4 bytes: %p\n", vet+1);
    printf("*vet + 4 bytes: %d\n", *(vet+1));
    printf("&vet[1]: %p\n", &vet[1]);

    printf("vet + 16 bytes: %p\n", vet+4);
    printf("*vet + 16 bytes: %d\n", *(vet+4));
    printf("&vet[1]: %p\n", &vet[1]);
*/

    for(int i = 0; i < 10; i++){
        // Acessando o vetor de um jeito estranho...
        printf("%d%c", *(vet+i), i < 9?' ':'\n');
    }

    return 0;
}