#include <Arduino.h>
#include <EEPROM.h>

#define LEDSZALAG 12
#define BUTTON 18
int fenyero;

void setup() {
  Serial.begin(115200);
  pinMode(LEDSZALAG, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  fenyero = EEPROM.read(1);
  Serial.print("EEPROM-ban tarolt fenyero: ");
  Serial.println(fenyero);
}

void loop() {
  analogWrite(LEDSZALAG, fenyero);
  if(digitalRead(BUTTON) == LOW)
  {
    Serial.println("Button Pressed");
    switch(fenyero)
    {
      case 255:
        Serial.println("100%->75%");
        fenyero = 192;
        Serial.println(fenyero);
        break;
      case 192:
        Serial.println("75%->50%");
        fenyero = 128;
        Serial.println(fenyero);
        break;
      case 128:
        Serial.println("50%->25%");
        fenyero = 64;
        Serial.println(fenyero);
        break;
      case 64:
        Serial.println("25%->12%");
        fenyero = 32;
        Serial.println(fenyero);
        break;
      case 32:
        Serial.println("12%->0%");
        fenyero = 0;
        Serial.println(fenyero);
        break;
      case 0:
        Serial.println("0%->100%");
        fenyero = 255;
        Serial.println(fenyero);
        break;
      default:
        Serial.println(fenyero);
        Serial.println("Halvany fingom sincs mi tortent, 100%-ra allitok");
        fenyero = 255;
    }
    EEPROM.update(1, fenyero);
    delay(500);
  }
}
