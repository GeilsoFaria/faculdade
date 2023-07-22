#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void funcao(int *, int *);

int main()

{

     int x, y;

     scanf("%d",&x); 

     scanf("%d",&y);

     funcao(&x,&y);

     printf("x = %d, y = %d", x, y);


     return 0;

} 

void funcao(int *px, int *py)

{

     px = py;

     *py = (*py) * (*px);

     *px = *px + 2;

}
