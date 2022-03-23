#include <stdio.h>
#include <string.h>

int main(){
    char str[201], maior[201];
    int verifica = 0;

    while(scanf("%s", str) != EOF){
        if(strlen(str) >= strlen(maior)){
            strcpy(maior, str);
            verifica = 1;
        }
    }

    if(verifica != 0){
        printf("A maior palavra informada foi %s\n", maior);
    }else{
        printf("Nenhuma palavra foi informada\n");
    }

    return 0;
}