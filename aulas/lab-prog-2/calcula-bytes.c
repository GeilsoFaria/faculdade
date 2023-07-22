#include <stdio.h>
#include <stdlib.h>

struct no
{
    int chave ;
    struct no *prox ;
} ;

struct no *p;

int main(void)
{
    printf("Bytes: %lu\n",sizeof(p));
    system("pause");
    return 0;
}
