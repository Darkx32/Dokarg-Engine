#pragma once
#include "SDL2/SDL.h"
#include "mathGame.hpp"

/*
* Class component for GameObjects
*/
class Component{
public:
    Vector2 position;
    Vector2 size;

    virtual void render(SDL_Renderer *renderer) {}
};