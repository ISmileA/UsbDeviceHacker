#pragma once
#include "main.h"
#include "ArduinoJson.h"
#include "modules/ClientProcessing.h"
#include "modules/SerialModule.h"
#include "configs/SerialConfig.h"



namespace Animation{
    
    ClientProcessing cpr;
    SerialModule serial;
    JsonDocument parsed;
    void set(){
        if(cpr.CheckCLientReq(&parsed, HTTP_POST)){
            uint8 data[4] = {};
            data[0] = ANIMATION;
            data[1] = SET_COMMAND;
            data[2] = 1;
            data[3] = parsed["animation"];  

            cpr.AnswerClient(serial.SendDataWithWait(data, 4));
        }
    };
    void remove(){
        if(cpr.CheckCLientReq(&parsed, HTTP_POST)){
            uint8 data[3] = {};
            data[0] = ANIMATION;
            data[1] = REMOVE_COMMAND;
            data[2] = 0;

            cpr.AnswerClient(serial.SendDataWithWait(data, 3));
        }
    };
};