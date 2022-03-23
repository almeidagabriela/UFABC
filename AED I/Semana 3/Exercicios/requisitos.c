#include <stdlib.h>
//#include "requisitos.h"
#include <stdio.h>

typedef struct Disciplina Disciplina;
struct Disciplina {
    int cod;
    char *nome;
    int creditos;
    Disciplina *requisito;
};

Disciplina *requisito_inicial(Disciplina *disciplina, int *qtd) {

    if(disciplina->requisito != NULL){
        *qtd = -1;
        disciplina = requisito_inicial(disciplina->requisito, qtd);
        *qtd = *qtd + 1;

    }else if(*qtd == -1){
        *qtd = 0;

    }else{
        disciplina = NULL;
        *qtd = 0;

    }

    return disciplina;
}

int main() {
    Disciplina *Disciplina1 = malloc(sizeof(Disciplina));
    Disciplina *Disciplina2 = malloc(sizeof(Disciplina));

    Disciplina1->cod = 10;
    Disciplina1->nome = "Disciplina1";
    Disciplina1->creditos = 4;
    Disciplina1->requisito = NULL;

    Disciplina2->cod = 20;
    Disciplina2->nome = "Disciplina2";
    Disciplina2->creditos = 6;
    Disciplina2->requisito = Disciplina1;

    int *qtd;

    Disciplina *inicial = requisito_inicial(Disciplina1, qtd);

    printf("Requisito inicial: \n");
    printf("Codigo: %d\n", inicial->cod);
    printf("Nome: %s\n", inicial->nome);
    printf("Creditos: %d\n", inicial->creditos);
    printf("Quantidade de requisitos: %d\n", *qtd);

    free(Disciplina1);
    free(Disciplina2);

    return 0;
}