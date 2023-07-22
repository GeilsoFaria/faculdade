#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void contando (int*n1, int*n2){
    if (*n1 % 5 ==0)
       {
    for (int cont = 0; cont <= *n2 ; cont + 5){

    printf ("%d\n", cont);

    }

    }else{
        if (*n1 % 5 !=0){
    for (int cont = 0; cont <= *n2; cont + 5){

    printf("%d\n", cont);

    }

    }

    }
    }


int main (){
    setlocale(LC_ALL, "Portuguese");
    int  n1, n2;
    printf("Digite dois números");
    scanf("%d%d", &n1, &n2);
    contando(&n1,&n2);
    system("pause");
    return 0;
}
