#include <stdio.h>
#include <stdlib.h>


int main(){

    int matriz [5][3] ={};
   


   printf(" Digite 15 valores para uma matriz  5x3 \n ");
   
    for (int i = 0 ; i < 5; i++){
        for (int j = 0; j < 3; j++){

        scanf("%d", &matriz[i][j]);
    }
}

     for (int i=0 ; i < 5; i++){
        for (int j= 0; j < 3; j++){

         printf("%d ", matriz[i][j]) ;
        }
        printf("\n");
     }
     



    system("pause");
    return 0;
}
