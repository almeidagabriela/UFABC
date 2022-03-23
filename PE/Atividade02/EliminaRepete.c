#include <stdio.h>
#include <stdlib.h>

void preencheVet(int *, int);
void eliminaRepetido(int *, int);
void tamanhoVet(int *, int, int *);
void mostraVet(int *, int, int);

int main(){
    int *v, n, tamanho = 0;

    scanf("%d\n", &n);

    v = (int*) malloc(n*sizeof(int));

    preencheVet(v, n);
    eliminaRepetido(v, n);
    tamanhoVet(v, n, &tamanho);
    mostraVet(v, n, tamanho);

    return 0;
}

void preencheVet(int *v, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
}

void eliminaRepetido(int *v, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j != i && v[j] == v[i]){
                if(j > i){
                    v[j] = -1;
                }else{
                    v[i] = -1;
                }
            }
        }
    }
}

void tamanhoVet(int *v, int n, int *tam){
    for(int i = 0; i < n; i++){
        if(v[i] != -1){
            *tam += 1;
        }
    }
}

void mostraVet(int *v, int n, int tam){
    int cont = 0;

    for(int i = 0; i < n; i++){
        if(v[i] != -1){
            cont++;
            printf("%d%c", v[i], cont < tam?' ':'\n');
        }
    }
}