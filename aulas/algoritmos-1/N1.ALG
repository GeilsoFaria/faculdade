Algoritmo "n1"

Var
   N: vetor[1..12] de inteiro;  {Procesamento}
   X, VX, VY, S: inteiro;

Inicio


    Para X de 1 ate 10 faca  {Procesamento}
    Escreval ("Digite um n�mero para a posi��o ", X);{Sa�da}
    Leia(N[X]); {Entrada}
    Fimpara
    
    Escreval ("Qual o valor da posic�o X"); {Sa�da}
    Leia(VX); {Entrada}
    Escreval ("Qual o valor para a posic�o Y "); {Sa�da}
    Leia (VY); {Entrada}
    N[11] <- VX; {Procesamento}
    N[12] <- VY;
    S <-  VX + VY;
    
    Para X de 1 ate 12 faca {Procesamento}
    Escreval (N[X]); {Sa�da}
    Fimpara
    Escreval (" A soma de ", VX ," e ", VY , " ser� ", S); {Sa�da}

Fimalgoritmo