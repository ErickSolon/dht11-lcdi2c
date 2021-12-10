#include "DHT.h"
#include <LCD_I2C.h>

#define DHTPIN A0
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE); 
LCD_I2C lcd(0x27, 16, 2);

void setup()
{
    lcd.begin(); 
    lcd.backlight();
    dht.begin();
}

void loop()
{
  sensorTemperaturaUmidade();
}

void sensorTemperaturaUmidade() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp.: " + String(temperatura) + String(" C"));
  lcd.setCursor(0, 1);
  lcd.print("Umidade: " + String(umidade) + String("%"));
  delay(3000);  
}
