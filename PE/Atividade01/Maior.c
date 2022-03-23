#include <stdio.h>

long int maior(long int, long int, long int);

int main(){
    long int A, B, C, nMaior;

    scanf("%ld %ld %ld", &A, &B, &C);

    nMaior = maior(A, B, C);
    printf("%ld\n", nMaior);

    return 0;
}

long int maior(long int A, long int B, long int C){
    long int maior = A;

    if(A > B && (A > C || A == C)){
        maior = A;
    }else if(B > A && (B > C || B == C)){
        maior = B;
    }else if(C > A && (C > B || C == B)){
        maior = C;
    }
    return maior;
}