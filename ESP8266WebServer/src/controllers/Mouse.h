#pragma once

#include "main.h"
#include "ArduinoJson.h"
#include "modules/ClientResponseModule.h"
#include "modules/SerialModule.h"
ClientResponse cres;
SerialModule serial;

namespace Mouse{

    StaticJsonDocument<20> parsed;

    void set(){
        if(server.method() == HTTP_POST){
            DeserializationError error = deserializeJson(parsed, server.arg("plain"));
            if(!error){
                uint8 data[4] = {0, 0, 0, 0};
                data[0] = parsed["buttons"];
                data[1] = parsed["move_x"];
                data[2] = parsed["move_y"];
                data[3] = parsed["scroll"];   

                string result = serial.SendDataWithWait(data, 4);
                if(result == "timeout")
                    server.send(507, "aplication/json", cres.error("Stm32 is not responding").c_str());
                else if(result == "error")
                    server.send(507, "aplication/json", cres.error("Stm32 sent an error").c_str());
                else if(result == "ok")
                    server.send(200, "aplication/json", cres.nice().c_str());
            }else
                server.send(400, "aplication/json", cres.error("Error body").c_str());
            
        }else
            server.send(400, "aplication/json", cres.error("Error request method").c_str());
    };
    void remove(){};
}