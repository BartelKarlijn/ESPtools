bool setup_ConnectKnownWifi(){
  bool returnMsg = false;
  Serial.println();
  Serial.println("Disconnecting current wifi connection");
  WiFi.disconnect();
  delay(1000);
  WiFi.mode(WIFI_STA);    // connect to network
  delay(1000);
  WiFi.begin(wifi_ssid.c_str(), wifi_pwd.c_str());
  delay(1000);

  // Dit houden we zo'n 30 sec vol, als het dan niet lukt AP opzetten.
  Serial.println("Connecting to wifi");
  delay(500);
  for (int i = 0; i < 50; i++) {
    delay(500);
    if ((WiFi.status() == WL_CONNECTED)) {
      wifi_ip = WiFi.localIP().toString();
      Serial.println(".");
      Serial.print("Connected successfully to ");
      Serial.println(wifi_ssid);
      Serial.print("Local IP: ");
      Serial.println(WiFi.localIP());
      returnMsg = true;
      break;
    }
    else {
      Serial.print(".");
    }
  }

  Serial.println("!");
  return returnMsg;
}