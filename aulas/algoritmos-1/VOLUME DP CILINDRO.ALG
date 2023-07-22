Algoritmo "Volume da Lata"

Var
 Raio_da_Base, Area_da_Base,Volume,Altura: Real;
 Const pi:3.14


Inicio

    P<-3.14 ;
    Escreva("Digite o Raio da Base: ");
      Leia (Raio_da_Base);
    Area_da_Base<- (Raio_da_Base^2)* Pi;
    Escreva ("Digite a altura do cilindro: ") ;
      Leia (Altura)
    Volume<- Area_da_Base * Altura ;
    Escreva ("O volume do Cilindro será", Volume);

Fimalgoritmo