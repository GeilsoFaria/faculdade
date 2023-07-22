Algoritmo "n1"

Var
   N: vetor[1..12] de inteiro;  {Procesamento}
   X, VX, VY, S: inteiro;

Inicio


    Para X de 1 ate 10 faca  {Procesamento}
    Escreval ("Digite um número para a posição ", X);{Saída}
    Leia(N[X]); {Entrada}
    Fimpara
    
    Escreval ("Qual o valor da posicão X"); {Saída}
    Leia(VX); {Entrada}
    Escreval ("Qual o valor para a posicão Y "); {Saída}
    Leia (VY); {Entrada}
    N[11] <- VX; {Procesamento}
    N[12] <- VY;
    S <-  VX + VY;
    
    Para X de 1 ate 12 faca {Procesamento}
    Escreval (N[X]); {Saída}
    Fimpara
    Escreval (" A soma de ", VX ," e ", VY , " será ", S); {Saída}

Fimalgoritmo