#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, *fila, cont = 0, sorteado = 0; // n = nº de participantes da festa

    scanf("%d", &n);

    while(n != 0){
        fila = (int*) malloc(n*sizeof(int));

        cont++;
        printf("Teste %d\n", cont);

        for(int i = 0; i < n; i++){
            scanf("%d", &fila[i]);

            if(fila[i] == i+1){
                sorteado = fila[i];
            }
        }

        printf("%d\n", sorteado);
        printf("\n");

        scanf("%d", &n);
    }

    return 0;
}