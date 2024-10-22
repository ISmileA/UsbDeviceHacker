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
    DynamicJsonDocument parsed(2048);

    void set(){
        if(cpr.CheckCLientReq(&parsed, HTTP_POST)){
            uint8 data[32] = {};
            data[0] = ANIMATION;
            data[1] = SET_COMMAND; 
            if(animate.AnimationSetup(&parsed, data))
                cpr.AnswerClient(serial.SendDataWithWait(data, data[2]+3));
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