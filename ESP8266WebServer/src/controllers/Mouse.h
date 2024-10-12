#pragma once

#include "main.h"
#include "ArduinoJson.h"
#include "modules/ClientProcessing.h"
#include "modules/SerialModule.h"
#include "configs/SerialConfig.h"
ClientProcessing cpr;
SerialModule serial;

namespace Mouse{

    JsonDocument parsed;
    void set(){
        if(cpr.CheckCLientReq(&parsed, HTTP_POST)){
            uint8 data[7] = {};
            data[0] = MOUSE;
            data[1] = SET_COMMAND;
            data[2] = 4;
            data[3] = parsed["buttons"];
            data[4] = parsed["move_x"];
            data[5] = parsed["move_y"];
            data[6] = parsed["scroll"];   

            cpr.AnswerClient(serial.SendDataWithWait(data, 7));
        }
    };
    void remove(){};
}