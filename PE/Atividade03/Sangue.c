#include <stdio.h>
#include <string.h>

int main(){
    char paciente[3], doador[3];
    int verifica = 0;

    scanf("%s %s", paciente, doador);

    if(strcmp(paciente, "A") == 0){
        verifica = 1;
        if(strcmp(doador, "A") == 0 || strcmp(doador, "O") == 0){
            verifica = 0;
        }
    }else if(strcmp(paciente, "B") == 0){
        verifica = 1;
        if(strcmp(doador, "B") == 0 || strcmp(doador, "O") == 0){
            verifica = 0;
        }
    }else if(strcmp(paciente, "O") == 0){
        verifica = 1;
        if(strcmp(doador, "O") == 0){
            verifica = 0;
        }
    }else if(strcmp(paciente, "AB") == 0){
        verifica = 0;
    }

    if(verifica == 0){
        printf("transfusao compativel\n");
    }else{
        printf("transfusao incompativel\n");
    }

    return 0;
}