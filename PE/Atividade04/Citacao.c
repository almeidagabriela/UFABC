#include <stdio.h>
#include <stdlib.h>

struct nomeCompleto
{
    char nome[101];
};

int main() {
    int i, n, ultimoNome = 0;
    char nome[101];
    struct nomeCompleto *citacao;

    citacao = (struct nomeCompleto*) malloc(n * sizeof(struct nomeCompleto));

    for (i = 0; (scanf("%s,", citacao[i].nome)) != EOF; i++){
        ultimoNome++;
    }

    printf("%s,", citacao[ultimoNome - 1].nome);

    for (i = 0; i < ultimoNome - 1; i++){
        printf(" %c.", citacao[i].nome[0]);
    }

    printf("\n");

    free(citacao);

    return 0;
}