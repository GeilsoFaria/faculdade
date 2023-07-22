Algoritmo "Questao1"

Var

   numeros_A: vetor[1..10] de inteiro; {Processamento de Dados}
   indice_A, V1020: inteiro ;{Processamento de Dados}

   numeros_B: vetor[1..10] de inteiro ; {Processamento de Dados}


Inicio
   Para indice_A de 1 ate 10 faca {Processamento de Dados}
      Escreval ("Qual o valor para a posição", indice_A, " do vetor"){Saída de Dados}
      Leia (numeros_A[indice_A]) {Entrada de Dados}
   Fimpara

   Para indice_A de 1 ate 10 faca {Processamento de Dados}
      Escreval("A posicao " , indice_A, " do vetor terá valor", numeros_A[indice_A]){Saída de Dados}
      Se(numeros_A[indice_A]>= 10) e(numeros_A[indice_A]<=20) entao {Processamento de Dados}
         V1020 <- V1020 + 1  {Processamento de Dados}
      Fimse
   Fimpara



   numeros_B[1] <- numeros_A[10]; {Processamento de Dados}
   Escreval("A posicao do vetor B[1] será de; ", numeros_B[1]);{Saída de Dados}
   numeros_B[2] <- numeros_A[9]; {Processamento de Dados}
   Escreval("A posicao do vetor B[2] será de; ", numeros_B[2]);{Saída de Dados}
   numeros_B[3] <- numeros_A[8]; {Processamento de Dados}
   Escreval("A posicao do vetor B[3] será de; ", numeros_B[3]);{Saída de Dados}
   numeros_B[4] <- numeros_A[7]; {Processamento de Dados}
   Escreval("A posicao do vetor B[4] será de; ", numeros_B[4]);{Saída de Dados}
   numeros_B[5] <- numeros_A[6] ; {Processamento de Dados}
   Escreval("A posicao do vetor B[5] será de; ", numeros_B[5]);{Saída de Dados}
   numeros_B[6] <- numeros_A[5]; {Processamento de Dados}
   Escreval("A posicao do vetor B[6] será de; ", numeros_B[6]);{Saída de Dados}
   numeros_B[7] <- numeros_A[4];  {Processamento de Dados}
   Escreval("A posicao do vetor B[7] será de; ", numeros_B[7]);{Saída de Dados}
   numeros_B[8] <- numeros_A[3];  {Processamento de Dados}
   Escreval("A posicao do vetor B[8] será de; ", numeros_B[8]);{Saída de Dados}
   numeros_B[9] <- numeros_A[2]; {Processamento de Dados}
   Escreval("A posicao do vetor B[9] será de; ", numeros_B[9]);{Saída de Dados}
   numeros_B[10] <- numeros_A[1]  {Processamento de Dados}
   Escreval("A posicao do vetor B[10] será de; ", numeros_B[10]) ;{Saída de Dados}

   Escreval("Foram Digitados ", V1020, " valores entre 10 e 20");  {Saída de Dados}

Fimalgoritmo