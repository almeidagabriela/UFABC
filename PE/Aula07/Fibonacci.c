#include <stdio.h>
/*
    Casos base: fibonacii(1) = 0
                fibonacci(2) = 1

    fibonacci(n) = fibonacci(n-2) + fibonacci(n-1);
*/

int fibonacci(int);

int main(){
    int n;

    scanf("%d", &n);
    printf("%d\n", fibonacci(n));

    return 0;
}

int fibonacci(int n){
    if(n == 1){
        return 0;
    }else if(n == 2){
        return 1;
    }

    return fibonacci(n-2) + fibonacci(n-1);
}