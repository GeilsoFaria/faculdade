
#include <stdio.h>

int fiboIter(int);
int fiboRec(int);

int main(){

	int num,aux,aux2;


	printf("Digite um numero");
	scanf("%d",&num);

    aux= fiboRec(num);
    aux2= fiboIter(num);

    printf("\n Fibonacci Recursivo: %d",aux);
	printf("\n Fibonacci Iterativo: %d", aux2);

	return 0;
}


int fiboRec(int num)
{
    if((num==0)|| (num==1))
    {
        return num;
    }else
        {
            return (fiboRec(num-1)+ fiboRec(num-2));

        }

}
int fiboIter(int num)
{
    int gfib1=0,gfib2=1,gfib3, contador=0;

    for(contador>0;contador<num;contador++)
    {

        gfib3= gfib2+gfib1;
        gfib1=gfib2;
        gfib2=gfib3;

    }
    return gfib1;

}
