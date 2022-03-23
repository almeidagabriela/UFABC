#include <stdio.h>

int main() {

    int numeroArabico, i;

    while (scanf("%d", &numeroArabico) != EOF)
    {
        for (i = numeroArabico; i >= 1000; i = i - 1000)
        {
            printf("M");
            numeroArabico = numeroArabico - 1000;
        }
        for (i = numeroArabico; i >= 900; i = i - 900)
        {
            printf("CM");
            numeroArabico = numeroArabico - 900;
        }
        for (i = numeroArabico; i >= 500; i = i - 500)
        {
            printf("D");
            numeroArabico = numeroArabico - 500;
        }
        for (i = numeroArabico; i >= 400; i = i - 400)
        {
            printf("CD");
            numeroArabico = numeroArabico - 400;
        }
        for (i = numeroArabico; i >= 100; i = i - 100)
        {
            printf("C");
            numeroArabico = numeroArabico - 100;
        }
        for (i = numeroArabico; i >= 90; i = i - 90)
        {
            printf("XC");
            numeroArabico = numeroArabico - 90;
        }
        for (i = numeroArabico; i >= 50; i = i - 50)
        {
            printf("L");
            numeroArabico = numeroArabico - 50;
        }
        for (i = numeroArabico; i >= 40; i = i - 40)
        {
            printf("XL");
            numeroArabico = numeroArabico - 40;
        }
        for (i = numeroArabico; i >= 10; i = i - 10)
        {
            printf("X");
            numeroArabico = numeroArabico - 10;
        }
        for (i = numeroArabico; i >= 9; i = i - 9)
        {
            printf("IX");
            numeroArabico = numeroArabico - 9;
        }
        for (i = numeroArabico; i >= 5; i = i - 5)
        {
            printf("V");
            numeroArabico = numeroArabico - 5;
        }
        for (i = numeroArabico; i >= 4; i = i - 4)
        {
            printf("IV");
            numeroArabico = numeroArabico - 4;
        }
        for (i = numeroArabico; i >= 1; i = i - 1)
        {
            printf("I");
            numeroArabico = numeroArabico - 1;
        }
        printf("\n");
    }

    return 0;
}