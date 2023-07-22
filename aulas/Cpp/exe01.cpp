#include <iostream>
#define pi 3.1415

using namespace std;

int restoDivPor2 ();
int areaCirculo();
int mediaArit3();
int volumeEsfera();

// SOMAR 2 NUMEROS REAIS
int main()
{
    float num1= 0.0,num2 = 0.0, soma=0.0;
    cout << "---- Somar 2 numeros reais ----" << endl;
    cout << "Digite o primeiro numero real" << endl;
    cin >> num1;
    cout << "Digite o segundo numero real" << endl;
    cin >> num2;
    soma = num1 + num2;
    cout << "A soma de " << num1 <<" e " << num2 << " eh: " << soma << endl;
    restoDivPor2();
    areaCirculo();
    mediaArit3();
    volumeEsfera();
    return 0;
}

//RESTO DA DIVISAO POR 2
int restoDivPor2()
{
    cout << "---- Resto da divisao por 2 ----" << endl;
    int num1=0, resto=0;
    cout << "Digite um numero inteiro" << endl;
    cin >> num1;
    resto = num1 % 2;
    cout << "O resto da divisao de " << num1 <<" por 2 eh " << resto << endl;
    return 0;
}

// AREA DO CIRCULO
int areaCirculo ()
{
    cout << "---- Area do Circulo ----" << endl;
    float raio = 0.0, area= 0.0;
    cout << "Digite o raio do circulo " << endl;
    cin >> raio;
    area= pi * (raio * raio) ;
    cout << "O raio " << raio <<" posssui area = " << area << endl;
    return 0;
}

// MEDIA ARITEMETICA ENTRE 3 NUMEROS
int mediaArit3()
{
    cout << "---- Media Aritmetica 3 numeros ----" << endl;
    float num1= 0.0,num2 = 0.0, num3 =0.0, media=0.0;
    cout << "Digite o primeiro numero real" << endl;
    cin >> num1;
    cout << "Digite o segundo numero real" << endl;
    cin >> num2;
    cout << "Digite o terceiro numero real" << endl;
    cin >> num3;
    media = (num1 + num2 + num3)/3;
    cout << "A media entre " << num1 <<" , " << num2 << " e "<< num3 << " eh: " << media << endl;
    return 0;
}

//  CALCULAR VOLUME DA ESFERA
int volumeEsfera()
{
    cout << "---- Volume esfera ----" << endl;
    float volumeEsfera=0.0, raio=0.0;
    cout << "Digite o raio da esfera " << endl;
    cin >> raio;
    volumeEsfera =(4 * pi *(raio * raio * raio))/3;
    cout << "O volume da esfera de " << raio << " eh= " << volumeEsfera << endl;
    return 0;
}
