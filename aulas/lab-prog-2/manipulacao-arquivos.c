#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *arq;
    FILE *arq2;
    int n1,n2,x;

    arq= fopen("entrada.txt","r");
    arq2=fopen("saida.txt","a");

    if(arq == NULL)
	{
		printf("Erro, nao foi possivel abrir o arquivo\n");
		exit(1);
	}
	else
        {
            if(arq2 == NULL)
            {
                printf("Erro, nao foi possivel abrir o arquivo\n");
                exit(1);
            }
            else
                {
                    fscanf(arq,"%d%d",&n1,&n2);
                    x=n1+n2;
                    fprintf(arq2,"%d\n",x);
                    printf("Saida: %d\n",x);
                }
        }
	fclose(arq);
	fclose(arq2);
	return 0;



}
