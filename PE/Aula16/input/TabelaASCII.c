#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){
    int i;

    printf("TABELA ASCII\n");
    for(i = 0; i < 128; i++){
        printf("%d = %c\n", i, i);
    }

    printf("MAIUSCULAS\n");
    for(i = 'A'; i <= 'Z'; i++){
        printf("%c ", i);
    }

    return 0;
}