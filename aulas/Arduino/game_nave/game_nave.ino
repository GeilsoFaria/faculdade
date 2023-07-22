#include <LiquidCrystal.h>

#define btnbaixo 8
#define btncima 9
#define bttiro 10

LiquidCrystal lcd (7, 6, 5, 4, 3, 2);

int vel = 100;
int pxnave, pynave, pxaste, pyaste, pxenergia, pyenergia, pxtiro, pytiro;
bool game, vtiro, vpilha;
int pontos;
double venergia;

byte nave[8] = {B10000, B01000, B01100, B01111, B01111, B01100, B01000, B10000};
byte asteroide[8] = {B00000, B01100, B11110, B11101, B10111, B11011, B11010, B00100};
byte explosao[8] = {B10001, B01010, B00100, B11111, B00100, B00100, B01010, B10001};
byte energia[8] = {B01110, B11111, B10001, B10101, B10101, B10101, B10001, B11111};
byte tiro[8] = {B00000, B00000, B00000, B01111, B01111, B00000, B00000, B00000};






void setup()
{
  pxnave = pynave = pxaste = pontos = pyaste = pxenergia = pyenergia = pytiro = 0;
  pxtiro = -1;
  pxaste = 12;
  venergia = 100;
  lcd.createChar(1, nave);
  lcd.createChar(2, asteroide);
  lcd.createChar(3, explosao);
  lcd.createChar(4, energia);
  lcd.createChar(5, tiro);
  lcd.begin(16, 2);
  lcd.clear();
  game = true;
  vtiro = vpilha = false;


}

void loop() 
{  

}
void desenhaNave(int px, int py)
{
  lcd.setCursor(px,py);
  lcd.write(1);
}
void desenhaAsteroide(int px, int py)
{
  lcd.setCursor(px,py);
  lcd.write(2);
}
void desenhaEnergia(int px, int py)
{
  lcd.setCursor(px,py);
  lcd.write(4);
}
void desenhaTiro(int px, int py)
{
  lcd.setCursor(px,py);
  lcd.write(5);
}
void desenhaExplosao(int px, int py)
{
  lcd.setCursor(px,py);
  lcd.write(3);
  delay(1000);
  lcd.clear();
}
void reset ()
{
  pontos= 0;
  venergia= 100;
  game= true;
}
void painel(int px)
{
  lcd.setCursor(px,0);
  lcd.print(pontos);
  lcd.setCursor(px,1);
  lcd.print(venergia);
}
void tela(int cond)
{
  char txt[6] = {(cond > 0 ? "GANHOU" : "PERDEU")}; /*1 GANHOU 0 PERDEU */
  lcd.setCursor(9,0);
  lcd.print("pts: ");
  lcd.setCursor(13,0);
  lcd.print(pontos);
  lcd.setCursor(1,0);
  lcd.print(txt);
  lcd.setCursor(0,1);
  lcd.print("PRESSIONE TIRO");
  
  
}
