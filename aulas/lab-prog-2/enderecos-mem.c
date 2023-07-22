#include <stdio.h>
#include <stdlib.h>
/*
Pesquise qual é o tamanho em bytes dos ponteiros utilizados pelo seu compilador. Para
isso, você possa usar funções que retornam esse tamanho (como o sizeof em C) ou
procurar pelo manual do compilador
*/
int main(void)
{
    int *p;
    int a;
    char b;

    a=13;
    b='a';

    printf("%d eh o valor de a\n",a);
    printf("O endereco na memoria de a eh: %p\n",&a);
    printf("Tamanho em bytes dos ponteiros no compilador eh: %lu\n", sizeof(p));


    return 0;
}
