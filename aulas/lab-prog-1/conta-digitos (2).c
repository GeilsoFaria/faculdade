#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>

int contadigitos(int n, int d);

/* Parte (b) */
int main() {
  int a, b, d;
  int val;
  int perm; /* indicador de passagem: se perm == 1 e' permutacao */

  printf("Digite dois inteiros: ");
  scanf("%d %d",&a,&b);
  perm = 1;

  //for (d = 1; d <= 9; d++)
    //if (contadigitos(a,d) != contadigitos(b,d))
      perm = 0;
      val= contadigitos(a,b);
      printf("O valor aparece %d", val);
/*
  if (perm == 1)
    printf("%d e' permutacao de %d\n",a,b);
  else
    printf("%d nao e' permutacao de %d\n",a,b);

  return 0;*/
}
/* Parte (a) */
int contadigitos(int n, int d) {

  int conta, resto;

  conta = 0;

  while (n != 0) {
    resto = n % 10;
    n = n/10;
    printf("resto %d",resto);
    if (resto == d)
    {
      conta++;
    }
  }

  return conta;
}


