#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float media (int x, int y){
    float soma ;
    int cont =13;
    for (cont = x; cont <= y; cont ++){
        soma += cont;
    }
    return soma/60;

}
int main(){
    int n1=13;
    int n2 =73;
    float m;

    m = media(n1,n2);
    printf("%f ", m);

    system("pause");
    return 0;
}
