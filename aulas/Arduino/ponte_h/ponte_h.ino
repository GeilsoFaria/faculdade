#define velm1 3
#define m1a 2
#define m1b 4
#define tempo 4000
#define vel 255
void setup()

{
 pinMode(velm1, OUTPUT);
 pinMode(m1a, OUTPUT);
 pinMode(m1b, OUTPUT);  

 analogWrite(velm1, 0);
 digitalWrite(m1a, LOW);
 digitalWrite(m1b, LOW);

}

void loop() 
{
  analogWrite(velm1, vel);
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  delay(tempo);

  analogWrite(velm1, 0);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  delay(100);
  
  analogWrite(velm1, vel);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  delay(tempo);
    
  

}
