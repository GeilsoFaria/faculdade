#include <stdio.h>
#include <stdlib.h>
/*
Declare duas variáveis x e y do tipo int e duas variáveis p e q do tipo int*. Atribua o
valor 2 para x e 8 para y, o endereço de x para p e o endereço de y para q. Então, imprima
(usando printf) as seguintes informações:
(a) O endereço de x e o valor de x;
(b) O valor de p e o valor de *p;
(c) O endereço de y e o valor de y;
(d) O endereço de p (não o seu conteúdo!).
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
