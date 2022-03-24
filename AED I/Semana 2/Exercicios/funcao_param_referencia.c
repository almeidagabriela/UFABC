#include "funcao_param_referencia.h"

void funcao(int a, int b, int *resultado) {
    int resultadoParenteses = 0;
    *resultado = 0;

    for(int i = 1; i <= a; i++){
    	for(int j = 1; j <= b; j++){
    		resultadoParenteses += i*j+10;
    	}
    	*resultado += 5*i*resultadoParenteses;
    	resultadoParenteses = 0;
    }
}