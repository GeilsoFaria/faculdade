algoritmo "IMC"
// 
//  
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 16/09/2020
Var
// Se��o de Declara��es das vari�veis 
    Peso, Altura, IMC: real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   Escreva("Qual o seu peso em Kg? ")
   Leia(Peso)
   Escreva("Qual a sua Altura em metros? ")
   Leia (Altura)
   IMC<- Peso/(Altura^2)
   Escreva("IMC: ", IMC)
   Se(IMC>17)e (IMC<18) entao
   Escreva("Voc� est� abaixo do peso")
   senao
      Se (IMC > 18) e (IMC < 24.5)entao
      Escreva("Seu peso � normal")
      senao
           Se (IMC > 24.5) e (IMC < 30) entao
           escreva("Voc� est� acima do peso")
           Senao
                Se (IMC > 30) e (IMC < 40) entao
                escreva("Voc� est� Obeso")
                Senao
                     Se (IMC > 40)entao
                     escreva ("Voc� est� em Obesidade M�RBIDA")
                     Fimse
                Fimse

             Fimse
      Fimse
   Fimse

   
Fimalgoritmo
