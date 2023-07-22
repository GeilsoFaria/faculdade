#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *arq;
    int n1,n2;

    arq= fopen("entrada.txt","a");

    if(arq == NULL)
	{
		printf("Erro, nao foi possivel abrir o arquivo\n");
		exit(1);
	}
	else
        {

            printf("Digite dois numeros inteiros\n");
            scanf("%d%d",&n1,&n2);
            fprintf(arq,"%d %d\n",n1,n2);


        }
	fclose(arq);
	return 0;



}
