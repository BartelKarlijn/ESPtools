void startWifi(String macAddress, String deviceName) {
  // eerst gekende wifi proberen
  Serial.println("Start Wifi ssid= ");
  wifi_ssid = Wifi_get_from_eeprom(SSID); // parameters uit eeprom halen (oa ssid/pw en PWD)
  wifi_pwd = Wifi_get_from_eeprom(PWD);
  Serial.println(wifi_ssid);

   flagWifiOn = setup_ConnectKnownWifi(macAddress, deviceName);  // Aan gekende wifi connecteren

  setup_AsyncWebserverBegin();    // webserver om html te tonen 

  if (! flagWifiOn) {
    setup_CreateAccessPoint(); // Toch eigen AccessPoint opzetten als gekende wifi niet gelukt.
  }
}