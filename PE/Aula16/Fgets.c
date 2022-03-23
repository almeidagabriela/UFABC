#include <stdio.h>

int main(){
    char str[10];

    // Entradas
    fgets(str, 10, stdin); //stdin: ponteiro via teclado

    // Saídas
    printf("%s\n", str);
    puts(str);

    return 0;
}