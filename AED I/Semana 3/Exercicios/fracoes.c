//#include "fracoes.h"
#include <stdio.h>

typedef struct Fracao Fracao;
struct Fracao {
    int numerador, denominador;
};

Fracao somar(Fracao f1, Fracao f2) {
    Fracao somaFracao;

    int resto = -1, denF1, denF2, numF1, numF2, mmc, mdc, numerador, denominador, numResultado, denResultado;

    numF1 = f1.numerador;
    numF2 = f2.numerador;
    denF1 = f1.denominador;
    denF2 = f2.denominador;

    while(resto != 0) {
        resto = denF1 % denF2;

        denF1 = denF2;
        denF2 = resto;
    }

    mdc = denF1;
    mmc = (f1.denominador * f2.denominador) / mdc;

    denF1 = f1.denominador;
    denF2 = f2.denominador;

    numerador = ((mmc/denF1)*numF1) + ((mmc/denF2)*numF2);
    denominador = mmc;

    numResultado = numerador;
    denResultado = denominador;

    resto = -1;

    while(resto != 0) {
        resto = numerador % denominador;

        numerador = denominador;
        denominador = resto;
    }

    mdc = numerador;

    somaFracao.numerador = numResultado / mdc;
    somaFracao.denominador = denResultado / mdc;

    return somaFracao;


}

Fracao somar_vetor(Fracao f[], int n_fracoes) {
    Fracao fSoma = somar(f[0], f[1]);

    if(n_fracoes > 2){
        for(int i = 2; i < n_fracoes; i++){
            fSoma = somar(fSoma, f[i]);
        }
    }

    return fSoma;
}

Fracao multiplicar(Fracao f1, Fracao f2) {
    Fracao multiplicaFracao;

    int denF1, denF2, numF1, numF2, numerador, denominador, mdc, resto = -1;

    numF1 = f1.numerador;
    numF2 = f2.numerador;
    denF1 = f1.denominador;
    denF2 = f2.denominador;

    numerador = numF1 * numF2;
    denominador = denF1 * denF2;

    while(resto != 0) {
        resto = numerador % denominador;

        numerador = denominador;
        denominador = resto;
    }

    mdc = numerador;

    numerador = numF1 * numF2;
    denominador = denF1 * denF2;

    multiplicaFracao.numerador = numerador / mdc;
    multiplicaFracao.denominador = denominador / mdc;

    return multiplicaFracao;
}

Fracao multiplicar_vetor(Fracao f[], int n_fracoes) {
    Fracao fMultiplica = multiplicar(f[0], f[1]);

    if(n_fracoes > 2){
        for(int i = 2; i < n_fracoes; i++){
            fMultiplica = multiplicar(fMultiplica, f[i]);
        }
    }

    return fMultiplica;
}

int main() {
    Fracao f1;
    f1.numerador = 15;
    f1.denominador = 20;

    Fracao f2;
    f2.numerador = 12;
    f2.denominador = 60;

    //Teste soma
    //Fracao nova = somar(f1, f2);

    //printf("Fração Soma: %d %d\n", nova.numerador, nova.denominador);

    //Teste multiplicação
    Fracao nova = multiplicar(f1, f2);

    Fracao novaDaNova[2];
/*
    novaDaNova[0].numerador = 15;
    novaDaNova[0].denominador = 20;
    novaDaNova[1].numerador = 12;
    novaDaNova[1].denominador = 60;
*/
    //Fracao nova = multiplicar(novaDaNova[0], novaDaNova[1]);

    printf("Fração Multiplicação: %d %d\n", nova.numerador, nova.denominador);

    return 0;
}