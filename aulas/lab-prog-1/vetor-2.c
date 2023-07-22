#include <stdio.h>
#include <stdlib.h>

int main(){

    int vetor[15];
    int vetorinvert[15];

    printf("Digite 15 números");

    for (int i=0; i <15 ; i++)
    {
        scanf("%d", &vetor[i]);
    }
    for (int i=0, j = 15 ; j < 0, i<15 ; j--, i++)
    {
        vetorinvert[j] = vetor[15-i-1];
        printf(" %d ", vetorinvert[j]);
    }
    system("pause");
    return 0;
}
