#include <HCSR04.h>
#define p_trigger 4
#define p_echo 5

UltraSonicDistanceSensor distanceSensor ( p_trigger, p_echo); // Inicializar sensor que usa pinos digitais 4 e 5.


float dist_cm, dist_m;

void setup()
{
  Serial.begin(9600);

}

void loop()
{
  dist_cm = distanceSensor.measureDistanceCm();
  dist_m =  dist_cm / 100;
  Serial.print("Distancia");
  Serial.println(dist_cm);
  Serial.print("cm");
  Serial.print("Distancia");
  Serial.println(dist_m);
  Serial.println("m");
  Serial.println("-------------------------------------");
  delay(1000);


}
