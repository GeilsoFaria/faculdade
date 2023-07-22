#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{   float n1, sqrtn1, pown1;
    printf("Digite um numero\n");
    scanf("%f", &n1);

    if(n1 > 0)
    {
        sqrtn1 = sqrt(n1);
        printf("A raiz quadrada de %.2f eh %.2f", n1, sqrtn1);
    }else
        {
            pown1 = pow(n1,2);
            printf("%.2f ao quadrado eh %.2f", n1, pown1);
        }



    system("pause");
    return 0;
}
