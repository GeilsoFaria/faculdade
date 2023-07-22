#include <stdio.h>
#include <stdlib.h>

int *p;
int v[]={};

void insere();
void duplica();
void mostra();

int main(void)
{
    int escolha=0;

    do
    {
        printf("[1] Inserir 10 valores em um vetor de inteiros\n");
        printf("[2] Duplicar os elementos do vetor\n");
        printf("[3] Imprimir os valores do vetor\n");
        printf("[4] Sair\n");
        scanf("%d",&escolha);
        switch(escolha)
        {
            case 1:
                insere();
                break;
            case 2:
                duplica();
                break;
            case 3:
                mostra();
                break;
        }
    }while(escolha!=4);

    free(p);
    system("pause");
    return 0;
}
void insere()
{
    int i;
    p =(int*)malloc(sizeof(int)*20);

    for(i=0;i<10;i++)
    {
        printf("Insira um valor\n");
        scanf("%d",&v[i]);
    }
}
void duplica()
{
    int i=9;
    p =(int*)malloc(sizeof(int)*20);

    for(p =v; p <= &v[9]; p++)
    {
        i++;
        v[i]=*p;
    }
}
void mostra()
{
    printf("VETOR= ");
	for(p = v; p <= &v[19]; p++)
    {
		printf("%d ", *p);
    }
}
