#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>

int indice(char temp[30]);
void pesquisar_pais(char *pais);
void liberar_tabela();

#define max 5     // nr de combinacoes PAIS-CAPITAL admitido
#define letras 25 // nr de letras consideradas do alfabeto, que vai resultar no tam da tabela

struct Pais_capital {
    char info[30];
    struct Pais_capital *prox;
};

struct Pais_capital *info_tabela[letras];

int main()
{
    int i;
    int j;
    int flag;
    char aux[30];

    for (i = 0; i < letras; i++) // inicializacao
    {
        info_tabela[i] = NULL;
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

        if (j == -1 || j >= letras) {
            printf("Erro: indice fora dos limites ou caractere nao alfabetico.");
            i = i-1;
            continue;
        }
        
        // Aloca um novo nó na memoria
        struct Pais_capital* novo = (struct Pais_capital*)malloc(sizeof(struct Pais_capital));
        strcpy(novo->info, aux);
        novo->prox = NULL;

        // Valida se não há colisão
        if (info_tabela[j] == NULL) {
            info_tabela[j] = novo;  
        } 
        else {
            struct Pais_capital* atual = info_tabela[j];

            // Percorre até o final da lista encadeada
            while (atual->prox != NULL) {
                atual = atual->prox;  
            }

            // Adiciona ao final da lista
            atual->prox = novo;  
        }

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

    liberar_tabela();

    return 0;
}

int indice(char *temp)
{
    // Validacao de letras minusculas
    if (temp[0] >= 'a' && temp[0] <= 'z') {
        return (temp[0] - 97);
    } 
    else if (temp[0] >= 'A' && temp[0] <= 'Z'){
        return (temp[0] - 65);
    }
    
    return -1;
}

void pesquisar_pais(char *pais) {
    int i = indice(pais);

    if (i == -1 || i >= letras) {
        printf("Erro: indice fora dos limites ou caractere nao alfabetico.\n");
        return;
    }

    struct Pais_capital *atual = info_tabela[i];
    while (atual != NULL) {
        if (strncmp(atual->info, pais, strlen(pais)) == 0) {
            printf("Pais-Capital eh: %s\n", atual->info);
            printf("Indice na tabela hash eh: %d\n", i);
            return;
        }
        atual = atual->prox;
    }
    printf("Erro: Pais nao encontrado.\n");
}

void liberar_tabela() {
    for (int i = 0; i < letras; i++) {
        struct Pais_capital *atual = info_tabela[i];
        while (atual != NULL) {
            struct Pais_capital *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        info_tabela[i] = NULL;
    }
    printf("Memoria liberada!\n");
}