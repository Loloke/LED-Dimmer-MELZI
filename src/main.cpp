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
        Serial.println("100%->50%");
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
        Serial.println("12%->7%");
        fenyero = 16;
        Serial.println(fenyero);
        break;
      case 16:
        Serial.println("7%->3%");
        fenyero = 8;
        Serial.println(fenyero);
        break;
      case 8:
        Serial.println("3%->1%");
        fenyero = 4;
        Serial.println(fenyero);
        break;
      case 4:
        Serial.println("3%->0%");
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
    analogWrite(LEDSZALAG, fenyero);
    delay(1000);
  }
}
