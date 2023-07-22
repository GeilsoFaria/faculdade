#include<stdio.h>
/*
Escreva uma função recursiva que recebe como parâmetros um número real x e um inteiro
n, tal que n > 1, e retorna o valor de x
n


*/
int calc_pot (float,int);

int main()
{
	int n;
	float x;
	printf("Digite um numero real e um inteiro");
	scanf("%f %d", &x,&n);
	printf("%d", calc_pot(x,n));
	return 0;
}


int calc_pot (float x ,int n){

    if (n==0)
    {
            return 1;
    }else
        {
            return (x * calc_pot (x,n-1));

        }

}

