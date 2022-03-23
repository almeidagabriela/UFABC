#include <stdio.h>

void preencheVet(int *, int);

int main(){
    int n, c, m, vetC[100], vetM[300], carimbada = 0, falta = 0;

    scanf("%d%d%d", &n, &c, &m);

    preencheVet(vetC, c);

    preencheVet(vetM, m);

    int igual = -1;

    for(int j = 0; j < c; j++){
        for(int i = 0; i < m; i++){
            if(vetM[i] == vetC[j] && igual == -1){
                carimbada++;
                igual = i;
            }
        }
        igual = -1;
    }

    falta = c - carimbada;
    printf("%d\n", falta);

    return 0;
}

void preencheVet(int *v, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
}