#include <stdio.h>

long int fatorial(int); //Protótipo

int main(){
    int n;

    scanf("%d", &n);

    printf("%ld\n", fatorial(n)); // usar "ld" para long int

    return 0;
}

long int fatorial(int n){
    int i;
    long int fat = 1;

    for(i = n; i > 0; i--){
        fat = fat * i;
    }

    return fat;
}