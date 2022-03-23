#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tComplex{
  int a;
  int b;
};

struct tComplex complexo(int, int);
struct tComplex soma(struct tComplex, struct tComplex);
struct tComplex sub(struct tComplex, struct tComplex);
struct tComplex mult(struct tComplex, struct tComplex);
struct tComplex divi(struct tComplex, struct tComplex);

int main(){
    int a, b, c, d;
    char i1[2], i2[2], operacao[2];
    struct tComplex complexM1, complexM2, resultado;

    while(scanf("%d %d%s %s %d %d%s", &a, &b, i1, operacao, &c, &d, i2) != EOF){

        complexM1 = complexo(a, b);
        complexM2 = complexo(c, d);

        if(strcmp(operacao, "+") == 0){
            resultado = soma(complexM1, complexM2);
        }else if(strcmp(operacao, "-") == 0){
            resultado = sub(complexM1, complexM2);
        }else if(strcmp(operacao, "*") == 0){
            resultado = mult(complexM1, complexM2);
        }else if(strcmp(operacao, "/") == 0){
            resultado = divi(complexM1, complexM2);
        }

        if(resultado.b >= 0){
            printf("%d +%di\n", resultado.a, resultado.b);
        }else{
            printf("%d %di\n", resultado.a, resultado.b);
        }
    }

    return 0;
}

struct tComplex complexo(int a, int b){
    struct tComplex complexo;
    complexo.a = a;
    complexo.b = b;

    return complexo;
}

struct tComplex soma(struct tComplex m1, struct tComplex m2){
    struct tComplex soma;

    soma.a = m1.a + m2.a;
    soma.b = m1.b + m2.b;

    return soma;
}

struct tComplex sub(struct tComplex m1, struct tComplex m2){
    struct tComplex sub;

    sub.a = m1.a - m2.a;
    sub.b = m1.b - m2.b;

    return sub;
}

struct tComplex mult(struct tComplex m1, struct tComplex m2){
    struct tComplex mult;

    mult.a = (m1.a * m2.a) + ((m1.b * m2.b) * -1);
    mult.b = (m1.a * m2.b) + (m1.b * m2.a);

    return mult;
}

struct tComplex divi(struct tComplex m1, struct tComplex m2){
    struct tComplex divi;

    divi.a = (m1.a * m2.a + m1.b * m2.b) / (m2.a*m2.a + m2.b*m2.b);
    divi.b = (((m1.a * m2.b)*-1) + m1.b * m2.a) / (m2.a*m2.a + m2.b*m2.b);
    return divi;
}