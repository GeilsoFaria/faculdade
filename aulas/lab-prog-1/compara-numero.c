#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{   int n1, n2, df;

    printf("Digite o primeiro numero\n");
    scanf ("%d", &n1);
    printf("Digite o segundo numero\n");
    scanf ("%d", &n2);
    if (n1 > n2)
    {
        df = n1 - n2;
        printf("%d eh maior que %d\n", n1,n2);
        printf("A diferenca entre %d e %d eh = %d\n", n1,n2, df);

    }else if(n2 > n1)
        {
            df = n2 - n1;
            printf("%d eh maior que %d\n", n2,n1);
            printf("A diferenca entre %d e %d eh = %d\n", n2,n1, df);

        }else
            {
                 printf("Numeros iguais\n");
                 printf("A diferenca entre %d e %d eh = 0\n", n1,n2);

            }




    system("pause");
    return 0;
}
