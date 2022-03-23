#include <stdio.h>
#include <string.h>

int main(){
    char str1[101], str2[101]; // Já que o máximo é 100

    // EOF = Final de Arquivo
    while(scanf("%s %s", str1, str2) != EOF){
        //Comparando strings
        if(strcmp(str1, str2) == 0){
            // Saída
            printf("iguais\n");
        }else{
            // Saída
            printf("diferentes\n");
        }
    }

    return 0;
}