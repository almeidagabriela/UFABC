#include <stdio.h>

void scanVetor(int *, int);

int main(){
    int vet[50], i, n;

    for(i = 0; i < 50; i++){
        printf("%d%c", vet[i], i < 49 ? ' ':'\n');
    }

    do{
        scanf("%d", &n); // Qtd de vezes que irei inserir um número
    }while(n < 0 || n > 49);

    scanVetor(vet, n);

    for(i = 0; i < 50; i++){
        printf("%d%c", vet[i], i < 49 ? ' ':'\n');
    }

    return 0;
}

void scanVetor(int *v, int n){
    int i;

    for(i = 0; i <= n; i++){
        scanf("%d", &v[i]);
    }
}