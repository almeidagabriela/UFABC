#include <stdio.h>
#include <string.h>

int main(){
    char str1[101], str2[101];

    //Entrada
    scanf("%s", str1);

    strcpy(str2, str1); //str2 = str1

    //Saída
    printf("%s\n", str2);

    return 0;
}