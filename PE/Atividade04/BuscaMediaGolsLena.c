#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Jogador
{
    char nomeAtleta[51];
    int quantGols;
};

struct Jogador perfilJogador (char*, int);

int main()
{
    int quantTimes, quantAtletas, quantGols, i, j, gols = 0, mediaGols;
    char nomeTime[51], nomeAtleta[51];
    struct Jogador *times;

    scanf("%d", &quantTimes);

    times = (struct Jogador*) malloc(quantTimes * sizeof(struct Jogador));

    for (i = 0; i < quantTimes; i++)
    {
        scanf ("%s %d", nomeTime, &quantAtletas);
        for (j = 0; j < quantAtletas; j++)
        {
            scanf("%s", times[j].nomeAtleta);
            scanf("%d", &times[j].quantGols);
            gols += times[j].quantGols;
        }
        mediaGols = (gols / quantAtletas);
        for (j = 0; j < quantAtletas; j++)
        {
           if (times[j].quantGols > mediaGols)
            {
                printf("[%s] %s\n", nomeTime, times[j].nomeAtleta);
            }
        gols = 0;
        }
    }

    free(times);

    return 0;
}

struct Jogador perfilJogador (char* nomeAtleta, int quantGols)
{
      struct Jogador t;
      strcpy(t.nomeAtleta, nomeAtleta);
      t.quantGols = quantGols;
      return t;
};