#pragma once

#include "main.h"
#include "ArduinoJson.h"

namespace Mouse{
    void set(){
        if(server.method() == HTTP_POST){
            StaticJsonDocument<300> parsed;
            DeserializationError error = deserializeJson(parsed, server.arg("plain"));
            if(!error){
                server.send(200, "text/html", "NiceJson");
            }
        }
    };
    void remove(){};
}