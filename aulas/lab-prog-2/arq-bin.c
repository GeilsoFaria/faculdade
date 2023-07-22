/*
3. Escreva um programa em C para ler os dois valores de entrada.dat (arquivo binário)
e salve o resultado da soma no arquivo saida.dat (arquivo binário).
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq;
    FILE *arq2;
    int n1,n2,s;

    arq=fopen("entrada.dat","rb+");
    arq2=fopen("saida.dat","ab+");

    while(!feof(arq))
    {
        fread(&n1,sizeof(int),1,arq);
        fread(&n2,sizeof(int),1,arq);
        s=n1+n2;
        fwrite(&s,sizeof(int),1,arq2);
    }
    fclose(arq);
    fclose(arq2);

    system("pause");
    return 0;
}
