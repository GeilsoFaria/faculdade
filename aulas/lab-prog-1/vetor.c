#include <stdio.h>


int main(void){
    float notas[5] = {0};
    float total= 0;
    float media = 0;
    for (int i = 1; i <= 5; i++)
        {
        printf("Escreva 5 notas");
        scanf("%f", &notas[i]);
        }
    for (int i= 1; i <= 5; i++)
        {
        total += notas[i];
        }
    media = total / 5;
    printf("A média foi de %f", media);




    return 0;
}
