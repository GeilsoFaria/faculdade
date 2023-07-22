#include <stdio.h>
#include <stdlib.h>

int main(){

    int vetor[10]= {};
    int x;

    printf ("Digite o valor do seu X");
    scanf ("%d", &x);
    printf("Digite dez números");

    for(int i=1; i <10; i++)
    {
        scanf (" %d ", &vetor[i]);

    }

    for(int i = 1; i<10; i++)
    {
           printf(" %d ", vetor[i]);

    }
    for (int i = 1; i< 10; i++)

    {
        if ( vetor [i] == x )
            {
                printf ("\n Achei ");
            }
        else{
            if(vetor[i] != x)
            { printf ("\n Não Achei");

            }
        }


    }

    printf("\n");

    return 0;
}
    system("pause");
