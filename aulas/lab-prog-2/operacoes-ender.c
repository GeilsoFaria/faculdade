#include <stdio.h>
#include <stdlib.h>
/*
Declare duas vari�veis x e y do tipo int e duas vari�veis p e q do tipo int*. Atribua o
valor 2 para x e 8 para y, o endere�o de x para p e o endere�o de y para q. Ent�o, imprima
(usando printf) as seguintes informa��es:
(a) O endere�o de x e o valor de x;
(b) O valor de p e o valor de *p;
(c) O endere�o de y e o valor de y;
(d) O endere�o de p (n�o o seu conte�do!).
*/
int main(void)
{
    int x,y,*p,*q;

    x=2;
    y=8;
    p=&x;
    q=&y;

    printf("%d eh o valor de x\n",x);//(a)
    printf("O endereco na memoria de x eh: %p\n",&x);//(a)

    printf("%p eh o valor de p\n",p);//(b)
    printf("%d eh o valor de *p\n",*p);//(b)

    printf("%d eh o valor de y\n",y);//(c)
    printf("O endereco na memoria de y eh: %p\n",&y);//(c)

    printf("O endereco na memoria de p eh: %p\n",&p);//(d)

    return 0;
}
