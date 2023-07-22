#include <stdio.h>

typedef struct
{
    char nome[25];
    char cpf[11];
    char part;
    char socio;

}cadastro_part;

int val_erbase(char aux);

int main()
{
    cadastro_part c;
    char aux;

    printf("Nome(sem espacos)\n");
    scanf("%s*c",&c.nome);

    printf("CPF(sem espacos)\n");
    scanf("%s*c",&c.cpf);

    printf("Tipo de participacao 'a', 'b', 'c', 'd' \n");
    scanf("%s*c",&c.part);
    aux= c.part;

    printf("eh socio Sim's', Nao'n'\n");
    scanf("%s*c",&c.socio);

    val_erbase(aux);

    return 0;

}

int val_erbase(char aux)
{
    int val_curso=0;

    switch(aux)
    {
        case'a':
            val_curso=30;
            printf("Em 1 curso vc pagara %d reais\n", val_curso);
            return val_curso;
            break;
        case'b':
            val_curso=60;
            printf("Em 2 cursos vc pagara %d reais\n", val_curso);
            return val_curso;
            break;
        case'c':
            val_curso=90;
            printf("Em 3 cursos vc pagara %d reais\n", val_curso);
            return val_curso;
            break;
        case'd':
            val_curso=100;
            printf("Em 4 cursos vc pagara %d reais\n", val_curso);
            return val_curso;
            break;
    }
}


