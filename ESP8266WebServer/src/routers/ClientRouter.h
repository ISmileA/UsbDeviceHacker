#pragma once

#include "main.h"
#include "controllers/Animation.h"
#include "controllers/Mouse.h"
#include "controllers/Keyboard.h"

void InitRouter(){

    server.on("/mouse/set", Mouse::set);
    server.on("/mouse/remove", Mouse::remove);
    server.on("/keyboard/set", Keyboard::set);
    server.on("/keyboard/remove", Keyboard::remove);
    server.on("/animation/set", Animation::set);
    server.on("/animation/remove", Animation::remove);

};
