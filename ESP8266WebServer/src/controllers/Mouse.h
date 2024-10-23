#pragma once

#include "main.h"
#include "ArduinoJson.h"
#include "modules/ClientProcessingModule.h"
#include "modules/SerialModule.h"
#include "configs/SerialConfig.h"

namespace Mouse{
    ClientProcessing cpr;
    SerialModule serial;
    JsonDocument parsed;

    void set(){
        if(cpr.CheckCLientReq(&parsed, HTTP_POST)){
            uint8 data[8] = {};
            data[0] = MOUSE;
            data[1] = SET_COMMAND;
            data[2] = 4;
            data[3] = 0;
            data[4] = (uint8_t)parsed["buttons"];
            data[5] = (uint8_t)parsed["move_x"];
            data[6] = (uint8_t)parsed["move_y"];
            data[7] = (uint8_t)parsed["scroll"];   

            cpr.AnswerClient(serial.SendDataWithWait(data, 8));
        }
    };
    void remove(){
        if(cpr.CheckCLientReq(&parsed, HTTP_POST)){
            uint8_t data[4] = {};
            data[0] = MOUSE;
            data[1] = REMOVE_COMMAND;
            data[2] = 0; 
            data[3] = 0;
            cpr.AnswerClient(serial.SendDataWithWait(data, 4));
        }
    };
    void click(){
        if(cpr.CheckCLientReq(&parsed, HTTP_POST)){
            uint8_t data[5] = {};
            data[0] = MOUSE;
            data[1] = CLICK_COMMAND;
            data[2] = 1; 
            data[3] = 0;
            data[4] = (uint8_t)parsed["buttons"];

            cpr.AnswerClient(serial.SendDataWithWait(data, 5));
        }
    }
}