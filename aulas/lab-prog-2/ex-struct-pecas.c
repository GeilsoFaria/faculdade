#include <stdio.h>



struct estoque
{
    char nome_peca[20];
    int num_peca;
    float preco;
    int quantidade;
    int pedido;

};
int main()
{
    struct estoque f;

    printf("Nome da peca\n");
    scanf("%s", f.nome_peca);

    printf("Numero da peca\n");
    scanf("%d", &f.num_peca);

    printf("Preco\n");
    scanf("%f", &f.preco);

    printf("Quantidade\n");
    scanf("%d", &f.quantidade);

    printf("Pedido\n");
    scanf("%d", &f.pedido);

    printf("%s\n %d\n %f\n %d\n %d\n",f.nome_peca, f.num_peca, f.preco, f.quantidade, f.pedido);

    return 0;



}


