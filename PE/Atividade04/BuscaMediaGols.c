#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Atleta{
    char nomeAtleta[51];
    int gols;
};

struct Atleta criaAtleta(char *, int);

int main(){
    int n, m, g, gols = 0, mediaGols;
    char times[51], nomes[51];
    struct Atleta *atletas;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        gols = 0;

        scanf("%s", times);
        scanf("%d", &m);

        atletas = (struct Atleta*) malloc(m * sizeof(struct Atleta));

        for(int j = 0; j < m; j++){
            scanf("%s %d", atletas[j].nomeAtleta, &atletas[j].gols);
            gols += atletas[j].gols;
        }

        mediaGols = gols / m;

        for(int j = 0; j < m; j++){
            if(atletas[j].gols > mediaGols){
                printf("[%s] %s\n", times, atletas[j].nomeAtleta);
            }
        }

        free(atletas);
    }

    return 0;
}

struct Atleta criaAtleta(char *nome, int gols){
    struct Atleta atleta;

    strcpy(atleta.nomeAtleta, nome);
    atleta.gols = gols;

    return atleta;
}