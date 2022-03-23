#include <stdio.h>
#include <string.h>

int main()
{
    int n, m1, m2, i;
    char nomeLua[12];
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &m1, &m2);
        if (m1 > m2){
          if (m2 >= 97){
              strcpy(nomeLua, "Cheia");
          }else if (m2 >= 3){
              strcpy(nomeLua, "Minguante");
          }
          else{
              strcpy(nomeLua, "Nova");
          }
        }
      if (m1 < m2){
          if (m2 >= 97){
              strcpy(nomeLua, "Cheia");
          }
          else if (m2 >= 3){
              strcpy(nomeLua, "Crescente");
          }
          else{
              strcpy(nomeLua, "Nova");
          }
      }
      printf("%s\n", nomeLua);
    }
    return 0;
}