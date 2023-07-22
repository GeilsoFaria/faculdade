#include <stdio.h>

/* Parte (a) */
int contadigitos(int n, int d) {

  int conta, resto;

  conta = 0;

  while (n != 0) {
    resto = n % 10;
    n = n/10;
    if (resto == d)
      conta++;
  }

  return conta;
}

/* Parte (b) */
int main() {
  int a, b, d;
  int perm; /* indicador de passagem: se perm == 1 e' permutacao */

  printf("Digite dois inteiros: ");
  scanf("%d %d",&a,&b);
  perm = 1;

  for (d = 1; d <= 9; d++)
    if (contadigitos(a,d) != contadigitos(b,d))
      perm = 0;
      printf("%d", conta);

  if (perm == 1)
    printf("%d e' permutacao de %d\n",a,b);
  else
    printf("%d nao e' permutacao de %d\n",a,b);

  return 0;
}
