#include <main.h>
#include <routers/ClientRouter.h>

ESP8266WebServer server(80);

const char* ssid = "Pixel_9287";               
const char* password = "12345678";


void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println("");
  Serial.print("Connecting to");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)                 // Проверка подключения к WiFi сети
  {
    delay(500);                                          
    Serial.print(".");                                   
  }
  Serial.println("Wifi is connected");

  InitRouter();                  
  server.begin();                                    
  Serial.println("Web server running.");               
  
  delay(1000);                                  
  Serial.println(WiFi.localIP());
}

void loop() {
  if(WiFi.status() == WL_CONNECTED){
    server.handleClient();
  }else{
    Serial.println("Wifi disconnected");
    delay(10);
    ESP.reset();
  }
}
