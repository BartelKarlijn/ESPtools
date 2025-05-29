String scanWifiNetworks(){
  String answertoSend;

//  Println("");
//  Println("Disconnecting current wifi connection");
//  WiFi.mode(WIFI_STA);
//  WiFi.disconnect();
//  delay(100);
//  Println("start scan");

// WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Println("scan done");
  if (n == 0) {
      answertoSend = "no networks found";
      Println("no networks found");
  } else {
    Print(n);
    Println(" networks found");
    for (int i = 0; i < n; ++i) {
      answertoSend += String (i + 1) + ": " + WiFi.SSID(i) + " (" + WiFi.RSSI(i) + ")" + String((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*" ) + "\n" ;
      // Print SSID and RSSI for each network found
      Print(i + 1);
      Print(": ");
      Print(WiFi.SSID(i));
      Print(" (");
      Print(WiFi.RSSI(i));
      Print(")");
      delay(10);
    }
  }
  Println("");
  return answertoSend;
}