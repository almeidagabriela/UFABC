#include <stdlib.h>
//#include "discos.h"

typedef struct Disco Disco;
struct Disco {
   int codigo;
   double preco;
};

void contador(int *comparador) {
    *comparador = *comparador + 1;
}

int particiona(Disco *v, int esq, int dir, int tipo, int *comparador) {
    Disco pivo = v[dir];
    int ultimo_menores = esq - 1;

    for(int i = esq; i < dir; i++) {
        contador(comparador);

        if(tipo == 1) {
            if(v[i].codigo < pivo.codigo) {
                ultimo_menores++;

                Disco aux = v[ultimo_menores];
                v[ultimo_menores] = v[i];
                v[i] = aux;
            }
        }else if(tipo == 2) {
            if(v[i].codigo > pivo.codigo) {
                ultimo_menores++;

                Disco aux = v[ultimo_menores];
                v[ultimo_menores] = v[i];
                v[i] = aux;
            }
        }else{
            if(v[i].preco < pivo.preco) {
                ultimo_menores++;

                Disco aux = v[ultimo_menores];
                v[ultimo_menores] = v[i];
                v[i] = aux;
            }else if(v[i].preco == pivo.preco && v[i].codigo < pivo.codigo) {
                ultimo_menores++;

                Disco aux = v[ultimo_menores];
                v[ultimo_menores] = v[i];
                v[i] = aux;
            }
        }

    }

    ultimo_menores++;
    v[dir] = v[ultimo_menores];
    v[ultimo_menores] = pivo;

    return ultimo_menores;
}

void quick_sort(Disco *v, int esq, int dir, int tipo, int *comparador) {
    if(esq < dir) {
        int i_pivo = particiona(v, esq, dir, tipo, comparador);

        quick_sort(v, esq, i_pivo - 1, tipo, comparador);
        quick_sort(v, i_pivo + 1, dir, tipo, comparador);
    }
}

int quicksort(Disco *v, int n, int tipo) {
    int comp = 0;
    int *comparador = &comp;

    quick_sort(v, 0, n-1, tipo, comparador);

    comp = *comparador;

    return comp;
}

int main() {

    return 0;
}