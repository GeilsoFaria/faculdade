Algoritmo "QuinzeNumeros"
// 
//  
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 23/09/2020
Var
// Se��o de Declara��es das vari�veis 
   QuantN , N, Resultado : real
   Resp : caractere

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc...
   Para QuantN <- 0 ate 5  faca
   Escreva ("Deseja Saber a Raiz de Qual N�mero" )
   Leia (N)
   Resultado <- RaizQ(N)
   Escreval ("A raiz quadrada ser� de:" , Resultado)
   FimPara


   Repita
   Escreva ("Deseja continuar [S/N]? ")
   Leia(Resp)
   Ate (Resp = "S")

   QuantN <- 5
   Enquanto (QuantN <= 10) faca
   Escreval ("Deseja saber a raiz de qual n�mero? ")
   Leia(N)
   Resultado <- RaizQ(N)
   Escreval("O resultado ser� de: ", Resultado)
   QuantN <- QuantN + 1
   FimEnquanto

Fimalgoritmo