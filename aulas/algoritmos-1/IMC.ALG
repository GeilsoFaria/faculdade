algoritmo "IMC"
// 
//  
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 16/09/2020
Var
// Seção de Declarações das variáveis 
    Peso, Altura, IMC: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   Escreva("Qual o seu peso em Kg? ")
   Leia(Peso)
   Escreva("Qual a sua Altura em metros? ")
   Leia (Altura)
   IMC<- Peso/(Altura^2)
   Escreva("IMC: ", IMC)
   Se(IMC>17)e (IMC<18) entao
   Escreva("Você está abaixo do peso")
   senao
      Se (IMC > 18) e (IMC < 24.5)entao
      Escreva("Seu peso é normal")
      senao
           Se (IMC > 24.5) e (IMC < 30) entao
           escreva("Você está acima do peso")
           Senao
                Se (IMC > 30) e (IMC < 40) entao
                escreva("Você está Obeso")
                Senao
                     Se (IMC > 40)entao
                     escreva ("Você está em Obesidade MÓRBIDA")
                     Fimse
                Fimse

             Fimse
      Fimse
   Fimse

   
Fimalgoritmo
