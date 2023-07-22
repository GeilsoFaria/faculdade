Algoritmo "Soma10n"
// 
//  
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 22/09/2020
Var
// Seção de Declarações das variáveis 
  contador, N, Soma, MV: inteiro
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
    contador <- 1
    Soma <- 0
    Enquanto (contador <= 5) faca
        Escreval("Qual o" , contador, "º valor")
        Leia (N)
        Se(N > MV) entao
        MV <- N
        Fimse
        Soma <- Soma + N
        contador <- contador + 1
    Fimenquanto
    Escreval("A soma será de ", Soma )
    Escreval ("O maior foi de " , MV)

Fimalgoritmo