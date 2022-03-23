#include <stdio.h>

void quantidadeDeCedulas(int, int*, int*, int*, int*, int*, int*, int*);

int main(){
    int n, q100, q50, q20, q10, q5, q2, q1;

    scanf("%d", &n);

    quantidadeDeCedulas(n, &q100, &q50, &q20, &q10, &q5, &q2, &q1);

    printf("R$%d.00\n", n);
    if(q100 != 0){
        printf("%d nota(s) de R$100.00\n", q100);
    }

    if(q50 != 0){
        printf("%d nota(s) de R$50.00\n", q50);
    }

    if(q20 != 0){
        printf("%d nota(s) de R$20.00\n", q20);
    }

    if(q10 != 0){
        printf("%d nota(s) de R$10.00\n", q10);
    }

    if(q5 != 0){
        printf("%d nota(s) de R$5.00\n", q5);
    }

    if(q2 != 0){
        printf("%d nota(s) de R$2.00\n", q2);
    }

    if(q1 != 0){
        printf("%d nota(s) de R$1.00\n", q1);
    }

    return 0;
}

void quantidadeDeCedulas(int n, int *q100, int *q50, int *q20, int *q10, int *q5, int *q2, int *q1){
    *q100 = n/100;
    int resto = n%100;
    *q50 = resto/50;
    resto = resto%50;
    *q20 = resto/20;
    resto = resto%20;
    *q10 = resto/10;
    resto = resto%10;
    *q5 = resto/5;
    resto = resto%5;
    *q2 = resto/2;
    resto = resto%2;
    *q1 = resto/1;
}