#pragma once
void setupSpiffs() {
  if(!SPIFFS.begin(true)){
    // if you have not used SPIFFS before on a ESP32, it will show this error.
    // after a reboot SPIFFS will be configured and will happily work.
    Println("An Error has occurred while mounting SPIFFS");
    return;
  }

  Print("SPIFFS Free: "); Println(humanReadableSize((SPIFFS.totalBytes() - SPIFFS.usedBytes())));
  Print("SPIFFS Used: "); Println(humanReadableSize(SPIFFS.usedBytes()));
  Print("SPIFFS Total: "); Println(humanReadableSize(SPIFFS.totalBytes()));

  //Println(listFiles(false));
}