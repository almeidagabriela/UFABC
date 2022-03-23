#include <stdio.h>

int main(){
    int a;
    float b;
    char c;
    double d;

    //Lendo os valores
    printf("Digite um valor inteiro: ");
    scanf("%d", &a);

    printf("Digite um ponto flutuante: ");
    scanf("%f", &b);

    printf("Digite um caracter: ");
    setbuf(stdin, NULL); // Limpando o dispositivo de entrada padrão
    scanf("%c", &c);

    printf("Digite um ponto flutuante de precisão dupla: ");
    scanf("%lf", &d);

    //Imprimindo os valores lidos
    printf("a: %d\n",a);
    printf("b: %f\n",b);
    printf("c: %c\n",c);
    printf("d: %lf\n",d);

    return 0;
}