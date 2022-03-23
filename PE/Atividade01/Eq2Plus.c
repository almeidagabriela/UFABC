#include <stdio.h>
#include <math.h>

int eq2(float, float, float, float*, float*);

int main(){
    float a, b, c, raiz1, raiz2, qtdRaiz;

    scanf("%f %f %f", &a, &b, &c);

    qtdRaiz = eq2(a, b, c, &raiz1, &raiz2);

    if(qtdRaiz == 2){
         printf("%.4f %.4f\n", raiz1, raiz2);
    }else if(qtdRaiz == 1){
        printf("%.4f\n", raiz1);
    }else{
        printf("nao ha raiz real\n");
    }

    return 0;
}

int eq2(float a, float b, float c, float *raiz1, float *raiz2){
    int qtd = 0;
    float delta;

    delta = pow(b, 2) - (4*a*c);

    if(delta > 0){
        *raiz1 = (-b + sqrt(delta)) / (2*a);
        *raiz2 = (-b - sqrt(delta)) / (2*a);
        qtd = 2;
    }else if(delta == 0){
        *raiz1 = -b / (2*a);
        qtd = 1;
    }else{
        qtd = 0;
    }

    return qtd;
}