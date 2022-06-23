#pragma once
#include "SDL2/SDL.h"
#include "input/keycodes.hpp"
#include "mathGame.hpp"

class Input{
public:
    static bool getKeyPressed(KeyCode keycode){
        const Uint8* state = SDL_GetKeyboardState(NULL);
        if(state[keycode]){
            return true;
        }
        return false;
    }

    static Vector2 getMousePosition(){
        int x, y;

        SDL_PumpEvents();

        SDL_GetMouseState(&x, &y);
        return Vector2{x, y};
    }

    static bool getMouseButtonPressed(MouseCode code){
        int x, y;
        Uint32 button;

        SDL_PumpEvents();

        button = SDL_GetMouseState(&x, &y);
        if((button & code) != 0){
            return true;
        }
        return false;
    }
};