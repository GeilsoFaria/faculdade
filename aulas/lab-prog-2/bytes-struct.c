#include <stdio.h>
#include <stdlib.h>

/*
Suponha que o tamanho de cada nó do exercício anterior seja 8 bytes. Qual o tamanho
total de uma lista ligada composta por 100 nós? E se fosse armazenado todas as chaves
em um vetor de 100 posições, qual seria o tamanho total em bytes?

*/
//800 Bytes.
struct no
{
    int chave ;
    struct no *prox ;
} ;
struct no *reg;

int main(void)
{
    int i;
    printf("Bytes: %lu\n",sizeof(reg)*100);
    printf("Bytes todas chaves: %lu\n",sizeof(reg->chave)*100);

    system("pause");
    return 0;
}
