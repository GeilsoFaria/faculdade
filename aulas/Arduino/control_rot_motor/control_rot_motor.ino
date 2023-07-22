# define pot A0
# define motor 2
# define tempo 10
void setup() {
  pinMode (pot, INPUT);
  pinMode (motor, OUTPUT);
}

void loop() {
  analogWrite(motor, map(analogRead(pot),0,1023,0,255));
  delay(tempo);
 
}
