#include "AnimationModule.h"

AnimationData animation;

bool AnimationModule::AnimationSetup(JsonDocument *parsed, uint8_t *data){
    animation.parsed = *parsed;
    animation.data = data;
    switch((uint8_t)animation.parsed["id"]){
        case(MOUSE_MOVE_ANIMATION):
            return MouseMoveAnimation();
        case(KEYBOARD_TEXT_ANIMATION):
            return KeyboardTextAnimation();
        case(MOUSE_ROUND_ANIMATION):
            return MouseRoundAnimation();
        default:
            server.send(400, "aplication/json", cpr.error("Error id").c_str());
            return false;
    }
}

bool AnimationModule::MouseMoveAnimation(){
    if(animation.parsed["direction"].is<const char*>()){
        const char *direction = animation.parsed["direction"];
        animation.data[2] = 4;
        animation.data[3] = 0;
        animation.data[4] = animation.parsed["id"];
        animation.data[5] = (uint8_t)direction[0];
        animation.data[6] = (uint8_t)animation.parsed["buttons"].as<uint8_t>();
        animation.data[7] = (uint8_t)animation.parsed["speed"].as<uint8_t>();
        if (direction[0] == 'r' || direction[0] == 'l' || direction[0] == 't' || direction[0] == 'b')
            return true;
    }
    server.send(400, "aplication/json", cpr.error("Error direction").c_str());
    return false;
}

bool AnimationModule::KeyboardTextAnimation(){
    if(animation.parsed["text"].is<const char*>()){
        const char *text = animation.parsed["text"];
        uint16_t size = strlen(text);
        animation.data[2] = (uint8_t)(size+2);
        animation.data[3] = (uint8_t)((size+2) >> 8);
        animation.data[4] = animation.parsed["id"].as<uint8_t>();
        for (int i=0; i<size; i++){
            animation.data[5+i] = (uint8_t)text[i];
        }
        animation.data[5+size] = (uint8_t)animation.parsed["repeat"].as<uint16_t>();
        return true;
    }
    server.send(400, "aplication/json", cpr.error("Error text").c_str());
    return false;
}

bool AnimationModule::MouseRoundAnimation(){
    animation.data[2] = 4;
    animation.data[3] = 0;
    animation.data[4] = animation.parsed["id"];
    animation.data[5] = animation.parsed["radius"].as<uint16_t>();
    animation.data[6] = animation.parsed["speed"].as<uint8_t>();
    animation.data[6] = animation.parsed["buttons"].as<uint8_t>();
    return true;
}