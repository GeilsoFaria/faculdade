#include<stdio.h>//Geilso Faria 24/10
#include <locale.h>
#include <stdlib.h>
int main(){
    setlocale(LC_ALL, "Portuguese");
    int idade, opiniao, entrevistados, idademv;
    int opruim = 0;
    int opessimo = 0;
    int opbom;
    float salario, medsalreg;
    printf("Quantas pessoas participar�o da Entrevista");
    scanf("%d", &entrevistados);

    while((entrevistados >1 )&&(entrevistados<entrevistados))
        entrevistados = entrevistados ++;
        {
        printf("Qual a sua idade");
        scanf("%d", &idade);
        if (idade > idademv)
        {
        idademv: idade;
        }

        printf("Qual o seu sal�rio");
        scanf("%f", &salario);
        printf("Qual a sua opini�o ");
        printf("Para EXCELENTE digite 5\n");
        printf("Para BOM digite 4\n");
        printf("Para REGULAR digite 3\n");
        printf("Para RUIM digite 2\n");
        printf("Para P�SSIMO digite 1\n");
        scanf("%d", &opiniao);
        }

        switch (opiniao)
        {
        case 1:
            opessimo= opessimo + 1;
            printf ("A quantidade de Pessoas que responderam P�SSIMO foi %d\n", opessimo);
            break;
        case 2:
            opruim = opruim + 1;
            printf ("A quantidade de Pessoas que responderam RUIM foi %d\n", opruim);
            break;
        case 3:
            medsalreg = medsalreg/ salario;
            printf ("A m�dia do sal�rio de Pessoas que responderam REGULAR foi %f\n", medsalreg);
            break;
        case 4:
            opbom = opbom / 100;
            ("A porcentagem de Pessoas que responderam BOM foi %d\n", opbom);
            break;
        case 5:
            printf("A idade da pessoa mais velha a responde EXCELENTE foi %d\n", idademv);
            break;
        }

    }







