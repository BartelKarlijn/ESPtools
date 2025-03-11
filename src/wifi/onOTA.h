void onOTAStart() {
    // Log when OTA has started
    Println("OTA update started!");
    // <Add your own code here>
  }
  
  void onOTAProgress(size_t current, size_t final) {
    // Log every 1 second
    if (millis() - ota_progress_millis > 1000) {
      ota_progress_millis = millis();
      Print("OTA Progress Current: ");
      Print(current);
      Print(" bytes");
      Print(final);
      Println(" bytes");
    }
  }
  
  void onOTAEnd(bool success) {
    // Log when OTA has finished
    if (success) {
      Println("OTA update finished successfully!");
    } else {
      Println("There was an error during OTA update!");
   }
    // <Add your own code here>
  }
  