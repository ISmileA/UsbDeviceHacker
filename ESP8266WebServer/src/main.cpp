#include <main.h>
#include <configs/WifiConfig.h>
#include <routers/ClientRouter.h>
#include <WifiInit.h>

ESP8266WebServer server(80);

void setup() {
  InitRouter();        
  Serial.begin(115200);
  delay(10);
  WifiInit(WIFI_NAME, WIFI_PASWORD);
}

void loop() {
  if(WiFi.status() == WL_CONNECTED)
    server.handleClient();
  else
    ESP.reset();
}
