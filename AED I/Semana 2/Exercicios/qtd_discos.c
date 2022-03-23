//#include "qtd_discos.h"
#include <stdlib.h>
#include <stdio.h>

void *quantidade_discos(char **discos, int n_discos) {
    //, int **quantidade_por_fabricante
    int fabA = 0, fabB = 0, fabC = 0, fabD = 0;
    int *vetor = malloc(sizeof(int) * 4);

    for(int i = 0; i < n_discos; i++){
        int j = 0;

        while(discos[i][j] != '\0'){
            if(j == 7){
                if(discos[i][j] == 65){
                    fabA++;
                }else if(discos[i][j] == 66){
                    fabB++;
                }else if(discos[i][j] == 67){
                    fabC++;
                }else if(discos[i][j] == 68){
                    fabD++;
                }
            }

            j++;
        }
    }

    vetor[0] = fabA;
    vetor[1] = fabB;
    vetor[2] = fabC;
    vetor[3] = fabD;

    for(int i = 0; i < 4; i++){
        printf("%d\n", vetor[i]);
    }

    //*quantidade_por_fabricante = vetor;
}

int main() {
    char *str[4];

    for(int i = 0; i < 4; i++){
        str[i] = malloc(sizeof(int) * 20);
    }

    str[0] = "Modelo_A1";
    str[1] = "Modelo_B1";
    str[2] = "Modelo_C1";
    str[3] = "Modelo_A1";

    quantidade_discos(str, 4);

    return 0;
}