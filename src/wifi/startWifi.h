void startWifi(String macAddress, String deviceName) {
  // eerst gekende wifi proberen
  Serial.println("Start Wifi ssid= ");
  wifi_ssid = Wifi_get_from_eeprom(SSID); // parameters uit eeprom halen (oa ssid/pw en PWD)
  wifi_pwd = Wifi_get_from_eeprom(PWD);
  Serial.println(wifi_ssid);

  delay(500);
    // Device name (before Wifi.mode)
  Serial.print("Current device name: ");
  Serial.println(WiFi.getHostname());
  
  Serial.print("Setting device name to: ");
  Serial.println(deviceName);
  delay(100);
  if (deviceName.length() > 0 and deviceName.length() < 32) {
    if (WiFi.setHostname(deviceName.c_str()) == ESP_OK) {
      Serial.print("Device name set to: ");
      Serial.println(deviceName);
    } else {
      Serial.print("Failed to set device name to ");
      Serial.println(deviceName);
    }
  } else {
    Serial.println("Invalid device name length");
  }

  flagWifiOn = setup_ConnectKnownWifi(macAddress);  // Aan gekende wifi connecteren

  setup_AsyncWebserverBegin();    // webserver om html te tonen 

  if (! flagWifiOn) {
    setup_CreateAccessPoint(); // Toch eigen AccessPoint opzetten als gekende wifi niet gelukt.
  }
}