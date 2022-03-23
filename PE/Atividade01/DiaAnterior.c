#include <stdio.h>

void diaAnterior(int, int, int, int*, int*, int*);

int main(){
    int d, m, a, dA, mA, aA;

    scanf("%d %d %d", &d, &m, &a);

    diaAnterior(d, m, a, &dA, &mA, &aA);

    printf("%d %d %d\n", dA, mA, aA);

    return 0;
}

void diaAnterior(int d, int m, int a, int *dA, int *mA, int *aA){
    int bissexto = 0;
    *dA = d;
    *mA = m;
    *aA = a;

    if(a % 400 == 0 || (a % 100 != 0 && a % 4 == 0)){
        bissexto = 1;
    }else{
        bissexto = 0;
    }

    if(d == 1){
        if(bissexto == 1){
            if(m == 3){
                *dA = 29;
                *mA = m - 1;
            }
        }else if(m == 3){
            *dA = 28;
            *mA = m - 1;
        }

        if(m == 5 || m == 7 || m == 10 || m == 12){
    		   *dA = 30;
    		   *mA = m - 1;
        }else if(m == 2 || m == 4 || m == 6 || m == 8 ||  m == 9 || m == 11){
            *dA = 31;
            *mA = m - 1;
        }else if(m == 1){
            *dA = 31;
            *mA = 12;
            *aA = a - 1;
        }
    }else{
        *dA = d - 1;
    }
}