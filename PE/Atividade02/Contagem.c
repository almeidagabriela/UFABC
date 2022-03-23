#include <stdio.h>
//#include <stdlib.h>

void preencheVet(int *, int);
int maiorOuIgual(int *, int, int);

int main(){
    int v[100000], n, k, verifica;
    //int *v;

    scanf("%d\n", &n);

    //v = (int*) malloc(n*sizeof(int));

    preencheVet(v, n);

    scanf("%d\n", &k);

    verifica = maiorOuIgual(v, n, k);

    printf("%d\n", verifica);

    return 0;
}

void preencheVet(int *v, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
}

int maiorOuIgual(int *v, int n, int k){
    int cont = 0;

    for(int i = 0; i < n; i++){
        if(v[i] >= k){
            cont++;
        }
    }

    return cont;
}