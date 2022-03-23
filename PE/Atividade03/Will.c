#include <stdio.h>
#include <string.h>

int main(){
    char alfabeto[26];
    int n, nLetra;

    while(scanf("%s", alfabeto) != EOF){
        scanf("%d", &n); // Qtd lampadas piscadas

        for(int i = 0; i < n; i++){
            scanf("%d", &nLetra);
            printf("%c", alfabeto[nLetra-1]);
        }

        printf("\n");
    }

    return 0;
}