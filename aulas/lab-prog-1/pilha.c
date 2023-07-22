#include <stdio.h>
/*

Pilha: ordem LIFO

Condi��o para armazenar: �ndice nunca pode estar acima do topo da pilha (overflow)

Condi��o para recuperar: �ndice nunca pode estar abaixo da base da pilha (underflow)

***** Fa�a uma solu��o completa para inserir e remover inteiros de uma pilha*****

*/

    int stack[10];

    int tos=0;//�ndice da pr�xima posi��o livre na pilha

    void push(int i);
    int pop();


    int main()
    {
        int n;

        printf("Digite un numero inteiro");
        scanf("%d", &n);
        while(push() != max);
        {
            pop();
        }






    }
    //armazena um dado na pilha

    void push(int i){

	if(tos >= MAX){

		printf("\n Pilha cheia");

		return;

	}

	stack[tos] = i;

	tos++;

    }



    //recupera um dado da pilha

    int pop(){

	if(tos <= 0){

		printf("\n Pilha vazia");

		return 0;

	}

	tos--;

	return(stack[tos]);

    }
