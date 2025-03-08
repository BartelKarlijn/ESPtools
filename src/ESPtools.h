#ifndef ESPTOOLS_H
#define ESPTOOLS_H

#include <Arduino.h>
#include <Preferences.h>

// Function declarations
void Wifi_save_to_eeprom(String wifi_ssid, String wifi_pwd);

enum WifiParam {
  SSID,
  PWD
};
String Wifi_get_from_eeprom (WifiParam param);

#endif // ESPTOOLS_H