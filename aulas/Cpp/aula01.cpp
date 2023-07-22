#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, soma, sub, div, mult, mod, teste, numero;
    a = 5;
    b = 6;
    soma=a+b;
    sub=a-b;
    div=a/b;
    mult=a*b;
    mod=a%b;
    teste = 2;
    //teste++;
    teste--;
    c= a++;
    d= ++b;

    cout << "Hello World" << endl;

    /*Testando expresoes aritmeticas*/
    cout << "Soma = " << soma << endl;
    cout << "Subtracao = " << sub << endl;
    cout << "Divisao = " << div << endl;
    cout << "Multiplicacao = " << mult << endl;
    cout << "Resto da divisao = " << mod << endl;

    /*Testando incremento*/
    cout << "teste= " << teste << endl;
    cout << "C= " << c << endl;
    cout << "D= " << d << endl;

    /*E/S*/

    cout << "Digite um numero inteiro" << endl;
    cin >> numero;

    numero++;
    cout << " O sucessor do numero eh " << numero << endl;

    return 0;
}
