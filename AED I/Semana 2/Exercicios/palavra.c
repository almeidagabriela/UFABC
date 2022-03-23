//#include "palavra.h"
#include <stdio.h>

void substituir_palavra(char *texto, char *palavra1, char* palavra2) {
    int i = 0, indice = 0, sobra = 0, falta = 0, volta = 0, tamanho = 0;
    char auxiliar1 = ' ', auxiliar2 = ' ';

    for(int i = 0; texto[i] != '\0'; i++){
        tamanho++;
    }

    for(int i = 0; texto[i] != '\0'; i++){
        if(texto[i] < 65 || (texto[i] > 90 && texto[i] < 97) || texto[i] > 122){
            int k = 0;

            for(int j = 0; j < i; j++){
                if(texto[j] == palavra1[k]){
                    k++;
                }else{
                    k = 0;
                }

                if(palavra1[k] == '\0' && (texto[j+1] < 65 || (texto[j+1] > 90 && texto[j+1] < 97) || texto[j+1] > 122)){
                    k = 0;

                    for(int l = 0; palavra2[l] != '\0'; l++){
                        if(palavra2[l+1] == '\0'){
                            if(l+1 == i-indice){
                                int n = 0;

                                for(int m = indice; m < i; m++){
                                    texto[m] = palavra2[n];
                                    n++;
                                }
                            }else if(l+1 > i-indice){
                                falta = (l+1)-(i-indice);
                                volta = 0;
                                while(volta < falta){
                                    for(int p = i; p < (tamanho+falta); p++){
                                        if(p == i){
                                            auxiliar1 = texto[p];
                                        }

                                        auxiliar2 = texto[p+1];
                                        texto[p+1] = auxiliar1;
                                        auxiliar1 = auxiliar2;

                                    }
                                    volta++;
                                }

                                int n = 0;

                                for(int m = indice; m < (i+falta); m++){
                                    texto[m] = palavra2[n];
                                    n++;
                                }

                            }else if(l+1 < i-indice){
                                if(volta == 0){
                                    sobra = (i-indice)-(l+1);
                                }

                                volta = 0;
                                while(volta < sobra){
                                    for(int p = (i-sobra); p < tamanho; p++){
                                        texto[p] = texto[p+1];
                                    }
                                    volta++;
                                }

                                int n = 0;

                                for(int m = indice; m < (i-sobra); m++){
                                    texto[m] = palavra2[n];
                                    n++;
                                }

                                i = indice;
                            }
                        }
                    }
                }
            }

            indice = i+1;
        }
    }
}

int main() {
    char palavra1[20] = "computador";
    char palavra2[20] = "modelo";
    char texto[200] = "Uma empresa que vende computadores trabalha com tres modelos: computador A, computador B e computador C.";
    int *qtd = 0;

    substituir_palavra(texto, palavra1, palavra2);

    printf("%s\n", texto);

    return 0;
}