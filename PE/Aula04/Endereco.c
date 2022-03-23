#include <stdio.h>

int main(){
    int i = 1;
    char c = 'E';
    float f = 12.7f;
    double d = 3.14;

    // Ponteiros
    int *ptI = &i;
    char *ptC = &c;
    float *ptF = &f;
    double *ptD = &d;

    printf("Conteudo de i: [%d] Endereco de i: [%p]\n", i, &i);
    printf("Conteudo de c: [%c] Endereco de i: [%p]\n", c, &c);
    printf("Conteudo de f: [%f] Endereco de i: [%p]\n", f, &f);
    printf("Conteudo de d: [%lf] Endereco de i: [%p]\n", d, &d);

    printf("Conteudo de ptI: [%p] Endereco de ptI: [%p]\n", ptI, &ptI);
    printf("Conteudo de ptC: [%p] Endereco de ptC: [%p]\n", ptC, &ptC);
    printf("Conteudo de ptF: [%p] Endereco de ptF: [%p]\n", ptF, &ptF);
    printf("Conteudo de ptD: [%p] Endereco de ptD: [%p]\n", ptD, &ptD);

    printf("Apontado por ptI: [%d]\n", *ptI);
    printf("Apontado por ptC: [%c]\n", *ptC);
    printf("Apontado por ptF: [%f]\n", *ptF);
    printf("Apontado por ptD: [%lf]\n", *ptD);

    return 0;
}