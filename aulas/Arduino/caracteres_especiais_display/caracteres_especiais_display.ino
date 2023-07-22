#include <LiquidCrystal.h>


LiquidCrystal lcd(7,6,5,4,3,2);

byte a1[8]={B00100,B11111,B10001,B11111,B01010,B01010,B01110,B00100};



void setup()
{
  lcd.begin(16,2);
  lcd.createChar(1,a1); 

}

void loop()
{
  lcd.clear(); 
  lcd.setCursor(5,0);
  lcd.write(1);
  delay(500);

}
