#include <stdio.h>
#include <stdlib.h>
#define MAXPILHA 10

/*
EXERCÍCIO 2

Execute as seguintes operações na pilha, mostrando após cada operação o
conteúdo da
pilha e o valor do índice topo.
empilhar(33)     ITENS[0]=33    SIMULAÇÃO DA PIlHA =33
empilhar(7)      ITENS[1]=7     SIMULAÇÃO DA PIlHA =33 7
empilhar(11)     ITENS[2]=11    SIMULAÇÃO DA PIlHA =33 7 11
desempilhar()    ITENS[2]=0     SIMULAÇÃO DA PIlHA =33 7 0
desempilhar()    ITENS[1]=0     SIMULAÇÃO DA PIlHA =33 0 0
empilhar(2)      ITENS[1]=2     SIMULAÇÃO DA PIlHA =33 2 0
*/
struct pilha
{
    int itens[MAXPILHA];
    int topo;
}s;
int Inicializa_topo(struct pilha *);
void empilhar(struct pilha*,int);
void desempilhar(struct pilha*);
int esta_vazia(struct pilha*);

int main(void)
{
    int a=0,op=-1;
    struct pilha s;

    Inicializa_topo(&s);
	do{
		printf("[0]Sair\n");
        printf("[1]Empilhar\n");
        printf("[2]Desempilhar\n");
        printf("[3]Verificar Vazio\n");
		scanf("%d",&op);
		switch(op)
		{
			case 0:
				break;
			case 1:
                printf("Digite um inteiro\n");
                scanf("%d",&a);
                empilhar(&s,a);
                break;
			case 2:
				desempilhar(&s);
				break;
			case 3:
			    esta_vazia(&s);
				break;
		}
	}while(op!=0);


    system("pause");
    return 0;
}

int Inicializa_topo(struct pilha *p)
{
    p->topo=-1;
    return p->topo;
}
void empilhar(struct pilha *p,int x)
{
    int i;

    if (p->topo>10)
        printf("OVERFLOW\n");
    else
    {
        p->topo+=1;
        p->itens[p->topo] = x;
        printf("EMPILHADO= %d\n",x);
    }

}
void desempilhar(struct pilha *p)
{
    int a=0,b=0;

    b=esta_vazia(p);

    if(b==-1)
        printf("UNDERFLOW \n");
    else
    {
        a = p->itens[p->topo];
        p->topo -=1;
        printf("DESEMPIHADO= %d\n ",a);
    }
}
int esta_vazia(struct pilha *s)
{
    int a=0;

    if (s->topo==-1)
    {
        printf("Esta VAZIA\n");
        return -1;
    }
    else
    {
        printf("NAO EH VAZIA\n");
        return 0;
    }
}
