#include <stdio.h>

int main(){
    int anoNasc, anoAtual, idade;
    char nome[100]; //String = vetor de caracteres

    scanf("%d %s %d", &anoAtual, nome, &anoNasc);

    idade = anoAtual - anoNasc;

    printf("%s, voce completa %d anos de idade neste ano.\n", nome, idade);

    return 0;
}