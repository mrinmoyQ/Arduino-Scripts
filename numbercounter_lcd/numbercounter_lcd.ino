#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int j = 0; j <= 200; j = j + 1) {
    lcd.clear();
    lcd.print(j);
    lcd.setCursor(8 , 0);
    lcd.print(200-j);
    delay(500);
  }
  // for (int j = 200; j >= 1; j = j - 1) {
  //   lcd.clear();
  //   lcd.setCursor(8 , 0);
  //   lcd.print(j);
  //   delay(50);
  // }
}