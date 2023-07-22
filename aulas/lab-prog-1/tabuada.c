#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int contador=0;
    int n=0;
    int tabuada=0;

    printf("Digite um numero entre 1 e 10 ");
    scanf("%d", &n);
    if (n>1 && n<10)
    {
        for (contador>=1;contador <=10;contador++)
        {
            tabuada = n * contador;
            printf("\n %d X %d = %d", n,contador, tabuada);
        }

    }


    system("pause");
    return 0;
}
