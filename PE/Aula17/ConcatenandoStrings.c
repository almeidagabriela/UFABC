#include <stdio.h>
#include <string.h>

int main(){
    char str1[201], str2[201]; //A segunda poderia ser só 101 mesmo, masok

    //Entrada
    while(scanf("%s %s", str1, str2) != EOF){
        strcat(str1, str2);

        //Saída
        printf("%s\n", str1);
    }

    return 0;
}