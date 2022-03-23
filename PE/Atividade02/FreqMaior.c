#include <stdio.h>
#include <stdlib.h>

void preencheVet(int *, int);
void freqUltima(int *, int);
void freqMaior(int *, int);

int main(){
    int v[10000], n;
    // int *v;

    scanf("%d\n", &n);

    //v = (int*) malloc(n*sizeof(int));

    preencheVet(v, n);
    freqUltima(v, n);
    freqMaior(v, n);

    return 0;
}

void preencheVet(int *v, int n){
    for(int i = 0; i < n; i++){
        scanf("%d\n", &v[i]);
    }
}

void freqUltima(int *v, int n){
    int nota = v[n-1];
    int cont = 0;

    for(int i = 0; i < n; i++){
        if(v[i] == nota){
            cont++;
        }
    }

    printf("Nota %d, %d vezes\n", nota, cont);
}

void freqMaior(int *v, int n){
    int maior = 0, indice = 0;

    for(int i = 0; i < n; i++){
        if(v[i] > maior){
            maior = v[i];
            indice = i;
        }
    }

    printf("Nota %d, indice %d\n", maior, indice);
}