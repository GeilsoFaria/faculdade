Algoritmo "Leiaquinze"
// 
//  
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 25/09/2020
Var
// Se��o de Declara��es das vari�veis 
 Quant: inteiro
 N, Resu: Real
 Resposta: caractere

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   Para Quant de 1 ate 15 faca
   Escreval ("Deseja saber a raiz de qual n�mero")
   Leia(N)
   Resu <- RaizQ(N)
   Escreval("O resultado ser� de:", Resu)
   Fimpara
   
   Enquanto Quant >= 15 faca
   Repita
   Escreval("Deseja continuar [S/N] ")
   Leia (Resposta)
        Se (Resposta= "N") entao
        Escreval("Terminamos Por Aqui, OBRIGADO! ")
        Fimalgoritmo
        Fimse
   Ate (Resposta = "S")
   Escreval ("Deseja saber a raiz de qual n�mero")
   Leia(N)
   Resu <- RaizQ(N)
   Escreval("O resultado ser� de:", Resu)
   Fimenquanto

Fimalgoritmo