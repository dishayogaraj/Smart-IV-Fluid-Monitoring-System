#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorPin = A0;
int ledPin = 13;
int buzzerPin = 8;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
}

void loop()
{
  int level = analogRead(sensorPin);

  int percentage = map(level, 0, 1023, 0, 100);

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("IV:");
  lcd.print(percentage);
  lcd.print("%");

  if(level < 300)
  {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);

    lcd.setCursor(0,1);
    lcd.print("Status: LOW");
  }
  else
  {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);

    lcd.setCursor(0,1);
    lcd.print("Status: OK ");
  }

  delay(500);
}