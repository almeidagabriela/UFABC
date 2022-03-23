#include <stdio.h>

int subtracao(int, int);

int main(){
    int a, b, resultado;

    scanf("%d %d", &a, &b);

    resultado = subtracao(a, b);

    printf("%d\n", resultado);

    return 0;
}

int subtracao(int a, int b){
    if(b > 0){
        subtracao((a-1), (b-1));
    }else{
        return a;
    }
}