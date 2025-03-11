void setup_AsyncWebserverBegin(){
  // Voordat we de webserver starten, moet je OTA opstarten, hier zonder user/pw
  ElegantOTA.begin(&webserver);
  // ElegantOTA callbacks
  ElegantOTA.onStart(onOTAStart);
  ElegantOTA.onProgress(onOTAProgress);
  ElegantOTA.onEnd(onOTAEnd);

  // Analoog gaan we de WebSerial opstarten, zodat je kan zien wat er gebeurt
  WebSerial.begin(&webserver);
  WebSerial.onMessage([&](uint8_t *data, size_t len) {
    Serial.printf("Received %lu bytes from WebSerial: ", len);
    
    String WebSerialMessage = String((char*)data).substring(0, len);
    Println("Message=" + WebSerialMessage);
//    commandParts = decodeCommand(String(WebSerialMessage));
//    executeCommand();
  });

  // Start server
  webserver.begin();
}