Algoritmo "Soma10n"
// 
//  
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 22/09/2020
Var
// Se��o de Declara��es das vari�veis 
  contador, N, Soma, MV: inteiro
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
    contador <- 1
    Soma <- 0
    Enquanto (contador <= 5) faca
        Escreval("Qual o" , contador, "� valor")
        Leia (N)
        Se(N > MV) entao
        MV <- N
        Fimse
        Soma <- Soma + N
        contador <- contador + 1
    Fimenquanto
    Escreval("A soma ser� de ", Soma )
    Escreval ("O maior foi de " , MV)

Fimalgoritmo