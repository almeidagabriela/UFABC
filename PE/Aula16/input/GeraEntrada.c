#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char * geraPalavra(int);

int main(int argc, char **argv){
    //Passaremos o numero por linha de comando
    int n = atoi(argv[1]), i;
    char *str;

    srand(time(NULL)); //(rand()%100)+1 --> Valores de 0 a 99 somando 1, ou seja, valores de 1 e 100

    for(i = 0; i < n; i++){
        str = geraPalavra((rand()%100)+1);
        printf("%s%s", str, i<n-1?"\n":"");
        //***SEMPRE LIBERAR MEMORIA QUANDO USAR O MALLOC***
        free(str);
    }

    return 0;
}

char * geraPalavra(int n){
    int i;
    char *str;

    //Alocando tamanho do vetor dinamicamente
    str = (char*) malloc((n+1) * sizeof(char));

    for(i = 0; i < n; i++){
        if(rand()%100 < 50){
            str[i] =(rand()%26)+65;
        }else{
            str[i] =(rand()%26)+97;
        }
    }

    //str[i] = 0;
    str[i] = '\0'; //Ultimo caracter

    return str;
}