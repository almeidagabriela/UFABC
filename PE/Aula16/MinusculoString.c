#include <stdio.h>
#include <string.h>
#include <ctype.h> //Necessario para utilizarmos o tolower

char * strlwr(char *);

int main(){
    char str[101];


    while(scanf("%s", str) != EOF){
        printf("%s\n", strlwr(str));
    }

    return 0;
}

char * strlwr(char *str){
    //strlen = tamanho da string
    for(int i = 0; i < strlen(str); i++){
        str[i] = tolower(str[i]);
    }

    return str;
}