#include <stdio.h>

void somaUm(int*, int*);

int main(){
    int vet[] = {1,2,3,4,5,6,7,8,9,10}, valor = 11;

    for(int i = 0; i < 10; i++){
        //Evitando o espaço em branco depois do ultimo vetor
        if(i < 9){
            printf("%d ", vet[i]);
        }else{
            printf("%d\n", vet[i]);
        }
    }

    printf("valor=%d\n", valor);

    // Passagem de parametro por referência
    somaUm(vet, &valor);

    for(int i = 0; i < 10; i++){
        //Evitando o espaço em branco depois do ultimo vetor
        printf("%d%c", vet[i], i<9?' ':'\n');
    }

    printf("valor=%d\n", valor);

    return 0;
}

void somaUm(int *v, int *ptV){
    int i;

    for(i = 0; i < 10; i++){
        v[i] = v[i] + 1;
    }

    *ptV = *ptV + 1;
}