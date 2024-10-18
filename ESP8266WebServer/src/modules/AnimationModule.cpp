#include "AnimationModule.h"


AnimationData animation;

void AnimationModule::AnimationSetup(JsonDocument *parsed, uint8_t *data){
    animation.parsed = *parsed;
    animation.data = data;
    switch((uint8_t)animation.parsed["id"]){
        case(MOUSE_MOVE_ANIMATION):
            MouseMoveAnimation();
            break;
        default:
            server.send(400, cpr.error("Error body").c_str());
    }
}

void AnimationModule::MouseMoveAnimation(){
    animation.data[2] = 4;
    animation.data[3] = (uint8_t)animation.parsed["id"];
    animation.data[4] = (uint8_t)animation.parsed["direction"];
    animation.data[5] = (uint8_t)animation.parsed["buttons"];
    animation.data[6] = (uint8_t)animation.parsed["speed"];
}