#include <stdio.h>
#include <stdlib.h>

struct no
{
    int chave ;
    struct no *prox;
    struct no *ant;
} ;
struct no *prim = NULL;
struct no *novo;
struct no *ult;

void inserir();
void encadear();
struct no* pesquisar(int);
void excluir(struct no*);
void imprimir();
//void verificaVazio();

int main()
{
	int	op, chave;
	struct no *res;

	do{
		printf("[0]Sair\n");
        printf("[1]Inserir\n");
        printf("[2]Pesquisar\n");
        printf("[3]Imprimir\n");
        printf("[4]Excluir\n");
        printf("[5]Verificar Vazio\n");
		scanf("%d", &op);
		switch(op)
		{
			case 0:
				break;
			case 1:
				inserir(); break;
			case 2:
				printf("\n Chave: ");
				scanf("%d", &chave);
				res = pesquisar(chave);
				if(!res)
					printf("\n Nao encontrado.");
				else
					printf("\n Chave= %d", res->chave);
				break;
			case 3:
				imprimir();
				break;
			case 4:
				printf("\n Chave: ");
				scanf("%d", &chave);
				res = pesquisar(chave);//retorna o registro
				if(!res)
					printf("\n Nao encontrado.");
				else
					excluir(res);
				break;
            case 5:
                //verificaVazio();
                break;
		}
	}while(op!=0);

	return 0;
}
void inserir()
{
    novo = (struct no*)malloc(sizeof(struct no));
    if(novo==NULL)
    {
        printf("\n Falha na alocacao");
		return;
	}
	printf("\n CHAVE: ");
	scanf("%d",&novo->chave);
	encadear();
}
void encadear()
{
    if(!prim)
    {
        prim=novo;
        prim->ant=NULL;
        prim->prox=NULL;
    }else
    {
        ult->prox=novo;
        novo->prox=NULL;
        novo->ant=ult;
    }
    ult=novo;
    printf("Cadastrado com sucesso \n");
}
struct no* pesquisar(int x)
{
    struct no *a;
    a=prim;

    while(a)
    {
        if(a->chave!=x)
            a=a->prox;
        else
            break;
    }
    return a;
}
void excluir(struct no* p)
{
    if(p==prim)
    {
        if(prim->prox!=NULL)
        {
            prim=prim->prox;
            prim->ant=NULL;
        }else
            {
                prim = NULL;
                ult = NULL;
                free(prim);
                free(ult);
            }
    }
    else
    {
        if(p==ult)
        {
            ult=ult->ant;
            ult->prox=NULL;

        }else
            {
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;
            }
    }
    printf("Excluido com sucesso \n");
}
void imprimir()
{
    struct no *p;
	p=prim;
	while(p)
    {
        printf("Chave: %d \n",p->chave);
        p=p->prox;
	}
}
/*void verificaVazio()
{
    struct no *p;
    p=prim;

    if(p==NULL)
    {
        printf("VAZIO\n");

    }else
    {
        printf("NAO EH VAZIO\n");
    }
}*/

