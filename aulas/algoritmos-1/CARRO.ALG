Algoritmo "Carro"

Var

 Litros_combustivel, autonomia, VM, Tempo_gasto, distancia: Real

Inicio

   Escreva("Defina a dist�ncia em KM percorrida ");{Sa�da de Dados}
          Leia (distancia) ;{ Entrada de dados}
   autonomia<- 10; {Processamento de Dados}
   Tempo_gasto<- 1.5; {Processamento de Dados}
   VM<- distancia/Tempo_gasto ;{Processamento de Dados}
   Escreval("A sua velocidade M�dia foi", VM, " Km/H");{Sa�da de Dados}
   Escreval ("O tempo de sua viagem foi ", Tempo_gasto , " Hora"); {Sa�da de Dados}
   Escreval("A dist�ncia percorrida foi", distancia , " KM"); {Sa�da de Dados}
   Litros_Combustivel<- distancia/autonomia; {Processamento de Dados}
   Escreval("Nessa viagem foi usado", Litros_combustivel, " litros de combust�vel "); {Sa�da de Dados}

Fimalgoritmo