#include <stdio.h>
#include <stdlib.h>

int main() {
    //char *romano;
    int numeroArabico, cont = 0;

    while(scanf("%d", &numeroArabico) != EOF){

        //romano = (char*) malloc(101 * sizeof(char));

        for (int i = numeroArabico; i >= 1000; i = i - 1000){
            //romano[cont] = 77;
            //cont++;
            printf("M");
            numeroArabico = numeroArabico - 1000;
        }
        for (int i = numeroArabico; i >= 900; i = i - 900){
            //romano[cont] = 67;
            //cont++;
            //romano[cont] = 77;
            //cont++;
            printf("CM");
            numeroArabico = numeroArabico - 900;
        }
        for (int i = numeroArabico; i >= 500; i = i - 500){
            //romano[cont] = 68;
            //cont++;
            printf("D");
            numeroArabico = numeroArabico - 500;
        }
        for (int i = numeroArabico; i >= 400; i = i - 400){
            //romano[cont] = 67;
            //cont++;
            //romano[cont] = 68;
            //cont++;
            printf("CD");
            numeroArabico = numeroArabico - 400;
        }
        for (int i = numeroArabico; i >= 100; i = i - 100){
            //romano[cont] = 67;
            //cont++;
            printf("C");
            numeroArabico = numeroArabico - 100;
        }
        for (int i = numeroArabico; i >= 90; i = i - 90){
            //romano[cont] = 88;
            //cont++;
            //romano[cont] = 67;
            //cont++;
            printf("XC");
            numeroArabico = numeroArabico - 90;
        }
        for (int i = numeroArabico; i >= 50; i = i - 50){
            //romano[cont] = 76;
            //cont++;
            printf("L");
            numeroArabico = numeroArabico - 50;
        }
        for (int i = numeroArabico; i >= 40; i = i - 40){
            //romano[cont] = 88;
            //cont++;
            //romano[cont] = 76;
            //cont++;
            printf("XL");
            numeroArabico = numeroArabico - 40;
        }
        for (int i = numeroArabico; i >= 10; i = i - 10){
            //romano[cont] = 88;
            //cont++;
            printf("X");
            numeroArabico = numeroArabico - 10;
        }
        for (int i = numeroArabico; i == 9; i = i - 9){
            //romano[cont] = 73;
            //cont++;
            //romano[cont] = 88;
            //cont++;
            printf("IX");
            numeroArabico = numeroArabico - 9;
        }
        for (int i = numeroArabico; i >= 5; i = i - 5){
            //romano[cont] = 86;
            //cont++;
            printf("V");
            numeroArabico = numeroArabico - 5;
        }
        for (int i = numeroArabico; i == 4; i = i - 4){
            //romano[cont] = 73;
            //cont++;
            //romano[cont] = 86;
            //cont++;
            printf("IV");
            numeroArabico = numeroArabico - 4;
        }
        for (int i = numeroArabico; i >= 1; i = i - 1){
            //romano[cont] = 73;
            //cont++;
            printf("I");
            numeroArabico = numeroArabico - 1;
        }

        //printf("%s\n", romano);
        printf("\n");
        // Limpando a String
        //free(romano);

        //cont = 0;
    }

    return 0;
}