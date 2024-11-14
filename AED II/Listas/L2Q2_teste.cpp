#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>

int indice(char temp[30]);
#define max 5     // nr de combinacoes PAIS-CAPITAL admitido
#define letras 25 // nr de letras consideradas do alfabeto, que vai resultar no tam da tabela

struct tabela
{
    char info[30];
} info_tabela[letras];

int main()
{
    int i;
    int j;
    int flag;
    char aux[30];
    // Recebe os valores digitados
    printf("Tabela Hash para guardar PAIS e CAPITAL \n");
    printf("Nao ha tratamento de colisoes \n");
    for (i = 0; i < letras; i++) // inicializacao
    {
        strcpy(info_tabela[i].info, "ainda nao prenchido");
    }
    printf("Entrada de dados... \n");
    printf("\n");
    printf("Siga este formato: PAIS-CAPITAL (cinco informacoes) \n");
    for (i = 0; i < max; i++)
    {
        printf("Entre com informacao %d: ", i + 1);
        scanf("\n %s", aux);
        j = indice(aux); // só aceita letras minusculas
        // printf("\n indice na tabela eh: %d ",j);
        strcpy(info_tabela[j].info, aux);
        // printf("\n %s: ",info_tabela[j].info);
        printf("\n");
    }
    // Permite pesquisar
    flag = 1;
    while (flag == 1)
    {
        printf("\n");
        printf("Entre com PAIS que deseja saber a capital \n");
        scanf("\n %s", aux);
        j = indice(aux);
        printf("\n");
        printf("Pais-Capital eh: %s ", info_tabela[j].info);
        printf("\n");
        printf("Indice na tabela hash eh: %d ", j);
        printf("\n");
        printf("Digite C (nova pesquisa) ou qualquer outra tecla para SAIR \n");
        scanf("\n %s", aux);
        if (aux[0] == 'C')
            flag = 1;
        else
            flag = 0;
        printf("\n");
    }

    return 0;
}

int indice(char *temp)
{
    return (temp[0] - 97);
}