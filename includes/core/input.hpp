#pragma once
#include "SDL2/SDL.h"
#include "core/keycodes.hpp"

class Input{
public:
    static bool getButton(Keycode keycode);
};