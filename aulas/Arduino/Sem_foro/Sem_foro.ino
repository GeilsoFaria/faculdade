#define led_vermelho 8
#define led_amarelo 9
#define led_verde 10


void setup() {
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT); 
}
void sinal_fechado(int tempo)
{
  digitalWrite(led_vermelho, HIGH);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_verde, LOW);
  delay(tempo);   
}
void aberto(int tempo)
{
  digitalWrite(led_vermelho, LOW);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_verde, HIGH);
  delay(tempo);   
}

void atencao(int tempo)
{
  digitalWrite(led_vermelho, LOW);
  digitalWrite(led_amarelo, HIGH);
  digitalWrite(led_verde, LOW);
  delay(tempo);   
}
void loop() 
{
  sinal_fechado(7000);
  
  aberto(9000);
  
  atencao(2000);
 
}
