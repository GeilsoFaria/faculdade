#include <Stepper.h>

#define e1 8 //Defindo portas do arduino
#define e2 9
#define e3 10
#define e4 11
#define passosPorGiro 64 // Quantidade de passos para um giro do motor
#define led 13
int i;

Stepper mp(passosPorGiro,e1,e3,e2,e4);//Passo os parametros

void setup() 
{ 
  pinMode (led, OUTPUT);
}

void loop() 
{
  digitalWrite(led, LOW);
  motor(500, 1,1,500,5);
  digitalWrite(led, HIGH);
  delay(3000);
  digitalWrite(led, LOW);
  motor(500, -1,1,500,5);
  digitalWrite(led, HIGH);
  delay(3000);
   
 
}
void motor(int vel, int sentido,int voltas, int tmp)
{
   mp.setSpeed(vel); //Quantidade de Rotações por minuto
   for(i=0;i<(32 * voltas);i++)
  {
    mp.step(passosPorGiro * sentido); //Método step dá um passo no motor , -1 anti-horário 1 horário
  }
   delay(tmp);
}
void motor(int vel, int sentido,int voltas, int tmp, int passos)
{
   mp.setSpeed(vel); //Quantidade de Rotações por minuto
   for(i=0;i<(passos * voltas);i++)
  {
    mp.step(passosPorGiro * sentido); //Método step dá um passo no motor , -1 anti-horário 1 horário
    delay(tmp);
  }
   delay(tmp * 2);
}
