#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rodizio(char *, char *);
void diaRodizio(char *, char *);

int main(){
    char s[101], valida[10];
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%s", s);

        rodizio(s, valida);
        printf("%s\n", valida);
    }

    return 0;
}

void rodizio(char *s, char *valida){
    int verLetras = 0, verNum = 0;
    strcpy(valida, "");

    if(strlen(s) != 8){
        strcpy(valida, "FAILURE");
    }else{
        // Validação das letras
        for(int i = 0; i < 3; i++){
            for(int j = 65; j <= 90; j++){
                if(s[i] == j){
                    verLetras = 1;
                }
            }

            if(verLetras != 1){
                strcpy(valida, "FAILURE");
            }

            verLetras = 0;
        }
        // Validação do caracter "-"
        if(valida != "FAILURE" && s[3] == 45){
            // Validação dos numeros
            for(int i = 4; i < 8; i++){
                for(int j = 48; j <= 57; j++){
                    if(s[i] == j){
                        verNum = 1;
                    }
                }

                if(verNum != 1){
                    strcpy(valida, "FAILURE");
                }

                verNum = 0;
            }
        }else{
            strcpy(valida, "FAILURE");
        }
    }

    if(strcmp(valida, "FAILURE") != 0){
        diaRodizio(s, valida);
    }
}

void diaRodizio(char *dia, char *valida){
    int posicao, final = 0;
    posicao = (strlen(dia))-1;
    final = dia[posicao];

    if(final == 49 || final == 50){
        strcpy(valida, "MONDAY");
    }else if(final == 51 || final == 52){
        strcpy(valida, "TUESDAY");
    }else if(final == 53 || final == 54){
        strcpy(valida, "WEDNESDAY");
    }else if(final == 55 || final == 56){
        strcpy(valida, "THURSDAY");
    }else if(final == 57 || final == 48){
        strcpy(valida, "FRIDAY");
    }
}