/*
Faça um programa em C fibo_arq.c que calcula e escreve em um arquivo binário
seq30_fib.dat os 30 primeiros números de Fibonacci.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    FILE *arq;
    int gfib1=0,gfib2=1,gfib3,i;

    arq=fopen("seq30_fib.dat","wb");

    for(i>0;i<30;i++)
    {
        fwrite(&gfib1,sizeof(int),1,arq);
        gfib3= gfib2+gfib1;
        gfib1=gfib2;
        gfib2=gfib3;
    }
    fclose(arq);


    system("pause");
    return 0;
}
