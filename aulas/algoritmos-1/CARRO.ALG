Algoritmo "Carro"

Var

 Litros_combustivel, autonomia, VM, Tempo_gasto, distancia: Real

Inicio

   Escreva("Defina a distância em KM percorrida ");{Saída de Dados}
          Leia (distancia) ;{ Entrada de dados}
   autonomia<- 10; {Processamento de Dados}
   Tempo_gasto<- 1.5; {Processamento de Dados}
   VM<- distancia/Tempo_gasto ;{Processamento de Dados}
   Escreval("A sua velocidade Média foi", VM, " Km/H");{Saída de Dados}
   Escreval ("O tempo de sua viagem foi ", Tempo_gasto , " Hora"); {Saída de Dados}
   Escreval("A distância percorrida foi", distancia , " KM"); {Saída de Dados}
   Litros_Combustivel<- distancia/autonomia; {Processamento de Dados}
   Escreval("Nessa viagem foi usado", Litros_combustivel, " litros de combustível "); {Saída de Dados}

Fimalgoritmo