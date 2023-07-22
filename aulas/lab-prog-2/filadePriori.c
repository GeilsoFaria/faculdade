#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 20
struct fila_prioridade
{
    int t[TAMANHO];
    int n;
};
void inserir(struct fila_prioridade*,int);
void aumentar_prioridade (struct fila_prioridade*);
void imprimir(struct fila_prioridade*);
int extrair_maximo(struct fila_prioridade*);
int retornaMAx(struct fila_prioridade*);

int main(void)
{
    int	op=-1,a=0;
	struct fila_prioridade *f;

	do
    {
		printf("\n [0]Sair");
		printf("\n [1]Aumentar Prioridade");
        printf("\n [2]Imprimir");
        printf("\n [3]Inserir");
        printf("\n [4]Extrair maximo que retorna e remove o elemento de maior prioridade");
        printf("\n [5]Maximo que retorna o elemento de maior prioridade\n");
		scanf("%d", &op);
		switch(op)
		{
			case 0:
				break;
			case 1:
			    aumentar_prioridade(&f);
                break;
			case 2:
			    imprimir(&f);
				break;
			case 3:
			    printf("Deseja inserir qual elemento\n");
			    scanf("%d",&a);
			    inserir(&f,a);
				break;
			case 4:
			    extrair_maximo(&f);
				break;
            case 5:
                retornaMAx(&f);
                break;
		}
	}while(op!=0);

    system("pause");
    return 0;
}
void inserir(struct fila_prioridade *f,int a)
{
}
void aumentar_prioridade(struct fila_prioridade *f)
{
}
void imprimir(struct fila_prioridade *f)
{
}
int extrair_maximo (struct fila_prioridade *f)
{
}
int retornaMAx(struct fila_prioridade *f)
{

}
