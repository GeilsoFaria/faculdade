#include <LiquidCrystal.h>

int i;
LiquidCrystal lcd(7,6,5,4,3,2); 
  
void setup() 
{
  lcd.begin(16,2);
  lcd.clear();
  

}

void loop()
{
 lcd.setCursor(3,0);
 lcd.print("XXX XXXXXX");
 lcd.setCursor(4,1);
 lcd.print("XXXXXXX");
 delay(3000);

 for(i = 0;i < 3; i++)
 {
  lcd.scrollDisplayLeft();
  delay(100);
 }
 for(i = 0;i < 6; i++)
 {
  lcd.scrollDisplayRight();
  delay(100);
 }
  for(i = 0;i < 3; i++)
 {
  lcd.scrollDisplayLeft();
  delay(100);
 }
 delay(1000);
 lcd.noDisplay();
 delay(500);
 lcd.display();
 delay(500);
 delay(1000);
 lcd.noDisplay();
 delay(500);
 lcd.display();
 delay(500);
 delay(1000);
 lcd.noDisplay();
 delay(500);
 lcd.display();
 delay(500);
 
}
