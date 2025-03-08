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
#include "eprom/save_eprom.h"

#endif // ESPTOOLS_H