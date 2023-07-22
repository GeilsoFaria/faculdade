#include <stdio.h>
#include <stdlib.h>
/*
3. Implemente a função swap() com o cabeçalho abaixo. Esta função deve realizar a troca
dos valores de *p1 e *p2.
void swap (int *p1, int *p2);
*/
void swap (int *p1, int *p2);

int main(void)
{
    int x,y;
    //int *p1,*p2;

    x=2;
    y=8;



    printf("%d eh o valor de *p1\n",x);
    printf("%d eh o valor de *p2\n",y);

    swap(&x,&y);

    return 0;
}
void swap (int *p1, int *p2)
{
    int aux;

    aux=*p1;
    *p1=*p2;
    *p2=aux;

    printf("%d eh o valor de *p1\n",*p1);
    printf("%d eh o valor de *p2\n",*p2);





}
