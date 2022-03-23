#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct tRacional{
  int a;
  int b; //Não pode ser 0
};

struct tRacional racional(int, int);
struct tRacional negativo(struct tRacional);
struct tRacional soma(struct tRacional, struct tRacional);
struct tRacional sub(struct tRacional, struct tRacional);
struct tRacional mult(struct tRacional, struct tRacional);
struct tRacional divi(struct tRacional, struct tRacional);
struct tRacional reduz(struct tRacional);

int mmc (int, int);
int mdc(int, int);

int main(){
    int a, b, c, d;
    char operacao[2];
    struct tRacional racional1, racional2, resultado;

    while(scanf("%d %d %s %d %d", &a, &b, operacao, &c, &d) != EOF){

        racional1 = racional(a, b);
        racional2 = racional(c, d);

        if(strcmp(operacao, "+") == 0){
            resultado = soma(racional1, racional2);
        }else if(strcmp(operacao, "-") == 0){
            resultado = soma(racional1, negativo(racional2));
        }else if(strcmp(operacao, "*") == 0){
            resultado = mult(racional1, racional2);
        }else if(strcmp(operacao, "/") == 0){
            resultado = divi(racional1, racional2);
        }

        printf("%d %d\n", resultado.a, resultado.b);
    }

    return 0;
}

struct tRacional racional(int a, int b){
    struct tRacional racional;
    racional.a = a;
    racional.b = b;

    return racional;
}

struct tRacional negativo(struct tRacional m1){
    struct tRacional negativo;

    negativo.a = m1.a * -1;
    negativo.b = m1.b;

    return negativo;
}

struct tRacional soma(struct tRacional m1, struct tRacional m2){
    struct tRacional soma;
    int resMMC = mmc(m1.b, m2.b);

    soma.a = ((resMMC / m1.b) * m1.a) + ((resMMC / m2.b) * m2.a);
    soma.b = resMMC;

    return reduz(soma);
}

struct tRacional mult(struct tRacional m1, struct tRacional m2){
    struct tRacional mult;

    mult.a = m1.a * m2.a;
    mult.b = m1.b * m2.b;

    return reduz(mult);
}

struct tRacional divi(struct tRacional m1, struct tRacional m2){
    struct tRacional divi;

    divi.a =  m1.a * m2.b;
    divi.b = m1.b * m2.a;
    return reduz(divi);
}

struct tRacional reduz(struct tRacional m1){
    struct tRacional reduz;
    int resMDC;

    resMDC = mdc(m1.a, m1.b);

    reduz.a = m1.a/resMDC;
    reduz.b = m1.b/resMDC;

    return reduz;
}

int mmc (int a, int b){
    return a * (b / mdc(a, b));
}

int mdc(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return fabs(a);
}