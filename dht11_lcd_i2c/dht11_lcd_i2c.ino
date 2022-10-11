
//Libraries
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11  (AM2302)
// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x3F, 16, 2);
//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
  Serial.begin(9600);
	dht.begin();
  lcd.begin();
  lcd.backlight();
  lcd.clear();
}

void loop()
{
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    lcd.clear();
    lcd.print("Humidity : " + String(hum,0) +"%");
    lcd.setCursor(0, 1);
    lcd.print("Temp : " + String(temp,1)+ " C");
    delay(2000); //Delay 2 sec.
}