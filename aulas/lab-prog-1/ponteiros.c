#include <stdio.h>
#include <stdlib.h>


void mult5 (int *num1, int *num2){

    for( *num1>= *num2  ; *num1 <= *num2 ; *num1= *num1+ 5 ) {
        if (*num1 % 5 != 0){
            do {
                *num1 = *num1+ 1;
            }while (*num1 % 5 != 0);
        }
        printf("%d\n", *num1);
     }
    }
int main (){
    int n1, n2;


    printf(" Digite o primeiro número\n ");
    scanf("%d", &n1);
    printf(" Digite o segundo número\n ");
    scanf("%d", &n2);
    mult5(&n1,&n2);




    system("pause");
    return 0;
}
