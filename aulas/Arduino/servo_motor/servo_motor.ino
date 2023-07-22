#include <Servo.h>


#define pot A0

Servo s1; //Declarando o servo motor

int angs1; //Variável para ângulo do servo motor


void setup()
{
  s1.attach(3);//Passando a porta do arduino para o Servo Motor
  angs1=0;
  s1.write(angs1);//Inicializando o ângulo do motor em 0
  pinMode(pot, INPUT);
}

void loop() 
{
  angs1= map(analogRead(pot), 0,1023,0,180);//Usando a função map para passar o angulo com o potenciômetro
  s1.write(angs1);
  delay(100);

}
