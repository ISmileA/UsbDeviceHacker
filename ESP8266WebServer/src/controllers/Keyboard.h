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
            uint8 data[11] = {};
            data[0] = KEYBOARD;
            data[1] = SET_COMMAND;
            data[2] = 8;
            data[3] = (uint8_t)parsed["modifier"];
            data[4] = (uint8_t)parsed["reserved"];
            data[5] = (uint8_t)parsed["keycode1"];
            data[6] = (uint8_t)parsed["keycode2"];
            data[7] = (uint8_t)parsed["keycode3"];      
            data[8] = (uint8_t)parsed["keycode4"];   
            data[9] = (uint8_t)parsed["keycode5"];   
            data[10] = (uint8_t)parsed["keycode6"];   

            cpr.AnswerClient(serial.SendDataWithWait(data, 11));
        }
    };
    void remove(){
        if(cpr.CheckCLientReq(&parsed, HTTP_POST)){
            uint8 data[3] = {};
            data[0] = KEYBOARD;
            data[1] = REMOVE_COMMAND;
            data[2] = 0; 

            cpr.AnswerClient(serial.SendDataWithWait(data, 3));
        }
    };
    void click(){
        if(cpr.CheckCLientReq(&parsed, HTTP_POST)){
            uint8 data[11] = {};
            data[0] = KEYBOARD;
            data[1] = CLICK_COMMAND;
            data[2] = 8;
            data[3] = (uint8_t)parsed["modifier"];
            data[4] = (uint8_t)parsed["reserved"];
            data[5] = (uint8_t)parsed["keycode1"];
            data[6] = (uint8_t)parsed["keycode2"];
            data[7] = (uint8_t)parsed["keycode3"];      
            data[8] = (uint8_t)parsed["keycode4"];   
            data[9] = (uint8_t)parsed["keycode5"];   
            data[10] = (uint8_t)parsed["keycode6"];   

            cpr.AnswerClient(serial.SendDataWithWait(data, 11));
        }
    }
};