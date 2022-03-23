#include <stdio.h>

int fibonacci(int);

int main(){
    int n;

    scanf("%d", &n);
    printf("%d\n", fibonacci(n));

    return 0;
}

int fibonacci(int n){
    int fiboAnt = 0, fiboAtu = 1, fiboProx;

    for(int i = 1; i < n; i++){
       fiboProx = fiboAnt + fiboAtu;
       fiboAnt = fiboAtu;
       fiboAtu = fiboProx;
    }

    return fiboAnt;
}