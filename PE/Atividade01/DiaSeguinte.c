#include <stdio.h>

void diaSeguinte(int, int, int, int*, int*, int*);

int main(){
    int d, m, a, dA, mA, aA;

    scanf("%d %d %d", &d, &m, &a);

    diaSeguinte(d, m, a, &dA, &mA, &aA);

    printf("%d %d %d\n", dA, mA, aA);

    return 0;
}

void diaSeguinte(int d, int m, int a, int *dA, int *mA, int *aA){
    int bissexto = 0;
    *dA = d;
    *mA = m;
    *aA = a;

    if(a % 400 == 0 || (a % 100 != 0 && a % 4 == 0)){
        bissexto = 1;
    }else{
        bissexto = 0;
    }

    if((m == 1 || m == 3 || m == 5 ||  m == 7 || m == 8 || m == 10) && d == 31){
        *dA = 1;
        *mA = m + 1;
    }else if((m == 4 || m == 6 || m == 9 || m == 11) && d == 30){
        *dA = 1;
        *mA = m + 1;
    }else if(m == 2){
        if(bissexto == 1){
            if(d == 29){
                *dA = 1;
                *mA = m + 1;
            }else{
                *dA = d + 1;
            }
        }else if(d == 28){
            *dA = 1;
            *mA = m + 1;
        }else{
            *dA = d + 1;
        }
    }else if(m == 12 && d == 31){
        *dA = 1;
        *mA = 1;
        *aA = a + 1;
    }else{
        *dA = d + 1;
    }
}