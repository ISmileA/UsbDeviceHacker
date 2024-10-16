#pragma once
#include <Arduino.h>
#include <configs/SerialConfig.h>
#include <iostream>
using namespace std;

class SerialModule {
private:
    bool status = false;
    uint8_t crc8(uint8_t *buffer, uint8_t size) {
        uint8_t crc = 0;
        for (uint8_t i = 0; i < size; i++) {
            uint8_t data = buffer[i];
            for (int j = 8; j > 0; j--) {
            crc = ((crc ^ data) & 1) ? (crc >> 1) ^ 0x8C : (crc >> 1);
            data >>= 1;
            }
        }
        return crc;
    }

    bool AwaitResponse(){
        uint32_t timer = millis();
        while((millis()-timer) < AWAIT_ANSWER_TIME){
            if(Serial.available() >= 3){
                uint8_t data[3] = {};
                Serial.readBytes(data, 3);
                if (data[0] == HEADER){
                    uint8_t crc = crc8(data, 2);
                    if(crc == data[2]){
                        status = data[1];
                        return true;
                    }
                }
            }
        }
        return false;
    }
public:
    string SendDataWithWait(uint8_t *data, uint16_t len){
        uint8_t data_out[len+2] = {HEADER,};
        for(int i = 0; i<len; i++){
            data_out[i+1] = data[i];
        }
        data_out[len+1] = crc8(data_out, len+1);
        Serial.write(data_out, len+2);
        if(AwaitResponse()){
            if (status){
                status = false;
                return "ok";
            }
            return "error";
        }
        return "timeout";
    }
};

