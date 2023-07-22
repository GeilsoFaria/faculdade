#include <stdio.h>
#include <stdlib.h>


int conta_digitos(int n , int d);

int main()
{
    int a, b, conta_repet;

    printf("Digite um numero inteiro qualquer");
    scanf("%d", &a);
    printf("Digite um numero entre 1 e 9");
    scanf("%d", &b);
    if ( b>=1 && b<=9)
    {
        conta_repet = contadigitos(a,b);
        printf("O numero %d aparece %d em %d", b,conta_repet,a);
    }
    else
    {
        printf("O numero digitado nao esta entre 1 e 9");
    }
    system("pause");
    return 0;
}
int conta_digitos(int n , int d)
{
    int resto;
    int contador= 0;

    resto= n/10;
    n= n/10;
    if(resto == d)
    {
        contador++;

    }
    return contador;



}
