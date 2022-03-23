#include <stdio.h>
#include <stdlib.h>

void preencheVet(int *, int);
void bubbleSort(int * , int);

int main(){
    int v[100000], n, vetVer[1000], m;

    scanf("%d\n", &n);

    //v = (int*) malloc(n*sizeof(int));

    preencheVet(v, n);

    scanf("%d\n", &m);

    //vetVer = (int*) malloc(m*sizeof(int));

    preencheVet(vetVer, m);

    int igual = -1;

    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(vetVer[j] == v[i] && igual == -1){
                igual = i;
                printf("%d\n", igual);
            }
        }
        if(igual == -1){
            printf("%d\n", igual);
        }
        igual = -1;
    }

    return 0;
}

void preencheVet(int *v, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
}