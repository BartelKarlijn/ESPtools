bool setup_ConnectKnownWifi(String macAddress, String deviceName){
  bool returnMsg = false;
  uint8_t baseMac[6];
  uint8_t wifi_mac[6];

  Serial.println();
  Serial.println("Disconnecting current wifi connection");
  WiFi.disconnect();
  
  delay(1000);
  WiFi.mode(WIFI_STA);    // connect to network
  delay(1000);
    // Device name (before Wifi.mode)
  Serial.print("Current device name: ");
  Serial.println(WiFi.getHostname());
  
  Serial.print("Trying to set device name to: ");
  Serial.println(deviceName);
  delay(100);
  WiFi.config(INADDR_NONE, INADDR_NONE, INADDR_NONE); // Clear any existing IP configuration
  if (deviceName.length() > 0 and deviceName.length() < 32) {
    if (WiFi.setHostname(deviceName.c_str()) == ESP_OK) {
      Serial.print("Device should be set to: ");
      Serial.println(deviceName);
    } else {
      Serial.print("Did we really fail to set device name to ");
      Serial.print(deviceName);
      Serial.println("? See next line for current device name:");
    }
  } else {
    Serial.println("Invalid device name length");
  }
    // Device name (before Wifi.mode)
  Serial.print("Updated device name: ");
  Serial.println(WiFi.getHostname());

  // Read base MAC address
  esp_err_t ret = esp_wifi_get_mac(WIFI_IF_STA, baseMac);
  Serial.print("Base MAC address:");
  if (ret == ESP_OK) {
    Serial.printf("%02x:%02x:%02x:%02x:%02x:%02x\n",
                  baseMac[0], baseMac[1], baseMac[2],
                  baseMac[3], baseMac[4], baseMac[5]);
  } else {
    Serial.println("Failed to read MAC address");
  }

  // Convert MAC address string to byte array
    if (macAddress.length() == 17) {
        bool valid = true;
        for (int i = 0; i < 6; i++) {
            int pos = i * 3;
            if (i < 5 && macAddress[pos + 2] != ':') {
                valid = false;
                break;
            }

            char hexPair[3] = { macAddress[pos], macAddress[pos + 1], '\0' };
            char *endPtr;
            long value = strtol(hexPair, &endPtr, 16);
            if (*endPtr != '\0' || value < 0 || value > 0xFF) {
                valid = false;
                break;
            }
            wifi_mac[i] = (uint8_t)value;
        }

        if (!valid) {
            Serial.println("Invalid MAC format");
        }
    } else {
        Serial.println("Invalid MAC length");
    }

    Serial.print("New MAC address: ");
    Serial.printf("%02x:%02x:%02x:%02x:%02x:%02x\n",
                  wifi_mac[0], wifi_mac[1], wifi_mac[2],
                  wifi_mac[3], wifi_mac[4], wifi_mac[5]);

    // Set MAC address
    esp_err_t err = esp_wifi_set_mac(WIFI_IF_STA, wifi_mac);
  if (err != ESP_OK) {
    Serial.print("Failed to set MAC address: ");
    Serial.println(esp_err_to_name(err));
  } else {
    Serial.print("MAC address set to: ");
    for (int i = 0; i < 6; i++) {
      Serial.printf("%02X", wifi_mac[i]);
      if (i < 5) {
        Serial.print(":");
      }
    }
    Serial.println();
  }

  WiFi.begin(wifi_ssid.c_str(), wifi_pwd.c_str());
  WiFi.setTxPower(WIFI_POWER_8_5dBm);
  delay(1000);

  setup_AsyncWebserverBegin();    // webserver om html te tonen
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