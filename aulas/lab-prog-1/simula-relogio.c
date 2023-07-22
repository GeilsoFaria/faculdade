#include <stdio.h>
#include <stdlib.h>

int main ()
{
    float segundos, minutos , horas;

    printf("Digite o tempo do evento em segundos");
    scanf("%f", &segundos);
    minutos = segundos/60;
    horas = minutos /60;
    printf("%.2f segundos\n", segundos);
    printf("%.2f minutos\n", minutos);
    printf("%.2f horas\n", horas);

    system("pause");
    return 0;
}
