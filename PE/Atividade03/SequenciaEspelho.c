#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inverte(char **, int);

int main(){
    int c, inicio, fim, tamanho;
    char **sequencia;

    scanf("%d", &c);

    for(int i = 0; i < c; i++){
        scanf("%d %d", &inicio, &fim);

        int divisao;

        for(int i = inicio; i <= fim; i++){
            printf("%d", i);
        }
        for(int i = fim; i >= inicio; i--){
            divisao = (i / 10);
            if(i % 10 == 0 && divisao < 100){
                printf("0");
            }

            divisao = ((i % 10) / 1);
            if(divisao != 0){
                printf("%d", divisao);
            }

            divisao = ((i % 100) / 10);
            if(divisao != 0){
                printf("%d", divisao);
            }

            divisao = ((i % 1000) / 100);
            if(divisao != 0){
                printf("%d", divisao);
            }

            divisao = ((i % 10000) / 1000);
            if(divisao != 0){
                printf("%d", divisao);
            }

            divisao = (i / 10000);
            if(divisao != 0){
                printf("%d", divisao);
            }
        }

        printf("\n");

        /*
        tamanho = (fim - inicio) + 1;

        sequencia = (char**) malloc(tamanho * sizeof(char*));

        for(int j = 0; j <= tamanho; j++){
            sequencia[j] = (char*) malloc(12222 * sizeof(char));
            sequencia[j] = (j+inicio);

            printf("%s\n", sequencia[j]);

            if(j == tamanho){
                inverte(sequencia, tamanho);
                free(sequencia[j]);
                free(sequencia);
            }
        }
        */
    }

    return 0;
}

void inverte(char **str, int n){
    for(int i = n-1; i >= 0; i--){
        printf("%s", str[i]);
        //free(str[i]);
    }
}