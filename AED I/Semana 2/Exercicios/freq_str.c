//#include "freq_str.h"
#include <stdio.h>

void frequencia_string(const char *str, const char *texto, int *qtd) {
    int i = 0, contador = 0, indice = 0;

    while(texto[i] != '\0'){
        if(texto[i+1] == '\0'){
            int k = 0, comparacao = 0;

            for(int j = indice; j < i; j++){
                if(texto[j] == str[k] || texto[j]+32 == str[k] || texto[j]-32 == str[k]){
                    if(k == 0){
                        indice = j;
                    }
                    k++;
                }else{
                    k = 0;
                }

                if(str[k] == '\0'){
                    contador++;
                    k = 0;


                    if(j+1 != i){
                        j = indice;
                    }
                }
            }
        }

        i++;
    }

    *qtd = contador;
}

int main() {
    char str[20] = "ABCA";
    char texto[200] = "abcdeABCaBcAbcAbCABcabCaBCde";
    int *qtd = 0;

    frequencia_string(str, texto, qtd);

    return 0;
}