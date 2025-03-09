void startWifi() {
  // eerst gekende wifi proberen
  Println("Start Wifi ssid= ");
  wifi_ssid = Wifi_get_from_eeprom(SSID); // parameters uit eeprom halen (oa ssid/pw en PWD)
  wifi_pwd = Wifi_get_from_eeprom(PWD);
  Println(wifi_ssid);
  delay(500);
  flagWifiOn = setup_ConnectKnownWifi();  // Aan gekende wifi connecteren
  
  if (! flagWifiOn) {
    setup_CreateAccessPoint(); // Toch eigen AccessPoint opzetten als gekende wifi niet gelukt.
  }
}