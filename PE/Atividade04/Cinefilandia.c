#include <stdio.h>
#include <stdlib.h>

struct PalavrasDoTitulo
{
    char palavra[101];
};

int main() {
    int i, n;
    char palavra[101];
    struct PalavrasDoTitulo *titulo;

    titulo = (struct PalavrasDoTitulo*) malloc(n * sizeof(struct PalavrasDoTitulo));

    for (i = 0; (scanf("%s", titulo[i].palavra)) != EOF; i++)
    {
        printf("%c", titulo[i].palavra[0]);
    }

    printf("\n");

    free(titulo);

    return 0;
}