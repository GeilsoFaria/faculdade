Algoritmo "Carro"
// 
//  
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 09/09/2020
Var
// Seção de Declarações das variáveis 
 Litros_combustivel, autonomia, VM, Tempo_gasto, distancia: Real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   autonomia<- 10
   Tempo_gasto<- 1.5
   Escreva("Defina a distância em KM percorrida ")
   Leia (distancia)
   VM<- distancia/Tempo_gasto
   Escreval("A sua velocidade Média foi", VM, " Km/H")
   Escreval ("O tempo de sua viagem foi ", Tempo_gasto , " Hora")
   Escreval("A distância percorrida foi", distancia , " KM")
   Litros_Combustivel<- distancia/autonomia
   Escreval("Nessa viagem foi usado", Litros_combustivel, " litros de combustível ")

Fimalgoritmo