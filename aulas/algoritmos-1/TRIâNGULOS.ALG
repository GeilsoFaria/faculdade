Algoritmo "Triângulos"
// 
//  
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 09/09/2020
Var
// Seção de Declarações das variáveis 
   L1, L2, L3: Real;
   EQ, ES, TRI : logico;

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   Escreva("Digite o Primeiro Lado: ")
   Leia (L1)
   Escreva("Digite o Segundo Lado: ")
   Leia (L2)
   Escreva("Digite o Terceiro Lado: ")
   Leia (L3)
   TRI<- (L1 < L2 + L3) e (L2 < L1 + L3) e (L3 < L1 + L2)
   EQ<- (L1=L2) e (L2=L3)
   ES<- (L1<>L2) e (L2<>L3) e (L1<>L3)
   Escreval ("Se Trata de um TRIÂNGULO ", TRI)
   Escreval ("O Triângulo é EQUILÁTERO ", EQ)
   Escreva ("O Triângulo é ESCALENO ", ES)

Fimalgoritmo