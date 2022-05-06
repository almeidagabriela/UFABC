#include <stdio.h>
#include <stdlib.h>

void imprimir_str(char *v, int n) {

    for(int i = 0; i < n; i++){
        printf("%c", v[i]);
    }

    printf("\n");
}

void imprimir_int(int *v, int n) {
    printf("[");

    for(int i = 0; i < n; i++){
        printf("%d", v[i]);

        if(i != n-1){
            printf(" ");
        }else{
            printf("]");
        }
    }

    printf("\n");
}

void countingsort(char *v, int n) {
    int c[26];

    for(int i = 0; i <= 25; i++) {
        c[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        c[v[i]-65]++;
    }

    imprimir_int(c, 26);

    for(int i = 1; i <= 25; i++) {
        c[i] += c[i - 1];
    }

    imprimir_int(c, 26);

    char saida[n];
    char atual;
    for(int i = n-1; i >= 0; i--) {
        atual = v[i];

        int indice = atual-65;
        saida[c[atual - 65] - 1] = atual;

        c[indice]--;
    }

    for(int i = 0; i < n; i++) {
        v[i] = saida[i];
    }
}

int main() {
    char msg[1000];
    int tamanho = 0, i = 0;

    scanf("%s", msg);

    while(msg[i] != '\0'){
        tamanho++;
        i++;
    }

    countingsort(msg, tamanho);

    imprimir_str(msg, tamanho);

    return 0;
}