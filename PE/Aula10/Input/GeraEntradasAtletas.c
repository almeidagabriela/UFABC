#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){
    int i, n = atoi(argv[1]); // transformar char(string) em inteiro
    char flagGen = argv[2][0]; // Para caso não venha nem F e nem M, considerarmos como aleatorio
    srand(time(NULL)); // numeros aleatorios

    for(i = 0; i < n; i++){
        printf("%d\n", (rand()%91)+10); // Vai gerar entre 10 e 100
        printf("%d.%d\n", rand()%3, rand()%100); // rand()%3 vai gerar um valor entre 0 e 2
        printf("%d.%d\n", rand()%100, rand()%100);

        // A = Aleatório
        if(flagGen == 'A'){
            printf("%c%s", rand()%100<50?'M':'F', i < n-1?"\n":"");
        }else{
            printf("%c%s", flagGen, i < n-1?"\n":"");
        }

    }

    return 0;
}