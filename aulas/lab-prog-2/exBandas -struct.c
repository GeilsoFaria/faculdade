#include <stdio.h>
#include <string.h>

typedef struct
{
    char nomeBanda[25];
    char genero[20];
    int  numIntegrantes;
    int  rankFavoritas;

}banda;

banda Banda[5];//Instaciamento do vetor com 5 posições

int verBanda();//Protótipo

void tipoMusica(banda b[]);

void verFavorita(banda b[]);

int main()
{
    banda b;
    int i;
    char escolha;

    printf("Digite 5 bandas favoritas e suas especifações\n");
    //Lê os dados
    for(int i=0;i<5;i++)
    {
        printf("Nome da banda(sem espacos)\n");
        scanf("%s*c",&Banda[i].nomeBanda);

        printf("Genero\n");
        scanf("%s*c",&Banda[i].genero);

        printf("Numero de Integrantes\n");
        scanf("%d*c",&Banda[i].numIntegrantes);

        printf("Lugar no Ranking de suas 5 favoritas\n");
        scanf("%d*c",&Banda[i].rankFavoritas);


    }
    //Exibe os dados
    for(int i=0;i<5;i++)
    {
        printf("Nome da banda: %s\n", Banda[i].nomeBanda);
        printf("Genero: %s\n", Banda[i].genero);
        printf("Numero de integrantes: %d\n", Banda[i].numIntegrantes);
        printf("Lugar no Ranking: %d º\n", Banda[i].rankFavoritas);
    }

    printf("Para ver uma a banda esta entre as favoritas digite 'v\n");
    printf("Para ver se o seu genero esta entre os favoritos digite 'g\n");
    printf("Para ver se se a banda eh uma da favoritas digite 'f\n");
    scanf("%s", &escolha);
    switch(escolha)
    {
    case 'v':
        verBanda();//chamada da função verBanda
        break;
    case 'g':
        tipoMusica(Banda); //chamada da função tipoMusica
        break;
    case 'f':
        verFavorita(Banda);//chamada da função verFavorita
        break;
    }
    return 0;
}
//função para ver a banda na posição desejada
int verBanda()
{
    int posicao;

    printf("Digite uma posicao de 1 a 5\n");
    scanf("%d", &posicao);

    printf("Nome da banda: %s\n", Banda[posicao-1].nomeBanda);
    printf("Genero: %s\n", Banda[posicao-1].genero);
    printf("Numero de integrantes: %d\n", Banda[posicao-1].numIntegrantes);
    printf("Lugar no Ranking: %d º\n", Banda[posicao-1].rankFavoritas);

}
//função para buscar generos
void tipoMusica(banda b[])
{
    int retorno, i;
    char genero[20];

    printf("Digite um genero favorito\n");
    scanf("%s",&genero);
    for(i=0;i<5;i++)
    {
        retorno= strcmp(genero, b[i].genero);
        if(retorno==0)
        {
            printf("Nome Banda: %s\n", b[i].nomeBanda);
        }
    }
}
void verFavorita(banda b[])
{
    char nome_banda[20];
    int retorno,i;

    printf("Digite o nome de uma banda\n");
    scanf("%s",&nome_banda);
    for(i=0;i<5;i++)
    {
        retorno= strcmp(nome_banda, b[i].nomeBanda);
        if(retorno==0)
        {
            printf("Eh uma banda favorita");
        }
    }
}

