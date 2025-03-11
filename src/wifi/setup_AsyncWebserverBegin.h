void setup_AsyncWebserverBegin(){
  // Voordat we de webserver starten, moet je OTA opstarten, hier zonder user/pw
  ElegantOTA.begin(&webserver);
  // ElegantOTA callbacks
  ElegantOTA.onStart(onOTAStart);
  ElegantOTA.onProgress(onOTAProgress);
  ElegantOTA.onEnd(onOTAEnd);

  // Start server
  webserver.begin();
}