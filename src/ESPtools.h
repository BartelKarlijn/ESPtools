#ifndef PRINTANYFORMAT_H
#define PRINTANYFORMAT_H

#include <Arduino.h>

// Function template declarations and definitions
template <typename T>
void Print(T message) {
  #ifdef PRINTWEBSERIAL
    WebSerial.print(message);
  #endif
  #ifdef PRINTSERIAL
    Serial.print(message);
  #endif
}

template <typename T>
void Println(T message) {
  #ifdef PRINTWEBSERIAL
    WebSerial.println(message);
  #endif
  #ifdef PRINTSERIAL
    Serial.println(message);
  #endif
}

#endif
