#include <stdio.h>
#include <string.h>

int main(){
    char str[201], menor[201];
    int verifica = 0, inicia = 0;

    while(scanf("%s", str) != EOF){
        if(inicia == 0){
            strcpy(menor, str);
            inicia = 1;
        }

        if(strlen(str) <= strlen(menor)){
            strcpy(menor, str);
            verifica = 1;
        }
    }

    if(verifica != 0){
        printf("A menor palavra informada foi %s\n", menor);
    }else{
        printf("Nenhuma palavra foi informada\n");
    }

    return 0;
}