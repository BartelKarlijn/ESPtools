void stopWifi() {
  // Wifi uitzetten
  Println("Stopping Wifi");
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  Println("Wifi stopped");
  
}