#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptA, *ptB;

    printf("char: %ld Bytes.\n", sizeof(char));
    printf("short int: %ld Bytes.\n", sizeof(short int));
    printf("int: %ld Bytes.\n", sizeof(int));
    printf("long int: %ld Bytes.\n", sizeof(long int));
    printf("long long int: %ld Bytes.\n", sizeof(long long int));
    printf("float: %ld Bytes.\n", sizeof(float));
    printf("double: %ld Bytes.\n", sizeof(double));

    ptA = (int*) malloc(sizeof(int)); // (int*) conversão explicita para ptA ser um ponteiro de inteiro
    ptB = (int*) malloc(sizeof(int));

    printf("conteudo de ptA: %d\n", *ptA);
    printf("conteudo de ptB: %d\n", *ptB);

    scanf("%d %d", ptA, ptB);

    printf("conteudo de ptA: %d\n", *ptA);
    printf("conteudo de ptB: %d\n", *ptB);

    *ptA *= *ptB * *ptB; // *ptA = 3 | *ptB = 2 | *ptA *= 2 * 2 | *pta = 3 * 4 | *pta = 12

    printf("---conteudo de ptA: %d\n", *ptA);
    printf("---conteudo de ptB: %d\n", *ptB);

    free(ptA); // Devolvendo as alocações de memórias pro SO
    free(ptB);

    return 0;
}