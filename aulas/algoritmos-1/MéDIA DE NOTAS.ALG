Algoritmo "Carro"
// 
//  
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 09/09/2020
Var
// Se��o de Declara��es das vari�veis 
 Litros_combustivel, autonomia, VM, Tempo_gasto, distancia: Real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   autonomia<- 10
   Tempo_gasto<- 1.5
   Escreva("Defina a dist�ncia em KM percorrida ")
   Leia (distancia)
   VM<- distancia/Tempo_gasto
   Escreval("A sua velocidade M�dia foi", VM, " Km/H")
   Escreval ("O tempo de sua viagem foi ", Tempo_gasto , " Hora")
   Escreval("A dist�ncia percorrida foi", distancia , " KM")
   Litros_Combustivel<- distancia/autonomia
   Escreval("Nessa viagem foi usado", Litros_combustivel, " litros de combust�vel ")

Fimalgoritmo