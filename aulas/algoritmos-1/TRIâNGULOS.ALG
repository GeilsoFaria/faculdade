Algoritmo "Tri�ngulos"
// 
//  
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 09/09/2020
Var
// Se��o de Declara��es das vari�veis 
   L1, L2, L3: Real;
   EQ, ES, TRI : logico;

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   Escreva("Digite o Primeiro Lado: ")
   Leia (L1)
   Escreva("Digite o Segundo Lado: ")
   Leia (L2)
   Escreva("Digite o Terceiro Lado: ")
   Leia (L3)
   TRI<- (L1 < L2 + L3) e (L2 < L1 + L3) e (L3 < L1 + L2)
   EQ<- (L1=L2) e (L2=L3)
   ES<- (L1<>L2) e (L2<>L3) e (L1<>L3)
   Escreval ("Se Trata de um TRI�NGULO ", TRI)
   Escreval ("O Tri�ngulo � EQUIL�TERO ", EQ)
   Escreva ("O Tri�ngulo � ESCALENO ", ES)

Fimalgoritmo