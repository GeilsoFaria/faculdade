/*2)N�o.Pois, diferentimente dos arquivos de texto que armazenam caracteres,
os arquivos bin�rios armazenam uma sequ�ncia de bits, que usando apenas editores de texto ser� imposs�vel a compreens�o.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq;
    int n1,n2;

    arq=fopen("entrada.dat","ab+");

    printf("Digite dois numeros inteiros\n");
    scanf("%d%d",&n1,&n2);
    fwrite(&n1,sizeof(int),1,arq);
    fwrite(&n2,sizeof(int),1,arq);

    fclose(arq);

    system("pause");
    return 0;
}
