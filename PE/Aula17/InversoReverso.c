#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printListaInverso(char **, int);
void printPalavraInvertida(char *);

int main(){
    char **lista, str[1001];
    int n;

    scanf("%d", &n);

    while(n != 0){
        //Alocando dinamicamente
        lista = (char**) malloc(n * sizeof(char*));

        for(int i = 0; i < n; i++){
            lista[i] = (char*) malloc(1001 * sizeof(char));
            scanf("%s", lista[i]);
        }
        printListaInverso(lista, n);
        free(lista);

        scanf("%d", &n);
    }

    return 0;
}

void printListaInverso(char **lista, int n){
    for(int i = n-1; i >= 0; i--){
        printPalavraInvertida(lista[i]);
        free(lista[i]); // **Devolvendo a memoria**
        printf("\n");
    }
}

void printPalavraInvertida(char *str){
    int i;

    //strlen não considera o \0 na contagem do tamanho
    for(i = strlen(str)-1; i >= 0; i--){
        printf("%c", str[i]);
    }
}