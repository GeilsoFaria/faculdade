#include<stdio.h>//Geilso Faria 17/10
#include <locale.h>
#include <stdlib.h>
int main(){
    setlocale(LC_ALL, "Portuguese");
    int valor;
    float ir;
    printf ("Qual o valor de sua Renda Anual");
    scanf("%d", &valor);
    if (valor < 22000)
    {
        printf("Você está ISENTO");
    }
    else
    {
        if ( (valor >= 22000) && (valor <= 33000))
		{
            ir = valor * 7.5/100;
            printf("Pagará de IR %f", ir);
        }
        else{
            if ( (valor >= 33000) && (valor <= 45000))
            {
                ir = valor * 12.5/100;
                printf("Pagará de IR %f", ir);
            }
            else{

                if((valor>= 45000)&& (valor <= 55900))
                    {ir = valor * 22.5/100;
                    printf("Pagará de IR %f", ir);
                }
                 else{
                    if (valor > 55900)
                       {
                        ir = valor * 27.5;
                        printf ("Pagará de IR, %f", ir);
                       }
            }

            }
            }
    }

    }







