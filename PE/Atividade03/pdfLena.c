#include <stdio.h>
#include <stdlib.h>

int main()
{
    int j=0,alturaMax=0,n=26, areaRetangulo;
    int *h = malloc(sizeof(int) * n);

    for(int h_i = 0; h_i < n; h_i++)
{
       scanf("%d",&h[h_i]);
    }

    char* palavra = (char *)malloc(512000 * sizeof(char));
    scanf("%s",palavra);

    while(palavra[j])
        {
            if(h[palavra[j]-97]>alturaMax) // 97 ASCII value of a
             {
                alturaMax=h[palavra[j]-97];
             }
        j++;
        }

    areaRetangulo = alturaMax*j;

    printf("%d\n", areaRetangulo);
    return 0;
}