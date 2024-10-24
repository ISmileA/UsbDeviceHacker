#pragma once
#include "main.h"
#include "ArduinoJson.h"
#include "modules/ClientProcessingModule.h"
#include "modules/SerialModule.h"
#include "configs/SerialConfig.h"

namespace Keyboard{
    ClientProcessing cpr;
    SerialModule serial;
    JsonDocument parsed;

    void set(){
        if(cpr.CheckCLientReq(&parsed, HTTP_POST)){
            uint8 data[12] = {};
            data[0] = KEYBOARD;
            data[1] = SET_COMMAND;
            data[2] = 8;
            data[3] = 0;
            data[4] = (uint8_t)parsed["modifier"];
            data[5] = (uint8_t)parsed["reserved"];
            data[6] = (uint8_t)parsed["keycode1"];
            data[7] = (uint8_t)parsed["keycode2"];
            data[8] = (uint8_t)parsed["keycode3"];      
            data[9] = (uint8_t)parsed["keycode4"];   
            data[10] = (uint8_t)parsed["keycode5"];   
            data[11] = (uint8_t)parsed["keycode6"];   

            cpr.AnswerClient(serial.SendDataWithWait(data, 12));
        }
    };
    void remove(){
        if(cpr.CheckCLientReq(&parsed, HTTP_POST)){
            uint8 data[4] = {};
            data[0] = KEYBOARD;
            data[1] = REMOVE_COMMAND;
            data[2] = 0; 
            data[3] = 0;
            cpr.AnswerClient(serial.SendDataWithWait(data, 4));
        }
    };
    void click(){
        if(cpr.CheckCLientReq(&parsed, HTTP_POST)){
            uint8 data[12] = {};
            data[0] = KEYBOARD;
            data[1] = CLICK_COMMAND;
            data[2] = 8;
            data[3] = 0;
            data[4] = (uint8_t)parsed["modifier"];
            data[5] = (uint8_t)parsed["reserved"];
            data[6] = (uint8_t)parsed["keycode1"];
            data[7] = (uint8_t)parsed["keycode2"];
            data[8] = (uint8_t)parsed["keycode3"];      
            data[9] = (uint8_t)parsed["keycode4"];   
            data[10] = (uint8_t)parsed["keycode5"];   
            data[11] = (uint8_t)parsed["keycode6"];   

            cpr.AnswerClient(serial.SendDataWithWait(data, 12));
        }
    }
};