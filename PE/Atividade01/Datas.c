#include <stdio.h>
#include <math.h>

int validaData(int, int, int);

int main(){
    int d, m, a, valida;

    scanf("%d %d %d", &d, &m, &a);

    valida = validaData(d, m, a);

    if(valida == 0){
        printf("DATA INVALIDA\n");
    }else{
        printf("DATA VALIDA\n");
    }

    return 0;
}

int validaData(int d, int m, int a){
    int valida = 0;

    if((m >= 1 && m <= 12) && d >= 1){
        if((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d <= 31)) {
		   return 1;
        }else if((m == 4 || m == 6 || m == 9 || m == 11) && (d <= 30)){
           return 1;
        }else if(m == 2){
           if(a % 400 == 0 || (a % 100 != 0 && a % 4 == 0)){
                if(d <= 29){
                    valida = 1;
                }else{
                    valida = 0;
                }
            }else if(d >= 29){
                valida = 0;
            }else if(d <= 28){
                valida = 1;
            }
        }
    }
    return valida;
}