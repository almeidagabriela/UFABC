#include <stdio.h>

int main(){
    int num, maior;

    scanf("%d", &num);

    maior = num;

    while(num >= 0){
        if(num > maior){
            maior = num;
        }
        scanf("%d", &num);
    }

    if(maior >= 0){
        printf("%d\n", maior);
    }else{
        puts("nenhum numero informado");
    }

    return 0;
}