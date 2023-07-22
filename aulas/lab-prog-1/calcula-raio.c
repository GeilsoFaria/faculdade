#include <stdio.h>
#include <stdlib.h>

/*
Escreva uma programa em C para ler o raio de uma esfera e calcular a sua área. O cálculo
da área deve ser implementado como uma função. Considere o cálculo da área de um
círculo como:
area = π × raio2
*/
float farea(float t);

int main()
{
    float area;
    float raio;

    printf("Por favor, digite o raio da esfera");
    scanf("%f", &raio);

    area = farea(raio);

    printf("Area %f", area);
    system("pause");
    return 0;
}

float farea(float t)
{
    float a;
    float pi = 3.14;
    a = pi*(t*t);

    return a;

}
