#include <stdio.h>

int main(){
    int mat[][3] = { {80,1,2}, {3,4,5}, {6,7,8}, {9,10,11} };

    printf("mat: %p\n", mat);
    printf("mat[0]: %p\n", mat[0]);
    printf("&mat[0]: %p\n", &mat[0]);
    printf("&mat[0][0]: %p\n", &mat[0][0]);
    printf("*mat: %p\n", *mat);
    printf("**mat: %d\n", **mat);

    for(int i = 0; i < 4; i++){
        printf("mat + %d: %p\n", i, mat+i);
        printf("**(mat + %d): %d\n", i, **(mat+i));
        printf("*(mat[i] + %d): %d\n", i, *(mat[i]));
    }

    printf("------Os valores da matriz estão alocados em sequencia------\n");

    for(int i = 0; i < 12; i++){
        printf("*((*mat) + %d): %d\n", i, *((*mat)+i));
    }

    return 0;
}