#ifndef ESPTOOLS_H
#define ESPTOOLS_H

#include <Arduino.h>
#include <Preferences.h>

// Wifi
#include <WiFi.h>           //
#include <AsyncTCP.h>       // nodig voor de ESPAyncWebserver
#include <ESPAsyncWebServer.h>
#include <ElegantOTA.h>
#include <WebSerial.h>

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
String humanReadableSize(const size_t bytes);
void listFiles();
void listStorage();
void setupSpiffs();
void writeFile(const char * path, const char * message);
String readFile(const char * path);
//Wifi

extern AsyncWebServer webserver;
String scanWifiNetworks();
void onOTAStart();
void onOTAProgress(size_t current, size_t final);
void onOTAEnd(bool success);
void setup_AsyncWebserverBegin();
bool setup_ConnectKnownWifi();
void setup_CreateAccessPoint();
void startWifi();
void stopWifi();

//Includes
//eprom
#include "eprom/save_eprom.h"
//I2C
#include "i2c/scanI2C.h"
//spiffs
#include "spiffs/humanReadableSize.h"
#include "spiffs/listFiles.h"
#include "spiffs/listStorage.h"
#include "spiffs/setupSpiffs.h"
#include "spiffs/writeFile.h"
#include "spiffs/readFile.h"
// wifi
#include "wifi/scanWifiNetworks.h"
#include "wifi/onOTA.h"
#include "wifi/setup_AsyncWebserverBegin.h"
#include "wifi/setup_ConnectKnownWifi.h"
#include "wifi/setup_CreateAccessPoint.h"
#include "wifi/startWifi.h"
#include "wifi/stopWifi.h"

#endif // ESPTOOLS_H