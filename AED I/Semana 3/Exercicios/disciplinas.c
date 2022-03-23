#include <stdlib.h>
//#include "disciplinas.h"
#include <stdio.h>

typedef struct Disciplina Disciplina;
struct Disciplina {
    int cod;
    char *nome;
    int creditos;
    Disciplina *requisito;
};

typedef struct Curso Curso;
struct Curso {
    int cod_curso;
    char *nome_curso;
    Disciplina *ultima_disciplina;
};

void insere_disciplina(Curso *curso, Disciplina *nova_disciplina) {
    int i = 0;

    while(curso->ultima_disciplina->nome[i] == nova_disciplina->nome[i]){
        i++;
    }

    if(curso->ultima_disciplina->nome[i] < nova_disciplina->nome[i]){
        nova_disciplina->requisito = curso->ultima_disciplina;
        curso->ultima_disciplina = nova_disciplina;
    }else if(curso->ultima_disciplina->requisito != NULL){
        curso->ultima_disciplina = curso->ultima_disciplina->requisito;
        insere_disciplina(curso, nova_disciplina);

    }else{
        curso->ultima_disciplina->requisito = nova_disciplina;
    }

}

int main() {
    Disciplina *nova = malloc(sizeof(Disciplina));
    Disciplina *Disciplina10 = malloc(sizeof(Disciplina));
    Disciplina *Disciplina20 = malloc(sizeof(Disciplina));
    Curso *Curso = malloc(sizeof(Curso));

    nova->cod = 99;
    nova->nome = "Disciplina1";
    nova->creditos = 1;
    nova->requisito = NULL;

    Disciplina10->cod = 10;
    Disciplina10->nome = "Disciplina10";
    Disciplina10->creditos = 4;
    Disciplina10->requisito = NULL;

    Disciplina20->cod = 20;
    Disciplina20->nome = "Disciplina20";
    Disciplina20->creditos = 6;
    Disciplina20->requisito = Disciplina10;

    Curso->cod_curso = 1;
    Curso->nome_curso = "Curso";
    Curso->ultima_disciplina = Disciplina20;

    insere_disciplina(Curso, nova);

    free(nova);
    free(Disciplina10);
    free(Disciplina20);

    return 0;
}