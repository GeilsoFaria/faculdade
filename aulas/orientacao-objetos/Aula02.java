package com.mycompany.aula02;

public class Aula02 
{
    public static void main(String[] args)
    {
        Caneta c1 = new Caneta();
        c1.cor= "Azul";
        c1.ponta=0.5f;
        c1.modelo="Bicx";
        c1.carga=99;
        c1.tampar();
        c1.status(); 
        c1.rabiscar();
        System.out.println("---------------------------------");
        c1.destampar();
        c1.status(); 
        c1.rabiscar();
    }
}
