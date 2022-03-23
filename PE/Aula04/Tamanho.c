#include <stdio.h>

int main(){
    /*
    int i = 1, j = 5, k = 10;
    int *pti = &i, *ptj =&j, *ptk = &k;

    printf("pti: %p\n", pti);
    printf("ptj: %p\n", ptj);
    printf("ptk: %p\n", ptk);
    */
    // Deslocamento na memória
    int l = 1, m = 7;
    int *ptl = &l, *ptm = &m;

    printf("ptl: %p ptm: %p\n", ptl, ptm);
    printf("%p - %d\n", ptl+1, *(ptl+1));

    return 0;
}