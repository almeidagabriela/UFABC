#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <math.h>

int indice(char temp[30]);
void pesquisar_pais(char *pais);

#define max 5     // nr de combinacoes PAIS-CAPITAL admitido
#define letras 25 // nr de letras consideradas do alfabeto, que vai resultar no tam da tabela
#define k 6
#define c 0.6180339887
#define b 64

struct Pais_capital {
    char info[30];
    int preenchido;
};

struct Pais_capital info_tabela[letras];

int main()
{
    int i;
    int j;
    int flag;
    char aux[30];

    for (i = 0; i < letras; i++) // inicializacao
    {
        info_tabela[i].preenchido = 0;
    }

    // Recebe os valores digitados
    printf("Tabela Hash para guardar PAIS e CAPITAL \n");
    printf("Com tratamento de colisoes \n");
    
    printf("Entrada de dados... \n");
    printf("\n");
    printf("Siga este formato: PAIS-CAPITAL (cinco informacoes) \n");
    for (i = 0; i < max; i++)
    {
        printf("Entre com informacao %d: ", i + 1);
        scanf("\n %s", aux);
        j = indice(aux); 
        int inicio = j;

        if (j == -1 || j >= letras) {
            printf("Erro: indice fora dos limites ou caractere nao alfabetico.");
            i = i-1;
            continue;
        }

        while (info_tabela[j].preenchido) {
            j = (j+1) % letras;
            if (j == inicio) break;
        }
        
        strcpy(info_tabela[j].info, aux);
        info_tabela[j].preenchido = 1;

        printf("\n");
    }

    // Permite pesquisar
    flag = 1;
    while (flag == 1)
    {
        printf("\n");
        printf("Entre com PAIS que deseja saber a capital \n");
        scanf("\n %s", aux);
        pesquisar_pais(aux);

        printf("Digite 'C' (nova pesquisa) ou qualquer outra tecla para SAIR \n");
        scanf("\n %s", aux);
        if (aux[0] == 'C' || aux[0] == 'c')
            flag = 1;
        else
            flag = 0;
        printf("\n");
    }

    return 0;
}

int indice(char *temp)
{
    int soma = 0;
    int i = 0;

    while (temp[i] != '-' && temp[i] != '\0') {
        i++;
    }

    int paisTam = i;

    for (int i = 0; i < paisTam; i += 2) {
        int parte_esquerda, parte_direita;

        if (i + 1 < paisTam) {
            parte_esquerda = temp[i];
            parte_direita = temp[i + 1];

            if (i == 0) {
                int temp = parte_esquerda;
                parte_esquerda = parte_direita;
                parte_direita = temp;
            }

            int soma_par = ((parte_esquerda - '0') + (parte_direita - '0')) % 10;
            soma = (soma * 10 + soma_par) % letras;
        } else {
            soma = (soma * 10 + (temp[i] - '0')) % letras;
        }
    }

    return soma % letras;
}

void pesquisar_pais(char *pais) {
    int i = indice(pais);
    int inicio = i;

    while (info_tabela[i].preenchido) {
        if (strncmp(info_tabela[i].info, pais, strlen(pais)) == 0 && info_tabela[i].info[strlen(pais)] == '-') {
            printf("Pais-Capital eh: %s\n", info_tabela[i].info);
            printf("Indice na tabela hash eh: %d\n", i);
            return;
        }

        i = (i+1) % letras;
        if (i == inicio) break;
    }

    printf("Erro: Pais nao encontrado.\n");
}