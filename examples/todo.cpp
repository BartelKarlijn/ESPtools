#include <Arduino.h>
#include <PrintAnyFormat.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
    Print("Print wo new line");
    Println("Print and start new line");
    delay(1000);
}