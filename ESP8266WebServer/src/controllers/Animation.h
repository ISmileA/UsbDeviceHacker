#pragma once
#include "main.h"
#include "ArduinoJson.h"
#include "modules/ClientProcessingModule.h"
#include "modules/SerialModule.h"
#include "configs/SerialConfig.h"
#include "modules/AnimationModule.h"


namespace Animation{

    AnimationModule animate;
    ClientProcessing cpr;
    SerialModule serial;
    JsonDocument parsed;

    void set(){
        if(cpr.CheckCLientReq(&parsed, HTTP_POST)){
            uint8 data[512] = {};
            data[0] = ANIMATION;
            data[1] = SET_COMMAND; 
            if(animate.AnimationSetup(&parsed, data)){
                uint16_t len = (uint16_t)data[2] | (uint16_t)(data[3] << 8);
                cpr.AnswerClient(serial.SendDataWithWait(data, len+4));
            }
        }
    };
    void remove(){
        if(cpr.CheckCLientReq(&parsed, HTTP_POST)){
            uint8 data[4] = {};
            data[0] = ANIMATION;
            data[1] = REMOVE_COMMAND;
            data[2] = 0;
            data[3] = 0;
            cpr.AnswerClient(serial.SendDataWithWait(data, 4));
        }
    };
};