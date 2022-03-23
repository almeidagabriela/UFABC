#include <stdio.h>

int adicao(int, int);

int main(){
    int a, b, resultado;

    scanf("%d %d", &a, &b);

    resultado = adicao(a, b);

    printf("%d\n", resultado);

    return 0;
}

int adicao(int a, int b){
    if(b > 0){
        adicao((a+1), (b-1));
    }else{
        return a;
    }
}