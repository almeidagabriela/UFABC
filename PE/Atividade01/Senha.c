#include <stdio.h>

int validaSenha(int);

int main(){
    int senha, validar;

    scanf("%d", &senha);

    validar = validaSenha(senha);

    if(validar == 0){
         printf("NAO\n");
    }else{
        printf("SIM\n");
    }

    return 0;
}

int validaSenha(int senha){
    int val, dig1, dig2, dig3, dig4;

    if(senha / 10000 != 0){
        val = 0;
    }else{
        dig1 = senha / 1000;
        senha = senha - (dig1 * 1000);
        dig2 = senha / 100;
        senha = senha - (dig2 * 100);
        dig3 = senha / 10;
        senha = senha - (dig3 * 10);
        dig4 = senha / 1;

        if((dig1 == 0) || (dig2 == 0) || (dig3 == 0) || (dig4 == 0)){
            val = 0;
        }else{
            val = 1;
        }
    }

    return val;
}