#include <stdio.h>

void preencheVet(int *, int);
void contaTipo(int *, int, int *, int);
void tipoComum(int *, int *, int *, int *, int *, int, int *);

int main(){
    int n, vetN[100000], tipo1 = 0, tipo2 = 0, tipo3 = 0, tipo4 = 0, tipo5 = 0, maior = 0, menor = 0, contMaior = 0, contMenor = 0, empate = 0;

    scanf("%d\n", &n);

    preencheVet(vetN, n);

    contaTipo(vetN, n, &tipo1, 1);
    contaTipo(vetN, n, &tipo2, 2);
    contaTipo(vetN, n, &tipo3, 3);
    contaTipo(vetN, n, &tipo4, 4);
    contaTipo(vetN, n, &tipo5, 5);

    tipoComum(&maior, &contMaior, &menor, &contMenor, &tipo1, 1, &empate);
    tipoComum(&maior, &contMaior, &menor, &contMenor, &tipo2, 2, &empate);
    tipoComum(&maior, &contMaior, &menor, &contMenor, &tipo3, 3, &empate);
    tipoComum(&maior, &contMaior, &menor, &contMenor, &tipo4, 4, &empate);
    tipoComum(&maior, &contMaior, &menor, &contMenor, &tipo5, 5, &empate);

    if(empate == 0){
        printf("%d\n", maior);
    }else{
        printf("%d\n", menor);
    }

    return 0;
}

void preencheVet(int *v, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
}

void contaTipo(int *v, int n, int *contTipo, int tipo){
    for(int i = 0; i < n; i++){
        if(v[i] == tipo){
            *contTipo+=1;
        }
    }
}

void tipoComum(int *maior, int *contMaior, int *menor, int *contMenor, int *contTipo, int tipo, int *empate){
    // Se tiver mais de um tipo com maior frequencia de repetições, consideramos o maior deles
    // Ex.: 1 4 4 4 5 5 5 3 3 1 | O tipo 4 e tipo 5 se repetem 3 vezes cada
    // Utilizaremos o 4 pois: 4 < 5
    if(*contTipo > *contMaior){
        *maior = tipo;
        *contMaior = *contTipo;
        *empate = 0;

        if(*contTipo > *contMenor){
            *menor = tipo;
            *contMenor = *contTipo;
        }
    }else if(*contTipo == *contMaior && tipo < *menor){
        *empate = 1;
        *menor = tipo;
        *contMenor = *contTipo;
    }
}