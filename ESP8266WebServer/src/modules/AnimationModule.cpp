#include "AnimationModule.h"


AnimationData animation;

bool AnimationModule::AnimationSetup(JsonDocument *parsed, uint8_t *data){
    animation.parsed = *parsed;
    animation.data = data;
    switch((uint8_t)animation.parsed["id"]){
        case(MOUSE_MOVE_ANIMATION):
            return MouseMoveAnimation();;
        default:
            server.send(400, "aplication/json", cpr.error("Error id").c_str());
            return false;
    }
}

bool AnimationModule::MouseMoveAnimation(){
    const char* direction = animation.parsed["direction"];
    animation.data[2] = 4;
    animation.data[3] = (uint8_t)animation.parsed["id"];
    animation.data[4] = (uint8_t)direction[0];
    animation.data[5] = (uint8_t)animation.parsed["buttons"];
    animation.data[6] = (uint8_t)animation.parsed["speed"];
    if (direction[0] == 'r' || direction[0] == 'l' || direction[0] == 't' || direction[0] == 'b')
        return true;
    server.send(400, "aplication/json", cpr.error("Error direction").c_str());
    return false;
}