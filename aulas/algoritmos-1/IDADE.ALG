Algoritmo "Idade"
//
//
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 11/09/2020
Var
   // Se��o de Declara��es das vari�veis
 ano, nascimento, idade: inteiro

Inicio
   // Se��o de Comandos, procedimento, fun��es, operadores, etc...
        Escreva (" Em que ano estamos ")
   Leia (ano)
        Escreva (" Em que ano voc� nasceu ")
   Leia (nascimento)
   Idade<- ano - nascimento
        Escreval(" A sua idade ser� de", Idade, "Anos em ", ano)

   Se( Idade >= 18) Ent�o
       Escreval (" Voc� j� ser� maior de Idade, em", ano)
   Sen�o
        Escreval (" Voc� ainda estar� sobre a responsabilidade de seus pais em", ano)
   FimSe

Fimalgoritmo