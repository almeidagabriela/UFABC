#include <stdio.h>
#include <string.h>

int main(){
    char msgS[102], impar = '1', par = '0';
    int qtdBits = 0;

    scanf("%s", msgS);

    for(int i = 0; msgS[i] != 0; i++){
        if(msgS[i] == '1'){
           qtdBits++;
        }
    }

    if(qtdBits % 2 == 0){
        strncat(msgS, &par, 1);
    }else{
        strncat(msgS, &impar, 1);
    }

    printf("%s\n", msgS);

    return 0;
}