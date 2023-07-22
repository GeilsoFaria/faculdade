Algoritmo "Leiaquinze"
// 
//  
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 25/09/2020
Var
// Seção de Declarações das variáveis 
 Quant: inteiro
 N, Resu: Real
 Resposta: caractere

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   Para Quant de 1 ate 15 faca
   Escreval ("Deseja saber a raiz de qual número")
   Leia(N)
   Resu <- RaizQ(N)
   Escreval("O resultado será de:", Resu)
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
   Escreval ("Deseja saber a raiz de qual número")
   Leia(N)
   Resu <- RaizQ(N)
   Escreval("O resultado será de:", Resu)
   Fimenquanto

Fimalgoritmo