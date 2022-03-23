#include <stdio.h>
#include <stdlib.h>

//Estrutura
struct Aluno{
    char nome[101];
    char matricula[12];
    int qtdNotas;
    int *notas;
};

//Prototipos da função
int calculaMedia(int *, int);
int somaVetor(int *, int);

int main(){
    int n, notaCorte; //Quantidade de alunos
    struct Aluno *turma;

    scanf("%d", &n);
    //Alocando vetor
    turma = (struct Aluno*) malloc(n *sizeof(struct Aluno));
    for(int i = 0; i < n; i++){
        scanf("%s", turma[i].nome);
        scanf("%s", turma[i].matricula);

        scanf("%d", &turma[i].qtdNotas);
        // Alocando vetor de inteiros para notas
        turma[i].notas = (int*) malloc(turma[i].qtdNotas * sizeof(int));

        for(int j = 0; j < turma[i].qtdNotas; j++){
            scanf("%d", &turma[i].notas[j]);
        }
    }

    scanf("%d", &notaCorte);
    /*
    for(int i = 0; i < n; i++){
        printf("Nome    : %s\n", turma[i].nome);
        printf("Maticula: %s\n", turma[i].matricula);

        printf("Notas   :");
        for(int j = 0; j < turma[i].qtdNotas; j++){
            printf("%d ", turma[i].notas[j]);
        }

        printf("\n\n");
    }
    */

    for(int i = 0; i < n; i++){
        if(calculaMedia(turma[i].notas, turma[i].qtdNotas) >= notaCorte){
            printf("[%s] %s\n", turma[i].matricula, turma[i].nome);
        }
        free(turma[i].notas);
    }

    free(turma);

    return 0;
}

int calculaMedia(int *v, int n){
    return somaVetor(v, n)/n;
}

int somaVetor(int *v, int n){
    int i, s = 0;

    for(i = 0; i < n; i++){
        s = s + v[i];
    }

    return s;
}