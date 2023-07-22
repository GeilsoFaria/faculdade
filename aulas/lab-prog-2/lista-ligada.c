#include <stdio.h>
#include <stdlib.h>

struct no
{
    int chave ;
    struct no *prox ;
} ;

struct lista_ligada
{
    struct no *cabeca;
};

struct no* lista_buscar(struct lista_ligada l,int);
void lista_inserir(struct lista_ligada *,int);
void lista_imprimir(struct lista_ligada l);
void lista_remover(struct lista_ligada *,int);
void verificaVazio(struct lista_ligada l);

int main(void)
{
    int	op=-1,chave,n=-1,res;

    struct lista_ligada l;

    l.cabeca=NULL;

	do
    {
		printf("[0]Sair\n");
        printf("[1]Inserir\n");
        printf("[2]Pesquisar\n");
        printf("[3]Imprimir\n");
        printf("[4]Excluir\n");
        printf("[5]Verificar Vazio\n");
		scanf("%d",&op);
		switch(op)
		{
			case 0:
				break;
			case 1:
			    printf("\nDigite o elemento (inteiro) a ser inserido na lista: ");
                scanf("%d", &n);
                lista_inserir(&l,n);
                break;
			case 2:
                printf("Chave: \n");
				scanf("%d", &chave);
                res = lista_buscar(l,chave);
				if(!res)
					printf("\n Nao encontrado.\n");
				else
                    printf("Chave encontrada = %d \n", chave);
				break;
			case 3:
                lista_imprimir(l);
				break;
			case 4:
			    printf("Chave: \n");
				scanf("%d", &chave);
                lista_remover(&l,chave);
				break;
            case 5:
                verificaVazio(l);
                break;
		}
	}while(op!=0);

    system("pause");
    return 0;
}
void lista_inserir(struct lista_ligada *l,int k)
{
    struct no *novo=NULL ;
    struct no **primeiro=NULL;
    struct no **ultimo=NULL;
    struct no *old, *p;

    p=*primeiro;

    novo = (struct no *)malloc(sizeof(struct no));
    novo->chave = k;

    if(!*ultimo)
    {
        novo->prox=NULL;
        *primeiro=novo;
        *ultimo=novo;

    }
    old=NULL;
    while(p)
    {
        if(p->chave > novo->chave)
        {
            old=p;
            p=p->prox;
        }else
            {
                if(old)
                {
                    old->prox=novo;
                    novo->prox=p;
                }
            }
            novo->prox=p;
            *primeiro=novo;

    }
    (*ultimo)->prox=novo;
    novo->prox=NULL;
    *ultimo=p;
    //novo = (struct no *)malloc(sizeof(struct no));

    //forma comum
    //novo->chave =k;
    /*novo->prox = NULL;
    novo->prox = l->cabeca;
    l->cabeca = novo;*/

    /*if(novo<l->cabeca)//SER O MENOR
    {
        l->cabeca=novo;
        novo->prox=NULL;
    }else if(novo>l->cabeca && novo<maior)//SER O DO MEIO
    {
         novo->prox =k;
    }
    else if(novo>maior)//SER O MAIOR
    {
        maior=novo;
        novo->prox=NULL;
    }*/
}
struct no* lista_buscar(struct lista_ligada l,int k)
{
    struct no *p;

    p = l.cabeca;
    while (p != NULL && p->chave != k)
    {
        p = p->prox;
    }
    return p;
}
void lista_remover(struct lista_ligada *l,int k)
{
    struct no *ant = NULL, *p = l->cabeca;

    while (p != NULL && p->chave != k)
    {
        ant = p;
        p = p->prox;
    }
    if (p == NULL)
    printf("Elemento nao encontrado!");
    else if (ant == NULL)
    l->cabeca = l->cabeca->prox;
    else
    ant->prox = p->prox;

    free(p);
}
void verificaVazio(struct lista_ligada l)
{
    if(l.cabeca==NULL)
    {
        printf("VAZIO\n");

    }else
    {
        printf("NAO EH VAZIO\n");
    }
}
void lista_imprimir(struct lista_ligada l)
{
	struct no *p;

	printf("\n Imprimindo lista ligada simples\n");
	for(p=l.cabeca; p!=NULL; p=p->prox)
    {
		printf("%d -> ",p->chave);
	}
	printf("NULL\n");
}
