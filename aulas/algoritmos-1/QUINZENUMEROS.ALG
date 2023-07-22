Algoritmo "QuinzeNumeros"
// 
//  
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 23/09/2020
Var
// Seção de Declarações das variáveis 
   QuantN , N, Resultado : real
   Resp : caractere

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc...
   Para QuantN <- 0 ate 5  faca
   Escreva ("Deseja Saber a Raiz de Qual Número" )
   Leia (N)
   Resultado <- RaizQ(N)
   Escreval ("A raiz quadrada será de:" , Resultado)
   FimPara


   Repita
   Escreva ("Deseja continuar [S/N]? ")
   Leia(Resp)
   Ate (Resp = "S")

   QuantN <- 5
   Enquanto (QuantN <= 10) faca
   Escreval ("Deseja saber a raiz de qual número? ")
   Leia(N)
   Resultado <- RaizQ(N)
   Escreval("O resultado será de: ", Resultado)
   QuantN <- QuantN + 1
   FimEnquanto

Fimalgoritmo