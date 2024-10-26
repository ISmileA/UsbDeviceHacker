#pragma once

#include <main.h>

void WifiInit(const char *ssid, const char* password){
    Serial.println("");
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED){
        delay(500);                                          
        Serial.print(".");                                   
    }
    
    Serial.println("Wifi is connected");          
    server.begin();                                    
    Serial.println("Web server running.");               
    delay(1000);                                  
    Serial.println(WiFi.localIP());
}