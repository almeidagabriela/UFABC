//#include "ordenar.h"
//#include "funcao_comparar.h"

typedef struct ItemVetor ItemVetor;
struct ItemVetor {
    char *modelo;
    char *planeta;
    int autonomia;
};

int comparar(ItemVetor item1, ItemVetor item2) {
    if(item1.autonomia < item2.autonomia){
        return -1;
    }else if(item1.autonomia > item2.autonomia){
        return 1;
    }else{
        for(int i = 0; item1.planeta[i] != '\0'; i++){
            if(item1.planeta[i] > item2.planeta[i]){
                return 1;
            }else if(item1.planeta[i] < item2.planeta[i]){
                return -1;
            }
        }

        for(int i = 0; item1.modelo[i] != '\0'; i++){
            if(item1.modelo[i] > item2.modelo[i]){
                return 1;
            }else if(item1.modelo[i] < item2.modelo[i]){
                return -1;
            }
        }
    }
}

int main() {
    return 0;
}