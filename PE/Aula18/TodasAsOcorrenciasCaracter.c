#include <stdio.h>
#include <string.h>

int main(){
    char str[101], letra, *pos;

    while(scanf("%s %c", str, &letra) != EOF){
        pos = strchr(str, letra); //retorna um ponteiro c/ a 1ª letra da string ou NULL caso não encontre

        while(pos != NULL){
            printf("letra \"%c\" ocorreu na posicao %ld\n", letra, pos-str);

            //Pega a posição do ponteiro encontrado e soma 1 para procurar uma outra ocorrencia a partir dele
            pos = strchr(pos+1, letra);
        }
    }

    return 0;
}