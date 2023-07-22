#include <stdio.h>

typedef struct
{
    char rua[25];
    char cidade[20];
    char estado[2];
    char cep[8];

}Endereco;

typedef struct
{
    Endereco endereco;
    char nome[15];
    char sobrenome[15];



}aluno;

int main()
{
    aluno a;
    Endereco f;

    printf("Nome da rua(sem espacos)\n");
    scanf("%s",f.rua);

    printf("Cidade\n");
    scanf("%s",f.cidade);

    printf("Estado\n");
    scanf("%s",f.estado);

    printf("CEP\n");
    scanf("%s",f.cep);

    printf("Nome(sem espacos)\n");
    scanf("%s",a.nome);

    printf("sobrenome\n");
    scanf("%s",a.sobrenome);

    printf("%s\n %s\n %s\n %s\n %s\n %s\n",f.rua,f.cidade,f.estado,f.cep,a.nome,a.sobrenome);

    return 0;
}


