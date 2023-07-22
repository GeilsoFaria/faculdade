/*
Crie um outro programa que
solicita um número n ao usuário (1 ≤ n ≤ 30) e este programa deve ler do arquivo binário
o n-ésimo número de Fibonacci salvo e então imprimi-lo na tela. Obs.: Você deve realizar
o acesso randômico no arquivo, ou seja, realize o acesso direto ao número que deve ser
lido.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    FILE *arq;
    int n;

    arq=fopen("seq30_fib.dat","rb+");

    if ((arq= fopen("seq30_fib.dat", "rb+")) == NULL)
    {
        printf("Arquivo nao pode ser aberto!\n");
    }else
        {
            printf("Digite um numero de 1 a 30\n");
            scanf("%d",&n);//LE P/POSICAO
            fseek(arq,(n*sizeof(int)),SEEK_CUR);//POSICIONA
            fread(&n,sizeof(int),1,arq);//LE NA POSICAO
            printf("FIBBONACCI:%d ",n);
        }
    fclose(arq);


    system("pause");
    return 0;
}
