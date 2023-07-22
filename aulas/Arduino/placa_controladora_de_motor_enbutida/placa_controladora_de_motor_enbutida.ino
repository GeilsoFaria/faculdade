#include <AFMotor.h>

AF_DCMotor motor(1); //Definindo motor para passar como parâmetro

void setup() 
{
  motor.setSpeed(0);//Declarando motor

}

void loop() 
{
  motor.setSpeed(255);//Velocidade Máxima
  motor.run(FORWARD);//Girando no sentido horário do motor
  delay(5000);

  motor.setSpeed(0);//Velocidade Minima
  motor.run(RELEASE);//Desligando o motor
  delay(250);

  motor.setSpeed(255);//Velocidade Máxima
  motor.run(BACKWARD);//Girando no sentido anti- horário do motor
  delay(5000);

  motor.setSpeed(0);//Velocidade Minima
  motor.run(RELEASE);//Desligando o motor
  delay(250);
  
}
