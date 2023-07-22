Algoritmo "Aposentadoria"

Var
   // Se��o de Declara��es das vari�veis
   Idade, tempo_contribuicao, sexo: Inteiro

Inicio
   // Se��o de Comandos, procedimento, fun��es, operadores, etc...
   escreva ("Digite a sua idade: ")
   leia(idade)
   escreva("Qual o seu tempo de contribui��o")
   leia(tempo_contribuicao)
   Escreva ("Qual o seu sexo? PARA M - Digite 1, PARA F - Digite 2")
   leia (sexo)


   escolha idade, tempo_contribuicao, sexo

   Caso 1
      idade >= 65
      tempo_contribuicao >= 15 sexo = 1
      escreva("Voc� j� pode se aposentar")
   caso 2
      idade >=  63 e tempo_contribuicao >= 10 e sexo = 1
      escreva"Voc� j� pode se aposentar
      Caso 3
         (idade >= 63)  e (tempo_contribuicao >= 10) e (sexo = 2)
         escreva("Voce j� pode se aposentar")
      Caso 4
         (idade >= 61) e (tempo_contribuicao >= 15) e (sexo = 2 )
         escreva ("Voc� j� pode se aposentar")

      Outrocaso
         escreva ("Voc� n�o pode se aposentar")

      Fimescolha

Fimalgoritmo