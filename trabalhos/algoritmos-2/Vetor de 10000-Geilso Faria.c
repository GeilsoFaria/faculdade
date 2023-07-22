#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void merge(int v[], int inicio, int meio, int fim);
void mergeSort(int v[], int inicio, int fim);
void quick_sort(int v[], int left, int right);
void insertionSort(int lista[], int quantidade);
void selectionSort(int lista[], int quantidade);
void bubble_sort(int v[], int n);
void imprimir(int v[]);

int main(void)
{
    int v[9999]={};
    int i,j;
    float tempo=0;
    clock_t t;

    for(i=0,j=10000;i<10000,j>0;i++,j--)
    {
        v[i]=j;
    }
    t = clock();
    mergeSort(v,0,9999);
    t = clock()- t;
    printf("Tempo de execucao em MILESSEGUNDOS MERGE SORT: %f\n", ((float)t))/(CLOCKS_PER_SEC/1000);



    for(i=0,j=10000;i<10000,j>0;i++,j--)
    {
        v[i]=j;
    }
    t = clock();
    quick_sort(v,0,9999);
    t = clock() - t;
    printf("Tempo de execucao em MILESSEGUNDOS QUICK SORT: %f\n", ((float)t))/(CLOCKS_PER_SEC/1000);


    for(i=0,j=10000;i<10000,j>0;i++,j--)
    {
        v[i]=j;
    }
    t = clock();
    insertionSort(v,10000);
    t = clock() - t;
    printf("Tempo de execucao em MILESSEGUNDOS INSERCTION SORT: %f\n", ((float)t))/(CLOCKS_PER_SEC/1000);

    for(i=0,j=10000;i<10000,j>0;i++,j--)
    {
        v[i]=j;
    }
    t = clock();
    selectionSort(v,10000);
    t = clock() - t;
    printf("Tempo de execucao em MILESSEGUNDOS SELECTION SORT: %f\n", ((float)t))/(CLOCKS_PER_SEC/1000);


     for(i=0,j=10000;i<10000,j>0;i++,j--)
    {
        v[i]=j;
    }
    t = clock();
    bubble_sort(v,10000);
    t = clock() - t;
    printf("Tempo de execucao em MILESSEGUNDOS BUBBLE SORT: %f\n", ((float)t))/(CLOCKS_PER_SEC/1000);

    return 0;
}
void mergeSort(int v[], int inicio, int fim)
{
    int meio;
    if(inicio < fim)
    {
        meio = floor((inicio+fim)/2);
        mergeSort(v,inicio,meio);
        mergeSort(v,meio+1,fim);
        merge(v,inicio,meio,fim);
    }
}
void merge(int v[], int inicio, int meio, int fim)
{
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL)
    {
        for(i=0; i<tamanho; i++)
        {
            if(!fim1 && !fim2)
            {
                if(v[p1] < v[p2])
                    temp[i]=v[p1++];
                else
                    temp[i]=v[p2++];

                if(p1>meio) fim1=1;
                if(p2>fim) fim2=1;
            }
            else
                {
                    if(!fim1)
                    temp[i]=v[p1++];
                    else
                    temp[i]=v[p2++];
                }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++)
        v[k]=temp[j];
    }
    free(temp);
}

void quick_sort(int v[], int left, int right)
{
	int i, j, centro, aux;
	i = left;
	j = right;
	centro = v[(left+right)/2];
	while(i<=j)
    {
        while(v[i]<centro && i<right){i++;}
		while(v[j]>centro && j>left){j--;}
		if(i<=j)
		{
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
		}
	}
	if(j>left) {quick_sort(v, left, j);}
	if(i<right) {quick_sort(v, i, right);}
}
void insertionSort(int lista[], int quantidade)
{
	int i, j, aux, menorID;
	for(int i = 1; i < quantidade; i++)
	{
		aux = lista[i];
 		for(j = i - 1; j >= 0 && lista[j] > aux; j--)
        {
 			lista[j+1] = lista[j];
        }
		lista[j+1] = aux;
 	}
}
void selectionSort(int lista[], int quantidade)
{
	int i, j, aux, menorID;
	for(int i = 0; i < quantidade-1; i++)
    {
		menorID = i;
 		for(int j = i + 1; j < quantidade; j++)
        {
 			if(lista[j] < lista[menorID])
 				menorID = j;
 		}
        aux = lista[i];
        lista[i] = lista[menorID];
        lista[menorID] = aux;
    }
}
void bubble_sort(int v[], int n){
	int i, j, aux;
	for(i=n-1; i>=1; i--)
    {
		for(j=0; j<i; j++)
		{
			if(v[j] > v[j+1])
            {
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
        }
    }
}
void imprimir(int v[])
{
 int i;
 for(i=0; i< 100; i++)
 printf("%d ", v[i]);
 printf("\n");
}
