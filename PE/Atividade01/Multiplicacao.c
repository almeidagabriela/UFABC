#include <stdio.h>

long int multiplicacao(int, int);

int main(){
    int a, b;
    long produto;

    scanf("%d %d", &a, &b);

    produto = multiplicacao(a, b);

    printf("%ld\n", produto);

    return 0;
}

long int multiplicacao(int a, int b){
    long int resultado = 0;

    if(a > 0){
        resultado = b + multiplicacao(a-1, b);
    }

    return resultado;
}