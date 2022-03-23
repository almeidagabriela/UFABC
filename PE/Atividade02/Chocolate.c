#include <stdio.h>
#include <stdlib.h>

void preencheVet(int *, int);
void qtdFormas(int *, int, int, int, int *);

int main(){
    int *v, n, d, m, cont, verifica = 0;
    // int v[10000];

    scanf("%d\n", &n);

    v = (int*) malloc(n*sizeof(int));

    preencheVet(v, n);

    scanf("%d%d\n", &d, &m);

    qtdFormas(v, n, d, m, &verifica);

    printf("%d\n", cont);

    return 0;
}

void preencheVet(int *v, int n){
    for(int i = 0; i < n; i++){
        scanf("%d\n", &v[i]);
    }
}

void qtdFormas(int *vet, int n, int d, int m, int *verifica){
    int soma = 0, tam = 0, contMes = 0, j = 0;

    while(contMes < m){
        for(int i = 0; i < n; i++){
            soma = soma + vet[i];
            tam = d - soma;

            if(tam > 0){
                contMes++;
            }else if(tam < 0){
                contMes--;
                soma = soma - vet[i];
            }else if(tam == 0){
                if(contMes == m-1){
                    verifica++;
                    contMes++;

                    // TESTANDO
                    printf("%d\n", soma);
                    printf("%d\n", d);
                    printf("%d\n", tam);
                }else{
                     contMes--;
                     soma = soma - vet[i];
                }
            }

            if(i == n-1 && tam != 0){
                soma = 0;
                contMes = 0;
                j++;
                i = j;

                if(i == n){
                    contMes = m;
                }
            }
        }
    }
}