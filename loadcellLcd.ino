/*
By: Suman Kumar ~BHUTUU
Program: Reading Load cell on Lcd Screen using Arduino UNO R3.
*/
#include "HX711.h"
#include "LiquidCrystal.h"

LiquidCrystal lcd(2, 3, 4, 5 ,6, 7);

HX711 scale;
String unit = "UNITS: ";
uint8_t dataPin = 8;
uint8_t clockPin = 9;

float a, b;
void setup()
{
  pinMode(10, OUTPUT);
  pinMode(11, INPUT);
  digitalWrite(10, HIGH);
  lcd.begin(16, 2);
  Serial.begin(57600);
  Serial.println(__FILE__);
  lcd.print(__FILE__);
  delay(500);
  lcd.setCursor(0, 0);
  Serial.print("LIBRARY VERSION: ");
  lcd.print("::LIBRARY VERSION::         ");
  lcd.setCursor(0, 1);
  Serial.println(HX711_LIB_VERSION);
  lcd.print(HX711_LIB_VERSION);
  Serial.println();
  delay(500);
  scale.begin(dataPin, clockPin);
  lcd.setCursor(0,0);
  Serial.print("UNITS:                  ");
  lcd.setCursor(0,1);
  lcd.print("                           ");
  lcd.setCursor(0,1);
  lcd.print(unit);
  Serial.println(scale.get_units(10));
  lcd.print(scale.get_units(10));
  lcd.setCursor(0,0);
  lcd.print("Empty the scale!          ");
  lcd.setCursor(0,1);
  lcd.print("& press any key           ");
  Serial.println("\nEmpty the scale, press a key to continue");
  //while(!Serial.available());
  //while(Serial.available()) Serial.read();
  while(!digitalRead(11, LOW));
  while(digitalRead(11, HIGH)){
    lcd.setCursor(0,0);
    lcd.print("Continuing...");
    lcd.setCursor(0,0);
    lcd.print("                 ")
  }
  
  scale.tare();
  lcd.setCursor(0,0);
  lcd.print("UNITS: ");
  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));
  lcd.print(scale.get_units(10));
  lcd.print("              ");

  delay(400);
  Serial.println("\nPut 1000 gram in the scale, press a key to continue");
  lcd.setCursor(0,0);
  lcd.print("put 1000g and         ");
  lcd.setCursor(0,1);
  lcd.print("presa any key!        ");

//  while(!Serial.available());
//  while(Serial.available()) Serial.read();
  while(!digitalRead(11, LOW));
  while(digitalRead(11, HIGH)) serial.print("done");
    lcd.setCursor(0,0);
    lcd.print("Continuing...");
    lcd.setCursor(0,0);
    lcd.print("                 ")


  scale.calibrate_scale(1000, 5);
  lcd.setCursor(0,0);
  lcd.print(unit);
  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));
  lcd.print(scale.get_units(10));
  lcd.print("              ");

  lcd.setCursor(0,0);
  Serial.println("\nScale is calibrated, press a key to continue");
  lcd.print("scale is calibrated,    ");
  lcd.setCursor(0,1);
  lcd.print("Press any key!          ");
  // Serial.println(scale.get_scale());
  // Serial.println(scale.get_offset());
//  while(!Serial.available());
//  while(Serial.available()) Serial.read();
  while(!digitalRead(11, LOW));
  while(digitalRead(11, HIGH)) serial.print("done");
    lcd.setCursor(0,0);
    lcd.print("Continuing...");
    lcd.setCursor(0,0);
    lcd.print("                 ");

  lcd.setCursor(0,0);
  lcd.print("  ::::UNITS::::         ");
  lcd.setCursor(0,1);
}


void loop()
{
  lcd.setCursor(0,1);
  lcd.print("                    ");
//  Serial.print("UNITS: ");
 a = scale.get_units(10);
 b = scale.get_units(10);
  while(true) {
        lcd.setCursor(1, 1);
        b = scale.get_units(10);
        if((a) <  b) {
            Serial.print("UNITS: ");
            Serial.println(b);
            lcd.print(b);
            lcd.print(" grams      ");
        } else if(a > b) {
            Serial.print("UNITS: ");
            Serial.println(b);
            lcd.print(b);
            lcd.print(" grams      ");
        }
    }
  //ignore grammer if measure is 1 gram its woud show grams only.. ah i am to implement this so ignore it!!
//  delay(250);
}
