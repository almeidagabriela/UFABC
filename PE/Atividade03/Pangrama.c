#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * strlwr(char *);

int main(){
    char frase[1001];
    int verifica = 0, cont = 0;

    //Entrada
    while(fgets(frase, 1001, stdin) != NULL){
        strcpy(frase, strlwr(frase));

        for(int j = 0; j < 26; j++){
            for(int i = 0; i < strlen(frase); i++){
                if(frase[i] == j+97 && verifica == 0){
                    cont++;
                    verifica = 1;
                }

            }
            verifica = 0;
        }

        if(cont == 26){
            printf("sim\n");
        }else{
            printf("nao\n");
        }

        cont = 0;
    }

    return 0;
}

char * strlwr(char *str){
    for(int i = 0; i < strlen(str); i++){
        str[i] = tolower(str[i]);
    }

    return str;
}