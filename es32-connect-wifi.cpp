// https://www.upesy.com/blogs/tutorials/how-to-connect-wifi-acces-point-with-esp32

#include <WiFi.h>

const char* ssid = "dibasdauliya";
const char* password = "dibas123@!!!";
const int WIFI_TIMEOUT = 20000; // 20 secs

void setup() {
  Serial.begin(115200);
  
  connectToWiFi();
}

void connectToWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  
  unsigned long startAttemptTime = millis();

  while (WiFi.status() != WL_CONNECTED && 
         millis() - startAttemptTime < WIFI_TIMEOUT) {
    delay(500);
    Serial.print(".");
  }

  if(WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected successfully!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFailed to connect!");
    Serial.println("Please check your credentials or WiFi availability");
  }
}

void loop() {
  if(WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi connection lost! Reconnecting...");
    WiFi.disconnect();
    connectToWiFi();
  }
  
  delay(10000); // check every 10 seconds
}