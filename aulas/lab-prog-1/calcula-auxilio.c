#include <stdlib.h>//Geilso Faria 24/10

#include <stdio.h>

#include <locale.h>



int main() {

    setlocale(LC_ALL, "Portuguese");

    float rendap, rendaf, custo, gastotot;

    int resp, quantalun, alunos, porcalun ;

    printf ("Qual a sua renda Pessoal? ");

    scanf ("%f", &rendap);

    printf ("Qual a sua renda familiar? ");

    scanf ("%f", &rendaf);

    do {

        switch(rendap)
        case (rendap <=522.50):
        if (rendaf<= 3135)
        printf ("Você terá direito ao auxílio de RS 200,00\n");
        default
        rintf ("Você NÃO terá direito ao auxílio\n");


    printf ("Quantos alunos a Universidade Possui?\n");

    scanf ("%d", &alunos);

    quantalun= quantalun +1;

    custo = quantalun * 200;

    porcalun  =(alunos - quantalun) /100;

    printf ("O CUSTO será de %f\n", custo);



    printf ("Para CONTINUAR digite 1, para SAIR digite 2");

    scanf ("%d", &resp);

    }

    } while (resp != 2);



      printf ("Total de Alunos  %d\n", alunos);

      printf ("A PORCENTAGEM de alunos foi de: %d\n");

    return 0;





}

