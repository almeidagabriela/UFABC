#include <stdio.h>
#include <string.h>

int main(){
    char t[101];

    while(fgets(t, 101, stdin) != NULL){
        for(int i = 0; i < strlen(t); i++){
            int j = 1;

            if((t[i] > 96 && t[i] < 123) && j <= 3){
                if(j == 1){
                    if(t[i] == 100){
                        //t[i] == d
                        
                    }else if(t[i] == 116){
                        //t[i] == t
                        
                    }else if(t[i] == 118){
                        //t[i] == v
                        
                    }else if(t[i] == 99){
                        //t[i] == c
                        
                    }else if(t[i] == 109){
                        //t[i] == m
                        
                    }
                }else if(j == 2){

                }else if(j == 3){

                }
            }

            j++;
            if(j == 3 && t[i] == 32){
                j = 1;
            }
        }

        printf("%s", t);
    }

    printf("\n");

    return 0;
}