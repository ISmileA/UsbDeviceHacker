#pragma once
#include <iostream>
#include <main.h>
#include <ArduinoJson.h>
using namespace std;

class ClientProcessing{
public:
    string error(string reason){
        return ("{\"status\":\"error\",\"reason\":\""+reason+"\"}");
    }
    string nice(){
        return "{\"status\":\"ok\"}";
    }
    bool CheckCLientReq(JsonDocument *json, uint8_t method){
        if(server.method() == method){
            DeserializationError err = deserializeJson(*json, server.arg("plain"));
            if(!err){
               return true;
            }else
                server.send(400, "aplication/json", error("Error body").c_str());
            
        }else
            server.send(400, "aplication/json", error("Error request method").c_str());
        return false;
    }
    void AnswerClient(string result){
        if(result == "timeout")
            server.send(507, "aplication/json", error("Stm32 is not responding").c_str());
        else if(result == "error")
            server.send(507, "aplication/json", error("Stm32 sent an error").c_str());
        else if(result == "ok")
            server.send(200, "aplication/json", nice().c_str()); 
    }
};