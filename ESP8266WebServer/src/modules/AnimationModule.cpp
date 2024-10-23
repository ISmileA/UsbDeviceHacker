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
        case(OTHER_ANIMATION):
            return OtherAnimations();
        default:
            server.send(400, "aplication/json", cpr.error("Error id").c_str());
            return false;
    }
}

bool AnimationModule::MouseMoveAnimation(){
    if(animation.parsed["direction"]){
        const char *direction = animation.parsed["direction"];
        animation.data[2] = 4;
        animation.data[3] = 0;
        animation.data[4] = (uint8_t)animation.parsed["id"];
        animation.data[5] = (uint8_t)direction[0];
        animation.data[6] = (uint8_t)animation.parsed["buttons"];
        animation.data[7] = (uint8_t)animation.parsed["speed"];
        if (direction[0] == 'r' || direction[0] == 'l' || direction[0] == 't' || direction[0] == 'b')
            return true;
    }
    server.send(400, "aplication/json", cpr.error("Error direction").c_str());
    return false;
}

bool AnimationModule::KeyboardTextAnimation(){
    if(animation.parsed["text"]){
        const char *text = animation.parsed["text"];
        uint16_t size = strlen(text);
        animation.data[2] = (uint8_t)(size+2);
        animation.data[3] = (uint8_t)((size+2) >> 8);
        animation.data[4] = (uint8_t)animation.parsed["id"];
        for (int i=0; i<size; i++){
            animation.data[5+i] = (uint8_t)text[i];
        }
        animation.data[5+size] = (uint8_t)animation.parsed["repeat"];
        return true;
    }
    server.send(400, "aplication/json", cpr.error("Error text").c_str());
    return false;
}

bool AnimationModule::OtherAnimations(){
    if (animation.parsed["nomer"]){
        animation.data[2] = 1;
        animation.data[3] = 0;
        animation.data[4] = animation.parsed["nomer"];
        return true;
    }
    server.send(400, "aplication/json", cpr.error("Error nomer").c_str());
    return false;
}