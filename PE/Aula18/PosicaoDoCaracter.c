#include <stdio.h>
#include <string.h>

int main(){
    char str[101], letra, *pos;

    while(scanf("%s %c", str, &letra) != EOF){
        pos = strchr(str, letra); //retorna um ponteiro c/ a 1ª letra da string

        if(pos != NULL){
            printf("a primeira ocorrencia da letra \"%c\" na string \"%s\" eh na posicao \"%ld\"\n", letra, str, pos-str);
            //printf("pos: %p --- *pos: %c\n", pos, *pos);
            //printf("%ld\n", pos-str);
        }else{
            printf("letra \"%c\" nao ocorre na string \"%s\"\n", letra, str);
            //printf("-1\n");
        }
    }

    return 0;
}