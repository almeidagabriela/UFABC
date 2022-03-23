#include <stdio.h>
#include <string.h>

int main(){
    char palavra[11];
    int h[26], alturaMaior = 0, area;

    for(int i = 0; i < 26; i++){
        scanf("%d", &h[i]);
    }

    scanf("%s", palavra);

    for(int i = 0; i < strlen(palavra); i++){
        if(h[palavra[i]-97] > alturaMaior){
            alturaMaior = h[palavra[i]-97];
        }
    }

    area = strlen(palavra) * alturaMaior;

    printf("%d\n", area);

    return 0;
}