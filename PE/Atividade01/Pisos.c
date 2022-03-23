#include <stdio.h>

void pisos(int, int, int*, int*);

int main(){

    int l, c, pt1, pt2;

    scanf("%d", &l);
    scanf("%d", &c);

    //if(1 <= l && c <= 100){
        pisos(l, c, &pt1, &pt2);
    //}

    printf("%d\n", pt1);
    printf("%d\n", pt2);

    return 0;
}

void pisos(int l, int c, int *pt1, int *pt2){
    // L: largura da sala | C: comprimento da sala
    *pt1 = (l*c) + ((l-1)*(c-1));
    *pt2 = ((c-1)*2) + ((l-1)*2);
}