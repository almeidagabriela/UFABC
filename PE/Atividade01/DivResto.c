#include <stdio.h>

int divisao(int, int);
int resto(int, int);

int main(){
    int a, b, resDiv, resResto;

    scanf("%d %d", &a, &b);

    resDiv = divisao(a, b);
    resResto = resto(a, b);

    printf("%d %d\n", resDiv, resResto);

    return 0;
}

int divisao(int a, int b){
    int resultado = 0;

    if(a > 0 && a >= b){
        resultado = 1 + divisao(a-b, b);
    }

    return resultado;
}

int resto(int a, int b){
    int resultado = 0, resDiv = 0;

    if(a > 0){
        if(a > b){
            resultado = resto(a-b, b);
        }else if(a < b){
            resultado = a;
        }
    }

    return resultado;
}