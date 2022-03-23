#include <stdio.h>

int main()
{
	int i, j, linhaA, colunaA, linhaB, colunaB, x, dimensao;


	scanf("%d",&dimensao);
	linhaA = dimensao;
	colunaA = dimensao;
	linhaB = dimensao;
	colunaB = dimensao;

	float matrizA[linhaA][colunaA], matrizB[linhaB][colunaB], matrizC[linhaA][colunaB];


	for(i = 0; i < linhaA; i++) {
		for(j = 0; j < colunaA; j++) {
			scanf("%f", &matrizA[i][j]);
		}
	}

	for(i = 0; i < linhaB; i++) {
		for(j = 0; j < colunaB; j++) {
			scanf("%f", &matrizB[i][j]);
		}
	}


	for(i = 0; i < linhaA; i++) {
		for(j = 0; j < colunaB; j++) {
				matrizC[i][j] =  matrizA[i][j] + matrizB[i][j];
		}
	}

	for(i = 0; i < linhaA; i++) {
		for(j = 0; j < colunaB; j++) {
			printf("%.f", matrizC[i][j]);
            if (j <= linhaA-2)
            {
                printf(" ");
            }
		}
            printf("\n");
	}

	return 0;

}