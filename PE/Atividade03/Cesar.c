#include <stdio.h>
#include <string.h>

int main(){
    char t[101];
    int d;

    scanf("%d\n", &d);

    while(fgets(t, 101, stdin) != NULL){
        for(int i = 0; i < strlen(t); i++){
            if((t[i] > 96 && t[i] < 123) || (t[i] > 64 && t[i] < 91)){
                if(t[i]+d > 122){
                    t[i] = (t[i]+d) - 26;
                }else if(t[i]+d > 90 && t[i] < 96){
                    t[i] = (t[i]+d) - 26;
                }else{
                    t[i] = t[i] + d;
                }
            }
        }

        printf("%s", t);
    }

    printf("\n");

    return 0;
}