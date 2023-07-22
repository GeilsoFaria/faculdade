#include <stdio.h>

int busca_bin(int vet[10],int x,int low,int high);

int main(void)
{
    int i=1,x, low=0,high=9;
    int vetor[10]={};

    for (i>0;i<=10;i++)
    {
        printf("Posicao %d \n",i);
        scanf("%d", &vetor[i]);
    }
    for(i=0;i<10;i++)
    {
        printf(" %d ",vetor[i]);
    }
        printf("Vetor preenchido, digite um numero\n");
        scanf("%d", &x);
        busca_bin(vetor[10],x,low,high);
        printf("%d na %d posicao do vetor", x,busca_bin(vetor[10],x,low,high));

}
int busca_bin(int vet[10], int x,int low,int high)
{
    int m,i=1;

    for(i>0;i<10;i++)
    {
    m = (low + high)/2;

    if(vet[m]< x)
    {
        low=5;
        high=9;
        m = (low + high)/2;
        return vet[m];
    }else if(vet[m]>x)
            {
                low=0;
                high=5;
                m = (low + high)/2;

                return vet[m];
            }else
                {
                    return 1;
                }
    }
}
