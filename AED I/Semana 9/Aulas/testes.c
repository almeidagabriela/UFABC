#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *vetor_aleatorio(int n) {
    int *v = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        v[i] = rand();
    }

    return v;
}

void imprimir(int *v, int n) {
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    printf("\n");
}

void selection_sort(int *v, int n) {
    //Passar por todos os indices do inicio ao penultimo elemento
    for(int i = 0; i < n-1; i++) {
        //Verificar se o elemento atual é realmente o menor
        int indice_menor = i;

        for(int k = i+1; k < n; k++) {
            if(v[k] < v[indice_menor]){
                indice_menor = k;
            }
        }

        if(indice_menor != i) {
            int tmp = v[indice_menor];
            v[indice_menor] = v[i];
            v[i] = tmp;
        }
    }
}

void bubblesort_es(int *v, int n) {
    int trocou = 1;

    for(int i = 0; i < n-1 && trocou; i++) {
        trocou = 0;

        for(int k = 0; k < n-1-i; k++) {
            if(v[k] > v[k+1]) {
                int tmp = v[k];
                v[k] = v[k+1];
                v[k+1] = tmp;

                trocou = 1;
            }
        }
    }
}

void insertionsort(int *v, int n) {
    for(int i = 1; i < n; i++) {
        // Encaixar o elemento atual no subvetor que vem antes
        int item_atual = v[i];
        int indice_para_insercao = i;

        for(int k = i-1; k >= 0 && item_atual < v[k]; k--) {
            // Desloca o vetor para a direita até encontrar a posição correta para inserção
            v[k+1] = v[k];
            indice_para_insercao--;
        }

        // Insere o elemento
        v[indice_para_insercao] = item_atual;
    }
}

void shellsort(int *v, int n) {
    int h = 1;// O valor inicial será 1/3 ou mais que o tamanho do vetor

    while(h < n / 3) h = 3 * h + 1;

    while(h >= 1) {
        for(int i = h; i < n; i++) {
            int item_atual = v[i];
            int indice_para_insercao = i;

            for(int k = i-h; k >= 0 && item_atual < v[k]; k-=h) {
                v[k+h] = v[k];
                indice_para_insercao-=h;
            }

            // Insere o elemento
            v[indice_para_insercao] = item_atual;
        }

        h = h / 3;
    }

}

void intercala(int *v, int esq_inicio, int esq_fim, int dir_fim) {
    int dir_inicio = esq_fim + 1;
    int esq = esq_inicio, dir = dir_inicio; // esq: percorre vetor da esquerda | dir: percorre vetor da direita
    int comp = dir_fim - esq_inicio + 1;
    int *v_aux = malloc(sizeof(int) * comp);

    for(int i = 0; i < comp; i++){
        // Verificar se os indices esq ou dir passaram dos limites dos vetores percorridos pelos mesmos
        if(esq > esq_fim) {
            v_aux[i] = v[dir++]; //Pega o elemento e depois incrementa
        }else if(dir > dir_fim) {
            v_aux[i] = v[esq++];
        }else if(v[esq] <= v[dir]){
            v_aux[i] = v[esq++];
        }else{
            v_aux[i] = v[dir++];
        }
    }

    for(int i = 0; i < comp; i++){
           v[esq_inicio + i] = v_aux[i];
    }

    free(v_aux);
}

// Função auxiliar
void mergesort(int *v, int esq, int dir) {
    // Verificar se há pelo menos dois elementos no escopo
    if (esq < dir) {
        int meio = (esq + dir) / 2; // Ponto medio entre esq e dir
        mergesort(v, esq, meio); // Vetor da esqueda
        mergesort(v, meio + 1, dir); // Vetor da direita
        intercala(v, esq, meio, dir);
    }
}

// Função principal
void merge_sort(int *v, int n) {
    mergesort(v, 0, n - 1);
}

// Função de particionamento
int particiona(int *v, int esq, int dir) {
    int pivo = v[dir]; // Armazenando o ultimo elemento do vetor como pivô
    int ultimo_menores = esq - 1; //Inicia a uma posição antes de começar o vetor

    for(int i = esq; i < dir; i++) {
        if(v[i] < pivo) {
            ultimo_menores++;

            int aux = v[ultimo_menores];
            v[ultimo_menores] = v[i];
            v[i] = aux;
        }
    }

    ultimo_menores++;
    v[dir] = v[ultimo_menores];
    v[ultimo_menores] = pivo;

    return ultimo_menores;
}

//Função auxiliar
void quick_sort(int *v, int esq, int dir) {
    //Verificar se há pelo menos dois elementos para ordenar
    if(esq < dir) {
        int i_pivo = particiona(v, esq, dir);

        quick_sort(v, esq, i_pivo - 1);
        quick_sort(v, i_pivo + 1, dir);
        // Não é consideradi o pivô pois o mesmo estará na posição correta.
    }
}

void quicksort(int *v, int n) {
    quick_sort(v, 0, n-1);
}

void teste(int algoritmo, char *nome_algoritmo) {
    //inicializar a semente do rand
    srand(123); // Semente igual para todos

    // Medir o tempo
    clock_t inicio = clock();

    int tamanho = 10000;
    int *vetor;

    for(int i = 0; i < 100; i++) {
        vetor = vetor_aleatorio(tamanho);

        switch(algoritmo) {
            case 1:
                selection_sort(vetor, tamanho);
                break;
            case 2:
                bubblesort_es(vetor, tamanho);
                break;
            case 3:
                insertionsort(vetor, tamanho);
                break;
            case 4:
                shellsort(vetor, tamanho);
                break;
            case 5:
                merge_sort(vetor, tamanho);
                break;
            case 6:
                quicksort(vetor, tamanho);
                break;
        }

        free(vetor);
    }

    // Calcula e imprime o tempo total
    double tempo_total = (double) (clock() - inicio) / CLOCKS_PER_SEC;
    printf("%s = %lf\n", nome_algoritmo, tempo_total);
}

int main() {

    teste(1, "Selection sort");
    teste(2, "Bubble sort");
    teste(3, "Insertion sort");
    teste(4, "Shell sort");
    teste(5, "Merge sort");
    teste(6, "Quick sort");

    return 0;
}