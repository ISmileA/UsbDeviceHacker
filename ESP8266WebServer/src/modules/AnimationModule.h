#pragma once
#include <main.h>
#include <ArduinoJson.h>
#include <modules/ClientProcessingModule.h>
#include <iostream>

#define MOUSE_MOVE_ANIMATION 0x01
#define KEYBOARD_TEXT_ANIMATION 0x02
#define MOUSE_ROUND_ANIMATION 0x03

typedef struct AnimationTag{
    JsonDocument parsed;
    uint8_t *data;
} AnimationData;

class AnimationModule
{
private:
    ClientProcessing cpr;
    bool MouseMoveAnimation();
    bool KeyboardTextAnimation();
    bool MouseRoundAnimation();
public:
    bool AnimationSetup(JsonDocument *parsed, uint8_t *data);
};

