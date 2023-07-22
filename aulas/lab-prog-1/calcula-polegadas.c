//Geilso Faria Rodrigues da Silva 17/10
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int polegadas;
    float conversao;
    #define polegada_centimetro  2.54

    printf("Qual o tamanho de sua TV em polegadas");
    scanf("%d", &polegadas);
    conversao = polegadas * polegada_centimetro;
    printf("O tamanho da sua TV em centímetros é de: %f\n", conversao);

    system("pause");
    return 0;
}
