#include <stdio.h>

void altera(int n) {
    printf("funcao n = %d\n", n);
    n = 10;
    printf("funcao n = %d\n", n);
}

int main() {
    int numero = 90;

    printf("main numero = %d\n", numero);
    altera(numero);
    printf("main numero = %d\n", numero);

    return 0;
}
