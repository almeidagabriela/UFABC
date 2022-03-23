#include <stdio.h>

int main() {
    char texto[200] = "Algoritmos   e   Estruturas de Dados I. Nessa disciplina,     serao vistas estruturas de dados como   listas, pilhas, filas e arvores  .   Tambem serao vistos algoritmos de  busca  e  ordenacao.";

    int i = 0, contador = 0;

    while(texto[i] != '\0'){
        if((texto[i] == ' ') && (texto[i-1] != ' ' && texto[i-1] != '.')){
            contador++;
        }else if(texto[i] == '.'){
            if(texto[i-1] != ' '){
                contador++;
            }
            printf("%d\n", contador);
            contador = 0;
        }
        i++;
    }

    return 0;
}