#include <stdio.h>
#include <stdlib.h>

int main(){
    int *v, i = 0;

    while(1){
        v = (int*) malloc(1000*sizeof(int));
        printf("%d\n", ++i);
        free(v); //Devolvendo espaço na memória após o uso
    }

    return 0;
}