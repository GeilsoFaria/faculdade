/* 3. Reescreva a função abaixo tornando-a recursiva. Esta função conta o número de algarismos
(dígitos) que um número inteiro n possui. Assuma n > 0.
int d i g i t o s ( int n ) {
int c on t = 1 ;
while ( n > 9 ) {
n = n / 1 0;
c on t += 1 ;
}
return c on t ;
}*/
#include <stdio.h>
int digitos(int);

int main (void)
{
    int n;

    printf("Digite um numero inteiro");
    scanf("%d",&n);
    printf(" %d digitos o numero possui ",digitos(n));
    return 0;
}

int digitos(int n){
    int contador=0;


    /*if(n<10)
    {
        return 1;
    }else*/if(n>1)
    {
        contador++;
        n=n/10;


        return digitos(n)+1;
    }
}
