#ifndef ESPTOOLS_H
#define ESPTOOLS_H

#include <Arduino.h>
#include <Preferences.h>

enum WifiParam {
  SSID,
  PWD
};
// Function declarations
//eeprom
void Wifi_save_to_eeprom(String wifi_ssid, String wifi_pwd);
String Wifi_get_from_eeprom (WifiParam param);
//i2c
void scanI2C();
//spiffs


//Includes
#include "eprom/save_eprom.h"
#include "i2c/scanI2C.h"

#endif // ESPTOOLS_H