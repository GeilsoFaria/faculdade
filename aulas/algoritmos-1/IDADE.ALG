Algoritmo "Idade"
//
//
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 11/09/2020
Var
   // Seção de Declarações das variáveis
 ano, nascimento, idade: inteiro

Inicio
   // Seção de Comandos, procedimento, funções, operadores, etc...
        Escreva (" Em que ano estamos ")
   Leia (ano)
        Escreva (" Em que ano você nasceu ")
   Leia (nascimento)
   Idade<- ano - nascimento
        Escreval(" A sua idade será de", Idade, "Anos em ", ano)

   Se( Idade >= 18) Então
       Escreval (" Você já será maior de Idade, em", ano)
   Senão
        Escreval (" Você ainda estará sobre a responsabilidade de seus pais em", ano)
   FimSe

Fimalgoritmo