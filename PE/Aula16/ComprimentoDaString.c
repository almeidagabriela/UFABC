#include <stdio.h>
#include <string.h>

int main(){
    char str[101]; // Já que o máximo é 100

    // EOF = Final de Arquivo
    while(scanf("%s", str) != EOF){
        // Saída
        printf("%ld\n", strlen(str));
    }

    return 0;
}