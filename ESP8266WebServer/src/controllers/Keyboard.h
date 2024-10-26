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
            data[4] = parsed["modifier"].as<uint8_t>();
            data[5] = parsed["reserved"].as<uint8_t>();
            data[6] = parsed["keycode1"].as<uint8_t>();
            data[7] = parsed["keycode2"].as<uint8_t>();
            data[8] = parsed["keycode3"].as<uint8_t>();      
            data[9] = parsed["keycode4"].as<uint8_t>();   
            data[10] = parsed["keycode5"].as<uint8_t>();   
            data[11] = parsed["keycode6"].as<uint8_t>();   

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
            data[4] = parsed["modifier"].as<uint8_t>();
            data[5] = parsed["reserved"].as<uint8_t>();
            data[6] = parsed["keycode1"].as<uint8_t>();
            data[7] = parsed["keycode2"].as<uint8_t>();
            data[8] = parsed["keycode3"].as<uint8_t>();      
            data[9] = parsed["keycode4"].as<uint8_t>();   
            data[10] = parsed["keycode5"].as<uint8_t>();   
            data[11] = parsed["keycode6"].as<uint8_t>();   

            cpr.AnswerClient(serial.SendDataWithWait(data, 12));
        }
    }
};