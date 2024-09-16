#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define trigPin 22
#define echoPin 23
LiquidCrystal_I2C lcd(0x27 ,16,2);
int jarak = 200;
int tinggi;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  lcd.begin();
    lcd.setCursor(2,0);
    lcd.print("SISTEM AKTIF");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tinggi : ");
}
void loop() {
  long duration, gape;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  gape = (duration/2) / 29.0;
  tinggi = jarak - gape;
    lcd.setCursor(8,0);
    lcd.print(tinggi);
    lcd.print(" ");
    lcd.print("CM");
    lcd.print("   ");
    delay(1500);
}
