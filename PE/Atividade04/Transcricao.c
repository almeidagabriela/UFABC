#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DNAtranscri
{
    char sequencia[1000001];
};

int main() {
    char sequencia[1000001], RNA[1000001], DNAtranscri[1000001], C = 'C', G = 'G', T = 'T', A = 'A';
    struct DNAtranscri DNA;

    while ( (scanf("%s", DNA.sequencia)) != EOF){
        for (int j = 0; j < strlen(DNA.sequencia); j++){
            if (DNA.sequencia[j] == 67){
                  strcat(RNA, "G");
            }
            else if (DNA.sequencia[j] == 71){
                  strcat(RNA, "C");
            }
            else if (DNA.sequencia[j] == 84){
                  strcat(RNA, "A");
            }
            else{
                  strcat(RNA, "U");
            }
        }
        printf("%s", RNA);
        strcpy(RNA, "");
        printf("\n");
    }

    return 0;
}